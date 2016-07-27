specific action log: loadLogrecordID
#
If [ $$stopRecordLoad = 1 ]
Exit Script [ ]
End If
#
#Set variables used for attaching Specific Action
#record IDs to Day records, and for conditionally
#formatting Day records related to Specific
#Action records.
Set Variable [ $$log; Value:logs::_lockDay ]
Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
Set Variable [ $$day1BugField; Value:logs::swBugField ]
#
#Inform other scripts if user is on or not on
#the Today or Yesterday record. This info will
#speed them up, since they will not have to
#check this out for themselves.
Set Field [ reference::ActivityLogDay; logs::_keyDay ]
Set Field [ reference::ActivityLogDayRecordNumber; Get (RecordNumber) ]
#
#Show conditional formatting of selected
#record related to the newly selected Day record.
Select Window [ Name: "Specific Action"; Current file ]
Go to Field [ ]
Refresh Window
#
#Go to layout displaying all time segements
#for the selected day record.
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$stopRecordLoad; Value:1 ]
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
#
Refresh Window
Set Variable [ $$stopRecordLoad ]
Go to Field [ ]
#
July 26, ଘ౮28 15:21:25 ActionLog.fp7 - loadLogrecordID -1-
