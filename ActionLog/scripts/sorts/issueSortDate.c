sorts: issueSortDate
If [ $$issueSort = "date" ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
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
Show Custom Dialog [ Message: "Sort by date created or modified?"; Buttons: “created”, “modified” ]
If [ Get ( LastMessageChoice ) = 1 ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issue::date; descending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Else
Sort Records [ Specified Sort Order: brainstate::description; ascending
issue::DisplayDateDone; descending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
End If
Set Variable [ $$issueSort; Value:"etad" ]
December 6, ଘ౮27 21:00:26 ActionLog.fp7 - issueSortDate -1-
