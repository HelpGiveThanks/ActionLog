start close: start
#PURPOSE save out graphic objects to external folder for reference in graphs and then go to the user layout
#
#
#1 save out graphic objects to external folder for reference in graphs
Set Variable [ $path; Value:"file:" & Get(TemporaryPath) & "1.gif" ]
Export Field Contents [ reference::gResources; “$path” ]
Set Variable [ $path; Value:"file:" & Get(TemporaryPath) & "2.gif" ]
Export Field Contents [ reference::gResources[3]; “$path” ]
#
#Recalculate help filepath. To do this,
#filemaker must create a new record which
#can then be deleted. The help filepath is a
#global record, and that means the
#recaclucated path will now be used for all
#memoryswitch records and scripts needing
#this path.
Go to Layout [ “MemorySwitch” (MemorySwitch) ]
New Record/Request
Delete Record/Request
[ No dialog ]
#
#Set version number.
Set Field [ MemorySwitch::versionActionLog; version::version ]
#
#2 go to the user layout
Go to Layout [ “users” (steward) ]
Show All Records
Sort Records [ Specified Sort Order: steward::FirstName; ascending
steward::LastName; ascending ]
[ Restore; No dialog ]
If [ steward::windowZoom = 150 ]
Set Zoom Level
[ 100% ]
Else If [ steward::windowZoom = 200 ]
Set Zoom Level
[ 100% ]
Else If [ steward::windowZoom = 300 ]
Set Zoom Level
[ 100% ]
Else If [ steward::windowZoom = 400 ]
Set Zoom Level
[ 100% ]
End If
// Adjust Window
[ Maximize ]
Adjust Window
[ Resize to Fit ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) * .8; Top: Get (ScreenHeight) * .05; Left: Get (ScreenWidth)
* .1 ]
Set Window Title [ Current Window; New Title: "HelpGiveThanks Solutions" ]
#
#Show regular menus if Admin logs in only.
Show/Hide Text Ruler
[ Hide ]
If [ Get ( AccountName ) = "Admin" ]
Show/Hide Status Area
[ Hide ]
Install Menu Set [ “[Standard FileMaker Menus]” ]
Else
Show/Hide Status Area
[ Lock; Hide ]
End If
July 13, ଘ౮28 13:03:19 ActionLog.fp7 - start -1-
