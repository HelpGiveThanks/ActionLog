specific action log: viewLogIssues
#
#Prevent windows from flashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Clear tag find variables and go to category layout.
Select Window [ Name: "Tag"; Current file ]
Set Variable [ $$found ]
Set Variable [ $$foundStatus ]
Go to Layout [ “IssuesAndObservationsTag” (category) ]
#
#Find all issues linked to this day.
Select Window [ Name: "Specific Action"; Current file ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: 0 ]
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
Sort Records [ Specified Sort Order: brainstate::description; ascending
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
Perform Script [ “loadIssuerecordID” ]
Set Variable [ $$stopSubtotal; Value:1 ]
Perform Script [ “TsubtotalTimeByGroup (UPDATED)” ]
December 6, ଘ౮27 21:20:26 ActionLog.fp7 - viewLogIssues -1-
