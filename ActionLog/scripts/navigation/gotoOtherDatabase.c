navigation: gotoOtherDatabase
Show Custom Dialog [ Message: "Open the Fat and Muscle Efficiency Research (FMER) application or the Budget Research application?";
Buttons: “cancel”, “Budget”, “FMER” ]
If [ Get (LastMessageChoice) = 1 ]
Else If [ Get (LastMessageChoice) = 2 ]
Select Window [ Name: "Budget Research" ]
If [ Get (LastError) = 112 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" )
& "Budget Research." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" )
& "Budget Research." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ) ]
[ No dialog ]
If [ Get (LastError) = 5 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" )
& "Budget Research.USR"
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" )
& "Budget Research.USR"
 ; " " ; "%20" ) ) ]
[ No dialog ]
End If
End If
Else If [ Get (LastMessageChoice) = 3 ]
Select Window [ Name: "Icons" ]
Select Window [ Name: "Workout Editor" ]
Select Window [ Name: "Plan Week" ]
Select Window [ Name: "My Workouts" ]
Select Window [ Name: "Planned Workouts" ]
If [ MemorySwitch::fatPath = "Workout Editor" ]
Select Window [ Name: "Icons" ]
Select Window [ Name: "Workout Editor" ]
Select Window [ Name: "Plan Week" ]
Else If [ MemorySwitch::fatPath = "Plan Week" ]
Select Window [ Name: "Icons" ]
Select Window [ Name: "Workout Editor" ]
Select Window [ Name: "Plan Week" ]
Else If [ MemorySwitch::fatPath = "Icons" ]
Select Window [ Name: "Icons" ]
Select Window [ Name: "Workout Editor" ]
Select Window [ Name: "Plan Week" ]
Else If [ MemorySwitch::fatPath = "My Workouts" ]
Select Window [ Name: "My Workouts" ]
Select Window [ Name: "Planned Workouts" ]
Else If [ MemorySwitch::fatPath = "Planned Workouts" ]
Select Window [ Name: "My Workouts" ]
Select Window [ Name: "Planned Workouts" ]
End If
Select Window [ Name: MemorySwitch::fatPath ]
If [ Get (LastError) = 112 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" )
& "Fat and Muscle Efficiency Research." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" )
& "Fat and Muscle Efficiency Research." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ) ]
[ No dialog ]
January 5, 平成26 14:22:35 ActionLog.fp7 - gotoOtherDatabase -1-navigation: gotoOtherDatabase
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" )
& "Fat and Muscle Efficiency Research." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" )
& "Fat and Muscle Efficiency Research." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ) ]
[ No dialog ]
If [ Get (LastError) = 5 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" )
& "Fat and Muscle Efficiency Research.USR"
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" )
& "Fat and Muscle Efficiency Research.USR"
 ; " " ; "%20" ) ) ]
[ No dialog ]
End If
End If
End If
January 5, 平成26 14:22:35 ActionLog.fp7 - gotoOtherDatabase -2-
