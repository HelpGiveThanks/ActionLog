action buttons: updateTime
#PURPOSE update the time paused fields and the total and grand total fields after a user leaves a time field or clicks the veto button.
They may or may not have done anything, but in case they did this update is performed.
#
#If user just clicked into the time field and the clicked
#out without doing anything then stop this script as
#there is not time change to update.
#NEED TO STOP $$FIELDVALUE GETTING CREATED WHEN STOPWATCH BUTTON IS CLICKED, THEN THIS SCRIPT STEP
SHOULD WORK.
#SAME TIME INCLUDE VARIABLE TO STOP UPDATE OF ISSUE TIME!
// If [ $$fieldValue = Get (ActiveFieldContents) ]
// Exit Script [ ]
// End If
#
#If user clicked the clear button but was in a field
#the clearPart1 script when it exits this field will
#trigger this script, which must be exited for the
#clearPart1 script to continue.
If [ $$warning ≠ "" ]
Exit Script [ ]
End If
#
If [ $$iphoneStop ≠ "" ]
Set Variable [ $$iphoneStop ]
Exit Script [ ]
End If
#
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#
#when the user is in the time edit window we want to
#use the recordnumber variable to focus on record in
#in use on this window. But when user goes from this
#edit window to the main window we want the sort script
#to find the record to focus by looping through each record's
#ID number until the correct record is found.
If [ $$sortstatus ≠ "" ]
Set Variable [ $$recordnumber; Value:Get (RecordNumber) ]
End If
#
#NOTE: the three # symbols set apart chunks of script.
#NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For
this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them
apart.
#
Freeze Window
#If the user enters a time field but makes no changes prevent the script from continuing if on the iphone. Do not do this for the PC as
the user could have dragged the time into another stopwatch, thus requring the script to udate this stopwatch's values.
If [ Get ( SystemPlatform ) = 3 and Get ( ActiveFieldContents ) = $$fieldValue and $$fieldValue ≠ "" ]
Go to Field [ ]
Set Variable [ $$fieldValue ]
Set Variable [ $$recordnumber ]
Set Variable [ $$stopRecordLoad ]
Halt Script
End If
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#If the user has deleted time in a time slot,
#check if this slot has been assigned
#to a specific action, and if so, remove its key
#from this specific action, and also show it as
#available to be assigned to any specific action.
Set Variable [ $RepetitionNumber; Value:Get ( ActiveRepetitionNumber ) ]
Set Variable [ $time; Value:$RepetitionNumber & day1::_lockDay ]
Set Variable [ $day; Value:day1::_lockDay ]
Go to Field [ ]
If [ day1::swStart[$repetitionNumber] = "" and day1::swPause[$repetitionNumber] = "" ]
#
#If user deleted all time for the day then
#prepare to remove the link to this day record.
If [ day1::_lockDay ≠ "" and day1::swTotalActivity = "" ]
Set Variable [ $removeDayLink; Value:1 ]
End If
#
#Subtract segment key from specific action record.
New Window [ ]
// New Window [ Height: 1; Width: 1; Top: -10000; Left: -10000 ]
Go to Layout [ “Issues” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::timeSegmentKeyList; $time ]
Perform Find [ ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
Set Field [ issue::timeSegmentKeyList; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item
is not removed, then the removal calc without the paragraph mark is used
If ( ValueCount ( $$timeAll ) ≠ ValueCount ( Substitute ( $$timeAll ; $time & "¶" ; "" ) ) ;
Substitute ( $$timeAll ; $time & "¶" ; "" ) ;
Substitute ( $$timeAll ; $time ; "" )
) ]
Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
Set Field [ day1::swLogTimeAccounting[$RepetitionNumber]; "" ]
#
#Remove link to day log from this issue record
#if day record is being deleted.
If [ $removeDayLink = 1 ]
Set Field [ issue::_keyLogs; If ( ValueCount ( issue::_keyLogs ) ≠ ValueCount ( Substitute ( issue::_keyLogs ; $day & "¶" ;
"" ) ) ;
Substitute ( issue::_keyLogs ; $day & "¶" ; "" ) ;
Substitute ( issue::_keyLogs ; $day ; "" ) ) ]
End If
#
#See if time segment is already in use by this time segment.
Go to Layout [ “issueTime” (issueTime) ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ issueTime::_keyDay; $day ]
Set Field [ issueTime::_keyRepetition; $RepetitionNumber ]
Perform Find [ ]
#
#If it is in use then delete it from this segment.
Delete Record/Request
[ No dialog ]
#
Close Window [ Current Window ]
#
#Make re-assignable.
Set Field [ issue::issueTotalTime; $totalTime ]
#
#Conditionally formats text of issue field Timer Green for on.
Set Variable [ $$TimeAssignedToSpecificAction ]
#
#Conditionally formats Day Time Segment Timer Green for on.
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$ActiveTimeSegment ]
Set Variable [ $$day1BugField ]
#UNTESTED!!!!!!!!!!!!!!!
Set Field [ issue::timer; "" ]
Refresh Window
Select Window [ Name: "Timer"; Current file ]
End If
Set Variable [ $RepetitionNumber ]
#
#
Set Variable [ $userID; Value:reference::farmerID ]
Set Variable [ $mergeID; Value:brainstate::groupID ]
Set Variable [ $mergeGrandID; Value:brainstate::groupOfGroupID ]
Set Variable [ $layout; Value:Get ( LayoutName ) ]
Set Variable [ $record; Value:Get (RecordNumber) ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:brainstate::_lockBrainstateID ]
// #needed by folderstopwatchcheck script in case the stopwatch being started or stopped belongs to a total record
// Set Variable [ $$folderon; Value:brainstate::groupID ]
// If [ day1::swSymbols = "veto" ]
// Set Variable [ $$stopwatchON; Value:"t" ]
// Set Variable [ $$onoff; Value:"" ]
// Else If [ day1::swSymbols = "note" or $$onoff = "note" ]
// Set Variable [ $$stopwatchON; Value:"f" ]
// Set Variable [ $$onoff; Value:"" ]
// End If
#
#
#
#A) BEGIN go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe
effect of the window while performing the script.
#
#1 exit field the user is in so that they are returned to a clean layout when done
Go to Field [ ]
#
// #2 open a new window and hide it
// New Window [ Name: "UpateTime"; Height: 100; Width: 100 ]
// Adjust Window
[ Hide ]
#
#3 go to the first record
Go to Record/Request/Page
[ First ]
Loop
If [ day1::_lockDay = "" and brainstate::_lockBrainstateID ≠ brainstate::groupID ]
Omit Record
Else If [ day1::_lockDay ≠ "" or brainstate::_lockBrainstateID = brainstate::groupID ]
Go to Record/Request/Page
[ Next; Exit after last ]
End If
End Loop
Go to Record/Request/Page
[ First ]
#
#A) END go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe
effect of the window while performing the script.
#
#
#
Loop
#
#B) BEGIN if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer
again, but if they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
#
#1 get the day records ID number
If [ day1::_lockDay ≠ "" and day1::swTotalActivity = "" ]
Set Variable [ $DayID; Value:day1::_lockDay ]
#needed by folderstopwatchcheck script
Set Variable [ $$stopwatchON; Value:"f" ]
#
#2 tag the main record as updated so any total and grand totals it is a part of get updated too
Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
#
#3 find the day record and delete it.
Go to Layout [ “calcDayTable” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_lockDay; $DayID ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
#
#4 Load updated variables in both Day and
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
Go to Layout [ “calcBrainstateTable” (brainstate) ]
End If
#
#B) END if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer again,
but if they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
#
#
#
#C) START skip the records that have not been changed.
#
#1 compare the record's total time against the last
#update time recorded, and if they are the same go
#to the next record.
#
#The updatetime field is populated by this script as a
#way of flagging when a record has been updated by
#this script.
#
#User may have used the drag feature to change
#multiple records and the only way to know what has
#been changed is to compare these time fields.
// If [ day1::updateTime ≠ day1::updateTimeCurrentTimeCalc and day1::swBugField = "note" ]
If [ day1::swSymbols ≠ day1::updateTimeSymbol or day1::updateTime ≠ day1::updateTimeCurrentTimeCalc ]
#
#2 if the record is a total or grand total record, go to the next record (these will be updated later in the script).
If [ brainstate::groupID ≠ brainstate::_lockBrainstateID ]
#
#C) END skip the records that have not been changed.
#
#
#
#D) BEGIN update changed record's flags
#
#1 equalize these two times, thus unflagging this record as needing updating.
Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
#
#2 flag this record as changed if it belongs to a total record, so later in this script that record's time can be updated
Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
#
#D) END update changed record's flags
#
#
#
#E) BEGIN update the pause time fields
#
#This script step has been removed. Initially, I thought since most records only have one time event to skip the
update pause step for these records. However, in testing I found that when a timer is started for a second
time event a pause time is calculated resulting in a gray bar in the bar chart. If the user then deletes this
second start time, this now disabled script stops that bar from being removed because when this script gets to
this step the field is blank and so no calculation is done. I decided to leave this failure in just in case I forgot
why this doesn't work, try it again, and fail to not perform the correct test, which I did until by accident noticed
something wrong!
// #1 if there is only one time, skip the following steps to recalculate the time paused between more than one time.
// If [ day1::swActivityLength[2] ≠ "" ]
#
#1 clear all PauseTotal fields, which is necessary because a user may have reduced the number of activity
times, thus reducing the number of pauses. NOTE: pause field repetition 1 is never used as their is no
pause between time zero and the first time.
Set Variable [ $repetition; Value:2 ]
Loop
Set Field [ day1::swPauseLength[$repetition]; Get ( CurrentTime ) ]
Clear [ day1::swPauseLength[$repetition] ]
[ Select ]
Set Variable [ $repetition; Value:$repetition+1 ]
Exit Loop If [ $repetition = 31 ]
End Loop
#
#2 calculate all pause times between activity times. This step is stopped when the next time to calculate a
pause between is blank or when this loop has reached the last repitition (this test is neccessary because
there are only 30 repetitions, so there will not be a blank 31 to detect, thus reaching 31 has to trigger a
stop).
Set Variable [ $repetition; Value:2 ]
Loop
Set Field [ day1::swPauseLength[$repetition]; day1::swStart[$repetition] - day1::swPause[$repetition-1] ]
Set Variable [ $repetition; Value:$repetition+1 ]
Exit Loop If [ day1::swStart[$repetition] = "" ]
Exit Loop If [ $repetition = 31 ]
End Loop
#
#E) END update the pause time fields
#
#
#E2) UPDATE the time in any dependent issues.
If [ $$stopCHUNK_updateIssueCategoryTime ≠ 1 ]
Set Variable [ $$timeSegment; Value:$time ]
Set Variable [ $$updateDay; Value:day1::_lockDay ]
Perform Script [ “CHUNK_updateIssueCategoryTime (update)” ]
Set Variable [ $$timeSegment ]
Set Variable [ $$updateDay ]
End If
#
#
End If
End If
#
Set Variable [ $$stopCHUNK_updateIssueCategoryTime ]
#
#
#F) BEGIN go to next record
#
#
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
#G) BEGIN find all user total records that need to be udated
#
#1 find records
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
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming
CheckUpdateTime step G1."; Buttons: “OK” ]
Go to Record/Request/Page [ $record ]
[ No dialog ]
Set Variable [ $$recordnumber ]
Set Variable [ $$stopRecordLoad ]
Exit Script [ ]
End If
#END error 1
#
#
#
#G) END find all user total records that need to be udated
#
#
#
#H) BEGIN update found record
#
#1 unflag this total record for total update
Clear [ brainstate::groupUpdate ]
[ Select ]
#
#1b set variables so total record's conditional formatting will match that of the stopwatch being updated.
If [ day1::swSymbols ≠ day1::updateTimeSymbol or $$onoff = "note" ]
Set Variable [ $$folderon; Value:brainstate::groupID ]
If [ day1::swSymbols = "veto" ]
Set Variable [ $$stopwatchON; Value:"t" ]
Set Variable [ $$onoff; Value:"" ]
Else If [ day1::swSymbols = "note" or $$onoff = "note" ]
Set Variable [ $$stopwatchON; Value:"f" ]
Set Variable [ $$onoff; Value:"" ]
End If
End If
Set Field [ day1::updateTimeSymbol; day1::swSymbols ]
#
#2 find its linked records
Set Variable [ $mergeto; Value:brainstate::groupID ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $mergeto ]
// Set Field [ brainstate::sortRetired; "=" ]
Perform Find [ ]
Perform Script [ “folderStopwatchCheck” ]
#3 go to the first record
Loop
If [ day1::swStart = "" and brainstate::_lockBrainstateID ≠ brainstate::groupID ]
Omit Record
Else If [ day1::swStart ≠ "" or brainstate::_lockBrainstateID = brainstate::groupID ]
Go to Record/Request/Page
[ Next; Exit after last ]
End If
End Loop
#
Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort”
brainstate::description; ascending ]
[ Restore; No dialog ]
#
#3 flag for grand total update
Go to Record/Request/Page
[ First ]
Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
#
#4 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased
(essentially by deleting its current day record and creating a new blank one).
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
#6 if there are no records to add then delete the just created related day record for this total record (this action
would be caused by the user deleting all the time in the linked records).
If [ brainstate::_lockBrainstateID = brainstate::groupID ]
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
#7 go the next part of the script once there are no more records to add
Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupID ]
#
#8 if there is a record to add capture its total time, omit it, go the first record and add this time to current total
time.
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
//insures that no more than 24 hours will be put into a day and that a day with negative time does not
cause an error. ]
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
#I) BEGIN find all user GRAND total records that need to be udated
#
#1 find records
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
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming
CheckUpdateTime step i1."; Buttons: “OK” ]
// Close Window [ Name: "UpateTime"; Current file ]
Go to Record/Request/Page [ $record ]
[ No dialog ]
Set Variable [ $$recordnumber ]
Set Variable [ $$stopRecordLoad ]
Exit Script [ ]
End If
#END error 1
#
#
#
#I) END find all user total records that need to be udated
#
#
#
#J) BEGIN update found record
#
#1 unflag this total record for grand total update
Clear [ brainstate::groupOfGroupUpdate ]
[ Select ]
#
#2 find its linked records
Set Variable [ $mergeto; Value:brainstate::groupOfGroupID ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::groupOfGroupID; $mergeto ]
Perform Find [ ]
Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” ]
[ Restore; No dialog ]
#
#3 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased
(essentially by deleting its current day record and creating a new blank one).
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
#5 if there are no records to add then delete the just created related day record for this total record (this action
would be caused by the user deleting all the time in the linked records).
If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
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
#7 if there is a record to add capture its total time, omit it, go the first record and add this time to current
total time.
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
//insures that no more than 24 hours will be put into a day and that a day with negative time does not
cause an error. ]
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
#Have to go back to orginal layout, otherwise Hide Window step causes the data to be delayed showing up after the next
interation of the stopwatch script runs thru.
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$record ]
Perform Find [ ]
Go to Layout [ $layout ]
Set Variable [ $$stopRecordLoad ]
If [ $mergeID ≠ "" and Left ( $layout ; 5 ) = "Total" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $mergeID ]
Perform Find [ ]
Else If [ $mergeGrandID ≠ "" and Left ( $layout ; 5 ) = "Grand" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupOfGroupID; $mergeGrandID ]
Perform Find [ ]
Else If [ Left ( $layout ; 5 ) ≠ "Total" ]
Perform Script [ “goBackButton_FindRecordsChunk” ]
Perform Script [ “CHUNK_lastDayUsed” ]
// Perform Script [ “folderStopwatchCheck” ]
Perform Script [ “DaySelectSortThenSort (Update)” ]
Halt Script
End If
If [ steward::retiredStatus = "r" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
Perform Script [ “CHUNK_lastDayUsed” ]
// Perform Script [ “folderStopwatchCheck” ]
Perform Script [ “DaySelectSortThenSort (Update)” ]
July 13, ଘ౮28 19:44:21 ActionLog.fp7 - updateTime -1-
