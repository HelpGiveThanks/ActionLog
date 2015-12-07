specific action log: deleteStatus
If [ status::_LockList = "" ]
Go to Field [ ]
Exit Script [ ]
End If
Set Variable [ $delete; Value:status::_LockList ]
Set Variable [ $name; Value:status::text ]
Go to Layout [ “IssuesAndObservations Copy” (issue) ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ issue::_keyStatus; $delete ]
Perform Find [ ]
Set Variable [ $error; Value:Get (LastError) ]
Go to Layout [ original layout ]
If [ $error ≠ 401 ]
Set Variable [ $delete ]
Show Custom Dialog [ Message: "'" & $name & "'" & " can be deleted once all Specific Actions tagged with it are switched to a different
status tag. NOTE: Status tags are global, so this tag may be applied to other Timer's Specific Actions not currently showing."; Buttons:
“OK” ]
Exit Script [ ]
End If
Refresh Window
Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
If [ Get ( LastMessageChoice ) = 2 ]
Delete Record/Request
[ No dialog ]
End If
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
December 6, ଘ౮27 21:12:21 ActionLog.fp7 - deleteStatus -1-
