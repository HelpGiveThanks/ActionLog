action buttons: newUser
#
#Only create a new user record if there isn't
#one already created.
If [ Get (FoundCount) > 0 ]
Go to Field [ user::FirstName ]
Exit Script [ ]
End If
#
#Create a new user record.
New Record/Request
#
#Put cursor in name text box.
Go to Field [ user::FirstName ]
#
#Inform user on how to proceed.
Show Custom Dialog [ Message: "A unique user record has just been created for you. After you enter your name, click the grey
button to the right to start your time journal. Cheers!"; Buttons: “OK” ]
#
December 10, ଘ౮28 23:59:48 ActionLog.fp7 - newUser -1-
