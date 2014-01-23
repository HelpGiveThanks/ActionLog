user: main: loadUser
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop this script while another script is running.
If [ $$stopLoadUser = 1 ]
Exit Script [ ]
End If
#
#Set variable to conditionally format current record.
Set Variable [ $$recordUser; Value:Get ( RecordID ) ]
Set Field [ planlog::kuserGlobal; exerciseMHR::kuser ]
Set Field [ exerciseMHR::kexerciseGlobal; exerciseMHR::_LexerciseMHR ]
#
#Set max heart rate for workout segment display.
Set Field [ segment01::MaxHeartRate; exerciseMHR::MaxHeartRateCurrent ]
Set Field [ exerciseMHR::MaxHeartRate; exerciseMHR::MaxHeartRateCurrent ]
Refresh Window
Go to Field [ ]
January 8, 平成26 12:05:38 Fat and Muscle Efﬁciency Research.fp7 - loadUser -1-
