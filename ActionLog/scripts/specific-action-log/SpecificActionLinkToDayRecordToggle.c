specific action log: SpecificActionLinkToDayRecordToggle
#
#Prevent windows from flashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Exit issue field so conditional formatting can be applied.
Go to Field [ ]
#
#
#BEGIN Link SPA record to selected Day record.
#
#
#Check if the selected SPA ID is in the day
#record's SPA keychain.
If [ specificAction::_LockSpecificAction & "¶" ≠ FilterValues ( $$logIssues ; specificAction::_LockSpecificAction & "¶" ) ]
#
#Get SPA record's ID.
Set Variable [ $newIssue; Value:specificAction::_LockSpecificAction ]
#
#Add SPA record's ID to the day (log) record's
#keychain of SPA keys (IDs).
Select Window [ Name: "Day"; Current file ]
Set Variable [ $newlog; Value:logs::_lockDay ]
Set Variable [ $$logIssue; Value:logs::_keyLogSPAs ]
Set Field [ logs::_keyLogSPAs; $newIssue & "¶" & $$logIssues ]
Set Variable [ $$logIssues; Value:logs::_keyLogSPAs ]
Go to Field [ ]
Refresh Window
#
#Add day ID (key) to the SPA's day ID
#keychain.
Select Window [ Name: "Specific Action"; Current file ]
Set Field [ specificAction::_keyLogs; $newlog & "¶" & $$IssueLogs ]
Set Variable [ $$IssueLogs; Value:specificAction::_keyLogs ]
#
#Show record has been modified.
Set Field [ specificAction::dateModified; Get ( CurrentTimeStamp ) ]
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
#END Link SPA record to selected Day record.
#
#
#
#
#BEGIN UnLink SPA record from selected Day record.
#
#
#Stop user from unlinking an SPA record from
#a Day record that has time segements
#assigned to the SPA record. Tell user they
#cannot do this, yet, and how to proceed.
If [ $$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 1 & $$log & "¶" = FilterValues ( $$timeAll ; 1 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 2 & $$log & "¶" = FilterValues ( $$timeAll ; 2 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 3 & $$log & "¶" = FilterValues ( $$timeAll ; 3 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 4 & $$log & "¶" = FilterValues ( $$timeAll ; 4 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 5 & $$log & "¶" = FilterValues ( $$timeAll ; 5 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 6 & $$log & "¶" = FilterValues ( $$timeAll ; 6 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 7 & $$log & "¶" = FilterValues ( $$timeAll ; 7 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 8 & $$log & "¶" = FilterValues ( $$timeAll ; 8 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 9 & $$log & "¶" = FilterValues ( $$timeAll ; 9 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 10 & $$log & "¶" = FilterValues ( $$timeAll ; 10 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 11 & $$log & "¶" = FilterValues ( $$timeAll ; 11 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 12 & $$log & "¶" = FilterValues ( $$timeAll ; 12 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 13 & $$log & "¶" = FilterValues ( $$timeAll ; 13 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 14 & $$log & "¶" = FilterValues ( $$timeAll ; 14 & $$log & "¶" )
 or
$$log & "¶" = FilterValues ( specificAction::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID)
 and 15 & $$log & "¶" = FilterValues ( $$timeAll ; 15 & $$log & "¶" ) ]
Show Custom Dialog [ Message: "The day you're trying to unlink from is contributing time to this specific action's total time.
Subtract this time, then unlink: 1) Click each green (dark highlighted) time segment in the Day window, then 2) 'subtract' in
each popup window."; Buttons: “OK” ]
Set Variable [ $$stopRecordLoad ]
Exit Script [ ]
End If
#
#
#Remove SPA ID from Day record so
#the day record will only have SPA keys
#(IDs) for SPAs still linked to it.
Set Variable [ $removeIssue; Value:specificAction::_LockSpecificAction ]
Select Window [ Name: "Day"; Current file ]
Set Variable [ $$logIssues; Value:logs::_keyLogSPAs ]
Set Variable [ $removelog; Value:logs::_lockDay ]
#
#Remove SPA ID.
Set Field [ logs::_keyLogSPAs; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not
removed, then the removal calc without the paragraph mark is used
If ( ValueCount ( $$logIssues ) ≠ ValueCount ( Substitute ( $$logIssues ; $removeIssue & "¶" ; "" ) ) ;
Substitute ( $$logIssues ; $removeIssue & "¶" ; "" ) ;
Substitute ( $$logIssues ; $removeIssue ; "" )
) ]
Set Variable [ $$logIssues; Value:logs::_keyLogSPAs ]
Go to Field [ ]
Refresh Window
#
#Remove day ID (key) from SPA record.
Select Window [ Name: "Specific Action"; Current file ]
Set Field [ specificAction::_keyLogs; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not
removed, then the removal calc without the paragraph mark is used
If ( ValueCount ( $$IssueLogs ) ≠ ValueCount ( Substitute ( $$IssueLogs ; $removeLog & "¶" ; "" ) ) ;
Substitute ( $$IssueLogs ; $removeLog & "¶" ; "" ) ;
Substitute ( $$IssueLogs ; $removeLog ; "" )
) ]
Set Variable [ $$IssueLogs; Value:specificAction::_keyLogs ]
#
#Show record has been modified.
Set Field [ specificAction::dateModified; Get ( CurrentTimeStamp ) ]
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
#
#
#END UnLink SPA record from selected Day record.
#
December 10, ଘ౮28 23:07:58 ActionLog.fp7 - SpecificActionLinkToDayRecordToggle -1-
