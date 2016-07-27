specific action log: startTimerAssignTimeSegmentToSpecificAction
#
#
#Don't allow user to start the timer if is active.
If [ issue::timer = "active" ]
Show Custom Dialog [ Message: "This timer is active in the past. To stop it so you can use it today, 1) click the 'day' button
above. 2) Scroll to the day whose dates are bold font, highlighted green. 3) Click the bolded date, and 4) in the Timer
window insert a stop time."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Exit the script if there are no records present
#or if the timer is already running.
If [ Get (FoundCount) = 0 or day1::swBugField = "veto" ]
If [ day1::swBugField = "veto" ]
Show Custom Dialog [ Message: "This button can only turn on one timer at a time, and there is already one running. ";
Buttons: “OK” ]
End If
Exit Script [ ]
End If
#
#Don't allow user to start the timer if is active.
If [ issue::timer = "active" ]
Exit Script [ ]
End If
#
// #Allow user to start timer on Day record
// #number one.
// Select Window [ Name: "Day"; Current file ]
// Set Variable [ $dayRecordNumber; Value:Get (RecordNumber) ]
// Select Window [ Name: "Specific Action"; Current file ]
// If [ $dayRecordNumber ≠ 1 ]
// Show Custom Dialog [ Message: "The day selected in the day window is not today, which can extend past midnight. 1) Click
the 'timer' button above. 2) Go to today's date. 3) Click the 'specificact' button. 4) Click 'start'. "; Buttons: “OK” ]
// Exit Script [ ]
// End If
#
#Only allow timer to be started if it is for today
#or tomorrow (meaning today after midnight).
If [ reference::day1 = Get ( CurrentDate ) or reference::day1 = Get ( CurrentDate ) - 1 ]
#
#
#Decided this info comment was just irritating.
#FYI: If you turn it on it has to be moved below
#the next segment of code.
#
// #If midnight has past, ask user if they want to
// #continue logging time for yesterday's record.
// If [ reference::day1 = Get ( CurrentDate ) - 1 ]
// Show Custom Dialog [ Message: "It is past midnight. Continue to log time for day " & reference::day1 & "?"; Buttons:
“yes”, “cancel” ]
// If [ Get ( LastMessageChoice ) = 2 ]
// Exit Script [ ]
// End If
// End If
#
#
#Insure that user is on the most current day
#record in the Timer window. So, if there is a
#record for Today but the user is on Yesterday's
#record in the Timer window, then stop this
#script and inform user to move Timer window
#day record to Today.
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
New Window [ ]
Go to Record/Request/Page
[ First ]
#
If [ reference::day1 ≠ reference::ActivityLogDay and reference::ActivityLogDay = Get ( CurrentDate ) ]
Set Variable [ $$stopRecordLoad ]
Select Window [ Name: "Specific Action"; Current file ]
Show Custom Dialog [ Message: "You can use this button after you advance the Timer window to today (" &Get
( CurrentDate ) & "). 1) Click the 'timer' button above. 2) Go to today's date. 3) Click the 'specificact' button. 4) Click
'start'."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#
#If the Day window is NOT on the most current
#day record, but the Timer window is (as just
#determined by the last script segment), then
#go to this record in the Day window too, before
#proceeding with turning on Timer in the
#Specific Action module.
Close Window [ Current Window ]
#
If [ Get (RecordNumber) ≠ 1 ]
Go to Record/Request/Page
[ First ]
#
#Go to layout displaying all time segements
#for the selected day record.
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
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
Set Variable [ $$day1BugField; Value:logs::swBugField ]
#
#Inform other scripts if user is on or not on
#the Today or Yesterday record. This info will
#speed them up, since they will not have to
#check this out for themselves.
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
#
Refresh Window
Set Variable [ $$stopRecordLoad ]
Go to Field [ ]
End If
#
#
#Script can now proceed to turn on the Timer.
#
#Change this specific action timer to active.
Select Window [ Name: "Specific Action"; Current file ]
Set Field [ issue::timer; "active" ]
#
If [ day1::swBugField = "note" ]
#
Set Variable [ $$specificActionTimer; Value:1 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
New Window [ Height: 1; Width: 1; Top: -10000; Left: -10000 ]
// New Window [ ]
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
#
#Show record has been modified.
Set Field [ issue::dateModified; Get ( CurrentTimeStamp ) ]
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
#TEST TO SEE IF STOP LOAD CAN BE TURNED OFF LATER IN THE SCRIPT!!!!!!!!!
#TEST TO SEE IF STOP LOAD CAN BE TURNED OFF LATER IN THE SCRIPT!!!!!!!!!
#TEST TO SEE IF STOP LOAD CAN BE TURNED OFF LATER IN THE SCRIPT!!!!!!!!!
#TEST TO SEE IF STOP LOAD CAN BE TURNED OFF LATER IN THE SCRIPT!!!!!!!!!
#TEST TO SEE IF STOP LOAD CAN BE TURNED OFF LATER IN THE SCRIPT!!!!!!!!!
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
#Go to layout displaying all time segements
#for the selected day record.
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
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
Set Variable [ $$day1BugField; Value:logs::swBugField ]
#
#Inform other scripts if user is on or not on
#the Today or Yesterday record. This info will
#speed them up, since they will not have to
#check this out for themselves.
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
Set Field [ reference::ActivityLogDayRecordNumber; Get (RecordNumber) ]
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
#Show record has been modified.
Set Field [ issue::dateModified; Get ( CurrentTimeStamp ) ]
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
Show Custom Dialog [ Message: "You can use this button after you change the date in the Timer window to today (" &Get
( CurrentDate ) & "). 1) Click the 'timer' button above. 2) Go to today's date. 3) Click the 'specificact' button. 4) Click
'start'."; Buttons: “OK” ]
#
#
#
End If
July 26, ଘ౮28 15:39:33 ActionLog.fp7 - startTimerAssignTimeSegmentToSpecificAction -1-
