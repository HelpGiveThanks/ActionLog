show/hide buttons and checkboxes: ShowButton
Freeze Window
Set Field [ steward::showORhide; "show" ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
If [ steward::showStatus = "" ]
#This script is activited by the hide button. When clicked the script performs a find of all the user records where the user has not
clicked the view checkbox putting a 't' into the view field. Thus it finds the users brainstate records with blank view fields.
Set Variable [ $user; Value:reference::farmerID ]
Enter Find Mode [ ]
Set Field [ brainstate::Show; "t" ]
Set Field [ brainstate::_keyUser; $user ]
#If the user wants to hide brainstate records than they want find only brainstate records where show = t; and if they want to show
all brainstate records then they just perform a find for all their records regardless of show status.
Perform Find [ ]
#why?
If [ Get ( LastError ) = 401 ]
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $user ]
Perform Find [ ]
Else If [ Get ( LastError ) ≠ 0 ]
Show Custom Dialog [ Title: "!"; Message: "Unexpected error performing hide script"; Buttons: “OK” ]
Halt Script
End If
Set Field [ steward::showStatus; "t" ]
Go to Field [ ]
If [ steward::retiredStatus ≠ "" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
End If
If [ steward::showStatus ≠ "" ]
#This script is activited by the hide button. When clicked the script performs a find of all the user records where the user has not
clicked the view checkbox putting a 't' into the view field. Thus it finds the users brainstate records with blank view fields.
Set Variable [ $user; Value:reference::farmerID ]
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $user ]
#If the user wants to hide brainstate records than they want find only brainstate records where show = t; and if they want to show
all brainstate records then they just perform a find for all their records regardless of show status.
Perform Find [ ]
If [ Get ( LastError ) = 401 ]
Show Custom Dialog [ Title: "!"; Message: "Unexpected error performing view script"; Buttons: “OK” ]
Else If [ Get ( LastError ) ≠ 0 ]
Show Custom Dialog [ Title: "!"; Message: "Unexpected error performing view script"; Buttons: “OK” ]
Halt Script
End If
Set Field [ steward::showStatus; "" ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
If [ steward::retiredStatus ≠ "" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
End If
July 26, ଘ౮28 14:24:00 ActionLog.fp7 - ShowButton -1-
