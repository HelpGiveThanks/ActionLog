not sure if these are being used: FolderStopwatchCheck
Go to Record/Request/Page
[ First ]
Loop
If [ $$folderon = brainstate::_lockBrainstateID ]
#no other stopwatch is running and one is turned on = 1 one stopwatch running
If [ brainstate::FolderOn = "" and $$stopwatchON = "t" ]
Set Field [ brainstate::FolderOn; "1" ]
Set Variable [ $$stopwatchON; Value:"" ]
Exit Script [ ]
End If
#x number of stopwatchs are already running and another one is turned on = x + 1 more stopwatch running
If [ brainstate::FolderOn ≠ "" and $$stopwatchON = "t" ]
Set Field [ brainstate::FolderOn; brainstate::FolderOn + 1 ]
Set Variable [ $$stopwatchON; Value:"" ]
Exit Script [ ]
End If
#x number of stopwatchs are already running and another one is turned off = x - 1 one less stopwatch running
If [ brainstate::FolderOn > 1 and $$stopwatchON = "f" ]
Set Field [ brainstate::FolderOn; brainstate::FolderOn - 1 ]
Set Variable [ $$stopwatchON; Value:"" ]
Exit Script [ ]
End If
#1 stopwatch is running and one is turned off = 0 stopwatchs running
If [ brainstate::FolderOn = 1 and $$stopwatchON = "f" ]
Set Field [ brainstate::FolderOn; "" ]
Set Variable [ $$stopwatchON; Value:"" ]
Exit Script [ ]
End If
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Exit Script [ ]
January 6, 平成26 12:59:34 ActionLog.fp7 - FolderStopwatchCheck -1-
