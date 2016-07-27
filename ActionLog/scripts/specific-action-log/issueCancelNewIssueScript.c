specific action log: issueTestForModification
#
#
#
#
If [ $$issueTestModificationOfThisText = "" ]
Set Variable [ $$issueTestModificationOfThisText; Value:issue::text ]
#
Else If [ $$issueTestModificationOfThisText ≠ "" ]
#
If [ $$issueTestModificationOfThisText ≠ issue::text ]
Set Field [ issue::dateModified; Get ( CurrentTimeStamp ) ]
End If
#
Set Variable [ $$issueTestModificationOfThisText ]
#
End If
July 26, ଘ౮28 15:35:20 ActionLog.fp7 - issueTestForModification -1-
