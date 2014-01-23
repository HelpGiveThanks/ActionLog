speciﬁc action log: LoadLogrecordID
If [ $$stopRecordLoad = 1 ]
Exit Script [ ]
Else If [ $$stoprecordload ≠ 1 ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Refresh Window
End If
#
#For attaching issue record IDs to log records, and
#for conditionally formatting log records related to an issue,
#system needs to know what IDs are associated with a log record.
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
Set Variable [ $$log; Value:logs::_lockDay ]
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
Go to Field [ ]
Refresh Window
Set Variable [ $$stopRecordLoad; Value:1 ]
Select Window [ Name: "Day"; Current ﬁle ]
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
Refresh Window
Set Variable [ $$stopRecordLoad ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
// Perform Script [ “viewLogIssues” ]
#
#A window showing set of all issues addressed on this
#needs to be show to the user in a new window.
January 6, 平成26 1:12:18 ActionLog.fp7 - LoadLogrecordID -1-
