log: dates: changeWeekDatePart2
Allow User Abort [ Off ]
Set Error Capture [ On ]
Set Variable [ $$stopLoadUserWeek; Value:1 ]
Set Variable [ $newDate; Value:week::date ]
Set Field [ week::date; $$olddate ]
#
Go to Layout [ “weekTag” (week) ]
#
Enter Find Mode [ ]
Set Field [ week::kuser; planlog::kuserGlobal ]
Perform Find [ ]
#
Sort Records [ Specified Sort Order: week::date; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
#
Loop
Exit Loop If [ $$oldDate = week::date ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
If [ $newDate < GetNthRecord ( week::date ; Get ( RecordNumber ) - 1 ) + 7
 or
$newDate > GetNthRecord ( week::date ; Get ( RecordNumber ) + 1 ) - 7
and
Get (RecordNumber) ≠ Get (FoundCount) ]
Set Variable [ $$olddate; Value:week::date ]
Go to Layout [ original layout ]
Set Variable [ $$stopLoadUserWeek ]
Show Custom Dialog [ Message: "Workout weeks cannot overlap. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Stop user from creating future weeks.
If [ $newDate > Get ( CurrentDate ) ]
Set Variable [ $$olddate; Value:week::date ]
Go to Layout [ original layout ]
Set Variable [ $$stopLoadUserWeek ]
Show Custom Dialog [ Message: "You cannot create logs for future workout weeks. (Check your computer time setting if the
date you are seetting is for today or any day prior to today.)"; Buttons: “OK” ]
Exit Script [ ]
End If
#
Set Field [ week::date; $newDate ]
Set Variable [ $$stopLoadUserWeek ]
Go to Layout [ original layout ]
#
January 8, 平成26 12:15:37 Fat and Muscle Efﬁciency Research.fp7 - changeWeekDatePart2 -1-
