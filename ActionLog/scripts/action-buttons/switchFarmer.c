action buttons: switchFarmer
#PURPOSE switch from one user's records to anothers via the reference ﬁeld farmer which is a global ﬁeld holding the current ID number of the
current user.
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#
#
#1 capture selected userID chosen
Set Variable [ $userID; Value:reference::farmerID ]
#
#2 ﬁnd this user's records
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
#
#3 if the user has no records, create a new one and assign it to the user so that there name will show up. (All the layouts are tied to the
brainstate table not the user table. So the only way to show a user name and all the correct formating attributes is to have one user
record.)
If [ Get ( LastError ) = 401 ]
Set Field [ reference::farmerID; "" ]
Go to Field [ reference::farmerID ]
Halt Script
Else If [ Get ( LastError ) ≠ 0 ]
Show Custom Dialog [ Title: "!"; Message: "Unexpected error performing switchFarmer script"; Buttons: “OK” ]
Go to Layout [ “users” (steward) ]
Show All Records
Halt Script
End If
#
#4 show the user's name
Set Field [ reference::farmerName; steward::FirstPlusLast ]
#
#5 show/hide all records according the user's last settings
If [ steward::retiredStatus = "r" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::hide: “t” ]
[ Restore ]
Else If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::Show: “=” ]
[ Restore ]
End If
#
#6 go to user's chosen day, sort records, and choose last used layout
If [ Left ( steward::chosenLayout ; 2 ) = "01" ]
Perform Script [ “to 1” ]
Else If [ Left ( steward::chosenLayout ; 2 ) = "07" ]
Perform Script [ “to 7” ]
Else If [ Left ( steward::chosenLayout ; 2 ) = "31" ]
Perform Script [ “to 31” ]
End If
January 5, 平成26 19:55:50 ActionLog.fp7 - switchFarmer -1-
