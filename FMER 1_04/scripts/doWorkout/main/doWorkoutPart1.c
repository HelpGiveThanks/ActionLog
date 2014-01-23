doWorkout: main: doWorkoutPart1
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#If the workout has not been totaled then exit script.
If [ activity::go = "" ]
Show Custom Dialog [ Message: "This workout must be totaled before you can do it. (Click the total button.)"; Buttons: “OK” ]
Exit Script [ ]
End If
#
#If the workout has not assigned a focus exit sript.
If [ activity::Type = "" ]
Show Custom Dialog [ Message: "All workouts are required to have a focus. Select one or more by checking the boxes at the
top of the screen."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Set green line to starting position.
Set Field [ activity::segmentNumberGlobal; 1 ]
#
If [ Get (LayoutTableName) = "activity" ]
#
#Capture workout key.
Set Variable [ $workout; Value:activity::_Lactivity ]
#
If [ Get (WindowName) ≠ "Select Workout" ]
New Window [ ]
End If
#Set window title to workout.
Set Window Title [ Current Window; New Title: "Workout" ]
Else
#
#Stop script if there is no written workout assigned.
If [ planlog::kworkout = "" ]
Exit Script [ ]
End If
#
#Capture workout key.
Set Variable [ $workout; Value:planlog::kworkout ]
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Set window title to workout.
New Window [ Name: "Workout" ]
#
#Restart load record script.
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
End If
#
January 8, 平成26 12:35:00 Fat and Muscle Efﬁciency Research.fp7 - doWorkoutPart1 -1-doWorkout: main: doWorkoutPart1
#Show on select layout.
Go to Layout [ “doWorkout” (activity) ]
#
#Find the workout.
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; $workout ]
Perform Find [ ]
#
#Inform user how to start workout.
Set Field [ activitySequence1::message; "click screen to start" ]
Set Field [ activitySequence1::timeToNextSegment; "" ]
#
#Set starting sequence segements.
Set Field [ activity::ksequence1; "" ]
Set Field [ activity::ksequence2; 1 ]
Set Field [ activity::ksequence3; 2 ]
January 8, 平成26 12:35:00 Fat and Muscle Efﬁciency Research.fp7 - doWorkoutPart1 -2-
