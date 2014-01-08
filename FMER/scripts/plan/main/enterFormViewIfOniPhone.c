plan: main: enterFormViewIfOniPhone
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop script from loading if other script is running.
If [ $$stopLoadUserWeek = 1 or $$stopiphone = 1 ]
Exit Script [ ]
End If
#
#If workout is assigned the exit field.
If [ planlog::kworkout ≠ "" ]
Set Field [ "" ]
Go to Field [ ]
Exit Script [ ]
End If
#
#If user is on iphone go to iphone layout instead so
#user can see everything.
If [ PatternCount ( Get ( ApplicationVersion ) ; "GO" ) ]
Set Variable [ $object; Value:Get ( ActiveLayoutObjectName ) ]
Go to Layout [ “weekPlanEnterNumbers” (planlog) ]
Go to Object [ Object Name: $object ]
End If
January 8, 平成26 12:22:17 Fat and Muscle Efﬁciency Research.fp7 - enterFormViewIfOniPhone -1-
