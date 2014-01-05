total: action buttons: addToTotalPart1
#PURPOSE create list of records that can be added to the current total record.
#
#
#
#1 constrain the current records being viewed to just the total record and mark it for adding. (This ﬁnding of the record to be marked could also
be done with a sort.)
Constrain Found Set [ Speciﬁed Find Requests: Find Records; Criteria: brainstate::groupType: “merge” ]
[ Restore ]
Set Field [ brainstate::groupAddCheckbox; "t" ]
#
#2 go to the add2total layout and ﬁnd all the users records excluding total and grandtotal records. (The list should include only records that
could be added to the total.)
Go to Layout [ “add2total” (brainstate) ]
Set Variable [ $userID; Value:reference::farmerID ]
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::groupType: “merge” ]
[ Restore ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::groupID: “>1” ]
[ Restore ]
Extend Found Set [ Speciﬁed Find Requests: Find Records; Criteria: brainstate::groupAddCheckbox: “t” ]
[ Restore ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::description: “=” ]
[ Restore ]
January 5, 平成26 14:11:51 ActionLog.fp7 - addToTotalPart1 -1-
