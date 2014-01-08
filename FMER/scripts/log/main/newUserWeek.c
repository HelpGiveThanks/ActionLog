log: main: newUserWeek
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Stop the user week record script from loading to
#speed up script and to stop variables from being wiped
#out.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Find all weeks assigned to user.
Go to Layout [ “weekTag” (week) ]
Enter Find Mode [ ]
Set Field [ week::kuser; planlog::kuserGlobal ]
Perform Find [ ]
#
#Sort by date and go to the last record.
Sort Records [ Specified Sort Order: week::date; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ Last ]
#
#Create a new week record and assign it a date 7 days
#from the last record's date.
New Record/Request
Set Field [ week::kuser; planlog::kuserGlobal ]
Set Field [ week::kintensity; 1 ]
Set Field [ week::date; Case ( Get ( RecordNumber ) - 1 = 0 ; Get ( CurrentDate ) ;
Case ( GetNthRecord( week::date ; Get ( RecordNumber ) - 1 ) = "" ; Get ( CurrentDate ) ;
GetNthRecord( week::date ; Get ( RecordNumber ) - 1 ) + 7 )) ]
#
#Stop user from creating future weeks.
If [ week::date > Get (CurrentDate) ]
Delete Record/Request
[ No dialog ]
Go to Layout [ original layout ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Show Custom Dialog [ Message: "You cannot create logs for future workout weeks."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Set the defautts to the newly created date.
Set Field [ planlog::kweekGlobal; week::_Lweek ]
Set Field [ planlog::dateGlobal; week::date ]
#
#
#
#Now create a new workout for this week.
#
#
January 8, 平成26 12:10:12 Fat and Muscle Efﬁciency Research.fp7 - newUserWeek -1-log: main: newUserWeek
#
#Create a new workout record.
Go to Layout [ original layout ]
New Record/Request
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::kweek; planlog::kweekGlobal ]
Set Field [ planlog::plannedOrPerformed; "logged" ]
// Set Field [ planlog::kexercise; exerciseMHR::kexerciseGlobal ]
#
#Insert date within the week of the workout week.
If [ week::date ≤ Get (CurrentDate) + 6 and week::date ≥ Get (CurrentDate) - 6 ]
Set Field [ planlog::date; Get (CurrentDate) ]
Else If [ week::date + 6 < Get (CurrentDate) ]
Set Field [ planlog::date; week::date ]
End If
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
#
// Enter Find Mode [ ]
// Set Field [ planlog::kuser; $user ]
// Perform Find [ ]
Sort Records [ Specified Sort Order: week::date; descending
planlog::date; descending ]
[ Restore; No dialog ]
Perform Script [ “loadUserLogWeek” ]
#
January 8, 平成26 12:10:12 Fat and Muscle Efﬁciency Research.fp7 - newUserWeek -2-
