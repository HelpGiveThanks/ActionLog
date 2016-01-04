specific action log: loadIssuerecordID
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
#flashing and going away. It needs to be reset
#when the user navigates to the record other than
#by click on the pulldown menus so the user
#doesn't get bumped out of the menu field
#if the database is focused on the record whose
#menus the user is trying to access.
Set Variable [ $$pulldownCheck; Value:Get (RecordID) ]
#
#disabled go to field takes a user view out of a
#a the text field if they entered it to go to this
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
Select Window [ Name: "Tag"; Current file ]
Scroll Window
[ Home ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ category::_LockList = $$group ]
Go to Record/Request/Page
[ Next; Exit after last ]
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
#
#Make sure date button in Specific Action
#window has the date of the Day window's
#active record.
Select Window [ Name: "Day"; Current file ]
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
Refresh Window
#
Select Window [ Name: "Specific Action"; Current file ]
Refresh Window
January 4, ଘ౮28 3:29:20 ActionLog.fp7 - loadIssuerecordID -1-
