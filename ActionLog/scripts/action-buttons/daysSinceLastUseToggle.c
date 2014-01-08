action buttons: DaysSinceLastUseToggle
If [ brainstate::DaysSinceLastUseToggle = "" ]
Set Field [ brainstate::DaysSinceLastUseToggle; "t" ]
Else If [ brainstate::DaysSinceLastUseToggle ≠ "" ]
Set Field [ brainstate::DaysSinceLastUseToggle; "" ]
End If
January 6, 平成26 13:03:49 ActionLog.fp7 - DaysSinceLastUseToggle -1-
