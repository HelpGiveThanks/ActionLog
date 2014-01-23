log: dates: changeDayDatePart2
Allow User Abort [ Off ]
Set Error Capture [ On ]
Set Variable [ $newDate; Value:planlog::date ]
Set Field [ planlog::date; $$olddate ]
#
If [ $newDate < Date ( Left ( planlog::kweekGlobal ; 2 ) ; Middle ( planlog::kweekGlobal ; 3 ; 2 ) ; Middle ( planlog::kweekGlobal ; 5 ;
4 ) ) or
$newDate > Date ( Left ( planlog::kweekGlobal ; 2 ) ; Middle ( planlog::kweekGlobal ; 3 ; 2 ) ; Middle ( planlog::kweekGlobal ; 5 ;
4 ) ) + 7 ]
Go to Field [ ]
Show Custom Dialog [ Message: "Workout week days must be within the workout week. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
Set Field [ planlog::date; $newDate ]
Go to Field [ ]
#
January 8, 平成26 12:16:45 Fat and Muscle Efﬁciency Research.fp7 - changeDayDatePart2 -1-
