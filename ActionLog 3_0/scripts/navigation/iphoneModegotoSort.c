navigation: iphoneModegotoSort
Set Variable [ $$iPhoneLayout; Value:Get ( LayoutName ) ]
Set Field [ steward::windowSizeAndPlace[5]; Get ( WindowHeight ) ]
Set Field [ steward::windowSizeAndPlace[6]; Get ( WindowWidth ) ]
Set Field [ steward::windowSizeAndPlace[7]; Get ( WindowTop ) ]
Set Field [ steward::windowSizeAndPlace[8]; Get ( WindowLeft ) ]
Go to Layout [ “01SortAndSchedule” (brainstate) ]
Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [1]; Width: steward::windowSizeAndPlace [2]; Top: steward::
windowSizeAndPlace [3]; Left: steward::windowSizeAndPlace [4] ]
// Adjust Window
[ Maximize ]
January 5, 平成26 19:07:12 ActionLog.fp7 - iphoneModegotoSort -1-
