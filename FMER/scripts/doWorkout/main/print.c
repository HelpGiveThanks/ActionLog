doWorkout: main: print
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#If the workout has not been totaled then exit script.
If [ activity::go = "" ]
Exit Script [ ]
End If
#
#If the workout has not assigned a focus exit sript.
If [ activity::Type = "" ]
Show Custom Dialog [ Message: "All workouts are required to have a focus. Select one or more by checking the boxes at the
top of the screen."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Set greem line to starting position.
Set Field [ activity::segmentNumberGlobal; 1 ]
#
If [ Get (LayoutTableName) = "activity" ]
#
#Capture workout key.
Set Variable [ $workout; Value:activity::_Lactivity ]
#
Else
#
#Stop script if there is no written workout assigned.
If [ planlog::kworkout = "" ]
Exit Script [ ]
End If
#
#Capture workout key.
Set Variable [ $workout; Value:planlog::kworkout ]
End If
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Set window title to workout.
New Window [ Name: "Print Workout" ]
#
#Restart load record script.
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
#
#Show on select layout.
Go to Layout [ “print” (activity) ]
#
#Find the workout.
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; $workout ]
January 8, 平成26 12:35:59 Fat and Muscle Efﬁciency Research.fp7 - print -1-doWorkout: main: print
Perform Find [ ]
Enter Preview Mode
Adjust Window
[ Resize to Fit ]
Refresh Window
#
#Print workout.
Print [ ]
#
#Set starting sequence segements.
Close Window [ Current Window ]
January 8, 平成26 12:35:59 Fat and Muscle Efﬁciency Research.fp7 - print -2-
