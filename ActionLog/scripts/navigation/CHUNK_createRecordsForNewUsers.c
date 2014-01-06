navigation: CHUNK_createRecordsForNewUsers
#PURPOSE check to make sure that the user has records and if not create a record for the user
#CHUNK USED BY goBackButton script
#CHUNK USED BY goToFarmer script
#
#
#
#NOTE: the three # symbols set apart chunks of script.
#NOTE: the ﬁnish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason,
they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $userID; Value:reference::farmerID ]
#
#
#
#1 ﬁnd this user's brainstate records
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
#
#2 if the user has no records, create a new one and assign it to the user so that there name will show up. (All the layouts are tied to the
brainstate table not the user table. So the only way to show a user name and all the correct formating attributes is to have one user
record.)
If [ Get ( FoundCount ) = 0 ]
Set Variable [ $actionNames; Value:"sleep" & ¶ &
"exercise brain" & ¶ &
"exercise body" & ¶ &
"decrease confusion" & ¶ &
"note learning" & ¶ &
"break" & ¶ &
"prepare" & ¶ &
//"travel" & ¶ &
"send and receive" & ¶ &
"study others" & ¶ &
"new day" & ¶ ]
Set Variable [ $actionOrderNumber; Value:1 & ¶ &
2 & ¶ &
4 & ¶ &
5 & ¶ &
7 & ¶ &
8 & ¶ &
10 & ¶ &
//12 & ¶ &
13 & ¶ &
15 & ¶ &
16 & ¶ ]
Set Variable [ $number; Value:1 ]
Loop
New Record/Request
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::hide; "t" & ¶ ]
Set Field [ brainstate::description; GetValue ( $actionNames ; $number ) ]
Set Field [ brainstate::sortNumber; GetValue ( $actionOrderNumber ; $number ) ]
Set Variable [ $number; Value:$number + 1 ]
Exit Loop If [ $number = 11 ]
End Loop
#
Set Variable [ $kpnBrainstateID; Value:brainstate::_lockBrainstateID ]
January 5, 平成26 19:14:42 ActionLog.fp7 - CHUNK_createRecordsForNewUsers -1-navigation: CHUNK_createRecordsForNewUsers
Go to Layout [ “calcDayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyBrainstate; $kpnBrainstateID ]
Set Field [ day1::_keyUser; $userID ]
// Set Field [ day1::_keyDay; reference::day1 ]
Set Field [ day1::swStart; Get ( CurrentTimeStamp ) ]
Set Field [ day1::swPause; Get ( CurrentTimeStamp ) ]
Show Custom Dialog [ Message: "Enter your date of birth so that this program can calculate your new day number, every day."; Buttons:
“OK”; Input #1: day1::_keyDay, "use date format: 01/01/1900" ]
Commit Records/Requests
If [ IsValid ( day1::_keyDay ) ≠ 1 ]
Show Custom Dialog [ Message: "Enter your date of birth so that this program can calculate your new day number, every day. Use
must enter a valid date using this format: 00/00/0000."; Buttons: “OK”; Input #1: day1::_keyDay, "use date format: 01/01/1900" ]
Commit Records/Requests
End If
Set Variable [ $dateOfLastUse; Value:day1::_keyDay ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Set Field [ brainstate::DateOfLastUse; $dateOfLastUse ]
End If
#
January 5, 平成26 19:14:42 ActionLog.fp7 - CHUNK_createRecordsForNewUsers -2-
