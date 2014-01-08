editCreateWorkout: editorButtons: segmentRowButtons: CHUNKcheckIfRepeatingIconsMeet
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Two zone icon check calculations.
If [ Middle ( $$end ; 9 ; 1 ) = "b" and
Left ( $$continue ; 1 ) = "b" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier = $$continueMultiplier - .5 ;
$$endMultiplier - .5 = $$continueMultiplier - .5) ]
Exit Script [ ]
Else If [ Middle ( $$end ; 9 ; 1 ) = "b" and
Left ( $$continue ; 1 ) = "t" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier - 1 = $$continueMultiplier + .5 ;
$$endMultiplier - 1.5 = $$continueMultiplier + .5 ) ]
Exit Script [ ]
Else If [ Middle ( $$end ; 9 ; 1 ) = "t" and
Left ( $$continue ; 1 ) = "b" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier + 1 = $$continueMultiplier - .5 ;
$$endMultiplier + 1.5 = $$continueMultiplier - .5 ) ]
Exit Script [ ]
Else If [ Middle ( $$end ; 9 ; 1 ) = "t" and
Left ( $$continue ; 1 ) = "t" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier = $$continueMultiplier + .5 ;
$$endMultiplier = $$continueMultiplier ) ]
Exit Script [ ]
End If
#
#One zone icon check calculations.
If [ Middle ( $$end ; 9 ; 1 ) = "b" and
Left ( $$continue ; 1 ) = "b" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier = $$continueMultiplier ;
$$endMultiplier - .5 = $$continueMultiplier ) ]
Exit Script [ ]
Else If [ Middle ( $$end ; 9 ; 1 ) = "b" and
Left ( $$continue ; 1 ) = "t" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier - 1 = $$continueMultiplier ;
$$endMultiplier - 1.5 = $$continueMultiplier ) ]
Exit Script [ ]
Else If [ Middle ( $$end ; 9 ; 1 ) = "m" and
Left ( $$continue ; 1 ) = "m" and
$$endZone = $$continueZone ]
Exit Script [ ]
Else If [ Middle ( $$end ; 9 ; 1 ) = "t" and
Left ( $$continue ; 1 ) = "b" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier + 1 = $$continueMultiplier ;
$$endMultiplier + 1.5 = $$continueMultiplier ) ]
Exit Script [ ]
Else If [ Middle ( $$end ; 9 ; 1 ) = "t" and
Left ( $$continue ; 1 ) = "t" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier = $$continueMultiplier ;
$$endMultiplier + .5 = $$continueMultiplier ) ]
January 8, 平成26 15:39:00 Fat and Muscle Efﬁciency Research.fp7 - CHUNKcheckIfRepeatingIconsMeet -1-editCreateWorkout: editorButtons: segmentRowButtons: CHUNKcheckIfRepeatingIconsMeet
Else If [ Middle ( $$end ; 9 ; 1 ) = "t" and
Left ( $$continue ; 1 ) = "t" and
Case (
Length ( $$endZone ) = 1 ;
$$endMultiplier = $$continueMultiplier ;
$$endMultiplier + .5 = $$continueMultiplier ) ]
Exit Script [ ]
End If
#
#If all tests fail then icons do not connect. inform user
#and exit script.
Show Custom Dialog [ Message: "The two icons you have selected for this repeat do not match. Make sure the end of the icon for the
last segment above ﬂows into the ﬁrst icon for the repeat."; Buttons: “OK” ]
Set Variable [ $$stop ]
Set Variable [ $$end ]
Set Variable [ $$endZone ]
Set Variable [ $$endMultiplier ]
Set Variable [ $$continue ]
Set Variable [ $$continueZone ]
Set Variable [ $$continueMultiplier ]
Set Variable [ $$stopIconInsert ]
Halt Script
#
January 8, 平成26 15:39:00 Fat and Muscle Efﬁciency Research.fp7 - CHUNKcheckIfRepeatingIconsMeet -2-
