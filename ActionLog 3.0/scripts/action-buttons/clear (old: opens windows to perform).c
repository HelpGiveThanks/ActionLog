action buttons: Clear (old: opens windows to perform)
#PURPOSE just like on a stopwatch, this script activated by the clear button deletes the time recorded for a brainstate record's related day
record. Rather than just return the time to zero, this scripts deletes the record in case the user made a mistake in starting a timer for a
particular brainstate record and will not be using it at all, in which case if it is not deleted, this unused record will ﬁll up the database wasting
space.
#
#
#BUG remove focus from any ﬁelds. This step seems to be neccessary as I periodically have been getting a -- this record is being modiﬁed in a
separate window -- message. I'm leaving this step in to see if I stop getting this message.
Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
Go to Field [ ]
Go to Record/Request/Page [ $recordNumber ]
[ No dialog ]
#
#
#1 check to insure that there is a record to clear and if not hast the script, then check to insure if there is a record that it is not a total or grand
total record. These total records are sums of other records and so their times are not created by the stopwatch script and should not be
cleared by this script. They will be cleared if there linked records' times are cleared by the UpdateTime script.
If [ day1::_keyDay = "" or
brainstate::_lockBrainstateID = brainstate::groupID or
brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
Halt Script
End If
#
#2 capture the day record's ID number
Set Variable [ $dayID; Value:day1::_lockDay ]
#
#3 open a new window to perform the delete. This is neccessary because just going to the day layout and then back to the brainstate layout will
reset the scroll and confuse the user. When a new window is used the scroll and focus on the orignal layout is not changed.
New Window [ Name: "Clear"; Height: 2; Width: 2 ]
Adjust Window
[ Hide ]
#
#3 ﬁnd and delete the day record then close the window
Go to Layout [ “calcDayTable” (day1) ]
Enter Find Mode [ ]
Insert Calculated Result [ day1::_lockDay; $dayID ]
[ Select ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ original layout ]
Close Window [ Name: "Clear"; Current ﬁle ]
#
#4 determine if the record whose time was just cleared is linked to a total and if so ﬂag it as changed and run the UpdateTime script to update its
total record's time.
Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
If [ brainstate::groupID ≠ "" ]
Perform Script [ “UpdateTime” ]
End If
#
#5 determine if the user is currently sorting by time and if so sort re-sort the records to remove this record from its current position in the time
sort. (It should be listed in alphabetical order under the list of records sorted by their times as this record no longer has any time associated
with it.)
Perform Script [ “sortRestoreAfterScript” ]
Go to Field [ ]
January 5, 平成26 19:43:14 ActionLog.fp7 - Clear (old: opens windows to perform) -1-
