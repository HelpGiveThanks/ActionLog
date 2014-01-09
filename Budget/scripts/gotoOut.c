gotoOut
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
If [ Get (LayoutName) = "budget" or
Get (LayoutName) = "store" or
Get (LayoutName) = "source" or
Get (LayoutName) = "people" ]
Else
Set Field [ budget::inLayoutGlobal; Get (LayoutName) ]
End If
#
If [ Get (FoundCount) = 0 & Get (LayoutName) = "Budget" ]
Show Custom Dialog [ Message: "There are no budgets to view."; Buttons: “OK” ]
Exit Script [ ]
End If
#
If [ budget::budgetGlobal = "" ]
Show Custom Dialog [ Message: "Click a button next the budget you want to view."; Buttons: “OK” ]
Exit Script [ ]
End If
#
If [ budget::outLayoutGlobal = "" ]
Else
Go to Layout [ budget::outLayoutGlobal ]
If [ Get (LayoutTableName) ≠ "out" ]
Go to Layout [ “PurchaseTotals3” (out) ]
End If
End If
#
Enter Find Mode [ ]
Set Field [ out::kbudget; budget::budgetGlobal ]
Perform Find [ ]
#
Perform Script [ “updatePurchaseHeaderCalc” ]
Sort Records [ Speciﬁed Sort Order: out::_Lyear; ascending
out::_Lmonth; ascending
person::person; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
January 8, 平成26 19:00:56 Budget Research.fp7 - gotoOut -1-
