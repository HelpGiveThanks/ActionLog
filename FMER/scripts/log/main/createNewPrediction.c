log: main: createNewPrediction
Show Custom Dialog [ Message: "Would you like to make a new predition to test your body against like, \"Comfortably hike hills after
these next weeks of exercises\" or keep the selected prediction or delete the current prediction? "; Buttons: “keep”, “new”,
“delete” ]
If [ Get (LastMessageChoice) = 1 ]
Go to Field [ ]
Go to Object [ Object Name: "prediction" ]
Exit Script [ ]
Else If [ Get (LastMessageChoice) = 2 ]
Go to Field [ ]
New Window [ ]
Go to Layout [ “predictionTag” (prediction 3) ]
New Record/Request
Set Field [ prediction 3::kuser; planlog::kuserGlobal ]
Set Variable [ $prediction; Value:prediction 3::_Lprediction ]
Set Field [ prediction 3::name; "Easily do X after these next weeks of workouts. " & prediction 3::_Lprediction ]
Close Window [ Current Window ]
Set Field [ week::kprediction; $prediction ]
Go to Object [ Object Name: "prediction" ]
Else If [ Get (LastMessageChoice) = 3 ]
Set Field [ week::kprediction; "" ]
Go to Field [ ]
End If
January 8, 平成26 12:12:05 Fat and Muscle Efﬁciency Research.fp7 - createNewPrediction -1-
