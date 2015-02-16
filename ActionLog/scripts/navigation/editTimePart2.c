navigation: EditTimePart2
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
#
#this gotoField removes focus from field if user in a
#field when activates this script. It then causes the script
#update script to cancel this script, but without changing
#the users sort. Then when activitated again having now
#exited all fields, the scirpt preforms fine. The alternative
#would be to cancel this script if the user was in a field
#when it was activited. This essentially does that (
#cancels the script because the focus will trigger a conﬂicting script).
Go to Field [ ]
Set Field [ steward::chosenSort; steward::chosenLayoutMain ]
Go to Layout [ “01Main” (brainstate) ]
#1 set the layout status field
Set Field [ steward::chosenLayout; Get ( LayoutName ) ]
Set Field [ steward::chosenSort; "rebmun" ]
Perform Script [ “sortNumbers” ]
#7 go to active brainstate or first brainstate.
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ day1::swBugField = "veto" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ day1::swBugField ≠ "veto" ]
Go to Record/Request/Page
[ First ]
End If
January 5, 平成26 19:10:19 ActionLog.fp7 - EditTimePart2 -1-
