planned workouts: main: CHUNKorderFrom1
Go to Record/Request/Page
[ First ]
Sort Records [ Specified Sort Order: week::Order; ascending ]
[ Restore; No dialog ]
Set Field [ week::Order; 1 ]
Set Variable [ $order; Value:1 ]
If [ Get (FoundCount) = 1 ]
Close Window [ Current Window ]
Exit Script [ ]
End If
Go to Record/Request/Page
[ Next ]
Loop
Set Variable [ $order; Value:$order + 1 ]
Set Field [ week::Order; $order ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Close Window [ Current Window ]
January 8, 平成26 12:33:09 Fat and Muscle Efﬁciency Research.fp7 - CHUNKorderFrom1 -1-
