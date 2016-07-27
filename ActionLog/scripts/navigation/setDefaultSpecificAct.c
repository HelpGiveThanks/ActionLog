action buttons: setDefaultSpecificAct
#Set selected timer as default specific act to
#load when the database is started.
If [ brainstate::_lockBrainstateID = steward::DefaultSpecificAction ]
Set Field [ steward::DefaultSpecificAction; "" ]
Else
Set Field [ steward::DefaultSpecificAction; brainstate::_lockBrainstateID ]
Set Field [ brainstate::HighlightSpecificActionButton; "r" ]
Go to Field [ ]
End If
#
July 26, ଘ౮28 16:00:38 ActionLog.fp7 - setDefaultSpecificAct -1-
