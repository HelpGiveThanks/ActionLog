navigation: gotoSpecificAction
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action tag or click the cancel button in the Tag window. After you do this you can go to
the Specific Action window. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
Select Window [ Name: "Specific Action" ]
December 6, ଘ౮27 20:39:26 ActionLog.fp7 - gotoSpecificAction -1-
