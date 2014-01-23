planned workouts: main: loadUserPlannedWeek
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop this script while another script is running.
If [ $$stopLoadUserWeek = 1 ]
Exit Script [ ]
End If
#
#Set variables to conditionally format current record.
Set Variable [ $$recordPlanned; Value:Get ( RecordID ) ]
Set Variable [ $$weekPlanned; Value:planlog::kweek ]
Set Variable [ $$planPrediction; Value:week::kprediction ]
Refresh Window
January 8, 平成26 12:29:44 Fat and Muscle Efﬁciency Research.fp7 - loadUserPlannedWeek -1-
