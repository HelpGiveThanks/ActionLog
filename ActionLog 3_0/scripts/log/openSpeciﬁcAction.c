log: openSpeciﬁcAction
#PURPOSE open log window and select log entry for
#current record.
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Stop the load record scripts. They slow things down.
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Variable [ $$stopSubtotal; Value:1 ]
#
#I really need to decide on ONE means to store the
#current brainstate key, isntead of making up a new
#one for each module because I'm not sure how the
#others are being used. A deﬁnition of each variable
#and how it is used would be great!
Set Variable [ $$logBrainstate; Value:brainstate::_lockBrainstateID ]
#
Set Window Title [ Current Window; New Title: "Timer" ]
#
#Open a new window to test if any log records exist
#for this brainstate record. A log record will not exist
#if the user has never logged anytime for this brainstate.
New Window [ Name: "Day"; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: Get (ScreenWidth) - 688 ]
Set Zoom Level
[ 100% ]
#
#Find ﬁrst issue record if there is one and set variable
#to conditionally format times for the ﬁrst day record.
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
// Set Field [ issue::text; "speciﬁc action" ]
// #
// #makes all new issues stay at the top of the window
// #until a non-blank status is assigned to them.
// Set Field [ issue::_keyStatus; 6302011014838316 ]
// Go to Field [ ]
// Go to Field [ issue::text ]
Else
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
January 5, 平成26 19:28:29 ActionLog.fp7 - openSpeciﬁcAction -1-log: openSpeciﬁcAction
Go to Record/Request/Page
[ First ]
#
Set Variable [ $$stopSubtotal ]
Perform Script [ “TsubtotalTimeByGroup” ]
End If
#
Set Variable [ $$issue; Value:issue::_LockList ]
Set Variable [ $$status; Value:issue::_keyStatus ]
Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
Set Variable [ $$group; Value:issue::_keyCategory ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
#
#Now ﬁnd log records for this timer.
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $$logBrainstate ]
Perform Find [ ]
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
#Sort and go to ﬁrst record.
Sort Records [ Speciﬁed Sort Order: logs::_keyBrainstate; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
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
#Show all status and category menu items for
brainstate's log.
New Window [ Name: "Tag" ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
#
#Update review dates.
Go to Object [ Object Name: "status" ]
January 5, 平成26 19:28:29 ActionLog.fp7 - openSpeciﬁcAction -2-log: openSpeciﬁcAction
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
Set Field [ status::status; "Remember existence" & ¶ & "of a speciﬁc action..." ]
Loop
Set Field [ status::text; GetValue ( $reviewNames ; $number ) ]
Set Field [ status::reviewDate; GetValue ( $reviewDates ; $number ) ]
Set Variable [ $number; Value:$number + 1 ]
Go to Portal Row
[ Select; Next; Exit after last ]
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
January 5, 平成26 19:28:29 ActionLog.fp7 - openSpeciﬁcAction -3-log: openSpeciﬁcAction
Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
Set Field [ issueCategory::text; "administration" ]
Set Variable [ $groupKey; Value:issueCategory::_LockList ]
End If
#
Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
#
#
#Show all issues for this brainstate's log.
New Window [ Name: "Speciﬁc Action"; Height: Get (ScreenHeight); Width: Get (ScreenWidth) - 688; Top: 0; Left: 0 ]
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
Set Field [ issue::text; "review these speciﬁc action items and update their status, priority, and grouping as necessary." ]
Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
Set Field [ issue::_keyStatus; 7152011154818554 ]
Set Field [ issue::_keyCategory; $groupKey ]
End If
#
Go to Layout [ “Issues” (issue) ]
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
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
January 5, 平成26 19:28:29 ActionLog.fp7 - openSpeciﬁcAction -4-
