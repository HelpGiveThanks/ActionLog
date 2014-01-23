doWorkout: main: doWorkoutPart2
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Fill screen and increase size for easy viewing.
If [ Get (ScreenWidth) > Get (WindowWidth) ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Width: Get (ScreenWidth); Top: 0; Left: 0 ]
Set Zoom Level
[ 300% ]
End If
#
If [ activitySequence1::message = "" or $$startTime ]
Set Field [ activitySequence1::message; "paused at " &
Case ( Hour ( Get (CurrentTime) ) > 12 ; Hour ( Get (CurrentTime) ) - 12 ; Hour ( Get (CurrentTime) ) )
 & ":" &
Case ( Minute ( Get (CurrentTime) ) < 10 ; "0" & Minute ( Get (CurrentTime) ) ;
Minute ( Get (CurrentTime) ) ) & ":" &
Case ( Seconds ( Get (CurrentTime) ) < 10 ; "0" & Seconds ( Get (CurrentTime) ) ;
Seconds ( Get (CurrentTime) ) ) ]
Set Field [ activitySequence1::timeToNextSegment; "" ]
Set Variable [ $$startTime ]
Halt Script
Else If [ activitySequence1::message = "click screen to log workout" ]
Perform Script [ “logWorkout” ]
Exit Script [ ]
End If
#
#Start workout at 00 seconds.
Set Field [ activitySequence1::timeToNextSegment; "" ]
Set Field [ activitySequence1::message; "starts in " & 60 - Seconds ( Get (CurrentTime) ) & TextSize ( "seconds" ; 15 ) & " at " &
Case ( Hour ( Get (CurrentTime) ) > 12 ; Hour ( Get (CurrentTime) ) - 12 ; Hour ( Get (CurrentTime) ) )
 & ":" &
Case ( Minute ( Get (CurrentTime) ) + 1 < 10 ; "0" & Minute ( Get (CurrentTime) ) + 1 ;
Minute ( Get (CurrentTime) ) ) + 1 & ":00" ]
Set Variable [ $$startTime; Value:activitySequence1::message ]
Pause/Resume Script [ Duration (seconds): 60 - Seconds ( Get (CurrentTime) ) ]
Set Variable [ $$startTime ]
Set Field [ activitySequence1::message; "" ]
#
#Show on select layout.
Set Variable [ $time; Value:Get ( CurrentTime ) ]
Set Variable [ $number; Value:1 ]
Loop
#
#Move the green line to the next segment.
Set Field [ activity::segmentNumberGlobal; activitySequence2::segement ]
#
#Set the time and pause until it is reached.
Set Field [ activitySequence1::timeToNextSegment; //( time to next segment + last time script paused ) - current time = actual
seconds before next segment
( ((Hour(activitySequence3::time) * 3600) + (Minute(activitySequence3::time) * 60) + Seconds(activitySequence3::time)) -
((Hour(activitySequence2::time) * 3600) + (Minute(activitySequence2::time) * 60) + Seconds(activitySequence2::time))
 +
$time ) ]
January 8, 平成26 12:36:29 Fat and Muscle Efﬁciency Research.fp7 - doWorkoutPart2 -1-doWorkout: main: doWorkoutPart2 Set Field [ activitySequence1::timeToNextSegment; //( time to next segment + last time script paused ) - current time = actual
seconds before next segment
( ((Hour(activitySequence3::time) * 3600) + (Minute(activitySequence3::time) * 60) + Seconds(activitySequence3::time)) -
((Hour(activitySequence2::time) * 3600) + (Minute(activitySequence2::time) * 60) + Seconds(activitySequence2::time))
 +
$time ) ]
Pause/Resume Script [ Duration (seconds): //( time to next segment + last time script paused ) - current time = actual seconds
before next segment
( ( (Hour(activitySequence3::time) * 3600) + (Minute(activitySequence3::time) * 60) + Seconds(activitySequence3::time)) -
((Hour(activitySequence2::time) * 3600) + (Minute(activitySequence2::time) * 60) + Seconds(activitySequence2::time))
 +
$time )
 -
Get (CurrentTime) ]
Set Variable [ $time; Value:Get ( CurrentTime ) ]
#
#Move segments up one each.
Set Field [ activity::ksequence1; activity::ksequence2 ]
Set Field [ activity::ksequence2; activity::ksequence3 ]
Set Field [ activity::ksequence3; activity::ksequence3 + 1 ]
#
#End workout after last sequence has been done.
Set Variable [ $number; Value:$number + 1 ]
Exit Loop If [ $number = activity::countSequenceSegments ]
End Loop
#
#Move the green line to the next segment.
Set Field [ activity::segmentNumberGlobal; activitySequence2::segement ]
#
#Set the time and pause until it is reached.
Set Field [ activitySequence1::timeToNextSegment; //( time to next segment + last time script paused ) - current time = actual seconds
before next segment
( ((Hour(activity::TotalWorkoutTime) * 3600) + (Minute(activity::TotalWorkoutTime) * 60) + Seconds(activity::TotalWorkoutTime)) -
((Hour(activitySequence2::time) * 3600) + (Minute(activitySequence2::time) * 60) + Seconds(activitySequence2::time))
 +
$time ) ]
Pause/Resume Script [ Duration (seconds): //( time to next segment + last time script paused ) - current time = actual seconds before
next segment
( ((Hour(activity::TotalWorkoutTime) * 3600) + (Minute(activity::TotalWorkoutTime) * 60) + Seconds(activity::TotalWorkoutTime)) -
((Hour(activitySequence2::time) * 3600) + (Minute(activitySequence2::time) * 60) + Seconds(activitySequence2::time))
 +
$time )
 -
Get (CurrentTime) ]
#
#Move green line to the end.
Set Field [ activity::segmentNumberGlobal; activitySequence2::segement + 1 ]
#
#Tell user they can log the workout now.
Set Field [ activitySequence1::message; "click screen to log workout" ]
#
January 8, 平成26 12:36:29 Fat and Muscle Efﬁciency Research.fp7 - doWorkoutPart2 -2-
