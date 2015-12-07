specific action log: gotoStatus
#
#
Set Variable [ $brainstateName; Value:brainstate::description ]
#
#Show all status tags.
Go to Layout [ “IssuesAndObservationsStatus” (status) ]
Enter Find Mode [ ]
Set Field [ status::lock; "status" ]
Perform Find [ ]
Set Field [ status::status; $brainstateName ]
Sort Records [ Specified Sort Order: status::order; ascending
status::text; ascending ]
[ Restore; No dialog ]
#
December 6, ଘ౮27 21:54:30 ActionLog.fp7 - gotoStatus -1-
