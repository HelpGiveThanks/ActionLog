Sorts: issueSortStatus
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
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Set Variable [ $$issueSort; Value:"status" ]
Set Variable [ $$stopSubtotal; Value:1 ]
Perform Script [ “TsubtotalTimeByGroup” ]
January 6, 平成26 0:58:24 ActionLog.fp7 - issueSortStatus -1-
