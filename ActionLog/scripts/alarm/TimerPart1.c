Alarm: TimerPart1
#basic administration tasks (required to prevent error message: record can't be modﬁed because it is open in another window)
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $activity; Value:brainstate::description ]
Set Variable [ $$alarmLayout; Value:Get ( LayoutName ) ]
// New Window [ Name: "Predict Activity Time"; Height: 420; Width: 630; Top: Get ( WindowHeight ) / 3; Left: Get ( WindowWidth ) / 3 ]
// Show/Hide Status Area
[ Lock; Hide ]
// Show/Hide Text Ruler
[ Hide ]
Go to Layout [ “timerSetAlarm” (steward) ]
Set Field [ reference::TimerDescription; $activity ]
Set Field [ reference::TimerSet; "" ]
Set Field [ reference::repeatAlarm; "" ]
// Pause/Resume Script [ Indeﬁnitely ]
January 6, 平成26 13:00:11 ActionLog.fp7 - TimerPart1 -1-
