log: navigation: selectWorkout
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Capture key of week user is looking at.
Set Variable [ $week; Value:planlog::kweek ]
#
#If planned workouts window exists go to it othersise
#create it.
Select Window [ Name: "Planned Workouts"; Current file ]
If [ Get (LastError) = 0 ]
#
#Loop to the week the user was looking at.
Loop
Exit Loop If [ planlog::kweek = $week ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#If not found then go to first record.
If [ planlog::kweek ≠ $week ]
Go to Record/Request/Page
[ First ]
End If
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadUserPlannedWeek” ]
Exit Script [ ]
#
End If
#
#Open a new window for planned workouts created by
#this user.
Adjust Window
[ Resize to Fit ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: 0 ]
Set Variable [ $width; Value:Get (WindowWidth) ]
New Window [ Name: "Planned Workouts"; Height: Get (ScreenHeight); Top: 0; Left: $width ]
Go to Layout [ “plannedWeek” (planlog) ]
#
#Find all user planned workouts.
Enter Find Mode [ ]
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::plannedOrPerformed; "planned" ]
Perform Find [ ]
Sort Records [ Specified Sort Order: prediction 3::name; ascending
week::Order; ascending ]
[ Restore; No dialog ]
January 8, 平成26 12:20:54 Fat and Muscle Efﬁciency Research.fp7 - selectWorkout -1-log: navigation: selectWorkout Sort Records [ Specified Sort Order: prediction 3::name; ascending
week::Order; ascending ]
[ Restore; No dialog ]
#
#Loop to the week the user was looking at.
Loop
Exit Loop If [ planlog::kweek = $week ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#If not found then go to first record.
If [ planlog::kweek ≠ $week ]
Go to Record/Request/Page
[ First ]
End If
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadUserPlannedWeek” ]
#
January 8, 平成26 12:20:54 Fat and Muscle Efﬁciency Research.fp7 - selectWorkout -2-
