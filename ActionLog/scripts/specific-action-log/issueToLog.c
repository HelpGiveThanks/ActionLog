specific action log: IssueToLog
#
#Prevent windows from ﬂashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Exit issue field so conditional formatting can be applied.
Go to Field [ ]
#
#If tag has not yet been selected, then add it.
If [ issue::_LockList & "¶" ≠ FilterValues ( $$logIssues ; issue::_LockList & "¶" ) ]
#
Set Variable [ $newIssue; Value:issue::_LockList ]
Select Window [ Name: "Day"; Current file ]
If [ Get (LastError) = 112 ]
Exit Script [ ]
New Window [ Name: "Day"; Height: Get (ScreenHeight); Width: 608; Top: 0; Left: 441 ]
End If
#
#prepare to add log ID to issueLogs so that the issue
#will have a record of all days logged to deal with it.
Set Variable [ $newlog; Value:logs::_lockDay ]
Set Variable [ $$logIssue; Value:logs::_keyLogIssues ]
#
Set Field [ logs::_keyLogIssues; $newIssue & "¶" & $$logIssues ]
Set Variable [ $$logIssues; Value:logs::_keyLogIssues ]
Go to Field [ ]
Refresh Window
Select Window [ Name: "Specific Action"; Current file ]
#
#Add log ID to issueLogs.
Set Field [ issue::_keyLogs; $newlog & "¶" & $$IssueLogs ]
Set Variable [ $$IssueLogs; Value:issue::_keyLogs ]
#
#For some reason if system does not re-go to this
#same record, other scripts trying to set fields for this
#record in a different window (so same layout
#different window will get an error 301 (record in use
#by another user). So it is neccessary.
#addTimeSegmentToIssue is the other scirpt that
#gets that error message when this step is left out.
Go to Record/Request/Page [ Get (RecordNumber) ]
[ No dialog ]
Refresh Window
Set Variable [ $$stopRecordLoad ]
Exit Script [ ]
End If
#
#
#
#
If [ $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 1 & $$log & "¶" = FilterValues ( $$timeAll ; 1 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 2 & $$log & "¶" = FilterValues ( $$timeAll ; 2 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 3 & $$log & "¶" = FilterValues ( $$timeAll ; 3 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 4 & $$log & "¶" = FilterValues ( $$timeAll ; 4 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 5 & $$log & "¶" = FilterValues ( $$timeAll ; 5 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 6 & $$log & "¶" = FilterValues ( $$timeAll ; 6 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 7 & $$log & "¶" = FilterValues ( $$timeAll ; 7 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 8 & $$log & "¶" = FilterValues ( $$timeAll ; 8 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 9 & $$log & "¶" = FilterValues ( $$timeAll ; 9 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 10 & $$log & "¶" = FilterValues ( $$timeAll ; 10 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 11 & $$log & "¶" = FilterValues ( $$timeAll ; 11 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 12 & $$log & "¶" = FilterValues ( $$timeAll ; 12 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 13 & $$log & "¶" = FilterValues ( $$timeAll ; 13 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 14 & $$log & "¶" = FilterValues ( $$timeAll ; 14 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 15 & $$log & "¶" = FilterValues ( $$timeAll ; 15 & $$log & "¶" ) ]
January 6, 平成26 1:16:39 ActionLog.fp7 - IssueToLog -1-specific action log: IssueToLog
If [ $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 1 & $$log & "¶" = FilterValues ( $$timeAll ; 1 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 2 & $$log & "¶" = FilterValues ( $$timeAll ; 2 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 3 & $$log & "¶" = FilterValues ( $$timeAll ; 3 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 4 & $$log & "¶" = FilterValues ( $$timeAll ; 4 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 5 & $$log & "¶" = FilterValues ( $$timeAll ; 5 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 6 & $$log & "¶" = FilterValues ( $$timeAll ; 6 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 7 & $$log & "¶" = FilterValues ( $$timeAll ; 7 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 8 & $$log & "¶" = FilterValues ( $$timeAll ; 8 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 9 & $$log & "¶" = FilterValues ( $$timeAll ; 9 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 10 & $$log & "¶" = FilterValues ( $$timeAll ; 10 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 11 & $$log & "¶" = FilterValues ( $$timeAll ; 11 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 12 & $$log & "¶" = FilterValues ( $$timeAll ; 12 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 13 & $$log & "¶" = FilterValues ( $$timeAll ; 13 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 14 & $$log & "¶" = FilterValues ( $$timeAll ; 14 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 15 & $$log & "¶" = FilterValues ( $$timeAll ; 15 & $$log & "¶" ) ]
Show Custom Dialog [ Message: "This act has time from the selected day record assigned to it. Do you really want to do unlink it?";
Buttons: “cancel”, “unlink” ]
If [ Get ( LastMessageChoice ) = 1 ]
Exit Script [ ]
End If
End If
#
#
#If issue is assigned to log, then remove it when user
#clicks the link button.
Set Variable [ $removeIssue; Value:issue::_LockList ]
#
#See if any time segements belong to this log record.
If [ issue::timeSegmentKeyList ≠ "" ]
#
New Window [ Name: "temp" ]
#
Select Window [ Name: "Day"; Current file ]
Set Variable [ $day; Value:daylog::_lockDay ]
Select Window [ Name: "temp"; Current file ]
If [ 1 & $day & "¶" = FilterValues ( $$timeAll ; 1 & $day & "¶" ) or
2 & $day & "¶" = FilterValues ( $$timeAll ; 2 & $day & "¶" ) or
3 & $day & "¶" = FilterValues ( $$timeAll ; 3 & $day & "¶" ) or
4 & $day & "¶" = FilterValues ( $$timeAll ; 4 & $day & "¶" ) or
5 & $day & "¶" = FilterValues ( $$timeAll ; 5 & $day & "¶" ) or
6 & $day & "¶" = FilterValues ( $$timeAll ; 6 & $day & "¶" ) or
7 & $day & "¶" = FilterValues ( $$timeAll ; 7 & $day & "¶" ) or
8 & $day & "¶" = FilterValues ( $$timeAll ; 8 & $day & "¶" ) or
9 & $day & "¶" = FilterValues ( $$timeAll ; 9 & $day & "¶" ) or
10 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
11 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
12 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
13 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
14 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
15 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) ]
January 6, 平成26 1:16:39 ActionLog.fp7 - IssueToLog -2-specific action log: IssueToLog
If [ 1 & $day & "¶" = FilterValues ( $$timeAll ; 1 & $day & "¶" ) or
2 & $day & "¶" = FilterValues ( $$timeAll ; 2 & $day & "¶" ) or
3 & $day & "¶" = FilterValues ( $$timeAll ; 3 & $day & "¶" ) or
4 & $day & "¶" = FilterValues ( $$timeAll ; 4 & $day & "¶" ) or
5 & $day & "¶" = FilterValues ( $$timeAll ; 5 & $day & "¶" ) or
6 & $day & "¶" = FilterValues ( $$timeAll ; 6 & $day & "¶" ) or
7 & $day & "¶" = FilterValues ( $$timeAll ; 7 & $day & "¶" ) or
8 & $day & "¶" = FilterValues ( $$timeAll ; 8 & $day & "¶" ) or
9 & $day & "¶" = FilterValues ( $$timeAll ; 9 & $day & "¶" ) or
10 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
11 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
12 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
13 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
14 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or
15 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) ]
Go to Layout [ “issueTime” (issueTime) ]
Enter Find Mode [ ]
Set Field [ issueTime::_keyDay; $day ]
Set Field [ issueTime::_keyIssue; $$issue ]
Perform Find [ ]
Delete All Records
[ No dialog ]
#
#Rebuild issue timeAll list of time segments assigned
#to this issue.
Enter Find Mode [ ]
Set Field [ issueTime::_keyIssue; $$issue ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
Perform Find [ ]
If [ Get (LastError) ≠ 401 ]
#
#Get total time for this issue.
Set Variable [ $totalTime; Value:issueTime::sum ]
#
#Make a list of found day and repetition keys.
Go to Record/Request/Page
[ First ]
Set Variable [ $RepAndDay; Value:issueTime::_keyRepetition & issueTime::_keyDay ]
Loop
Set Variable [ $list; Value:issueTime::_keyRepetition & issueTime::_keyDay & "¶" & $RepAndDay ]
Set Variable [ $RepAndDay; Value:$list ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Replace timeAll list with updated list.
Go to Layout [ “Issues” (issue) ]
Set Field [ issue::issueTotalTime; $TotalTime ]
Set Field [ issue::timeSegmentKeyList; $list ]
Set Variable [ $$timeAll; Value:$list ]
#
Else If [ Get (LastError) = 401 ]
#
#Erase timeAll list.
Go to Layout [ “Issues” (issue) ]
Set Field [ issue::issueTotalTime; "" ]
Set Field [ issue::timeSegmentKeyList; "" ]
Set Variable [ $$timeAll ]
End If
#
#Add up total time for category it is in.
Set Variable [ $categoryKey; Value:issue::_keyCategory ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $categoryKey ]
Perform Find [ ]
Sort Records [ Specified Sort Order: issue::sortTime; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
January 6, 平成26 1:16:39 ActionLog.fp7 - IssueToLog -3-specific action log: IssueToLog
Loop
Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
#
Close Window [ Name: "temp"; Current file ]
#
End If
#
#
#prepare to remove log ID from issueLogs so that the issue
#will have a record of all days logged to deal with it.
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$logIssues; Value:logs::_keyLogIssues ]
Set Variable [ $removelog; Value:logs::_lockDay ]
#
Set Field [ logs::_keyLogIssues; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not removed, then
the removal calc without the paragraph mark is used
If ( ValueCount ( $$logIssues ) ≠ ValueCount ( Substitute ( $$logIssues ; $removeIssue & "¶" ; "" ) ) ;
Substitute ( $$logIssues ; $removeIssue & "¶" ; "" ) ;
Substitute ( $$logIssues ; $removeIssue ; "" )
) ]
Set Variable [ $$logIssues; Value:logs::_keyLogIssues ]
Go to Field [ ]
Refresh Window
Select Window [ Name: "Specific Action"; Current file ]
#
#Remove log ID from issueLogs.
Set Field [ issue::_keyLogs; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not removed, then the
removal calc without the paragraph mark is used
If ( ValueCount ( $$IssueLogs ) ≠ ValueCount ( Substitute ( $$IssueLogs ; $removeLog & "¶" ; "" ) ) ;
Substitute ( $$IssueLogs ; $removeLog & "¶" ; "" ) ;
Substitute ( $$IssueLogs ; $removeLog ; "" )
) ]
Set Variable [ $$IssueLogs; Value:issue::_keyLogs ]
#
#For some reason if system does not re-go to this
#same record, other scripts trying to set fields for this
#record in a different window (so same layout
#different window will get an error 301 (record in use
#by another user). So it is neccessary.
#addTimeSegmentToIssue is the other scirpt that
#gets that error message when this step is left out.
Go to Record/Request/Page [ Get (RecordNumber) ]
[ No dialog ]
Set Variable [ $$stopRecordLoad ]
January 6, 平成26 1:16:39 ActionLog.fp7 - IssueToLog -4-
