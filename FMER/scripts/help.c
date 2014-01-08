help
#
#
#This step is required or else the main FMER window
#will remain hidden behind the timer window if open.
// Close Window [ Name: "Help" ]
#
#Set back path from help to this solution.
Set Field [ MemorySwitch::backToSolution; "FMER" ]
#
#Users, Exercises and Conditions help screen
If [ Get (LayoutName) = "Proﬁle" ]
Set Field [ MemorySwitch::helpLayoutName; "Users, Exercises and Conditions" ]
Set Field [ MemorySwitch::helpObjectName; "" ]
#
#Select, Do, Log workout help screen
Else If [ Left (Get (LayoutName) ; 4 ) = "user" ]
Set Field [ MemorySwitch::helpLayoutName; "Select, Do, Log Workouts" ]
Set Field [ MemorySwitch::helpObjectName; "log" ]
#
Else If [ Get (LayoutName) = "selectWorkout" ]
Set Field [ MemorySwitch::helpLayoutName; "Select, Do, Log Workouts" ]
Set Field [ MemorySwitch::helpObjectName; "select" ]
#
Else If [ Get (LayoutName) = "doWorkout" ]
Set Field [ MemorySwitch::helpLayoutName; "Select, Do, Log Workouts" ]
Set Field [ MemorySwitch::helpObjectName; "do" ]
#
Else If [ Left (Get (LayoutName) ; 4 ) = "plan" ]
Set Field [ MemorySwitch::helpLayoutName; "Select, Do, Log Workouts" ]
Set Field [ MemorySwitch::helpObjectName; "planned" ]
#
#Plan, Create, Edit workout help screen
Else If [ Get (LayoutName) = "weekPlan" ]
Set Field [ MemorySwitch::helpLayoutName; "Edit/Create Workout" ]
Set Field [ MemorySwitch::helpObjectName; "plan" ]
#
Else If [ Left (Get (LayoutName) ; 4 ) = "Edit" ]
Set Field [ MemorySwitch::helpLayoutName; "Edit/Create Workout" ]
Set Field [ MemorySwitch::helpObjectName; "edit" ]
#
Else If [ Left (Get (LayoutName) ; 4 ) = "Icon" ]
Set Field [ MemorySwitch::helpLayoutName; "Edit/Create Workout" ]
Set Field [ MemorySwitch::helpObjectName; "icon" ]
#
End If
#
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; " " ;
"%20" ) ;
Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ;
4 ) ) ; "ﬁle:/" ; "ﬁle://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
January 8, 平成26 15:49:38 Fat and Muscle Efﬁciency Research.fp7 - help -1-help
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; " " ;
"%20" ) ;
Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ;
4 ) ) ; "ﬁle:/" ; "ﬁle://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
Open URL [ Substitute ( Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" &
Right ( Get (FilePath) ; 4 ) ) ; "ﬁle:/" ; "ﬁle://" ) ; " " ; "%20" ) ; "ﬁle://" ; "ﬁle:///Volumes/" ) ]
[ No dialog ]
#
Select Window [ Name: "Help" ]
Select Window [ Name: "Tutorial" ]
#
January 8, 平成26 15:49:38 Fat and Muscle Efﬁciency Research.fp7 - help -2-
