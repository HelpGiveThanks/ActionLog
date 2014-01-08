planned workouts: main: deletePlannedWeek
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Capture variable for week.
Set Variable [ $week; Value:planlog::kweek ]
Refresh Window
#
#Ask user if this record needs to be deleted.
Show Custom Dialog [ Message: "Delete this planned week? NOTE: The workouts attached to this week will not be deleted, only
these plans to use them."; Buttons: “cancel”, “delete” ]
#
#If not, then cancel script.
If [ Get ( LastMessageChoice ) = 1 ]
Set Variable [ $week ]
Refresh Window
#
#Restart load record script.
Set Variable [ $$stopLoadUserWeek ]
Exit Script [ ]
End If
#
#Delete it.
#Find all planned workouts for this week.
New Window [ ]
Enter Find Mode [ ]
Set Field [ planlog::kweek; $week ]
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::plannedOrPerformed; "planned" ]
Perform Find [ ]
Delete All Records
[ No dialog ]
#
#Find this week record and delete it.
Go to Layout [ “weekTag” (week) ]
Enter Find Mode [ ]
Set Field [ week::_Lweek; $week ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
#
#Return user to previous window.
Close Window [ Current Window ]
#
#Set variables to conditionally format current record.
Set Variable [ $$recordPlan; Value:Get ( RecordID ) ]
Refresh Window
#
January 8, 平成26 12:33:40 Fat and Muscle Efﬁciency Research.fp7 - deletePlannedWeek -1-planned workouts: main: deletePlannedWeek
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
#
#Let user know that the workouts will now be renumbered.
If [ Get (FoundCount) ≠ 0 ]
Show Custom Dialog [ Message: "Your planned workouts will now be renumbered to close gap left by deleted workout."; Buttons:
“OK” ]
Perform Script [ “orderPlannedWorkouts” ]
End If
#
January 8, 平成26 12:33:40 Fat and Muscle Efﬁciency Research.fp7 - deletePlannedWeek -2-
