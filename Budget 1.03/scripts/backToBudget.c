backToBudget
#
If [ Get (LayoutTableName) = "in" ]
Set Field [ budget::inLayoutGlobal; Get (LayoutName) ]
Else If [ Get (LayoutTableName) = "out" ]
Set Field [ budget::outLayoutGlobal; Get (LayoutName) ]
End If
#
Go to Layout [ “budget” (budget) ]
Show All Records
Sort Records [ Speciﬁed Sort Order: budget::name; ascending ]
[ Restore; No dialog ]
January 8, 平成26 18:59:50 Budget Research.fp7 - backToBudget -1-
