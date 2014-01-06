Sorts: sortActivityWeek
#PURPOSE sort by total time on week or month layouts
#
#
#
If [ steward::chosenSort = "act" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: brainstate::monthsum; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "tca" ]
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
If [ steward::chosenSort ≠ "atc" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortBlanksToBottom; descending
brainstate::monthsum; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "act" ]
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
January 6, 平成26 0:50:19 ActionLog.fp7 - sortActivityWeek -1-
