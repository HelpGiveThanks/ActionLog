navigation: total: goAndComeBackPart1Total
#PURPOSE prevent huge time delay. (For some reason, when you select a new value in the go or scale dropdown lists, filemaker goes into a
lengthy re-calc of all the barcharts on the layout, even though these drop downs are not connected in anyway with any of the record being
calculated. To prevent this form happening, this script makes filemaker freeze the window and go to another layout. This other layout has
a script layout trigger that causes the user to be returned to the layout that they just left. This back and forth between layouts seems to
stop the recalc process from occuring.)
#
#
#
#1 capture layout name for bounceback part 2 and then freeze window and go to bounce back layout.
Set Variable [ $$layoutTotal; Value:Get ( LayoutName ) ]
Freeze Window
Go to Layout [ “bounceBackUtilityLayoutTotal” (brainstate) ]
January 5, 平成26 19:24:55 ActionLog.fp7 - goAndComeBackPart1Total -1-
