navigation: gotoHelp
#
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action tag or click the cancel button in the Tag window. After you do this you
can open Help to learn about creating new specific-actions. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
#
#If triggered on the Other Solutions window then
#show a comment instead of opening the Help solultion.
If [ Get ( WindowName ) = "Other Solutions" ]
Show Custom Dialog [ Message: "This window is just buttons that open other solutions or the website. Click a button and your
solution will open."; Buttons: “OK” ]
Exit Script [ ]
End If
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
Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
Set Field [ MemorySwitch::helpObjectName; "specific action" ]
#
Else If [ Left (Get (LayoutName) ; 3 ) = "log" ]
Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
Set Field [ MemorySwitch::helpObjectName; "day" ]
#
Else If [ Get (LayoutName) = "IssuesAndObservationsTag" ]
Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
Set Field [ MemorySwitch::helpObjectName; "add" ]
#
Else If [ Get (LayoutName) = "IssuesAndObservationsOrder" ]
Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
Set Field [ MemorySwitch::helpObjectName; "order" ]
#
Else If [ Get (LayoutName) = "IssuesAndObservationsFIND" ]
Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
Set Field [ MemorySwitch::helpObjectName; "find" ]
End If
#
#Open the help solution and set the help screen to look at.
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; " " ;
"%20" ) ;
Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ;
4 ) ) ; "file:/" ; "file://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
Open URL [ Substitute ( Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" &
Right ( Get (FilePath) ; 4 ) ) ; "file:/" ; "file://" ) ; " " ; "%20" ) ; "file://" ; "file:///Volumes/" ) ]
[ No dialog ]
#
#If it is already open, then just go the currently open
#windows of the Help solution.
Select Window [ Name: "Help" ]
Select Window [ Name: "Tutorial" ]
#
#
December 6, ଘ౮27 20:27:41 ActionLog.fp7 - gotoHelp -1-
