log: gotoLogs
#PURPOSE open log window and select log entry for
#current record.
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#If user remains in time edit field, conditional formatting
#fails to work in day window when time is assigned.
Go to Field [ ]
#
#Stop the load record scripts. They slow things down.
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Variable [ $$stopSubtotal; Value:1 ]
#
#I really need to decide on ONE means to store the
#current brainstate key, isntead of making up a new
#one for each module because I'm not sure how the
#others are being used. A definition of each variable
#and how it is used would be great!
Set Variable [ $$logBrainstate; Value:brainstate::_lockBrainstateID ]
Set Variable [ $day1; Value:reference::day1 ]
#
#If the user is already viewing the Specific Action
#and current day record for this timer then just
#show them these windows.
Select Window [ Name: "Day"; Current file ]
If [ logs::_keyBrainstate = $$logBrainstate and logs::_keyDay = $day1 ]
#
#Display all rows of time for this timer.
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
#
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
#
#Start load record scripts as needed for normal function.
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$stopSubtotal ]
Exit Script [ ]
#
#If only a new day has been added, then just update
#the Day window and show user the rest of the
#Specific Action windows without changing them.
Else If [ logs::_keyBrainstate = $$logBrainstate and logs::_keyDay ≠ $day1 ]
#
#Find new day record for this timer.
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $$logBrainstate ]
Perform Find [ ]
#
#Sort and go to first record.
Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
#Display all rows of time for this timer.
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
#
#For attaching issue record IDs to log records, and
#for conditionally formatting log records related to an issue,
#system needs to know what IDs are associated with a log record.
Set Variable [ $$log; Value:logs::_lockDay ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
#
#Start load record scripts as needed for normal function.
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$stopSubtotal ]
#
Perform Script [ “loadLogrecordID” ]
#
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
#
Exit Script [ ]
#
End If
#
#Find first issue record if there is one and set variable
#to conditionally format times for the first day record.
Go to Layout [ “Issues” (issue) ]
#
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
#
If [ Get ( LastError ) = 401 ]
// New Record/Request
// Set Field [ issue::_keyBrainstate; $$logBrainstate ]
// Set Field [ issue::_keyCategory; $groupID ]
// Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
// Set Field [ issue::lock; "issue" ]
// Set Field [ issue::text; "specific action" ]
// #
// #makes all new issues stay at the top of the window
// #until a non-blank status is assigned to them.
// Set Field [ issue::_keyStatus; 7152011154818554 ]
// Go to Field [ ]
// Go to Field [ issue::text ]
Else
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
#
Set Variable [ $$stopSubtotal ]
Perform Script [ “TsubtotalTimeByGroup (UPDATED)” ]
End If
#
Set Variable [ $$issue; Value:issue::_LockList ]
Set Variable [ $$status; Value:issue::_keyStatus ]
Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
Set Variable [ $$group; Value:issue::_keyCategory ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
#
#Now find log records for this timer.
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $$logBrainstate ]
Perform Find [ ]
#
#Sort and go to first record.
Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
#Display all rows of time for this timer.
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
#
#For attaching issue record IDs to log records, and
#for conditionally formatting log records related to an issue,
#system needs to know what IDs are associated with a log record.
Set Variable [ $$log; Value:logs::_lockDay ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
#
Refresh Window
#
#
#
#Show all status and category menu items for
brainstate's log.
Select Window [ Name: "Tag"; Current file ]
Go to Layout [ “IssuesAndObservationsTag” (category) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
Sort Records [ Specified Sort Order: group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
#
#Update timer's total time. This is only done
#when switching specific action timers rather than
#each time a timer's total is changed due to the
#amount of time it takes to calculate this total.
Perform Script [ “updateTimerTotalTimeInTagWindow (NEW)” ]
#
#FIX FIX FIX FIX
#FIX FIX FIX FIX
#FIX FIX FIX FIX
#FIX FIX FIX FIX
#FIX FIX FIX FIX
#
#Update review dates.
Go to Object [ Object Name: "status" ]
Go to Portal Row
[ Select; First ]
Set Variable [ $reviewNames; Value:"daily" & ¶ &
"weekly" & ¶ &
"monthly" & ¶ &
"1/2 yearly" & ¶ &
"yearly" & ¶ &
"complete" & ¶ &
"discard" ]
Set Variable [ $reviewDates; Value://daily review
"" & ¶ &
//weekly review
Case (
Day ( Get ( CurrentDate ) ) < 8 ;
Month ( Get ( CurrentDate ) ) - 1 & "/" ;
Month ( Get ( CurrentDate ) ) & "/" ) &
Case (
DayOfWeek ( Get ( CurrentDate ) ) = 1 ; Day ( Get ( CurrentDate ) ) ;
DayOfWeek ( Get ( CurrentDate ) - 1 ) = 1 ; Day ( Get ( CurrentDate ) - 1 ) ;
DayOfWeek ( Get ( CurrentDate ) - 2 ) = 1 ; Day ( Get ( CurrentDate ) - 2 ) ;
DayOfWeek ( Get ( CurrentDate ) - 3 ) = 1 ; Day ( Get ( CurrentDate ) - 3 ) ;
DayOfWeek ( Get ( CurrentDate ) - 4 ) = 1 ; Day ( Get ( CurrentDate ) - 4 ) ;
DayOfWeek ( Get ( CurrentDate ) - 5 ) = 1 ; Day ( Get ( CurrentDate ) - 5 ) ;
DayOfWeek ( Get ( CurrentDate ) - 6 ) = 1 ; Day ( Get ( CurrentDate ) - 6 ) )
//& " - "
&
//Month ( Get ( CurrentDate ) ) & "/" &
//Case (
//DayOfWeek ( Get ( CurrentDate ) ) = 7 ; Day ( Get ( CurrentDate ) ) ;
//DayOfWeek ( Get ( CurrentDate ) + 1 ) = 7 ; Day ( Get ( CurrentDate ) + 1 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 2 ) = 7 ; Day ( Get ( CurrentDate ) + 2 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 3 ) = 7 ; Day ( Get ( CurrentDate ) + 3 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 4 ) = 7 ; Day ( Get ( CurrentDate ) + 4 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 5 ) = 7 ; Day ( Get ( CurrentDate ) + 5 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 6 ) = 7 ; Day ( Get ( CurrentDate ) + 6 ) )
¶ &
//monthly review
" " &
Case (
Day ( Get ( CurrentDate ) ) > 7 ;
//MonthName ( Month ( Get ( CurrentDate ) ) + 1 & "/" & 1 & "/" & 2012) ;
//MonthName ( Month ( Get ( CurrentDate ) ) & "/" & 1 & "/" & 2012) )
//& ")"
Month ( Get ( CurrentDate ) ) + 1 & "/" & "1" ;
Month ( Get ( CurrentDate ) ) & "/" & "1" ) ]
Set Variable [ $number; Value:1 ]
If [ status::text = "" ]
Set Field [ status::status; "Remember existence" & ¶ & "of a specific action..." ]
Loop
Set Field [ status::text; GetValue ( $reviewNames ; $number ) ]
Set Field [ status::reviewDate; GetValue ( $reviewDates ; $number ) ]
Set Variable [ $number; Value:$number + 1 ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
#
#Find all groups for this action.
Go to Layout [ “menuGroups” (issueCategory) ]
Enter Find Mode [ ]
Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
Set Field [ issueCategory::lock; "location" ]
Perform Find [ ]
#
#If none are found then create one.
If [ Get ( LastError ) = 401 ]
New Record/Request
Set Field [ issueCategory::lock; "location" ]
Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
Set Field [ issueCategory::text; "administration" ]
Set Variable [ $groupKey; Value:issueCategory::_LockList ]
End If
#
Go to Layout [ “IssuesAndObservationsTag” (category) ]
#
#
#
#Show all issues for this brainstate's log.
Select Window [ Name: "Specific Action"; Current file ]
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
#
#If none are found then create one.
If [ Get ( LastError ) = 401 ]
New Record/Request
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
Set Field [ issue::lock; "issue" ]
Set Field [ issue::text; "review these specific action items and update their status, priority, and grouping as necessary." ]
Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
Set Field [ issue::_keyStatus; 7152011154818554 ]
Set Field [ issue::_keyCategory; $groupKey ]
End If
#
Go to Layout [ “Issues” (issue) ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
Set Variable [ $$issueSort; Value:"status" ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
#Start load record scripts as needed for normal function.
Set Variable [ $$stopRecordLoad ]
Perform Script [ “loadIssuerecordID (UPDATED)” ]
December 6, ଘ౮27 20:47:52 ActionLog.fp7 - gotoLogs -1-
