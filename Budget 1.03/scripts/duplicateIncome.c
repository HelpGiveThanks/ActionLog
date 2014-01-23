duplicateIncome
Allow User Abort [ Off ]
Set Error Capture [ On ]
Set Variable [ $record; Value:in::_Lin ]
Set Variable [ $date; Value:in::date ]
New Window [ ]
New Record/Request
Set Variable [ $recordDuplicate; Value:in::_Lin ]
Delete Record/Request
[ No dialog ]
Enter Find Mode [ ]
Set Field [ in::_Lin; $record ]
Perform Find [ ]
Duplicate Record/Request
Set Field [ in::_Lin; $recordDuplicate ]
Set Field [ in::date; Case ( Month ( $date ) + 1 = 13 ;
1 & "/" & 1 & "/" & Year ( $date ) + 1 ;
( Month ( $date ) + 1 ) & "/" & 1 & "/" & Year ( $date ) ) ]
Close Window [ Current Window ]
Show All Records
Sort Records [ ]
[ No dialog ]
Loop
Go to Record/Request/Page
[ Next; Exit after last ]
Exit Loop If [ out::_Lout = $recordDuplicate ]
End Loop
Perform Script [ “updateIncomeHeaderCalc” ]
Go to Field [ ]
January 8, 平成26 18:54:56 Budget Research.fp7 - duplicateIncome -1-
