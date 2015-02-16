action buttons: DeleteBrainstate CHUNKS: CHUNK_deleteTotalOrGrandtotalRecord
#PURPOSE delete a total or grand total record and also clear the linked records of their link to it (the records that add up to the total/grandtotal
being deleted).
#CHUNK USED BY DeleteBrainstate Script
#
#
#
#NOTE: the three # symbols set apart chunks of script.
#NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason,
they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#
#A BEGIN delete total record
#
#1 if total record find all linked records so that they can be cleared of their link
If [ brainstate::groupType = "merge" ]
Set Variable [ $mergeID; Value:brainstate::groupID ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $mergeID ]
Perform Find [ ]
#
#
#
#BEGIN find error 1
If [ Get ( LastError ) ≠ 0 ]
#tell user the error number.
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming
CHUNK_deleteTotalOrGrandtotalRecord script part A1."; Buttons: “OK” ]
#Find all records user had showing when they clicked the merge button
Perform Script [ “goBackButton” ]
End If
#END find error 1
#
#
#
#2 clear all the linked record's linked to the old total record
Go to Record/Request/Page
[ First ]
Loop
Set Field [ brainstate::groupID; "" ]
Set Field [ brainstate::groupDisplayID; "" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#3 sort the total record to the top and mark it for deletion. (Delete is the last step in the process so if the computer crashes or loses power
the user can still complete the delete process. If the record was deleted before the links the where deleted and the computer crashed,
those linked records would forever be linked to the now deleted total record unless the user could directly access the data table.)
Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
January 5, 平成26 19:58:03 ActionLog.fp7 - CHUNK_deleteTotalOrGrandtotalRecord -1-action buttons: DeleteBrainstate CHUNKS: CHUNK_deleteTotalOrGrandtotalRecord
Set Variable [ $$deleteID; Value:brainstate::_lockBrainstateID ]
If [ brainstate::groupOfGroupID ≠ "" ]
#
#4 capture total record's ID number from the record to be deleted and then omit this soon to be deleted record
Set Variable [ $brainstateID; Value:brainstate::groupOfGroupID ]
Set Variable [ $displayID; Value:brainstate::_Number ]
Set Variable [ $description; Value:brainstate::description ]
Set Field [ brainstate::description; " delete interrupted! click here for info: This record should be deleted, along with this total record
ID number -- " & $brainstateID & ". You can then rebuild it using the total process. // " & $description ]
Set Field [ brainstate::groupOfGroupID; "" ]
Omit Record
#
#5 make a list of the grandtotal records it is being removed from so that they can be used to re-total the grandtotal
Go to Layout [ “calcBrainstateTable” (brainstate) ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $brainstateID ]
Perform Find [ ]
Sort Records [ Specified Sort Order: brainstate::groupAddCheckbox; descending
brainstate::groupType; based on value list: “MergeSort” ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentTimeStamp ) & " Deleted: " & $displayID & " " & $description ]
#
#6 subtract record's time from grandtotal
Perform Script [ “CHUNK_recalculateGrandTotal” ]
#
#7 delete the record chosen to be deleted
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$deleteID ]
Perform Find [ ]
If [ brainstate::_lockBrainstateID = $$deleteID ]
Delete Record/Request
[ No dialog ]
Else If [ brainstate::_lockBrainstateID ≠ $$deleteID ]
Show Custom Dialog [ Title: "!"; Message: "Error peforming A7 of the CHUNK_deleteTotalOrGrandtotalRecord script."; Buttons:
“OK” ]
End If
#
#8 if user was on the viewGrandtotal layout find only those records that are part of the grandtotal being viewed prior to deleting and
show the user those records on that layout.
If [ Left ( $$deletelayout ; 5 ) = "viewG" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupOfGroupID; $brainstateID ]
Perform Find [ ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Layout [ “GrandTotal” (brainstate) ]
Go to Field [ ]
Halt Script
End If
#
#9 if user was not on the viewgrandotal layout go back to the layout user was on and show records that users was looking at
Perform Script [ “goBackButton” ]
Halt Script
End If
#
January 5, 平成26 19:58:03 ActionLog.fp7 - CHUNK_deleteTotalOrGrandtotalRecord -2-action buttons: DeleteBrainstate CHUNKS: CHUNK_deleteTotalOrGrandtotalRecord
#9 delete total record
Delete Record/Request
[ No dialog ]
Set Variable [ $$deleteID; Value:"total" ]
Perform Script [ “goBackButton” ]
Halt Script
#
#A END delete total record
#
#
#
#B BEGIN delete grandtotal record
#
#1 if grand total record find all linked records so that they can be cleared of their link
Else If [ brainstate::groupType = "mergeGrand" ]
Set Variable [ $mergeID; Value:brainstate::groupOfGroupID ]
Enter Find Mode [ ]
Set Field [ brainstate::groupOfGroupID; $mergeID ]
Perform Find [ ]
#
#
#
#BEGIN find error 2
If [ Get ( LastError ) ≠ 0 ]
#tell user the error number.
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming delete script part C8."; Buttons:
“OK” ]
#Find all records user had showing when they clicked the merge button
Perform Script [ “goBackButton” ]
End If
#END find error 2
#
#
#
#2 clear all the linked record's linked to the old grand total record
Go to Record/Request/Page
[ First ]
Loop
Set Field [ brainstate::groupOfGroupID; "" ]
Set Field [ brainstate::groupOfGroupDisplayID; "" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#3 sort the grandtotal record to the top and delete it
Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Variable [ $$deleteID; Value:brainstate::_lockBrainstateID ]
If [ brainstate::_lockBrainstateID = $$deleteID ]
Delete Record/Request
[ No dialog ]
Else If [ brainstate::_lockBrainstateID ≠ $$deleteID ]
Show Custom Dialog [ Title: "!"; Message: "Error peforming B2 of the CHUNK_deleteTotalOrGrandtotalRecord script."; Buttons:
“OK” ]
End If
January 5, 平成26 19:58:03 ActionLog.fp7 - CHUNK_deleteTotalOrGrandtotalRecord -3-action buttons: DeleteBrainstate CHUNKS: CHUNK_deleteTotalOrGrandtotalRecord
#
#4 return user to previous layout and halt the script
Set Variable [ $$deleteID; Value:"grandtotal" ]
Perform Script [ “goBackButton” ]
Halt Script
#
End If
#
#B END delete grandtotal record
January 5, 平成26 19:58:03 ActionLog.fp7 - CHUNK_deleteTotalOrGrandtotalRecord -4-
