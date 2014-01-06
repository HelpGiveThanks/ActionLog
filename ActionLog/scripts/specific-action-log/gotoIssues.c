speciﬁc action log: gotoIssues
Set Variable [ $brainstate; Value:brainstate::_lockBrainstateID ]
New Window [ ]
Go to Layout [ “Issues” (issue) ]
Sort Records [ Speciﬁed Sort Order: issue::_keyBrainstate; ascending
issue::_keyStatus; ascending
issueCategory::text; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $brainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
If [ Get ( LastError ) = 401 ]
New Record/Request
Set Field [ issue::_keyBrainstate; $brainstate ]
Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
Set Field [ issue::lock; "issue" ]
Set Field [ issue::text; "issue" ]
Go to Field [ ]
Go to Field [ issue::text ]
End If
January 6, 平成26 11:24:06 ActionLog.fp7 - gotoIssues -1-
