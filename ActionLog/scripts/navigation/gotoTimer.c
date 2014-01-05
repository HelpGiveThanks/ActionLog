navigation: gotoTimer
#
#Stop script if user is process of picking a speciﬁc action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a speciﬁc-action group. After you do this you can select to go to other windows. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
Select Window [ Name: "Timer" ]
January 5, 平成26 14:24:47 ActionLog.fp7 - gotoTimer -1-
