specific action log: recordLoad
If [ $$stopRecordLoad = 1 or $$otherApps = 1 ]
Exit Script [ ]
End If
If [ reference::CurrentRecord = Get (RecordID) ]
Exit Script [ ]
End If
Set Field [ reference::CurrentRecord; Get ( RecordID ) ]
If [ Get ( WindowTop ) < 0 ]
Move/Resize Window [ Current Window; Top: 0 ]
End If
January 6, 平成26 1:08:40 ActionLog.fp7 - recordLoad -1-
