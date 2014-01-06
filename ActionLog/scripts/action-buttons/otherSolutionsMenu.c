action buttons: otherSolutionsMenu
#PURPOSE go to other apps menu.
#
#
#
#1 go to the edit/create layout and show all users.
Close Window [ Name: "Other Solutions"; Current ﬁle ]
New Window [ Name: "Other Solutions" ]
Go to Layout [ “users Copy3” (steward) ]
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
Pause/Resume Script [ Indeﬁnitely ]
January 5, 平成26 19:55:08 ActionLog.fp7 - otherSolutionsMenu -1-
