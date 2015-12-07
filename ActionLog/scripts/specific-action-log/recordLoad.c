specific action log: recordLoad
If [ $$stopRecordLoad = 1 or $$otherApps = 1 or $$specificActionTimer = 1 ]
Exit Script [ ]
End If
If [ reference::CurrentRecord = Get (RecordID) ]
Exit Script [ ]
End If
Set Field [ reference::CurrentRecord; Get ( RecordID ) ]
Set Variable [ $$timerIDnumber; Value:brainstate::_lockBrainstateID ]
Set Variable [ $$day1BugField; Value:day1::swBugField ]
If [ Get ( WindowTop ) < 0 ]
Move/Resize Window [ Current Window; Top: 0 ]
End If
December 6, ଘ౮27 21:02:05 ActionLog.fp7 - recordLoad -1-
