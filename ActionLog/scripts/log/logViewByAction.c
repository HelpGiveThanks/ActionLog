log: logViewByAction
Go to Layout [ “logs2rows” (logs) ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
Go to Layout [ “logByActioniPhone” (logs) ]
End If
Sort Records [ Speciﬁed Sort Order: brainstate::description; ascending
logs::_keyBrainstate; descending
logs::swStart; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
January 5, 平成26 19:32:30 ActionLog.fp7 - logViewByAction -1-
