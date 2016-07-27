action buttons: allSolutionsMenu
#PURPOSE go to all solutions menu.
#
#
#
#1 go to the edit/create layout and show all users.
Close Window [ Name: "All Solutions"; Current file ]
New Window [ Name: "All Solutions" ]
Go to Layout [ “allSolutionsMenu” (steward) ]
Show All Records
#
#Size window to 100%
Set Zoom Level
[ 100% ]
Adjust Window
[ Resize to Fit ]
#
#
If [ MemorySwitch::name = "" ]
Show Custom Dialog [ Message: "Click the folder icon (top left corner) and to start a library and add it to this quick-start menu.";
Buttons: “OK” ]
End If
#
#Set variable that will close this other apps menu
#when the user selectes a new database.
Set Variable [ $$otherApps; Value:1 ]
Pause/Resume Script [ Indefinitely ]
July 26, ଘ౮28 14:07:24 ActionLog.fp7 - allSolutionsMenu -1-
