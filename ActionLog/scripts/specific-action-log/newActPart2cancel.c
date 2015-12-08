specific action log: newActPart2cancel
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop script if user is NOT in the process of picking a specific action group.
If [ $$pick ≠ 1 ]
Exit Script [ ]
End If
#
#
#If user cancels and decides not create a new action...
Set Variable [ $$pick ]
Go to Field [ ]
// Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
// Go to Layout [ “IssuesAndObservationsTag” (category) ]
Refresh Window
#
#Give key to current specific action.
Select Window [ Name: "Specific Action"; Current file ]
Delete Record/Request
[ No dialog ]
#
Sort Records [ ]
[ No dialog ]
Refresh Window
Perform Script [ “LoadIssuerecordID” ]
January 6, 平成26 11:15:28 ActionLog.fp7 - newActPart2cancel -1-
