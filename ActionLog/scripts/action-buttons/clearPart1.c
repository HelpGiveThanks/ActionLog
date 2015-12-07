action buttons: clearPart1
If [ day1::swActivityLength = "" ]
Exit Script [ ]
End If
Set Variable [ $$warning; Value:brainstate::_lockBrainstateID ]
Refresh Window
Show Custom Dialog [ Title: "?"; Message: "Clear all today's times for" & ¶ & ¶ & GetValue ( brainstate::description ; 1 ) & "?";
Buttons: “Cancel”, “OK” ]
If [ Get ( LastMessageChoice ) = 1 ]
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
If [ $$logBrainstate ≠ brainstate::_lockBrainstateID ]
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $name; Value:brainstate::description ]
Select Window [ Name: "Timer"; Current file ]
Show Custom Dialog [ Title: "?"; Message: "Specific Action window's timer = " & GetValue ( $name ; 1 )& ¶ & "Timer window's
timer = " & GetValue ( brainstate::description ; 1 ) &¶ & "Really clear Timer window's — " & GetValue ( brainstate::
description ; 1 ) & " — timer?"; Buttons: “Cancel”, “OK” ]
End If
If [ Get ( LastMessageChoice ) = 1 ]
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
Go to Field [ ]
Set Variable [ $$warning ]
Refresh Window
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:brainstate::_lockBrainstateID ]
Perform Script [ “clearPart2 (UPDATED)” ]
December 6, ଘ౮27 20:53:26 ActionLog.fp7 - clearPart1 -1-
