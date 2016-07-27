show/hide buttons and checkboxes: retireCheckbox
#PURPOSE change the user's retired status and note this change in the records info box
#
#
#
#1 retire the record and note this change in status. (The if test says to look for a non-blank record and this is because the checkbox has
inserted the letter r before this script is activated. So the record will not be blank when the user wants it retired.)
If [ brainstate::sortRetired ≠ "" ]
Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶retired: " & Get ( CurrentTimeStamp ) ]
End If
#neccessary step to remove focus from checkbox
Go to Field [ ]
#
#2 if the user current has elected to hide all retired records hide this newly retired record and also tell user why it is being
hidden/omitted.
If [ brainstate::sortRetired ≠ "" and steward::retiredStatus ≠ "" ]
Show Custom Dialog [ Title: "retired"; Message: "You currently have the hide retired or r button on. So this record will now be
hidden. ¶¶To see this record again, click the r button."; Buttons: “OK”, “cancel” ]
If [ Get (LastMessageChoice) = 2 ]
Set Field [ brainstate::sortRetired; "" ]
Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶un-retired: " & Get ( CurrentTimeStamp ) ]
Go to Field [ ]
Exit Script [ ]
Else
Omit Record
End If
End If
#
#3 un- retire the record and note this change in status. (The if test says to look for a record and this is because the checkbox has
deleted the letter r before this script is activated. So the record will be blank when the user wants the record un-retired.)
If [ brainstate::sortRetired = "" ]
Set Field [ brainstate::sortRetired; "" ]
Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶un-retired: " & Get ( CurrentTimeStamp ) ]
End If
#neccessary step to remove focus from checkbox
Go to Field [ ]
July 26, ଘ౮28 14:10:09 ActionLog.fp7 - retireCheckbox -1-
