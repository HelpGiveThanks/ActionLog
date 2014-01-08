editCreateWorkout: editorButtons: newSegment
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Capture the workout key.
Set Variable [ $workout; Value:activity::_Lactivity ]
Set Variable [ $newSegment; Value:Get ( ActiveLayoutObjectName ) ]
Go to Field [ ]
#
#Open a new window so the users place is not lost.
New Window [ Height: 1; Width: 1; Top: 1; Left: 1 ]
Go to Layout [ “WorkoutSegment” (segment01) ]
#
#Find all segments in for this workout and sort them.
Enter Find Mode [ ]
Set Field [ segment01::kworkout; $workout ]
Perform Find [ ]
Sort Records [ Specified Sort Order: segment01::SegmentNumber; ascending ]
[ Restore; No dialog ]
#
#Go to the last segement to determine what the segment
#number needs to be.
Go to Record/Request/Page
[ Last ]
Set Variable [ $segment; Value:Case ( segment01::SegmentNumber = "" ; "01" ;
Case ( Length (segment01::SegmentNumber + 1 ) = 1 ; "0" & segment01::SegmentNumber + 1 ; segment01::SegmentNumber +
1 ) ) ]
#
#If there are already 24 segments then tell user only
#24 segments are allowed and then exit script.
If [ $segment ≥ 25 ]
Show Custom Dialog [ Message: "24 segments are all that are currently allowed."; Buttons: “OK” ]
Close Window [ Current Window ]
Exit Script [ ]
End If
#
#Create a new segment record for this workout.
New Record/Request
Set Field [ segment01::SegmentNumber; $segment ]
Set Field [ activity::segmentNumberGlobal; $segment ]
Set Field [ segment01::kworkout; $workout ]
#
#If this is the first segment for this workout then set
#its zone to 1 as all workouts must start in zone 1.
If [ $segment = "01" ]
Set Field [ segment01::ZonePick; 1 ]
Close Window [ Current Window ]
Refresh Window
[ Flush cached join results ]
Exit Script [ ]
End If
#
January 8, 平成26 12:46:56 Fat and Muscle Efﬁciency Research.fp7 - NewSegment -1-editCreateWorkout: editorButtons: NewSegment
#Close the window to return user to workout window
#which now will show the newly added segment.
Close Window [ Current Window ]
Refresh Window
[ Flush cached join results ]
January 8, 平成26 12:46:56 Fat and Muscle Efﬁciency Research.fp7 - NewSegment -2-
