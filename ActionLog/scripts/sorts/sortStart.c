Sorts: sortStart
#PURPOSE sort by start time
#
#
#
If [ steward::chosenSort = "allow" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
// Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStart; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::groupType; ascending
day1::swStart; ascending
brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "wolla" ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
Go to Field [ ]
Halt Script
End If
If [ steward::chosenSort ≠ "allow" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
// Sort Records [ Specified Sort Order: day1::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
// Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::groupType; ascending
day1::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::groupType; ascending
day1::swStart; descending
brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "allow" ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
Go to Field [ ]
End If
January 6, 平成26 0:48:31 ActionLog.fp7 - sortStart -1-
