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
#Set variable that will close this other apps menu
#when the user selectes a new database.
Set Variable [ $$otherApps; Value:1 ]
Pause/Resume Script [ Indefinitely ]
February 1, 平成26 18:26:17 ActionLog.fp7 - allSolutionsMenu -1-
