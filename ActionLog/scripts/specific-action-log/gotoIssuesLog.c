speciﬁc action log: gotoIssuesLog
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Speciﬁc Action" ]
If [ Get ( WindowZoomLevel ) > 150 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
Else If [ Get ( WindowZoomLevel ) = 150 ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Width: 441; Left: 0 ]
End If
Go to Layout [ “Issues” (issue) ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logbrainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$issue; Value:issue::_LockList ]
Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
Refresh Window
End If
January 6, 平成26 11:07:41 ActionLog.fp7 - gotoIssuesLog -1-
