tutorial: moveTutorialStepToDifferentTutorial
Set Field [ tutorial::kTutorial; tutorial::tutorialName ]
Go to Field [ ]
If [ tutorial::kTutorial ≠ GetNthRecord ( tutorial::kTutorial ; Get (RecordNumber ) - 1 ) and Get (RecordNumber) ≠ 1 or
tutorial::kTutorial ≠ GetNthRecord ( tutorial::kTutorial ; Get (RecordNumber ) + 1 ) and Get (RecordNumber ) + 1 ≤ Get (FoundCount) ]
Omit Record
End If
