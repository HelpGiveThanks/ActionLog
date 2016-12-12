Re-link orphaned issuetime records
#
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#
Show Custom Dialog [ Message: "This script needs more testing as it is deleting links to assigned time segments."; Buttons: “OK” ]
Exit Script [ ]
#
Go to Layout [ “SPATime” (SPATime) ]
Show All Records
Sort Records [ Specified Sort Order: SPATime::_Number; descending ]
[ Restore; No dialog ]
#
Go to Record/Request/Page
[ First ]
Loop
Set Variable [ $issue; Value:SPATime::_keySPA ]
Set Variable [ $dayLink; Value:SPATime::_keyDay ]
Set Variable [ $timeSegmentLink; Value:SPATime::_keyRepetition & SPATime::_keyDay ]
#
Go to Layout [ “specificAction” (specificAction) ]
#
Enter Find Mode [ ]
Set Field [ specificAction::_LockSpecificAction; $issue ]
Perform Find [ ]
#
If [ Get ( LastError ) ≠ 401 ]
#Add day and repetition key to issue if not there.
If [ FilterValues (specificAction::timeSegmentKeyList ; $timeSegmentLink & "¶") ≠ $timeSegmentLink & "¶" ]
Set Variable [ $timeAll; Value:specificAction::timeSegmentKeyList ]
Set Field [ specificAction::timeSegmentKeyList; $timeSegmentLink & ¶ & $timeAll ]
End If
#
#Add link to day if not there.
If [ FilterValues (specificAction::_keyLogs ; $dayLink & "¶") ≠ $dayLink & "¶" ]
Set Variable [ $day; Value:specificAction::_keyLogs ]
Set Field [ specificAction::_keyLogs; $dayLink & ¶ & $day ]
End If
#
Go to Layout [ “SPATime” (SPATime) ]
Set Field [ SPATime::orphanCheck; "OK" ]
#
Else
Go to Layout [ “SPATime” (SPATime) ]
Set Field [ SPATime::orphanCheck; "orphan" ]
End If
#
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#
#NOW REDO TIME CALC FOR ALL RECORDS
#
Go to Layout [ “specificAction” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::lock; "issue" ]
Perform Find [ ]
#
Go to Record/Request/Page
[ First ]
#
Loop
Set Variable [ $issue; Value:specificAction::_LockSpecificAction ]
#
Go to Layout [ “SPATime” (SPATime) ]
Enter Find Mode [ ]
Set Field [ SPATime::_keySPA; $issue ]
Perform Find [ ]
#
Go to Record/Request/Page
[ First ]
Loop
Set Variable [ $totalTime; Value:SPATime::TimeCalc + $totalTime ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
Go to Layout [ “specificAction” (specificAction) ]
Set Field [ specificAction::SPATotalTime; $totalTime ]
Set Variable [ $totalTime ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
Set Window Title [ Current Window; New Title: "backup" ]
#
December 11, ଘ౮28 20:58:30 MyData.fp7 - Re-link orphaned issuetime records -1-
