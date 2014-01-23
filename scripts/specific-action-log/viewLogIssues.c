speciﬁc action log: viewLogIssues
#
#Prevent windows from ﬂashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#If ﬁnd mode is active clear it.
If [ $$found ≠ "" ]
Select Window [ Name: "Tag"; Current ﬁle ]
Set Variable [ $$found ]
Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
End If
#
#Find all issues linked to this day.
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Speciﬁc Action"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: 0 ]
If [ Get ( WindowZoomLevel ) > 150 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
End If
End If
Go to Layout [ “Issues” (issue) ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
Enter Find Mode [ ]
Set Field [ issue::_keyLogs; $$log ]
Perform Find [ ]
If [ Get (FoundCount) = 0 ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
End If
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
Scroll Window
[ Home ]
Set Variable [ $$issueSort; Value:"status" ]
Go to Record/Request/Page
[ First ]
Set Variable [ $$stopRecordLoad ]
Perform Script [ “LoadIssuerecordID” ]
Set Variable [ $$stopSubtotal; Value:1 ]
Perform Script [ “TsubtotalTimeByGroup” ]
January 6, 平成26 1:17:12 ActionLog.fp7 - viewLogIssues -1-
