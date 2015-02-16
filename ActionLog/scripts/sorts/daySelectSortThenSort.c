Sorts: DaySelectSortThenSort
#PURPOSE sort the user's records according to the sort specified in the sort status field
#
#
#
#1 find the sort the user wants and sort the user's records with it
If [ Left ( Get ( LayoutName ) ; 5 ) ≠ "total" ]
If [ steward::chosenSort = "Brainstates A-Z" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "number" ]
Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Set Field [ steward::chosenSort; "number" ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$recordFIXTOMANYVARIABLES = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Go to Field [ ]
Set Variable [ $$record ]
Set Variable [ $$recordnumber ]
Set Variable [ $$recordFIXTOMANYVARIABLES ]
Set Variable [ $$record ]
Halt Script
#
Else If [ steward::chosenSort = "ms" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
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
Loop
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -1-Sorts: DaySelectSortThenSort
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "abc" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "sub" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "cat" ]
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -2-Sorts: DaySelectSortThenSort
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "allow" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
// Sort Records [ Specified Sort Order: day1::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
// Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::groupType; ascending
day1::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::groupType; ascending
day1::swStart; ascending
brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$recordFIXTOMANYVARIABLES = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Set Variable [ $$recordFIXTOMANYVARIABLES ]
// If [ $$recordnumber ≠ "" ]
// Go to Record/Request/Page
[ First ]
// Scroll Window
[ Home ]
// Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
// Set Variable [ $$recordnumber ]
// End If
Halt Script
#
Else If [ steward::chosenSort = "veto" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::swStop; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -3-Sorts: DaySelectSortThenSort
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "act" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "id" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -4-Sorts: DaySelectSortThenSort
Else If [ steward::chosenSort = "Brainstates Z-A" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "rebmun" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "sm" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::groupID; descending
brainstate::groupOfGroupID; descending
brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -5-Sorts: DaySelectSortThenSort
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "cba" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "bus" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "tac" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -6-Sorts: DaySelectSortThenSort
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "wolla" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStart; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSort = "etov" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStop; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -7-Sorts: DaySelectSortThenSort
#
Else If [ steward::chosenSort = "tca" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
End If
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
End If
If [ steward::chosenSortTotal = "Brainstates A-Z" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -8-Sorts: DaySelectSortThenSort
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "number" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "ms" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
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
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "abc" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -9-Sorts: DaySelectSortThenSort
Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "sub" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "cat" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -10-Sorts: DaySelectSortThenSort
Halt Script
#
Else If [ steward::chosenSortTotal = "allow" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::swStart; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "veto" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::swStop; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "act" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; ascending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -11-Sorts: DaySelectSortThenSort
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "id" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "Brainstates Z-A" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
brainstate::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "rebmun" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -12-Sorts: DaySelectSortThenSort
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "sm" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::groupID; descending
brainstate::groupOfGroupID; descending
brainstate::sortNumber; descending
brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "cba" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending
brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -13-Sorts: DaySelectSortThenSort
#
Else If [ steward::chosenSortTotal = "bus" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending
brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "tac" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::sortCategory; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "wolla" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStart; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -14-Sorts: DaySelectSortThenSort Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "etov" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStop; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
Else If [ steward::chosenSortTotal = "tca" ]
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; descending
brainstate::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
Halt Script
#
End If
Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -15-Sorts: DaySelectSortThenSort
Go to Record/Request/Page
[ Next ]
End Loop
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
January 5, 平成26 20:16:42 ActionLog.fp7 - DaySelectSortThenSort -16-
