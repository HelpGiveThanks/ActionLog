specific action log: deleteStatus
Set Variable [ $row; Value:Get ( PortalRowNumber ) ]
If [ status::_LockList = "" ]
Go to Field [ ]
Exit Script [ ]
End If
If [ Get (ActiveFieldContents) = "" ]
Show Custom Dialog [ Title: "!"; Message: "Select an item to delete."; Buttons: “OK” ]
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
Show Custom Dialog [ Message: "'" & $name & "'" & " can be deleted once all issues tagged with it are switched to a different status tag
in the issues log window. NOTE: Status tags are global, so this tag may be applied to other action's issues not currently showing.";
Buttons: “OK” ]
Exit Script [ ]
End If
Refresh Window
Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
If [ Get ( LastMessageChoice ) = 2 ]
Go to Field [ status::_LockList ]
Go to Portal Row [ $row ]
[ Select; No dialog ]
Delete Portal Row
[ No dialog ]
End If
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
January 6, 平成26 1:14:34 ActionLog.fp7 - deleteStatus -1-
