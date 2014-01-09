newBudget
Allow User Abort [ Off ]
Set Error Capture [ On ]
Go to Field [ ]
If [ Get (LastError) = 509 ]
Go to Field [ budget::name ]
Exit Script [ ]
End If
New Record/Request
Set Field [ budget::name; "test" ]
Set Variable [ $budget; Value:budget::_Lbudget ]
Go to Layout [ “target” (outTarget) ]
New Record/Request
Set Field [ outTarget::kbudget; $budget ]
Go to Layout [ “budget” (budget) ]
Set Field [ budget::name; "" ]
Go to Field [ budget::name ]
January 8, 平成26 18:48:30 Budget Research.fp7 - newBudget -1-
