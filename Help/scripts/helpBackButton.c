helpBackButton
#
#
If [ MemorySwitch::backToSolution = "Library" ]
Perform Script [ “CHUNK_backToLibrary” ]
Else If [ MemorySwitch::backToSolution = "ActionLog" ]
// Set Field [ MemorySwitch::currentLibraryMainWIndow; Get ( WindowName ) ]
// Set Field [ MemorySwitch::currentLibraryPath; Get ( FilePath ) ]
Select Window [ Name: "Tag" ]
Select Window [ Name: "Day" ]
Select Window [ Name: "Speciﬁc Action" ]
Select Window [ Name: "Timer" ]
If [ Get (LastError) = 112 ]
Set Variable [ $timer; Value:Get (LastError) ]
End If
Select Window [ Name: "HelpGiveThanks Apps" ]
If [ Get (LastError) = 112 ]
Set Variable [ $app; Value:Get (LastError) ]
End If
If [ $timer + $app = 224 ]
Open URL [ Substitute ( MemorySwitch::helpPath ; "help" ; "actionLog81" ) ]
[ No dialog ]
Open URL [ Substitute ( MemorySwitch::helpPath ; "help" ; "actionLog" ) ]
[ No dialog ]
End If
Else If [ MemorySwitch::backToSolution = "FMER" ]
If [ MemorySwitch::helpLayoutName = "Select, Do, Log Workouts" ]
Select Window [ Name: "Select Workout" ]
Select Window [ Name: "Workout" ]
Select Window [ Name: "Icons" ]
Select Window [ Name: "Plan Week" ]
Select Window [ Name: "Workout Editor" ]
Select Window [ Name: "Planned Workouts" ]
Select Window [ Name: "My Workouts" ]
If [ MemorySwitch::helpObjectName = "select" ]
Select Window [ Name: "Select Workout" ]
Else If [ MemorySwitch::helpObjectName = "do" ]
Select Window [ Name: "Select Workout" ]
Select Window [ Name: "Workout" ]
Else If [ MemorySwitch::helpObjectName = "planned" ]
Select Window [ Name: "Planned Workouts" ]
End If
Else If [ MemorySwitch::helpLayoutName = "Edit/Create Workout" ]
Select Window [ Name: "My Workouts" ]
Select Window [ Name: "Planned Workouts" ]
Select Window [ Name: "Select Workout" ]
Select Window [ Name: "Workout" ]
Select Window [ Name: "Icons" ]
Select Window [ Name: "Plan Week" ]
Select Window [ Name: "Workout Editor" ]
If [ MemorySwitch::helpObjectName = "icon" ]
Select Window [ Name: "Icons" ]
Else If [ MemorySwitch::helpObjectName = "select" ]
Select Window [ Name: "Select Workout" ]
Else If [ MemorySwitch::helpObjectName = "plan" ]
Select Window [ Name: "Plan Week" ]
Else If [ MemorySwitch::helpObjectName = "do" ]
Select Window [ Name: "Select Workout" ]
Select Window [ Name: "Workout" ]
End If
Else If [ MemorySwitch::helpLayoutName = "Users, Exercises and Conditions" ]
Select Window [ Name: "Fat and Muscle Efﬁciency Research" ]
End If
Else If [ MemorySwitch::backToSolution = "Budget Research" ]
If [ MemorySwitch::helpLayoutName = "Users and Budgets" ]
Select Window [ Name: "Budget Research" ]
Else If [ MemorySwitch::helpLayoutName = "Income = In" ]
Select Window [ Name: "Budget Research" ]
Else If [ MemorySwitch::helpLayoutName = "Purchases = Out" ]
Select Window [ Name: "Budget Research" ]
End If
#
#
If [ Get (LastError) = 112 ]
Set Variable [ $timer; Value:Get (LastError) ]
End If
Select Window [ Name: "HelpGiveThanks Apps" ]
If [ Get (LastError) = 112 ]
Set Variable [ $app; Value:Get (LastError) ]
End If
If [ $timer + $app = 224 ]
Open URL [ Substitute ( MemorySwitch::helpPath ; "help" ; "actionLog82" ) ]
[ No dialog ]
Open URL [ Substitute ( MemorySwitch::helpPath ; "help" ; "actionLog" ) ]
[ No dialog ]
End If
End If
#
#
#
#
// #This script functions like a browsers back button
// #script, taking users back thru help windows bread
// #crumb style.
// If [ ValueCount ( tutorial::layoutName ) = 1 ]
// Exit Script [ ]
// Else
// Set Field [ tutorial::layoutName; Substitute ( tutorial::layoutName ; LeftValues (tutorial::layoutName ; 1 ) ; "" ) ]
// Set Variable [ $value1; Value:GetValue ( tutorial::layoutName ; 1 ) ]
// Go to Layout [ $value1 ]
// End If
January 4, 平成26 18:57:07 help.fp7 - helpBackButton -1-
