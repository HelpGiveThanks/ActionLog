editCreateWorkout: triggeredScripts: insertIcon
If [ $$stopIconInsert = 1 ]
Exit Script [ ]
End If
If [ $$icon ≠ "" ]
Set Field [ $$icon ]
Set Field [ activity::go; "" ]
Set Variable [ $$icon ]
Go to Field [ ]
Else If [ $$icon = "" and Get(ActiveFieldContents) ≠ "" ]
Set Variable [ $$icon; Value:Get(ActiveFieldContents) ]
Go to Field [ ]
Else If [ $$icon = "" and Get(ActiveFieldContents) = "" ]
Go to Field [ ]
Select Window [ Name: "Icons"; Current file ]
End If
January 8, 平成26 15:42:24 Fat and Muscle Efﬁciency Research.fp7 - insertIcon -1-
