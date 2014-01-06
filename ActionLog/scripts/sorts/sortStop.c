Sorts: sortStop
#PURPOSE sort by stop time
#
#
#
If [ steward::chosenSort = "veto" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: day1::_keyDay; ascending
day1::swStop; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "etov" ]
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
If [ steward::chosenSort ≠ "veto" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Speciﬁed Sort Order: day1::swStop; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "veto" ]
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
January 6, 平成26 0:49:08 ActionLog.fp7 - sortStop -1-
