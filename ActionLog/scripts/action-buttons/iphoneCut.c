action buttons: iphoneCut
#
#If the there is nothing to cut exit script.
If [ Get ( ActiveFieldContents ) = "" ]
Exit Script [ ]
End If
#
#Make a copy the field contents.
Set Variable [ $$copy; Value:Get (ActiveFieldContents) ]
#
#Clear the field, which is the cutting part.
Set Field [ "" ]
#
#Exit the field and highlight the 'paste'
#button to show the user a copy is ready
#for pasting.
Go to Field [ ]
Refresh Window
December 15, ଘ౮28 23:13:58 ActionLog.fp7 - iphoneCut -1-
