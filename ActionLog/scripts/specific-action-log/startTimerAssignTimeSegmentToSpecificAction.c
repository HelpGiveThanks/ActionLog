specific action log: startTimerAssignTimeSegmentToSpecificAction
#
#SPA = Specific Action
#
#See if the user has entered a time segment
#in the Timer window, and dragged its time to
#another time segement, and hasn't exited the
#the initially entered time segment (allowing
#the updateTime script to do its job).
Select Window [ Name: "Timer"; Current file ]
#
#Once this script exits the time segement field
#in the Timer window, the updateTime script
#will start. This next variable will allow
#this 'start' button script to continue after
#the update.
Set Variable [ $$timerWindowCheck; Value:1 ]
Go to Field [ ]
Set Variable [ $$timerWindowCheck ]
#
#
#BEGIN See if user can start timer.
#
#
#Stop user from creating future timer records.
If [ Get ( CurrentDate ) < reference::day1 ]
#
#Return to the Specific Action window.
If [ Get ( SystemPlatform ) = 3 ]
Select Window [ Name: "Specific Action"; Current file ]
Else
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Day"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
End If
#
#Inform user why the can't use the button.
Show Custom Dialog [ Message: "Timer records cannot be created for future events." & ¶ & "1) Go to the timer window (click the
'timer' button above)." & ¶ & "2) Move the timer window date back to today."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#
#If the Timer window is focused on yesterday,
#make sure there are no Timers running today.
If [ //day1 is yesterday = true or 1.
 ( reference::day1 = Get ( CurrentDate ) - 1 ) = 1 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Variable [ $$specificActionTimer; Value:1 ]
New Window [ ]
Go to Layout [ “DayTable” (day1) ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
Enter Find Mode [ ]
Set Field [ day1::_keyDay; Get ( CurrentDate ) ]
Perform Find [ ]
#
#Set a variable if there are Timers
#running today.
If [ Get ( LastError ) ≠ 401 ]
Set Variable [ $todayExists; Value:1 ]
End If
Close Window [ Current Window ]
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$specificActionTimer ]
End If
#
#Return to the Specific Action window.
If [ Get ( SystemPlatform ) = 3 ]
Select Window [ Name: "Specific Action"; Current file ]
Else
Select Window [ Name: "Tag"; Current file ]
Select Window [ Name: "Day"; Current file ]
Select Window [ Name: "Specific Action"; Current file ]
End If
#
#Don't allow user to start the timer if the
#Timer window is not in the present (meaning
#today or after midnight, which allows the
#user to have a day the extends past midnight),
#OR if the user has started creating timer
#records for today, and the Timer window is
#focused on yesterday.
If [ //1) day1 is today = false or 0, and
 ( reference::day1 = Get ( CurrentDate ) ) = 0 and
//2) day1 is yesterday and there are no day1 records for today = false.
 ( reference::day1 = Get ( CurrentDate ) - 1 and $todayExists ≠ 1 ) = 0 ]
If [ Get ( SystemPlatform ) = 3 ]
Show Custom Dialog [ Message: "You can use the 'start' button after you advance the Timer window to today's date (" &Get
( CurrentDate ) & "). 1) Click the 'timer' button above. 2) Set the Timer window's date to today's date. 3) Click the
'specificact' button. 4) Click 'start'."; Buttons: “OK” ]
Else
Show Custom Dialog [ Message: "You can use the 'start' button after you advance the Timer window to today's date (" &Get
( CurrentDate ) & "). 1) Click the 'timer' button above. 2) Set the Timer window's date to today's date. 3) Click the
'specificaction' button. 4) Click 'start'."; Buttons: “OK” ]
End If
Exit Script [ ]
End If
#
#Don't allow user to start the timer if it is
#already active for today (most likely because
#the user accidently clicked the 'start' button ).
If [ specificAction::timer = "active" and reference::day1 = Get ( CurrentDate ) and day1::swBugField = "veto" and (reference::
ActivityLogDay < reference::day1) ≠ 1 or
specificAction::timer = "active" and reference::day1 = Get ( CurrentDate ) - 1 and day1::swBugField = "veto" and (reference::
ActivityLogDay < reference::day1) ≠ 1 ]
Exit Script [ ]
End If
#
#Don't allow user to start the timer if it is
#active in the past by ...
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Variable [ $$specificActionTimer; Value:1 ]
New Window [ ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#...finding all Specific Action records assigned
#to this timer that are active, and ...
Enter Find Mode [ ]
Set Field [ specificAction::timer; "active" ]
#(Need to eventual change variable name to $$SPAtimer)
Set Field [ specificAction::_keyTimer; $$logBrainstate ]
Perform Find [ ]
Set Variable [ $activeRecordsFound; Value:Get (FoundCount) ]
#
#... telling user why they cannot start timer if
#it is active in the past.
Close Window [ Current Window ]
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$specificActionTimer ]
If [ $activeRecordsFound ≠ 0 ]
Show Custom Dialog [ Message: "Active in the past. 'Start' button will work after you 1) click the 'day' button/go to the Day
window. 2) Scroll to each day whose date is highlighted and bolded. 3) Click each bolded date, and 4) in the Timer window,
insert a stop time for each one."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Don't allow user to start the timer if another
#another Specific Action timer is running and
#is assigned to today, OR if there are no
#Specific Actions present to assign the time to.
If [ Get (FoundCount) = 0 or day1::swBugField = "veto" ]
If [ day1::swBugField = "veto" ]
Show Custom Dialog [ Message: "There is already a Specific Action time segment assigned to today's active timer. 1) Click
'stop' to free up the main Timer, and then 2) click 'start' to both start it and assign it to this Specific Action. "; Buttons:
“OK” ]
Else
Show Custom Dialog [ Message: "Click the 'new' button first to create a specific action, then you can click 'start' to assign
time to it."; Buttons: “OK” ]
End If
Exit Script [ ]
End If
#
#
#Decided this info comment was just irritating.
#FYI: If you turn it on it has to be moved below
#the next segment of code.
// #If midnight has past, ask user if they want to
// #continue logging time for yesterday's record.
// If [ reference::day1 = Get ( CurrentDate ) - 1 ]
// Show Custom Dialog [ Message: "It is past midnight. Continue to log time for day " & reference::day1 & "?"; Buttons: “yes”,
“cancel” ]
// If [ Get ( LastMessageChoice ) = 2 ]
// Exit Script [ ]
// End If
// End If
#
#
#END See if user can start timer.
#
#
#If the Day window is NOT on the most current
#day record, but the Timer window is, then
#go to the current record in the Day window
#too, before proceeding with turning on Timer
#in the Specific Action window.
If [ reference::ActivityLogDayRecordNumber ≠ 1 ]
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Go to Record/Request/Page
[ First ]
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
Set Variable [ $$stopRecordLoad ]
Go to Field [ ]
End If
#
#Script can now proceed to turn on the Timer
#and assign it to this SPA.
#
#Change this specific action timer to active.
Select Window [ Name: "Specific Action"; Current file ]
Set Field [ specificAction::timer; "active" ]
Go to Field [ ]
#
#Go to a new window, so current window
#doesn't change focus.
Set Variable [ $$specificActionTimer; Value:1 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
New Window [ Height: 1; Width: 1; Top: -10000; Left: -10000 ]
// New Window [ ]
#
#Find the timer to restart OR start.
Go to Layout [ “01EditTime” (timer) ]
Enter Find Mode [ ]
Set Field [ timer::_lockTimer; $$logBrainstate ]
Perform Find [ ]
#
#
#BEGIN Restart Timer.
#
#
#If a record for this timer (brainstate) has
#already been created for today, then add a
#new time segment to it.
If [ day1::swBugField = "note" ]
#
#BEGIN Run copied "note veto view" script steps.
#
#NOTE: Rather than run this script I thought it
#would be better to copy just the steps needed
#in the Specific Action window to start the timer.
# SO if you edit anything in this section,
#also make the same changes in the
#"note veto view" script.
#
#
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
#END Run copied "note veto view" script steps.
#
#
#Close window for finding and starting timer.
Close Window [ Current Window ]
#
#END Restart Timer.
#
#
#
#
#BEGIN Start Timer.
#
#
#BEGIN Run copied "note veto view" script steps.
#
#NOTE: Rather than run this script I thought it
#would be better to copy just the steps needed
#in the Specific Action window to start the timer.
# SO if you edit anything in this section,
#also make the same changes in the
#"note veto view" script.
#
#If a record for this timer (brainstate) has
#not been created for today, then create one.
Else If [ day1::swBugField = "" ]
Set Variable [ $$stopwatchON; Value:"t" ]
Set Variable [ $$newTimer; Value:1 ]
#
#Capture current timer (brainstate) variables.
Set Variable [ $record; Value:Get ( RecordNumber ) ]
#
#Create new day record and give it keys to
#this timer (brainstate).
Set Variable [ $kpnBrainstateID; Value:timer::_lockTimer ]
Set Variable [ $userID; Value:reference::userID ]
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
Perform Script [ “CHUNK_lastDayUsed” ]
#END Cleanup, answer why?, delete unused steps, etc.
#
#Close window for finding and starting timer.
Close Window [ Current Window ]
#
#Show new day record for this timer.
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
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
#END Run copied "note veto view" script steps.
#
#Sort Timer window if on an edit time layout.
Select Window [ Name: "Timer"; Current file ]
If [ Get ( LayoutName ) = "EditTimeiPhone" or Get ( LayoutName ) = "01EditTime" ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::groupType; ascending
day1::swStart; ascending
timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
End If
#
#
End If
#
#
#END Start Timer.
#
#
#
#
#BEGIN Show all windows and update Day variables.
#
#
#Show user that Timer window timer was updated
#by re-arraning all windows if on a mac or PC.
#(The other windows will be resized and
#moved as they are focused upon below.)
If [ Get ( SystemPlatform ) ≠ 3 ]
Move/Resize Window [ Name: "Timer"; Current file; Height: Get (ScreenHeight) - 276; Width: Get (ScreenWidth) - 344; Top: 251;
Left: 344 ]
Move/Resize Window [ Name: "Specific Action"; Current file; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: 0 ]
Move/Resize Window [ Name: "Tag"; Current file; Height: 266; Width: 344; Top: 0; Left: 688 ]
Move/Resize Window [ Name: "Day"; Current file; Height: 266; Width: 344; Top: 0; Left: 344 ]
End If
#
#Set variables used for attaching Specific Action
#record IDs to Day records, and for conditionally
#formatting Day records related to Specific
#Action records.
Select Window [ Name: "Day"; Current file ]
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
#
#END Show all windows and update Day variables.
#
#
#
#
#BEGIN Add newly created time segement to SPA.
#
#Set up timer to stop.
Set Variable [ $$specificActionTimer ]
#
#Capture repetition number and _lockDay of
#segment just created = segment ID.
Set Variable [ $day; Value:daylog::_lockDay ]
Set Variable [ $repetition; Value:logs::swOccurances ]
#
#Conditionally format new segment to show
#that it is assigned to the selected issue.
Set Field [ daylog::swLogTimeAccounting[$repetition]; $$issue ]
#
#Create a new issueTime record giving it
#issue, day, and repetition keys so this
#segement's time will be added to total time
#spent on the selected specific action.
Go to Layout [ “SPATimeTable” (SPATime) ]
New Record/Request
Set Field [ SPATime::_keyDay; $day ]
Set Field [ SPATime::_keyRepetition; $repetition ]
Set Field [ SPATime::_keySPA; $$issue ]
#
#Add day and repetition keys to the list of all
#day and repetition keys for this issue.
Go to Layout [ “SpecificActionTable” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::_LockSpecificAction; $$issue ]
Perform Find [ ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
Set Variable [ $time; Value:$repetition & $day ]
Set Field [ specificAction::timeSegmentKeyList; $time & ¶ & $$timeAll ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
#
#Check if the selected SPA ID is in the day
#record's SPA keychain.
If [ specificAction::_LockSpecificAction & "¶" ≠ FilterValues ( $$logIssues ; specificAction::_LockSpecificAction & "¶" ) ]
#
#Add day ID (key) to the SPA's day ID
#keychain.
Set Field [ specificAction::_keyLogs; $day & "¶" & $$IssueLogs ]
Set Variable [ $$IssueLogs; Value:specificAction::_keyLogs ]
#
#Add SPA record's ID to the day (log) record's
#keychain of SPA keys (IDs).
Go to Layout [ “logs1row” (logs) ]
Set Variable [ $$logIssue; Value:logs::_keyLogSPAs ]
Set Field [ logs::_keyLogSPAs; $$issue & "¶" & $$logIssues ]
Set Variable [ $$logIssues; Value:logs::_keyLogSPAs ]
Go to Field [ ]
Refresh Window
#
End If
#
#Determine correct layout on which to show
#all time segments.
Select Window [ Name: "Day"; Current file ]
Go to Layout [ “logs1row” (logs) ]
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
End If
Set Variable [ $$stopRecordLoad ]
#
#Return to Specific Action window and insure
#window is resized to fit in Timer window too.
Select Window [ Name: "Specific Action"; Current file ]
#
#Show record has been modified.
Set Field [ specificAction::dateModified; Get ( CurrentTimeStamp ) ]
#
Refresh Window
#
#
#END Add newly created time segement to SPA.
#
December 16, ଘ౮28 14:59:10 ActionLog.fp7 - startTimerAssignTimeSegmentToSpecificAction -1-
