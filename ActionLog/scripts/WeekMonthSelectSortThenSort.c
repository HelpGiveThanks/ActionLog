Sorts: WeekMonthSelectSortThenSort
#PURPOSE sort the user's records according to the sort speciﬁed in the sort status ﬁeld
#
#
#
#1 ﬁnd the sort the user wants and sort the user's records with it
If [ steward::chosenSort = "Brainstates A-Z" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortBlanksToBottom; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "number" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "ms" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortMergeToBlanksToBottom; descending
brainstate::groupID; ascending
brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "abc" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "sub" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "cat" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "allow" ]
January 6, 平成26 0:28:25 ActionLog.fp7 - WeekMonthSelectSortThenSort -1-Sorts: WeekMonthSelectSortThenSort
Sort Records [ Speciﬁed Sort Order: day1::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "veto" ]
Sort Records [ Speciﬁed Sort Order: day1::swStop; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "act" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortBlanksToBottom; descending
brainstate::monthsum; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "id" ]
Sort Records [ Speciﬁed Sort Order: brainstate::_lockBrainstateID; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "Brainstates Z-A" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortBlanksToBottom; descending
brainstate::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "rebmun" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "sm" ]
Sort Records [ Speciﬁed Sort Order: brainstate::groupID; descending
brainstate::groupOfGroupID; descending
brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "cba" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ] January 6, 平成26 0:28:25 ActionLog.fp7 - WeekMonthSelectSortThenSort -2-Sorts: WeekMonthSelectSortThenSort Sort Records [ Speciﬁed Sort Order: brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "bus" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "tac" ]
Sort Records [ Speciﬁed Sort Order: brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "wolla" ]
Sort Records [ Speciﬁed Sort Order: day1::_keyDay; ascending
day1::swStart; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "etov" ]
Sort Records [ Speciﬁed Sort Order: day1::_keyDay; ascending
day1::swStop; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
Else If [ steward::chosenSort = "tca" ]
Sort Records [ Speciﬁed Sort Order: brainstate::monthsum; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
#
End If
Sort Records [ Speciﬁed Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
January 6, 平成26 0:28:25 ActionLog.fp7 - WeekMonthSelectSortThenSort -3-
