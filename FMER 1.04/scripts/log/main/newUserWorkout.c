log: main: newUserWorkout
Allow User Abort [ Off ]
Set Error Capture [ On ]
If [ Get (FoundCount) = 0 ]
Perform Script [ “newUserWeek” ]
Exit Script [ ]
End If
#
#Stop the user week record script from loading to
#speed up script and to stop variables from being wiped
#out.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#
#Create a new workout record.
New Record/Request
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::kweek; planlog::kweekGlobal ]
Set Field [ planlog::plannedOrPerformed; "logged" ]
// Set Field [ planlog::kexercise; exerciseMHR::kexerciseGlobal ]
#
#Insert date wtihin the week of the workout week.
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
Sort Records [ Specified Sort Order: week::date; descending
planlog::date; descending ]
[ Restore; No dialog ]
Perform Script [ “loadUserLogWeek” ]
// Enter Find Mode [ ]
// Set Field [ planlog::kuser; $user ]
// Perform Find [ ]
#
January 8, 平成26 12:10:42 Fat and Muscle Efﬁciency Research.fp7 - newUserWorkout -1-
