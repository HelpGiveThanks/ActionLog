specific action log: newActPart1
#
Set Variable [ $$stopRecordLoad; Value:1 ]
#
New Record/Request
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
Set Field [ issue::lock; "issue" ]
Set Field [ issue::_keyStatus; 7152011154818554 ]
Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
#
#Set variable to remove background color and allow
#message explaining assigning group to show.
Set Variable [ $newAct; Value:issue::_LockList ]
Refresh Window
#
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
#
#Set variable to remove background color and allow
#message explaining assigning group to show.
Set Variable [ $newAct; Value:issue::_LockList ]
Refresh Window
#
Select Window [ Name: "Tag"; Current file ]
Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
Set Variable [ $$pick; Value:1 ]
Refresh Window
Pause/Resume Script [ Indefinitely ]
#
January 6, 平成26 11:14:23 ActionLog.fp7 - newActPart1 -1-
