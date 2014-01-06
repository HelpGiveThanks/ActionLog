Sorts: sortBrainstateTotal
#PURPOSE sort by record title
#
#
#
If [ steward::chosenSortTotal = "Brainstates A-Z" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: day1::_keyDay; ascending
brainstate::description; descending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSortTotal; "Brainstates Z-A" ]
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
If [ steward::chosenSortTotal ≠ "Brainstates A-Z" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: day1::_keyDay; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSortTotal; "Brainstates A-Z" ]
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
January 6, 平成26 0:51:30 ActionLog.fp7 - sortBrainstateTotal -1-
