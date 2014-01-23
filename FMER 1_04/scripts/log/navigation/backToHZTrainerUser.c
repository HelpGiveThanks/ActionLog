log: navigation: backToHZTrainerUser
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
Close Window [ Name: "Planned Workouts"; Current file ]
Close Window [ Name: "Icons"; Current file ]
Close Window [ Name: "Select Workout"; Current file ]
Close Window [ Name: "Workout Editor"; Current file ]
Close Window [ Name: "Plan Week"; Current file ]
Set Window Title [ Current Window; New Title: "Fat and Muscle Efﬁciency Research" ]
#
Go to Layout [ “Proﬁle” (exerciseMHR) ]
#
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ planlog::kuserGlobal = user::_Luser ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
January 8, 平成26 12:20:21 Fat and Muscle Efﬁciency Research.fp7 - backToHZTrainerUser -1-
