action buttons: info
#PURPOSE open a window to display record info if there is any to display.
#
#
#
#1 check to see if there is info
If [ brainstate::linkinfo ≠ "" ]
#
#2 open window and display info
New Window [ Name: "info"; Height: 500; Width: 400 ]
Show/Hide Status Area
[ Lock; Hide ]
Show/Hide Text Ruler
[ Hide ]
Go to Layout [ “info” (brainstate) ]
End If
January 5, 平成26 19:48:09 ActionLog.fp7 - info -1-
