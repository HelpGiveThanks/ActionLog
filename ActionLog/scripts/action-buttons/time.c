action buttons: time
#PURPOSE script attached to the time button on the edit time layouts. It checks if user is in a time field, and if they are inserts the current time
into it, and if they are not tells them how to use the time button.
#
#
If [ brainstate::_lockBrainstateID = brainstate::groupID ]
Go to Field [ ]
Halt Script
End If
#
#1 determine if the user is in a time field
If [ Get ( ActiveFieldName ) = "swPause" or Get ( ActiveFieldName ) = "swStart" ]
#
#2 if they are then insert the current time into it
Insert Current Time [ ]
[ Select ]
Go to Field [ ]
Halt Script
End If
#
#2 if they are not tell them how to use this button
Show Custom Dialog [ Title: "!"; Message: "This button is for inserting the current time into a stop or start time field."; Buttons: “OK” ]
January 5, 平成26 19:57:24 ActionLog.fp7 - time -1-
