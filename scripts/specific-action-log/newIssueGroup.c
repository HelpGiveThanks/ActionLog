speciﬁc action log: newIssueGroup
#
Set Variable [ $brainstate; Value:brainstate::_lockBrainstateID ]
#
Go to Layout [ “IssuesAndObservations Copy” (issue) ]
#
New Record/Request
Set Field [ issue::lock; "location" ]
Set Field [ issue::_keyBrainstate; $brainstate ]
#
Set Variable [ $group; Value:issue::_LockList ]
#
Go to Layout [ original layout ]
#
Go to Object [ Object Name: "group" ]
#
Go to Portal Row
[ First ]
Loop
Exit Loop If [ $group = category::_LockList ]
Go to Portal Row
[ Select; Next ]
End Loop
#
Go to Field [ category::text ]
January 6, 平成26 11:15:58 ActionLog.fp7 - newIssueGroup -1-
