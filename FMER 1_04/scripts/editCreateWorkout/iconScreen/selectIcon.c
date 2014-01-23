editCreateWorkout: iconScreen: selectIcon
If [ $$icon ≠ IconsForGrid::aboutIcone ]
Set Variable [ $$icon; Value:Get(ActiveFieldContents) ]
Else If [ $$icon = IconsForGrid::aboutIcone ]
Set Variable [ $$icon ]
End If
Go to Field [ ]
If [ $$showSelection ≠ "" ]
Refresh Window
Select Window [ Name: "Workout Editor"; Current file ]
Else
Select Window [ Name: "Workout Editor"; Current file ]
End If
January 8, 平成26 15:43:26 Fat and Muscle Efﬁciency Research.fp7 - selectIcon -1-
