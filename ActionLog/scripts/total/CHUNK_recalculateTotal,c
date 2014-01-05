total: CHUNK_recalculateTotal
#PURPOSE recalculate the total time for each day for the given set of records
#CHUNK USED BY DeleteBrainstate Script
#CHUNK USED BY seperateFromTotal Script
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
Set Variable [ $brainstateID; Value:brainstate::groupID ]
#
#
#
#A) BEGIN delete total's day records
#
#1 delete all the total's day records, which will include some of the time from the just separated or soon to be deleted record. (Now we are ready
to create new total records for the records that remain.)
Enter Find Mode [ ]
Go to Layout [ “calcTotalNewRecord” (day2) ]
Set Field [ day2::_keyBrainstate; $brainstateID ]
Perform Find [ ]
#
#2 double check to insure records to be deleted are the right records. (During testing all 900+ records where deleted from my database. I think
what happened is the ﬁnd came up with zero records and then displayed all the records in the database and the next step deleted them.
This If check will prevent that from happening again if that is what happened. I have been unable to duplicate this massive error, so this
might not be reason why all the records where deleted, but this is the only time when the database is told to delete all found records, rather
than just one record, so I ﬁgure it must have been caused here.)
If [ day2::_keyBrainstate = $brainstateID ]
Delete All Records
[ No dialog ]
End If
#
#A) END delete total's day records
#
#
#
Loop
#B) BEGIN check if there are records to be totaled
#
#1 make sure there is a record to be totaled (this step will be important when this loop is repeated after the ﬁrst record to be totaled is
omitted).
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Go to Record/Request/Page
[ First ]
#
#If all records are empty then the total is complete and now the user needs to be shown the new total record and all the records that will
feed into it until they are separated.
If [ brainstate::_lockBrainstateID = brainstate::groupID ]
Exit Script [ ]
End If
#
#B) END check if there are records to be totaled
#
January 5, 平成26 13:24:44 ActionLog.fp7 - CHUNK_recalculateTotal -1-total: CHUNK_recalculateTotal
#
#
#C BEGIN ﬁnd total record's related day records
#
#1 make a list of the ﬁrst brainstate's day records in a new window
Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
Go to Layout [ “calcTotalSelectedList” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
Perform Find [ ]
#
#C END ﬁnd total record's related day records
#
#
#
#D BEGIN no records found loop (this loop will either complete the total process or ﬁnd a record with related day records to be added to the
total record)
#
Loop
#
#1 if records are found exit loop
Exit Loop If [ Get ( LastError ) = 0 ]
#
#2 clear the merge ﬁeld (the big X in the box on the ToBeMerged layout) and omit this record
If [ Get ( LastError ) = 401 ]
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Set Field [ brainstate::groupAddCheckbox; "" ]
Omit Record
#
#
#
#
#If all records are empty then the total is complete and now the user needs to be shown the new total record and all the records
that will feed into it until they are separated.
If [ brainstate::_lockBrainstateID = brainstate::groupID ]
Exit Script [ ]
End If
#
#
#BEGIN ﬁnd error 2
Else If [ Get ( LastError ) ≠ 0 ]
#tell user the error number
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming merge script part D2.";
Buttons: “OK” ]
#Find all records user had showing when they clicked the merge button
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
If [ steward::retiredStatus = "r" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::hide: “t” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
January 5, 平成26 13:24:44 ActionLog.fp7 - CHUNK_recalculateTotal -2-total: CHUNK_recalculateTotal
Halt Script
End If
If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::Show: “=” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
Halt Script
End If
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Halt Script
End If
#END ﬁnd error 2
#
#
#
#3 make a list of this record's day records in a new window.
Go to Layout [ “calcTotalSelectedList” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
Perform Find [ ]
End Loop
#
#D END no records found loop (this loop will either complete the total process or ﬁnd a record with related day records to be added to the
total record)
#
#
#
#E BEGIN create new related day records and add selected record's time to them
#
Loop
#1 ﬁnd any day records for the new brainstate that match the kfDay of the ﬁrst merge record. If this new record already has data in it,
then we want to add new data to the old data; not replace the old data with new data.
Set Variable [ $mergeDay; Value:day1::_keyDay ]
Enter Find Mode [ ]
Go to Layout [ “calcTotalNewRecord” (day2) ]
Set Field [ day2::_keyBrainstate; $brainstateID ]
Set Field [ day2::_keyDay; $mergeDay ]
Perform Find [ ]
#
#2 if no matches are found, create a new day record and put in the time of the ﬁrst the current day record
If [ Get ( LastError ) = 401 ]
New Record/Request
Set Field [ day2::_keyBrainstate; $brainstateID ]
Set Field [ day2::_keyDay; $mergeDay ]
Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
Go to Layout [ “calcTotalSelectedList” (day1) ]
Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
Go to Layout [ “calcTotalNewRecord” (day2) ]
Set Field [ day2::swPause; Case (
$TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ;
$TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ;
day2::_keyDay & " " & $TotalActivity )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
January 5, 平成26 13:24:44 ActionLog.fp7 - CHUNK_recalculateTotal -3-total: CHUNK_recalculateTotal
Set Field [ day2::swPause; Case (
$TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ;
$TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ;
day2::_keyDay & " " & $TotalActivity )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
#
#
#
#BEGIN ﬁnd error 3
Else If [ Get ( LastError ) ≠ 0 ]
#tell user the error number
Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming merge script part E2."; Buttons:
“OK” ]
#Find all records user had showing when they clicked the merge button.
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
If [ steward::retiredStatus = "r" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::hide: “t” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
Halt Script
End If
If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::Show: “=” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
Halt Script
End If
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Halt Script
#END ﬁnd error 3
#
#
#
#3 if a match is found, then add the current day's time to this day's time.
Else If [ Get ( LastError ) = 0 ]
Go to Layout [ “calcTotalSelectedList” (day1) ]
Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
Go to Layout [ “calcTotalNewRecord” (day2) ]
Set Field [ day2::swPause; Case (
$TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ;
$TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ;
day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
End If
#
#4 repeat loop for found record's next related day record.
January 5, 平成26 13:24:44 ActionLog.fp7 - CHUNK_recalculateTotal -4-total: CHUNK_recalculateTotal
Go to Layout [ “calcTotalSelectedList” (day1) ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#E END create new related day records and add selected record's time to them
#
#
#
#F BEGIN go to next record with related day records to be added to the new total record.
#
Go to Layout [ “calcBrainstateTable” (brainstate) ]
#Clear the merge ﬁeld (the big X in the box on the ToBeMerged layout).
Set Field [ brainstate::groupAddCheckbox; "" ]
Omit Record
#
#F END go to next record with related day records to be added to the new total record.
#
#
#
End Loop
January 5, 平成26 13:24:44 ActionLog.fp7 - CHUNK_recalculateTotal -5-
