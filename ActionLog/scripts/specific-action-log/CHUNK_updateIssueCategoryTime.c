speciﬁc action log: CHUNK_updateIssueCategoryTime
#
#This script is used by the updateTime script
#and the clear script.
#
Allow User Abort [ Off ]
Set Error Capture [ On ]
#FIRST capture current window so system can go
#to it after ﬁnished, otherwise
#UpdateTime script tries to continue in the wrong
#window, which is showing the wrong layout!
Set Variable [ $UpdateTimewindowName; Value:Get ( WindowName ) ]
#
#Find all issues with this day record's time attributed
#to them.
Go to Field [ ]
#
New Window [ Name: "temp"; Height: 1; Width: 1; Top: -1000; Left: -1000 ]
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::timeSegmentKeyList; "*" & Replace ( Quote("1") ; 2 ; 1 ; $$updateDay ) ]
Perform Find [ ]
If [ Get (LastError) = 401 ]
Close Window [ Name: "temp"; Current ﬁle ]
Exit Script [ ]
End If
#
#Make sure user is not in any ﬁelds before updating
#as this prevents update of time for the record
#the user is in (have not test how yet).
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
If [ Get (LastError) ≠ 112 ]
Go to Field [ ]
End If
#
Select Window [ Name: "temp"; Current ﬁle ]
#
#Make a list of them.
Go to Record/Request/Page
[ First ]
Loop
Set Variable [ $AllIssueRecordsNeedingUpdate; Value:issue::_LockList & "¶" & $issueList ]
Set Variable [ $issueList; Value:$AllIssueRecordsNeedingUpdate ]
If [ $$clear = 1 ]
#
#Remove link to log from issue record.
Set Field [ issue::_keyLogs; If ( ValueCount ( issue::_keyLogs ) ≠ ValueCount ( Substitute ( issue::_keyLogs ; $$updateDay & "¶" ;
"" ) ) ;
Substitute ( issue::_keyLogs ; $$updateDay & "¶" ; "" ) ;
Substitute ( issue::_keyLogs ; $$updateDay ; "" ) ) ]
#
#Remove time segment key from list.
#(the teen numbers must come ﬁrst otherwise
#the singly digits will delete 3 in 13 and leave
#behind an orphaned 1 for example)
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 11 & $$updateday & "¶" ; "" ) ]
Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 12 & $$updateday & "¶" ; "" ) ]
January 6, 平成26 11:06:57 ActionLog.fp7 - CHUNK_updateIssueCategoryTime -1-speciﬁc action log: CHUNK_updateIssueCategoryTime
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
#Update the time for each issue in the list.
Loop
Set Variable [ $issue; Value:GetValue ( $AllIssueRecordsNeedingUpdate ; 1 ) ]
Set Variable [ $AllIssueRecordsNeedingUpdate; Value:If ( ValueCount ( $AllIssueRecordsNeedingUpdate ) ≠ ValueCount ( Substitute
( $AllIssueRecordsNeedingUpdate ; $issue & "¶" ; "" ) ) ;
Substitute ( $AllIssueRecordsNeedingUpdate ; $issue & "¶" ; "" ) ;
Substitute ( $AllIssueRecordsNeedingUpdate ; $issue ; "" ) ) ]
#
#Find all time segments attributed to this issue.
Go to Layout [ “issueTime” (issueTime) ]
Enter Find Mode [ ]
Set Field [ issueTime::_keyIssue; $issue ]
Perform Find [ ]
Exit Loop If [ Get (LastError) = 400 ]
#
#Get total time for this issue.
Set Variable [ $totalTime; Value:issueTime::sum ]
#
#And update this issue's total time.
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_LockList; $issue ]
Perform Find [ ]
Set Field [ issue::issueTotalTime; $totalTime ]
#
#Add up total time for category it is in.
Set Variable [ $categoryKey; Value:issue::_keyCategory ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $categoryKey ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: issue::sortTime; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
Go to Record/Request/Page
[ Next; Exit after last ]
January 6, 平成26 11:06:57 ActionLog.fp7 - CHUNK_updateIssueCategoryTime -2-speciﬁc action log: CHUNK_updateIssueCategoryTime Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#
#Disabled the next chunk after deciding it was
#better to use ﬁlemaker's subtotal calc rather
#doing it with this script chunk whose beneﬁt
#was subtotaling items in a category even when
#items where divided by status. Filemaker's
#subtotal calc subtotals at the status and category
#breaks (essentially all breaks caused by a sort)
#but I decided to show issue the time by status
#and category too, so that is why this script chunk
#is now disabled. The other reason was that it
#bogged down the system taking a long time to run.
// #To reset all the category subtotal times, ﬁrst ﬁnd
// #and sort all this issues records.
// Set Variable [ $brainstateIssues; Value:issue::_keyBrainstate ]
// Enter Find Mode [ ]
// Set Field [ issue::_keyBrainstate; $brainstateIssues ]
// Perform Find [ ]
// Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
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
// #Return the ﬁrst record in this subset and give it
// #the subset total, then give the subtotal to all
// #records in this subset.
// Go to Record/Request/Page [ $recordNumber ]
[ No dialog ]
January 6, 平成26 11:06:57 ActionLog.fp7 - CHUNK_updateIssueCategoryTime -3-speciﬁc action log: CHUNK_updateIssueCategoryTime
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
End Loop
#
#
#
Close Window [ Name: "temp"; Current ﬁle ]
#
// #If user cleared record then need to check if there
// #are log records to show user, and if not close the
// #log windows if they are open.
// #
// Select Window [ Name: "Day"; Current ﬁle ]
// If [ Get (LastError) = 112 ]
// Select Window [ Name: $UpdateTimewindowName; Current ﬁle ]
// Exit Script [ ]
// End If
// #
// If [ daylog::swActivityLength[11] ≠ "" ]
// Go to Layout [ “logs3rows” (logs) ]
// Else If [ daylog::swActivityLength[6] ≠ "" ]
// Go to Layout [ “logs2rows” (logs) ]
// Else If [ daylog::swActivityLength[6] = "" ]
// Go to Layout [ “logs1row” (logs) ]
// End If
// Refresh Window
Select Window [ Name: $UpdateTimewindowName; Current ﬁle ]
Exit Script [ ]
January 6, 平成26 11:06:57 ActionLog.fp7 - CHUNK_updateIssueCategoryTime -4-
