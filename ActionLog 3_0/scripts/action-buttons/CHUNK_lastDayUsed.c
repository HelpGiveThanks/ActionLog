action buttons: CHUNK_lastDayUsed
#PURPOSE go the selected farmer's records from the createEditFarmer layout. (This is script is identical to the switchFarmer script except for
step 1, which is required because the reference ﬁeld is not available on this layout, and so the user's ID must be taken from the user table,
not the reference table.)
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#
#
#
Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
Go to Layout [ “logByDate” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $brainstateID ]
Perform Find [ ]
If [ Get ( LastError ) = 401 ]
Go to Layout [ original layout ]
Exit Script [ ]
End If
Sort Records [ Speciﬁed Sort Order: logs::_keyDay; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Field [ brainstate::DateOfLastUse; logs::_keyDay ]
Set Variable [ $date; Value:logs::_keyDay ]
If [ brainstate::groupID ≠ "" ]
Set Variable [ $brainstateID; Value:brainstate::groupID ]
Enter Find Mode [ ]
Set Field [ logs::_keyBrainstate; $brainstateID ]
Perform Find [ ]
If [ Get ( LastError ) = 401 ]
Go to Layout [ original layout ]
Exit Script [ ]
End If
Sort Records [ Speciﬁed Sort Order: logs::_keyDay; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
If [ reference::day1 ≠ $date ]
Set Field [ brainstate::DateOfLastUse; logs::_keyDay ]
Else If [ reference::day1 = $date ]
Set Field [ brainstate::DateOfLastUse; $date ]
End If
End If
Go to Layout [ original layout ]
January 5, 平成26 19:39:30 ActionLog.fp7 - CHUNK_lastDayUsed -1-
