Sorts: sortNumbersTotal
#PURPOSE of the 4 number and alpha ﬁelds, sort by the ﬁrst one
#
#
#
If [ steward::chosenSortTotal = "number" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSortTotal; "rebmun" ]
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
If [ steward::chosenSortTotal ≠ "number" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSortTotal; "number" ]
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
January 6, 平成26 0:52:05 ActionLog.fp7 - sortNumbersTotal -1-
