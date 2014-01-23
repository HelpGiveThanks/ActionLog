deleteStore
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $delete; Value:store::_Lstore ]
New Window [ ]
Go to Layout [ “purchases” (Art) ]
Enter Find Mode [ ]
Set Field [ Art::kstore; $delete ]
Perform Find [ ]
If [ Get ( LastError ) = 0 ]
Set Variable [ $number; Value:Get (FoundCount) ]
Close Window [ Current Window ]
Show Custom Dialog [ Message: Case ( $number = 1 ; "Store/organization/etc. is in use " & $number & " time. You can only delete a store/organization/etc. name that is
not in use. " ; "Store/organization/etc. is in use " & $number & " times. You can only delete a store/organization/etc. name that is not in use. " ); Buttons: “OK” ]
Else If [ Get ( LastError ) = 401 ]
Close Window [ Current Window ]
Go to Field [ store::store ]
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
January 8, 平成26 19:06:18 Budget Research.fp7 - deleteStore -1-
