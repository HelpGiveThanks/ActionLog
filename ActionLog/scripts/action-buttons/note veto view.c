action buttons: note veto view
#PURPOSE merge selected record's time data into one total record and then link these records so that time added in the future to any
of the merge records will be automatically added to the one total record.
#
#
If [ $$logBrainstate = brainstate::_lockBrainstateID and brainstate::_lockBrainstateID = steward::DefaultSpecificAction ]
Show Custom Dialog [ Message: "Select a specific action; then click start or stop. You can always edit its time in the edit-time
window. NOTE: This general-action timer is your specific action default. Edit it to change the default."; Buttons: “OK” ]
If [ Get (LastMessageChoice) = 1 ]
If [ Get ( SystemPlatform ) = 3 ]
Select Window [ Name: "Specific Action"; Current file ]
Else
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Day"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
End If
Exit Script [ ]
End If
End If
#
#
#
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:brainstate::_lockBrainstateID ]
Set Variable [ $$record; Value:Get (RecordNumber) ]
Set Variable [ $$recordnumber; Value:Get ( RecordNumber ) ]
Freeze Window
#needed by folderstopwatchcheck script in case the stopwatch being started or stopped belongs to a total record
Set Variable [ $$folderon; Value:brainstate::groupID ]
#
#
#
If [ brainstate::sortRetired ≠ "" ]
Show Custom Dialog [ Title: "!"; Message: "This record is currently retired. To make it active again, click on the r to the
immediate left of the record title (if the edit controls are hidden, then first click the edit button (top left corner of this window).";
Buttons: “OK” ]
Halt Script
End If
If [ brainstate::description = "" ]
Exit Script [ ]
End If
#
#1 if the view button is showing: determine if the record is total record, and it is show the these linked records, unless the user is on the
total record layout in which case halt the script. (From the user's point of view the stopwatch button will say 'view' instead of 'note'
if it is a total record, and this part of the script will be activitated.)
If [ brainstate::_lockBrainstateID = brainstate::groupID or brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
If [ Left ( Get ( LayoutName ) ; 5 ) = "total" or Left ( Get ( LayoutName ) ; 5 ) = "grand" ]
Halt Script
End If
Set Variable [ $$record; Value:1 ]
Perform Script [ “showLinkedRecords” ]
Halt Script
End If
#
#1 If there is no day record create a new one.
If [ day1::swSymbols = "" ]
Set Variable [ $$stopwatchON; Value:"t" ]
Set Variable [ $$newTimer; Value:1 ]
#
#1 capture record number user is currently on
Set Variable [ $record; Value:Get ( RecordNumber ) ]
#2 if not create a new one for this brainstate record and do it a new window so the user's focus is maintained (just going to the day
layout and back resest the scroll bar unfortunately and I can't find away around this, but I want too!)
#
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
#
#Now find the new log record for this timer if
#it is currently loaded (the current Specific
#Action timer showing).
If [ $$logBrainstate = brainstate::_lockBrainstateID ]
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $$logBrainstate ]
Perform Find [ ]
#
#Sort, turn on load record script to set Day
#record's variables, and go to first record.
Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
Set Variable [ $$stopRecordLoad ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
Select Window [ Name: "Timer"; Current file ]
End If
#
Set Variable [ $$newTimer ]
#
#NOTE: The folder or parent and child timer
#scripts and layouts are currently not is use in
#favor of tracking such parent-child information
#in the Specific Action module.
// #4 check if the record belongs to a total
// #record and modify its foldercheck field if so
// #to inform user on main screen that a
// #stopwatch may be activite that is not currently shown.
// Perform Script [ “folderStopwatchCheck” ]
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
Perform Script [ “DaySelectSortThenSort (Update)” ]
#
#Allows specific action script to continue.
If [ $$specificActionTimer = 1 ]
Exit Script [ Result: "note veto view" ]
Exit Script [ ]
Else
Halt Script
End If
#
End If
#
#5 if the veto button is showing stop the
#stopwatch and put in the in the time stopped.
If [ day1::swSymbols = "veto" ]
Set Variable [ $$stopwatchON; Value:"f" ]
Set Field [ day1::swPause[day1::swOccurances]; Get ( CurrentTimeStamp ) ]
Set Variable [ $$TimeAssignedToSpecificAction; Value:issue::_LockList ]
#
#5 recalculate the time for this record and
#check and see if is linked to any total records
#and if so update their time too.
Perform Script [ “updateTime (update)” ]
End If
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
#This sets a flag for the updateTime script
#telling it to ignore this stopwatches time for
#updates to total records because until it is
#stopped its time has not changed and does
#not need to be included in an update.
Set Field [ day1::updateTimeSymbol; day1::swSymbols ]
Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
#
#NOTE: The folder or parent and child timer
#scripts and layouts are currently not is use in
#favor of tracking such parent-child information
#in the Specific Action module.
// #4 check if the record belongs to a total
// #record and modify its foldercheck field if so
// #to inform user on main screen that a
// #stopwatch may be activite that is not currently shown.
// Perform Script [ “folderStopwatchCheck” ]
#
#Go back to original record number so sort script
#gets ID number. (It would be better to fix sort
#script so it exits rather than halts all scripts.)
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Perform Script [ “DaySelectSortThenSort (Update)” ]
July 13, ଘ౮28 19:42:39 ActionLog.fp7 - note veto view -1-
