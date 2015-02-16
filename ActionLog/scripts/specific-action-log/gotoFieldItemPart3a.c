specific action log: gotoFieldItemPart3a
#
#If user clicked on the pulldown when the focus
#of the system was on another record, stop this
#script so user wont' get a useless ﬂash of the menu.
If [ $$pulldownCheck ≠ Get (RecordID) ]
Set Variable [ $$pulldownCheck; Value:Get (RecordID) ]
Go to Field [ ]
Exit Script [ ]
End If
Go to Object [ Object Name: 2 ]
// Go to Field [ issue::_keyCategory ]
[ Select/perform ]
January 6, 平成26 11:23:34 ActionLog.fp7 - gotoFieldItemPart3a -1-
