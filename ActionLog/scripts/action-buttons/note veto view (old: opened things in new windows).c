action buttons: note veto view (old: opened things in new windows)
#PURPOSE merge selected record's time data into one total record and then link these records so that time added in the future to any of the
merge records will be automatically added to the one total record.
#
#
#BUG remove focus from any ﬁelds. This step seems to be neccessary as I periodically have been getting a -- this record is being modiﬁed in a
separate window -- message. I'm leaving this step in to see if I stop getting this message.
Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
Go to Field [ ]
Go to Record/Request/Page [ $recordNumber ]
[ No dialog ]
#
#
#
If [ brainstate::sortRetired ≠ "" ]
Show Custom Dialog [ Title: "!"; Message: "This record is currently retired. To make it active again, click on the r to the immediate left of
the record title (if the edit controls are hidden, then ﬁrst click the edit button (top left corner of this window)."; Buttons: “OK” ]
Halt Script
End If
#
#1 if the view button is showing: determine if the record is total record, and it is show the these linked records, unless the user is on the total
record layout in which case halt the script. (From the user's point of view the stopwatch button will say 'view' instead of 'note' if it is a total
record, and this part of the script will be activitated.)
If [ brainstate::_lockBrainstateID = brainstate::groupID or brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
If [ Left ( Get ( LayoutName ) ; 5 ) = "total" or Left ( Get ( LayoutName ) ; 5 ) = "grand" ]
Halt Script
End If
Perform Script [ “showLinkedRecords” ]
Halt Script
End If
#
#1 if the note button is showing ﬁrst determine if there is a day record to update
If [ day1::swSymbols = "" ]
#
#2 if not create a new one for this brainstate record and do it a new window so the user's focus is maintained (just going to the day layout
and back resest the scroll bar unfortunately and I can't ﬁnd away around this, but I want too!)
Set Variable [ $kpnBrainstateID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $userID; Value:reference::farmerID ]
New Window [ Name: "!"; Height: 100; Width: 100 ]
Adjust Window
[ Hide ]
Go to Layout [ “calcDayTable” (day1) ]
New Record/Request
Set Field [ day1::_keyBrainstate; $kpnBrainstateID ]
Set Field [ day1::_keyUser; $userID ]
Set Field [ day1::_keyDay; reference::day1 ]
#
#3 start the timer by inserting the current time in the start ﬁeld
Set Field [ day1::swStart; Get ( CurrentTimeStamp ) ]
Close Window [ Name: "!"; Current ﬁle ]
Go to Layout [ original layout ]
#
#4 sort the records if the current sort is based on time which will make this record with zero current time shoot the top or bottom of the list
depending on how the user is currently shorting time. The point is to keep the focus where the user expects it to be so the sort, which
removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the
focus is returned to the ﬁrst record.
Perform Script [ “DaySelectSortThenSort” ]
Halt Script
End If
#
#5 if the veto button is showing stop the stopwatch and put in the in the time stopped
January 5, 平成26 19:37:02 ActionLog.fp7 - note veto view (old: opened things in new windows) -1-action buttons: note veto view (old: opened things in new windows)
If [ day1::swSymbols = "veto" ]
Set Field [ day1::swPause[day1::swOccurances]; Get ( CurrentTimeStamp ) ]
#
#5 recalculate the time for this record and check and see if is linked to any total records and if so update their time too
Perform Script [ “UpdateTime” ]
Perform Script [ “DaySelectSortThenSort” ]
Halt Script
End If
#
#6 if the note button is showing restart the timer by putting a new start time in next available start ﬁeld for this day record
Set Field [ day1::swStart[day1::swOccurances + 1]; Get ( CurrentTimeStamp ) ]
If [ day1::swOccurances = 29 ]
Set Field [ day1::swStart[29]; Get ( CurrentTimeStamp ) ]
End If
#
#7 recalculate the pause between stop and start times to show user the amount of time that has passed since the last time this brainstate was
active
Perform Script [ “UpdatePauseTotals” ]
Perform Script [ “DaySelectSortThenSort” ]
January 5, 平成26 19:37:02 ActionLog.fp7 - note veto view (old: opened things in new windows) -2-
