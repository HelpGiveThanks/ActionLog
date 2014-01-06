Sorts: sortBrainstateWeekMonth
#PURPOSE by record title on week or month layouts
#
#
#
If [ steward::chosenSort = "Brainstates A-Z" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortBlanksToBottom; descending
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
Go to Field [ ]
Halt Script
End If
If [ steward::chosenSort ≠ "Brainstates A-Z" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortBlanksToBottom; descending
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
Go to Field [ ]
Halt Script
End If
January 6, 平成26 0:33:42 ActionLog.fp7 - sortBrainstateWeekMonth -1-
