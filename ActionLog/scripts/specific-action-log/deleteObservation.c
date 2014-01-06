speciﬁc action log: deleteObservation
Set Variable [ $row; Value:Get ( PortalRowNumber ) ]
Go to Field [ ]
Go to Portal Row [ $row ]
[ Select; No dialog ]
Set Variable [ $delete; Value:observation::_LockList ]
Set Variable [ $name; Value:observation::text ]
Refresh Window
Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
If [ Get ( LastMessageChoice ) = 2 ]
Delete Portal Row
[ No dialog ]
End If
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
January 6, 平成26 11:25:39 ActionLog.fp7 - deleteObservation -1-
