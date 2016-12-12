navigation: viewAllNotes
#
#Open note view in a new window so as not
#effect the Timer window.
Set Variable [ $$note; Value:1 ]
New Window [ Name: "Timer Notes"; Height: Get (ScreenHeight); Width: Get (ScreenWidth)/2; Top: 0; Left: Get (ScreenWidth)/4 ]
Set Zoom Level
[ 100% ]
Go to Layout [ “AllNotes1row” (logs) ]
#
#
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
Enter Find Mode [ ]
Set Field [ logs::_keyTimer; $$timerIDnumber ]
Perform Find [ ]
#
#If no records are found (because this timer
#has never been used) then tell the user this.
If [ Get (FoundCount) = 0 ]
Close Window [ Current Window ]
Show Custom Dialog [ Message: "You have never used/started this timer. A note is part of a timer's day record. Create a timer
day record for '" & timer::description & "' by clicking on it. Then you can create a note for it."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Sort and go to first record.
Sort Records [ Specified Sort Order: logs::_keyTimer; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
Set Variable [ $$note ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
#
#
If [ Get ( CurrentDate ) = day1::_keyDay or
Get ( CurrentDate ) - 1 = day1::_keyDay or
Get ( CurrentDate ) + 1 = day1::_keyDay ]
Else If [ Get ( CurrentDate ) = reference::day1 // or
// Get ( CurrentDate ) - 1 = reference::day1 or
// Get ( CurrentDate ) + 1 = reference::day1 ]
Show Custom Dialog [ Message: "You must start a timer in order to create a note for " & reference::day1 & ". 1) Click 'back' and
2) then click '" & timer::description & "'."; Buttons: “OK” ]
Go to Field [ ]
Else
Go to Field [ ]
End If
Pause/Resume Script [ Indefinitely ]
December 12, ଘ౮28 10:47:48 ActionLog.fp7 - viewAllNotes -1-
