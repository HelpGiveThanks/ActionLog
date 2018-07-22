action buttons: iphonePaste
#
#If the there is nothing to paste exit script.
If [ $$copy = "" ]
Exit Script [ ]
End If
#
#Paste the copy into the selected field.
Set Field [ $$copy ]
#
#Clear the $$copy variable and un-highligh
#the 'paste' button.
Set Variable [ $$copy ]
Go to Field [ ]
December 15, ଘ౮28 23:15:59 ActionLog.fp7 - iphonePaste -1-
