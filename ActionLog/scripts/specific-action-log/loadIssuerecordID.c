specific action log: loadIssuerecordID
#
#Stop this script from slowing other scripts
#while they are working.
If [ $$stopRecordLoad = 1 ]
Exit Script [ ]
End If
#
#Set key variables.
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Variable [ $$group; Value:specificAction::_keyGroup ]
Set Variable [ $$status; Value:specificAction::_keyStatus ]
Set Field [ timer::pulldownTimer; specificAction::_keyTimer ]
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
#For attaching issue record IDs to log records,
#and for conditionally formatting log records
#related to an issue, system needs to know
#what IDs are associated with a log record.
Set Variable [ $$issue; Value:specificAction::_LockSpecificAction ]
Set Variable [ $$issueLogs; Value:specificAction::_keyLogs ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
#
#Select and highlight this specific-action
#record's group tag in the Tag window.
Set Variable [ $$stopGroup; Value:1 ]
Set Variable [ $$stopIssuePulldownMenus; Value:1 ]
Select Window [ Name: "Tag"; Current file ]
Scroll Window
[ Home ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ SPAGroupTag::_LockSpecificAction = $$group ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ SPAGroupTag::_LockSpecificAction ≠ $$group ]
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
#Return to Specific Action window so user can
#do what they need to do.
Select Window [ Name: "Specific Action"; Current file ]
Refresh Window
#
December 10, ଘ౮28 21:01:35 ActionLog.fp7 - loadIssuerecordID -1-
