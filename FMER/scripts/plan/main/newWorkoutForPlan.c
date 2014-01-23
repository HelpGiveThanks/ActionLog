plan: main: newWorkoutForPlan
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#If there are no records, create new planned week
#for this new week of workouts.
If [ Get (FoundCount) = 0 ]
Go to Layout [ “weekTag” (week) ]
New Record/Request
Set Field [ week::kuser; planlog::kuserGlobal ]
Set Variable [ $newWeek; Value:week::_Lweek ]
Go to Layout [ original layout ]
#
#If there are records then capture the week key for them.
Else
Set Variable [ $newWeek; Value:planlog::kweek ]
End If
#
#Create a new planned workout.
New Record/Request
Set Field [ planlog::kweek; $newWeek ]
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::plannedOrPerformed; "planning" ]
#
#Conditional format new record so user sees that it
#is the active record.
If [ $$stopiphone = 1 ]
Exit Script [ ]
End If
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadPlanWeek” ]
Perform Script [ “enterFormViewIfOniPhone” ]
Go to Field [ ]
#
January 8, 平成26 12:24:04 Fat and Muscle Efﬁciency Research.fp7 - newWorkoutForPlan -1-
