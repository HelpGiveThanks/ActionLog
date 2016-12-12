log: changeLogs Copy
#PURPOSE open log window and select log entry for
#current record, but if that record has no time entry
#the show the calendar log view for that record
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $$stopSubtotal; Value:1 ]
#
#I really need to decide on ONE means to store the
#current brainstate key, isntead of making up a new
#one for each module because I'm not sure how the
#others are being used. A definition of each variable
#and how it is used would be great!
Set Variable [ $$logBrainstate; Value:brainstate::_lockBrainstateID ]
#
#Stop the load record scripts. They slow things down.
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Window Title [ Current Window; New Title: "Timer" ]
#
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Day"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
// End If
Go to Layout [ “Issues” (issue) ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$issue; Value:issue::_LockList ]
Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
Refresh Window
#neccessary step when two monitors are used as this
#window can be opened in smaller monitor and then
#move over to larger monitor but not adjust its height
#unless this step is included.
Move/Resize Window [ Name: "Day"; Current file; Height: Get (ScreenHeight) ]
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$stopRecordLoad ]
Exit Script [ ]
#
#
#
#Open a new window to test if any log records exist
#for this brainstate record. A log record will not exist
#if the user has never logged anytime for this brainstate.
New Window [ Name: "Day"; Height: Get (ScreenHeight); Width: 608; Top: 0; Left: 441 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
Set Zoom Level
[ 100% ]
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $$logBrainstate ]
Perform Find [ ]
#
#Decided to show log windows even if there are
#no log records as user may want to create some
#issues.
If [ Get ( LastError ) = 401 ]
January 5, 平成26 19:29:43 ActionLog.fp7 - changeLogs Copy -1-log: changeLogs Copy
If [ Get ( LastError ) = 401 ]
Show Custom Dialog [ Title: "!"; Message: "You can create issues for this brainstate, but until you click the stopwatch for this brainstate
there will be no log records to show in the Activity Log window. "; Buttons: “OK” ]
End If
#
#
#If there are records for this brainstate then show them.
Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
#Show all status and category menu items for
brainstate's log.
Select Window [ Name: "Tag"; Current file ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Tag" ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: //If (Get (ScreenWidth) / 2 + 1100 ≤ Get
(ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 1100 )
Get (ScreenWidth)/2 ]
Set Zoom Level
[ 100% ]
End If
Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
Go to Layout [ “menuGroups” (issueCategory) ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Find the blank (10 space) record for this brainstate's
#set of group tags for grouping issues by group.
Enter Find Mode [ ]
Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
Set Field [ issueCategory::lock; "location" ]
Set Field [ issueCategory::text; "==" & " " ]
Set Field [ issueCategory::order; "" ]
Perform Find [ ]
#
#If the blank (10 space) record is not found then
#create a new one.
If [ Get ( LastError ) = 401 ]
New Record/Request
Set Field [ issueCategory::lock; "location" ]
Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
Set Field [ issueCategory::text; " " ]
Set Variable [ $groupID; Value:issueCategory::_LockList ]
End If
#
#Set the key for the first blank record (actually
#the record with 10 spaces in it, which looks
#blank to the user and will scroll to the top, which
#is what is essential.
January 5, 平成26 19:29:43 ActionLog.fp7 - changeLogs Copy -2-log: changeLogs Copy
Set Variable [ $$blankGroupKey; Value:issueCategory::_LockList ]
Enter Find Mode [ ]
Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
Set Field [ issueCategory::lock; "location" ]
Perform Find [ ]
Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
#
#
#Show all issues for this brainstate's log.
New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: Get (ScreenWidth) / 2; Top: 0; Left: 0 ]
Set Zoom Level
[ 100% ]
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
If [ Get ( LastError ) = 401 ]
New Record/Request
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::_keyCategory; $groupID ]
Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
Set Field [ issue::lock; "issue" ]
Set Field [ issue::text; "issue" ]
#
#makes all new issues stay at the top of the window
#until a non-blank status is assigned to them.
Set Field [ issue::_keyStatus; 6302011014838316 ]
Go to Field [ ]
Go to Field [ issue::text ]
End If
Go to Layout [ “Issues” (issue) ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
Perform Script [ “TsubtotalTimeByGroup” ]
Set Variable [ $$issueSort; Value:"status" ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
#neccessary step when two monitors are used as this
#window can be opened in smaller monitor and then
#move over to larger monitor but not adjust its height
#unless this step is included.
// Move/Resize Window [ Name: "Activity Log"; Current file; Height: Get (ScreenHeight) ]
#
#Start load record scripts as needed for normal function.
Set Variable [ $$stopRecordLoad ]
Perform Script [ “LoadIssuerecordID” ]
Select Window [ Name: "Day"; Current file ]
January 5, 平成26 19:29:43 ActionLog.fp7 - changeLogs Copy -3-log: changeLogs Copy
Perform Script [ “LoadLogrecordID” ]
January 5, 平成26 19:29:43 ActionLog.fp7 - changeLogs Copy -4-
