specific action log: recordLoad
If [ $$stopRecordLoad = 1 or $$otherApps = 1 or $$specificActionTimer = 1 or $$note = 1 ]
Exit Script [ ]
End If
If [ reference::CurrentRecord = Get (RecordID) ]
Exit Script [ ]
End If
Set Field [ reference::CurrentRecord; Get ( RecordID ) ]
Set Variable [ $$timerIDnumber; Value:timer::_lockTimer ]
If [ Get ( WindowTop ) < 0 ]
Move/Resize Window [ Current Window; Top: 0 ]
End If
December 10, ଘ౮28 20:59:58 ActionLog.fp7 - recordLoad -1-
