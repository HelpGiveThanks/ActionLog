start
Go to Layout [ “budget” (budget) ]
Set Window Title [ Current Window; New Title: "Budget Research" ]
Set Zoom Level
[ 100% ]
#
#Report version number to Memory Switch Table.
Set Field [ MemorySwitch::versionBudget; Reference::version ]
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
Install Menu Set [ “Custom Menu Set 1” ]
End If
January 8, 平成26 18:44:18 Budget Research.fp7 - start -1-
