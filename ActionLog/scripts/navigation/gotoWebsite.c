navigation: gotoWebsite
#
#Close other solutions window if open after selecting website.
If [ $$otherApps = 1 ]
Set Variable [ $$otherApps ]
Close Window [ Name: "Other Solutions"; Current file ]
Open URL [ "http://helpgivethanks.org/apps/thebuggenie/wiki/Overview" ]
[ No dialog ]
End If
January 30, 平成26 22:24:33 ActionLog.fp7 - gotoWebsite -1-
