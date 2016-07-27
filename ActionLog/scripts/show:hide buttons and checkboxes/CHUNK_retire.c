show/hide buttons and checkboxes: CHUNK_retire
#PURPOSE set the status for whether or not to show retired records and then show or hide them.
#
#
#
#2 set the retired status to blank
#8 it the user wants retired records hidden then hide these records if any
If [ steward::retiredStatus ≠ "" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
Enter Find Mode [ ]
Set Field [ brainstate::hide; "t" ]
Set Field [ brainstate::sortRetired; "=" ]
Set Field [ brainstate::groupDisplayID; "=" ]
Set Field [ brainstate::_keyUser; reference::farmerID ]
Extend Found Set [ ]
Else If [ steward::retiredStatus = "" ]
Enter Find Mode [ ]
Set Field [ brainstate::hide; "t" ]
Set Field [ brainstate::groupDisplayID; "=" ]
Set Field [ brainstate::_keyUser; reference::farmerID ]
Extend Found Set [ ]
End If
July 26, ଘ౮28 14:18:30 ActionLog.fp7 - CHUNK_retire -1-
