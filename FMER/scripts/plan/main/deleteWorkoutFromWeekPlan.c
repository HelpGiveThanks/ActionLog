plan: main: deleteWorkoutFromWeekPlan
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#If no records exist, exit script.
If [ Get (FoundCount) = 0 ]
Exit Script [ ]
End If
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Capture variables to check for workout and week.
Set Variable [ $delete; Value:planlog::_Lplanlog ]
Set Variable [ $week; Value:planlog::kweek ]
Refresh Window
#
#Ask user if this record needs to be deleted.
Show Custom Dialog [ Message: "Delete this workout plan? NOTE: The workout assigned to this planned use will not be deleted.";
Buttons: “cancel”, “delete” ]
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
January 8, 平成26 12:25:08 Fat and Muscle Efﬁciency Research.fp7 - deleteWorkoutFromWeekPlan -1-plan: main: deleteWorkoutFromWeekPlan Delete Record/Request
[ No dialog ]
End If
#
#Return user to previous window.
Close Window [ Current Window ]
#
#Set variables to conditionally format current record.
Set Variable [ $$recordPlan; Value:Get ( RecordID ) ]
Refresh Window
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
#
January 8, 平成26 12:25:08 Fat and Muscle Efﬁciency Research.fp7 - deleteWorkoutFromWeekPlan -2-
