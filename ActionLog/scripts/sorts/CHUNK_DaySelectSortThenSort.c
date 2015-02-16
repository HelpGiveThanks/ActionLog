Sorts: CHUNK_DaySelectSortThenSort
#PURPOSE sort the user's records according to the sort specified in the sort status field (had to create this script for scripts that need this sort
but should not halt after doing the sort but go on to other sorts)
#
#
#
#1 find the sort the user wants and sort the user's records with it
If [ steward::chosenSort = "Brainstates A-Z" ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "number" ]
Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "ms" ]
Sort Records [ Specified Sort Order: brainstate::sortMergeToBlanksToBottom; descending
brainstate::groupID; ascending
brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "abc" ]
Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "sub" ]
Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
January 5, 平成26 20:18:31 ActionLog.fp7 - CHUNK_DaySelectSortThenSort -1-Sorts: CHUNK_DaySelectSortThenSort
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "cat" ]
Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "allow" ]
Sort Records [ Specified Sort Order: day1::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "veto" ]
Sort Records [ Specified Sort Order: day1::swStop; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "act" ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "id" ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "Brainstates Z-A" ]
January 5, 平成26 20:18:31 ActionLog.fp7 - CHUNK_DaySelectSortThenSort -2-Sorts: CHUNK_DaySelectSortThenSort
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "rebnum" ]
Sort Records [ Specified Sort Order: brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "sm" ]
Sort Records [ Specified Sort Order: brainstate::groupID; descending
brainstate::groupOfGroupID; descending
brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "cba" ]
Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "bus" ]
Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "tac" ]
January 5, 平成26 20:18:31 ActionLog.fp7 - CHUNK_DaySelectSortThenSort -3-Sorts: CHUNK_DaySelectSortThenSort
Sort Records [ Specified Sort Order: brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "wolla" ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStart; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "etov" ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStop; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
Else If [ steward::chosenSort = "tca" ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
Exit Script [ ]
#
End If
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Set Variable [ $$record ]
January 5, 平成26 20:18:31 ActionLog.fp7 - CHUNK_DaySelectSortThenSort -4-
