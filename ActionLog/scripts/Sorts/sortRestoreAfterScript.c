Sorts: sortRestoreAfterScript
#PURPOSE after another script is run that may change time values this script is run to re-sort the records according time unless the user has
them sorted another way, in which case this script is halted and no sort is performed.
#
#
#
#1 check if the sort status ﬁeld to see if the user is currently sorting by time and if so sort the records
If [ steward::chosenSort = "wact" or
steward::chosenSort = "wtca" or
steward::chosenSort = "act" or
steward::chosenSort = "tca" or
steward::chosenSort = "veto" or
steward::chosenSort = "etov" or
steward::chosenSort = "allow" or
steward::chosenSort = "wolla" or
steward::chosenSort = "Brainstates A-Z" or
steward::chosenSort = "Brainstates Z-A" ]
Sort Records [ Speciﬁed Sort Order: day1::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
#
#not sure why I put this in here. So I'm leaving it for now until its use become apparent or I'm satisiﬁed it is not needed.
// If [ day1::_keyDay = "" ]
// Go to Record/Request/Page
[ First ]
// End If
End If
// If [ steward::chosenSort = "act" or
steward::chosenSort = "tca" or
steward::chosenSort = "veto" or
steward::chosenSort = "etov" or
steward::chosenSort = "allow" or
steward::chosenSort = "wolla" ]
// Show Custom Dialog [ Title: "!"; Message: "Your list of records has been resorted based on time: total time, start time, or f-stop time.";
Buttons: “OK” ]
// End If
January 5, 平成26 20:15:09 ActionLog.fp7 - sortRestoreAfterScript -1-
