editCreateWorkout: editorButtons: segmentSupport: timer
If [ activity::NewSegmentButton = "" ]
Install OnTimer Script [ “updateTime”; Interval: 1 ]
Else If [ activity::NewSegmentButton ≠ "" ]
Set Field [ activity::NewSegmentButton; "" ]
Install OnTimer Script [ ]
End If
January 8, 平成26 12:51:37 Fat and Muscle Efﬁciency Research.fp7 - timer -1-
