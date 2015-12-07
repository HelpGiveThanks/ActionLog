specific action log: updateModifyDate
#
#
#Two script sections to change modify date.
#
#
#
#This section updates records with no logged time.
// Set Variable [ $$stopRecordLoad; Value:1 ]
// Go to Record/Request/Page
[ First ]
// Loop
// If [ issue::issueTotalTime = "" ]
// Set Field [ issue::dateModified; issue::DisplayDate ]
// End If
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
// Set Variable [ $$stopRecordLoad ]
// Exit Script [ ]
#
#
#
#This section udpates modify date to last date
#time was logged for this specific action record.
Set Variable [ $$stopRecordLoad; Value:1 ]
Go to Record/Request/Page
[ First ]
#
Loop
Set Variable [ $issue; Value:issue::_LockList ]
If [ issue::issueTotalTime ≠ "" ]
Select Window [ Name: "Day"; Current file ]
Go to Record/Request/Page
[ First ]
Loop
If [ $issue & "¶" = FilterValues ( logs::_keyLogIssues ; $issue & "¶" ) ]
Set Variable [ $modate; Value:logs::_keyDay & " 12:00:00 PM" ]
End If
Exit Loop If [ $issue & "¶" = FilterValues ( logs::_keyLogIssues ; $issue & "¶" ) ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Select Window [ Name: "Specific Action"; Current file ]
Set Field [ issue::dateModified; $modate ]
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Set Variable [ $$stopRecordLoad ]
December 6, ଘ౮27 22:01:05 ActionLog.fp7 - updateModifyDate -1-
