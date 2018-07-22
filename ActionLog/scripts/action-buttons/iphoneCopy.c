action buttons: iphoneCopy
#
#If the there is nothing to copy exit script.
If [ Get ( ActiveFieldContents ) = "" ]
Exit Script [ ]
End If
#
#Make a copy the field contents.
Set Variable [ $$copy; Value:Get (ActiveFieldContents) ]
#
#Exit the field and highlight the 'paste'
#button to show the user a copy is ready
#for pasting.
Go to Field [ ]
Refresh Window
December 15, ଘ౮28 23:12:03 ActionLog.fp7 - iphoneCopy -1-
