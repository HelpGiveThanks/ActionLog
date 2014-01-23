deletePersonName
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $delete; Value:person::_Lperson ]
New Window [ ]
Go to Layout [ “PurchaseTotals1” (out) ]
Enter Find Mode [ ]
Set Field [ out::kperson; $delete ]
Perform Find [ ]
If [ Get ( LastError ) = 0 ]
Set Variable [ $number; Value:Get (FoundCount) ]
Close Window [ Current Window ]
Show Custom Dialog [ Message: Case ( $number = 1 ; "Person/group is in use " & $number & " time. You can only delete a person/group name that is not in use. " ;
"Person/group is in use " & $number & " times. You can only delete a person/group name that is not in use. " ); Buttons: “OK” ]
Else If [ Get ( LastError ) = 401 ]
Close Window [ Current Window ]
Go to Field [ person::person ]
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
January 8, 平成26 19:06:45 Budget Research.fp7 - deletePersonName -1-
