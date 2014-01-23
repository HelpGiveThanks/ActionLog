updatePurchaseHeaderCalc
If [ Get (FoundCount) = 0 ]
Set Variable [ $$stopMessage; Value:1 ]
New Record/Request
Set Variable [ $delete; Value:1 ]
End If
If [ out::UpdateCalcField = "" ]
Set Field [ out::UpdateCalcField; "t" ]
Else
Set Field [ out::UpdateCalcField; "" ]
End If
Commit Records/Requests
Refresh Window
If [ $delete = 1 ]
Delete Record/Request
[ No dialog ]
Set Variable [ $$stopMessage ]
End If
January 8, 平成26 19:11:42 Budget Research.fp7 - updatePurchaseHeaderCalc -1-
