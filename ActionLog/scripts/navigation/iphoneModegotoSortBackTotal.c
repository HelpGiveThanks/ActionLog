navigation: iphoneModegotoSortBackTotal
If [ steward::iPhoneLayout ≠ "" ]
Set Field [ steward::windowSizeAndPlace; Get ( WindowHeight ) ]
Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowWidth ) ]
Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowTop ) ]
Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowLeft ) ]
Go to Layout [ $$iPhoneLayout ]
Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [5]; Width: steward::windowSizeAndPlace [6]; Top:
steward::windowSizeAndPlace [7]; Left: steward::windowSizeAndPlace [8] ]
Exit Script [ ]
End If
Go to Layout [ “TotalMain” (brainstate) ]
January 5, 平成26 19:09:02 ActionLog.fp7 - iphoneModegotoSortBackTotal -1-
