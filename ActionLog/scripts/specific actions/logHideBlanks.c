log: logHideBlanks
#PURPOSE open log window and select log entry for current record, but if that record has no time entry the show the calendar log view for that
record
#
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: logs::log: “=” ]
[ Restore ]
#1 capture layout name for the return trip
If [ Get ( LastError ) = 401 ]
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
If [ Left ( $$iphoneLog; 8 ) = "TotalLog" ]
Go to Layout [ “TotalLogEditTimeiPhone” (brainstate) ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Scroll Window
[ Home ]
Set Variable [ $$iphoneLog; Value:"" ]
Show Custom Dialog [ Title: "!"; Message: "All log entries are blank."; Buttons: “OK” ]
Halt Script
End If
Go to Layout [ “LogEditTimeiPhone” (brainstate) ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Scroll Window
[ Home ]
Show Custom Dialog [ Title: "!"; Message: "All log entries are blank."; Buttons: “OK” ]
Halt Script
End If
Go to Layout [ $$loglayout ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Scroll Window
[ Home ]
Show Custom Dialog [ Title: "!"; Message: "All log entries are blank."; Buttons: “OK” ]
Halt Script
End If
January 5, 平成26 19:33:03 ActionLog.fp7 - logHideBlanks -1-
