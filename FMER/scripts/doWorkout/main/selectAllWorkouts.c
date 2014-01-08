doWorkout: main: selectAllWorkouts
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Capture workout key.
Set Variable [ $workout; Value:planlog::kworkout ]
#
#Stop the user week record script from loading to
#speed up script and to stop variables from being wiped
#out.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Find all workouts for this user.
New Window [ Name: "Select Workout" ]
#
#Show on select layout.
Go to Layout [ “selectWorkout” (activity) ]
Enter Find Mode [ ]
Set Field [ activity::kuser; planlog::kuserGlobal ]
Perform Find [ ]
#
#Restart load record script.
Set Variable [ $$stopLoadUserWeek ]
#
#If $workout is not blank then go to that workout.
If [ $workout ≠ "" ]
Loop
Exit Loop If [ activity::_Lactivity = $workout ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
#
#Hilight current record.
Perform Script [ “loadUserActivity” ]
January 8, 平成26 12:37:25 Fat and Muscle Efﬁciency Research.fp7 - selectAllWorkouts -1-
