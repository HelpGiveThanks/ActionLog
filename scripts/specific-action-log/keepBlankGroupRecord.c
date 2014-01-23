speciﬁc action log: keepBlankGroupRecord
If [ $$stopGroup ≠ "" ]
Exit Script [ ]
End If
If [ category::text = " " ]
Go to Field [ ]
Show Custom Dialog [ Message: "This ﬁrst record must remain blank, so that new issues are always sorted to the top in the Issues Log
window."; Buttons: “OK” ]
End If
January 6, 平成26 11:25:10 ActionLog.fp7 - keepBlankGroupRecord -1-
