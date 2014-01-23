updateIncomeHeaderCalc
If [ Get (FoundCount) = 0 ]
New Record/Request
Set Variable [ $delete; Value:1 ]
End If
If [ out::UpdateCalcField = "" ]
Set Field [ in::UpdateCalcField; "t" ]
Else
Set Field [ in::UpdateCalcField; "" ]
End If
Commit Records/Requests
Refresh Window
If [ $delete = 1 ]
Delete Record/Request
[ No dialog ]
End If
January 8, 平成26 19:12:26 Budget Research.fp7 - updateIncomeHeaderCalc -1-
