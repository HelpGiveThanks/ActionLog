navigation: gotoDatabaseFMER
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
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "ﬁle:/" ; "ﬁle:/" )
& "Fat and Muscle Efﬁciency Research." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "ﬁle:/" ; "ﬁle://" )
& "Fat and Muscle Efﬁciency Research." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ) ]
[ No dialog ]
If [ Get (LastError) = 5 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "ﬁle:/" ; "ﬁle:/" )
& "Fat and Muscle Efﬁciency Research.USR"
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "ﬁle:/" ; "ﬁle://" )
& "Fat and Muscle Efﬁciency Research.USR"
 ; " " ; "%20" ) ) ]
[ No dialog ]
End If
End If
#
#Close other apps window if open after selecting an app.
If [ $$otherApps = 1 ]
Close Window [ Name: "Other Apps"; Current ﬁle ]
End If
January 5, 平成26 14:23:18 ActionLog.fp7 - gotoDatabaseFMER -1-
