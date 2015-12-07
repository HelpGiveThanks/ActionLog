specific action log: TsubtotalTimeByGroupForStatus
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can assign other tags. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
If [ Get (WindowName) = "Tag" ]
#Make key to fit this group's lock.
Set Variable [ $$status; Value:status::_LockList ]
Go to Field [ ]
Refresh Window
#
#Give key to current specific action.
Select Window [ Name: "Specific Action"; Current file ]
Set Field [ issue::_keyStatus; $$status ]
End If
#
// Perform Script [ “issueSortStatus” ]
Perform Script [ “Tstatus” ]
// Perform Script [ “TsubtotalTimeByGroup” ]
Select Window [ Name: "Tag"; Current file ]
December 6, ଘ౮27 21:31:55 ActionLog.fp7 - TsubtotalTimeByGroupForStatus -1-
