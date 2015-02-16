action buttons: newBrainstateOnMainLayouts
#PURPOSE create a new record for the user and check hide automatically so record will show up on main page if requested by user (I know,
the field name should be changed)
#
#
#
#1 capture the user's ID number
Set Variable [ $userID; Value:reference::farmerID ]
#
#2 create a new record
New Record/Request
#
#3 assign is to the user and check hide field
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::hide; "t" ]
Commit Records/Requests
[ Skip data entry validation; No dialog ]
#
#4 records must be sorted by ID number, otherwise as soon as the brainstate name field is exited the database sorts the brainstate list by
whatever current sort is selected, and the user will see their newly created record disappear. Step 1 of sorting by ID is to clear the
reference::sort field which is used to conditionally formate the label of the currnt sort. 2 sort the records so the new record is the first
record, then 3 go to that first records brainstate name field.
Clear [ reference::sort ]
[ Select ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
#
#5 put cursor in title text box for the user to enter a title
Go to Field [ brainstate::description ]
January 5, 平成26 19:44:41 ActionLog.fp7 - newBrainstateOnMainLayouts -1-
