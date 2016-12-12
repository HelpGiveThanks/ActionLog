specific action log: moveTagStep1
#
#Exit script if move is in progress.
If [ $$stopMoveStep1 = 1 ]
Exit Script [ ]
End If
#
#Capture essential information used by
#moveTagStep2 script.
Set Variable [ $$groupKey; Value:SPAGroupTag::_keyGroup ]
Set Variable [ $$groupName; Value:TagGroup::text ]
Go to Field [ ]
December 10, ଘ౮28 23:41:53 ActionLog.fp7 - moveTagStep1 -1-
