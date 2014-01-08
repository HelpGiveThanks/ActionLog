log: main: resetMaxHeartRate
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Reset max heart rate to selected exercise max.
If [ Get (LayoutTableName) = "planlog" ]
Set Field [ exerciseMHR::MaxHeartRate; exerciseLog::MaxHeartRateCurrent ]
Set Field [ segment01::MaxHeartRate; exerciseLog::MaxHeartRateCurrent ]
Go to Field [ ]
Else
Set Field [ exerciseActivity::MaxHeartRate; exerciseActivity::MaxHeartRateCurrent ]
Set Field [ segment01::MaxHeartRate; exerciseActivity::MaxHeartRateCurrent ]
Go to Field [ ]
#
End If
January 8, 平成26 12:11:40 Fat and Muscle Efﬁciency Research.fp7 - resetMaxHeartRate -1-
