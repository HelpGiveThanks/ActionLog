speciﬁc action log: ActivityLog!!!!ﬁndAllBrainstateLogs
Set Variable [ $$stopRecordLoad; Value:1 ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $$LogBrainstate ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: logs::_keyBrainstate; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
Set Variable [ $$stopRecordLoad ]
Go to Record/Request/Page
[ First ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
Set Variable [ $$log; Value:logs::_lockDay ]
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
Refresh Window
Scroll Window
[ Home ]
// Perform Script [ “viewAllLogIssues” ]
January 6, 平成26 11:05:44 ActionLog.fp7 - ActivityLog!!!!ﬁndAllBrainstateLogs -1-
