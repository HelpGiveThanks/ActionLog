specific action log: gotoDay
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action tag or click the cancel button in the Tag window. After you do this you
can go to the Day window."; Buttons: “OK” ]
Exit Script [ ]
End If
#
Select Window [ Name: "Day"; Current file ]
December 6, ଘ౮27 22:00:06 ActionLog.fp7 - gotoDay -1-
