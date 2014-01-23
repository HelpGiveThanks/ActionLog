speciﬁc action log: gotoIssueOrder
#
#If user clicked on the pulldown when the focus
#of the system was on another record, stop this
#script so user wont' get a useless ﬂash of the menu.
If [ $$pulldownCheck ≠ Get (RecordID) ]
Set Variable [ $$pulldownCheck; Value:Get (RecordID) ]
Go to Field [ ]
Exit Script [ ]
End If
Go to Object [ Object Name: "order" ]
// Go to Field [ issue::order ]
[ Select/perform ]
January 6, 平成26 11:23:06 ActionLog.fp7 - gotoIssueOrder -1-
