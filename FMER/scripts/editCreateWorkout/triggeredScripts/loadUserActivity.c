editCreateWorkout: triggeredScripts: loadUserActivity
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop this script while another script is running.
If [ $$stopLoadUserWeek = 1 ]
Exit Script [ ]
End If
#
#Set variables to conditionally format current record.
Set Variable [ $$recordActivity; Value:activity::_Lactivity ]
Refresh Window
January 8, 平成26 15:40:06 Fat and Muscle Efﬁciency Research.fp7 - loadUserActivity -1-
