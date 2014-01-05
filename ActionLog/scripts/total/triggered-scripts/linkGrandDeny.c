total: triggered scripts: linkGrandDeny
#PURPOSE on the total up layout there is a box for the user to click into to choose a record to be part of a new grand total record. This script
runs a test to see if the user may include the record chosen. The reason behind this test is to prevent the user from replacing an already
linked-to-a-grand-total-record's link information in the form of that grand total record's ID currently in this linked record's linkID ﬁeld. While it
might be nice to allow the user to count one record as part of several grand totals, the current design does not allow this. So until it is
changed, the user must be prevented from unlinking a record while creating a new total record.
The second purpose is to insure that only total records are included in grand totals. This insures that no normal record is part of a total and part
of the same grand total that its total record is a part of, which cause double counting the normal record's time in the grand total.
#
#
#
#1 check to insure that the record is not part of another grand total record.
If [ brainstate::groupOfGroupID ≠ "" ]
Clear [ ]
[ Select ]
Show Custom Dialog [ Title: "!"; Message: "This record is part of another grand total record (or is one) and cannot be included in another
grand total."; Buttons: “OK” ]
Go to Field [ ]
End If
#
#2 check to insure that the record is a total record.
If [ brainstate::_lockBrainstateID ≠ brainstate::groupID ]
Clear [ ]
[ Select ]
Show Custom Dialog [ Title: "!"; Message: "Only total records may be selected to create a grand total record."; Buttons: “OK” ]
Go to Field [ ]
Halt Script
End If
January 5, 平成26 13:43:05 ActionLog.fp7 - linkGrandDeny -1-
