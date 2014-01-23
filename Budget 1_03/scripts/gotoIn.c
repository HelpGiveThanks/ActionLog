gotoIn
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
If [ Get (LayoutName) = "budget" or
Get (LayoutName) = "store" or
Get (LayoutName) = "source" or
Get (LayoutName) = "people" ]
Else
Set Field [ budget::outLayoutGlobal; Get (LayoutName) ]
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
If [ budget::inLayoutGlobal = "" ]
Go to Layout [ “income2” (in) ]
Else
Go to Layout [ budget::inLayoutGlobal ]
If [ Get (LayoutTableName) ≠ "in" ]
Go to Layout [ “income2” (in) ]
End If
End If
#
Enter Find Mode [ ]
Set Field [ in::kbudget; budget::budgetGlobal ]
Perform Find [ ]
#
Perform Script [ “updateIncomeHeaderCalc” ]
Sort Records [ Speciﬁed Sort Order: in::year; ascending
in::Month; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
January 8, 平成26 19:01:25 Budget Research.fp7 - gotoIn -1-
