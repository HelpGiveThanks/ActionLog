tutorial: gotoSelectedTutorial
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $kTutorial; Value:tutorialGroup::_Ltutorial ]
Go to Field [ ]
Set Variable [ $$stopScript; Value:1 ]
Go to Layout [ “tutorialUse” (tutorial) ]
Enter Find Mode [ ]
Set Field [ tutorial::kTutorial; $kTutorial ]
Perform Find [ ]
If [ $$lastError = 401 ]
Set Variable [ $$lastError ]
New Record/Request
Set Field [ tutorial::kTutorial; $kTutorial ]
End If
Set Variable [ $$stopScript ]
Sort Records [ Speciﬁed Sort Order: tutorial::kTutorial; ascending
tutorial::number; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Perform Script [ “performTutorialStep” ]
Scroll Window
[ Home ]
