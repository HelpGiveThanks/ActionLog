user: main: selectExerciseDELETE
If [ exerciseMHR::MaxHeartRateTestBPM = "" ]
Set Field [ exerciseMHR::MaxHeartRate; "" ]
Set Field [ planlog::kexercise; "" ]
Go to Field [ ]
Show Custom Dialog [ Message: "Before this exericse can be selected you need to put in the bpm (beats-per-minute) for the
max-heart rate determined during your last max-heart-rate test for this exericise."; Buttons: “OK” ]
Exit Script [ ]
End If
Set Field [ exerciseMHR::MaxHeartRate; exerciseMHR::MaxHeartRateCurrent ]
Set Field [ planlog::kuserGlobal; exerciseMHR::kuser ]
Go to Field [ ]
January 8, 平成26 12:07:01 Fat and Muscle Efﬁciency Research.fp7 - selectExerciseDELETE -1-
