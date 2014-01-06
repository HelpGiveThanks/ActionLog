action buttons: DeleteFarmer
#PURPOSE determine if user really wants to delete the selected record and delete that record if true.
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
#
#
#
#A) BEGIN check if user is in any ﬁelds (neccessary because if user is in a ﬁeld another script could be triggered causing this script to be
terminated).
#
#1 check if there are 2 or more records to merge and if not halt the script. (Can't merge if zero or 1 records are selected.
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
#B) BEGIN check to insure user has something they can use a password to delete this record and all records associated with it
#
#1 password check
If [ WordCount ( steward::FirstName ) + WordCount ( steward::LastName ) = 0 ]
Show Custom Dialog [ Title: "!"; Message: "You must have something (other than spaces) typed in at least the ﬁrst or last name text boxes
to use as a password to delete this record."; Buttons: “OK” ]
Halt Script
End If
#
#B) END check to insure user has something they can use a password to delete this record and all records associated with it
#
#
#
#C) BEGIN ask for delete conﬁrmation
#
#1) clear the reference. This ﬁeld is the lock the user must insert the ﬁrst letter of the record's title to open and then delete the record. This step
insures it is locked!
Set Field [ reference::YorN; "" ]
#
#2) open a text box and ask the user to type in the full name of the user to be deleted
Show Custom Dialog [ Title: "DELETE steward::FirstPlusLast"; Message: "Type the full name as shown below and click OK to delete all
records for this person. ¶¶"
& steward::FirstPlusLast; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
#
#C) END ask for delete conﬁrmation
January 5, 平成26 19:53:52 ActionLog.fp7 - DeleteFarmer -1-action buttons: DeleteFarmer
#
#
#
#D) BEGIN delete
#
#1) halt delete if the user typed nothing or hit the cancel button
If [ reference::YorN = "" ]
Halt Script
#
#2) conﬁrm user typed correct name
Else If [ reference::YorN = steward::FirstPlusLast or
reference::YorN = steward::FirstName and steward::LastName = "" ]
#
#3) delete
Delete Record/Request
[ No dialog ]
Halt Script
#
End If
#
#4) if the user failed to follow directions give them another chance
Loop
Set Field [ reference::YorN; "" ]
Show Custom Dialog [ Title: "DELETE steward::FirstPlusLast"; Message: "Type the full name as shown below and click OK to delete all
records for this person. ¶¶"
& steward::FirstPlusLast; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
Exit Loop If [ reference::YorN = steward::FirstPlusLast
 or
reference::YorN = steward::FirstName and steward::LastName = ""
or
reference::YorN = "" ]
End Loop
#
#5) halt delete if the user typed nothing or hit the cancel button
If [ reference::YorN = "" ]
Halt Script
End If
#
#6) delete
Delete Record/Request
[ No dialog ]
Halt Script
#
#D) END delete
January 5, 平成26 19:53:52 ActionLog.fp7 - DeleteFarmer -2-
