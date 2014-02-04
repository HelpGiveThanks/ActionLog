navigation: gotoDatabaseBudget
Select Window [ Name: "Budget Research" ]
If [ Get (LastError) = 112 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "ﬁle:/" ; "ﬁle:/" )
& "Budget Planner." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "ﬁle:/" ; "ﬁle://" )
& "Budget Planner." & Right ( Get ( FilePath ) ; 3 )
 ; " " ; "%20" ) ) ]
[ No dialog ]
If [ Get (LastError) = 5 ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "ﬁle:/" ; "ﬁle:/" )
& "Budget Research.HG2"
 ; " " ; "%20" ) ;
Substitute (
Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "ﬁle:/" ; "ﬁle://" )
& "Budget Research.HG2"
 ; " " ; "%20" ) ) ]
[ No dialog ]
End If
End If
#
#Close other apps window if open after selecting an app.
If [ $$otherApps = 1 ]
Set Variable [ $$otherApps ]
Close Window [ Name: "Other Solutions"; Current ﬁle ]
End If
February 4, 平成26 10:31:56 ActionLog.fp7 - gotoDatabaseBudget -1-