navigation: gotoHelp
#
#
#This step is required or else the main library window
#will remain hidden behind the timer window if open.
// Close Window [ Name: "Help" ]
#
#Set back path from help to this solution.
Set Field [ MemorySwitch::backToSolution; "ActionLog" ]
#
If [ Get (LayoutName) = "users" ]
Set Field [ MemorySwitch::helpLayoutName; "dashboard" ]
Set Field [ MemorySwitch::helpObjectName; "" ]
#
Else If [ Get (LayoutName) = "01Main" ]
Set Field [ MemorySwitch::helpLayoutName; "timer" ]
Set Field [ MemorySwitch::helpObjectName; "" ]
#
Else If [ Get (LayoutName) = "01editTime" ]
Set Field [ MemorySwitch::helpLayoutName; "timer edit" ]
Set Field [ MemorySwitch::helpObjectName; "" ]
#
Else If [ Get (LayoutName) = "Issues" ]
Set Field [ MemorySwitch::helpLayoutName; "Speciﬁc Action" ]
Set Field [ MemorySwitch::helpObjectName; "speciﬁc action" ]
#
Else If [ Left (Get (LayoutName) ; 3 ) = "log" ]
Set Field [ MemorySwitch::helpLayoutName; "Speciﬁc Action" ]
Set Field [ MemorySwitch::helpObjectName; "day" ]
#
Else If [ Get (LayoutName) = "IssuesAndObservationsTag" ]
Set Field [ MemorySwitch::helpLayoutName; "Speciﬁc Action" ]
Set Field [ MemorySwitch::helpObjectName; "add" ]
#
Else If [ Get (LayoutName) = "IssuesAndObservationsOrder" ]
Set Field [ MemorySwitch::helpLayoutName; "Speciﬁc Action" ]
Set Field [ MemorySwitch::helpObjectName; "order" ]
#
Else If [ Get (LayoutName) = "IssuesAndObservationsFIND" ]
Set Field [ MemorySwitch::helpLayoutName; "Speciﬁc Action" ]
Set Field [ MemorySwitch::helpObjectName; "ﬁnd" ]
End If
#
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; " " ; "%20" ) ;
Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ;
"ﬁle:/" ; "ﬁle://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
Open URL [ Substitute ( Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get
(FilePath) ; 4 ) ) ; "ﬁle:/" ; "ﬁle://" ) ; " " ; "%20" ) ; "ﬁle://" ; "ﬁle:///Volumes/" ) ]
[ No dialog ]
#
Select Window [ Name: "Help" ]
Select Window [ Name: "Tutorial" ]
#
#
January 5, 平成26 14:21:53 ActionLog.fp7 - gotoHelp -1-
