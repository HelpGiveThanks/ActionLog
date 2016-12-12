specific action log: CHUNK_updateIssueCategoryTime
#
#This script is used by the updateTime script
#and the clear script and the script
#stopTimerAssignedToSpecificAction.
#
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#FIRST capture current window so system can go
#to it after finished, otherwise
#UpdateTime script tries to continue in the wrong
#window, which is showing the wrong layout!
Set Variable [ $UpdateTimewindowName; Value:Get ( WindowName ) ]
#
#Find all issues with this Day record's time attributed
#to them. (This chunk script will be repeated
#for each timer used on this day. It handles
#one timer's specific actions at a time.)
New Window [ Name: "temp"; Height: 1; Width: 1; Top: -1000; Left: -1000 ]
// New Window [ Name: "temp" ]
Go to Field [ ]
Go to Layout [ “SpecificActionTable” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::timeSegmentKeyList; "*" & Replace ( Quote("1") ; 2 ; 1 ; $$updateDay ) ]
Perform Find [ ]
If [ Get (LastError) = 401 ]
#
#If none are found, it could mean the SPA
#record just had its only time segment for the
#day removed. Run a check on this record to
#to insure if it was just active that is
#inactivated, unless it is active on other days.
#
#
Close Window [ Name: "temp"; Current file ]
Exit Script [ ]
End If
#
#Make sure user is not in any fields before updating
#as this prevents update of time for the record
#the user is in (have not tested how yet).
Select Window [ Name: "Specific Action"; Current file ]
If [ Get (LastError) ≠ 112 ]
Go to Field [ ]
End If
#
#See if any of these Specific Action (issue)
#records are active on multiple days.
Select Window [ Name: "temp"; Current file ]
Perform Script [ “CHUNK_seeIfSPAisActiveOnOtherDays (new)” ]
#
#Get the ID of any specific action timer
#that may just have been turned on, so it
#can be found and shown at end of this script
#if it is not currently showing.
Go to Record/Request/Page
[ First ]
Loop
If [ $$logBrainstate = timer::_lockTimer ]
If [ FilterValues (specificAction::timeSegmentKeyList ; day1::swOccurances & day1::_lockDay & "¶" ) = day1::swOccurances
& day1::_lockDay & "¶" and day1::swBugField = "veto" ]
Set Variable [ $SpecificActionWindowFocusedOnThisIssue; Value:specificAction::_LockSpecificAction ]
End If
End If
Exit Loop If [ $SpecificActionWindowFocusedOnThisIssue ≠ "" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Make a list of all Specific Action (issue) records
#this day-record time segment's are linked to.
Go to Record/Request/Page
[ First ]
Loop
Set Variable [ $AllIssueRecordsNeedingUpdate; Value:specificAction::_LockSpecificAction & "¶" & $issueList ]
Set Variable [ $issueList; Value:$AllIssueRecordsNeedingUpdate ]
#
#Clear all records IF AND ONLY IF 'clearall'
#button has been clicked.
If [ $$clear = 1 ]
#
#Remove link to log from issue record and update
#the variable containing these links if any.
Set Field [ specificAction::_keyLogs; If ( ValueCount ( specificAction::_keyLogs ) ≠ ValueCount ( Substitute ( specificAction::
_keyLogs ; $$updateDay & "¶" ; "" ) ) ;
Substitute ( specificAction::_keyLogs ; $$updateDay & "¶" ; "" ) ;
Substitute ( specificAction::_keyLogs ; $$updateDay ; "" ) ) ]
Set Variable [ $$logissues; Value:logs::_keyLogSPAs ]
#
#Remove time segment key from list.
#(the teen numbers must come first otherwise
#the singly digits will delete 3 in 13 and leave
#behind an orphaned 1 for example)
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 11 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 12 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 13 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 14 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 15 & $$updateday & "¶" ;
"" ) ]
#
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 1 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 2 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 3 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 4 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 5 & $$updateday & "¶" ;
"" ) ]
#
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 6 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 7 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 8 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 9 & $$updateday & "¶" ;
"" ) ]
Set Field [ specificAction::timeSegmentKeyList; Substitute ( specificAction::timeSegmentKeyList ; 10 & $$updateday & "¶" ;
"" ) ]
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Update the time for each issueTime record in the list.
Loop
Set Variable [ $issue; Value:GetValue ( $AllIssueRecordsNeedingUpdate ; 1 ) ]
Set Variable [ $AllIssueRecordsNeedingUpdate; Value:If ( ValueCount ( $AllIssueRecordsNeedingUpdate ) ≠ ValueCount
( Substitute ( $AllIssueRecordsNeedingUpdate ; $issue & "¶" ; "" ) ) ;
Substitute ( $AllIssueRecordsNeedingUpdate ; $issue & "¶" ; "" ) ;
Substitute ( $AllIssueRecordsNeedingUpdate ; $issue ; "" ) ) ]
#
#Find all time segments attributed to this
#issue so their total time can be calculated.
Go to Layout [ “SPATimeTable” (SPATime) ]
Enter Find Mode [ ]
Set Field [ SPATime::_keySPA; $issue ]
Perform Find [ ]
#
#When there are no more issues to be found
#(thus, the find criteria are empty = error 400)
#exit the loop.
Exit Loop If [ Get (LastError) = 400 ]
Set Variable [ $totalTime; Value:SPATime::sum ]
#
#Update issue's total time field with the
#re-calculated total time.
Go to Layout [ “SpecificActionTable” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::_LockSpecificAction; $issue ]
Perform Find [ ]
Set Field [ specificAction::SPATotalTime; $totalTime ]
#
#Re-calculate total time all issues in this issue's
#issue group shown in the Tag Menu window.
Set Variable [ $categoryKey; Value:specificAction::_keyGroup ]
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
End Loop
#
Close Window [ Name: "temp"; Current file ]
#
#Conditionally format Specific Action record if
#the current time segement is active and assigned to it.
Select Window [ Name: "Specific Action"; Current file ]
#
#Get selected records number so it can be
#returned to if no linked record is found.
Set Variable [ $currentIssueNumber; Value:Get ( RecordNumber ) ]
#
#Check if the Specific Action window
#is showing the active specific action if there
#is one, and if not showing then find and
#show it.
If [ $SpecificActionWindowFocusedOnThisIssue ≠ "" ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Determine if the issue whose time is being updated
#is in the set of current found issues, and if
#not then find and show it.
If [ $SpecificActionWindowFocusedOnThisIssue ≠ specificAction::_LockSpecificAction ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $SpecificActionWindowFocusedOnThisIssue = specificAction::_LockSpecificAction ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#If not showing then find, show and focus on it.
#NOTE: See openSpecificAction script for
#altenate way to accomplish this by sorting
#most recently modified records to the top in
#order to speed up looping to active timer if
#there is one, and stopping looping after the
#first 10 recently modified records. Not sure
#if this is faster or not. Need to test.
If [ $SpecificActionWindowFocusedOnThisIssue ≠ specificAction::_LockSpecificAction ]
Enter Find Mode [ ]
Set Field [ specificAction::_LockSpecificAction; $SpecificActionWindowFocusedOnThisIssue ]
Extend Found Set [ ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $SpecificActionWindowFocusedOnThisIssue = specificAction::_LockSpecificAction ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
#
#If no linked record is found return user to
#selected record, but if found then load
#its variables.
If [ $SpecificActionWindowFocusedOnThisIssue ≠ specificAction::_LockSpecificAction ]
Go to Record/Request/Page [ $currentIssueNumber ]
[ No dialog ]
Else
Set Variable [ $$stopRecordLoad ]
Perform Script [ “loadIssuerecordID” ]
End If
End If
#
Set Variable [ $$stopRecordLoad ]
End If
#
If [ FilterValues (specificAction::timeSegmentKeyList ; day1::swOccurances & day1::_lockDay & "¶" ) = day1::swOccurances & $$log &
"¶" and day1::swBugField = "veto" ]
Set Variable [ $$day1BugField; Value:day1::swBugField ]
Else If [ day1::swBugField = "note" or day1::swBugField = "" ]
Set Variable [ $$day1BugField ]
End If
#
#Update totals for category tags, which takes
#a sort of data to return fresh totals.
Select Window [ Name: "Tag"; Current file ]
Set Variable [ $tagLayoutName; Value:Get (LayoutName) ]
If [ Get ( LayoutName ) = "IssuesAndObservationsTag" ]
Sort Records [ Specified Sort Order: TagGroup::order; based on value list: “1-99”
TagGroup::text; ascending
SPAGroupTag::sortTime; ascending
SPAGroupTag::text; ascending ]
[ Restore; No dialog ]
Else
Go to Layout [ “IssuesAndObservationsTag” (SPAGroupTag) ]
Sort Records [ Specified Sort Order: TagGroup::order; based on value list: “1-99”
TagGroup::text; ascending
SPAGroupTag::sortTime; ascending
SPAGroupTag::text; ascending ]
[ Restore; No dialog ]
Go to Layout [ $tagLayoutName ]
End If
#
Select Window [ Name: $UpdateTimewindowName; Current file ]
Exit Script [ ]
#
December 10, ଘ౮28 23:13:19 ActionLog.fp7 - CHUNK_updateIssueCategoryTime -1-
