total: triggered scripts: addToGrandtotalDeny
#PURPOSE on the add2grandtotal layout there is a box for the user to click into to choose a record to be part of a total record. This script runs a test to see if the user may include the record chosen. The reason behind this test is to prevent the user from replacing an already linked- to-a-total-record's link information in the form of that total record's ID currently in this linked record's linkID field. While it might be nice to allow the user to count one record as part of several totals, the current design does not allow this.
#
#
#
#1 check to insure record is not the total record being add to.
If [ brainstate::groupOfGroupAddCheckbox = "" and brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
Set Field [ brainstate::groupOfGroupAddCheckbox; "t" ]
Go to Field [ ]
Show Custom Dialog [ Title: "!"; Message: "Select available records to add to this grandtotal record or click the cancel button."; Buttons: “OK” ]
Halt Script End If
#
#2 check to insure record is not itself a grandtotal record. (Replacing the linkID would turn this record into a normal record and stop it from functioning as a total of it's currently linked records time.)
If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ] Clear [ ]
[ Select ]
Show Custom Dialog [ Title: "!"; Message: "This is a grandtotal record. You may not make it part of the currently selected grandtotal record."; Buttons: “OK” ]
Go to Field [ ]
Halt Script End If
#
#3 check to insure record is not linked to another total record. (Replacing the linkID would route all future time changes to be summed in the new total record the user is trying to create.)
If [ brainstate::groupOfGroupID ≠ "" ] Clear [ ]
[ Select ]
Show Custom Dialog [ Title: "!"; Message: "This record is part of another grandtotal record and cannot be made part of this grandtotal record (unless you separate it from its current grandtotal record first)."; Buttons: “OK” ]
Go to Field [ ] End If
￼January 5, 平成26 14:04:46
ActionLog.fp7 - addToGrandtotalDeny -1-
