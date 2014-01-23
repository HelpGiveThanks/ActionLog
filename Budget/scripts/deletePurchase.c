deletePurchase
Set Variable [ $delete; Value:out::_Lout ]
Go to Field [ out::Date ]
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
Perform Script [ “updatePurchaseHeaderCalc” ]
// Insert Text [ out::UpdateCalcField; “1” ]
[ Select ]
// Commit Records/Requests
[ No dialog ]
// Clear [ out::UpdateCalcField ]
[ Select ]
// Commit Records/Requests
[ No dialog ]
// Enter Browse Mode
January 8, 平成26 19:03:12 Budget Research.fp7 - deletePurchase -1-
