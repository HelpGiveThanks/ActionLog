triggered scripts: layoutStatus
#PURPOSE set the layout status field with the layout that triggers this script when it loads
#
#
If [ Get (LayoutName) = $$loglayout or $$otherApps = 1 or $$specificActionTimer = 1 or $$newTimer = 1 ]
Exit Script [ ]
End If
#
#1 set the layout status field
Set Field [ steward::chosenLayout; Get ( LayoutName ) ]
#
#2 set the layout variable (I think I created this and then didn't end up using it, I think. I can't find it being used in any scripts, but due to
paranoia I'm leaving it here. I'm just to tired at this point to look for it.)
Set Variable [ $$layout; Value:Get ( LayoutName ) ]
#
Set Field [ steward::windowSizeAndPlace; Get ( WindowHeight ) ]
Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowWidth ) ]
Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowTop ) ]
Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowLeft ) ]
Set Field [ steward::windowZoom; Get ( WindowZoomLevel ) ]
August 13, 平成27 16:51:48 ActionLog.fp7 - layoutStatus -1-
