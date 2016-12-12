specific action log: deleteStatus
#
#Prevent the default status being deleted. It's
#record has a unique ID number that is
#assigned to the first Specific Action record
#created when none exist by either the
#openSpecificAction script or the
#gotoSpecificAction script.
If [ status::_LockSpecificAction = "7152011154818554" ]
Set Variable [ $delete; Value:status::_LockSpecificAction ]
Refresh Window
Show Custom Dialog [ Message: "This is the default status record. You may change its name, but you cannot delete it."; Buttons:
“OK” ]
Set Variable [ $delete ]
Refresh Window
Exit Script [ ]
End If
#
#Prevent deletion of any in use status records.
If [ status::_LockSpecificAction = "" ]
Go to Field [ ]
Exit Script [ ]
End If
Set Variable [ $delete; Value:status::_LockSpecificAction ]
Set Variable [ $name; Value:status::text ]
Go to Layout [ “IssuesAndObservations Copy” (specificAction) ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ specificAction::_keyStatus; $delete ]
Perform Find [ ]
Set Variable [ $error; Value:Get (LastError) ]
Go to Layout [ original layout ]
If [ $error ≠ 401 ]
Set Variable [ $delete ]
Show Custom Dialog [ Message: "'" & $name & "'" & " can be deleted once all Specific Actions tagged with it are switched to a
different status tag. NOTE: Status tags are global, so this tag may be applied to other Timer's Specific Actions not currently
showing."; Buttons: “OK” ]
Exit Script [ ]
End If
Refresh Window
#
#If not in use then delete status record.
Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
If [ Get ( LastMessageChoice ) = 2 ]
Delete Record/Request
[ No dialog ]
End If
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
December 11, ଘ౮28 14:49:35 ActionLog.fp7 - deleteStatus -1-
