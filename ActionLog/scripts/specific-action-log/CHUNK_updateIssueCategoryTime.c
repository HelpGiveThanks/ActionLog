specific action log: CHUNK_updateIssueCategoryTime
#
#This script is used by the updateTime script
#and the clear script and the script
#stopTimerAssignedToSpecificAction.
#
Allow User Abort [ Off ]
Set Error Capture [ On ]
#FIRST capture current window so system can go
#to it after finished, otherwise
#UpdateTime script tries to continue in the wrong
#window, which is showing the wrong layout!
Set Variable [ $UpdateTimewindowName; Value:Get ( WindowName ) ]
#
#Find all issues with this day record's time attributed
#to them.
Go to Field [ ]
#
New Window [ Name: "temp"; Height: 1; Width: 1; Top: -1000; Left: -1000 ]
// New Window [ Name: "temp" ]
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::timeSegmentKeyList; "*" & Replace ( Quote("1") ; 2 ; 1 ; $$updateDay ) ]
Perform Find [ ]
If [ Get (LastError) = 401 ]
Close Window [ Name: "temp"; Current file ]
Exit Script [ ]
End If
#
#Determine if the Specific Action window is
#focused on timer being updated by this script.
#If it is, set a variable to make a note of this for
#use at the end of this script where the
#Specifci Action window's conditional
#formatting is adjusted as needed.
If [ $$logBrainstate = issue::_keyBrainstate ]
Set Variable [ $SpecificActionWindowFocusedOnThisIssue; Value:issue::_LockList ]
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
Select Window [ Name: "temp"; Current file ]
#
#Make a list of them.
Go to Record/Request/Page
[ First ]
Loop
Set Variable [ $AllIssueRecordsNeedingUpdate; Value:issue::_LockList & "¶" & $issueList ]
Set Variable [ $issueList; Value:$AllIssueRecordsNeedingUpdate ]
If [ $$clear = 1 ]
#
#Remove link to log from issue record and update
#the variable containing these links if any.
Set Field [ issue::_keyLogs; If ( ValueCount ( issue::_keyLogs ) ≠ ValueCount ( Substitute ( issue::_keyLogs ; $$updateDay &
"¶" ; "" ) ) ;
Substitute ( issue::_keyLogs ; $$updateDay & "¶" ; "" ) ;
Substitute ( issue::_keyLogs ; $$updateDay ; "" ) ) ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
#
#Remove time segment key from list.
#(the teen numbers must come first otherwise
#the singly digits will delete 3 in 13 and leave
#behind an orphaned 1 for example)
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 11 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 12 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 13 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 14 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 15 & $$updateday & "¶" ; "" ) ]
#
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 1 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 2 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 3 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 4 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 5 & $$updateday & "¶" ; "" ) ]
#
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 6 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 7 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 8 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 9 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 10 & $$updateday & "¶" ; "" ) ]
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
Go to Layout [ “issueTime” (issueTime) ]
Enter Find Mode [ ]
Set Field [ issueTime::_keyIssue; $issue ]
Perform Find [ ]
Exit Loop If [ Get (LastError) = 400 ]
Set Variable [ $totalTime; Value:issueTime::sum ]
#
#Update issue's total time field with the
#re-calculated total time.
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_LockList; $issue ]
Perform Find [ ]
Set Field [ issue::issueTotalTime; $totalTime ]
#
#Re-calculate total time all issues in this issue's
#issue group shown in the Tag Menu window.
Set Variable [ $categoryKey; Value:issue::_keyCategory ]
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
#
#Disabled the next chunk after deciding it was
#better to use filemaker's subtotal calc rather
#doing it with this script chunk whose benefit
#was subtotaling items in a category even when
#items where divided by status. Filemaker's
#subtotal calc subtotals at the status and category
#breaks (essentially all breaks caused by a sort)
#but I decided to show issue the time by status
#and category too, so that is why this script chunk
#is now disabled. The other reason was that it
#bogged down the system taking a long time to run.
// #To reset all the category subtotal times, first find
// #and sort all this issues records.
// Set Variable [ $brainstateIssues; Value:issue::_keyBrainstate ]
// Enter Find Mode [ ]
// Set Field [ issue::_keyBrainstate; $brainstateIssues ]
// Perform Find [ ]
// Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issue::timeTotalSummaryByCategory; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
// Go to Record/Request/Page
[ First ]
// #
// #
// #AddUp total time showing for this subset of
// #a cateogory broken up into subsets by different
// #statuses, like the subset of some category's
// #record that are pending, or completed, etc.
// Loop
// Set Variable [ $category; Value:issue::_keyCategory ]
// Set Variable [ $status; Value:issue::_keyStatus ]
// Set Variable [ $recordNumber; Value:Get (RecordNumber) ]
// Set Variable [ $subsetTotal ]
// Set Variable [ $oldTotal ]
// #
// Loop
// Set Variable [ $subsetTotal; Value:issue::issueTotalTime + $oldTotal ]
// Set Variable [ $oldTotal; Value:$subsetTotal ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// Exit Loop If [ issue::_keyCategory ≠ $category
//This next step I thought could happen, but then realized it can nevery happen
//or
//issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
// End Loop
// #
// #Return the first record in this subset and give it
// #the subset total, then give the subtotal to all
// #records in this subset.
// Go to Record/Request/Page [ $recordNumber ]
[ No dialog ]
// #
// Loop
// Set Field [ issue::timeTotalSumByCatSortedByStatus; $subsetTotal ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// Exit Loop If [ issue::_keyCategory ≠ $category
//This next step I thought could happen, but then realized it can nevery happen
//or
//issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
// End Loop
// #
// Exit Loop If [ Get (LastError) = 101 ]
// End Loop
End Loop
#
Close Window [ Name: "temp"; Current file ]
#
#Conditionally format Specific Action record if
#the current time segement is active and assigned to it.
#
#Check if the Specific Action window
#is focused on this updating timer.
Select Window [ Name: "Specific Action"; Current file ]
If [ $SpecificActionWindowFocusedOnThisIssue ≠ "" ]
#
#Determine if the issue whose time is being updated
#is showing in the Specific Action window, and if
#not then find and show it.
If [ $SpecificActionWindowFocusedOnThisIssue ≠ issue::_LockList ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $SpecificActionWindowFocusedOnThisIssue ≠ issue::_LockList ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#If not showing then find, show and focus on it.
If [ $SpecificActionWindowFocusedOnThisIssue ≠ issue::_LockList ]
Enter Find Mode [ ]
Set Field [ issue::_LockList; $SpecificActionWindowFocusedOnThisIssue ]
Extend Found Set [ ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $SpecificActionWindowFocusedOnThisIssue ≠ issue::_LockList ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
#
Set Variable [ $$stopRecordLoad ]
Perform Script [ “loadIssuerecordID” ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
End If
#
#Set ActiveTimeSegment variable to on or off
#state, which is used by the script
#stopTimerAssignedToSpecificAction.
#NOTE: Need to test if this variable is really
#being used anymore.
If [ FilterValues (issue::timeSegmentKeyList ; day1::swOccurances & day1::_lockDay & "¶" ) = day1::swOccurances & $$log & "¶"
and day1::swBugField = "veto" ]
Set Variable [ $$ActiveTimeSegment; Value:day1::swOccurances & day1::_lockDay ]
Else If [ day1::swBugField = "note" or day1::swBugField = "" ]
Set Variable [ $$ActiveTimeSegment ]
End If
End If
#
If [ FilterValues (issue::timeSegmentKeyList ; day1::swOccurances & day1::_lockDay & "¶" ) = day1::swOccurances & $$log & "¶" and
day1::swBugField = "veto" ]
Set Variable [ $$day1BugField; Value:day1::swBugField ]
Else If [ day1::swBugField = "note" or day1::swBugField = "" ]
Set Variable [ $$day1BugField ]
End If
#
#Update totals for category tags.
Select Window [ Name: "Tag"; Current file ]
Set Variable [ $tagLayoutName; Value:Get (LayoutName) ]
If [ Get ( LayoutName ) = "IssuesAndObservationsTag" ]
Sort Records [ Specified Sort Order: group::order; based on value list: “1-99”
group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
Else
Go to Layout [ “IssuesAndObservationsTag” (category) ]
Sort Records [ Specified Sort Order: group::order; based on value list: “1-99”
group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
Go to Layout [ $tagLayoutName ]
End If
#
Select Window [ Name: $UpdateTimewindowName; Current file ]
Exit Script [ ]
January 3, ଘ౮28 20:14:48 ActionLog.fp7 - CHUNK_updateIssueCategoryTime -1-
