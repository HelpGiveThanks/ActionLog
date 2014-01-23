triggered scripts: xpLayout
#PURPOSE set the layout status ﬁeld with the layout that triggers this script when it loads
#
#
If [ Get ( SystemPlatform ) = -2 ]
Go to Layout [ “01SortAndScheduleXP” (brainstate) ]
Exit Script [ ]
End If
#
Go to Layout [ “01SortAndSchedule” (brainstate) ]
January 6, 平成26 1:04:03 ActionLog.fp7 - xpLayout -1-
