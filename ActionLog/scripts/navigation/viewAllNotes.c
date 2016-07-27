navigation: viewAllNotes
#
#
Set Variable [ $$note; Value:1 ]
New Window [ Name: "Timer Notes"; Height: Get (ScreenHeight); Width: Get (ScreenWidth)/2; Top: 0; Left: Get (ScreenWidth)/4 ]
Set Zoom Level
[ 100% ]
Go to Layout [ “AllNotes1row” (logs) ]
#
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $$timerIDnumber ]
Perform Find [ ]
#
#Sort and go to first record.
Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending
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
2) then click '" & brainstate::description & "'."; Buttons: “OK” ]
Go to Field [ ]
Else
Go to Field [ ]
End If
Pause/Resume Script [ Indefinitely ]
July 26, ଘ౮28 16:04:09 ActionLog.fp7 - viewAllNotes -1-
