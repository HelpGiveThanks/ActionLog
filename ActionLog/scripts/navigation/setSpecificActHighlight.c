action buttons: setSpecificActHighlight
#
#If selected timer is default specific act then
#prevent user from un-highlighting it.
If [ brainstate::_lockBrainstateID = steward::DefaultSpecificAction ]
Set Field [ brainstate::HighlightSpecificActionButton; "r" ]
Go to Field [ ]
Show Custom Dialog [ Message: "This is your default specific action timer. To un-highlight it 1) click the 'defaultspecificact'
button, and then 2) click this check box."; Buttons: “OK” ]
Else
Set Field [ steward::DefaultSpecificAction; "" ]
Go to Field [ ]
End If
#
July 26, ଘ౮28 16:02:01 ActionLog.fp7 - setSpecificActHighlight -1-
