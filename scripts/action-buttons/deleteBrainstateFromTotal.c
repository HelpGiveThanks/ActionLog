action buttons: DeleteBrainstateFromTotal
#PURPOSE determine if user really wants to delete the selected record, delete that record if true, and if it is a total or grand total record also
clear its linked records of their link.
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
Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $mergeID; Value:brainstate::groupID ]
Set Variable [ $deleteID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $deletelayout; Value:Get ( LayoutName ) ]
Set Variable [ $$deletelayout; Value:Get ( LayoutName ) ]
Set Variable [ $$record; Value:Get ( RecordNumber ) ]
#
#
#
#A) BEGIN check if user is in any ﬁelds (neccessary because if user is in a ﬁeld another script could be triggered causing this script to be
terminated).
#
#1 check if user is in any ﬁelds and if so halt the script
If [ Get ( ActiveFieldName ) ≠ "" ]
Show Custom Dialog [ Title: "!"; Message: "As long as record is in use it cannot be deleted. Please exit all ﬁelds and try again. "; Buttons:
“OK” ]
Halt Script
End If
#
#A) END check if user is in any ﬁelds (neccessary because if user is in a ﬁeld another script could be triggered causing this script to be
terminated).
#
#
#
#B) BEGIN ask for delete conﬁrmation
#
#1) clear the reference. This ﬁeld is the lock the user must insert the ﬁrst letter of the record's title to open and then delete the record. This step
insures it is locked! (If there is a value in the ﬁeld, the ﬁeld is unlocked and the user could accidently delete a record they really decide that
they want to keep.)
Set Field [ reference::YorN; "" ]
#
#2) open a text box and ask the user to type in the ﬁrst letter of the records title
Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or 1 space if blank) and click OK to
delete ¶¶"
& brainstate::description; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
#
#B) END ask for delete conﬁrmation
#
#
#
#C) BEGIN conﬁrm user wants to delete record or cancel delete
#
#1) halt delete if the user typed nothing and clicked OK or hit the cancel button
January 5, 平成26 19:53:12 ActionLog.fp7 - DeleteBrainstateFromTotal -1-action buttons: DeleteBrainstateFromTotal
If [ reference::YorN = "" ]
Halt Script
End If
#
#2) conﬁrm user typed correct letter OR if record was blank and user typed in a blank (this test covers the possibility that ﬁrst letter of title may
be a blank, and insures the user's desire to delete the record is taken care of in the case of blank or blank looking record).
If [ reference::YorN = Left ( brainstate::description ; 1 ) or reference::YorN = " " and brainstate::description = "" ]
#
#3) if the user failed to follow directions give them all the chances they need to follow them correctly
Else If [ reference::YorN ≠ Left ( brainstate::description ; 1 ) or reference::YorN ≠ " " and brainstate::description = "" ]
Loop
Set Field [ reference::YorN; "" ]
Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or click the space bar once
to type a space in the ﬁeld below if title appears to be blank) and click OK to delete ¶"
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
Halt Script
End If
#
#C) END conﬁrm user wants to delete record or cancel delete
#
#
#
#D) BEGIN delete total or grandtotal record
#
#1) check if total or grandtotal record and if so perform the CHUNK_deleteTotalOrGrandtotalRecord script
If [ brainstate::groupType ≠ "" ]
Perform Script [ “CHUNK_deleteTotalOrGrandtotalRecord” ]
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
January 5, 平成26 19:53:12 ActionLog.fp7 - DeleteBrainstateFromTotal -2-action buttons: DeleteBrainstateFromTotal
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
#3) if user was on the viewTotal screen ﬁnd only those records that are part of the total being viewed prior to deleting and show the
user those records on that layout.
If [ Left ( $deletelayout ; 5 ) = "total" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $mergeID ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: brainstate::_lockBrainstateID; descending ]
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
#4) if user was not on the viewTotal screen go back to the layout user was on and show records that users was looking at
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
January 5, 平成26 19:53:12 ActionLog.fp7 - DeleteBrainstateFromTotal -3-action buttons: DeleteBrainstateFromTotal
Show Custom Dialog [ Title: "!"; Message: "Error peforming G1 of the DeleteBrainstate script."; Buttons: “OK” ]
End If
#
#2) if user was on the viewTotal screen ﬁnd only those records that are part of the total being viewed prior to deleting and show the user those
records on that layout.
If [ Left ( $deletelayout ; 4 ) = "Tota" ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $brainstateID ]
Perform Find [ ]
#
#4 it the user wants retired records hidden then hide these records if any
// If [ steward::retiredStatus ≠ "" ]
// Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
// End If
Perform Script [ “CHUNK_retire” ]
#
Perform Script [ “CHUNK_DaySelectSortThenSort” ]
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
Halt Script
#
#G) END delete record
January 5, 平成26 19:53:12 ActionLog.fp7 - DeleteBrainstateFromTotal -4-
