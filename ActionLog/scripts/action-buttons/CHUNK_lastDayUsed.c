action buttons: CHUNK_lastDayUsed
#PURPOSE calculates last day a timer was used
#so on days when a timer is not in use, this
#number can be shown to users letting them
#know how long since they last used a timer,
#or how long since they last exercised,
#for example.
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#
Set Variable [ $brainstateID; Value:timer::_lockTimer ]
Go to Layout [ “logByDate” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyTimer; $brainstateID ]
Perform Find [ ]
If [ Get ( LastError ) = 401 ]
Go to Layout [ original layout ]
Set Field [ timer::DateOfLastUse; "" ]
Exit Script [ ]
End If
Sort Records [ Specified Sort Order: logs::_keyDay; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Field [ timer::DateOfLastUse; logs::_keyDay ]
Set Variable [ $date; Value:logs::_keyDay ]
If [ timer::groupID ≠ "" ]
Set Variable [ $brainstateID; Value:timer::groupID ]
Enter Find Mode [ ]
Set Field [ logs::_keyTimer; $brainstateID ]
Perform Find [ ]
If [ Get ( LastError ) = 401 ]
Go to Layout [ original layout ]
Exit Script [ ]
End If
Sort Records [ Specified Sort Order: logs::_keyDay; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
If [ reference::day1 ≠ $date ]
Set Field [ timer::DateOfLastUse; logs::_keyDay ]
Else If [ reference::day1 = $date ]
Set Field [ timer::DateOfLastUse; $date ]
End If
End If
Go to Layout [ original layout ]
December 12, ଘ౮28 11:31:41 ActionLog.fp7 - CHUNK_lastDayUsed -1-
