deleteBudget
Allow User Abort [ Off ]
Set Error Capture [ On ]
Go to Field [ ]
If [ Get (LastError) = 509 ]
Set Variable [ $noName; Value:1 ]
End If
Set Variable [ $delete; Value:budget::_Lbudget ]
#
New Window [ ]
Go to Layout [ “PurchaseTotals1” (out) ]
Enter Find Mode [ ]
Set Field [ out::kbudget; $delete ]
Perform Find [ ]
If [ Get ( LastError ) = 0 ]
Set Variable [ $outNumber; Value:Get (FoundCount) ]
End If
Go to Layout [ “income2” (in) ]
Enter Find Mode [ ]
Set Field [ in::kbudget; $delete ]
Perform Find [ ]
If [ Get ( LastError ) = 0 ]
Set Variable [ $inNumber; Value:Get (FoundCount) ]
Close Window [ Current Window ]
Show Custom Dialog [ Message: "This budget cannot be deleted because there are records attached to this budget: " &
Case ( $inNumber ≠ "" ; "in records = " & $inNumber ) &
Case ( $outNumber ≠ "" ; ", out records = " & $outNumber ) &
"."; Buttons: “OK” ]
#
Else If [ $inNumber + $outNumber < 1 ]
Close Window [ Current Window ]
Go to Field [ budget::name ]
Scroll Window
[ To Selection ]
Go to Field [ ]
Refresh Window
Show Custom Dialog [ Message: "delete current record?"; Buttons: “cancel”, “delete” ]
If [ Get (LastMessageChoice) = 1 ]
Set Variable [ $delete ]
Refresh Window
If [ $noName = 1 ]
Go to Field [ budget::name ]
January 8, 平成26 19:03:54 Budget Research.fp7 - deleteBudget -1-deleteBudget
End If
Exit Script [ ]
End If
Delete Record/Request
[ No dialog ]
If [ $delete = budget::budgetGlobal ]
Set Field [ budget::budgetGlobal; "" ]
End If
End If
#
January 8, 平成26 19:03:54 Budget Research.fp7 - deleteBudget -2-
