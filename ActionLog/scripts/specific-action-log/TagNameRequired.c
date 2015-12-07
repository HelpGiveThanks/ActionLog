specific action log: TagNameRequired
#
If [ category::text = "" and $$TagNameRequired = "" ]
Set Field [ category::text; "tag" & category::_LockList ]
End If
#
If [ status::text = "" and $$TagNameRequired = "" ]
Set Field [ status::text; "status" & status::_LockList ]
End If
#
December 6, ଘ౮27 21:49:25 ActionLog.fp7 - TagNameRequired -1-
