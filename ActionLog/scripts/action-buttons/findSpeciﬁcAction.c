action buttons: FindSpecificAction
#Capture errors and tell user about them in custom
#dialogue box.
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#If the user clicks the find button and the system is already
#in find mode, capture the user's current find request
#and then perform the requested find.
#This capture is done in case nothing is found and the
#user is asked if they want to modify their request.
#The system puts in the captured request so that the
#user can see the failed request.
If [ Get (WindowMode) = 1 ]
Set Variable [ $issueText; Value:issue::text ]
Perform Find [ ]
#
#If the system is not in find mode and the find button
#is clicked then enter find mode and await the user's
#find request.
Else
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Show/Hide Status Area
[ Hide ]
Show/Hide Text Ruler
[ Hide ]
Go to Layout [ “IssuesFIND” (issue) ]
Go to Field [ issue::text ]
Pause/Resume Script [ Indefinitely ]
Set Variable [ $issueText; Value:issue::text ]
Perform Find [ ]
End If
#
#If the find fails tell the user it failed and give them
#option to modify their request or cancel the find.
Loop
If [ Get (LastError) = 401 ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::text; $issueText ]
Go to Field [ issue::text ]
Show Custom Dialog [ Message: "No records match this request."; Buttons: “cancel”, “modify find” ]
#
#If the user decides to modify their request then re-enter
#find mode and await the users new request.
If [ Get ( LastMessageChoice ) = 2 ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Variable [ $issueText; Value:issue::text ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::text; $issueText ]
Go to Field [ issue::text ]
Pause/Resume Script [ Indefinitely ]
Set Variable [ $issueText; Value:issue::text ]
#
#If the user decides to cancel their the find, then return
#to the main record window and show all records.
January 5, 平成26 19:49:06 ActionLog.fp7 - FindSpecificAction -1-action buttons: FindSpecificAction
Else If [ Get ( LastMessageChoice ) = 1 ]
Go to Layout [ “Issues” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Perform Find [ ]
Show/Hide Status Area
[ Hide ]
Show/Hide Text Ruler
[ Hide ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Exit Script [ ]
End If
Perform Find [ ]
End If
#
#If the find is successful then show the user the found
#records on the main records layout.
Exit Loop If [ Get (LastError) = 0 ]
End Loop
Go to Layout [ “Issues” (issue) ]
Show/Hide Status Area
[ Hide ]
Show/Hide Text Ruler
[ Hide ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
January 5, 平成26 19:49:06 ActionLog.fp7 - FindSpecificAction -2-
