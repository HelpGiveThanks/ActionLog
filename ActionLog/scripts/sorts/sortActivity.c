Sorts: sortActivity
#PURPOSE sort by total time on the day layouts
#
#
#
If [ steward::chosenSort = "act" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; descending
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
If [ steward::chosenSort ≠ "act" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; ascending
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
January 6, 平成26 0:49:44 ActionLog.fp7 - sortActivity -1-
