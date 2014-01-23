startDatabase
#
#
Show/Hide Text Ruler
[ Hide ]
Show/Hide Status Area
[ Lock; Hide ]
#
#Report version number to Memory Switch Table.
Set Field [ MemorySwitch::versionHelp; tutorial::version ]
#
#Set name of window to help and size to ﬁt window.
Set Window Title [ Current Window; New Title: "Help" ]
Adjust Window
[ Resize to Fit ]
Go to Layout [ MemorySwitch::helpLayoutName ]
#
#Check if database is being started by administrator.
#If it is then show admin tools.
If [ Get ( AccountName ) = "admin" ]
Set Variable [ $$admin; Value:1 ]
Show/Hide Status Area
[ Hide ]
End If
#
#If there is no pause the script fails to work.
Pause/Resume Script [ Duration (seconds): .1 ]
Go to Object [ Object Name: MemorySwitch::helpObjectName ]
Go to Field [ ]
#
