tutorial: newTutorialStep
#
#
If [ tutorial::layoutName = "" ]
Show Custom Dialog [ Message: "Select a tutorial name or create a new name for a new tutorial."; Buttons: “OK” ]
Exit Script [ ]
End If
#
Set Variable [ $tutorialNumber; Value:tutorial::number ]
Set Variable [ $tutorialLayout; Value:tutorial::klayout ]
Set Variable [ $tutorialName; Value:tutorial::kTutorial ]
New Record/Request
#
Set Field [ tutorial::klayout; $tutorialLayout ]
Set Field [ tutorial::kTutorial; $tutorialName ]
#
If [ $tutorialNumber = "" ]
Set Field [ tutorial::number; 1 ]
Else
Set Field [ tutorial::number; $tutorialNumber + .5 ]
End If
#
#
Sort Records [ Speciﬁed Sort Order: tutorial::kTutorial; ascending
tutorial::number; ascending ]
[ Restore; No dialog ]
// If [ Get (FoundCount) > $tutorialNumber + 1 ]
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
// End If
#
#
Go to Field [ tutorial::helpNumber ]
#
