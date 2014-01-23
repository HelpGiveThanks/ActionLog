chooseBudget
Allow User Abort [ Off ]
Set Error Capture [ On ]
Set Field [ budget::budgetGlobal; budget::_Lbudget ]
Go to Field [ ]
If [ Get (LastError) = 509 ]
Go to Field [ budget::name ]
End If
January 8, 平成26 19:01:54 Budget Research.fp7 - chooseBudget -1-
