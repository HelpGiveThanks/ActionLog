plan: main: 30seconds
#
#If workout is assigned then exit field.
If [ planlog::kworkout ≠ "" ]
Set Field [ "" ]
Go to Field [ ]
Exit Script [ ]
End If
If [ Get (ActiveFieldContents) = "" ]
Set Field [ 30 ]
Go to Field [ ]
Exit Script [ ]
End If
Set Field [ "" ]
Go to Field [ ]
January 8, 平成26 12:23:12 Fat and Muscle Efﬁciency Research.fp7 - 30seconds -1-
