speciﬁc action log: deletePreﬁx
Set Variable [ $delete; Value:preﬁx::_LockList ]
Set Variable [ $name; Value:preﬁx::text ]
Go to Object [ Object Name: 5 ]
Refresh Window
Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
If [ Get ( LastMessageChoice ) = 2 ]
Delete Record/Request
[ No dialog ]
End If
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
January 6, 平成26 1:14:00 ActionLog.fp7 - deletePreﬁx -1-
