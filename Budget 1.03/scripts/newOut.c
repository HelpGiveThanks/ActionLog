newOut
New Record/Request
Go to Layout [ “PurchaseTotals4” (out) ]
Set Field [ out::purchaseLayoutView; "less" & Get (LayoutName) ]
Set Field [ out::kbudget; budget::budgetGlobal ]
Sort Records [ Speciﬁed Sort Order: out::_Lyear; ascending
out::_Lmonth; ascending
person::person; ascending ]
[ Restore; No dialog ]
January 8, 平成26 18:50:41 Budget Research.fp7 - newOut -1-
