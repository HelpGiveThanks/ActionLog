speciﬁc action log: goToIssueFromAssignedTimeSegment
Set Variable [ $timeSegment; Value:Get ( ActiveRepetitionNumber ) & logs::_lockDay ]
Go to Field [ ]
Select Window [ Name: "Speciﬁc Action"; Current ﬁle ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
January 6, 平成26 11:11:12 ActionLog.fp7 - goToIssueFromAssignedTimeSegment -1-
