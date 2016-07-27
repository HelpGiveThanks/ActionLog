navigation: CHUNK_createRecordsForNewUsers
#PURPOSE check to make sure that the user has records and if not create a record for the user
#CHUNK USED BY goBackButton script
#CHUNK USED BY goToFarmer script
#
#
#
#NOTE: the three # symbols set apart chunks of script.
#NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For
this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them
apart.
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
#1 find this user's brainstate records
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
#
#2 if the user has no records, create a new one and assign it to the user so that there name will show up. (All the layouts are tied to the
brainstate table not the user table. So the only way to show a user name and all the correct formating attributes is to have one
user record.)
If [ Get ( FoundCount ) = 0 ]
Set Variable [ $actionNames; Value:"sleep" & ¶ &
"TQM action" & ¶ &
"note learning" & ¶ &
"InBetween/Journal" & ¶ &
"watch media" & ¶ &
"break" & ¶ &
"exercise brain" & ¶ &
"exercise body" & ¶ &
"new day" & ¶ ]
Set Variable [ $actionOrderNumber; Value:1 & ¶ &
4 & ¶ &
4 & ¶ &
7 & ¶ &
7 & ¶ &
7 & ¶ &
10 & ¶ &
10 & ¶ &
23 & ¶ ]
Set Variable [ $actionOrderLetter; Value:"a" & ¶ &
"a" & ¶ &
"b" & ¶ &
"a" & ¶ &
"b" & ¶ &
"c" & ¶ &
"a" & ¶ &
"b" & ¶ &
"a" & ¶ ]
Set Variable [ $highlightLibrary; Value:"" & ¶ &
"" & ¶ &
"r" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ ]
Set Variable [ $highlightSpecificAction; Value:"" & ¶ &
"r" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"r" & ¶ &
"r" & ¶ &
"" & ¶ ]
Set Variable [ $setDefaultSpecificAction; Value:"" & ¶ &
"1" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ ]
Set Variable [ $number; Value:1 ]
Loop
New Record/Request
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::hide; "t" & ¶ ]
Set Field [ brainstate::description; GetValue ( $actionNames ; $number ) ]
Set Field [ brainstate::sortNumber; GetValue ( $actionOrderNumber ; $number ) ]
Set Field [ brainstate::sortAlpha; GetValue ( $actionOrderLetter ; $number ) ]
Set Field [ brainstate::HighlightLibraryButton; GetValue ( $highlightLibrary ; $number ) ]
Set Field [ brainstate::HighlightSpecificActionButton; GetValue ( $highlightSpecificAction ; $number ) ]
If [ GetValue ( $setDefaultSpecificAction ; $number ) = 1 ]
Commit Records/Requests
Set Field [ steward::DefaultSpecificAction; brainstate::_lockBrainstateID ]
End If
Set Variable [ $number; Value:$number + 1 ]
Exit Loop If [ $number = 10 ]
End Loop
#
Set Variable [ $kpnBrainstateID; Value:brainstate::_lockBrainstateID ]
Go to Layout [ “calcDayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyBrainstate; $kpnBrainstateID ]
Set Field [ day1::_keyUser; $userID ]
Set Field [ day1::swStart; Get ( CurrentTimeStamp ) ]
Set Field [ day1::swPause; Get ( CurrentTimeStamp ) ]
Show Custom Dialog [ Message: "Enter your date of birth so that this program can calculate your new day number, every day.";
Buttons: “OK”; Input #1: day1::_keyDay, "use date format: 01/01/1900" ]
Commit Records/Requests
If [ IsValid ( day1::_keyDay ) ≠ 1 ]
Show Custom Dialog [ Message: "Enter your date of birth so that this program can calculate your new day number, every
day. Use must enter a valid date using this format: 00/00/0000."; Buttons: “OK”; Input #1: day1::_keyDay, "use date
format: 01/01/1900" ]
Commit Records/Requests
End If
Set Variable [ $dateOfLastUse; Value:day1::_keyDay ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Set Field [ brainstate::DateOfLastUse; $dateOfLastUse ]
End If
#
July 13, ଘ౮28 13:32:49 ActionLog.fp7 - CHUNK_createRecordsForNewUsers -1-
