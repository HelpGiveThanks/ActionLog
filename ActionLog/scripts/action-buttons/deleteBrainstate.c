action buttons: DeleteBrainstate
#PURPOSE determine if user really wants to delete the selected record, delete that record if true, and if it is a total or grand total record also
clear its linked records of their link.
#
#
#
#NOTE: the three # symbols set apart chunks of script.
#NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason,
they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
#
#
If [ brainstate::_lockBrainstateID = brainstate::groupID and brainstate::groupType ≠ "" ]
Show Custom Dialog [ Title: "!"; Message: "Action groups must be deleted from the group display screen. You will taken there now.";
Buttons: “OK”, “Cancel” ]
If [ Get ( LastMessageChoice ) = 2 ]
Halt Script
End If
Perform Script [ “note veto view” ]
Go to Layout [ “TotalSort” (brainstate) ]
Exit Script [ ]
End If
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $userID; Value:reference::farmerID ]
Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $deleteID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $deletelayout; Value:Get ( LayoutName ) ]
Set Variable [ $$deletelayout; Value:Get ( LayoutName ) ]
Set Variable [ $$hide; Value:brainstate::hide ]
#
#
#
#A) BEGIN check if user is in any fields (neccessary because if user is in a field another script could be triggered causing this script to be
terminated).
#
#1 check if user is in any fields and if so halt the script
If [ Get ( ActiveFieldName ) ≠ "" ]
Show Custom Dialog [ Title: "!"; Message: "As long as record is in use it cannot be deleted. Please exit all fields and try again. "; Buttons:
“OK” ]
Halt Script
End If
#
#A) END check if user is in any fields (neccessary because if user is in a field another script could be triggered causing this script to be
terminated).
#
#
#
#B) BEGIN ask for delete confirmation
#
#1) clear the reference. This field is the lock the user must insert the first letter of the record's title to open and then delete the record. This step
insures it is locked! (If there is a value in the field, the field is unlocked and the user could accidently delete a record they really decide that
they want to keep.)
Set Field [ reference::YorN; "" ]
#
#2) open a text box and ask the user to type in the first letter of the records title
Set Variable [ $$warning; Value:brainstate::_lockBrainstateID ]
Refresh Window
Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or 1 space if blank) and click OK to
delete ¶¶"
& brainstate::description; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ] January 5, 平成26 19:52:27 ActionLog.fp7 - DeleteBrainstate -1-action buttons: DeleteBrainstate Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or 1 space if blank) and click OK to
delete ¶¶"
& brainstate::description; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
#
#B) END ask for delete confirmation
#
Set Variable [ $$warning ]
Refresh Window
#
#
#C) BEGIN confirm user wants to delete record or cancel delete
#
#1) halt delete if the user typed nothing and clicked OK or hit the cancel button
If [ reference::YorN = "" ]
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
#
#2) confirm user typed correct letter OR if record was blank and user typed in a blank (this test covers the possibility that first letter of title may
be a blank, and insures the user's desire to delete the record is taken care of in the case of blank or blank looking record).
If [ reference::YorN = Left ( brainstate::description ; 1 ) or reference::YorN = " " and brainstate::description = "" ]
#
#3) if the user failed to follow directions give them all the chances they need to follow them correctly
Else If [ reference::YorN ≠ Left ( brainstate::description ; 1 ) or reference::YorN ≠ " " and brainstate::description = "" ]
Loop
Set Field [ reference::YorN; "" ]
Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or click the space bar once
to type a space in the field below if title appears to be blank) and click OK to delete ¶"
& brainstate::description; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
Exit Loop If [ reference::YorN = Left ( brainstate::description ; 1 )
or
brainstate::description = "" and reference::YorN = " "
or
reference::YorN = "" ]
End Loop
End If
#
#4) recheck if the user typed nothing and clicked OK or hit the cancel button
If [ reference::YorN = "" ]
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
#
#C) END confirm user wants to delete record or cancel delete
#
#
#
#D) BEGIN delete total or grandtotal record
#
#1) check if total or grandtotal record and if so perform the CHUNK_deleteTotalOrGrandtotalRecord script
If [ brainstate::groupType ≠ "" and brainstate::_lockBrainstateID = brainstate::groupID
 or
brainstate::groupType ≠ "" and brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
January 5, 平成26 19:52:27 ActionLog.fp7 - DeleteBrainstate -2-action buttons: DeleteBrainstate
Perform Script [ “CHUNK_deleteTotalOrGrandtotalRecord” ]
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
#
#D) END delete total or grandtotal record
#
#
#
#E) BEGIN determine if record is linked to a total record and subtract it
#
#1) subtract record's time from total if it was part of a total.
If [ brainstate::groupID ≠ "" ]
Perform Script [ “CHUNK_deleteRecordsTimeFromTotal” ]
#
#2) capture mergeID (necessary if user was on the totalview layout for returning the user to that layout and showing only the records with
the same mergeID)
Set Variable [ $brainstateID; Value:brainstate::groupID ]
#
#E) END determine if record is linked to a total record and subtract it
#
#
#
#F) BEGIN delete record linked to a total record and a grandtotal record
#
#1) subtract record's time from a grandtotal if this record was part of a grandtotal
If [ brainstate::groupOfGroupUpdate = "u" ]
Perform Script [ “CHUNK_recalculateGrandTotal” ]
#
#2) delete the record chosen to be deleted aftering updating total and grandtotal
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$deleteID ]
Perform Find [ ]
If [ brainstate::_lockBrainstateID = $deleteID ]
Delete Record/Request
[ No dialog ]
Else If [ brainstate::_lockBrainstateID ≠ $deleteID ]
Show Custom Dialog [ Title: "!"; Message: "Error peforming F2 of the DeleteBrainstate script."; Buttons: “OK” ]
End If
#
#3) if user was on the viewTotal screen find only those records that are part of the total being viewed prior to deleting and show the
user those records on that layout.
If [ Left ( $deletelayout ; 5 ) = "Total" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $brainstateID ]
Perform Find [ ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Layout [ $$deletelayout ]
// #NOT TESTED
// If [ Get ( SystemPlatform ) = 3 ]
// Go to Layout [ “TotalMainiPhone” (brainstate) ]
// End If
// #END NOT TESTED
Go to Field [ ]
January 5, 平成26 19:52:27 ActionLog.fp7 - DeleteBrainstate -3-action buttons: DeleteBrainstate
Set Variable [ $$warning ]
Refresh Window
Halt Script
End If
#
#4) if user was not on the viewTotal screen go back to the layout user was on and show records that users was looking at
Perform Script [ “goBackButton” ]
End If
End If
#
#F) END delete record linked to a total record and a grandtotal record
#
#
#
#G) BEGIN delete record
#
#1) delete the record chosen to be deleted
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $deleteID ]
Perform Find [ ]
If [ brainstate::_lockBrainstateID = $deleteID ]
Delete Record/Request
[ No dialog ]
Else If [ brainstate::_lockBrainstateID ≠ $deleteID ]
Show Custom Dialog [ Title: "!"; Message: "Error peforming G1 of the DeleteBrainstate script."; Buttons: “OK” ]
End If
#
#2) if user was on the viewTotal screen find only those records that are part of the total being viewed prior to deleting and show the user those
records on that layout.
If [ Left ( $deletelayout ; 4 ) = "Tota" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $brainstateID ]
Perform Find [ ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Layout [ $$deletelayout ]
// #NOT TESTED
// If [ Get ( SystemPlatform ) = 3 ]
// Go to Layout [ “TotalMainiPhone” (brainstate) ]
// End If
// #END NOT TESTED
Go to Field [ ]
Halt Script
End If
#
#3) if user was not on the view Total screen, go back to the layout user was on and show records that users was looking at
Perform Script [ “goBackButton” ]
Halt Script
#
#G) END delete record
January 5, 平成26 19:52:27 ActionLog.fp7 - DeleteBrainstate -4-
