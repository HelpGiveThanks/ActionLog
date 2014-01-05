start close: close
#PURPOSE save out graphic objects to external folder for reference in graphs and then go to the user layout
#
#
#
// #2 ﬂag/unﬂag active stopwatch ﬁeld for conditional formatting on main screen if current screen is total layout
// If [ Left ( Get ( LayoutName ) ; 5 ) = "total" or Left ( Get ( LayoutName ) ; 5 ) = "grand" ]
// Perform Script [ “FolderStopwatchCheck” ]
// End If
#
#1 set the layout status ﬁeld
// If [ Get ( SystemPlatform ) ≠ 3 and steward::iPhoneLayout = "" ]
// Set Field [ steward::windowSizeAndPlace; Get ( WindowHeight ) ]
// Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowWidth ) ]
// Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowTop ) ]
// Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowLeft ) ]
// Exit Script [ ]
// End If
// Set Field [ steward::windowSizeAndPlace[5]; Get ( WindowHeight ) ]
// Set Field [ steward::windowSizeAndPlace[6]; Get ( WindowWidth ) ]
// Set Field [ steward::windowSizeAndPlace[7]; Get ( WindowTop ) ]
// Set Field [ steward::windowSizeAndPlace[8]; Get ( WindowLeft ) ]
January 5, 平成26 13:19:45 ActionLog.fp7 - close -1-
