specific action log: uniqueTagGroupNameRequired
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
// If [ SPAGroupTag::_LockSpecificAction = "" ]
// Go to Field [ ]
// Exit Script [ ]
// End If
#
Set Variable [ $brainstate; Value:timer::_lockTimer ]
Set Variable [ $name; Value:TagGroup::text ]
Go to Field [ ]
#
New Window [ ]
Go to Layout [ “IssuesAndObservationsTagUniqueNameCheck” (TagGroup) ]
Enter Find Mode [ ]
Set Field [ TagGroup::_keyTimer; $brainstate ]
Set Field [ TagGroup::lock; "group" ]
Set Field [ TagGroup::text; "==" & $name ]
Perform Find [ ]
#
Set Variable [ $found; Value:Get (FoundCount) ]
#
If [ $found ≠ 1 ]
Close Window [ Current Window ]
Set Field [ TagGroup::text; $name & "_" & TagGroup::_LockSpecificAction ]
Show Custom Dialog [ Message: "All tag-group names must be unique, and cannot be blank."; Buttons: “OK” ]
Exit Script [ ]
End If
Close Window [ Current Window ]
Exit Script [ ]
#
Refresh Window
Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
#
If [ Get ( LastMessageChoice ) = 2 ]
Go to Layout [ “menuGroups” (SPAGroupTag 2) ]
Enter Find Mode [ ]
Set Field [ SPAGroupTag 2::_LockSpecificAction; $delete ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ original layout ]
End If
#
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
December 10, ଘ౮28 23:15:48 ActionLog.fp7 - uniqueTagGroupNameRequired -1-
