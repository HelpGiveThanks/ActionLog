deleteIncome
Set Variable [ $delete; Value:in::_Lin ]
Go to Field [ in::date ]
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
Perform Script [ “updateIncomeHeaderCalc” ]
January 8, 平成26 19:05:04 Budget Research.fp7 - deleteIncome -1-
