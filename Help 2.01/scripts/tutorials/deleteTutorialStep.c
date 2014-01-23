tutorial: deleteTutorialStep
Show Custom Dialog [ Message: "Delete instruction " & Get (RecordNumber) & " ?"; Buttons: “Cancel”, “OK” ]
If [ Get ( LastMessageChoice ) = 1 ]
Exit Script [ ]
End If
Delete Record/Request
[ No dialog ]
Sort Records [ Speciﬁed Sort Order: tutorial::kTutorial; ascending
tutorial::number; ascending ]
[ Restore; No dialog ]
Go to Field [ ]
New Window [ ]
Go to Record/Request/Page
[ Last ]
Loop
Set Field [ tutorial::number; Get (RecordNumber) ]
Go to Record/Request/Page
[ Previous; Exit after last ]
End Loop
Close Window [ Current Window ]
