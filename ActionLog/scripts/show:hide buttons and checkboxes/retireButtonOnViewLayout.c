show/hide buttons and checkboxes: retireButtonOnViewLayout
#PURPOSE set the status for whether or not to show retired records and then show or hide them.
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $userID; Value:reference::farmerID ]
Set Variable [ $layoutname; Value:Get ( LayoutName ) ]
Set Variable [ $totalRecord; Value:brainstate::groupID ]
#
#
#
#1 if the retired status is not blank and the user clicks the retired button then they want to show all retired records, so find all records
If [ steward::retiredStatus ≠ "" ]
#future developement: omit retired records if the retired button is on
// If [ Get ( LayoutName ) = "viewTotal" or Get ( LayoutName ) = "viewGrandtotal" ]
// Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” ]
[ Restore ]
// Halt Script
// End If
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::groupID; $totalRecord ]
Perform Find [ ]
#
#BEGIN find error 1
If [ Get ( LastError ) ≠ 0 ]
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming RetireButton script part
1."; Buttons: “OK” ]
Go to Layout [ $layoutname ]
Halt Script
End If
#END find error 1
#
#2 set the retired status to blank
Set Field [ steward::retiredStatus; "" ]
#
#3 if the retired status is blank and the user clicks the retired button then they want to hide all retired records, so omit retired
records from the users set of records
Else If [ steward::retiredStatus = "" ]
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::sortRetired; "=" ]
Set Field [ brainstate::groupID; $totalRecord ]
Perform Find [ ]
#
#BEGIN find error 2
If [ Get ( LastError ) ≠ 0 ]
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming RetireButton script part
3."; Buttons: “OK” ]
Go to Layout [ $layoutname ]
Halt Script
End If
#END find error 2
#
#4 set the retired status to r (not blank because it now has an r in it)
Set Field [ steward::retiredStatus; "r" ]
End If
Perform Script [ “DaySelectSortThenSort (Update)” ]
July 26, ଘ౮28 14:19:40 ActionLog.fp7 - retireButtonOnViewLayout -1-
