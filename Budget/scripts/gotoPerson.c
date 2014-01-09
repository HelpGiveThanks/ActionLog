gotoPerson
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $$outLayout; Value:Get (LayoutName) ]
Set Field [ budget::outLayoutGlobal; Get (LayoutName) ]
Go to Layout [ “people” (person) ]
Enter Find Mode [ ]
Set Field [ person::kbudget; budget::budgetGlobal ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: person::person; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
January 8, 平成26 18:49:33 Budget Research.fp7 - gotoPerson -1-
