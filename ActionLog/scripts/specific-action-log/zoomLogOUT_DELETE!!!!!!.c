speciﬁc action log: zoomLogOUT_DELETE!!!!!!
Select Window [ Name: "Tag"; Current ﬁle ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Tag"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: Get (ScreenWidth) - 441 ]
Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
End If
If [ Get ( WindowZoomLevel ) = 400 ]
Move/Resize Window [ Current Window; Width: 830; Left: If (Get (ScreenWidth) / 2 + 830 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get
(ScreenWidth) - 830 ) ]
Set Zoom Level
[ 300% ]
Else If [ Get ( WindowZoomLevel ) = 300 ]
Set Zoom Level
[ 200% ]
Move/Resize Window [ Current Window; Width: 550; Left: If (Get (ScreenWidth) / 2 + 550 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get
(ScreenWidth) - 550 ) ]
Else If [ Get ( WindowZoomLevel ) = 200 ]
Move/Resize Window [ Current Window; Width: 441; Left: If (Get (ScreenWidth) ≥ 441 + 608 + 441; 441 + 608 ; Get (ScreenWidth) -
441 ) ]
Set Zoom Level
[ 150% ]
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
If [ Get ( WindowZoomLevel ) = 400 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
Set Zoom Level
[ 300% ]
Else If [ Get ( WindowZoomLevel ) = 300 ]
Set Zoom Level
[ 200% ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
Else If [ Get ( WindowZoomLevel ) = 200 ]
Move/Resize Window [ Current Window; Width: 441; Left: 0 ]
Set Zoom Level
[ 150% ]
January 6, 平成26 11:10:11 ActionLog.fp7 - zoomLogOUT_DELETE!!!!!! -1-speciﬁc action log: zoomLogOUT_DELETE!!!!!!
End If
Select Window [ Name: "Day"; Current ﬁle ]
If [ Get ( WindowZoomLevel ) = 400 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
Set Zoom Level
[ 300% ]
Else If [ Get ( WindowZoomLevel ) = 300 ]
Set Zoom Level
[ 200% ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
Else If [ Get ( WindowZoomLevel ) = 200 ]
Move/Resize Window [ Current Window; Width: 608; Left: 441 ]
Set Zoom Level
[ 150% ]
End If
January 6, 平成26 11:10:11 ActionLog.fp7 - zoomLogOUT_DELETE!!!!!! -2-
