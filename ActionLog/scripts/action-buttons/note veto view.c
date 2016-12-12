action buttons: note veto view
#HISTORY AND NEEDED CHANGES: This script
#used to help the ActionLog keep track of 1)
#grandtotal records, 2) timer total records,
#and timer records. In testing, this way of
#helping the user group activities by time was
#too imprecise, and so I created the Specific
#Action module, making 1) timers in the main
#timer window function as grand total timers,
#of 2) specific action total group times, and
#finally 3) specific actions times as the
#smallest record of user time.
# The grandtotal and total script steps,
#layouts, and fields nave never been removed.
#They will be when timer permits. Use these
#BEGIN/END statements to flag questionable
#script steps.
#BEGIN Cleanup, answer why?, delete unused steps, etc.
#END Cleanup, answer why?, delete unused steps, etc.
#
#Specifically, this script now just turns on and
#off timers in the main Timer windows.
#
#If the user clicked on the new day timer, tell
#them how to reset it if it is not set, or set it
#up for them. Exit when done, either way.
If [ timer::newDayTimer ≠ "" ]
If [ timer::DateOfLastUse ≠ "" ]
Show Custom Dialog [ Message: "This timer shows your current day of life. To change it 1) click '" & timer::
DaysSinceLastUse & "' to go to your birthday. 2) Click 'cleartime' to clear all time for this day. 3) Click '" & timer::
description & "' to create a new birth day record. To hide it click 'edit' and then click its retire checkbox."; Buttons: “OK” ]
Exit Script [ ]
End If
Perform Script [ “newDayTimerSetup (new)” ]
Exit Script [ ]
End If
#
#Stop user from creating future timer records.
If [ Get ( CurrentDate ) < reference::day1 ]
Show Custom Dialog [ Message: "Timer records cannot be created for future events."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#If this timer is loaded in the Specific Action
#window, then prevent user from activiting it
#in this window, and take user there to start
#and stop it.
If [ $$logBrainstate = timer::_lockTimer // and brainstate::_lockBrainstateID = steward::DefaultSpecificAction ]
If [ Get ( SystemPlatform ) = 3 ]
Select Window [ Name: "Specific Action"; Current file ]
Else
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Day"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
End If
Show Custom Dialog [ Message: "The " & timer::description & " timer is loaded in the Specific Action window (now showing), so
you must operate it here using the 'start' and 'stop' buttons (until you load up a different timer). Edit any time segements
started here in the Timer window."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#
#BEGIN Cleanup, answer why?, delete unused steps, etc.
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:timer::_lockTimer ]
Set Variable [ $$record; Value:Get (RecordNumber) ]
Set Variable [ $$recordnumber; Value:Get ( RecordNumber ) ]
Freeze Window
#END Cleanup, answer why?, delete unused steps, etc.
#
#Don't start a timer that has no name. Maybe
#the user wants to create a space between
#timers, so don't force the user to give timers
#a name.
If [ timer::description = "" ]
Show Custom Dialog [ Message: "Give this timer a name: 1) Click 'edit' and then 2) enter a name in the name field."; Buttons:
“OK” ]
Exit Script [ ]
End If
#
#
#BEGIN Start Timer.
#
#
#If a record for this timer (brainstate) has
#not been created for today, then create one.
If [ day1::swSymbols = "" ]
Set Variable [ $$stopwatchON; Value:"t" ]
Set Variable [ $$newTimer; Value:1 ]
#
#Capture current timer (brainstate) variables.
Set Variable [ $record; Value:Get ( RecordNumber ) ]
Set Variable [ $kpnBrainstateID; Value:timer::_lockTimer ]
Set Variable [ $userID; Value:reference::userID ]
#
#Create new day record and give it keys to
#this timer (brainstate).
Go to Layout [ “DayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyTimer; $kpnBrainstateID ]
Set Field [ day1::_keyUser; $userID ]
Set Field [ day1::_keyDay; reference::day1 ]
#
#Start the timer by inserting the current time
#into the first start-time field.
Set Field [ day1::swStart; Get ( CurrentTimeStamp ) ]
#
#
#BEGIN Cleanup, answer why?, delete unused steps, etc.
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
Perform Script [ “CHUNK_lastDayUsed (update)” ]
#END Cleanup, answer why?, delete unused steps, etc.
#
#
#Show new day record for this timer if it is
#currently loaded in the Specific Action window.
If [ $$logBrainstate = timer::_lockTimer ]
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Go to Layout [ “logs2rows” (logs) ]
#Find it.
Enter Find Mode [ ]
Set Field [ logs::_keyTimer; $$logBrainstate ]
Perform Find [ ]
#Sort it to the top and focus window on it.
Sort Records [ Specified Sort Order: logs::_keyTimer; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
Set Variable [ $$stopRecordLoad ]
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
Set Variable [ $$logissues; Value:logs::_keyLogSPAs ]
#
#Inform other scripts if user is on or not on
#the Today or Yesterday record. This info will
#speed them up, since they will not have to
#check this out for themselves.
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
Set Field [ reference::ActivityLogDayRecordNumber; Get (RecordNumber) ]
#
#Return user to the Timer window.
Select Window [ Name: "Timer"; Current file ]
End If
#
#BEGIN Cleanup, answer why?, delete unused steps, etc.
Set Variable [ $$newTimer ]
#END Cleanup, answer why?, delete unused steps, etc.
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
Perform Script [ “DaySelectSortThenSort (update)” ]
#
#BEGIN Cleanup, answer why?, delete unused steps, etc.
# I think this script is halted by the script
#above so these steps would never be done?
#
#Allows specific action script to continue.
If [ $$specificActionTimer = 1 ]
Exit Script [ Result: "note veto view" ]
Exit Script [ ]
Else
Halt Script
End If
#END Cleanup, answer why?, delete unused steps, etc.
#
End If
#
#
#END Start Timer.
#
#
#
#
#BEGIN Restart Timer.
#
#
If [ day1::swSymbols = "note" ]
#Restart the timer by putting a new start
#time in the next a available start field.
Set Variable [ $$stopwatchON; Value:"t" ]
Set Field [ day1::swStart[day1::swOccurances + 1]; Get ( CurrentTimeStamp ) ]
If [ day1::swOccurances = 29 ]
Set Field [ day1::swStart[29]; Get ( CurrentTimeStamp ) ]
End If
#
#Recalculate the pause between stop and
#start times to show user the amount of time
#that has passed since the last time this
#timer (brainstate) was active.
Perform Script [ “updatePauseTotals” ]
#
#BEGIN Cleanup, answer why?, delete unused steps, etc.
#This sets a flag for the updateTime script
#telling it to ignore this stopwatches time for
#updates to total records because until it is
#stopped its time has not changed and does
#not need to be included in an update.
Set Field [ day1::updateTimeSymbol; day1::swSymbols ]
Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
#
#Go back to original record number so sort script
#gets ID number. (It would be better to fix sort
#script so it exits rather than halts all scripts.)
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Perform Script [ “DaySelectSortThenSort (update)” ]
#END Cleanup, answer why?, delete unused steps, etc.
#
End If
#
#
#END Restart Timer.
#
#
#
#
#BEGIN Stop Timer.
#
#
#If the timer is running, then stop it.
If [ day1::swSymbols = "veto" ]
Set Variable [ $$stopwatchON; Value:"f" ]
Set Field [ day1::swPause[day1::swOccurances]; Get ( CurrentTimeStamp ) ]
Set Variable [ $$TimeAssignedToSpecificAction; Value:specificAction::_LockSpecificAction ]
#
#Recalculate the time for this timer any
#specific actions linked to it.
Perform Script [ “updateTime (update)” ]
End If
#
#
#END Stop Timer.
#
December 10, ଘ౮28 20:37:07 ActionLog.fp7 - note veto view -1-
