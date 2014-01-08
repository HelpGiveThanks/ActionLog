log: main: loadUserLogWeek
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop script if other script is running.
If [ $$stopLoadUserWeek = 1 ]
Exit Script [ ]
End If
#
#Set fields to conditionally format current workout and
#workout week.
Set Field [ planlog::dateGlobal; week::date ]
Set Variable [ $$record; Value:Get ( RecordID ) ]
Set Field [ planlog::kweekGlobal; planlog::kweek ]
#
#Reset max heart rate to selected exercise max.
Set Field [ segment01::MaxHeartRate; exerciseLog::MaxHeartRateCurrent ]
Set Field [ exerciseMHR::MaxHeartRate; exerciseLog::MaxHeartRateCurrent ]
#
Go to Field [ ]
Refresh Window
#
January 8, 平成26 12:09:23 Fat and Muscle Efﬁciency Research.fp7 - loadUserLogWeek -1-
