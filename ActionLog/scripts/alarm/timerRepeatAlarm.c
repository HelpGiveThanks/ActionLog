alarm: TimerRepeatAlarm
Insert Current Time [ reference::TimerSet ]
[ Select ]
Go to Layout [ “timerAlarm” (steward) ]
Go to Field [ ]
Pause/Resume Script [ Duration (seconds): 11 ]
Go to Layout [ “timerSetAlarm” (steward) ]
Go to Field [ ]
Loop
Pause/Resume Script [ Duration (seconds): reference::gDuration ]
Go to Layout [ “timerAlarm” (steward) ]
// Adjust Window
[ Hide ]
Pause/Resume Script [ Duration (seconds): 11 ]
Go to Layout [ “timerSetAlarm” (steward) ]
End Loop
// Close Window [ Name: "Predict Activity Time"; Current ﬁle ]
January 6, 平成26 13:01:46 ActionLog.fp7 - TimerRepeatAlarm -1-
