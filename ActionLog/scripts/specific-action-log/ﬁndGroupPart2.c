speciﬁc action log: ﬁndGroupPart2
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Make key to ﬁt this group's lock.
Set Variable [ $$group; Value:category::_LockList ]
Go to Field [ ]
If [ FilterValues ( $$found ; $$group ) = $$group & ¶ ]
#
#Find all speciﬁc actions with this key.
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Go to Record/Request/Page
[ First ]
Loop
If [ issue::_keyCategory = $$group ]
Omit Record
Else
Go to Record/Request/Page
[ Next; Exit after last ]
End If
End Loop
Set Variable [ $$found; Value:Substitute ( $$found ; $$group & ¶ ; "" ) ]
Set Variable [ $$stopRecordLoad ]
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Else
#
#Find all speciﬁc actions with this key.
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $$group ]
Extend Found Set [ ]
If [ Get (LastError) ≠ 401 ]
Set Variable [ $$found; Value:$$group & ¶ & $$found ]
Else
Show Custom Dialog [ Message: "There are no speciﬁc actions tagged as part of this group."; Buttons: “OK” ]
End If
Set Variable [ $$stopRecordLoad ]
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
End If
Perform Script [ “LoadIssuerecordID” ]
#
#If user selected the same category that was already
#selected then stop this script.
Select Window [ Name: "Tag"; Current ﬁle ]
January 6, 平成26 11:22:34 ActionLog.fp7 - ﬁndGroupPart2 -1-speciﬁc action log: ﬁndGroupPart2
Refresh Window
#
// #Find all speciﬁc actions with this key.
// Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
January 6, 平成26 11:22:34 ActionLog.fp7 - ﬁndGroupPart2 -2-
