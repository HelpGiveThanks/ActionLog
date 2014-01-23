editCreateWorkout: editorButtons: duplicateWorkout
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#If there are no records, stop the script.
If [ Get (FoundCount) = 0 ]
Exit Script [ ]
End If
#
#Capture the workout key.
Set Variable [ $workoutOriginal; Value:activity::_Lactivity ]
#
#Set green segment bar to segment 1.
Set Field [ activity::segmentNumberGlobal; 1 ]
#
#Return to editor window if not in this window.
If [ Get (WindowName) = "Select Workout" ]
Close Window [ Current Window ]
Select Window [ Name: "Workout Editor"; Current file ]
#
#Find selected workout to duplicate.
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; $workoutOriginal ]
Perform Find [ ]
End If
#
#Create a new workout.
New Record/Request
#
#Capture the new workout's key.
Set Variable [ $workout; Value:activity::_Lactivity ]
#
#Delete this record as we only want a new key.
Delete Record/Request
[ No dialog ]
#
#Duplicate the workout.
Duplicate Record/Request
#
#Replace the duplicate key with the new key.
Set Field [ activity::_Lactivity; $workout ]
#
#Omit orginal record.
Go to Record/Request/Page
[ First ]
Omit Record
#
#Set status to blank (not in use).
Set Field [ activity::planningOrPlanned; "" ]
#
#Open a new window so the users place is not lost.
New Window [ Height: 1; Width: 1; Top: 1; Left: 1 ]
January 8, 平成26 12:39:14 Fat and Muscle Efﬁciency Research.fp7 - duplicateWorkout -1-editCreateWorkout: editorButtons: duplicateWorkout
// New Window [ Top: 1; Left: 1 ]
Go to Layout [ “WorkoutSegment” (segment01) ]
#
#Find all segments in for orginal workout.
Enter Find Mode [ ]
Set Field [ segment01::kworkout; $workoutOriginal ]
Perform Find [ ]
#
#Now repeat the duplication process for each segment:
#new record for key, duplicate record, replace key.
Go to Record/Request/Page
[ Last ]
Loop
#
New Record/Request
Set Variable [ $segment; Value:segment01::_Lsegment ]
#
Delete Record/Request
[ No dialog ]
#
Duplicate Record/Request
Set Field [ segment01::_Lsegment; $segment ]
Set Field [ segment01::kworkout; $workout ]
#
Omit Record
Omit Record
#
Exit Loop If [ Get (FoundCount) = 0 ]
#
End Loop
#
#Show newly duplicated workout.
Close Window [ Current Window ]
#
January 8, 平成26 12:39:14 Fat and Muscle Efﬁciency Research.fp7 - duplicateWorkout -2-
