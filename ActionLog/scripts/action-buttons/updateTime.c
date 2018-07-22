action buttons: updateTime
#HISTORY AND NEEDED CHANGES: This script
#used to help the ActionLog keep track of 1)
#grandtotal records, 2) timer total records,
#and timer records. In testing, this way of
#helping the user group activities by time was
#too imprecise, and so I created the Specific
#Action module, making 1) timers in the main
#timer window function as grand total timers,
#of 2) specific action total group times, and
#finally 3) specific actions times as the
#smallest record of user time.
# The grandtotal and total script steps,
#layouts, and fields nave never been removed.
#They will be when time permits. These
#BEGIN and END statements below I am using
#to flag questionable (deletable?) script steps.
#BEGIN Cleanup, answer why?, delete unused steps, etc.
#END Cleanup, answer why?, delete unused steps, etc.
#
#Specifically, this script updates time for all
#timers because user could have dragged time
#into timers other than the one they have
#currently selected.
#
#
#If user clicked the clear button but was in a field
#the clearPart1 script when it exits this field will
#trigger this script, which must be exited for the
#clearPart1 script to continue.
If [ $$warning ≠ "" ]
Exit Script [ ]
End If
#
#
#When the user is in the time edit window we want to
#use the recordnumber variable to focus on record in
#use on this window. But when user goes from this
#edit window to the main window we want the sort script
#to find the record to focus on by looping through each
#record's ID number until the correct record is found.
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
#Prevent records loading during loops thru
#them to speed up scripts.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#BEGIN: Remove time segment key.
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
New Window [ Name: "Specific Action Table" ]
// New Window [ Name: "Specific Action Table"; Height: 1; Width: 1; Top: -10000; Left: -10000 ]
Go to Layout [ “SpecificActionTable” (specificAction) ]
Enter Find Mode [ ]
Set Field [ specificAction::timeSegmentKeyList; $time ]
Perform Find [ ]
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
Set Field [ specificAction::timeSegmentKeyList; //last item in list has no paragraph mark, so a valuecount test needs to be done
and if item is not removed, then the removal calc without the paragraph mark is used
If ( ValueCount ( $$timeAll ) ≠ ValueCount ( Substitute ( $$timeAll ; $time & "¶" ; "" ) ) ;
Substitute ( $$timeAll ; $time & "¶" ; "" ) ;
Substitute ( $$timeAll ; $time ; "" )
) ]
#
#BUG Sometimes have to go the other window
#with same layout table open becuase system
#says the user is using this record being
#updated, even though the user is in zero
#fields in that other window.
If [ Get (LastError) = 301 ]
Select Window [ Name: "Specific Action"; Current file ]
Go to Field [ ]
Select Window [ Name: "Specific Action Table"; Current file ]
Set Field [ specificAction::timeSegmentKeyList; //last item in list has no paragraph mark, so a valuecount test needs to be
done and if item is not removed, then the removal calc without the paragraph mark is used
If ( ValueCount ( $$timeAll ) ≠ ValueCount ( Substitute ( $$timeAll ; $time & "¶" ; "" ) ) ;
Substitute ( $$timeAll ; $time & "¶" ; "" ) ;
Substitute ( $$timeAll ; $time ; "" )
) ]
End If
#
#See if this SPA is still active on other days.
#NOTE: In the case where there is only one
#segment for the day linked to an issue that
#has just been removed, this script must be
#run here. This script will be run again below
#on this same issue if it does have more than
#one segment linked to this day. There has to
#be a variable that can be created and used,
#so this does not happen, but I leave it up to a
#future sprint to discover this efficiency
#improvement.
Perform Script [ “CHUNK_seeIfSPAisActiveOnOtherDays” ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Imporant to commit the record now as
#otherwise the system will retain the old value
#and it put back in as linked time segement.
Commit Records/Requests
Set Variable [ $$timeAll; Value:specificAction::timeSegmentKeyList ]
Set Field [ day1::swLogTimeAccounting[$RepetitionNumber]; "" ]
#
#Remove link to day log from this issue record
#if day record is being deleted.
If [ $removeDayLink = 1 ]
Set Field [ specificAction::_keyLogs; If ( ValueCount ( specificAction::_keyLogs ) ≠ ValueCount ( Substitute ( specificAction::
_keyLogs ; $day & "¶" ; "" ) ) ;
Substitute ( specificAction::_keyLogs ; $day & "¶" ; "" ) ;
Substitute ( specificAction::_keyLogs ; $day ; "" ) ) ]
End If
#
#See if time segment is in use by any SPA
#records.
Go to Layout [ “SPATimeTable” (SPATime) ]
Set Error Capture [ On ]
Allow User Abort [ Off ]
Enter Find Mode [ ]
Set Field [ SPATime::_keyDay; $day ]
Set Field [ SPATime::_keyRepetition; $RepetitionNumber ]
Perform Find [ ]
#
#Delete the now deleted time segement from
#this issue.
Delete Record/Request
[ No dialog ]
#
Close Window [ Current Window ]
#
#
#BEGIN Cleanup, answer why?, delete unused steps, etc.
#
#The format is now based on an
#issue field not this variable. Not sure if it is
#in use elsewhere. Testing required before removing.
#
#Conditionally formats text of issue field Timer Green for on.
Set Variable [ $$TimeAssignedToSpecificAction ]
#
#END Cleanup, answer why?, delete unused steps, etc.
#
#
#Return to Timer window for next part of script.
Select Window [ Name: "Timer"; Current file ]
End If
Set Variable [ $RepetitionNumber ]
#END: Remove time segment key.
#
#
Set Variable [ $userID; Value:reference::userID ]
Set Variable [ $mergeID; Value:timer::groupID ]
Set Variable [ $mergeGrandID; Value:timer::groupOfGroupID ]
Set Variable [ $layout; Value:Get ( LayoutName ) ]
Set Variable [ $record; Value:Get (RecordNumber) ]
Go to Layout [ “TimerTable” (timer) ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Set Variable [ $$recordFIXTOMANYVARIABLES; Value:timer::_lockTimer ]
// #needed by folderstopwatchcheck script in case the stopwatch being started or stopped belongs to a total record
// Set Variable [ $$folderon; Value:timer::groupID ]
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
If [ day1::_lockDay = "" and timer::_lockTimer ≠ timer::groupID ]
Omit Record
Else If [ day1::_lockDay ≠ "" or timer::_lockTimer = timer::groupID ]
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
Set Field [ timer::groupUpdate; If ( timer::groupID ≠ "" ; "u" ; "" ) ]
Set Field [ timer::groupOfGroupUpdate; If ( timer::groupOfGroupID ≠ "" ; "u" ; "" ) ]
#
#3 find the day record and delete it.
Go to Layout [ “DayTable” (day1) ]
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
Set Variable [ $$log; Value:logs::_lockDay ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$logissues; Value:logs::_keyLogSPAs ]
#
#Inform other scripts if user is on or not on
#the Today or Yesterday record. This info will
#speed them up, since they will not have to
#check this out for themselves.
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
Set Field [ reference::ActivityLogDayRecordNumber; Get (RecordNumber) ]
#
#Go to layout displaying all time segements
#for the selected day record.
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
Refresh Window
#
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$issueLogs; Value:specificAction::_keyLogs ]
Refresh Window
Select Window [ Name: $refreshDayCurrentWindow; Current file ]
#
Go to Layout [ “TimerTable” (timer) ]
End If
#
#B) END if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer again,
but if they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
#
#
#
#C) START skip Timer records' related day
#records that have not been changed.
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
If [ day1::swSymbols ≠ day1::updateTimeSymbol or day1::updateTime ≠ day1::updateTimeCurrentTimeCalc ]
#
#2 if the record is a total or grand total record, go to the next record (these will be updated later in the script).
If [ timer::groupID ≠ timer::_lockTimer ]
#
#C) END skip Timer records' related day
#records that have not been changed.
#
#
#
#D) BEGIN update changed record's flags
#
#1 equalize these two times, thus unflagging this record as needing updating.
Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
#
#2 flag this record as changed if it belongs to a total record, so later in this script that record's time can be updated
Set Field [ timer::groupUpdate; If ( timer::groupID ≠ "" ; "u" ; "" ) ]
#
#D) END update changed record's flags
#
#
#
#E) BEGIN update the pause time fields
#
#This script step has been removed. Initially, I thought since most records only have one time event to skip the update
pause step for these records. However, in testing I found that when a timer is started for a second time event a
pause time is calculated resulting in a gray bar in the bar chart. If the user then deletes this second start time, this
now disabled script stops that bar from being removed because when this script gets to this step the field is blank
and so no calculation is done. I decided to leave this failure in just in case I forgot why this doesn't work, try it
again, and fail to not perform the correct test, which I did until by accident noticed something wrong!
// #1 if there is only one time, skip the following steps to recalculate the time paused between more than one time.
// If [ day1::swActivityLength[2] ≠ "" ]
#
#1 clear all PauseTotal fields, which is necessary because a user may have reduced the number of activity times,
thus reducing the number of pauses. NOTE: pause field repetition 1 is never used as their is no pause
between time zero and the first time.
Set Variable [ $repetition; Value:2 ]
Loop
Set Field [ day1::swPauseLength[$repetition]; Get ( CurrentTime ) ]
Clear [ day1::swPauseLength[$repetition] ]
[ Select ]
Set Variable [ $repetition; Value:$repetition+1 ]
Exit Loop If [ $repetition = 31 ]
End Loop
#
#2 calculate all pause times between activity times. This step is stopped when the next time to calculate a pause
between is blank or when this loop has reached the last repitition (this test is neccessary because there are
only 30 repetitions, so there will not be a blank 31 to detect, thus reaching 31 has to trigger a stop).
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
#Only perform this update if there are issues
#linked to this day.
If [ $$stopCHUNK_updateIssueCategoryTime ≠ 1 and day1::_keyLogSPAs ≠ "" ]
Set Variable [ $$timeSegment; Value:$time ]
Set Variable [ $$updateDay; Value:day1::_lockDay ]
Perform Script [ “CHUNK_updateIssueCategoryTime” ]
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
Set Field [ timer::_keyUser; $user ]
Set Field [ timer::groupUpdate; "u" ]
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
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime
step G1."; Buttons: “OK” ]
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
Clear [ timer::groupUpdate ]
[ Select ]
#
#1b set variables so total record's conditional formatting will match that of the stopwatch being updated.
If [ day1::swSymbols ≠ day1::updateTimeSymbol or $$onoff = "note" ]
Set Variable [ $$folderon; Value:timer::groupID ]
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
Set Variable [ $mergeto; Value:timer::groupID ]
Go to Layout [ “TimerTable” (timer) ]
Enter Find Mode [ ]
Set Field [ timer::groupID; $mergeto ]
// Set Field [ timer::sortRetired; "=" ]
Perform Find [ ]
Perform Script [ “folderStopwatchCheck” ]
#3 go to the first record
Loop
If [ day1::swStart = "" and timer::_lockTimer ≠ timer::groupID ]
Omit Record
Else If [ day1::swStart ≠ "" or timer::_lockTimer = timer::groupID ]
Go to Record/Request/Page
[ Next; Exit after last ]
End If
End Loop
#
Sort Records [ Specified Sort Order: timer::groupType; based on value list: “MergeSort”
timer::description; ascending ]
[ Restore; No dialog ]
#
#3 flag for grand total update
Go to Record/Request/Page
[ First ]
Set Field [ timer::groupOfGroupUpdate; If ( timer::groupOfGroupID ≠ "" ; "u" ; "" ) ]
#
#4 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially
by deleting its current day record and creating a new blank one).
If [ day1::_keyDay = "" ]
Set Variable [ $BrainstateID; Value:timer::_lockTimer ]
Go to Layout [ “DayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyTimer; $BrainstateID ]
Insert Calculated Result [ day1::_keyDay; reference::day1 ]
[ Select ]
Go to Layout [ “TimerTable” (timer) ]
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
#6 if there are no records to add then delete the just created related day record for this total record (this action would be
caused by the user deleting all the time in the linked records).
If [ timer::_lockTimer = timer::groupID ]
If [ day1::swTotalActivity = "0:00:00" ]
Set Variable [ $dayID; Value:day1::_lockDay ]
Go to Layout [ “DayTable” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_lockDay; $dayID ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ “TimerTable” (timer) ]
End If
#
#7 go the next part of the script once there are no more records to add
Exit Loop If [ timer::_lockTimer = timer::groupID ]
#
#8 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
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
Set Field [ timer::_keyUser; $user ]
Set Field [ timer::groupOfGroupUpdate; "u" ]
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
Clear [ timer::groupOfGroupUpdate ]
[ Select ]
#
#2 find its linked records
Set Variable [ $mergeto; Value:timer::groupOfGroupID ]
Go to Layout [ “TimerTable” (timer) ]
Enter Find Mode [ ]
Set Field [ timer::groupOfGroupID; $mergeto ]
Perform Find [ ]
Sort Records [ Specified Sort Order: timer::groupType; based on value list: “MergeSort” ]
[ Restore; No dialog ]
#
#3 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased
(essentially by deleting its current day record and creating a new blank one).
Go to Record/Request/Page
[ First ]
If [ day1::_keyDay = "" ]
Set Variable [ $BrainstateID; Value:timer::_lockTimer ]
Go to Layout [ “DayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyTimer; $BrainstateID ]
Insert Calculated Result [ day1::_keyDay; reference::day1 ]
[ Select ]
Go to Layout [ “TimerTable” (timer) ]
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
If [ timer::_lockTimer = timer::groupOfGroupID ]
If [ day1::swTotalActivity = "0:00:00" ]
Set Variable [ $dayID; Value:day1::_lockDay ]
Go to Layout [ “DayTable” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_lockDay; $dayID ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ “TimerTable” (timer) ]
End If
#
#6 go the next part of the script once there are no more records to add
Exit Loop If [ timer::_lockTimer = timer::groupOfGroupID ]
#
#7 if there is a record to add capture its total time, omit it, go the first record and add this time to current total
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
Set Field [ timer::_lockTimer; $$record ]
Perform Find [ ]
Go to Layout [ $layout ]
Set Variable [ $$stopRecordLoad ]
If [ $mergeID ≠ "" and Left ( $layout ; 5 ) = "Total" ]
Enter Find Mode [ ]
Set Field [ timer::groupID; $mergeID ]
Perform Find [ ]
Else If [ $mergeGrandID ≠ "" and Left ( $layout ; 5 ) = "Grand" ]
Enter Find Mode [ ]
Set Field [ timer::groupOfGroupID; $mergeGrandID ]
Perform Find [ ]
Else If [ Left ( $layout ; 5 ) ≠ "Total" ]
Perform Script [ “goBackButton_FindRecordsChunk” ]
Perform Script [ “CHUNK_lastDayUsed” ]
Perform Script [ “DaySelectSortThenSort” ]
#
#The user entered a time segment in
#the Timer window, dragged its time to
#another time segement, and has not yet
#exited the entered time segment. They then
#went to the Specific Action window and
#clicked the 'start' button, which set this
#variable and started this script.
If [ $$timerWindowCheck = 1 ]
Exit Script [ ]
Else
Halt Script
End If
End If
If [ user::retiredStatus = "r" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: timer::sortRetired: “r” ]
[ Restore ]
End If
Perform Script [ “CHUNK_lastDayUsed” ]
Perform Script [ “DaySelectSortThenSort” ]
December 16, ଘ౮28 14:55:56 ActionLog.fp7 - updateTime -1-
