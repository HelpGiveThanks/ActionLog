navigation: viewAllNotesLayoutCheck
#
If [ $$note = 1 ]
Exit Script [ ]
End If
#
#Display all rows of time for this timer.
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “AllNotes3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “AllNotes2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “AllNotes1row” (logs) ]
End If
#
Go to Field [ logs::log ]
July 26, ଘ౮28 16:06:06 ActionLog.fp7 - viewAllNotesLayoutCheck -1-
