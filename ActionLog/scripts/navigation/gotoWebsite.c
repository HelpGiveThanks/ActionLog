navigation: gotoWebsite
#
#Close all solutions window after selecting website.
If [ $$otherApps = 1 ]
Set Variable [ $$otherApps ]
Close Window [ Name: "All Solutions"; Current file ]
Open URL [ "http://helpgivethanks.org/apps/thebuggenie/wiki/Overview" ]
[ No dialog ]
End If
July 13, ଘ౮28 13:10:27 ActionLog.fp7 - gotoWebsite -1-
