planned workouts: main: orderPlannedWorkouts
Set Variable [ $week; Value:planlog::kweek ]
Set Variable [ $prediction; Value:week::kprediction ]
Set Variable [ $order; Value:week::Order ]
Go to Field [ ]
If [ $prediction = "" ]
Show Custom Dialog [ Message: "gdhgfd"; Buttons: “OK” ]
Exit Script [ ]
End If
New Window [ ]
Go to Layout [ “weekTag” (week) ]
Enter Find Mode [ ]
Set Field [ week::kprediction; $prediction ]
Perform Find [ ]
Sort Records [ Specified Sort Order: week::Order; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ week::Order = $order ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ week::Order = $order and week::_Lweek = $week ]
Go to Record/Request/Page
[ Next ]
If [ Get (LastError) ≠ 0 or week::Order ≠ $order ]
Perform Script [ “CHUNKorderFrom1” ]
Go to Object [ Object Name: "prediction" ]
Exit Script [ ]
Else If [ week::Order = $order ]
Loop
Set Variable [ $order; Value:$order + 1 ]
Set Field [ week::Order; $order ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Perform Script [ “CHUNKorderFrom1” ]
Go to Object [ Object Name: "prediction" ]
Exit Script [ ]
End If
End If
#
If [ week::Order = $order and week::_Lweek ≠ $week ]
Set Field [ week::Order; $order - 1 ]
End If
#
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ week::Order = $order ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
January 8, 平成26 12:32:10 Fat and Muscle Efﬁciency Research.fp7 - orderPlannedWorkouts -1-planned workouts: main: orderPlannedWorkouts
If [ week::Order = $order and week::_Lweek = $week ]
Go to Record/Request/Page
[ Next ]
If [ Get (LastError) ≠ 0 or week::Order ≠ $order ]
Perform Script [ “CHUNKorderFrom1” ]
Go to Object [ Object Name: "prediction" ]
Exit Script [ ]
Else If [ week::Order = $order ]
Loop
Set Variable [ $order; Value:$order + 1 ]
Set Field [ week::Order; $order ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
End If
Perform Script [ “CHUNKorderFrom1” ]
Go to Object [ Object Name: "prediction" ]
January 8, 平成26 12:32:10 Fat and Muscle Efﬁciency Research.fp7 - orderPlannedWorkouts -2-
