navigation: CHUNK_loadORcreateTimersForUser
#
#CHUNK USED BY openActionLogs script
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $userID; Value:reference::userID ]
#
#Find this user's timer records.
Go to Layout [ “TimerTable” (timer) ]
Enter Find Mode [ ]
Set Field [ timer::_keyUser; $userID ]
Perform Find [ ]
#If the user has no records, create new ones
#and assign them to the user so that there
#name will show up.
If [ Get ( FoundCount ) = 0 ]
#
#First, create a set of variables with 7 values
#each that will be applied to each of the new 7
#timers as they are created.
#
#Set timer names.
Set Variable [ $actionNames; Value:"sleep" & ¶ &
"improve quality" & ¶ &
"note learning" & ¶ &
"in-between/journal" & ¶ &
"exercise brain" & ¶ &
"exercise body" & ¶ &
"new day" & ¶ ]
#Set timer order.
Set Variable [ $actionOrderNumber; Value:1 & ¶ &
4 & ¶ &
4 & ¶ &
7 & ¶ &
10 & ¶ &
10 & ¶ &
23 & ¶ ]
#Set timer alpha order.
Set Variable [ $actionOrderLetter; Value:"a" & ¶ &
"a" & ¶ &
"b" & ¶ &
"a" & ¶ &
"a" & ¶ &
"b" & ¶ &
"a" & ¶ ]
#Set 'in-between/journal' timer to highlight
#'note' button.
Set Variable [ $highlightNote; Value:"" & ¶ &
"" & ¶ &
"" & ¶ &
"r" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ ]
#Set 'note learning' timer to highlight
#'library' button.
Set Variable [ $highlightLibrary; Value:"" & ¶ &
"" & ¶ &
"r" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ ]
#Set 'improve quality', 'exercise brain', and
#exercise body' timers to highlight
#'specificaction' button.
Set Variable [ $highlightSpecificAction; Value:"" & ¶ &
"r" & ¶ &
"" & ¶ &
"" & ¶ &
"r" & ¶ &
"r" & ¶ &
"" & ¶ ]
#Set 'improve quality' timer to be the default
#timer which means that its specific actions
#are loaded at startup.
Set Variable [ $setDefaultSpecificAction; Value:"" & ¶ &
"1" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ ]
#Set 'new day' timer to only track user's
#birthday, so it always shows the current day
#the user is on.
Set Variable [ $setNewDay; Value:"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"" & ¶ &
"1" & ¶ ]
#
#Now in the second part of timer creation, all
#these variables are applied to each timer
#depending on what number it is in the
#sequence of timers that are now being
#created.
Set Variable [ $number; Value:1 ]
Loop
New Record/Request
Set Field [ timer::_keyUser; $userID ]
Set Field [ timer::hide; "t" & ¶ ]
Set Field [ timer::description; GetValue ( $actionNames ; $number ) ]
Set Field [ timer::sortNumber; GetValue ( $actionOrderNumber ; $number ) ]
Set Field [ timer::sortAlpha; GetValue ( $actionOrderLetter ; $number ) ]
Set Field [ timer::HighlightNoteButton; GetValue ( $highlightNote ; $number ) ]
Set Field [ timer::HighlightLibraryButton; GetValue ( $highlightLibrary ; $number ) ]
Set Field [ timer::HighlightSpecificActionButton; GetValue ( $highlightSpecificAction ; $number ) ]
Set Field [ timer::newDayTimer; GetValue ( $setNewDay ; $number ) ]
If [ GetValue ( $setDefaultSpecificAction ; $number ) = 1 ]
Commit Records/Requests
Set Field [ user::DefaultSpecificAction; timer::_lockTimer ]
End If
Set Variable [ $number; Value:$number + 1 ]
Exit Loop If [ $number = 8 ]
End Loop
End If
#
#
December 11, ଘ౮28 0:36:39 ActionLog.fp7 - CHUNK_loadORcreateTimersForUser -1-
