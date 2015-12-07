specific action log: viewAllLogIssues
#
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#
#Clear tag find variables and go to category layout.
Select Window [ Name: "Tag"; Current file ]
Set Variable [ $$found ]
Set Variable [ $$foundStatus ]
Go to Layout [ “IssuesAndObservationsTag” (category) ]
#
#neccessary step when two monitors are used as this
#window can be opened in smaller monitor and then
#move over to larger monitor but not adjust its height
#unless this step is included.
Select Window [ Name: "Specific Action"; Current file ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: 0 ]
If [ Get ( WindowZoomLevel ) > 150 ]
Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
End If
End If
Go to Layout [ “Issues” (issue) ]
#
#remember record user was looking at before
#find all issue records.
Set Variable [ $issueRecord; Value:issue::_LockList ]
#
#Find all issue records.
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
Sort Records [ ]
[ No dialog ]
Set Variable [ $$issueSort; Value:"status" ]
#
#Now go the record the user was looking at.
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
Loop
Exit Loop If [ issue::_LockList = $issueRecord ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#If the user was not looking at any records then
#go to the first record.
If [ issue::_LockList ≠ $issueRecord ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
End If
Set Variable [ $$stopRecordLoad ]
Perform Script [ “loadIssuerecordID” ]
December 6, ଘ౮27 21:21:53 ActionLog.fp7 - viewAllLogIssues -1-
