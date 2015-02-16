Sorts: sortID
#PURPOSE sort by ID
#
#
#
If [ steward::chosenSort = "id" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "di" ]
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
If [ steward::chosenSort ≠ "id" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "id" ]
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
January 6, 平成26 0:50:56 ActionLog.fp7 - sortID -1-
