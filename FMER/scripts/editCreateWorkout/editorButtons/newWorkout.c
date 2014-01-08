editCreateWorkout: editorButtons: newWorkout
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Create a new segment record for this workout.
New Record/Request
Set Field [ activity::kuser; planlog::kuserGlobal ]
#
#Set greem line to starting position.
Set Field [ activity::segmentNumberGlobal; 1 ]
#
#Capture workout key and then find just this workout.
Set Variable [ $workout; Value:activity::_Lactivity ]
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; $workout ]
Perform Find [ ]
#
#Set max heart rate to current global max.
Set Field [ activity::kexercise; exerciseMHR::kexerciseGlobal ]
Set Field [ exerciseActivity::MaxHeartRate; exerciseActivity::MaxHeartRateCurrent ]
Set Field [ segment01::MaxHeartRate; exerciseActivity::MaxHeartRateCurrent ]
#
#Create a first segment for this workout.
Perform Script [ “NewSegment” ]
#
January 8, 平成26 12:38:25 Fat and Muscle Efﬁciency Research.fp7 - NewWorkout -1-
