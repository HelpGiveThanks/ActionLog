specific action log: tagSort
#
#Sort records and save sort state for future visits.
If [ Get (LayoutName) = "IssuesAndObservationsTag" or Get (LayoutName) = "IssuesAndObservationsFIND" ]
If [ reference::tagCatSort = "abc" ]
Set Field [ reference::tagCatSort; "group" ]
Sort Records [ Specified Sort Order: group::order; based on value list: “1-99”
group::text; ascending
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
January 3, ଘ౮28 20:19:48 ActionLog.fp7 - tagSort -1-
