action buttons: UpdateTime (old: opened things in new windows)
#PURPOSE update the time paused ﬁelds and the total and grand total ﬁelds after a user leaves a time ﬁeld or clicks the veto button. They may
or may not have done anything, but in case they did this update is performed.
#
#
#
#NOTE: the three # symbols set apart chunks of script.
#NOTE: the ﬁnish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason,
they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $userID; Value:reference::farmerID ]
#
#
#
#A) BEGIN go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of
the window while performing the script.
#
#1 exit ﬁeld the user is in so that they are returned to a clean layout when done
Go to Field [ ]
#
#2 open a new window and hide it
New Window [ Name: "UpateTime"; Height: 100; Width: 100 ]
Adjust Window
[ Hide ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
#
#3 go to the ﬁrst record
Go to Record/Request/Page
[ First ]
#
#A) END go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of
the window while performing the script.
#
#
#
Loop
#
#B) BEGIN if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer again, but if
they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
#
#1 get the day records ID number
If [ day1::_lockDay ≠ "" and day1::swTotalActivity = "" ]
Set Variable [ $DayID; Value:day1::_lockDay ]
#
#2 tag the main record as updated so any total and grand totals it is a part of get updated too
Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
#
#3 ﬁnd the day record ad delete it
Go to Layout [ “calcDayTable” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_lockDay; $DayID ]
Perform Find [ ]
January 5, 平成26 19:40:08 ActionLog.fp7 - UpdateTime (old: opened things in new windows) -1-action buttons: UpdateTime (old: opened things in new windows)
Delete Record/Request
[ No dialog ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
End If
#
#B) END if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer again, but if
they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
#
#
#
#C) START skip the records that have not been changed.
#
#1 compare the record's total time against the last update time recorded, and if they are the same go to the next record.
The updatetime ﬁeld is populated by this script as a way of ﬂagging when a record has been updated by this script.
User may have used the drag feature to change multiple records and the only way to know what has been changed is to compare these
time ﬁelds.
If [ day1::updateTime ≠ day1::updateTimeCurrentTimeCalc ]
#
#2 if the record is a total or grand total record, go to the next record (these will be updated later in the script).
If [ brainstate::groupID ≠ brainstate::_lockBrainstateID ]
#
#C) END skip the records that have not been changed.
#
#
#
#D) BEGIN update changed record's ﬂags
#
#1 equalize these two times, thus unﬂagging this record as needing updating.
Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
#
#2 ﬂag this record as changed if it belongs to a total record, so later in this script that record's time can be updated
Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
#
#D) END update changed record's ﬂags
#
#
#
#E) BEGIN update the pause time ﬁelds
#
#This script step has been removed. Initially, I thought since most records only have one time event to skip the update pause
step for these records. However, in testing I found that when a timer is started for a second time event a pause time is
calculated resulting in a gray bar in the bar chart. If the user then deletes this second start time, this now disabled script
stops that bar from being removed because when this script gets to this step the ﬁeld is blank and so no calculation is done.
I decided to leave this failure in just in case I forgot why this doesn't work, try it again, and fail to not perform the correct test,
which I did until by accident noticed something wrong!
// #1 if there is only one time, skip the following steps to recalculate the time paused between more than one time.
// If [ day1::swActivityLength[2] ≠ "" ]
#
#1 clear all PauseTotal ﬁelds, which is necessary because a user may have reduced the number of activity times, thus
reducing the number of pauses. NOTE: pause ﬁeld repetition 1 is never used as their is no pause between time zero
and the ﬁrst time.
Set Variable [ $repetition; Value:2 ]
Loop
Set Field [ day1::swPauseLength[$repetition]; Get ( CurrentTime ) ]
Clear [ day1::swPauseLength[$repetition] ]
[ Select ]
January 5, 平成26 19:40:08 ActionLog.fp7 - UpdateTime (old: opened things in new windows) -2-action buttons: UpdateTime (old: opened things in new windows)
Set Variable [ $repetition; Value:$repetition+1 ]
Exit Loop If [ $repetition = 31 ]
End Loop
#
#2 calculate all pause times between activity times. This step is stopped when the next time to calculate a pause between is
blank or when this loop has reached the last repitition (this test is neccessary because there are only 30 repetitions, so
there will not be a blank 31 to detect, thus reaching 31 has to trigger a stop).
Set Variable [ $repetition; Value:2 ]
Loop
Set Field [ day1::swPauseLength[$repetition]; day1::swStart[$repetition] - day1::swPause[$repetition-1] ]
Set Variable [ $repetition; Value:$repetition+1 ]
Exit Loop If [ day1::swStart[$repetition] = "" ]
Exit Loop If [ $repetition = 31 ]
End Loop
#
#E) END update the pause time ﬁelds
#
#
#
End If
End If
#
#
#
#F) BEGIN go to next record
#
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#F) END go to next record
#
#
#
Loop
#
#G) BEGIN ﬁnd all user total records that need to be udated
#
#1 ﬁnd records
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $user ]
Set Field [ brainstate::groupUpdate; "u" ]
Perform Find [ ]
#
#2 if no records are found go to step
Exit Loop If [ Get ( LastError ) = 401 ]
#
#
#
#BEGIN error 1
If [ Get ( LastError ) ≠ 0 ]
#tell user the error number
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime step G1.";
Buttons: “OK” ]
Close Window [ Name: "UpateTime"; Current ﬁle ]
Exit Script [ ]
January 5, 平成26 19:40:08 ActionLog.fp7 - UpdateTime (old: opened things in new windows) -3-action buttons: UpdateTime (old: opened things in new windows)
End If
#END error 1
#
#
#
#G) END ﬁnd all user total records that need to be udated
#
#
#
#H) BEGIN update found record
#
#1 unﬂag this total record for total update
Clear [ brainstate::groupUpdate ]
[ Select ]
#
#2 ﬁnd its linked records
Set Variable [ $mergeto; Value:brainstate::groupID ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $mergeto ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: brainstate::groupType; based on value list: “MergeSort”
brainstate::description; ascending ]
[ Restore; No dialog ]
#
#3 ﬂag for grand total update
Go to Record/Request/Page
[ First ]
Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
#
#4 if linked records are found, ﬁrst reset the total record's time to zero in case the amount of time has decreased (essentially by
deleting its current day record and creating a new blank one).
If [ day1::_keyDay = "" ]
Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
Go to Layout [ “calcDayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyBrainstate; $BrainstateID ]
Insert Calculated Result [ day1::_keyDay; reference::day1 ]
[ Select ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
End If
Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
#
Loop
#
#5 go to the last record
Go to Record/Request/Page
[ Last ]
#
#6 if there are no records to add then delete the just created related day record for this total record (this action would be caused
by the user deleting all the time in the linked records).
If [ brainstate::_lockBrainstateID = brainstate::groupID ]
If [ day1::swTotalActivity = "0:00:00" ]
January 5, 平成26 19:40:08 ActionLog.fp7 - UpdateTime (old: opened things in new windows) -4-action buttons: UpdateTime (old: opened things in new windows)
Set Variable [ $dayID; Value:day1::_lockDay ]
Go to Layout [ “calcDayTable” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_lockDay; $dayID ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
End If
#
#7 go the next part of the script once there are no more records to add
Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupID ]
#
#8 if there is a record to add capture its total time, omit it, go the ﬁrst record and add this time to current total time.
Else If [ day1::_keyDay = "" ]
Omit Record
Else If [ day1::_keyDay ≠ "" ]
Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
Omit Record
Go to Record/Request/Page
[ First ]
Insert Calculated Result [ day1::swPause; Case (
$TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ;
$TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ;
day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
[ Select ]
End If
End Loop
#
#H) END update found record
#
#
#
Loop
#
#I) BEGIN ﬁnd all user GRAND total records that need to be udated
#
#1 ﬁnd records
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $user ]
Set Field [ brainstate::groupOfGroupUpdate; "u" ]
Perform Find [ ]
#
#2 if no records are found go to step
Exit Loop If [ Get ( LastError ) = 401 ]
#
#
#
#BEGIN error 1
If [ Get ( LastError ) ≠ 0 ]
#tell user the error number
January 5, 平成26 19:40:08 ActionLog.fp7 - UpdateTime (old: opened things in new windows) -5-action buttons: UpdateTime (old: opened things in new windows) #tell user the error number
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime step
i1."; Buttons: “OK” ]
Close Window [ Name: "UpateTime"; Current ﬁle ]
Exit Script [ ]
End If
#END error 1
#
#
#
#I) END ﬁnd all user total records that need to be udated
#
#
#
#J) BEGIN update found record
#
#1 unﬂag this total record for grand total update
Clear [ brainstate::groupOfGroupUpdate ]
[ Select ]
#
#2 ﬁnd its linked records
Set Variable [ $mergeto; Value:brainstate::groupOfGroupID ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::groupOfGroupID; $mergeto ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: brainstate::groupType; based on value list: “MergeSort” ]
[ Restore; No dialog ]
#
#3 if linked records are found, ﬁrst reset the total record's time to zero in case the amount of time has decreased (essentially by
deleting its current day record and creating a new blank one).
Go to Record/Request/Page
[ First ]
If [ day1::_keyDay = "" ]
Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
Go to Layout [ “calcDayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyBrainstate; $BrainstateID ]
Insert Calculated Result [ day1::_keyDay; reference::day1 ]
[ Select ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
End If
Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
#
Loop
#
#4 go to the last record
Go to Record/Request/Page
[ Last ]
#
#5 if there are no records to add then delete the just created related day record for this total record (this action would be
caused by the user deleting all the time in the linked records).
If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
January 5, 平成26 19:40:08 ActionLog.fp7 - UpdateTime (old: opened things in new windows) -6-action buttons: UpdateTime (old: opened things in new windows)
If [ day1::swTotalActivity = "0:00:00" ]
Set Variable [ $dayID; Value:day1::_lockDay ]
Go to Layout [ “calcDayTable” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_lockDay; $dayID ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
End If
#
#6 go the next part of the script once there are no more records to add
Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
#
#7 if there is a record to add capture its total time, omit it, go the ﬁrst record and add this time to current total time.
Else If [ day1::_keyDay = "" ]
Omit Record
Else If [ day1::_keyDay ≠ "" ]
Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
Omit Record
Go to Record/Request/Page
[ First ]
Insert Calculated Result [ day1::swPause; Case (
$TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ;
$TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ;
day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an
error. ]
[ Select ]
End If
End Loop
End Loop
#
#J) END update found record
#
#
#
End Loop
#
#Have to go back to orginal layout, otherwise Hide Window step causes the data to be delayed showing up after the next interation of the
stopwatch script runs thru.
Close Window [ Name: "UpateTime"; Current ﬁle ]
Perform Script [ “DaySelectSortThenSort” ]
January 5, 平成26 19:40:08 ActionLog.fp7 - UpdateTime (old: opened things in new windows) -7-
