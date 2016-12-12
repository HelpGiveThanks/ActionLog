specific actions: openSpecificAction
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Stop the load record scripts.
#They slow things down.
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Variable [ $$stopSubtotal; Value:1 ]
#
#Set timer variable (legacy name: brainstate)
#used for scripts steps below and for other
#specific action scripts.
Set Variable [ $$logBrainstate; Value:Case ( user::DefaultSpecificAction ≠ "" ; user::DefaultSpecificAction ; timer::_lockTimer ) ]
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
Go to Layout [ “Issues” (specificAction) ]
#
#Check if there is an active timer linked to any
#specific action records.
Enter Find Mode [ ]
Set Field [ specificAction::_keyTimer; $$logBrainstate ]
Set Field [ specificAction::lock; "issue" ]
Perform Find [ ]
If [ day1::swBugField = "veto" ]
#
#To speed up finding process, sort records by
#modify date so most recently modified
#records sort the top, of which, the ative timer
#record should be in the top 10.
Sort Records [ Specified Sort Order: timer::description; ascending
specificAction::DisplayDateDone; descending
SPAStatus::order; ascending
SPAStatus::text; ascending
SPAGroupTag 2::order; ascending
SPAGroupTag 2::text; ascending
specificAction::order; based on value list: “1-99”
specificAction::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ FilterValues (specificAction::timeSegmentKeyList ; day1::swOccurances & $$log & "¶" ) = day1::
swOccurances & $$log & "¶" and day1::swBugField = "veto" ]
Exit Loop If [ Get ( RecordNumber ) = 10 ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ FilterValues (specificAction::timeSegmentKeyList ; day1::swOccurances & $$log & "¶" ) = day1::swOccurances & $$log & "¶"
and day1::swBugField = "veto" ]
#
#If an active timer linked issue is found, then
#sort all issue records by status (which is the
#default sort at start up) and note this issues
#place in the list so it can be focused upon at
#this scripts end.
Sort Records [ Specified Sort Order: timer::description; ascending
SPAStatus::order; ascending
SPAStatus::text; ascending
SPAGroupTag 2::order; ascending
SPAGroupTag 2::text; ascending
specificAction::order; based on value list: “1-99”
specificAction::text; ascending ]
[ Restore; No dialog ]
Set Variable [ $activeIssueTimerNumber; Value:Get ( RecordNumber ) ]
Else
#
#If no active timer linked issue is found in the
#first 10 looped thru, then default sort the
#records and select the first one.
Sort Records [ Specified Sort Order: timer::description; ascending
SPAStatus::order; ascending
SPAStatus::text; ascending
SPAGroupTag 2::order; ascending
SPAGroupTag 2::text; ascending
specificAction::order; based on value list: “1-99”
specificAction::text; ascending ]
[ Restore; No dialog ]
End If
Else
#
#If no active timer is on right now (thus there
#is no issue linked to an active timer), then
#default sort the records and select the first one.
Sort Records [ Specified Sort Order: timer::description; ascending
SPAStatus::order; ascending
SPAStatus::text; ascending
SPAGroupTag 2::order; ascending
SPAGroupTag 2::text; ascending
specificAction::order; based on value list: “1-99”
specificAction::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
End If
#
If [ Get ( LastError ) = 401 ]
// New Record/Request
// Set Field [ specificAction::_keyTimer; $$logBrainstate ]
// Set Field [ specificAction::_keyGroup; $groupID ]
// Set Field [ specificAction::date; Get ( CurrentTimeStamp ) ]
// Set Field [ specificAction::lock; "issue" ]
// Set Field [ specificAction::text; "specific action" ]
// #
// #makes all new issues stay at the top of the window
// #until a non-blank status is assigned to them.
// Set Field [ specificAction::_keyStatus; 6302011014838316 ]
// Go to Field [ ]
// Go to Field [ specificAction::text ]
Else
Set Variable [ $$stopSubtotal ]
Perform Script [ “TsubtotalTimeByGroup” ]
End If
#
#Now format the specific action record
#selected for the user to see by the processes above.
Set Variable [ $$issue; Value:specificAction::_LockSpecificAction ]
Set Variable [ $$status; Value:specificAction::_keyStatus ]
Set Variable [ $$issueLogs; Value:specificAction::_keyLogs ]
Set Variable [ $$group; Value:specificAction::_keyGroup ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
#
#Now find log records for this timer.
Go to Layout [ “logs1row” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyTimer; $$logBrainstate ]
Perform Find [ ]
#
#Sort and go to first record.
Sort Records [ Specified Sort Order: logs::_keyTimer; descending
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
#Set variables used for attaching Specific Action
#record IDs to Day records, and for conditionally
#formatting Day records related to Specific
#Action records.
Set Variable [ $$log; Value:logs::_lockDay ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$logissues; Value:logs::_keyLogSPAs ]
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
Go to Layout [ “IssuesAndObservationsTag” (SPAGroupTag) ]
Enter Find Mode [ ]
Set Field [ timer::_lockTimer; $$logBrainstate ]
Perform Find [ ]
#
#If none are found then create one.
If [ Get ( FoundCount ) = 0 ]
Set Variable [ $$TagNameRequired; Value:1 ]
#
#Create new group record.
New Record/Request
Set Field [ SPAGroupTag::lock; "group" ]
Set Field [ SPAGroupTag::_keyTimer; $$logBrainstate ]
Set Field [ SPAGroupTag::text; "Admin" ]
Set Variable [ $group; Value:SPAGroupTag::_LockSpecificAction ]
#
#Remove it so it only shows up as a header and
#and not as both a header and a tag.
Omit Record
#
#Create a new tag record and assign it to this new
#group so the group will show up as its header.
New Record/Request
Set Field [ SPAGroupTag::lock; "location" ]
Set Field [ SPAGroupTag::_keyTimer; $$logBrainstate ]
Set Field [ SPAGroupTag::_keyGroup; $group ]
Set Field [ SPAGroupTag::text; "Administration" ]
Set Variable [ $groupKey; Value:SPAGroupTag::_LockSpecificAction ]
#
#Turn off variable set at start of script.
Set Variable [ $$TagNameRequired ]
End If
#
#Sort records so group headers will show up.
Sort Records [ Specified Sort Order: TagGroup::text; ascending
SPAGroupTag::sortTime; ascending
SPAGroupTag::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Variable [ $newtag; Value:SPAGroupTag::_LockSpecificAction ]
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
Set Variable [ $brainstateName; Value:timer::description ]
Go to Layout [ “IssuesAndObservationsStatus” (status) ]
Enter Find Mode [ ]
Set Field [ status::lock; "status" ]
Perform Find [ ]
Set Field [ status::status; $brainstateName ]
Sort Records [ Specified Sort Order: status::order; ascending
status::text; ascending ]
[ Restore; No dialog ]
#
#The ActionLog will always be released with 7
#status tag records, so there is never a need
#to create them. BUT if for some reason they
#do get deleted then recreate them with the
#same ID numbers.
If [ Get (FoundCount) = 0 ]
#Set names.
Set Variable [ $names; Value:"priority" & ¶ &
"active" & ¶ &
"pending" & ¶ &
"on hold" & ¶ &
"backlog" & ¶ &
"complete" & ¶ &
"discard" ]
#Set order.
Set Variable [ $order; Value:"01" & ¶ &
10 & ¶ &
30 & ¶ &
35 & ¶ &
40 & ¶ &
50 & ¶ &
80 & ¶ ]
#Set ID numbers.
Set Variable [ $ID; Value:"6302011014838316" & ¶ &
"7152011154818554" & ¶ &
"7012011225345430" & ¶ &
"6282011175345221" & ¶ &
"7102011010856482" & ¶ &
"6282011175339220" & ¶ &
"6282011175349222" & ¶ ]
#Set records' number.
Set Variable [ $recordNumber; Value:"316" & ¶ &
"554" & ¶ &
"430" & ¶ &
"221" & ¶ &
"482" & ¶ &
"220" & ¶ &
"222" & ¶ ]
Set Variable [ $number; Value:1 ]
Loop
New Record/Request
Set Field [ status::text; GetValue ( $names ; $number ) ]
Set Field [ status::order; GetValue ( $order ; $number ) ]
Set Field [ status::_LockSpecificAction; GetValue ($ID ; $number ) ]
Set Field [ status::_Number; GetValue ($recordNumber ; $number ) ]
Set Field [ status::lock; "status" ]
Set Variable [ $number; Value:$number + 1 ]
Exit Loop If [ $number = 8 ]
End Loop
End If
#
#Show all group tags for this timer.
Go to Layout [ “IssuesAndObservationsTag” (SPAGroupTag) ]
#
#Show all this timer's specific action records.
New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: Get (ScreenWidth) - 688; Top: 0; Left: 0 ]
Go to Layout [ “SpecificActionTable” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::_keyTimer; $$logBrainstate ]
Set Field [ specificAction::lock; "issue" ]
Perform Find [ ]
#
#If none are found then create one.
If [ Get ( LastError ) = 401 ]
New Record/Request
Set Field [ specificAction::_keyTimer; $$logBrainstate ]
Set Field [ specificAction::date; Get ( CurrentTimeStamp ) ]
Set Field [ specificAction::lock; "issue" ]
Set Field [ specificAction::text; "review these specific action items and update their status, priority, and grouping as necessary." ]
Set Field [ timer::pulldownTimer; specificAction::_keyTimer ]
Set Field [ specificAction::_keyStatus; 7152011154818554 ]
Set Field [ specificAction::_keyGroup; $newTag ]
#
#Now format the specific action record
#selected for the user to see as the active record.
Set Variable [ $$issue; Value:specificAction::_LockSpecificAction ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$status; Value:specificAction::_keyStatus ]
Set Variable [ $$issueLogs; Value:specificAction::_keyLogs ]
Set Variable [ $$group; Value:specificAction::_keyGroup ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
#
Refresh Window
End If
#
Go to Layout [ “Issues” (specificAction) ]
Sort Records [ Specified Sort Order: timer::description; ascending
SPAStatus::order; ascending
SPAStatus::text; ascending
SPAGroupTag 2::order; ascending
SPAGroupTag 2::text; ascending
specificAction::order; based on value list: “1-99”
specificAction::text; ascending ]
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
If [ specificAction::_keyStatus = "" ]
Set Field [ specificAction::_keyStatus; $newStatus ]
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
Set Field [ timer::pulldownTimer; specificAction::_keyTimer ]
Set Variable [ $$stopIssuePulldownMenus; Value:1 ]
#
December 11, ଘ౮28 14:46:31 ActionLog.fp7 - openSpecificAction -1-
