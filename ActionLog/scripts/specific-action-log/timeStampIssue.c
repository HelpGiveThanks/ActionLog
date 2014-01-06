speciﬁc action log: timeStampIssue
Set Variable [ $time; Value:daylog::_lockDay ]
Go to Field [ ]
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
Set Variable [ $timeAll; Value:issue::timeSegmentKeyList ]
If [ $time & "¶" ≠ FilterValues ( $timeAll ; $time & "¶" ) ]
Set Field [ issue::timeSegmentKeyList; $time & ¶ & $timeAll ]
Exit Script [ ]
End If
Set Field [ issue::timeSegmentKeyList; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not
removed, then the removal calc without the paragraph mark is used
If ( ValueCount ( $timeAll ) ≠ ValueCount ( Substitute ( $timeAll ; $time & "¶" ; "" ) ) ;
Substitute ( $timeAll ; $time & "¶" ; "" ) ;
Substitute ( $timeAll ; $time ; "" )
) ]
January 6, 平成26 1:18:46 ActionLog.fp7 - timeStampIssue -1-
