log: openSpecificAction
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
#Set timer variable (legacy name: brainstate)
#a newfor scripts steps below and for other
#specific action scripts.
Set Variable [ $$logBrainstate; Value:Case ( steward::DefaultSpecificAction ≠ "" ; steward::DefaultSpecificAction ; brainstate::
_lockBrainstateID ) ]
#
#Used in finding an active specific-action
#timer required to set the $activeIssueTimerNumber
#variable below.
Set Variable [ $$log; Value:day1::_lockDay ]
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
#Find first or active issue record and set variable
#to conditionally format times for the first day record.
Go to Layout [ “Issues” (issue) ]
#
#Check if there is an active timer linked any
#specific action records.
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
If [ day1::swBugField = "veto" ]
#
#To speed up finding process, sort records by
#modify date so most recently modified
#records sort the top, of which, the ative timer
#record should be in the top 10.
Sort Records [ Specified Sort Order: brainstate::description; ascending
issue::DisplayDateDone; descending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; day1::swOccurances & $$log & "¶" ) = day1::swOccurances & $$log
& "¶" and day1::swBugField = "veto" ]
Exit Loop If [ Get ( RecordNumber ) = 10 ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ FilterValues (issue::timeSegmentKeyList ; day1::swOccurances & $$log & "¶" ) = day1::swOccurances & $$log & "¶" and
day1::swBugField = "veto" ]
#
#If an active timer linked issue is found, then
#sort all issue records by status (which is the
#default sort at start up) and note this issues
#place in the list so it can be focused upon at
#this scripts end.
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Set Variable [ $activeIssueTimerNumber; Value:Get ( RecordNumber ) ]
Else
#
#If no active timer linked issue is found in the
#first 10 looped thru, then default sort the
#records and select the first one.
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
End If
Else
#
#If no active timer is on right now (thus there
#is no issue linked to an active timer), then
#default sort the records and select the first one.
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
End If
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
// Set Field [ issue::_keyStatus; 6302011014838316 ]
// Go to Field [ ]
// Go to Field [ issue::text ]
Else
Set Variable [ $$stopSubtotal ]
Perform Script [ “TsubtotalTimeByGroup” ]
End If
#
#Now format the specific action record
#selected for the user to see by the processes above.
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
#Display all rows of time for this timer.
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
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
#Set variables used for attaching Specific Action
#record IDs to Day records, and for conditionally
#formatting Day records related to Specific
#Action records.
Set Variable [ $$log; Value:logs::_lockDay ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$day1BugField; Value:logs::swBugField ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
#
#Inform other scripts if user is on or not on
#the Today or Yesterday record. This info will
#speed them up, since they will not have to
#check this out for themselves.
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
Set Field [ reference::ActivityLogDayRecordNumber; Get (RecordNumber) ]
#
Refresh Window
#
#Find all category tags for this timer.
New Window [ Name: "Tag" ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
Go to Layout [ “IssuesAndObservationsTag” (category) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
#
#If none are found then create one.
If [ Get ( LastError ) = 401 ]
Perform Script [ “newTagGroup” ]
End If
Sort Records [ Specified Sort Order: group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Variable [ $newtag; Value:category::_LockList ]
#
#Update timer's total time. This is only done now
#when selecting a specific action timer rather than
#each time a timer's total is changed due to the
#amount of time it takes to calculate this total.
Perform Script [ “updateTimerTotalTimeInTagWindow” ]
#
#Turn this variable back on as it is shut off
#when the script above was performed.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Find all status tags.
Set Variable [ $brainstateName; Value:brainstate::description ]
Go to Layout [ “IssuesAndObservationsStatus” (status) ]
Enter Find Mode [ ]
Set Field [ status::lock; "status" ]
Perform Find [ ]
Set Field [ status::status; $brainstateName ]
Sort Records [ Specified Sort Order: status::order; ascending
status::text; ascending ]
[ Restore; No dialog ]
#
#Create status tags if none exist.
Go to Layout [ “IssuesAndObservationsStatus” (status) ]
Set Variable [ $reviewNames; Value:"priority" & ¶ &
"active" & ¶ &
"pending" & ¶ &
"on hold" & ¶ &
"backlog" & ¶ &
"complete" & ¶ &
"discard" ]
Set Variable [ $number; Value:1 ]
If [ Get (FoundCount) = 0 ]
Loop
New Record/Request
Set Field [ status::text; GetValue ( $reviewNames ; $number ) ]
Set Variable [ $number; Value:$number + 1 ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
Go to Record/Request/Page
[ First ]
Set Variable [ $newStatus; Value:status::_LockList ]
#
#Show all category tags for this timer.
Go to Layout [ “IssuesAndObservationsTag” (category) ]
#
#Show all issues for this brainstate's log.
New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: Get (ScreenWidth) - 688; Top: 0; Left: 0 ]
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
Set Field [ issue::_keyStatus; $newStatus ]
Set Field [ issue::_keyCategory; $newTag ]
#
#Now format the specific action record
#selected for the user to see by the processes above.
Set Variable [ $$issue; Value:issue::_LockList ]
Set Variable [ $$status; Value:issue::_keyStatus ]
Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
Set Variable [ $$group; Value:issue::_keyCategory ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
#
Refresh Window
End If
#
Go to Layout [ “Issues” (issue) ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Set Variable [ $$issueSort; Value:"status" ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
If [ $activeIssueTimerNumber ≠ "" and $activeIssueTimerNumber ≠ 1 ]
Go to Record/Request/Page [ $activeIssueTimerNumber ]
[ No dialog ]
End If
#
#Assign status to issue if it doesn't have one.
If [ issue::_keyStatus = "" ]
Set Field [ issue::_keyStatus; $newStatus ]
End If
#
#Start load record scripts as needed for normal function.
Set Variable [ $$stopRecordLoad ]
#
#If user clicked on the pulldown when the focus
#of the system was on another record, this
#variable prevents the pulldown menu from
#flashing and going away. It needs to be reset
#when the user navigates to the record other than
#by click on the pulldown menus so the user
#doesn't get bumped out of the menu field
#if the database is focused on the record whose
#menus the user is trying to access.
Set Variable [ $$pulldownCheck; Value:Get (RecordID) ]
Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
Set Variable [ $$stopIssuePulldownMenus; Value:1 ]
#
July 13, ଘ౮28 13:34:50 ActionLog.fp7 - openSpecificAction -1-
