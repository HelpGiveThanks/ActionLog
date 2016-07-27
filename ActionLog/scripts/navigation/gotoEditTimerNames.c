navigation: gotoEditTimerNames
#
Set Variable [ $$EditTimerNamesReturnLayout; Value:Get (LayoutName) ]
#
If [ Get (SystemPlatform) = 3 ]
Go to Layout [ “01SortAndScheduleiPhone” (brainstate) ]
Else
Go to Layout [ “01SortAndSchedule” (brainstate) ]
End If
#
#Conditionally formatt timer's light blue and tan.
Set Field [ steward::chosenSort; "rebmun" ]
#
Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
July 26, ଘ౮28 15:54:54 ActionLog.fp7 - gotoEditTimerNames -1-
