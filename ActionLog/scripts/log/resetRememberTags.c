log: resetRememberTags
#PURPOSE resets remember tags.
#
#
#Stop script if user is process of picking a speciﬁc action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a speciﬁc-action group. After you do this you can reset these tags to the default setting. ";
Buttons: “OK” ]
Exit Script [ ]
End If
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Go to Field [ ]
#
#Make sure user wants to reset dates to default.
Show Custom Dialog [ Message: "Are you sure you want to reset the remember tags names to daily, weekly, monthly, 1/2 yearly, yearly,
complete, discard?"; Buttons: “cancel”, “OK” ]
If [ Get ( LastMessageChoice ) = 1 ]
Exit Script [ ]
End If
#
#Update remember names and review dates.
Set Field [ status::status; "Remember existence" & ¶ & "of a speciﬁc action..." ]
Go to Object [ Object Name: "status" ]
Go to Portal Row
[ Select; First ]
Set Variable [ $reviewNames; Value:"daily" & ¶ &
"weekly" & ¶ &
"monthly" & ¶ &
"1/2 yearly" & ¶ &
"yearly" & ¶ &
"complete" & ¶ &
"discard" ]
// Set Variable [ $reviewDates; Value://daily review
"" & ¶ &
//weekly review
Case (
Day ( Get ( CurrentDate ) ) < 8 ;
Month ( Get ( CurrentDate ) ) - 1 & "/" ;
Month ( Get ( CurrentDate ) ) & "/" ) &
Case (
DayOfWeek ( Get ( CurrentDate ) ) = 1 ; Day ( Get ( CurrentDate ) ) ;
DayOfWeek ( Get ( CurrentDate ) - 1 ) = 1 ; Day ( Get ( CurrentDate ) - 1 ) ;
DayOfWeek ( Get ( CurrentDate ) - 2 ) = 1 ; Day ( Get ( CurrentDate ) - 2 ) ;
DayOfWeek ( Get ( CurrentDate ) - 3 ) = 1 ; Day ( Get ( CurrentDate ) - 3 ) ;
DayOfWeek ( Get ( CurrentDate ) - 4 ) = 1 ; Day ( Get ( CurrentDate ) - 4 ) ;
DayOfWeek ( Get ( CurrentDate ) - 5 ) = 1 ; Day ( Get ( CurrentDate ) - 5 ) ;
DayOfWeek ( Get ( CurrentDate ) - 6 ) = 1 ; Day ( Get ( CurrentDate ) - 6 ) )
& " - " &
//Month ( Get ( CurrentDate ) ) & "/" &
Case (
DayOfWeek ( Get ( CurrentDate ) ) = 7 ; Day ( Get ( CurrentDate ) ) ;
DayOfWeek ( Get ( CurrentDate ) + 1 ) = 7 ; Day ( Get ( CurrentDate ) + 1 ) ;
DayOfWeek ( Get ( CurrentDate ) + 2 ) = 7 ; Day ( Get ( CurrentDate ) + 2 ) ;
DayOfWeek ( Get ( CurrentDate ) + 3 ) = 7 ; Day ( Get ( CurrentDate ) + 3 ) ;
DayOfWeek ( Get ( CurrentDate ) + 4 ) = 7 ; Day ( Get ( CurrentDate ) + 4 ) ;
DayOfWeek ( Get ( CurrentDate ) + 5 ) = 7 ; Day ( Get ( CurrentDate ) + 5 ) ;
DayOfWeek ( Get ( CurrentDate ) + 6 ) = 7 ; Day ( Get ( CurrentDate ) + 6 ) )
& ¶ &
//monthly review
" " &
Case (
Day ( Get ( CurrentDate ) ) > 7 ;
//MonthName ( Month ( Get ( CurrentDate ) ) + 1 & "/" & 1 & "/" & 2012) ;
//MonthName ( Month ( Get ( CurrentDate ) ) & "/" & 1 & "/" & 2012) )
//& ")"
Month ( Get ( CurrentDate ) ) + 1 & "/" & "1" ;
Month ( Get ( CurrentDate ) ) & "/" & "1" ) ] January 5, 平成26 19:34:11 ActionLog.fp7 - resetRememberTags -1-log: resetRememberTags
// Set Variable [ $reviewDates; Value://daily review
"" & ¶ &
//weekly review
Case (
Day ( Get ( CurrentDate ) ) < 8 ;
Month ( Get ( CurrentDate ) ) - 1 & "/" ;
Month ( Get ( CurrentDate ) ) & "/" ) &
Case (
DayOfWeek ( Get ( CurrentDate ) ) = 1 ; Day ( Get ( CurrentDate ) ) ;
DayOfWeek ( Get ( CurrentDate ) - 1 ) = 1 ; Day ( Get ( CurrentDate ) - 1 ) ;
DayOfWeek ( Get ( CurrentDate ) - 2 ) = 1 ; Day ( Get ( CurrentDate ) - 2 ) ;
DayOfWeek ( Get ( CurrentDate ) - 3 ) = 1 ; Day ( Get ( CurrentDate ) - 3 ) ;
DayOfWeek ( Get ( CurrentDate ) - 4 ) = 1 ; Day ( Get ( CurrentDate ) - 4 ) ;
DayOfWeek ( Get ( CurrentDate ) - 5 ) = 1 ; Day ( Get ( CurrentDate ) - 5 ) ;
DayOfWeek ( Get ( CurrentDate ) - 6 ) = 1 ; Day ( Get ( CurrentDate ) - 6 ) )
& " - " &
//Month ( Get ( CurrentDate ) ) & "/" &
Case (
DayOfWeek ( Get ( CurrentDate ) ) = 7 ; Day ( Get ( CurrentDate ) ) ;
DayOfWeek ( Get ( CurrentDate ) + 1 ) = 7 ; Day ( Get ( CurrentDate ) + 1 ) ;
DayOfWeek ( Get ( CurrentDate ) + 2 ) = 7 ; Day ( Get ( CurrentDate ) + 2 ) ;
DayOfWeek ( Get ( CurrentDate ) + 3 ) = 7 ; Day ( Get ( CurrentDate ) + 3 ) ;
DayOfWeek ( Get ( CurrentDate ) + 4 ) = 7 ; Day ( Get ( CurrentDate ) + 4 ) ;
DayOfWeek ( Get ( CurrentDate ) + 5 ) = 7 ; Day ( Get ( CurrentDate ) + 5 ) ;
DayOfWeek ( Get ( CurrentDate ) + 6 ) = 7 ; Day ( Get ( CurrentDate ) + 6 ) )
& ¶ &
//monthly review
" " &
Case (
Day ( Get ( CurrentDate ) ) > 7 ;
//MonthName ( Month ( Get ( CurrentDate ) ) + 1 & "/" & 1 & "/" & 2012) ;
//MonthName ( Month ( Get ( CurrentDate ) ) & "/" & 1 & "/" & 2012) )
//& ")"
Month ( Get ( CurrentDate ) ) + 1 & "/" & "1" ;
Month ( Get ( CurrentDate ) ) & "/" & "1" ) ]
Set Variable [ $reviewDates; Value://daily review
"" & ¶ &
//weekly review
Case (
Day ( Get ( CurrentDate ) ) < 8 ;
Month ( Get ( CurrentDate ) ) - 1 & "/" ;
Month ( Get ( CurrentDate ) ) & "/" ) &
Case (
DayOfWeek ( Get ( CurrentDate ) ) = 1 ; Day ( Get ( CurrentDate ) ) ;
DayOfWeek ( Get ( CurrentDate ) - 1 ) = 1 ; Day ( Get ( CurrentDate ) - 1 ) ;
DayOfWeek ( Get ( CurrentDate ) - 2 ) = 1 ; Day ( Get ( CurrentDate ) - 2 ) ;
DayOfWeek ( Get ( CurrentDate ) - 3 ) = 1 ; Day ( Get ( CurrentDate ) - 3 ) ;
DayOfWeek ( Get ( CurrentDate ) - 4 ) = 1 ; Day ( Get ( CurrentDate ) - 4 ) ;
DayOfWeek ( Get ( CurrentDate ) - 5 ) = 1 ; Day ( Get ( CurrentDate ) - 5 ) ;
DayOfWeek ( Get ( CurrentDate ) - 6 ) = 1 ; Day ( Get ( CurrentDate ) - 6 ) )
//& " - "
&
//Month ( Get ( CurrentDate ) ) & "/" &
//Case (
//DayOfWeek ( Get ( CurrentDate ) ) = 7 ; Day ( Get ( CurrentDate ) ) ;
//DayOfWeek ( Get ( CurrentDate ) + 1 ) = 7 ; Day ( Get ( CurrentDate ) + 1 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 2 ) = 7 ; Day ( Get ( CurrentDate ) + 2 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 3 ) = 7 ; Day ( Get ( CurrentDate ) + 3 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 4 ) = 7 ; Day ( Get ( CurrentDate ) + 4 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 5 ) = 7 ; Day ( Get ( CurrentDate ) + 5 ) ;
//DayOfWeek ( Get ( CurrentDate ) + 6 ) = 7 ; Day ( Get ( CurrentDate ) + 6 ) )
¶ &
//monthly review
" " &
Case (
Day ( Get ( CurrentDate ) ) > 7 ;
//MonthName ( Month ( Get ( CurrentDate ) ) + 1 & "/" & 1 & "/" & 2012) ;
//MonthName ( Month ( Get ( CurrentDate ) ) & "/" & 1 & "/" & 2012) )
//& ")"
Month ( Get ( CurrentDate ) ) + 1 & "/" & "1" ;
Month ( Get ( CurrentDate ) ) & "/" & "1" ) ]
Set Variable [ $number; Value:1 ]
Loop
Set Field [ status::text; GetValue ( $reviewNames ; $number ) ]
Set Field [ status::reviewDate; GetValue ( $reviewDates ; $number ) ]
Set Variable [ $number; Value:$number + 1 ]
Go to Portal Row
[ Select; Next; Exit after last ]
End Loop
#
Go to Field [ ]
#
January 5, 平成26 19:34:11 ActionLog.fp7 - resetRememberTags -2-
