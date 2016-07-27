navigation: editTimePart1
#
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Set Field [ steward::chosenLayoutMain; steward::chosenSort ]
#
#Toggle the retired status field.
If [ steward::retiredStatus = "" ]
Perform Script [ “retireButton” ]
End If
#
#Go to correct layout.
If [ $$EditTimerNamesReturnLayout ≠ "" ]
Go to Layout [ $$EditTimerNamesReturnLayout ]
Set Variable [ $$EditTimerNamesReturnLayout ]
Else
#
If [ Get (SystemPlatform) ≠ 3 ]
Go to Layout [ “01EditTime” (brainstate) ]
Else
Go to Layout [ “EditTimeiPhone” (brainstate) ]
End If
#
End If
#
#Perform correct sort.
If [ Filter ( Get (LayoutName) ; "M" ) = "M" ]
Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "number" ]
Else
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::groupType; ascending
day1::swStart; ascending
brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "allow" ]
End If
#
#
#Go to active brainstate or first brainstate.
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ day1::swBugField = "veto" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ day1::swBugField ≠ "veto" ]
Go to Record/Request/Page
[ First ]
End If
July 13, ଘ౮28 13:29:37 ActionLog.fp7 - editTimePart1 -1-
