specific action log: addORsubtractTimeSegmentFromSPA
#
#SPA = Specific Action (issue)
#
#Exit script if user clicked on an empty
#time segement.
If [ Get ( ActiveFieldContents ) = "" ]
Go to Field [ ]
Exit Script [ ]
End If
#
#Exit script if user has not exited a Timer
#window field, which can prevent linking
#of records.
Select Window [ Name: "Timer"; Current file ]
If [ Get (ActiveFieldName) ≠ "" ]
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
Select Window [ Name: "Day"; Current file ]
Go to Field [ ]
Show Custom Dialog [ Message: "You are in a field in the Timer window which you must exit before assigning time segements
to specific actions. 1) Click 'timer' above. 2) Exit the field."; Buttons: “OK” ]
Exit Script [ ]
End If
Select Window [ Name: "Day"; Current file ]
#
#Get segment ID information.
Set Variable [ $timeSegment; Value:Get ( ActiveRepetitionNumber ) & logs::_lockDay ]
#
#Get last segment ID information (to
#determine later on if segment being
#added is active).
Set Variable [ $lastSegment; Value:logs::swOccurances & logs::_lockDay ]
#
#Prevent windows from flashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each record's
#information throughout the script, rather than just
#one time at the end of the script.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Get category key for adding up total category time
#later in the script.
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $categoryKey; Value:specificAction::_keyGroup ]
Go to Field [ ]
#
#For some reason if system does not re-go to same
#issue record, record in a different window (so same
#layout different window will get an error 301 (record
#in use by another user).
Go to Record/Request/Page [ Get (RecordNumber) ]
[ No dialog ]
#
#Capture repetition number, timer status, and
#_lockDay of segment user clicked in log window.
Select Window [ Name: "Day"; Current file ]
Set Variable [ $day; Value:daylog::_lockDay ]
Set Variable [ $noteOrVeto; Value:logs::swBugField ]
Set Variable [ $repetition; Value:Get (ActiveRepetitionNumber) ]
Go to Field [ ]
#
#See if time segment is already in use by ANY segment.
Go to Layout [ “SPATimeTable” (SPATime) ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ SPATime::_keyDay; $day ]
Set Field [ SPATime::_keyRepetition; $repetition ]
Perform Find [ ]
#
#
#BEGIN Add segment to Specific Action record.
#
#If it is not in use create a new record in issueTime
#window and give it issue, day, and repetition keys.
#to add their time to the total of all time spent on
#the selected issue.
If [ Get (LastError) = 401 ]
New Record/Request
Set Field [ SPATime::_keyDay; $day ]
Set Field [ SPATime::_keyRepetition; $repetition ]
Set Field [ SPATime::_keySPA; $$issue ]
#
#Add up total time for this issue.
Enter Find Mode [ ]
Set Field [ SPATime::_keySPA; $$issue ]
Perform Find [ ]
Set Variable [ $totalTime; Value:SPATime::sum ]
#
#Set new total time for this issue.
Go to Layout [ “SpecificActionTable” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::_LockSpecificAction; $$issue ]
Perform Find [ ]
Set Field [ specificAction::SPATotalTime; $totalTime ]
#
#Add day and repetition keys to the list of all
#day and repetition keys for this issue.
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
Set Variable [ $time; Value:$repetition & $day ]
Set Field [ specificAction::timeSegmentKeyList; $time & ¶ & $$timeAll ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
#
#Add up total time for category it is in.
Enter Find Mode [ ]
Set Field [ specificAction::_keyGroup; $categoryKey ]
Perform Find [ ]
Sort Records [ Specified Sort Order: specificAction::_keyGroup; ascending ]
[ Restore; No dialog ]
#
#Stop doing this modification of all records tagged
#with the same catetory so the MODIFY DATE
#only gets changed when something unique in
#an issue record is changed. And besides,
#category tag's total time is now displayed in the
#tag window rather than the Specific Action window.
// Go to Record/Request/Page
[ First ]
// Loop
// Set Field [ specificAction::timeTotalSumByGroup; specificAction::timeTotalSummaryByGroup ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
#
#Set new total time for category tag.
Set Field [ SPAGroupTag 2::SPATotalTime; GetSummary ( specificAction::timeSummary ; specificAction::_keyGroup ) ]
#
Go to Layout [ original layout ]
#
#Conditionally format new segment to show
#that it is assigned to the selected issue.
Set Field [ daylog::swLogTimeAccounting[$repetition]; $$issue ]
#
#If issue is not linked to day whose time has just
#been added to it, then link it.
Select Window [ Name: "Specific Action"; Current file ]
If [ specificAction::_LockSpecificAction & "¶" ≠ FilterValues ( $$logIssues ; specificAction::_LockSpecificAction & "¶" ) ]
Perform Script [ “SpecificActionLinkToDayRecordToggle” ]
End If
#
#If this Specific Action/issue record has the
#last Day time segement assigned to it, and
#this Day's timer is active, then conditional
#format this Specific Action (issue) record
#'active'.
If [ FilterValues (specificAction::timeSegmentKeyList ; $repetition & $day & "¶" ) = $lastSegment & "¶" and $noteOrVeto = "veto" ]
Set Field [ specificAction::timer; "active" ]
End If
#
#Show record has been modified.
Set Field [ specificAction::dateModified; Get ( CurrentTimeStamp ) ]
#
#Update changed SPA varilables.
Set Variable [ $$issueLogs; Value:specificAction::_keyLogs ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
Set Variable [ $$stopRecordLoad ]
#
#Prevent error where user is told record is
#being modified in another window.
Go to Field [ ]
#
#Return user to Day window.
Select Window [ Name: "Day"; Current file ]
#
#END Add segment to Specific Action record.
#
#
#
#
#BEGIN Go to linked SPA or subtract time segment.
#
Else If [ Get (LastError) ≠ 401 ]
#
#Get SPA (issue) ID that this segment is assigned
#to. This will be used later in the script if the
#user decides to subtract this time from this
#SPA, which may not be the SPA that the the
#user is currently focused on.
# For example, the user can decide to re-assign
#a time segment from one SPA that they are
#currently not focused upon, to one that they
#are, by first subtracting the segement from it's
#old SPA, thus freeing it up to now be re-
#assigned to the SPA that they are focused on.
Set Variable [ $issue; Value:SPATime::_keySPA ]
#
#Give user choice to subtract time segment or
#got to one its linked to.
Go to Layout [ original layout ]
If [ $$specificActionTimer = "" ]
Show Custom Dialog [ Message: "Subtract time segment from Specific Action credited with it? (Allows it to be credited to a
different Specific Action.)¶ OR¶Go to Specific Action credited with this time?"; Buttons: “Go”, “Subtract” ]
End If
#
#
#BEGIN Go to linked SPA.
#
#If user decides to go this record, then go to it.
If [ Get ( LastMessageChoice ) = 1 and $$specificActionTimer = "" ]
Go to Field [ ]
#
#If this is the record currently selected then
#exit the script.
Select Window [ Name: "Specific Action"; Current file ]
If [ FilterValues (specificAction::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
Set Variable [ $$stopRecordLoad ]
Exit Script [ ]
End If
#
#Get selected records number so it can be
#returned to if no linked record is found.
Set Variable [ $currentIssueNumber; Value:Get ( RecordNumber ) ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ FilterValues (specificAction::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#If record is not showing then find it.
If [ FilterValues (specificAction::timeSegmentKeyList ; $timeSegment & "¶") ≠ $timeSegment & "¶" ]
Enter Find Mode [ ]
Set Field [ specificAction::timeSegmentKeyList; $timeSegment & "¶" ]
Extend Found Set [ ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ FilterValues (specificAction::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
#
#If no linked record is found return user to
#selected record.
If [ FilterValues (specificAction::timeSegmentKeyList ; $timeSegment & "¶") ≠ $timeSegment & "¶" ]
Go to Record/Request/Page [ $currentIssueNumber ]
[ No dialog ]
Set Variable [ $$stopRecordLoad ]
Exit Script [ ]
End If
#
#Upon going to or finding the requested
#record, load its variables and update the
#Day window.
Set Variable [ $$stopRecordLoad ]
Perform Script [ “loadIssuerecordID” ]
Exit Script [ ]
End If
#
#END Go to linked SPA.
#
#
#BEGIN Subtract time segment.
#
#Conditionally format segment so it shows as unassigned.
Set Field [ daylog::swLogTimeAccounting[$repetition]; "" ]
#
#If it is in use then subtract its time from the total
#time of all time segements attributed to this issue.
#BUT first set a new issue ID variable as the user
#may be removing the time from an issue not currently
#selected, meaning the time was part of a different
#issue and when the user clicked on this time to assign
#to a new issue, the time first had to be deleted from
#the issue to which it is currently assigned.
Go to Layout [ “SPATimeTable” (SPATime) ]
Set Variable [ $issueTimeDelete; Value:SPATime::_keySPA ]
Delete Record/Request
[ No dialog ]
#
#Add up total time for issue.
Enter Find Mode [ ]
Set Field [ SPATime::_keySPA; $issueTimeDelete ]
Perform Find [ ]
Set Variable [ $totalTime; Value:SPATime::sum ]
#
#Then subtract day and repetition keys from the list
#of all day and repetition keys for this issue.
Go to Layout [ “Issues” (specificAction) ]
Set Variable [ $time; Value:$repetition & $day ]
Enter Find Mode [ ]
Set Field [ specificAction::timeSegmentKeyList; $time ]
Perform Find [ ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
Set Field [ specificAction::timeSegmentKeyList; //last item in list has no paragraph mark, so a valuecount test needs to be done
and if item is not removed, then the removal calc without the paragraph mark is used
If ( ValueCount ( $$timeAll ) ≠ ValueCount ( Substitute ( $$timeAll ; $time & "¶" ; "" ) ) ;
Substitute ( $$timeAll ; $time & "¶" ; "" ) ;
Substitute ( $$timeAll ; $time ; "" )
) ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
Set Field [ specificAction::SPATotalTime; $totalTime ]
#
#Show record has been modified.
Set Field [ specificAction::dateModified; Get ( CurrentTimeStamp ) ]
#
#Add up total time for category it is in.
Go to Layout [ “Issues” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::_keyGroup; $categoryKey ]
Perform Find [ ]
Sort Records [ Specified Sort Order: specificAction::_keyGroup; ascending ]
[ Restore; No dialog ]
#
#Stop doing this modification of all records tagged
#with the same catetory so the MODIFY DATE
#only gets changed when something unique in
#an issue record is changed. And besides,
#category tag's total time is now displayed in the
#tag window rather than the Specific Action window.
// Go to Record/Request/Page
[ First ]
// Loop
// Set Field [ specificAction::timeTotalSumByGroup; specificAction::timeTotalSummaryByGroup ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
#
#Set new total time for category tag.
Set Field [ SPAGroupTag 2::SPATotalTime; GetSummary ( specificAction::timeSummary ; specificAction::_keyGroup ) ]
#
#Update current SPA record's varilables in case
#this record happens to be the one from
#which a time segement was just subtracted
#(which it most likely is not, in my experience,
#but it could be).
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$issueLogs; Value:specificAction::_keyLogs ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
Set Variable [ $$stopRecordLoad ]
Go to Field [ ]
#
#See if this SPA is still active after subtracting
#the selected Day's time segment ...
#NOTE: This next chunk needs to be
#performed in a separate window.
New Window [ Height: 1; Width: 1; Top: -10000; Left: -10000 ]
Go to Layout [ “SpecificActionTable” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::_LockSpecificAction; $issue ]
Perform Find [ ]
#... by running this next script.
Perform Script [ “CHUNK_seeIfSPAisActiveOnOtherDays” ]
Close Window [ Current Window ]
#
#Return user to Day layout they where on at
#the start.
Select Window [ Name: "Day"; Current file ]
Go to Layout [ original layout ]
End If
#
#Prevent error where user is told record is
#being modified in another window.
Go to Field [ ]
#
#
#END Subtract time segment.
#
#
#END Go to linked SPA or subtract time segment.
#
December 16, ଘ౮28 1:02:38 ActionLog.fp7 - addORsubtractTimeSegmentFromSPA -1-
