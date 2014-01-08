editCreateWorkout: editorButtons: fillPlanSlotWithWorkout
Allow User Abort [ Off ]
Set Error Capture [ On ]
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
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Capture the key for this workout.
Set Variable [ $workout; Value:activity::_Lactivity ]
#
#Close select window.
Close Window [ Name: "Select Workout"; Current file ]
#
#Select the planning window.
Select Window [ Name: "Plan Week"; Current file ]
#
#If there are no records to insert this key into then
#create a new record.
If [ Get (FoundCount) = 0 ]
Set Variable [ $$stopiphone; Value:1 ]
Perform Script [ “newWorkoutForPlan” ]
#
#If there are, make sure user wants to replace
#record values.
Else
Show Custom Dialog [ Message: "Add workout here (all time will be replaced with workout's time in zone) OR Make a new record
for workout values?"; Buttons: “cancel”, “replace”, “new” ]
If [ Get ( LastMessageChoice ) = 1 ]
Exit Script [ ]
Else If [ Get ( LastMessageChoice ) = 3 ]
Set Variable [ $$stopiphone; Value:1 ]
Perform Script [ “newWorkoutForPlan” ]
End If
End If
#
#Insert the user and workout keys.
Set Field [ planlog::kworkout; $workout ]
#
#Now clear all the time from this workout. This is done
January 8, 平成26 12:43:29 Fat and Muscle Efﬁciency Research.fp7 - FillPlanSlotWithWorkout -1-editCreateWorkout: editorButtons: FillPlanSlotWithWorkout
#because the summary field that calculates time in zone
#is set to add up al these times and the workout time
#from any related workouts. So to insure only the related
#workout's time is used these fields must be cleared.
Set Field [ planlog::z1hour; "" ]
Set Field [ planlog::z1minute; "" ]
Set Field [ planlog::z1second; "" ]
Set Field [ planlog::z2hour; "" ]
Set Field [ planlog::z2minute; "" ]
Set Field [ planlog::z2second; "" ]
Set Field [ planlog::z3hour; "" ]
Set Field [ planlog::z3minute; "" ]
Set Field [ planlog::z3second; "" ]
Set Field [ planlog::z4hour; "" ]
Set Field [ planlog::z4minute; "" ]
Set Field [ planlog::z4second; "" ]
Set Field [ planlog::z5hour; "" ]
Set Field [ planlog::z5minute; "" ]
Set Field [ planlog::z5second; "" ]
Go to Field [ ]
#
#If user is on iphone there is a bug that prevents
#calc of precentages unless all records are re-found.
If [ PatternCount ( Get ( ApplicationVersion ) ; "GO" ) ]
Enter Find Mode [ ]
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::plannedOrPerformed; "planning" ]
Perform Find [ ]
End If
#
#Set variables to conditionally format current record.
Set Variable [ $$recordPlan; Value:Get ( RecordID ) ]
Refresh Window
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Set Variable [ $$stopiphone ]
#
January 8, 平成26 12:43:29 Fat and Muscle Efﬁciency Research.fp7 - FillPlanSlotWithWorkout -2-
