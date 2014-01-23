action buttons: clearPart2
#PURPOSE just like on a stopwatch, this script activated by the clear button deletes the time recorded for a brainstate record's related day
record. Rather than just return the time to zero, this scripts deletes the record in case the user made a mistake in starting a timer for a
particular brainstate record and will not be using it at all, in which case if it is not deleted, this unused record will ﬁll up the database wasting
space.
#
#1 check to insure that there is a record to clear and if not hast the script, then check to insure if there is a record that it is not a total or grand
total record. These total records are sums of other records and so their times are not created by the stopwatch script and should not be
cleared by this script. They will be cleared if there linked records' times are cleared by the UpdateTime script.
If [ day1::_keyDay = "" or
brainstate::_lockBrainstateID = brainstate::groupID or
brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
Set Variable [ $$recordFIXTOMANYVARIABLES ]
Halt Script
End If
#
#preserve stopwatch symbol for use in updatetime script as it will be deleted by this script
Set Variable [ $$onoff; Value:"note" ]
#BUG remove focus from any ﬁelds. This step seems to be neccessary as I periodically have been getting a -- this record is being modiﬁed in a
separate window -- message. I'm leaving this step in to see if I stop getting this message.
Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
Go to Field [ ]
Go to Record/Request/Page [ $recordNumber ]
[ No dialog ]
#
#
#
#2 capture the day record's ID number
Set Variable [ $dayID; Value:day1::_lockDay ]
#
// #3 open a new window to perform the delete. This is neccessary because just going to the day layout and then back to the brainstate layout
will reset the scroll and confuse the user. When a new window is used the scroll and focus on the orignal layout is not changed.
// New Window [ Name: "Clear"; Height: 2; Width: 2 ]
// Adjust Window
[ Hide ]
#
#3 ﬁnd and delete the day record
Go to Layout [ “calcDayTable” (day1) ]
Enter Find Mode [ ]
Insert Calculated Result [ day1::_lockDay; $dayID ]
[ Select ]
Perform Find [ ]
#
#Capture day key to remove time from an issues records
#that currently have time from this day attributed to them.
Set Variable [ $$updateDay; Value:day1::_lockDay ]
Set Variable [ $$clear; Value:1 ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Delete Record/Request
[ No dialog ]
Set Variable [ $$stopRecordLoad ]
Go to Layout [ original layout ]
Perform Script [ “CHUNK_lastDayUsed” ]
#
#4 determine if the record whose time was just cleared is linked to a total and if so ﬂag it as changed and run the UpdateTime script to update its
total record's time.
Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
If [ brainstate::groupID ≠ "" ]
#
#Update time in issue records if neccessary.
January 5, 平成26 19:42:30 ActionLog.fp7 - clearPart2 -1-action buttons: clearPart2
Perform Script [ “CHUNK_updateIssueCategoryTime” ]
Set Variable [ $$clear ]
#
// #Reload log record in case current variables are
// #set for log record that was just deleted/cleared.
// Select Window [ Name: "Activity Log"; Current ﬁle ]
// If [ Get (LastError) ≠ 112 //window missing ]
// Perform Script [ “LoadLogrecordID” ]
// End If
Select Window [ Name: "Timer"; Current ﬁle ]
Set Variable [ $$stopCHUNK_updateIssueCategoryTime; Value:1 ]
#
#Update time for affected total record if any and for
#other brainstate records as user may have dragged
#time to other records before clearing this one, and
#so system needs to update the time in those records.
Perform Script [ “UpdateTime” ]
End If
#
#5 determine if the user is currently sorting by time and if so sort re-sort the records to remove this record from its current position in the time
sort. (It should be listed in alphabetical order under the list of records sorted by their times as this record no longer has any time associated
with it.)
Go to Field [ ]
January 5, 平成26 19:42:30 ActionLog.fp7 - clearPart2 -2-
