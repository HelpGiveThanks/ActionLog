navigation: gotoOrder
#
#Stop script if user is process of picking a speciﬁc action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a speciﬁc-action group. After you do this you can select to go to the order menu. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
January 5, 平成26 14:28:49 ActionLog.fp7 - gotoOrder -1-
