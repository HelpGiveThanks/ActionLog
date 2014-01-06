Sorts: sortSubAlphaTotal
#PURPOSE of the 4 number and alpha ﬁelds, sort by the last one
#
#
#
If [ steward::chosenSortTotal = "cat" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSortTotal; "tac" ]
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
If [ steward::chosenSortTotal ≠ "cat" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSortTotal; "cat" ]
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
January 6, 平成26 0:53:47 ActionLog.fp7 - sortSubAlphaTotal -1-
