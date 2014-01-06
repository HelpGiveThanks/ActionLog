Sorts: issueSortDate
If [ $$issueSort = "date" ]
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issue::date; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Set Variable [ $$issueSort; Value:"date" ]
Exit Script [ ]
End If
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issue::date; descending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Set Variable [ $$issueSort; Value:"etad" ]
January 6, 平成26 0:59:31 ActionLog.fp7 - issueSortDate -1-
