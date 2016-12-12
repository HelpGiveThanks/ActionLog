specific action log: TagNameRequired
#
If [ SPAGroupTag::text = "" and $$TagNameRequired = "" ]
Set Field [ SPAGroupTag::text; "tag" & SPAGroupTag::_LockSpecificAction ]
End If
#
If [ status::text = "" and $$TagNameRequired = "" ]
Set Field [ status::text; "status" & status::_LockSpecificAction ]
End If
#
December 10, ଘ౮28 23:16:48 ActionLog.fp7 - TagNameRequired -1-
