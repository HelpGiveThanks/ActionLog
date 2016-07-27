show/hide buttons and checkboxes: retireButton
#PURPOSE set the status for whether or not to show retired records and then show or hide them.
#
#
#
#2 set the retired status to blank
#
// If [ Left ( $$loglayout ; 5 ) = "total" ]
// Perform Script [ “retireButtonOnViewLayout” ]
// End If
#
#4 set the retired status to r (not blank because it now has an r in it)
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $userID; Value:reference::farmerID ]
Set Variable [ $mergeID; Value:brainstate::groupID ]
#
#2 toggle the retired status field
If [ steward::retiredStatus = "" ]
Set Field [ steward::retiredStatus; "r" ]
Else If [ steward::retiredStatus ≠ "" ]
Set Field [ steward::retiredStatus; "" ]
End If
#
#
#1 set the current find status to hide. The show and hide scripts use the showORhide field to determine if the user wants to hide or
show marked records. This field also is used to format the hide and show buttons to visually tell the user which of the two is
currently selected, or if neither of the two is selected (this field is blank).
#
#2 if the hide status is blank and the user clicks the hide button then they want to hide records records marked hide (hide=t), so find
only blank records, will have the effect of omitting all non-blank records.
If [ steward::hideStatus ≠ "" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupType; "merge" ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
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
#4 it the user wants retired records hidden then hide these records if any
// If [ steward::retiredStatus ≠ "" ]
// Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
// Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::sortRetired: “=”
AND brainstate::groupDisplayID: “=” ]
[ Restore ]
// Else If [ steward::retiredStatus = "" ]
// Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::groupDisplayID:
“=” ]
[ Restore ]
// End If
Perform Script [ “CHUNK_retire” ]
#
#3 set the hide status to blank, remove the focus from any field, and resort the records according the user's current sort status
Perform Script [ “DaySelectSortThenSort (Update)” ]
#
End If
#
#6 if the hide status is not blank and the user clicks the hide button then they want to show all records, so find all records
If [ steward::hideStatus = "" ]
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
#8 it the user wants retired records hidden then hide these records if any
// If [ steward::retiredStatus ≠ "" ]
// Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
// Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::sortRetired: “=”
AND brainstate::groupDisplayID: “=” ]
[ Restore ]
// Else If [ steward::retiredStatus = "" ]
// Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::groupDisplayID:
“=” ]
[ Restore ]
// End If
Perform Script [ “CHUNK_retire” ]
#
#7 set the hide status to t (not blank), remove the focus from any field, and resort the records according the user's current sort
status
// Perform Script [ “DaySelectSortThenSort (Update)” ]
#
End If
Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
July 26, ଘ౮28 14:17:25 ActionLog.fp7 - retireButton -1-
