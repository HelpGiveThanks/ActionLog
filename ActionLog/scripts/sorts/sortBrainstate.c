Sorts: sortBrainstate
#PURPOSE sort by record title
#
#
#
If [ steward::chosenSort = "Brainstates A-Z" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: day1::_keyDay; ascending
brainstate::description; descending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "Brainstates Z-A" ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
Halt Script
End If
If [ steward::chosenSort ≠ "Brainstates A-Z" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: day1::_keyDay; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "Brainstates A-Z" ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
Halt Script
End If
January 6, 平成26 0:32:59 ActionLog.fp7 - sortBrainstate -1-
