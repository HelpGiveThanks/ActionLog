speciﬁc action log: deleteGroup
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Stop script if user is process of picking a speciﬁc action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a speciﬁc-action group. After you do this you can delete group tags. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
If [ Get (ActiveFieldContents) = "" ]
Show Custom Dialog [ Title: "!"; Message: "Select an item to delete."; Buttons: “OK” ]
Go to Field [ ]
Exit Script [ ]
End If
#
If [ category::_LockList = "" ]
Go to Field [ ]
Exit Script [ ]
End If
#
Set Variable [ $delete; Value:category::_LockList ]
Set Variable [ $name; Value:category::text ]
#
Go to Layout [ “IssuesAndObservations Copy” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $delete ]
Perform Find [ ]
#
Set Variable [ $error; Value:Get (LastError) ]
#
Go to Layout [ original layout ]
If [ $error ≠ 401 ]
Set Variable [ $delete ]
Show Custom Dialog [ Message: "'" & $name & "'" & " can be deleted once all issues tagged with it are switched to a different item tag in
the issues log window."; Buttons: “OK” ]
Exit Script [ ]
End If
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
January 6, 平成26 1:15:06 ActionLog.fp7 - deleteGroup -1-
