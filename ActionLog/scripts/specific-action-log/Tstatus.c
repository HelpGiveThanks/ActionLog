speciﬁc action log: Tstatus
If [ issueStatus::order > 79 ]
Set Variable [ $$stopgotoIssueResolution; Value:1 ]
Set Field [ issue::order; "" ]
End If
Go to Field [ ]
If [ issue::_keyCategory ≠ "" ]
Go to Field [ issue::dateDone ]
Set Field [ issue::dateDone; Get ( CurrentTimeStamp ) ]
Go to Field [ ]
End If
Set Variable [ $$stopgotoIssueResolution ]
#
#if over 90, do not take user to record when status is changed.
If [ issueStatus::order > 79 or $$stopSort ≠ "" ]
Halt Script
End If
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Scroll Window
[ To Selection ]
January 6, 平成26 11:21:29 ActionLog.fp7 - Tstatus -1-
