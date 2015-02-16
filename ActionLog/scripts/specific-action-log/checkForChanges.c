specific action log: CheckForChanges
If [ brainstate::_lockBrainstateID = brainstate::groupID or Filter ( Get ( ApplicationVersion ) ; "go" ) = "go" ]
Go to Field [ ]
Halt Script
End If
Set Variable [ $$fieldValue; Value:Get ( ActiveFieldContents ) ]
January 6, 平成26 1:12:52 ActionLog.fp7 - CheckForChanges -1-
