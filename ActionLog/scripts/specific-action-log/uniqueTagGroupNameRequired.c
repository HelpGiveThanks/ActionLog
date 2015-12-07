specific action log: uniqueTagGroupNameRequired
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
// If [ category::_LockList = "" ]
// Go to Field [ ]
// Exit Script [ ]
// End If
#
Set Variable [ $brainstate; Value:brainstate::_lockBrainstateID ]
Set Variable [ $name; Value:group::text ]
Go to Field [ ]
#
New Window [ ]
Go to Layout [ “IssuesAndObservationsTagUniqueNameCheck” (group) ]
Enter Find Mode [ ]
Set Field [ group::_keyBrainstate; $brainstate ]
Set Field [ group::lock; "group" ]
Set Field [ group::text; "==" & $name ]
Perform Find [ ]
#
Set Variable [ $found; Value:Get (FoundCount) ]
#
If [ $found ≠ 1 ]
Close Window [ Current Window ]
Set Field [ group::text; $name & group::_LockList ]
Show Custom Dialog [ Message: "All tag names must be unique, and must not be blank."; Buttons: “OK” ]
Exit Script [ ]
End If
Close Window [ Current Window ]
Exit Script [ ]
#
Refresh Window
Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
#
If [ Get ( LastMessageChoice ) = 2 ]
Go to Layout [ “menuGroups” (issueCategory) ]
Enter Find Mode [ ]
Set Field [ issueCategory::_LockList; $delete ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ original layout ]
End If
#
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
December 6, ଘ౮27 21:47:50 ActionLog.fp7 - uniqueTagGroupNameRequired -1-
