plan: navigation: backToPlannedWorkouts
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
Set Window Title [ Current Window; New Title: "Planned Workouts" ]
Adjust Window
[ Resize to Fit ]
Set Variable [ $width; Value:Get (WindowWidth) ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: $width ]
Go to Layout [ “plannedWeek” (planlog) ]
Perform Find [ Specified Find Requests: Find Records; Criteria: planlog::kuser: “=” ]
[ Restore ]
#
Close Window [ Name: "Plan Week"; Current file ]
Close Window [ Name: "Icons"; Current file ]
Close Window [ Name: "Workout Editor"; Current file ]
#
Select Window [ Name: "Plan Week"; Current file ]
January 8, 平成26 12:28:01 Fat and Muscle Efﬁciency Research.fp7 - backToPlannedWorkouts -1-
