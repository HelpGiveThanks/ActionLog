editCreateWorkout: editorButtons: deleteWorkout
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#If there are no records, stop the script.
If [ Get (FoundCount) = 0 ]
Exit Script [ ]
End If
#Check if workout is locked.
If [ activity::planningOrPlanned = "" ]
Show Custom Dialog [ Message: "Delete this workout?"; Buttons: “cancel”, “delete” ]
If [ Get (LastMessageChoice) = 1 ]
Exit Script [ ]
Else
Set Variable [ $workout; Value:activity::_Lactivity ]
Delete Record/Request
[ No dialog ]
#
Go to Layout [ “WorkoutSegment” (segment01) ]
Enter Find Mode [ ]
Set Field [ segment01::kworkout; $workout ]
Perform Find [ ]
If [ segment01::kworkout = $workout ]
Delete All Records
[ No dialog ]
End If
#
Go to Layout [ “activitySequence1” (activitySequence1) ]
Enter Find Mode [ ]
Set Field [ activitySequence1::kactivity; $workout ]
Perform Find [ ]
If [ activitySequence1::kactivity = $workout ]
Delete All Records
[ No dialog ]
End If
#
Select Window [ Name: "Plan Week"; Current file ]
#
#Stop the user week record script from loading to
#speed up script and to stop variables from being wiped
#out.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Get record number so after looping system can return
#the record the user was on.
Set Variable [ $number; Value:Get (RecordNumber) ]
#
#Loop thru all records and remove deleted workout key.
Loop
If [ planlog::kworkout = $workout ]
Set Field [ planlog::kworkout; "" ]
End If
January 8, 平成26 12:39:46 Fat and Muscle Efﬁciency Research.fp7 - deleteWorkout -1-editCreateWorkout: editorButtons: deleteWorkout
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Restart load record script.
#new record.
Set Variable [ $$stopLoadUserWeek ]
Select Window [ Name: "Workout Editor"; Current file ]
End If
Go to Layout [ original layout ]
End If
#
January 8, 平成26 12:39:46 Fat and Muscle Efﬁciency Research.fp7 - deleteWorkout -2-
