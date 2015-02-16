alarm: TimerPart2
If [ reference::repeatAlarm ≠ "" ]
Perform Script [ “TimerRepeatAlarm” ]
Halt Script
End If
Insert Current Time [ reference::TimerSet ]
[ Select ]
Go to Layout [ “timerAlarm” (steward) ]
Go to Field [ ]
Pause/Resume Script [ Duration (seconds): 11 ]
Go to Layout [ “timerSetAlarm” (steward) ]
Go to Field [ ]
Pause/Resume Script [ Duration (seconds): reference::gDuration ]
Go to Layout [ “timerAlarm” (steward) ]
Adjust Window
[ Hide ]
Pause/Resume Script [ Duration (seconds): 11 ]
Go to Layout [ $$alarmLayout ]
// Close Window [ Name: "Predict Activity Time"; Current file ]
January 6, 平成26 13:01:14 ActionLog.fp7 - TimerPart2 -1-
