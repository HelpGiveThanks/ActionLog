speciﬁc action log: LoadIssuerecordID
If [ $$stopRecordLoad = 1 ]
Exit Script [ ]
End If
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$group; Value:issue::_keyCategory ]
Set Variable [ $$status; Value:issue::_keyStatus ]
Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
Go to Field [ ]
#
#If user clicked on the pulldown when the focus
#of the system was on another record, this
#variable prevents the pulldown menu from
#ﬂashing and going away. It needs to be reset
#when the user navigates to the record other than
#by click on the pulldown menus so the user
#doesn't get bumped out of the menu ﬁeld
#if the database is focused on the record whose
#menus the user is trying to access.
Set Variable [ $$pulldownCheck; Value:Get (RecordID) ]
#
#disabled go to ﬁeld takes a user view out of a
#a the text ﬁeld if they entered it to go to this
#record, which I don't like as a user, so it is off.
// Go to Field [ ]
Set Variable [ $$stopIssuePulldownMenus; Value:1 ]
Refresh Window
#
#For attaching issue record IDs to log records, and
#for conditionally formatting log records related to an issue,
#system needs to know what IDs are associated with a log record.
Set Variable [ $$issue; Value:issue::_LockList ]
Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
Set Variable [ $$stopGroup; Value:1 ]
Select Window [ Name: "Tag"; Current ﬁle ]
Go to Object [ Object Name: "group" ]
Scroll Window
[ Home ]
Go to Portal Row
[ Last ]
Loop
Exit Loop If [ category::_LockList = $$group ]
Go to Portal Row
[ Previous; Exit after last ]
End Loop
If [ category::_LockList ≠ $$group ]
Scroll Window
[ Home ]
Go to Record/Request/Page
[ First ]
End If
Go to Field [ ]
Set Variable [ $$stopGroup ]
Refresh Window
Select Window [ Name: "Day"; Current ﬁle ]
Refresh Window
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
Refresh Window
January 6, 平成26 1:09:44 ActionLog.fp7 - LoadIssuerecordID -1-
