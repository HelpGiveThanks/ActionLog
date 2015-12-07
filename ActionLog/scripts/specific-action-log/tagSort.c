specific action log: tagSort
#
#Sort records and save sort state for future visits.
If [ Get (LayoutName) = "IssuesAndObservationsTag" or Get (LayoutName) = "IssuesAndObservationsFIND" ]
If [ reference::tagCatSort = "abc" ]
Set Field [ reference::tagCatSort; "group" ]
Sort Records [ Specified Sort Order: group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
Else
Set Field [ reference::tagCatSort; "abc" ]
Sort Records [ Specified Sort Order: category::text; ascending
category::sortTime; ascending ]
[ Restore; No dialog ]
End If
End If
December 6, ଘ౮27 21:59:12 ActionLog.fp7 - tagSort -1-
