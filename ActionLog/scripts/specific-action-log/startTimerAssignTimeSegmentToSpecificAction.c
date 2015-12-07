specific action log: startTimerAssignTimeSegmentToSpecificAction
#
#
If [ Get (FoundCount) = 0 ]
Exit Script [ ]
End If
#
#Only allow timer to be started if it is for today
#or tomorrow (meaning today after midnight).
If [ reference::day1 = Get ( CurrentDate ) or reference::day1 = Get ( CurrentDate ) + 1 ]
#
If [ reference::day1 ≠ reference::ActivityLogDay ]
Select Window [ Name: "Day"; Current file ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Select Window [ Name: "Specific Action"; Current file ]
End If
#
If [ day1::swBugField = "note" ]
#
Set Variable [ $$specificActionTimer; Value:1 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
New Window [ Height: 1; Width: 1; Top: -10000; Left: -10000 ]
Go to Layout [ “01EditTime” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
#
#
#BEGIN: Script steps copied from script "note veto view."
#
#
#NOTE: Rather than run this script I thought it
#would be better to copy just the steps needed
#in the Specific Action window to start the timer.
#Since it cannot be edited from this screen, the
#sort is not needed in the Timer window unless
#the timer is being turned on for the first time
#in the currently selected day.
#
#6 if the note button is showing restart the
#timer by putting a new start time in next
#available start field for this day record.
Set Variable [ $$stopwatchON; Value:"t" ]
Set Field [ day1::swStart[day1::swOccurances + 1]; Get ( CurrentTimeStamp ) ]
If [ day1::swOccurances = 29 ]
Set Field [ day1::swStart[29]; Get ( CurrentTimeStamp ) ]
End If
#
#7 recalculate the pause between stop and
#start times to show user the amount of time
#that has passed since the last time this
#brainstate was active.
Perform Script [ “updatePauseTotals” ]
#
#
#END: Script steps copied from script "note veto view."
#
#
Close Window [ Current Window ]
Set Variable [ $$stopRecordLoad ]
#
#Show user that Timer window timer has been started.
Move/Resize Window [ Name: "Timer"; Current file; Height: Get (ScreenHeight) - 276; Width: Get (ScreenWidth) - 344; Top:
251; Left: 344 ]
Move/Resize Window [ Name: "Specific Action"; Current file; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: 0 ]
Move/Resize Window [ Name: "Tag"; Current file; Height: 266; Width: 344; Top: 0; Left: 688 ]
Move/Resize Window [ Name: "Day"; Current file; Height: 266; Width: 344; Top: 0; Left: 344 ]
#
#Conditionally format and set up timer to stop.
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$day1BugField; Value:logs::swBugField ]
Set Variable [ $$specificActionTimer ]
#
#Determine correct layout to show all time segments.
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
#
#Trigger scripts that add this new time
#segment to current action.
Go to Field [ daylog::swActivityLength[daylog::swOccurances] ]
[ Select/perform ]
#
Select Window [ Name: "Specific Action"; Current file ]
#
#
// #BEGIN: Script steps copied from script "linkActionToDay."
// #
// #Needed to be done for first timer segment of the day.
// #
// #If tag has not yet been selected, then add it.
// If [ issue::_LockList & "¶" ≠ FilterValues ( $$logIssues ; issue::_LockList & "¶" ) ]
// #
// Set Variable [ $newIssue; Value:issue::_LockList ]
// Select Window [ Name: "Day"; Current file ]
// If [ Get (LastError) = 112 ]
// New Window [ Name: "Day"; Height: Get (ScreenHeight); Width: 608; Top: 0; Left: 441 ]
// Go to Layout [ “logs1row” (logs) ]
// End If
// #
// #prepare to add log ID to issueLogs so that the issue
// #will have a record of all days logged to deal with it.
// Set Variable [ $newlog; Value:logs::_lockDay ]
// Set Variable [ $$logIssue; Value:logs::_keyLogIssues ]
// #
// Set Field [ logs::_keyLogIssues; $newIssue & "¶" & $$logIssues ]
// Set Variable [ $$logIssues; Value:logs::_keyLogIssues ]
// Go to Field [ ]
// Refresh Window
// Select Window [ Name: "Specific Action"; Current file ]
// #
// #Add log ID to issueLogs.
// Set Field [ issue::_keyLogs; $newlog & "¶" & $$IssueLogs ]
// Set Variable [ $$IssueLogs; Value:issue::_keyLogs ]
// #
// #For some reason if system does not re-go to this
// #same record, other scripts trying to set fields for this
// #record in a different window (so same layout
// #different window will get an error 301 (record in use
// #by another user). So it is neccessary.
// #addTimeSegmentToIssue is the other scirpt that
// #gets that error message when this step is left out.
// Go to Record/Request/Page [ Get (RecordNumber) ]
[ No dialog ]
// End If
// #
// #END: Script steps copied from script "linkActionToDay."
#
Refresh Window
#
#
#
#
Else If [ day1::swBugField = "" ]
#
Set Variable [ $$specificActionTimer; Value:1 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
New Window [ Height: 1; Width: 1; Top: -10000; Left: -10000 ]
Go to Layout [ “01EditTime” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
#
Set Variable [ $$stopwatchON; Value:"t" ]
Set Variable [ $$newTimer; Value:1 ]
#
#1 capture record number user is currently on
Set Variable [ $record; Value:Get ( RecordNumber ) ]
#
#2 if not create a new one for this brainstate record and do it a new window so the user's focus is maintained (just going to
the day layout and back resest the scroll bar unfortunately and I can't find away around this, but I want too!)
Set Variable [ $kpnBrainstateID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $userID; Value:reference::farmerID ]
Go to Layout [ “calcDayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyBrainstate; $kpnBrainstateID ]
Set Field [ day1::_keyUser; $userID ]
Set Field [ day1::_keyDay; reference::day1 ]
#
#3 start the timer by inserting the current time in the start field
Set Field [ day1::swStart; Get ( CurrentTimeStamp ) ]
#
#This step sets a flag for the updateTime
#script telling it to ignore this stopwatches
#time for updates to total records because
#until it is stopped its time has not changed
#and does not need to be included in an update.
Set Field [ day1::updateTimeSymbol; day1::swSymbols ]
Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
Go to Layout [ original layout ]
Go to Record/Request/Page [ $record ]
[ No dialog ]
Perform Script [ “CHUNK_lastDayUsed” ]
#
Close Window [ Current Window ]
#
#Now find the new log record for this timer.
Select Window [ Name: "Day"; Current file ]
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
#For attaching issue record IDs to log records, and
#for conditionally formatting log records related to an issue,
#system needs to know what IDs are associated with a log record.
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
Set Variable [ $$log; Value:logs::_lockDay ]
#
#Attach new time segment to issue record.
#(The daylog::swOccurances field tells the
#system which segment is new.)
Go to Field [ daylog::swActivityLength[daylog::swOccurances] ]
[ Select/perform ]
#
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$newTimer ]
#
Select Window [ Name: "Timer"; Current file ]
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:brainstate::_lockBrainstateID ]
#
#4 sort the records if the current sort is based
#on time which will make this record with zero
#current time shoot to the top or bottom of the
#list depending on how the user is currently
#shorting time. The point is to keep the focus
#where the user expects it to be so the sort,
#which removes the focus from the current
#record is only done if the user wants the
#records sorted by time, in which case after
#the sort the focus is returned to the first record.
Perform Script [ “DaySelectSortThenSort” ]
#
Select Window [ Name: "Day"; Current file ]
#
#For attaching issue record IDs to log records, and
#for conditionally formatting log records related to an issue,
#system needs to know what IDs are associated with a log record.
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
Set Variable [ $$log; Value:logs::_lockDay ]
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
Set Variable [ $$day1BugField; Value:logs::swBugField ]
#
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
#
Move/Resize Window [ Name: "Day"; Current file; Height: 266; Width: 344; Top: 0; Left: 344 ]
// Refresh Window
#
Select Window [ Name: "Tag"; Current file ]
Move/Resize Window [ Name: "Tag"; Current file; Height: 266; Width: 344; Top: 0; Left: 688 ]
#
Move/Resize Window [ Name: "Timer"; Current file; Height: Get (ScreenHeight) - 276; Width: Get (ScreenWidth) - 344; Top:
251; Left: 344 ]
#
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$toggleSpecificActionView; Value:1 ]
Move/Resize Window [ Name: "Specific Action"; Current file; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: 0 ]
#
#For attaching issue record IDs to log records, and
#for conditionally formatting log records related to an issue,
#system needs to know what IDs are associated with a log record.
Set Variable [ $$issue; Value:issue::_LockList ]
Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
Set Variable [ $$stopGroup; Value:1 ]
#
#
#
Refresh Window
#
#
Set Variable [ $$specificActionTimer ]
#
End If
#
Else
#
Show Custom Dialog [ Message: "Go to the Timer window to start a timer for a specific action in the past. This button can only
be used for starting a timer in the present. Timer window date is " & reference::ActivityLogDay & ". Change this date in the
timer window."; Buttons: “OK” ]
#
#
#
End If
December 6, ଘ౮27 22:07:18 ActionLog.fp7 - startTimerAssignTimeSegmentToSpecificAction -1-
