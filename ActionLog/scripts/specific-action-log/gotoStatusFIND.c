specific action log: gotoStatusFIND
#
#
Set Variable [ $brainstateName; Value:brainstate::description ]
Set Variable [ $$foundStatus ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Go to the find layout for category tags.
Go to Layout [ “IssuesAndObservationsStatusFIND” (status) ]
Enter Find Mode [ ]
Set Field [ status::lock; "status" ]
Perform Find [ ]
Set Field [ status::status; $brainstateName ]
Sort Records [ Specified Sort Order: status::order; ascending
status::text; ascending ]
[ Restore; No dialog ]
#
#Clear all specific actions records.
Select Window [ Name: "Specific Action"; Current file ]
Enter Find Mode [ ]
Set Field [ issue::_keyStatus; "nothing" ]
Perform Find [ ]
#
#Return to tag window.
Select Window [ Name: "Tag"; Current file ]
Scroll Window
[ Home ]
#
#
#FOR NOW DO NOT find current statuses shown
#in the Specific Action window.
// Select Window [ Name: "Specific Action"; Current file ]
// Set Variable [ $$stopRecordLoad; Value:1 ]
// Go to Record/Request/Page
[ First ]
// Set Variable [ $$foundStatus; Value:issue::_keyStatus & ¶ ]
// Loop
// If [ FilterValues ( $$foundStatus ; issue::_keyStatus & ¶ ) ≠ issue::_keyStatus & ¶ ]
// Set Variable [ $$foundStatus; Value:issue::_keyStatus & ¶ & $$foundStatus ]
// End If
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
// Set Variable [ $$stopRecordLoad ]
// Go to Record/Request/Page
[ First ]
// #
// Select Window [ Name: "Tag"; Current file ]
// Refresh Window
#
December 6, ଘ౮27 21:56:51 ActionLog.fp7 - gotoStatusFIND -1-
