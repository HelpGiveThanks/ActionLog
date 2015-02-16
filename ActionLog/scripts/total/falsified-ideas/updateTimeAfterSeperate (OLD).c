total: falsified ideas: UpdateTimeAfterSeperate (OLD)
#PURPOSE separate a record it total record only deleting only the time on the day separated, but keeping the time previously added. This
turned out not to be a good idea. If the user re-adds this record to the total, its time doubled on those days its time was not deleted during
the separate.
// #
// #
// #
// #NOTE: the three # symbols set apart chunks of script.
// #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this
reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
// #
// #
// #
// #basic administration tasks
// Set Error Capture [ On ]
// Allow User Abort [ Off ]
// Set Variable [ $userID; Value:reference::farmerID ]
// #
// #
// #
// #A) BEGIN go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect
of the window while performing the script.
// #
// #1 open a new window and hide it
// New Window [ Name: "UpateTime"; Height: 100; Width: 100 ]
// Adjust Window
[ Hide ]
// Go to Layout [ “calcBrainstateTable” (brainstate) ]
// #
// #A) END go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of
the window while performing the script.
// #
// #
// #
// #B) BEGIN mark record for grandtotal update (if it is part of one) and determine if the just separated record was the last record this total
record was summing up.
// #
// #1 ﬂag for grand total update
// Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort”
brainstate::description; ascending ]
[ Restore; No dialog ]
// Go to Record/Request/Page
[ First ]
// Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
// #
// #2 determine if user has deleted all records to total and if so give them the option to turn this total record into a normal record or add another
record to it to keep it as a total record.
// If [ Get ( FoundCount ) = 1 and brainstate::_lockBrainstateID = brainstate::groupID ]
// If [ day1::_keyDay ≠ "" ]
// Set Variable [ $dayID; Value:day1::_lockDay ]
// Go to Layout [ “calcDayTable” (day1) ]
// Enter Find Mode [ ]
// Set Field [ day1::_lockDay; $dayID ]
// Perform Find [ ]
// Delete Record/Request
[ No dialog ]
// End If
// Close Window [ Name: "UpateTime"; Current file ]
// Go to Layout [ “totalViewSeparated” (brainstate) ]
January 5, 平成26 14:14:24 ActionLog.fp7 - UpdateTimeAfterSeperate (OLD) -1-total: falsified ideas: UpdateTimeAfterSeperate (OLD)
// Show Custom Dialog [ Title: "!"; Message: "Option 1) To make this record a non-total record, change its name (opptional), and click the
go back button.¶Option 2) To keep it as a total record, click the add button and select 1 or more records for it to total."; Buttons: “OK” ]
// Go to Field [ brainstate::description ]
// Halt Script
// End If
// #
// #B) END mark record for grandtotal update (if it is part of one) and determine if the just separated record was the last record this total record
was summing up.
// #
// #
// #
// #C) BEGIN total record
// #
// #1 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially by deleting its
current day record and creating a new blank one).
// If [ day1::_keyDay = "" ]
// Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
// Go to Layout [ “calcDayTable” (day1) ]
// New Record/Request
// Set Field [ day1::_keyBrainstate; $BrainstateID ]
// Insert Calculated Result [ day1::_keyDay; reference::day1 ]
[ Select ]
// Go to Layout [ “calcBrainstateTable” (brainstate) ]
// End If
// Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
// Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
// #
// Loop
// #
// #2 go to the last record
// Go to Record/Request/Page
[ Last ]
// #
// #3 if there are no records to add then delete the just created related day record for this total record (this action would be caused by the
user deleting all the time in the linked records).
// If [ brainstate::_lockBrainstateID = brainstate::groupID ]
// If [ day1::swTotalActivity = "0:00:00" ]
// Set Variable [ $dayID; Value:day1::_lockDay ]
// Go to Layout [ “calcDayTable” (day1) ]
// Enter Find Mode [ ]
// Set Field [ day1::_lockDay; $dayID ]
// Perform Find [ ]
// Delete Record/Request
[ No dialog ]
// Go to Layout [ “calcBrainstateTable” (brainstate) ]
// End If
// #
// #4 go the next part of the script once there are no more records to add
// Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupID ]
// #
// #5 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
January 5, 平成26 14:14:24 ActionLog.fp7 - UpdateTimeAfterSeperate (OLD) -2-total: falsified ideas: UpdateTimeAfterSeperate (OLD)
// Else If [ day1::_keyDay = "" ]
// Omit Record
// Else If [ day1::_keyDay ≠ "" ]
// Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
// Omit Record
// Go to Record/Request/Page
[ First ]
// Insert Calculated Result [ day1::swPause; Case (
$TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ;
$TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ;
day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
[ Select ]
// End If
// End Loop
// #
// #C) END update found record
// #
// #
// #
// Loop
// #
// #D) BEGIN find all user GRAND total records that need to be udated
// #
// #1 find records
// Enter Find Mode [ ]
// Set Field [ brainstate::_keyUser; $user ]
// Set Field [ brainstate::groupOfGroupUpdate; "u" ]
// Perform Find [ ]
// #
// #2 if no records are found go to step
// Exit Loop If [ Get ( LastError ) = 401 ]
// #
// #
// #
// #BEGIN error 1
// If [ Get ( LastError ) ≠ 0 ]
// #tell user the error number
// Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime step i1.";
Buttons: “OK” ]
// Close Window [ Name: "UpateTime"; Current file ]
// Exit Script [ ]
// End If
// #END error 1
// #
// #
// #
// #D) END find all user GRAND total records that need to be udated
// #
// #
// #
// #E) BEGIN update found record
// #
// #1 unﬂag this total record for grand total update
// Clear [ brainstate::groupOfGroupUpdate ]
[ Select ]
January 5, 平成26 14:14:24 ActionLog.fp7 - UpdateTimeAfterSeperate (OLD) -3-total: falsified ideas: UpdateTimeAfterSeperate (OLD) // Clear [ brainstate::groupOfGroupUpdate ]
[ Select ]
// #
// #2 find its linked records
// Set Variable [ $mergeto; Value:brainstate::groupOfGroupID ]
// Go to Layout [ “calcBrainstateTable” (brainstate) ]
// Enter Find Mode [ ]
// Set Field [ brainstate::groupOfGroupID; $mergeto ]
// Perform Find [ ]
// Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” ]
[ Restore; No dialog ]
// #
// #3 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially by deleting
its current day record and creating a new blank one).
// Go to Record/Request/Page
[ First ]
// If [ day1::_keyDay = "" ]
// Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
// Go to Layout [ “calcDayTable” (day1) ]
// New Record/Request
// Set Field [ day1::_keyBrainstate; $BrainstateID ]
// Insert Calculated Result [ day1::_keyDay; reference::day1 ]
[ Select ]
// Go to Layout [ “calcBrainstateTable” (brainstate) ]
// End If
// Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
// Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
// #
// Loop
// #
// #4 go to the last record
// Go to Record/Request/Page
[ Last ]
// #
// #5 if there are no records to add then delete the just created related day record for this total record (this action would be caused by
the user deleting all the time in the linked records).
// If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
// If [ day1::swTotalActivity = "0:00:00" ]
// Set Variable [ $dayID; Value:day1::_lockDay ]
// Go to Layout [ “calcDayTable” (day1) ]
// Enter Find Mode [ ]
// Set Field [ day1::_lockDay; $dayID ]
// Perform Find [ ]
// Delete Record/Request
[ No dialog ]
// Go to Layout [ “calcBrainstateTable” (brainstate) ]
// End If
// #
// #6 go the next part of the script once there are no more records to add
// Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
// #
// #7 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
January 5, 平成26 14:14:24 ActionLog.fp7 - UpdateTimeAfterSeperate (OLD) -4-total: falsified ideas: UpdateTimeAfterSeperate (OLD)
// #7 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
// Else If [ day1::_keyDay = "" ]
// Omit Record
// Else If [ day1::_keyDay ≠ "" ]
// Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
// Omit Record
// Go to Record/Request/Page
[ First ]
// Insert Calculated Result [ day1::swPause; Case (
$TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ;
$TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ;
day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
[ Select ]
// End If
// End Loop
// End Loop
// #
// #8) close window and sort records
// Close Window [ Name: "UpateTime"; Current file ]
// Perform Script [ “sortRestoreAfterScript” ]
// #
// #E) END update found record
January 5, 平成26 14:14:24 ActionLog.fp7 - UpdateTimeAfterSeperate (OLD) -5-
