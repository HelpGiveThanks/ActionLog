navigation: editTimePart1
#PURPOSE goto the edit timer layout.
#
Set Variable [ $$record; Value:timer::_lockTimer ]
Set Field [ user::chosenLayoutMain; user::chosenSort ]
#
#Toggle the retired status field.
If [ user::retiredStatus = "" ]
Perform Script [ “retireButton” ]
End If
#
#Go to correct layout.
If [ $$EditTimerNamesReturnLayout ≠ "" ]
Go to Layout [ $$EditTimerNamesReturnLayout ]
Set Variable [ $$EditTimerNamesReturnLayout ]
Else
#
If [ Get (SystemPlatform) ≠ 3 ]
Go to Layout [ “01EditTime” (timer) ]
Else
Go to Layout [ “EditTimeiPhone” (timer) ]
End If
#
End If
#
#Perform correct sort.
If [ Filter ( Get (LayoutName) ; "M" ) = "M" ]
Sort Records [ Specified Sort Order: timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Set Field [ user::chosenSort; "number" ]
Else
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::groupType; ascending
day1::swStart; ascending
timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Set Field [ user::chosenSort; "allow" ]
End If
#
#Go to active brainstate or first brainstate.
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
#
December 10, ଘ౮28 20:22:37 ActionLog.fp7 - editTimePart1 -1-
