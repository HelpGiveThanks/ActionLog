changeDate
Allow User Abort [ Off ]
Set Error Capture [ On ]
Set Variable [ $record; Value:out::_Lout ]
Set Variable [ $month; Value:out::_Lmonth ]
Set Variable [ $year; Value:out::_Lyear ]
New Window [ ]
Go to Layout [ “purchases” (Art) ]
Enter Find Mode [ ]
Set Field [ Art::kout; $record ]
Perform Find [ ]
Go to Record/Request/Page
[ First ]
Loop
Set Field [ Art::kmonth; $month ]
Set Field [ Art::kyear; $year ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Close Window [ Current Window ]
Sort Records [ ]
[ No dialog ]
January 8, 平成26 19:10:33 Budget Research.fp7 - changeDate -1-
