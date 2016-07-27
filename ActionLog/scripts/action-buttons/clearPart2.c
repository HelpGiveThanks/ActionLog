action buttons: clearPart2
#PURPOSE just like on a stopwatch, this script activated by the clear button deletes the time recorded for a brainstate record's related
day record. Rather than just return the time to zero, this scripts deletes the record in case the user made a mistake in starting a
timer for a particular brainstate record and will not be using it at all, in which case if it is not deleted, this unused record will fill up
the database wasting space.
#
#
Allow User Abort [ Off ]
#
#
#1 check to insure that there is a record to clear and if not hast the script, then check to insure if there is a record that it is not a total or
grand total record. These total records are sums of other records and so their times are not created by the stopwatch script and
should not be cleared by this script. They will be cleared if there linked records' times are cleared by the UpdateTime script.
If [ day1::_keyDay = "" or
brainstate::_lockBrainstateID = brainstate::groupID or
brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
Set Variable [ $$recordFIXTOMANYVARIABLES ]
Set Variable [ $$clear ]
Halt Script
End If
#
#preserve stopwatch symbol for use in updatetime script as it will be deleted by this script
Set Variable [ $$onoff; Value:"note" ]
#BUG remove focus from any fields. This step seems to be neccessary as I periodically have been getting a -- this record is being
modified in a separate window -- message. I'm leaving this step in to see if I stop getting this message.
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
// #3 open a new window to perform the delete. This is neccessary because just going to the day layout and then back to the
brainstate layout will reset the scroll and confuse the user. When a new window is used the scroll and focus on the orignal layout
is not changed.
// New Window [ Name: "Clear"; Height: 2; Width: 2 ]
// Adjust Window
[ Hide ]
#
#3 find and delete the day record
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
#WHAT??? Check these next steps out as groups are no longer used and the update time script is last and will perform the chunk
scripts again!?
#WHAT??? Check these next steps out as groups are no longer used and the update time script is last and will perform the chunk
scripts again!?
#WHAT??? Check these next steps out as groups are no longer used and the update time script is last and will perform the chunk
scripts again!?
#WHAT??? Check these next steps out as groups are no longer used and the update time script is last and will perform the chunk
scripts again!?
#WHAT??? Check these next steps out as groups are no longer used and the update time script is last and will perform the chunk
scripts again!?
#WHAT??? Check these next steps out as groups are no longer used and the update time script is last and will perform the chunk
scripts again!?
#WHAT??? Check these next steps out as groups are no longer used and the update time script is last and will perform the chunk
scripts again!?
#
#4 determine if the record whose time was just cleared is linked to a total and if so flag it as changed and run the UpdateTime script to
update its total record's time.
Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
If [ brainstate::groupID ≠ "" ]
#
#Update time in issue records if neccessary.
Perform Script [ “CHUNK_updateIssueCategoryTime (update)” ]
#
#Load updated variables in both Day and
#Specific Action windows and refresh them to
#trigger current conditional formatting for
#selected records.
Set Variable [ $refreshDayCurrentWindow; Value:Get ( WindowName ) ]
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
Set Variable [ $$log; Value:logs::_lockDay ]
Set Variable [ $$day1BugField; Value:logs::swBugField ]
Refresh Window
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
Refresh Window
Select Window [ Name: $refreshDayCurrentWindow; Current file ]
#
#Script will halt after performing sort step below
#so clear the $$clear variable.
Set Variable [ $$clear ]
#
// #Reload log record in case current variables are
// #set for log record that was just deleted/cleared.
// Select Window [ Name: "Activity Log"; Current file ]
// If [ Get (LastError) ≠ 112 //window missing ]
// Perform Script [ “loadLogrecordID (update)” ]
// End If
Select Window [ Name: "Timer"; Current file ]
Set Variable [ $$stopCHUNK_updateIssueCategoryTime; Value:1 ]
#
#Update time for affected total record if any and for
#other brainstate records as user may have dragged
#time to other records before clearing this one, and
#so system needs to update the time in those records.
Perform Script [ “updateTime” ]
End If
#
#
#
#5 determine if the user is currently sorting by time and if so sort re-sort the records to remove this record from its current position in
the time sort. (It should be listed in alphabetical order under the list of records sorted by their times as this record no longer has
any time associated with it.)
Go to Field [ ]
July 13, ଘ౮28 19:49:15 ActionLog.fp7 - clearPart2 -1-
