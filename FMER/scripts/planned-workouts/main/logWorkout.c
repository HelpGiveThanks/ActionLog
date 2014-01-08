planned workouts: main: logWorkout
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Stop the user week record script from loading to
#speed up script and to stop variables from being wiped
#out.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Capture the key for this workout.
#Workout Editor Window
If [ Get (WindowName) = "Workout Editor" ]
Set Variable [ $workout; Value:activity::_Lactivity ]
#
#Capture window title for user's workouts.
// Set Variable [ $me; Value:userName::name & "'s Workouts" ]
Set Variable [ $me; Value:"My Workouts" ]
#
#Prevent workout from being modified as now it has
#been used.
Set Field [ activity::planningOrPlanned; "locked" ]
#
#Clear workout from window.
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; "nothing" ]
Perform Find [ ]
#
#Select Workout Window
Else If [ Get (WindowName) = "Select Workout" or Get (WindowName) = "Workout" ]
Set Variable [ $workout; Value:activity::_Lactivity ]
#
#Capture window title for user's workouts.
// Set Variable [ $me; Value:userName::name & "'s Workouts" ]
Set Variable [ $me; Value:"My Workouts" ]
#
#Prevent workout from being modified as now it has
#been used.
Set Field [ activity::planningOrPlanned; "locked" ]
#
#Clear workout from Editor window.
Select Window [ Name: "Workout Editor"; Current file ]
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; "nothing" ]
Perform Find [ ]
#
Close Window [ Name: "Select Workout"; Current file ]
Close Window [ Name: "Workout"; Current file ]
#
#Planned Workouts Window
Else If [ Get (WindowName) = "Planned Workouts" ]
Set Variable [ $workout; Value:planlog::kworkout ]
Set Variable [ $note; Value:planlog::note ]
January 8, 平成26 12:31:09 Fat and Muscle Efﬁciency Research.fp7 - logWorkout -1-planned workouts: main: logWorkout
#
#Capture window title for user's workouts.
// Set Variable [ $me; Value:user::name & "'s Workouts" ]
Set Variable [ $me; Value:"My Workouts" ]
#
End If
#
#Select user workout log window.
Select Window [ Name: $me; Current file ]
#
#Restart load record script and perform it to highlight
#new record.
Set Variable [ $$stopLoadUserWeek ]
#
#Create a new workout record to assign the planned
#workout to.
Perform Script [ “newUserWorkout” ]
#
#Assign the workout and set the status to logged.
Set Field [ planlog::kworkout; $workout ]
Set Field [ planlog::note; $note ]
Set Field [ planlog::z1hour; Hour ( activity::Zone1Time ) ]
Set Field [ planlog::z1minute; Minute ( activity::Zone1Time ) ]
Set Field [ planlog::z1second; Seconds ( activity::Zone1Time ) ]
#
Set Field [ planlog::z2hour; Hour ( activity::Zone2Time ) ]
Set Field [ planlog::z2minute; Minute ( activity::Zone2Time ) ]
Set Field [ planlog::z2second; Seconds ( activity::Zone2Time ) ]
#
Set Field [ planlog::z3hour; Hour ( activity::Zone3Time ) ]
Set Field [ planlog::z3minute; Minute ( activity::Zone3Time ) ]
Set Field [ planlog::z3second; Seconds ( activity::Zone3Time ) ]
#
Set Field [ planlog::z4hour; Hour ( activity::Zone4Time ) ]
Set Field [ planlog::z4minute; Minute ( activity::Zone4Time ) ]
Set Field [ planlog::z4second; Seconds ( activity::Zone4Time ) ]
#
Set Field [ planlog::z5hour; Hour ( activity::Zone5Time ) ]
Set Field [ planlog::z5minute; Minute ( activity::Zone5Time ) ]
Set Field [ planlog::z5second; Seconds ( activity::Zone5Time ) ]
#
#Go to selection.
Scroll Window
[ To Selection ]
Go to Field [ ]
#
January 8, 平成26 12:31:09 Fat and Muscle Efﬁciency Research.fp7 - logWorkout -2-
