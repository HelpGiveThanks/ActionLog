specific action log: deleteIssue
Set Variable [ $delete; Value:issue::_LockList ]
Set Variable [ $$stopCategoryRequest; Value:1 ]
Set Variable [ $name; Value:issue::text ]
Go to Object [ Object Name: 5 ]
Refresh Window
Show Custom Dialog [ Title: "!"; Message: "Delete, " & Case ( Length ($name) < 26 ; $name ; Left ($name ; 30) ) & " ... ?"; Buttons:
“Cancel”, “Delete” ]
Show Custom Dialog [ Title: "!"; Message: "Delete, " & Case ( Length ($name) < 26 ; $name ; Left ($name ; 30) ) & " ... ?"; Buttons:
“Cancel”, “Delete” ]
#
If [ Get ( LastMessageChoice ) = 2 ]
#
If [ issue::issueTotalTime ≠ "" ]
#
#Prevent windows from flashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
New Window [ Name: "temp" ]
#
#Exit issue field so conditional formatting can be applied.
Go to Field [ ]
#
#Prepare to remove issue time for category.
Set Variable [ $categoryKey; Value:issue::_keyCategory ]
Set Field [ issue::issueTotalTime; "" ]
#
#Eliminate this issue's time from the all the time
#assigned to its category.
Go to Layout [ “issueTime” (issueTime) ]
Enter Find Mode [ ]
Set Field [ issueTime::_keyIssue; $$issue ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
Perform Find [ ]
Delete All Records
[ No dialog ]
#
#Add up total time for category it was in.
Go to Layout [ “Issues” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $categoryKey ]
Perform Find [ ]
Sort Records [ Specified Sort Order: issue::sortTime; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Find all day records linked to this issue.
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyLogIssues; $$issue ]
Perform Find [ ]
Go to Record/Request/Page
[ First ]
Loop
#
#Remove issue key from an activity log (day) records.
Set Variable [ $logIssues; Value:logs::_keyLogIssues ]
Set Field [ logs::_keyLogIssues; //last item in list has no paragraph mark, so a valuecount test needs to be done and if
item is not removed, then the removal calc without the paragraph mark is used.
If ( ValueCount ( $logIssues ) ≠ ValueCount ( Substitute ( $logIssues ; $$issue & "¶" ; "" ) ) ;
Substitute ( $logIssues ; $$issue & "¶" ; "" ) ;
Substitute ( $logIssues ; $$issue ; "" )
) ]
#
#Remove issue key from repetitions for each record.
Set Variable [ $repetition; Value:1 ]
Loop
If [ logs::swLogTimeAccounting[$repetition] = $$issue ]
Set Field [ logs::swLogTimeAccounting[$repetition]; "" ]
End If
Set Variable [ $repetition; Value:$repetition + 1 ]
Exit Loop If [ $repetition = 31 ]
End Loop
#
#Go to next day record.
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
Set Variable [ $$stopRecordLoad ]
#
Close Window [ Name: "temp"; Current file ]
End If
#
Delete Record/Request
[ No dialog ]
End If
#
Set Variable [ $delete ]
Set Variable [ $$stopCategoryRequest ]
Select Window [ Name: "Specific Action"; Current file ]
Go to Field [ issue::text ]
Go to Field [ ]
Refresh Window
#
December 6, ଘ౮27 21:08:46 ActionLog.fp7 - deleteIssue -1-
