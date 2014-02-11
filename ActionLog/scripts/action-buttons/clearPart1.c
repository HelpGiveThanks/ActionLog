action buttons: clearPart1
If [ day1::swActivityLength = "" ]
Exit Script [ ]
End If
Set Variable [ $$warning; Value:brainstate::_lockBrainstateID ]
Refresh Window
Show Custom Dialog [ Title: "?"; Message: "Clear all today's times for" & ¶ & ¶ & brainstate::description & "?"; Buttons: “Cancel”, “OK” ]
If [ Get ( LastMessageChoice ) = 1 ]
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
Set Variable [ $$warning ]
Refresh Window
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:brainstate::_lockBrainstateID ]
Perform Script [ “clearPart2” ]
January 5, 平成26 19:41:54 ActionLog.fp7 - clearPart1 -1-
