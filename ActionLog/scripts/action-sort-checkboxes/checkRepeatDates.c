action sort checkboxes: CheckRepeatDates
If [ brainstate::scheduleRepeatEventYear ≠ "" ]
Show Custom Dialog [ Title: "pick one"; Message: "Choose to repeat item on specific weeks of the month OR every so many weeks, but
not both."; Buttons: “OK” ]
Set Field [ brainstate::scheduleRepeatEventMonth; "" ]
Go to Field [ ]
End If
January 6, 平成26 12:53:53 ActionLog.fp7 - CheckRepeatDates -1-
