changePerson
Allow User Abort [ Off ]
Set Error Capture [ On ]
Set Variable [ $record; Value:out::_Lout ]
Set Variable [ $person; Value:out::kperson ]
New Window [ ]
Go to Layout [ “purchases” (Art) ]
Enter Find Mode [ ]
Set Field [ Art::kout; $record ]
Perform Find [ ]
Go to Record/Request/Page
[ First ]
Loop
Set Field [ Art::kperson; $person ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Close Window [ Current Window ]
Sort Records [ ]
[ No dialog ]
January 8, 平成26 19:11:00 Budget Research.fp7 - changePerson -1-
