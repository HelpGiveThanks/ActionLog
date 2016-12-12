start close: start
#
#
#Save out graphic objects to external folder
#for reference in graphs.
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
#Go to the user layout.
Go to Layout [ “users” (user) ]
Show All Records
Sort Records [ Specified Sort Order: user::FirstName; ascending
user::LastName; ascending ]
[ Restore; No dialog ]
If [ user::windowZoom = 150 ]
Set Zoom Level
[ 100% ]
Else If [ user::windowZoom = 200 ]
Set Zoom Level
[ 100% ]
Else If [ user::windowZoom = 300 ]
Set Zoom Level
[ 100% ]
Else If [ user::windowZoom = 400 ]
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
#
#Close Timer, Specific Action, Day, and Tag
#windows if user is restarting solution.
Close Window [ Name: "Timer"; Current file ]
Close Window [ Name: "Specific Action"; Current file ]
Close Window [ Name: "Day"; Current file ]
Close Window [ Name: "Tag"; Current file ]
Close Window [ Name: "Temp"; Current file ]
Close Window [ Name: ""; Current file ]
#
#Insure user is running compatable versiona
#the reference and MyData files.
If [ reference::version ≠ "3.2b BETA" ]
Show Custom Dialog [ Message: "You need to download the file 'reference, version 3.2b BETA' for version 3.2b BETA of the
ActionLog."; Buttons: “OK” ]
End If
#
If [ backup::version ≠ "3.2b BETA" ]
Show Custom Dialog [ Message: "You need to download the file 'MyData, version 3.2b BETA' for version 3.2b BETA of the
ActionLog."; Buttons: “OK” ]
End If
#
#
December 11, ଘ౮28 21:41:36 ActionLog.fp7 - start -1-
