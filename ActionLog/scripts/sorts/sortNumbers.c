Sorts: sortNumbers
#PURPOSE of the 4 number and alpha fields, sort by the first one
#
#
#
// If [ steward::chosenSort = "number" ]
// Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
// Sort Records [ Specified Sort Order: brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
// Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
// Set Field [ steward::chosenSort; "rebmun" ]
// Go to Record/Request/Page
[ First ]
// Loop
// Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
// Go to Record/Request/Page
[ Next ]
// End Loop
// Set Variable [ $$record ]
// Go to Field [ ]
// Halt Script
// End If
// If [ steward::chosenSort ≠ "number" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "number" ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
Go to Field [ ]
// End If
January 6, 平成26 0:34:17 ActionLog.fp7 - sortNumbers -1-
