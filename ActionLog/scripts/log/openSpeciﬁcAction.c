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
#I really need to decide on ONE means to store the
#current brainstate key, isntead of making up a new
#one for each module because I'm not sure how the
#others are being used. A definition of each variable
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
// Set Field [ issue::_keyStatus; 6302011014838316 ]
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
#For attaching issue record IDs to log records, and
#for conditionally formatting log records related to an issue,
#system needs to know what IDs are associated with a log record.
Set Variable [ $$log; Value:logs::_lockDay ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
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
Perform Script [ “newTagGroup (NEW SCRIPT)” ]
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
Perform Script [ “updateTimerTotalTimeInTagWindow (NEW)” ]
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
If [ issue::_keyStatus = "" ]
Set Field [ issue::_keyStatus; $newStatus ]
End If
#
#Start load record scripts as needed for normal function.
Set Variable [ $$stopRecordLoad ]
December 6, ଘ౮27 20:45:51 ActionLog.fp7 - openSpecificAction -1-
