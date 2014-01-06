Sorts: issueSortOrderNumber
// If [ $$issueSort = "status" ]
// Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issueStatus::order; descending
issueStatus::text; descending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
// Set Variable [ $$issueSort; Value:"sutats" ]
// Exit Script [ ]
// End If
If [ Get ( FoundCount ) = 0 ]
Set Variable [ $$issueSort; Value:"order" ]
Refresh Window
Exit Script [ ]
End If
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issue::order; based on value list: “1-99”
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::text; ascending ]
[ Restore; No dialog ]
Set Variable [ $$issueSort; Value:"order" ]
Set Variable [ $$stopSubtotal; Value:1 ]
Perform Script [ “TsubtotalTimeByOrder” ]
January 6, 平成26 0:58:55 ActionLog.fp7 - issueSortOrderNumber -1-
