specific action log: findGroupPart2
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#
If [ Get (LayoutTableName) = "category" ]
#
#Make key to fit this group's lock.
Set Variable [ $$group; Value:category::_LockList ]
Go to Field [ ]
#
#Remove found specific actions with this key if
#user already found them and now wants to
#hide them.
If [ FilterValues ( $$found ; $$group ) = $$group & ¶ ]
#
#Remove the find request the user just clicked on,
#and then determine the number of find requests remaining.
Set Variable [ $$found; Value:Substitute ( $$found ; $$group & ¶ ; "" ) ]
Set Variable [ $valueNumber; Value:ValueCount ( $$found ) ]
#
#Go the specific action window and begin the process
#of finding requested records minus the ones
#the user no longer wants to see.
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Find last request first and if their zero requests
#then find no records.
Enter Find Mode [ ]
If [ $valueNumber = 0 ]
Set Field [ issue::_keyCategory; "none" ]
Perform Find [ ]
Set Variable [ $$stopRecordLoad ]
Select Window [ Name: "Tag"; Current file ]
Refresh Window
Exit Script [ ]
Else
Set Field [ issue::_keyCategory; GetValue ( $$found ; $valueNumber ) ]
Perform Find [ ]
End If
#
#Find aditional records until all requests have
#been satisfied.
Enter Find Mode [ ]
Loop
Set Variable [ $valueNumber; Value:$valueNumber - 1 ]
Exit Loop If [ $valueNumber = 0 ]
Set Field [ issue::_keyCategory; GetValue ( $$found ; $valueNumber ) ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Extend Found Set [ ]
End Loop
#
#
#STOP USING this loop which omitted records.
#This method is really slow when their are 500 +
#records. Replaced with the above method for
#finding records user wants to view.
// Go to Record/Request/Page
[ First ]
// Loop
// If [ issue::_keyCategory = $$group ]
// Omit Record
// Else
// Go to Record/Request/Page
[ Next; Exit after last ]
// End If
// End Loop
#
#
Set Variable [ $$stopRecordLoad ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Else
#
#Find all specific actions with this key.
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $$group ]
Extend Found Set [ ]
If [ Get (LastError) ≠ 401 ]
Set Variable [ $$found; Value:$$group & ¶ & $$found ]
Else
Show Custom Dialog [ Message: "There are no specific actions tagged with this category."; Buttons: “OK” ]
Set Variable [ $$stopRecordLoad ]
End If
Set Variable [ $$stopRecordLoad ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
End If
Perform Script [ “loadIssuerecordID” ]
#
#If user selected the same category that was already
#selected then stop this script.
Select Window [ Name: "Tag"; Current file ]
Refresh Window
#
#
#
Else
#
#
#
#Make key to fit this group's lock.
Set Variable [ $$findStatus; Value:status::_LockList ]
Go to Field [ ]
#
#Remove found specific actions with this key if
#user already found them and now wants to
#hide them.
If [ FilterValues ( $$foundStatus ; $$findStatus ) = $$findStatus & ¶ ]
#
#Remove the find request the user just clicked on,
#and then determine the number of find requests remaining.
Set Variable [ $$foundStatus; Value:Substitute ( $$foundStatus ; $$findStatus & ¶ ; "" ) ]
Set Variable [ $valueNumber; Value:ValueCount ( $$foundStatus ) ]
#
#Go the specific action window and begin the process
#of finding requested records minus the ones
#the user no longer wants to see.
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Find last request first and if their zero requests
#then find no records.
Enter Find Mode [ ]
If [ $valueNumber = 0 ]
Set Field [ issue::_keyStatus; "none" ]
Perform Find [ ]
Set Variable [ $$stopRecordLoad ]
Select Window [ Name: "Tag"; Current file ]
Refresh Window
Exit Script [ ]
Else
Set Field [ issue::_keyStatus; GetValue ( $$foundStatus ; $valueNumber ) ]
Perform Find [ ]
End If
#
#Find aditional records until all requests have
#been satisfied.
Loop
Set Variable [ $valueNumber; Value:$valueNumber - 1 ]
Exit Loop If [ $valueNumber = 0 ]
Set Field [ issue::_keyStatus; GetValue ( $$foundStatus ; $valueNumber ) ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Extend Found Set [ ]
End Loop
#
#
#STOP USING this loop which omitted records.
#This method is really slow when their are 500 +
#records. Replaced with the above method for
#finding records user wants to view.
// Go to Record/Request/Page
[ First ]
// Loop
// If [ issue::_keyStatus = $$findStatus ]
// Omit Record
// Else
// Go to Record/Request/Page
[ Next; Exit after last ]
// End If
// End Loop
// Set Variable [ $$foundStatus; Value:Substitute ( $$foundStatus ; $$findStatus & ¶ ; "" ) ]
#
#
Set Variable [ $$stopRecordLoad ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Else
#
#Find all specific actions with this key.
Select Window [ Name: "Specific Action"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Enter Find Mode [ ]
Set Field [ issue::_keyStatus; $$findStatus ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Extend Found Set [ ]
If [ Get (LastError) ≠ 401 ]
Set Variable [ $$foundStatus; Value:$$findStatus & ¶ & $$foundStatus ]
Else
Show Custom Dialog [ Message: "There are no specific actions tagged with this status."; Buttons: “OK” ]
Set Variable [ $$stopRecordLoad ]
End If
Set Variable [ $$stopRecordLoad ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
End If
Perform Script [ “loadIssuerecordID” ]
#
#If user selected the same category that was already
#selected then stop this script.
Select Window [ Name: "Tag"; Current file ]
Refresh Window
#
End If
December 6, ଘ౮27 21:38:13 ActionLog.fp7 - findGroupPart2 -1-
