log: main: deleteLoggedWorkoutFromWeek
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Capture variables to check for workout and week.
Set Variable [ $workout; Value:planlog::kworkout ]
Set Variable [ $delete; Value:planlog::_Lplanlog ]
Set Variable [ $week; Value:planlog::kweek ]
Refresh Window
#
#Ask user if this record needs to be deleted.
Show Custom Dialog [ Message: "Delete this planned workout? NOTE: The workout itself will not be deleted, only this instance of its
use during this week."; Buttons: “cancel”, “delete” ]
#
#If not, then cancel script.
If [ Get ( LastMessageChoice ) = 1 ]
Set Variable [ $delete ]
Refresh Window
#
#Restart load record script.
Set Variable [ $$stopLoadUserWeek ]
Exit Script [ ]
End If
#
#Delete it.
Delete Record/Request
[ No dialog ]
#
#Make sure this workout is not the last workout for
#this week.
New Window [ ]
Enter Find Mode [ ]
Set Field [ planlog::kweek; $week ]
Perform Find [ ]
#
#If it was the last workout for this week ....
If [ Get (FoundCount) = 0 ]
#
#Find this week on the week layout and delete it.
Go to Layout [ “weekTag” (week) ]
Enter Find Mode [ ]
Set Field [ week::_Lweek; $week ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ original layout ]
End If
#
January 8, 平成26 12:11:11 Fat and Muscle Efﬁciency Research.fp7 - deleteLoggedWorkoutFromWeek -1-log: main: deleteLoggedWorkoutFromWeek
#If workout is attached, see if it is the only log record
#using this workout.
If [ $workout ≠ "" ]
Enter Find Mode [ ]
Set Field [ planlog::kworkout; $workout ]
Set Field [ planlog::plannedOrPerformed; "logged" ]
Set Field [ activity::planningOrPlanned; "logged" ]
Perform Find [ ]
#
#Find this week on the week layout and clear its
#logged status.
If [ Get (FoundCount) = 0 ]
Go to Layout [ “CalculateTime” (activity) ]
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; $workout ]
Set Field [ activity::planningOrPlanned; "logged" ]
Perform Find [ ]
Set Field [ activity::planningOrPlanned; "" ]
End If
End If
#
#Return user to previous window.
Close Window [ Current Window ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadUserLogWeek” ]
#
January 8, 平成26 12:11:11 Fat and Muscle Efﬁciency Research.fp7 - deleteLoggedWorkoutFromWeek -2-
