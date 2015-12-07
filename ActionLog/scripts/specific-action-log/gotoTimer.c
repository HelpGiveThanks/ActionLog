specific action log: gotoTimer
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action tag or click the cancel button in the Tag window. After you do this you
can go to the Timer window."; Buttons: “OK” ]
Exit Script [ ]
End If
#
Select Window [ Name: "Timer"; Current file ]
December 6, ଘ౮27 21:57:54 ActionLog.fp7 - gotoTimer -1-
