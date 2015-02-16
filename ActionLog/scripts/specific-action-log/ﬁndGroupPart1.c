specific action log: findGroupPart1
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can find specific act records by group."; Buttons:
“OK” ]
Exit Script [ ]
End If
#
#Find all specific actions with this key.
Go to Layout [ “IssuesAndObservationsFIND” (brainstate) ]
Scroll Window
[ Home ]
Set Variable [ $$found ]
#
#Find all specific actions with this key.
Select Window [ Name: "Specific Action"; Current file ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; "nothing" ]
Perform Find [ ]
#
#If user selected the same category that was already
#selected then stop this script.
Select Window [ Name: "Tag"; Current file ]
Go to Layout [ “IssuesAndObservationsFIND” (brainstate) ]
Scroll Window
[ Home ]
#
January 6, 平成26 11:22:02 ActionLog.fp7 - findGroupPart1 -1-
