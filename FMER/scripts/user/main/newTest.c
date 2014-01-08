user: main: newTest
#
If [ exerciseMHR::kuser = "" ]
Perform Script [ “newHuman” ]
Exit Script [ ]
End If
#
Set Variable [ $user; Value:exerciseMHR::kuser ]
#
Go to Layout [ original layout ]
#
New Record/Request
Set Field [ exerciseMHR::kuser; $user ]
#
Sort Records [ Specified Sort Order: user::name; ascending ]
[ Restore; No dialog ]
Go to Field [ ]
January 8, 平成26 12:06:05 Fat and Muscle Efﬁciency Research.fp7 - newTest -1-
