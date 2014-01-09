duplicatePurchase
Allow User Abort [ Off ]
Set Error Capture [ On ]
Freeze Window
Set Variable [ $$stopMessage; Value:1 ]
Set Variable [ $record; Value:out::_Lout ]
Set Variable [ $date; Value:out::Date ]
Set Field [ budget::outLayoutGlobal; Get (LayoutName) ]
New Window [ ]
Freeze Window
New Record/Request
Set Variable [ $recordDuplicate; Value:out::_Lout ]
Delete Record/Request
[ No dialog ]
Enter Find Mode [ ]
Set Field [ out::_Lout; $record ]
Perform Find [ ]
Duplicate Record/Request
Set Field [ out::_Lout; $recordDuplicate ]
Set Field [ out::Date; Case ( Month ( $date ) + 1 = 13 ;
1 & "/" & 1 & "/" & Year ( $date ) + 1 ;
( Month ( $date ) + 1 ) & "/" & 1 & "/" & Year ( $date ) ) ]
Set Variable [ $date; Value:out::Date ]
Go to Layout [ “purchases” (Art) ]
Enter Find Mode [ ]
Set Field [ Art::kout; $record ]
Perform Find [ ]
Loop
Go to Record/Request/Page
[ Last ]
Set Variable [ $kout; Value:Art::kout ]
New Record/Request
Set Variable [ $purchaseDuplicate; Value:Art::_Lpurchases ]
Delete Record/Request
[ No dialog ]
Duplicate Record/Request
Set Field [ Art::_Lpurchases; $purchaseDuplicate ]
Set Field [ Art::kout; $recordDuplicate ]
Set Field [ Art::date; $date ]
Set Field [ Art::kmonth; Month ( $date ) ]
Set Field [ Art::kyear; Year ( $date ) ]
January 8, 平成26 18:54:27 Budget Research.fp7 - duplicatePurchase -1-duplicatePurchase
#507 errror due to invalid date.
#507 errror due to invalid date.
#507 errror due to invalid date.
#507 errror due to invalid date.
Omit Record
Omit Record
Exit Loop If [ Get ( FoundCount) = 0 ]
End Loop
Close Window [ Current Window ]
Sort Records [ ]
[ No dialog ]
Perform Script [ “gotoOut” ]
Loop
Go to Record/Request/Page
[ Next; Exit after last ]
Exit Loop If [ out::_Lout = $recordDuplicate ]
End Loop
Perform Script [ “updatePurchaseHeaderCalc” ]
Go to Field [ ]
Set Variable [ $$stopMessage ]
January 8, 平成26 18:54:27 Budget Research.fp7 - duplicatePurchase -2-
