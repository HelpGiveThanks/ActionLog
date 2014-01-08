plan: main: loadPlanWeek
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop this script while another script is running.
If [ $$stopLoadUserWeek = 1 ]
Exit Script [ ]
End If
#
#Set variables to conditionally format current record.
Set Variable [ $$recordPlan; Value:Get ( RecordID ) ]
Refresh Window
January 8, 平成26 12:21:34 Fat and Muscle Efﬁciency Research.fp7 - loadPlanWeek -1-
