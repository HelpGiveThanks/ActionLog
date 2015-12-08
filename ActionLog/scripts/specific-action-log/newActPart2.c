specific action log: newActPart2
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Make key to fit this group's lock.
Set Variable [ $$group; Value:category::_LockList ]
Set Variable [ $$pick ]
Go to Field [ ]
// Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
// Go to Layout [ “IssuesAndObservationsTag” (category) ]
Refresh Window
#
#Give key to current specific action.
Select Window [ Name: "Specific Action"; Current file ]
Set Field [ issue::_keyCategory; $$group ]
Set Field [ issue::oldCategorykey; $$group ]
#
#These two keys are essential for the subtotal to work.
Set Variable [ $$status; Value:issue::_keyStatus ]
Set Field [ issue::sortTime; issueCategory::text ]
#
// #If user selected the same category that was already
// #selected then stop this script.
// If [ issue::_keyCategory = issue::oldCategorykey and $$stopSubtotal = "" ]
// Go to Field [ ]
// Exit Script [ ]
// End If
#
Sort Records [ ]
[ No dialog ]
Refresh Window
Perform Script [ “LoadIssuerecordID” ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
Go to Record/Request/Page
[ Next ]
Go to Record/Request/Page
[ Next ]
Go to Record/Request/Page
[ Next ]
Go to Record/Request/Page
[ Next ]
Go to Record/Request/Page
[ Next ]
Go to Record/Request/Page
[ Next ]
Go to Record/Request/Page
[ Next ]
Go to Record/Request/Page
[ Next ]
Go to Record/Request/Page
[ Next ]
Set Variable [ $$stopRecordLoad ]
Go to Record/Request/Page [ $recordNumber ]
[ No dialog ]
Go to Field [ issue::text ]
January 6, 平成26 11:14:57 ActionLog.fp7 - newActPart2 -1-
