action buttons: newBrainstateOnTotalLayouts
#PURPOSE create a new record for the user (but do not check hide automatically)
#
#
#
#1 capture the user's ID number
Set Variable [ $userID; Value:reference::farmerID ]
#
#2 create a new record
New Record/Request
#
#3 assign is to the user
Set Field [ brainstate::_keyUser; $userID ]
Commit Records/Requests
[ Skip data entry validation; No dialog ]
#
#4 records must be sorted by ID number, otherwise as soon as the brainstate name ﬁeld is exited the database sorts the brainstate list by
whatever current sort is selected, and the user will see their newly created record disappear. Step 1 of sorting by ID is to clear the
reference::sort ﬁeld which is used to conditionally formate the label of the currnt sort. 2 sort the records so the new record is the ﬁrst
record, then 3 go to that ﬁrst records brainstate name ﬁeld.
Clear [ reference::sort ]
[ Select ]
Sort Records [ Speciﬁed Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
#
#5 put cursor in title text box for the user to enter a title
Go to Field [ brainstate::description ]
January 5, 平成26 19:44:00 ActionLog.fp7 - newBrainstateOnTotalLayouts -1-
