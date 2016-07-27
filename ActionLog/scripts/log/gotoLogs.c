log: gotoLogs
#PURPOSE open log window and select log entry for
#current record.
#
#
If [ $$logBrainstate ≠ brainstate::_lockBrainstateID and brainstate::HighlightSpecificActionButton ≠ "" ]
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $name; Value:brainstate::description ]
Select Window [ Name: "Timer"; Current file ]
Show Custom Dialog [ Message: //"View '" & GetValue ( $name; 1) & "' timer's specific actions or load '" & GetValue
( brainstate::description ; 1 ) & "' timer's specific actions?"
//"Your Specific Action windows = '" & GetValue ( $name; 1) & "'. View '" & GetValue ( $name; 1) & "' or load '" & GetValue
( brainstate::description ; 1 ) & "' specific actions?"
"View — specific actions for — " & GetValue ( $name; 1) & ¶ & "or" & ¶ & "Load — specific actions for — " & GetValue
( brainstate::description ; 1 ); Buttons: “load”, “view” ]
#
#
If [ Get ( LastMessageChoice ) = 2 ]
If [ Get ( SystemPlatform ) = 3 ]
Select Window [ Name: "Specific Action"; Current file ]
Else
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Day"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
End If
Exit Script [ ]
End If
#
Else If [ Right ( Filter ( brainstate::description ; "!" ) ; 1 ) ≠ "!" ]
#
If [ Get ( SystemPlatform ) = 3 ]
Select Window [ Name: "Specific Action"; Current file ]
Else
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Day"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
End If
Exit Script [ ]
End If
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
#current brainstate key, instead of making up a new
#one for each module. I'm not sure how the
#others are being used. Perhaps since the
#current brainstate in the Specific Action log
#can be different from that in the Timer
#window, the system reall does require two
#such keys? A definition of each variable
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
Else If [ logs::_keyBrainstate = $$logBrainstate and logs::_keyDay ≠ $day1 ]
#If only a new day has been added, then just update
#the Day window and show user the rest of the
#Specific Action windows without changing them.
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
Set Variable [ $$day1BugField; Value:logs::swBugField ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
#
#Start load record scripts as needed for normal function.
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$stopSubtotal ]
#
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
Refresh Window
#
Exit Script [ ]
#
End If
#
#
#Find first issue record if there is one and set variables
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
Perform Script [ “TsubtotalTimeByGroup” ]
End If
#
#Set the variables.
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
Set Variable [ $$day1BugField; Value:logs::swBugField ]
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
Sort Records [ Specified Sort Order: group::order; based on value list: “1-99”
group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
#
#Update timer's total time. This is only done
#when switching specific action timers rather than
#each time a timer's total is changed due to the
#amount of time it takes to calculate this total.
Perform Script [ “updateTimerTotalTimeInTagWindow” ]
#
#Turn this variable back on as it is shut off
#when the script above was performed.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Find all groups for this action.
Go to Layout [ “IssuesAndObservationsTag” (category) ]
Enter Find Mode [ ]
Set Field [ category::_keyBrainstate; $$logBrainstate ]
Set Field [ category::lock; "location" ]
Perform Find [ ]
#
#If none are found then create one.
If [ Get ( LastError ) = 401 ]
Set Variable [ $$TagNameRequired; Value:1 ]
#
#Create new group record.
New Record/Request
Set Field [ category::lock; "group" ]
Set Field [ category::_keyBrainstate; $$logBrainstate ]
Set Field [ category::text; "Admin" ]
Set Variable [ $group; Value:category::_LockList ]
#
#Remove it so it only shows up as a header and
#and not as both a header and a tag.
Omit Record
#
#Create a new tag record and assign it to this new
#group so the group will show up as its header.
New Record/Request
Set Field [ category::lock; "location" ]
Set Field [ category::_keyBrainstate; $$logBrainstate ]
Set Field [ category::_keyCategory; $group ]
Set Field [ category::text; "Administration" ]
Set Variable [ $groupKey; Value:category::_LockList ]
#
#Turn off variable set at start of script.
Set Variable [ $$TagNameRequired ]
End If
#
#Sort records so group headers will show up.
Sort Records [ Specified Sort Order: group::order; based on value list: “1-99”
group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
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
#
#Set final variables for navigation to other records.
Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
Go to Field [ ]
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
#
#disabled go to field takes a user view out of a
#a the text field if they entered it to go to this
#record, which I don't like as a user, so it is off.
// Go to Field [ ]
Set Variable [ $$stopIssuePulldownMenus; Value:1 ]
Refresh Window
July 13, ଘ౮28 13:38:52 ActionLog.fp7 - gotoLogs -1-
