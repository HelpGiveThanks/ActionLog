speciﬁc action log: TsubtotalTimeByGroupForStatus
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop script if user is process of picking a speciﬁc action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a speciﬁc-action group. After you do this you can assign other tags. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
If [ Get (WindowName) = "Tag" ]
#Make key to ﬁt this group's lock.
Set Variable [ $$status; Value:status::_LockList ]
Go to Field [ ]
Refresh Window
#
#Give key to current speciﬁc action.
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
Set Field [ issue::_keyStatus; $$status ]
End If
#
// Perform Script [ “issueSortStatus” ]
Perform Script [ “Tstatus” ]
Perform Script [ “TsubtotalTimeByGroup” ]
January 6, 平成26 11:20:23 ActionLog.fp7 - TsubtotalTimeByGroupForStatus -1-
