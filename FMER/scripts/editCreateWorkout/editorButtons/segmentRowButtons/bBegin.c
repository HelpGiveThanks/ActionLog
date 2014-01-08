editCreateWorkout: editorButtons: segmentRowButtons: bBegin
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Capture the segment number.
Set Variable [ $segment; Value:Right ( Get ( ActiveLayoutObjectName ) ; 2 ) ]
#
#If stop variable is not blank then exit script as this
#this script was just gone thru and needs stop or it
#it will keep going forever.
If [ $$stop ≠ "" ]
Exit Script [ ]
End If
#
#This script step insures that a workouts time
#cannot be modified and then used without re-totaling
#the workout first to take account of the modification.
Set Field [ activity::go; "" ]
#
#If field is occupied then clear it and exit script.
If [ Get ( ActiveFieldContents ) ≠ "" ]
Set Field [ "" ]
Go to Field [ ]
Exit Script [ ]
End If
#
#Exit script if aEnd is not set.
If [ activity::rowAend = "" ]
Go to Field [ ]
Show Custom Dialog [ Message: "Set the end segment for the ﬁrst row before setting the beginning segment for this second
row."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#If selected beginning happens after the end, tell user
#that this cannot make a repeat happen and exit sript.
If [ $segment > GetValue ( activity::rowAend ; 1 ) ]
Go to Field [ ]
Show Custom Dialog [ Message: "You have the 2nd row starting after the 1st row ends. These rows must overlap."; Buttons:
“OK” ]
Refresh Window
Exit Script [ ]
End If
#
#Stop icon load script to keep variables from being changed.
Set Variable [ $$stopIconInsert; Value:1 ]
#
#To prevent a logic loop set the stop variable to 1.
Set Variable [ $$stop; Value:1 ]
#
#Collect row ending icon information.
Go to Object [ Object Name: "icon" & GetValue ( activity::rowAend ; 1 ) ]
January 8, 平成26 12:54:59 Fat and Muscle Efﬁciency Research.fp7 - bBegin -1-editCreateWorkout: editorButtons: segmentRowButtons: bBegin
Set Variable [ $$end; Value:Get ( ActiveFieldContents ) ]
Go to Object [ Object Name: "zone" & GetValue ( activity::rowAend ; 1 ) ]
Set Variable [ $$endZone; Value:Get ( ActiveFieldContents ) ]
Set Variable [ $$endMultiplier; Value:Case (
$$endZone = 5 ; 5 ;
$$endZone = "4-5" ; 4.5 ;
$$endZone = 4 ; 4 ;
$$endZone = "3-4" ; 3.5 ;
$$endZone = 3 ; 3 ;
$$endZone = "2-3" ; 2.5 ;
$$endZone = 2 ; 2 ;
$$endZone = 1 ; 1 ;
 "" ) ]
#
#Collect row ending icon information.
Go to Object [ Object Name: "icon" & $segment ]
Set Variable [ $$continue; Value:Get ( ActiveFieldContents ) ]
Go to Object [ Object Name: "zone" & $segment ]
Set Variable [ $$continueZone; Value:Get ( ActiveFieldContents ) ]
Set Variable [ $$continueMultiplier; Value:Case (
$$continueZone = 5 ; 5 ;
$$continueZone = "4-5" ; 4.5 ;
$$continueZone = 4 ; 4 ;
$$continueZone = "3-4" ; 3.5 ;
$$continueZone = 3 ; 3 ;
$$continueZone = "2-3" ; 2.5 ;
$$continueZone = 2 ; 2 ;
$$continueZone = 1 ; 1 ;
 "" ) ]
#
#See of row ending fits with row ending icon.
Perform Script [ “CHUNKcheckIfRepeatingIconsMeet” ]
#
#Clear variables if it is fine.
Set Variable [ $$end ]
Set Variable [ $$endZone ]
Set Variable [ $$endMultiplier ]
Set Variable [ $$continue ]
Set Variable [ $$continueZone ]
Set Variable [ $$continueMultiplier ]
#
#Set new row ending.
Go to Object [ Object Name: "bBegin" & $segment ]
Set Field [ $segment & ¶ ]
Set Variable [ $$stop ]
Set Variable [ $$stopIconInsert ]
Go to Field [ ]
#
January 8, 平成26 12:54:59 Fat and Muscle Efﬁciency Research.fp7 - bBegin -2-
