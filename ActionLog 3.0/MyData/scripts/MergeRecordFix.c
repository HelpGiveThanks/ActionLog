MergeRecordFix
Go to Record/Request/Page
[ First ]
Set Field [ brainstate::groupDisplayID; Right ( brainstate::groupID ; 4 ) ]
If [ brainstate::groupDisplayID = "" ]
Set Field [ brainstate::hide; "t" ]
End If
Loop
Go to Record/Request/Page
[ Next; Exit after last ]
Set Field [ brainstate::groupDisplayID; Right ( brainstate::groupID ; 4 ) ]
If [ brainstate::groupDisplayID = "" ]
Set Field [ brainstate::hide; "t" ]
End If
End Loop
January 6, 平成26 13:13:46 MyData.fp7 - MergeRecordFix -1-
