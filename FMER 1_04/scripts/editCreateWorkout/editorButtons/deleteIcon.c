editCreateWorkout: editorButtons: deleteIcon
Set Variable [ $delete; Value:Right ( Get ( ActiveLayoutObjectName ) ; 2 ) ]
Go to Object [ Object Name: "segment" & $delete ]
If [ Get ( ActiveFieldContents ) = "" ]
Go to Field [ ]
Set Variable [ $delete ]
Refresh Window
Exit Script [ ]
End If
Show Custom Dialog [ Message: "delete icon or segement? If you delete icon the segement stays. If you delete the segement all
other segements move over to close the gap."; Buttons: “cancel”, “x icon”, “x segement” ]
If [ Get ( LastMessageChoice ) = 3 ]
Show Custom Dialog [ Message: "Are you sure you want delete this segement and move all the other segements over to ﬁll in its
gap?"; Buttons: “cancel”, “x segment” ]
If [ Get ( LastMessageChoice ) = 2 ]
Set Variable [ $workout; Value:activity::_Lactivity ]
New Window [ Height: 1; Width: 1; Top: 1; Left: 1 ]
// New Window [ ]
Go to Layout [ “WorkoutSegment” (segment01) ]
Enter Find Mode [ ]
Set Field [ segment01::kworkout; $workout ]
Set Field [ segment01::SegmentNumber; $delete ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
#
#Close gap by re-numbering all segments.
Enter Find Mode [ ]
Set Field [ segment01::kworkout; $workout ]
Perform Find [ ]
Go to Record/Request/Page
[ First ]
Set Variable [ $segment; Value:1 ]
Loop
Set Field [ segment01::SegmentNumber; If ($segment < 10 ; "0" & $segment ; $segment ) ]
Set Variable [ $segment; Value:segment01::SegmentNumber + 1 ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Close Window [ Current Window ]
Go to Field [ ]
Refresh Window
Exit Script [ ]
End If
End If
Go to Field [ ]
Refresh Window
Show Custom Dialog [ Message: "delete icon?"; Buttons: “OK”, “Cancel” ]
If [ Get ( LastMessageChoice ) = 1 ]
Go to Object [ Object Name: "icon" & $delete ]
Set Field [ "" ]
Go to Field [ ]
End If
January 8, 平成26 12:53:13 Fat and Muscle Efﬁciency Research.fp7 - deleteIcon -1-editCreateWorkout: editorButtons: deleteIcon
Set Variable [ $delete ]
Refresh Window
January 8, 平成26 12:53:13 Fat and Muscle Efﬁciency Research.fp7 - deleteIcon -2-
