user: navigation: goltoUserWeek
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Set variable to conditionally format current record.
#This is done in case user changed anything after record
#was loaded.
Set Variable [ $$recordUser; Value:Get ( RecordID ) ]
Set Field [ planlog::kuserGlobal; exerciseMHR::kuser ]
Set Field [ exerciseMHR::kexerciseGlobal; exerciseMHR::_LexerciseMHR ]
#
#Set max heart rate for workout segment display.
Set Field [ segment01::MaxHeartRate; exerciseMHR::MaxHeartRateCurrent ]
Set Field [ exerciseMHR::MaxHeartRate; exerciseMHR::MaxHeartRateCurrent ]
Refresh Window
Go to Field [ ]
#
#Stop script if essential info is missing and inform user.
If [ exerciseMHR::MaxHeartRateCurrent = "" or exerciseMHR::exercise = "" or user::name = "" ]
Show Custom Dialog [ Message: "Name, test exercise and test bpm ﬁelds must be ﬁlled in before going to workouts."; Buttons:
“OK” ]
Exit Script [ ]
End If
#
#Create a new window for planning workouts.
Adjust Window
[ Resize to Fit ]
Set Variable [ $width; Value:Get (WindowWidth) ]
New Window [ Name: "Plan Week"; Height: Get (ScreenHeight); Left: $width ]
Go to Layout [ “weekPlan” (planlog) ]
#
#Start record load script to highlight first record.
Set Variable [ $$stopLoadUserWeek ]
#
#Find any workouts in the planning stage created
#by this user.
Enter Find Mode [ ]
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::plannedOrPerformed; "planning" ]
Perform Find [ ]
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Create a window to show icons for creating workouts.
New Window [ Name: "Icons" ]
If [ PatternCount ( Get ( ApplicationVersion ) ; "GO" ) ]
January 8, 平成26 12:07:30 Fat and Muscle Efﬁciency Research.fp7 - goltoUserWeek -1-user: navigation: goltoUserWeek
Go to Layout [ “iconSmallGrid” (iconGrid) ]
Else
Set Variable [ $$showSelection; Value:1 ]
Go to Layout [ “iconLargeGrid” (iconGrid) ]
Adjust Window
[ Resize to Fit ]
End If
#
#Create a window for editing and creating new workouts.
New Window [ Name: "Workout Editor"; Height: Get (ScreenHeight); Top: 0; Left: 0 ]
#
#Set greem line to starting position.
Set Field [ activity::segmentNumberGlobal; 1 ]
#
If [ PatternCount ( Get ( ApplicationVersion ) ; "GO" ) ]
Go to Layout [ “EditSmallTime” (activity) ]
Else
Go to Layout [ “Edit” (activity) ]
End If
Adjust Window
[ Resize to Fit ]
#
#Find nothing so editor window is empty.
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; "nothing" ]
Perform Find [ ]
#
#Set green segment line to segment 1.
Set Field [ activity::segmentNumberGlobal; 1 ]
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
Go to Record/Request/Page
[ First ]
#
#Restart load record script and perform it to highlight
#current record, if any.
January 8, 平成26 12:07:30 Fat and Muscle Efﬁciency Research.fp7 - goltoUserWeek -2-user: navigation: goltoUserWeek
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadUserPlannedWeek” ]
#
#Select planned workouts window.
Select Window [ Name: "Planned Workouts"; Current file ]
#
#Select user log.
Select Window [ Name: "Fat and Muscle Efficiency Research"; Current file ]
#
#Go to user workout layout.
Set Window Title [ Current Window; New Title: "My Workouts" ]
Move/Resize Window [ Current Window; Top: 0; Left: 0 ]
Go to Layout [ “userWeek” (planlog) ]
Adjust Window
[ Resize to Fit ]
#
#Find all user logged workouts.
Enter Find Mode [ ]
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::plannedOrPerformed; "logged" ]
Perform Find [ ]
If [ Get (LastError) = 401 ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Exit Script [ ]
End If
Sort Records [ Specified Sort Order: week::date; descending
planlog::date; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Field [ planlog::kweekGlobal; planlog::kweek ]
Go to Field [ ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadUserLogWeek” ]
#
January 8, 平成26 12:07:30 Fat and Muscle Efﬁciency Research.fp7 - goltoUserWeek -3-
