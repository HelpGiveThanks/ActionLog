speciﬁc action log: ﬁndGroupPart1
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop script if user is process of picking a speciﬁc action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a speciﬁc-action group. After you do this you can ﬁnd speciﬁc act records by group."; Buttons:
“OK” ]
Exit Script [ ]
End If
#
#Find all speciﬁc actions with this key.
Go to Layout [ “IssuesAndObservationsFIND” (brainstate) ]
Scroll Window
[ Home ]
Set Variable [ $$found ]
#
#Find all speciﬁc actions with this key.
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; "nothing" ]
Perform Find [ ]
#
#If user selected the same category that was already
#selected then stop this script.
Select Window [ Name: "Tag"; Current ﬁle ]
Go to Layout [ “IssuesAndObservationsFIND” (brainstate) ]
Scroll Window
[ Home ]
#
January 6, 平成26 11:22:02 ActionLog.fp7 - ﬁndGroupPart1 -1-
