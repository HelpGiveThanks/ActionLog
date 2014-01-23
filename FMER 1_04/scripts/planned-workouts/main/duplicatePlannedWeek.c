planned workouts: main: duplicatePlannedWeek
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Capture the week key.
Set Variable [ $week; Value:planlog::kweek ]
#
#Go to plan window and see if there is a plan in progress.
Select Window [ Name: "Plan Week"; Current file ]
#
#If there is tell user it will be deleted if they proceed.
If [ Get (FoundCount) ≠ 0 ]
Show Custom Dialog [ Message: "You are already planning a week of workouts. If you decide to continue with the duplicate of
the planned week in the Planned Workouts window, the plan in this window will be deleted."; Buttons: “cancel”, “continue” ]
#
#If user cancels, then return user to planned window
#and exit script.
If [ Get (LastMessageChoice) = 1 ]
Select Window [ Name: "Planned Workouts"; Current file ]
Set Variable [ $$stopLoadUserWeek ]
Exit Script [ ]
End If
#
#If user says to proceed then delete current plan records.
Set Variable [ $weekDelete; Value:planlog::kweek ]
#
#Delete all plan records
Delete All Records
[ No dialog ]
#
#Find this week on the week layout and delete it.
Go to Layout [ “weekTag” (week) ]
Enter Find Mode [ ]
Set Field [ week::_Lweek; $weekDelete ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
#
#Return ot plan layout and continue with duplication.
Go to Layout [ “weekPlan” (planlog) ]
End If
#
#Find week to be duplicated.
Select Window [ Name: "Plan Week"; Current file ]
Enter Find Mode [ ]
Set Field [ planlog::kweek; $week ]
Perform Find [ ]
#
January 8, 平成26 12:30:36 Fat and Muscle Efﬁciency Research.fp7 - duplicatePlannedWeek -1-planned workouts: main: duplicatePlannedWeek
#Go to week layout and find week.
Go to Layout [ “weekTag” (week) ]
Enter Find Mode [ ]
Set Field [ week::_Lweek; $week ]
Perform Find [ ]
#
#Create a new week.
New Record/Request
#
#Capture the new week's key.
Set Variable [ $newWeek; Value:week::_Lweek ]
#
#Delete this record as we only want a new key.
Delete Record/Request
[ No dialog ]
#
#Duplicate the week.
Duplicate Record/Request
#
#Replace the duplicate key with the new key.
Set Field [ week::_Lweek; $newWeek ]
#
#Go back to plan window.
Go to Layout [ “weekPlan” (planlog) ]
#
#Give the new week key to duplciates of these workouts.
Go to Record/Request/Page
[ Last ]
Loop
#
#Create a new planned workout.
New Record/Request
#
#Capture the new workout's key.
Set Variable [ $workout; Value:planlog::_Lplanlog ]
#
#Delete this record as we only want a new key.
Delete Record/Request
[ No dialog ]
#
#Duplicate the planned workout.
Duplicate Record/Request
#
#Replace the duplicate key with the new key.
Set Field [ planlog::_Lplanlog; $workout ]
#
#Give it the new week key.
Set Field [ planlog::kweek; $newWeek ]
#
#Set status to planning.
Set Field [ planlog::plannedOrPerformed; "planning" ]
January 8, 平成26 12:30:36 Fat and Muscle Efﬁciency Research.fp7 - duplicatePlannedWeek -2-planned workouts: main: duplicatePlannedWeek
#
#Omit duplicate and orginal records.
Omit Record
Omit Record
#
Exit Loop If [ Get (FoundCount) = 0 ]
End Loop
#
#Find all the newly duplicated workouts.
Enter Find Mode [ ]
Set Field [ planlog::kweek; $newWeek ]
Perform Find [ ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadPlanWeek” ]
#
January 8, 平成26 12:30:36 Fat and Muscle Efﬁciency Research.fp7 - duplicatePlannedWeek -3-
