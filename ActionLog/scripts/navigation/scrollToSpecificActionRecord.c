navigation: scrollToSpecificActionRecord
#
If [ $$scrollTop ≠ 1 ]
Set Variable [ $$scrollTop; Value:1 ]
Else
Set Variable [ $$scrollTop ]
Scroll Window
[ Home ]
Exit Script [ ]
End If
#
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
Set Variable [ $$stopRecordLoad; Value:1 ]
#
Go to Record/Request/Page
[ Next ]
If [ Get ( LastError ) = 0 ]
Go to Record/Request/Page
[ Previous ]
End If
#
Set Variable [ $$stopRecordLoad ]
#
July 26, ଘ౮28 15:57:23 ActionLog.fp7 - scrollToSpecificActionRecord -1-
