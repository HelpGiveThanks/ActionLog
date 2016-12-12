sorts: DaySelectSortThenSort
#PURPOSE sort the user's records according to the sort specified in the sort status field
#
#
#
#1 find the sort the user wants and sort the user's records with it
If [ Left ( Get ( LayoutName ) ; 5 ) ≠ "total" ]
If [ user::chosenSort = "Brainstates A-Z" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "number" ]
Sort Records [ Specified Sort Order: timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Set Field [ user::chosenSort; "number" ]
Set Variable [ $$stopRecordLoad; Value:1 ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$recordFIXTOMANYVARIABLES = timer::_lockTimer ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Set Field [ reference::CurrentRecord; Get ( RecordID ) ]
Set Variable [ $$timerIDnumber; Value:timer::_lockTimer ]
Go to Field [ ]
Set Variable [ $$record ]
Set Variable [ $$recordnumber ]
Set Variable [ $$stopRecordLoad ]
Set Variable [ $$recordFIXTOMANYVARIABLES ]
#
Else If [ user::chosenSort = "ms" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortMergeToBlanksToBottom; descending
timer::groupID; ascending
timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "abc" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "sub" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "cat" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "allow" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
// Sort Records [ Specified Sort Order: day1::swStart; ascending
timer::description; ascending ]
[ Restore; No dialog ]
// Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::groupType; ascending
day1::swStart; ascending
timer::description; ascending ]
[ Restore; No dialog ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::groupType; ascending
day1::swStart; ascending
timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$recordFIXTOMANYVARIABLES = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "veto" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::swStop; ascending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "act" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; ascending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "id" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::_lockTimer; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "Brainstates Z-A" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "rebmun" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortNumber; descending
timer::sortAlpha; descending
timer::sortSubNumber; descending
timer::sortCategory; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "sm" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::groupID; descending
timer::groupOfGroupID; descending
timer::sortNumber; descending
timer::sortAlpha; descending
timer::sortSubNumber; descending
timer::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "cba" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortAlpha; descending
timer::sortSubNumber; descending
timer::sortCategory; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "bus" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortSubNumber; descending
timer::sortCategory; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "tac" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortCategory; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "wolla" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStart; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "etov" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStop; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSort = "tca" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
End If
#
#Allows specific action script to continue.
If [ $$specificActionTimer = 1 ]
Exit Script [ Result: "note veto view" ]
Exit Script [ ]
#
#The user entered a time segment in
#the Timer window, dragged its time to
#another time segement, and has not yet
#exited the entered time segment. They then
#went to the Specific Action window and
#clicked the 'start' button, which set this
#variable and started this script.
Else If [ $$timerWindowCheck = 1 ]
Exit Script [ ]
#
Else
Halt Script
End If
End If
#
#
#
#
#
#
#
#
#Not all the next steps below are even in use
#any more? Testing required before removing.
#
#
#
#
#
#
#
#
If [ Left ( Get ( LayoutName ) ; 5 ) ≠ "total" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::_lockTimer; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
End If
#
#Had to include this if to move the exit or halt
#if that applies to all of these total sort ifs to
#be placed just once at the end of this this if.
If [ 1 = 1 ]
If [ user::chosenSortTotal = "Brainstates A-Z" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "number" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "ms" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortMergeToBlanksToBottom; descending
timer::groupID; ascending
timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "abc" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "sub" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "cat" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "allow" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::swStart; ascending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "veto" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::swStop; ascending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "act" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; ascending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "id" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::_lockTimer; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "Brainstates Z-A" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "rebmun" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortNumber; descending
timer::sortAlpha; descending
timer::sortSubNumber; descending
timer::sortCategory; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "sm" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::groupID; descending
timer::groupOfGroupID; descending
timer::sortNumber; descending
timer::sortAlpha; descending
timer::sortSubNumber; descending
timer::description; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "cba" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortAlpha; descending
timer::sortSubNumber; descending
timer::sortCategory; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "bus" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortSubNumber; descending
timer::sortCategory; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "tac" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::sortCategory; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "wolla" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStart; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "etov" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swStop; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
Else If [ user::chosenSortTotal = "tca" ]
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
day1::swTotalActivity; descending
timer::description; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
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
#
End If
#
#Here is the 1 = 1 if that applies to all of the
#above total sort ifs.
#
#Allows specific action script to continue.
If [ $$specificActionTimer = 1 ]
Exit Script [ Result: "note veto view" ]
Exit Script [ ]
#
#The user entered a time segment in
#the Timer window, dragged its time to
#another time segement, and has not yet
#exited the entered time segment. They then
#went to the Specific Action window and
#clicked the 'start' button, which set this
#variable and started this script.
Else If [ $$timerWindowCheck = 1 ]
Exit Script [ ]
#
Else
Halt Script
End If
End If
#
Set Variable [ $$record; Value:timer::_lockTimer ]
Sort Records [ Specified Sort Order: timer::_lockTimer; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $$record = timer::_lockTimer ]
Go to Record/Request/Page
[ Next ]
End Loop
#
Set Variable [ $$record ]
If [ $$recordnumber ≠ "" ]
Scroll Window
[ Home ]
Go to Record/Request/Page [ $$recordnumber ]
[ No dialog ]
Set Variable [ $$recordnumber ]
End If
#
December 10, ଘ౮28 20:53:50 ActionLog.fp7 - DaySelectSortThenSort -1-
