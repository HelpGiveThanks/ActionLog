doWorkout: main: selectWorkout
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#if the workout has been logged, inform the user and
#exit the script.
If [ activity::planningOrPlanned ≠ "" ]
Show Custom Dialog [ Message: "This workout is locked. It is part of planned weeks of workouts and/or logged. You may copy
this workout and edit its copy."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Capture workout key.
Set Variable [ $workout; Value:activity::_Lactivity ]
#
#Set max heart rate to current global max.
Set Field [ activity::kexercise; exerciseMHR::kexerciseGlobal ]
Set Field [ exerciseActivity::MaxHeartRate; exerciseActivity::MaxHeartRateCurrent ]
Set Field [ segment01::MaxHeartRate; exerciseActivity::MaxHeartRateCurrent ]
#
#Set green segment bar to segment 1.
Set Field [ activity::segmentNumberGlobal; 1 ]
#
#Close window and then find just this workout.
Close Window [ Current Window ]
Select Window [ Name: "Workout Editor"; Current file ]
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; $workout ]
Perform Find [ ]
#
January 8, 平成26 12:37:54 Fat and Muscle Efﬁciency Research.fp7 - selectWorkout -1-
