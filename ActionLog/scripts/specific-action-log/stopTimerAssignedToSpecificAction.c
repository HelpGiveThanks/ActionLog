specific action log: stopTimerAssignedToSpecificAction
#
#
#Set variable if the Specific Actions timer is active.
Set Variable [ $active; Value:specificAction::timer ]
#
#Make sure the user has entered a time segment
#in the Timer window, and dragged its time to
#another time segement, and hasn't exited the
#the initial entered time segment (allowing the
#updateTime script to do its job).
Select Window [ Name: "Timer"; Current file ]
#
#This next step exits any time segment field if
#the user should happen to be in one.
#Once this script exits the time segement field
#in the Timer window, the updateTime script
#will start. This next variable will allow
#this 'stop' button script to continue after
#the update.
Set Variable [ $$timerWindowCheck; Value:1 ]
Go to Field [ ]
Set Variable [ $$timerWindowCheck ]
#
#Make sure to focus Timer window on current
#Specific Action Timer.
Set Variable [ $$stopRecordLoad; Value:1 ]
If [ $$logBrainstate ≠ timer::_lockTimer ]
Set Variable [ $timerWindowRecordNumber; Value:Get (RecordNumber) ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$logBrainstate = timer::_lockTimer ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
#
#
#BEGIN See if user can stop timer.
#
#
#
#Exit the script if the timer is not running.
If [ day1::swBugField ≠ "veto" and $active = "" ]
#
#Return user to record they where focused on
#before this script started.
If [ $timerWindowRecordNumber ≠ "" ]
Go to Record/Request/Page [ $timerWindowRecordNumber ]
[ No dialog ]
Set Variable [ $$stopRecordLoad ]
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
Exit Script [ ]
End If
#
#Only allow timer in the main Timer window
#to be stopped if it is running today or
#yesterday (in case the user's day goes into
#the morning hours of the next day).
If [ //reference::day1 = date of main Timer window
reference::day1 ≠ Get ( CurrentDate ) and Get ( CurrentDate ) - 1 > reference::day1 ]
#
#Return user to record they where focused on
#before this script started.
If [ $timerWindowRecordNumber ≠ "" ]
Go to Record/Request/Page [ $timerWindowRecordNumber ]
[ No dialog ]
Set Variable [ $$stopRecordLoad ]
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
#Inform user why the can't use the button.
Show Custom Dialog [ Message: "The 'stop' button cannot stop timers running in the past. To stop this " & reference::
ActivityLogDay & " timer: 1) click the 'timer' button above. 2) Go to the edit-time view. 3) Insert a stop time for it."; Buttons:
“OK” ]
Exit Script [ ]
End If
#
#If the Timer window is focused on yesterday,
#make sure there are no Timers running today.
If [ //day1 is yesterday = true or 1.
 ( reference::day1 = Get ( CurrentDate ) - 1 ) = 1 ]
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
Set Variable [ $$specificActionTimer ]
End If
#
#Return user to record they where focused on
#before this script started.
If [ $timerWindowRecordNumber ≠ "" ]
Go to Record/Request/Page [ $timerWindowRecordNumber ]
[ No dialog ]
Set Variable [ $$stopRecordLoad ]
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
#Don't allow user to stop the timer the timer
#is in the future.
If [ //reference::day1 = date of timer window.
Get (CurrentDate) < reference::day1 ]
Show Custom Dialog [ Message: "Timer window is in the future. Return the timer window to today. 1) Go to the Timer window
(click the 'timer' button above). 2) Move the Timer window date back to today."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Don't allow user to stop the timer if the
#the user started creating timer records for
#today, and the Timer window is focused
#on yesterday.
If [ //1) day1 is today = false or 0, and
 ( reference::day1 = Get ( CurrentDate ) ) = 0 and
//2) day1 is yesterday and there are no day1 records for today = false.
 ( reference::day1 = Get ( CurrentDate ) - 1 and $todayExists ≠ 1 ) = 0 ]
Show Custom Dialog [ Message: "The 'stop' button cannot stop timer's in the past, which " & Get ( CurrentDate ) - 1 & " became
once a " & Get ( CurrentDate ) & " timer was started. To stop yesterday's timer: 1) click the 'timer' button above. 2) Go to the
edit-time view. 3) Insert a stop time for this timer."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Don't allow user to stop the timer if is active
#a day previous to the day in the Timer window.
If [ //reference::ActivityLogDay = date of selected Day window record.
reference::ActivityLogDay < reference::day1 and specificAction::timer = "active" ]
Show Custom Dialog [ Message: "Timer window is one day ahead. To stop this timer 1) go to the Timer window (click the 'timer'
button above). 2) Move the Timer window date one day back. 3) Insert a stop time OR try clicking the 'stop' button again.";
Buttons: “OK” ]
Exit Script [ ]
End If
#
#Make sure the user if focused on the first
#record in the Day window.
If [ reference::day1 ≠ reference::ActivityLogDay ]
Select Window [ Name: "Day"; Current file ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Select Window [ Name: "Specific Action"; Current file ]
End If
#
#Stop timer.
If [ day1::swBugField = "veto" ]
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $$specificActionTimer; Value:1 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Isolate just the timer to be stopped.
New Window [ Height: 1; Width: 1; Top: -10000; Left: -10000 ]
Go to Layout [ “01EditTime” (timer) ]
Enter Find Mode [ ]
Set Field [ timer::_lockTimer; $$logBrainstate ]
Perform Find [ ]
#
#Note day user is on.
Set Variable [ $userID; Value:reference::userID ]
Set Variable [ $$updateDay; Value:day1::_lockDay ]
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:timer::_lockTimer ]
#
#Stop the timer and put record the
#time stopped.
Set Variable [ $$stopwatchON; Value:"f" ]
Set Field [ day1::swPause[day1::swOccurances]; Get ( CurrentTimeStamp ) ]
#
#Remove the active green formating from the
#Day window.
Set Variable [ $$day1BugField ]
#
#Recalculate the time for this record.
Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
Perform Script [ “updatePauseTotals” ]
Close Window [ Current Window ]
#
#Update the Specific Action record's total time.
Perform Script [ “CHUNK_updateIssueCategoryTime” ]
#
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$specificActionTimer ]
Set Variable [ $$TimeAssignedToSpecificAction ]
#
#Show Specific Action record has been modified.
Set Field [ specificAction::dateModified; Get ( CurrentTimeStamp ) ]
#
Refresh Window
#
End If
#
December 10, ଘ౮28 23:24:21 ActionLog.fp7 - stopTimerAssignedToSpecificAction -1-
