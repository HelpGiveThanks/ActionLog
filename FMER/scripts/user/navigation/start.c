user: navigation: start
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Checked if opened by user or by backup script.
Paste [ ]
[ Select ]
If [ ]
End If
#
#current record, if any.
Set Window Title [ Current Window; New Title: "Fat and Muscle Efﬁciency Research" ]
Show/Hide Text Ruler
[ Hide ]
Show/Hide Status Area
[ Lock; Hide ]
Go to Record/Request/Page
[ First ]
Perform Script [ “loadUser” ]
#
#
#Show regular menus if Admin logs in only.
Show/Hide Text Ruler
[ Hide ]
If [ Get ( AccountName ) = "Admin" ]
Show/Hide Status Area
[ Hide ]
Install Menu Set [ “[Standard FileMaker Menus]” ]
Else
Show/Hide Status Area
[ Lock; Hide ]
End If
#
#Report version number to Memory Switch Table.
Set Field [ MemorySwitch::versionFMER; Icons01::version ]
January 8, 平成26 12:08:17 Fat and Muscle Efﬁciency Research.fp7 - start -1-
