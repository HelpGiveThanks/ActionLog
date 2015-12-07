specific action log: openSpecificActionWebLink
#
#
#
#Only allow timer to be stopped if it is running today
#or tomorrow (meaning today after midnight).
#
#
If [ issue::weblink = "" ]
Go to Field [ issue::weblink ]
Else
Go to Field [ issue::weblink ]
Open URL [ issue::weblink ]
[ No dialog ]
End If
#
#
December 7, ଘ౮27 14:33:39 ActionLog.fp7 - openSpecificActionWebLink -1-
