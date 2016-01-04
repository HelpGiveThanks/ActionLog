specific action log: stopTimerAssignedToSpecificAction
#
#
#Exit the script if the timer is not running.
If [ day1::swBugField ≠ "veto" ]
Exit Script [ ]
End If
#
#
#Only allow timer to be stopped if it is running today
#or tomorrow (meaning today after midnight).
If [ reference::day1 = Get ( CurrentDate ) or reference::day1 + 1 = Get ( CurrentDate ) ]
#
If [ reference::day1 ≠ reference::ActivityLogDay ]
Select Window [ Name: "Day"; Current file ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Select Window [ Name: "Specific Action"; Current file ]
End If
#
If [ day1::swBugField = "veto" ]
#
Set Variable [ $$specificActionTimer; Value:1 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#
#
New Window [ Height: 1; Width: 1; Top: -10000; Left: -10000 ]
Go to Layout [ “01EditTime” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
Set Variable [ $userID; Value:reference::farmerID ]
Set Variable [ $$updateDay; Value:day1::_lockDay ]
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:brainstate::_lockBrainstateID ]
#
#5 if the veto button is showing stop the
#stopwatch and put in the in the time stopped.
Set Variable [ $$stopwatchON; Value:"f" ]
Set Field [ day1::swPause[day1::swOccurances]; Get ( CurrentTimeStamp ) ]
#
#Remove the active green formating from the
#Specific Action and Day windows.
Set Variable [ $$day1BugField ]
#
#5 recalculate the time for this record.
#1 equalize these two times, thus unflagging this record as needing updating.
#
Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
#
#
Perform Script [ “updatePauseTotals” ]
#
#
Perform Script [ “CHUNK_updateIssueCategoryTime” ]
#
#
Close Window [ Current Window ]
#
#NOTE: This next section can probably be
#deleted as it done by the previous script
#CHUNK... .
// #Go to record time to which time will be added.
// Select Window [ Name: "Specific Action"; Current file ]
// If [ FilterValues (issue::timeSegmentKeyList ; $$activeTimeSegment & "¶") ≠ $$activeTimeSegment & "¶" ]
// Go to Record/Request/Page
[ First ]
// Loop
// Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; $$activeTimeSegment & "¶") = $$activeTimeSegment
& "¶" ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
// #
// #If record is not showing then find and add it to
// #list of records being shown.
// If [ FilterValues (issue::timeSegmentKeyList ; $$activeTimeSegment & "¶") ≠ $$activeTimeSegment & "¶" ]
// Enter Find Mode [ ]
// Set Field [ issue::timeSegmentKeyList; $$activeTimeSegment & "¶" ]
// Extend Found Set [ ]
// Sort Records [ ]
[ No dialog ]
// Go to Record/Request/Page
[ First ]
// Loop
// Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; $$activeTimeSegment & "¶") = $
$activeTimeSegment & "¶" ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
// End If
// Set Variable [ $$stopRecordLoad ]
// Set Variable [ $$TimeAssignedToSpecificAction ]
// Perform Script [ “loadIssuerecordID” ]
// End If
#
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$specificActionTimer ]
Set Variable [ $$TimeAssignedToSpecificAction ]
#
Refresh Window
#
End If
#
#
Else
#
Show Custom Dialog [ Message: "Go to the Timer window to stop a timer for a specific action taking place in the past. This
button can only be used for stopping a timer running in the present. Timer window date is " & reference::ActivityLogDay & ".
Change this date in the timer window."; Buttons: “OK” ]
#
End If
#
January 4, ଘ౮28 4:11:27 ActionLog.fp7 - stopTimerAssignedToSpecificAction -1-
