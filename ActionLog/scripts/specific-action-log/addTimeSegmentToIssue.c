specific action log: addTimeSegmentToIssue
#
If [ Get ( ActiveFieldContents ) = "" ]
Go to Field [ ]
Exit Script [ ]
End If
Set Variable [ $timeSegment; Value:Get ( ActiveRepetitionNumber ) & logs::_lockDay ]
#
#Prevent windows from flashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#If the user activated Specific Action timer by
#dragging time from another timer then the
#update the $$day1BugField to reflect it's
#active. The dragging method of activiation
#fails to update variables.
If [ logs::swBugField = "veto" ]
Set Variable [ $$day1BugField; Value:"veto" ]
End If
#
#Get category key for adding up total category time
#later in the script.
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $categoryKey; Value:issue::_keyCategory ]
Go to Field [ ]
#
#For some reason if system does not re-go to same
#issue record, record in a different window (so same
#layout different window will get an error 301 (record
#in use by another user).
Go to Record/Request/Page [ Get (RecordNumber) ]
[ No dialog ]
Select Window [ Name: "Day"; Current file ]
#
#Capture repetition number and _lockDay when
#segment is clicked in log window.
Set Variable [ $day; Value:daylog::_lockDay ]
Set Variable [ $repetition; Value:Get (ActiveRepetitionNumber) ]
Go to Field [ ]
#
#See if time segment is already in use by ANY segment.
Go to Layout [ “issueTime” (issueTime) ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ issueTime::_keyDay; $day ]
Set Field [ issueTime::_keyRepetition; $repetition ]
Perform Find [ ]
#
#If it is not in use create a new record in issueTime
#window and give it issue, day, and repetition keys.
#to add their time to the total of all time spent on
#this issue.
If [ Get (LastError) = 401 ]
New Record/Request
Set Field [ issueTime::_keyDay; $day ]
Set Field [ issueTime::_keyRepetition; $repetition ]
Set Field [ issueTime::_keyIssue; $$issue ]
#
#Add up total time for this issue.
Enter Find Mode [ ]
Set Field [ issueTime::_keyIssue; $$issue ]
Perform Find [ ]
Set Variable [ $totalTime; Value:issueTime::sum ]
#
#Set new total time for this issue.
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_LockList; $$issue ]
Perform Find [ ]
Set Field [ issue::issueTotalTime; $totalTime ]
#
#Add day and repetition keys to the list of all day
#and repetition keys for this issue.
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
Set Variable [ $time; Value:$repetition & $day ]
Set Field [ issue::timeSegmentKeyList; $time & ¶ & $$timeAll ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
#
#Add up total time for category it is in.
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $categoryKey ]
Perform Find [ ]
Sort Records [ Specified Sort Order: issue::_keyCategory; ascending ]
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
// Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
#
#Set new total time for category tag.
// Set Field [ issueCategory::issueTotalTime; issue::timeTotalSummaryByCategory ]
Set Field [ issueCategory::issueTotalTime; GetSummary ( issue::timeSummary ; issue::_keyCategory ) ]
#
Go to Layout [ original layout ]
#
#Conditionally format segment to show that it is assigned.
Set Field [ daylog::swLogTimeAccounting[$repetition]; $$issue ]
#
#Capture Day window time segment timer that is on.
Set Variable [ $$ActiveTimeSegment; Value:logs::swOccurances & logs::_lockDay ]
#
#If issue is not linked to day whose time has just
#been added to it, then link it.
Select Window [ Name: "Specific Action"; Current file ]
If [ issue::_LockList & "¶" ≠ FilterValues ( $$logIssues ; issue::_LockList & "¶" ) ]
Perform Script [ “linkActionToDay” ]
End If
#
#Inform user the timer is running for this specific
#action record with conditional formatting.
Select Window [ Name: "Day"; Current file ]
Go to Field [ ]
#
#
#
#
Else If [ Get (LastError) ≠ 401 ]
Go to Layout [ original layout ]
If [ $$specificActionTimer = "" ]
Show Custom Dialog [ Message: "Subtract time from act currently credited with it, so that it can be credited to a different
act?¶¶Go to act credited with this time?"; Buttons: “GoToAct”, “Subtract” ]
End If
If [ Get ( LastMessageChoice ) = 1 and $$specificActionTimer = "" ]
Go to Field [ ]
#
#Go to record time to which time will be added.
Select Window [ Name: "Specific Action"; Current file ]
#
#Get selected records number so it can be
#returned to if no linked record is found.
Set Variable [ $currentIssueNumber; Value:Get ( RecordNumber ) ]
#
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#If record is not showing then find and add it to
#list of records being shown.
If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") ≠ $timeSegment & "¶" ]
Enter Find Mode [ ]
Set Field [ issue::timeSegmentKeyList; $timeSegment & "¶" ]
Extend Found Set [ ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
Set Variable [ $$stopRecordLoad ]
#
#If no linked record is found return user to
#selected record.
If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") ≠ $timeSegment & "¶" ]
Go to Record/Request/Page [ $currentIssueNumber ]
[ No dialog ]
End If
Perform Script [ “loadIssuerecordID” ]
#
Exit Script [ ]
End If
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
Go to Layout [ “issueTime” (issueTime) ]
Set Variable [ $issueTimeDelete; Value:issueTime::_keyIssue ]
Delete Record/Request
[ No dialog ]
#
#Add up total time for issue.
Enter Find Mode [ ]
Set Field [ issueTime::_keyIssue; $issueTimeDelete ]
Perform Find [ ]
Set Variable [ $totalTime; Value:issueTime::sum ]
#
#Then subtract day and repetition keys from the list
#of all day and repetition keys for this issue.
Go to Layout [ “Issues” (issue) ]
Set Variable [ $time; Value:$repetition & $day ]
Enter Find Mode [ ]
Set Field [ issue::timeSegmentKeyList; $time ]
Perform Find [ ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
Set Field [ issue::timeSegmentKeyList; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item
is not removed, then the removal calc without the paragraph mark is used
If ( ValueCount ( $$timeAll ) ≠ ValueCount ( Substitute ( $$timeAll ; $time & "¶" ; "" ) ) ;
Substitute ( $$timeAll ; $time & "¶" ; "" ) ;
Substitute ( $$timeAll ; $time ; "" )
) ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
Set Field [ issue::issueTotalTime; $totalTime ]
#
#Add up total time for category it is in.
Go to Layout [ “Issues” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $categoryKey ]
Perform Find [ ]
Sort Records [ Specified Sort Order: issue::_keyCategory; ascending ]
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
// Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
#
#Set new total time for category tag.
// Set Field [ issueCategory::issueTotalTime; issue::timeTotalSummaryByCategory ]
Set Field [ issueCategory::issueTotalTime; GetSummary ( issue::timeSummary ; issue::_keyCategory ) ]
#
Go to Layout [ original layout ]
Go to Layout [ original layout ]
Go to Field [ ]
Select Window [ Name: "Specific Action"; Current file ]
#
#Inform user timer stopped running for this specific
#action record with conditional formatting.
Set Variable [ $$TimeAssignedToSpecificAction ]
End If
Set Variable [ $$stopRecordLoad ]
Select Window [ Name: "Specific Action"; Current file ]
Perform Script [ “loadIssuerecordID” ]
Select Window [ Name: "Day"; Current file ]
July 26, ଘ౮28 15:30:12 ActionLog.fp7 - addTimeSegmentToIssue -1-
