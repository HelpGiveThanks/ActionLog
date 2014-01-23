action buttons: DeleteBrainstate CHUNKS: CHUNK_deleteRecordsTimeFromTotal
#PURPOSE ﬁnd the to-be-deleted record's total record, omit the to-be-deleted record and then start the process of updating the total records
day records (subtracting the to-be-deleted record's time from these records). By omitting the to-be-deleted at this stage if the computer
crashes or loses power and is then re-booted the program will show that the to-be-deleted still in need of deleting and the process can be
done again becuase the delete takes place as the ﬁnal part of the script.
#CHUNK USED BY DeleteBrainstate Script
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#
#
#1 capture total record's ID number from the record to be deleted and then omit this soon to be deleted record
Set Variable [ $brainstateID; Value:brainstate::groupID ]
Set Variable [ $$deleteID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $displayID; Value:brainstate::_Number ]
Set Variable [ $totaldisplayID; Value:brainstate::groupDisplayID ]
Set Variable [ $description; Value:brainstate::description ]
Set Field [ brainstate::description; " delete interrupted! click here for info: This record is ﬁne, the bad news is the record that totaled its time
may have been corrupted. So this total record ID number -- " & $totaldisplayID & " -- should be deleted and rebuilt if you still want it. // "
& $description ]
Set Field [ brainstate::groupID; "" ]
Set Field [ brainstate::groupDisplayID; "" ]
#
#2 ﬁnd all records linked to this total record
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $brainstateID ]
Perform Find [ ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::description: “" delete inter"” ]
[ Restore ]
#
#DISABLED: I thought these next steps where a good idea: to delete total records with nothing to total. But after thinking about it, I now think I
should allow the user to do this. There is no harm in having a non-working total record. It can always be used again by adding records to it
to total, or by turning it into a regular record.)
// #3 determine if user has deleted all records to total
// If [ Get ( FoundCount ) = 1 and brainstate::_lockBrainstateID = brainstate::groupID ]
// #
// #4 capture total record's mergeID
// Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
// #
// #5 ﬂag for grand total update
// If [ brainstate::groupOfGroupID ≠ "" ]
// Set Field [ brainstate::groupOfGroupUpdate; "u" ]
// End If
// #
// #6 tell user this record is being deleted and why.
// Go to Layout [ <unknown> ]
// Show Custom Dialog [ Title: "!"; Message: "This total record has no more records to total and so it is being deleted. You can always re-create
it by clicking the total button."; Buttons: “OK” ]
// Delete Record/Request
[ No dialog ]
// Enter Find Mode [ ]
// Set Field [ brainstate::_lockBrainstateID; $$deleteID ]
// Perform Find [ ]
// Delete Record/Request
[ No dialog ]
// Perform Script [ “goBackButton” ]
// Halt Script
// End If
#
#4 capture total record's mergeID and remove the t from its merge ﬁeld
Sort Records [ Speciﬁed Sort Order: brainstate::groupType; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ Last ]
Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentTimeStamp ) & " Deleted: " & $displayID & " " & $description ]
#
#5 ﬂag for grand total update
Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
#
Perform Script [ “CHUNK_recalculateTotal” ]
January 5, 平成26 20:08:05 ActionLog.fp7 - CHUNK_deleteRecordsTimeFromTotal -1-
