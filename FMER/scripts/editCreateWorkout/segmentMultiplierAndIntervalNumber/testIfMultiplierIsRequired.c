editCreateWorkout: segmentMultiplierAndIntervalNumber: testIfMultiplierIsRequired
If [ $$stop ≠ "" ]
Exit Script [ ]
End If
Set Variable [ $object; Value:Get ( ActiveLayoutObjectName ) ]
Set Variable [ $$stopIconInsert; Value:1 ]
Set Variable [ $number; Value:Right ( Get ( ActiveLayoutObjectName ) ; 2 ) ]
Go to Object [ Object Name: "icon" & $number ]
Set Variable [ $$stopIconInsert ]
If [ Middle ( Get (ActiveFieldContents) ; 3 ; 4 ) ≠ "none" ]
Set Variable [ $$stop; Value:1 ]
Go to Object [ Object Name: $object & " copy" ]
Set Variable [ $$stop ]
Exit Script [ ]
End If
Set Variable [ $$stop ]
Go to Field [ ]
January 8, 平成26 15:46:34 Fat and Muscle Efﬁciency Research.fp7 - testIfMultiplierIsRequired -1-
