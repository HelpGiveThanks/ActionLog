action buttons: UpdatePauseTotals
#PURPOSE update the time paused fields and the total and grand total fields after a user leaves a time field or clicks the veto button. They may
or may not have done anything, but in case they did this update is performed.
#
#
#1 if there is only one time, skip the following steps to recalculate the time paused between more than one time.
If [ day1::swActivityLength[2] ≠ "" ]
#
#2 calculate all pause times between activity times. This step is stopped when the next time to calculate a pause between is blank or when
this loop has reached the last repitition (this test is neccessary because there are only 30 repetitions, so there will not be a blank 31 to
detect, thus reaching 31 has to trigger a stop).
Set Variable [ $repetition; Value:2 ]
Loop
Set Field [ day1::swPauseLength[$repetition]; day1::swStart[$repetition] - day1::swPause[$repetition-1] ]
Set Variable [ $repetition; Value:$repetition+1 ]
Exit Loop If [ day1::swStart[$repetition] = "" ]
Exit Loop If [ $repetition = 31 ]
End Loop
End If
January 5, 平成26 19:41:17 ActionLog.fp7 - UpdatePauseTotals -1-
