action buttons: editFarmer
#PURPOSE go to createEdit farmer layout and show all users.
#
#
#
#1 go to the edit/create layout and show all users.
Go to Layout [ “users” (steward) ]
Show All Records
Close Window [ Name: "Day"; Current file ]
Close Window [ Name: "Specific Action"; Current file ]
Close Window [ Name: "Tag"; Current file ]
#
#Set window title.
Set Window Title [ Current Window; New Title: "HelpGiveThanks Solutions" ]
#
#Size and move window.
Set Zoom Level
[ 100% ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) * .8; Top: Get (ScreenHeight) * .05; Left: Get (ScreenWidth)
* .1 ]
July 26, ଘ౮28 14:05:35 ActionLog.fp7 - editFarmer -1-
