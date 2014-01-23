gotoHelp
#
#Set back path from help to this solution.
Set Field [ MemorySwitch::backToSolution; "Budget Research" ]
#
If [ Get (LayoutName) = "Budget" ]
Set Field [ MemorySwitch::helpLayoutName; "Users and Budgets" ]
Set Field [ MemorySwitch::helpObjectName; "" ]
#
Else If [ Left ( Get (LayoutName) ; 1 ) = "P" or
Left ( Get (LayoutName) ; 2 ) = "St" ]
Set Field [ MemorySwitch::helpLayoutName; "Purchases = Out" ]
Set Field [ MemorySwitch::helpObjectName; "" ]
#
Else If [ Left ( Get (LayoutName) ; 1 ) = "I" or
Left ( Get (LayoutName) ; 2 ) = "Sc" ]
Set Field [ MemorySwitch::helpLayoutName; "Income = In" ]
Set Field [ MemorySwitch::helpObjectName; "" ]
#
End If
#
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; " " ; "%20" ) ;
Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; "ﬁle:/" ; "ﬁle://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
Open URL [ Substitute ( Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; "ﬁle:/" ; "ﬁle:
//" ) ; " " ; "%20" ) ; "ﬁle://" ; "ﬁle:///Volumes/" ) ]
[ No dialog ]
#
Select Window [ Name: "Help" ]
Select Window [ Name: "Tutorial" ]
#
#
January 8, 平成26 19:13:28 Budget Research.fp7 - gotoHelp -1-
