show/hide buttons and checkboxes: HideButton
#PURPOSE set the status for whether or not to show or hide records marked hide and then show or hide them.
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
// #1 set the current find status to hide. The show and hide scripts use the showORhide field to determine if the user wants to hide or
show marked records. This field also is used to format the hide and show buttons to visually tell the user which of the two is
currently selected, or if neither of the two is selected (this field is blank).
// Set Field [ steward::showORhide; "hide" ]
// If [ Left ( $$loglayout ; 5 ) = "total" ]
// Perform Script [ “retireButton” ]
// End If
#
#2 if the hide status is blank and the user clicks the hide button then they want to hide records records marked hide (hide=t), so find
only blank records, will have the effect of omitting all non-blank records.
If [ steward::hideStatus = "" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupType; "merge" ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
#FIX COMMENT
Enter Find Mode [ ]
Set Field [ brainstate::hide; "t" ]
Set Field [ brainstate::groupID; "=" ]
Set Field [ brainstate::_keyUser; $userID ]
Extend Found Set [ ]
#
#BEGIN find error 1
If [ Get ( LastError ) ≠ 0 ]
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming HideButton script part
1."; Buttons: “OK” ]
Go to Layout [ original layout ]
Halt Script
End If
#END find error 1
#
#3 set the hide status to blank, remove the focus from any field, and resort the records according the user's current sort status
Set Field [ steward::showORhide; "hide" ]
Set Field [ steward::hideStatus; "t" ]
Go to Field [ ]
#
#4 it the user wants retired records hidden then hide these records if any
If [ steward::retiredStatus ≠ "" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
#
#5 go to the first record and halt the script
Perform Script [ “DaySelectSortThenSort (Update)” ]
End If
#
#6 if the hide status is not blank and the user clicks the hide button then they want to show all records, so find all records
If [ steward::hideStatus ≠ "" ]
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::hide; "t" ]
Perform Find [ ]
#
#BEGIN find error 2
If [ Get ( LastError ) ≠ 0 ]
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming HideButton script part
6."; Buttons: “OK” ]
Go to Layout [ original layout ]
Halt Script
End If
#END find error 2
#
#7 set the hide status to t (not blank), remove the focus from any field, and resort the records according the user's current sort
status
Set Field [ steward::showORhide; "show" ]
Set Field [ steward::hideStatus; "" ]
Go to Field [ ]
#
#8 it the user wants retired records hidden then hide these records if any
If [ steward::retiredStatus ≠ "" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
#
#9 go to the first record and halt the script
Perform Script [ “DaySelectSortThenSort (Update)” ]
End If
July 26, ଘ౮28 14:21:55 ActionLog.fp7 - HideButton -1-
