log: logShowAll
#PURPOSE show only all records being browsed (list view)
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
// If [ Left ( $$loglayout ; 5 ) ≠ "total" ]
// Halt Script
// End If
#1 capture record number and object number user is currently on
#
#2 go to selected object
Go to Layout [ “LogHome” (brainstate) ]
Go to Record/Request/Page
[ First ]
Set Variable [ $itemID; Value:brainstate::_lockBrainstateID ]
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $itemID ]
Perform Find [ ]
Loop
Go to Layout [ “LogHome” (brainstate) ]
Go to Record/Request/Page
[ Next; Exit after last ]
Set Variable [ $itemID; Value:brainstate::_lockBrainstateID ]
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $itemID ]
Extend Found Set [ ]
End Loop
Go to Layout [ “logs2rows” (logs) ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
Go to Layout [ “logByActioniPhone” (logs) ]
End If
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
logs::_keyBrainstate; ascending
logs::logDay; descending ]
[ Restore; No dialog ]
January 5, 平成26 19:26:28 ActionLog.fp7 - logShowAll -1-
