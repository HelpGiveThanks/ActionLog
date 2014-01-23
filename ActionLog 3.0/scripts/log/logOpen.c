log: logOpen
Set Variable [ $$loglayout; Value:Get ( LayoutName ) ]
Go to Layout [ “LogHome” (brainstate) ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 ]
Go to Layout [ “logHomeiPhone” (brainstate) ]
End If
January 5, 平成26 19:30:53 ActionLog.fp7 - logOpen -1-
