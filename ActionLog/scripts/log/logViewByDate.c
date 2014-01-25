log: logViewByDate
Go to Layout [ “logByDate” (logs) ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
Go to Layout [ “logByDateiPhone” (logs) ]
End If
Sort Records [ Speciﬁed Sort Order: logs::_keyDay; descending
logs::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
January 5, 平成26 19:32:00 ActionLog.fp7 - logViewByDate -1-
