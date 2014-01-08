plan: main: setWorkoutEditorGoal
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#If there are no records then exit script.
If [ Get (FoundCount) = 0 ]
Exit Script [ ]
End If
#
#Capture current window name.
Set Variable [ $window; Value:Get ( WindowName ) ]
#
#Select the Workout Editor window.
Select Window [ Name: "Workout Editor"; Current file ]
#
#If there is no workout, then create a new one.
If [ Get (FoundCount) = 0 ]
Perform Script [ “NewWorkout” ]
End If
#
#Capture the current workouts key.
Set Variable [ $workout; Value:activity::_Lactivity ]
Go to Field [ ]
#
#Select the previous window.
Select Window [ Name: $window; Current file ]
#
#If the current record is assigned to a workout then capture
#this key. Next insert the key for the current workout
#being edited so that its goal fields can be populated
#with the time from this record.
If [ planlog::kworkout ≠ "" ]
Set Variable [ $returnToWorkout; Value:planlog::kworkout ]
Set Field [ planlog::kworkout; $workout ]
Set Field [ activity::z1timeGoal; planlog::z1workoutTime ]
Set Field [ activity::z2timeGoal; planlog::z2workoutTime ]
Set Field [ activity::z3timeGoal; planlog::z3workoutTime ]
Set Field [ activity::z4timeGoal; planlog::z4workoutTime ]
Set Field [ activity::z5timeGoal; planlog::z5workoutTime ]
#
#Re-insert the orginal workout's key.
Set Field [ planlog::kworkout; $returnToWorkout ]
#
#Insert the key for the current workout
#being edited so that its goal fields can be populated
#with the time from this record.
Else
Set Field [ planlog::kworkout; $workout ]
Set Field [ activity::z1timeGoal; Case ( Time ( planlog::z1hour ; planlog::z1minute ; planlog::z1second ) = 0 ; "" ; Time ( planlog::
z1hour ; planlog::z1minute ; planlog::z1second ) ) ]
Set Field [ activity::z2timeGoal; Case ( Time ( planlog::z2hour ; planlog::z2minute ; planlog::z2second ) = 0 ; "" ; Time ( planlog::
z2hour ; planlog::z2minute ; planlog::z2second ) ) ]
January 8, 平成26 12:24:39 Fat and Muscle Efﬁciency Research.fp7 - SetWorkoutEditorGoal -1-plan: main: SetWorkoutEditorGoal
Set Field [ activity::z3timeGoal; Case ( Time ( planlog::z3hour ; planlog::z3minute ; planlog::z3second ) = 0 ; "" ; Time ( planlog::
z3hour ; planlog::z3minute ; planlog::z3second ) ) ]
Set Field [ activity::z4timeGoal; Case ( Time ( planlog::z4hour ; planlog::z4minute ; planlog::z4second ) = 0 ; "" ; Time ( planlog::
z4hour ; planlog::z4minute ; planlog::z4second ) ) ]
Set Field [ activity::z5timeGoal; Case ( Time ( planlog::z5hour ; planlog::z5minute ; planlog::z5second ) = 0 ; "" ; Time ( planlog::
z5hour ; planlog::z5minute ; planlog::z5second ) ) ]
#
#Clear the workout key field.
Set Field [ planlog::kworkout; "" ]
End If
#
#Leave this record's fields so that the conditional formatting
#can refresh.
Go to Field [ ]
#
#Go to the workout editor window, where the goal fields
#have now been updated.
Select Window [ Name: "Workout Editor"; Current file ]
January 8, 平成26 12:24:39 Fat and Muscle Efﬁciency Research.fp7 - SetWorkoutEditorGoal -2-
