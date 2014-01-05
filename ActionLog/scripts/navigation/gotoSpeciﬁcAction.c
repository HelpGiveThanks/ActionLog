navigation: gotoSpeciﬁcAction
#
#Stop script if user is process of picking a speciﬁc action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a speciﬁc-action group. After you do this you can select to go to other windows. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
Select Window [ Name: "Speciﬁc Action" ]
January 5, 平成26 14:27:58 ActionLog.fp7 - gotoSpeciﬁcAction -1-
