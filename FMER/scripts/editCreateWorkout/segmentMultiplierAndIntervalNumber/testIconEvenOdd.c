editCreateWorkout: segmentMultiplierAndIntervalNumber: testIconEvenOdd
Set Variable [ $number; Value:Right ( Get ( ActiveFieldTableName ) ; 1 ) ]
Go to Object [ Object Name: "multiplier" & $number ]
Set Variable [ $evenOdd; Value:Get ( ActiveFieldContents ) ]
Go to Object [ Object Name: "number" & $number ]
If [ If(Mod(Get(ActiveFieldContents);2) = 0;"even";"odd") ≠ $evenOdd ]
Set Field [ "" ]
Show Custom Dialog [ Message: "This icon requires an " & $evenOdd & " number to ﬁnish up with a heart rate that will end up
where the icons line ends up."; Buttons: “OK” ]
Exit Script [ ]
End If
Go to Field [ ]
January 8, 平成26 15:48:15 Fat and Muscle Efﬁciency Research.fp7 - testIconEvenOdd -1-
