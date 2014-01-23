deleteSource
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $delete; Value:source::_Lsource ]
New Window [ ]
Go to Layout [ “income2” (in) ]
Enter Find Mode [ ]
Set Field [ in::ksource; $delete ]
Perform Find [ ]
If [ Get ( LastError ) = 0 ]
Set Variable [ $number; Value:Get (FoundCount) ]
Close Window [ Current Window ]
Show Custom Dialog [ Message: Case ( $number = 1 ; "Source is in use " & $number & " time. You can only delete sources that are not in use. " ; "Source is in use " &
$number & " times. You can only delete sources that are not in use. " ); Buttons: “OK” ]
Set Variable [ $delete ]
Refresh Window
Exit Script [ ]
Else If [ Get ( LastError ) = 401 ]
Close Window [ Current Window ]
Go to Field [ source::source ]
Scroll Window
[ To Selection ]
Go to Field [ ]
Refresh Window
Show Custom Dialog [ Message: "delete current record?"; Buttons: “cancel”, “delete” ]
If [ Get (LastMessageChoice) = 1 ]
Set Variable [ $delete ]
Refresh Window
Exit Script [ ]
End If
Delete Record/Request
[ No dialog ]
End If
January 8, 平成26 19:05:49 Budget Research.fp7 - deleteSource -1-
