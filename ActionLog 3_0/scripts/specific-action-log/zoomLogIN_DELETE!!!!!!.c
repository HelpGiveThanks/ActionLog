speciﬁc action log: zoomLogIN_DELETE!!!!!!
Select Window [ Name: "Tag"; Current ﬁle ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Tag"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: Get (ScreenWidth) - 441 ]
Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
End If
If [ Get ( WindowZoomLevel ) = 150 ]
Set Zoom Level
[ 200% ]
Move/Resize Window [ Current Window; Width: 550; Left: If (Get (ScreenWidth) / 2 + 550 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get
(ScreenWidth) - 550 ) ]
Else If [ Get ( WindowZoomLevel ) = 200 ]
Move/Resize Window [ Current Window; Width: 830; Left: If (Get (ScreenWidth) / 2 + 830 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get
(ScreenWidth) - 830 ) ]
Set Zoom Level
[ 300% ]
Else If [ Get ( WindowZoomLevel ) = 300 ]
Move/Resize Window [ Current Window; Width: 1100; Left: If (Get (ScreenWidth) / 2 + 1100 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ;
Get (ScreenWidth) - 1100 ) ]
Set Zoom Level
[ 400% ]
End If
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Speciﬁc Action"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: 0 ]
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
If [ Get ( WindowZoomLevel ) = 150 ]
Set Zoom Level
[ 200% ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
Else If [ Get ( WindowZoomLevel ) = 200 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
Set Zoom Level
[ 300% ]
Else If [ Get ( WindowZoomLevel ) = 300 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
Set Zoom Level
[ 400% ]
January 6, 平成26 11:08:59 ActionLog.fp7 - zoomLogIN_DELETE!!!!!! -1-speciﬁc action log: zoomLogIN_DELETE!!!!!!
End If
Select Window [ Name: "Day"; Current ﬁle ]
If [ Get ( WindowZoomLevel ) = 150 ]
Set Zoom Level
[ 200% ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
Else If [ Get ( WindowZoomLevel ) = 200 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
Set Zoom Level
[ 300% ]
Else If [ Get ( WindowZoomLevel ) = 300 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
Set Zoom Level
[ 400% ]
End If
January 6, 平成26 11:08:59 ActionLog.fp7 - zoomLogIN_DELETE!!!!!! -2-
