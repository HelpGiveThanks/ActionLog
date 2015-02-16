navigation: EditTimePart1
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Set Field [ steward::chosenLayoutMain; steward::chosenSort ]
#
#
#2 toggle the retired status field
If [ steward::retiredStatus = "" ]
Perform Script [ “retireButton” ]
End If
#
#
Go to Layout [ “01EditTime” (brainstate) ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::groupType; ascending
day1::swStart; ascending
brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
// Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "allow" ]
#7 go to active brainstate or first brainstate.
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
// Go to Record/Request/Page
[ First ]
// Loop
// Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
// Go to Record/Request/Page
[ Next ]
// End Loop
// If [ day1::_keyBrainstate = "" ]
// Scroll Window
[ Home ]
// End If
January 5, 平成26 19:09:41 ActionLog.fp7 - EditTimePart1 -1-
