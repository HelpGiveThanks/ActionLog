triggered scripts: layoutExit
#PURPOSE set the layout status ﬁeld with the layout that triggers this script when it loads
#
#
#
#1 set the layout status ﬁeld
Set Field [ steward::windowSizeAndPlace; Get ( WindowWidth ) ]
Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowHeight ) ]
Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowLeft ) ]
Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowTop ) ]
#
#2 set the layout variable (I think I created this and then didn't end up using it, I think. I can't ﬁnd it being used in any scripts, but due to paranoia
I'm leaving it here. I'm just to tired at this point to look for it.)
January 6, 平成26 1:03:32 ActionLog.fp7 - layoutExit -1-
