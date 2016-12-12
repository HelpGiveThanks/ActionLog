action buttons: clearPart1
#PURPOSE activated by the 'cleartime' and sets
#up the 'clearPart2' script to clear all time for a
#given day for the selected timer.
#
If [ day1::swActivityLength = "" ]
Exit Script [ ]
End If
Set Variable [ $$warning; Value:timer::_lockTimer ]
Refresh Window
Show Custom Dialog [ Title: "?"; Message: "Clear all today's times for" & ¶ & ¶ & GetValue ( timer::description ; 1 ) & "?"; Buttons:
“Cancel”, “OK” ]
If [ Get ( LastMessageChoice ) = 1 ]
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
If [ $$logBrainstate ≠ timer::_lockTimer ]
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $name; Value:timer::description ]
Select Window [ Name: "Timer"; Current file ]
Show Custom Dialog [ Message: "JUST TO BE SURE: Timer Window = '" & GetValue ( timer::description ; 1 ) & "', WHILE"& ¶ &
"Specific Action windows = '" & GetValue ( $name; 1) & "'."
& ¶ & ¶ & "Continue to clear time for '" & GetValue ( timer::description ; 1 ) & "'?"; Buttons: “cancel”, “yes” ]
End If
If [ Get ( LastMessageChoice ) = 1 ]
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
Go to Field [ ]
Set Variable [ $$warning ]
Refresh Window
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:timer::_lockTimer ]
Perform Script [ “clearPart2 (update)” ]
#
Set Variable [ $$clear ]
#
#
December 10, ଘ౮28 20:47:42 ActionLog.fp7 - clearPart1 -1-
