action buttons: newDayTimerSetup
#PURPOSE create/change birthday Day record.
#
#If this is the new day timer...
If [ timer::newDayTimer ≠ "" ]
#
#Explain how to set up this timer, and help the
#user set it up.
Show Custom Dialog [ Message: "Enter your date of birth so that this program can calculate your new day number, every day.";
Buttons: “OK”, “cancel”; Input #1: user::birthday, "use date format: 01/01/1900" ]
#
#If user does not want to then exit the script
#after telling them that this timer can only be
#used to show days since their birth, and that
#it can be retired if they don't want to see it.
If [ Get ( LastMessageChoice ) = 2 ]
Show Custom Dialog [ Message: "This timer can only be used to show your current day of life. If you don't want it to see it,
click 'edit' and then click its retire checkbox to hide it."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#If the user entered in an invalid date or
#entered the date in the wrong format, then
#tell the user this and give them opportunity
#to enter it as required.
If [ IsValid ( user::birthday ) ≠ 1 ]
Loop
Exit Loop If [ IsValid ( user::birthday ) = 1 ]
#
#Explain how to set up this timer, and help the
#user set it up.
Show Custom Dialog [ Message: "Date format entered won't work. You must use this date format: 01/01/1900.";
Buttons: “OK”, “cancel”; Input #1: user::birthday, "use date format: 01/01/1900" ]
#
#If user does not want to then exit the script
#after telling them that this timer can only be
#used to show days since their birth, and that
#it can be retired if they don't want to see it.
If [ Get ( LastMessageChoice ) = 2 ]
Show Custom Dialog [ Message: "This timer can only be used to show your current day of life. If you don't want it
to see it, click 'edit' and then click its retire checkbox to hide it."; Buttons: “OK” ]
Exit Script [ ]
End If
End Loop
End If
#
#Once the user has entered their birthday
#correctly then create a new day record on
#their birthday assigned to the new day timer.
Set Variable [ $birthday; Value:user::birthday ]
Set Field [ timer::DateOfLastUse; $birthday ]
Commit Records/Requests
New Window [ ]
Go to Layout [ “DayTable” (day1) ]
New Record/Request
Set Field [ day1::log; "Hello World!" ]
Set Field [ day1::_keyDay; $birthday ]
Set Field [ day1::_keyTimer; $$timerIDnumber ]
Set Field [ day1::_keyUser; reference::userID ]
Set Field [ day1::swStart; Get ( CurrentTimeStamp ) ]
Set Field [ day1::swPause; Get ( CurrentTimeStamp ) ]
Close Window [ Current Window ]
End If
#
#
December 10, ଘ౮28 23:40:25 ActionLog.fp7 - newDayTimerSetup -1-
