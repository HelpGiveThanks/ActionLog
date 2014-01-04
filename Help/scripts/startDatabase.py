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
#Check if database is being started by administrator.
#If it is then show admin tools.
If [ Get ( AccountName ) = "admin" ]
Set Variable [ $$admin; Value:1 ]
End If
#
#Set name of window to help and size to Þt window.
Set Window Title [ Current Window; New Title: "Help" ]
Adjust Window
[ Resize to Fit ]
Go to Layout [ MemorySwitch::helpLayoutName ]
#
#If there is no pause the script fails to work.  
Pause/Resume Script [ Duration (seconds): .1 ]
Go to Object [ Object Name: MemorySwitch::helpObjectName ]
Go to Field [ ]
#
January 4, ??26 12:27:35 help.fp7 - startDatabase -1-