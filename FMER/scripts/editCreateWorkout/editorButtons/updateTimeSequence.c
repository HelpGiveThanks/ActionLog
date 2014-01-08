editCreateWorkout: editorButtons: updateTimeSequence
Allow User Abort [ Off ]
Set Error Capture [ On ]
Go to Field [ ]
#
#If there are no records, stop the script.
If [ Get (FoundCount) = 0 ]
Exit Script [ ]
End If
#
#Stop icon load script from running during this script.
Set Variable [ $$stopIconInsert; Value:1 ]
#
#If the workout does not begin at the bottom of
#zone 1, tell user and exit script.
Go to Object [ Object Name: "icon01" ]
If [ Left ( Get (ActiveFieldContents) ; 1 ) ≠ "b" ]
Set Field [ activity::segmentNumberGlobal; 1 ]
Set Field [ activity::go; "" ]
Show Custom Dialog [ Message: "Start your workout from the bottom of zone 1."; Buttons: “OK” ]
Set Variable [ $$stopIconInsert ]
Exit Script [ ]
End If
Go to Field [ ]
Go to Object [ Object Name: "ugly" ]
#
#If the workout has not assigned a focus exit sript.
If [ activity::Type = "" ]
If [ Get (LayoutName) = "EditSmallGraph" ]
Go to Layout [ “EditSmallGraph” (activity) ]
Go to Field [ activity::Type ]
[ Select/perform ]
End If
Show Custom Dialog [ Message: "All workouts are required to have a focus. Select one or more by checking the boxes at the
top of the screen."; Buttons: “OK” ]
Set Variable [ $$stopIconInsert ]
Exit Script [ ]
End If
#
#Clear incomplete repeat fields.
If [ activity::rowBbegin = "" or activity::rowAend = "" ]
Set Field [ activity::rowAend; "" ]
Set Field [ activity::rowBbegin; "" ]
Set Field [ activity::rowBend; "" ]
Set Field [ activity::rowCbegin; "" ]
Else If [ activity::rowCbegin = "" or activity::rowBend = "" ]
Set Field [ activity::rowBend; "" ]
Set Field [ activity::rowCbegin; "" ]
End If
Go to Field [ ]
#
New Window [ Height: 1; Width: 1; Top: 1; Left: 1 ]
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -1-editCreateWorkout: editorButtons: updateTimeSequence
// New Window [ Top: 1; Left: 1 ]
#Clear time.
Set Variable [ $workout; Value:activity::_Lactivity ]
Go to Layout [ “WorkoutSegment” (segment01) ]
Enter Find Mode [ ]
Set Field [ segment01::kworkout; $workout ]
Perform Find [ ]
Go to Record/Request/Page
[ First ]
Loop
Set Field [ segment01::stopWatchTimeRowA; "" ]
Set Field [ segment01::stopWatchTimeRowB; "" ]
Set Field [ segment01::stopWatchTimeRowC; "" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Check if all totalTime field are filled in.
Go to Record/Request/Page
[ First ]
Loop
Set Variable [ $totalTime; Value:segment01::SegmentNumber ]
Exit Loop If [ segment01::TotalTime ≤ 0 ]
Exit Loop If [ //Do not evaluate segment 1.
$totalTime ≠ "01" and
//Two zone icon check calculations.
Case (
//If user has selected two zones for icon check to insure it is a 2 zone icon. two zone icons are easy to understand when
stretched, and require equal time spent in both zones.
Middle ( segment01::iconInfo ; 14 ; 1 ) ≠ 2 and Length ( segment01::ZonePick ) ≠ 1 or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier - .5 ;
segment01::iconCheckLastZoneMultiplier - .5 = segment01::ZoneMultiplier - .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier - 1 = segment01::ZoneMultiplier + .5 ;
segment01::iconCheckLastZoneMultiplier - 1.5 = segment01::ZoneMultiplier + .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier + 1 = segment01::ZoneMultiplier - .5 ;
segment01::iconCheckLastZoneMultiplier + 1.5 = segment01::ZoneMultiplier - .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier + .5 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ) or
//One zone icon check calculations.
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier - .5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier - 1 = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier - 1.5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "m" and
Left ( segment01::iconInfo ; 1 ) = "m" and
segment01::iconCheckLastZonePick = segment01::ZonePick or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier + 1 = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier + 1.5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier + .5 = segment01::ZoneMultiplier )
 ; "" ; 1 ) = 1 ]
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -2-editCreateWorkout: editorButtons: updateTimeSequence
Exit Loop If [ //Do not evaluate segment 1.
$totalTime ≠ "01" and
//Two zone icon check calculations.
Case (
//If user has selected two zones for icon check to insure it is a 2 zone icon. two zone icons are easy to understand when
stretched, and require equal time spent in both zones.
Middle ( segment01::iconInfo ; 14 ; 1 ) ≠ 2 and Length ( segment01::ZonePick ) ≠ 1 or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier - .5 ;
segment01::iconCheckLastZoneMultiplier - .5 = segment01::ZoneMultiplier - .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier - 1 = segment01::ZoneMultiplier + .5 ;
segment01::iconCheckLastZoneMultiplier - 1.5 = segment01::ZoneMultiplier + .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier + 1 = segment01::ZoneMultiplier - .5 ;
segment01::iconCheckLastZoneMultiplier + 1.5 = segment01::ZoneMultiplier - .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier + .5 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ) or
//One zone icon check calculations.
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier - .5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier - 1 = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier - 1.5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "m" and
Left ( segment01::iconInfo ; 1 ) = "m" and
segment01::iconCheckLastZonePick = segment01::ZonePick or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier + 1 = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier + 1.5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier + .5 = segment01::ZoneMultiplier )
 ; "" ; 1 ) = 1 ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ segment01::TotalTime ≤ 0 ]
Close Window [ Current Window ]
Go to Object [ Object Name: "time" & $totalTime ]
Set Field [ activity::segmentNumberGlobal; $totalTime ]
Set Field [ activity::go; "" ]
Go to Field [ ]
Show Custom Dialog [ Message: "Segment " & $totalTime & " is incomplete."; Buttons: “OK” ]
Set Variable [ $$stopIconInsert ]
Exit Script [ ]
End If
#
#If the workout has icons that do not flow into
#each other, tell user and exit script.
If [ //Do not evaluate segment 1.
$totalTime ≠ "01" and
//Two zone icon check calculations.
Case (
//If user has selected two zones for icon check to insure it is a 2 zone icon. two zone icons are easy to understand when
stretched, and require equal time spent in both zones.
Middle ( segment01::iconInfo ; 14 ; 1 ) ≠ 2 and Length ( segment01::ZonePick ) ≠ 1 or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier - .5 ;
segment01::iconCheckLastZoneMultiplier - .5 = segment01::ZoneMultiplier - .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier - 1 = segment01::ZoneMultiplier + .5 ;
segment01::iconCheckLastZoneMultiplier - 1.5 = segment01::ZoneMultiplier + .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier + 1 = segment01::ZoneMultiplier - .5 ;
segment01::iconCheckLastZoneMultiplier + 1.5 = segment01::ZoneMultiplier - .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier + .5 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ) or
//One zone icon check calculations.
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier - .5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier - 1 = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier - 1.5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "m" and
Left ( segment01::iconInfo ; 1 ) = "m" and
segment01::iconCheckLastZonePick = segment01::ZonePick or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier + 1 = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier + 1.5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier + .5 = segment01::ZoneMultiplier )
 ; "" ; 1 ) = 1 ]
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -3-editCreateWorkout: editorButtons: updateTimeSequence
If [ //Do not evaluate segment 1.
$totalTime ≠ "01" and
//Two zone icon check calculations.
Case (
//If user has selected two zones for icon check to insure it is a 2 zone icon. two zone icons are easy to understand when
stretched, and require equal time spent in both zones.
Middle ( segment01::iconInfo ; 14 ; 1 ) ≠ 2 and Length ( segment01::ZonePick ) ≠ 1 or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier - .5 ;
segment01::iconCheckLastZoneMultiplier - .5 = segment01::ZoneMultiplier - .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier - 1 = segment01::ZoneMultiplier + .5 ;
segment01::iconCheckLastZoneMultiplier - 1.5 = segment01::ZoneMultiplier + .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier + 1 = segment01::ZoneMultiplier - .5 ;
segment01::iconCheckLastZoneMultiplier + 1.5 = segment01::ZoneMultiplier - .5 ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier + .5 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ) or
//One zone icon check calculations.
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier - .5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "b" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier - 1 = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier - 1.5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "m" and
Left ( segment01::iconInfo ; 1 ) = "m" and
segment01::iconCheckLastZonePick = segment01::ZonePick or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "b" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier + 1 = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier + 1.5 = segment01::ZoneMultiplier ) or
Middle ( segment01::iconCheckLastIcon ; 9 ; 1 ) = "t" and
Left ( segment01::iconInfo ; 1 ) = "t" and
Case (
Length ( segment01::iconCheckLastZonePick ) = 1 ;
segment01::iconCheckLastZoneMultiplier = segment01::ZoneMultiplier ;
segment01::iconCheckLastZoneMultiplier + .5 = segment01::ZoneMultiplier )
 ; "" ; 1 ) = 1 ]
Close Window [ Current Window ]
Go to Object [ Object Name: "icon" & $totalTime ]
Set Field [ activity::segmentNumberGlobal; $totalTime ]
Set Field [ activity::go; "" ]
Go to Field [ ]
Show Custom Dialog [ Message: "Segment " & $totalTime & "'s icon does not work with previous icon."; Buttons: “OK” ]
Set Variable [ $$stopIconInsert ]
Exit Script [ ]
End If
#
#If the workout does not end at the bottom of zone 1,
#tell user and exit script.
If [ segment01::SegmentNumber = 1 ]
Go to Record/Request/Page
[ First ]
End If
Set Variable [ $totalTime; Value:segment01::SegmentNumber ]
If [ segment01::ZoneMultiplier = 1 and
Middle ( segment01::iconInfo ; 9 ; 1 ) = "b" ] January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -4-editCreateWorkout: editorButtons: updateTimeSequence If [ segment01::ZoneMultiplier = 1 and
Middle ( segment01::iconInfo ; 9 ; 1 ) = "b" ]
Set Field [ activity::segmentNumberGlobal; 1 ]
Else
Close Window [ Current Window ]
Go to Object [ Object Name: "icon" & $totalTime ]
Set Field [ activity::segmentNumberGlobal; $totalTime ]
Set Field [ activity::go; "" ]
Go to Field [ ]
Show Custom Dialog [ Message: "The last icon's line must end at the bottom of zone 1."; Buttons: “OK” ]
Set Variable [ $$stopIconInsert ]
Exit Script [ ]
End If
#
#Turn icon load script back on. It will not be triggered
#for the rest of this script.
Set Variable [ $$stopIconInsert ]
#
#Clear time.
Go to Layout [ “activitySequence1” (activitySequence1) ]
Enter Find Mode [ ]
Set Field [ activitySequence1::kactivity; $workout ]
Perform Find [ ]
Delete All Records
[ No dialog ]
#
#Go to calculate time layout to begin to fill in time
#for this workout.
Go to Layout [ “CalculateTime” (activity) ]
#
#All workouts begin at time zero.
Set Field [ segment01::stopWatchTimeRowA; "00:00:00" ]
Set Variable [ $sequenceTime; Value:"00:00:00"& ¶ ]
Set Field [ activity::m25; "01" ]
Go to Object [ Object Name: "ksegment" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ ]
#
#Start with adding time to the second segement in row a.
Set Variable [ $segment; Value:2 ]
Set Variable [ $segmentSequence; Value:1 & ¶ ]
#
#All workouts begin at time zero.
Loop
#
#If user specified workout to repeat to the previous
#segment, then exit the loop and begin the next loop.
Exit Loop If [ GetValue ( activity::rowAend ; 1 ) = $segment - 1 ]
Exit Loop If [ GetValue ( activity::rowAend ; 1 ) = "0" & $segment - 1 ]
#
#Get the current segments total time or exit loop if
#if there is no time. This can happen if the step below
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -5-editCreateWorkout: editorButtons: updateTimeSequence
#the if arguement has already created the final total
#record, which means the user has already run the script
#once and has made a change to one of the segments
#so it is being run again.
Go to Object [ Object Name: "time" & $segment - 1 ]
Go to Object [ Object Name: "time0" & $segment - 1 ]
Set Variable [ $time; Value:Get ( ActiveFieldContents ) + $time ]
Set Variable [ $segmentSequence; Value:$segmentSequence & $segment & ¶ ]
#
#Add values to the time and segment variables which
#will be used below to create a new set of sequence
#records. These are used to walk a user through the
#exercise one segment at a time.
Set Variable [ $sequenceTime; Value:$time & ¶ & $sequenceTime ]
#
Set Field [ activity::m25; $segment ]
Go to Object [ Object Name: "ksegment" ]
If [ Get (ActiveFieldContents) = "" ]
Set Field [ activity::m25; "0" & $segment ]
Go to Object [ Object Name: "ksegment" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ & $sequenceSegment ]
Else If [ Get (ActiveFieldContents) ≠ "" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ & $sequenceSegment ]
End If
#
#Put in the time and set the segment variable to go
#to the next segment.
Go to Object [ Object Name: "a" & $segment ]
Go to Object [ Object Name: "a0" & $segment ]
Set Field [ $time ]
Set Variable [ $segment; Value:$segment + 1 ]
Go to Object [ Object Name: "time" & $segment ]
Go to Object [ Object Name: "time0" & $segment ]
Exit Loop If [ Get (ActiveFieldContents) = "" ]
End Loop
#
#If there are no repeats then finish up the script.
If [ activity::rowBbegin = "" or activity::rowAend = "" ]
Go to Field [ ]
#
#Note total number of segements including repeats
#in workout.
Set Variable [ $valueCount; Value:ValueCount ( $sequenceTime ) ]
Set Field [ activity::countSequenceSegments; $valueCount ]
#
#Create a new sequence for activity.
Go to Layout [ “activitySequence1” (activitySequence1) ]
Perform Find [ Specified Find Requests: Find Records; Criteria: activitySequence1::_LactivitySequence:
“99999999999999999999” ]
[ Restore ]
Loop
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -6-editCreateWorkout: editorButtons: updateTimeSequence
New Record/Request
Set Field [ activitySequence1::kactivity; $workout ]
Set Field [ activitySequence1::time; GetValue ( $sequenceTime ; $valueCount ) ]
Set Field [ activitySequence1::ksegment; GetValue ( $sequenceSegment ; $valueCount ) ]
Set Variable [ $valueCount; Value:$valueCount - 1 ]
Exit Loop If [ $valueCount = 0 ]
End Loop
#
#Insert sequence order and segments performed for
#each sequence.
Set Variable [ $valueCount; Value:ValueCount ( $sequenceTime ) ]
Loop
Set Field [ activitySequence1::sequence; $valueCount ]
Set Field [ activitySequence1::segement; GetValue ( $segmentSequence ; $valueCount ) ]
Set Variable [ $valueCount; Value:$valueCount - 1 ]
Exit Loop If [ $valueCount = 0 ]
Go to Record/Request/Page
[ Previous; Exit after last ]
End Loop
#
Close Window [ Current Window ]
Perform Script [ “CHUNKAddUpPointsAndTime” ]
Exit Script [ ]
End If
#
#
#
#Row B
#
#
#
#First segment
Go to Object [ Object Name: "time" & GetValue ( activity::rowAend ; 1 ) ]
Set Variable [ $time; Value:Get ( ActiveFieldContents ) ]
Go to Object [ Object Name: "a" & GetValue ( activity::rowAend ; 1 ) ]
Set Variable [ $time; Value:Get ( ActiveFieldContents ) + $time ]
#
#Add values to the time and segment variables which
#will be used below to create a new set of sequence
#records. These are used to walk a user through the
#exercise one segment at a time.
Set Variable [ $sequenceTime; Value:$time & ¶ & $sequenceTime ]
Set Field [ activity::m25; GetValue ( activity::rowBbegin ; 1 ) ]
Go to Object [ Object Name: "ksegment" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ & $sequenceSegment ]
#
Go to Object [ Object Name: "b" & GetValue ( activity::rowBbegin ; 1 ) ]
Set Field [ $time ]
Set Variable [ $segment; Value:GetValue ( activity::rowBbegin ; 1 ) + 1 ]
Set Variable [ $segmentSequence; Value:$segmentSequence & GetValue ( activity::rowBbegin ; 1 ) & ¶ ]
#
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -7-editCreateWorkout: editorButtons: updateTimeSequence
#Second segement in on row B.
Loop
#
#If user specified workout to repeat to the previous
#segment, then exit the loop and begin the next loop.
Exit Loop If [ GetValue ( activity::rowBend ; 1 ) = $segment - 1 ]
Exit Loop If [ GetValue ( activity::rowBend ; 1 ) = "0" & $segment - 1 ]
#
#Get the current segments total time or exit loop if
#if there is no time. This can happen if the step below
#the if arguement has already created the final total
#record, which means the user has already run the script
#once and has made a change to one of the segments
#so it is being run again.
Go to Object [ Object Name: "time" & $segment - 1 ]
Go to Object [ Object Name: "time0" & $segment - 1 ]
Set Variable [ $time; Value:Get ( ActiveFieldContents ) + $time ]
Set Variable [ $segmentSequence; Value:$segmentSequence & $segment & ¶ ]
#
#Add values to the time and segment variables which
#will be used below to create a new set of sequence
#records. These are used to walk a user through the
#exercise one segment at a time.
Set Variable [ $sequenceTime; Value:$time & ¶ & $sequenceTime ]
#
Set Field [ activity::m25; $segment ]
Go to Object [ Object Name: "ksegment" ]
If [ Get (ActiveFieldContents) = "" ]
Set Field [ activity::m25; "0" & $segment ]
Go to Object [ Object Name: "ksegment" ]
Else If [ Get (ActiveFieldContents) ≠ "" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ & $sequenceSegment ]
End If
#
Go to Object [ Object Name: "ksegment" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ & $sequenceSegment ]
#
#Put in the time and set the segment variable to go
#to the next segment.
Go to Object [ Object Name: "b" & $segment ]
Go to Object [ Object Name: "b0" & $segment ]
Set Field [ $time ]
Set Variable [ $segment; Value:$segment + 1 ]
Go to Object [ Object Name: "time" & $segment ]
Go to Object [ Object Name: "time0" & $segment ]
Exit Loop If [ Get (ActiveFieldContents) = "" ]
End Loop
#
#If there are no repeats then finish up the script.
If [ activity::rowCbegin = "" or activity::rowBend = "" ]
Go to Field [ ]
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -8-editCreateWorkout: editorButtons: updateTimeSequence
#
#Note total number of segements including repeats
#in workout.
Set Variable [ $valueCount; Value:ValueCount ( $sequenceTime ) ]
Set Field [ activity::countSequenceSegments; $valueCount ]
#
#Create a new sequence for activity.
Go to Layout [ “activitySequence1” (activitySequence1) ]
Perform Find [ Specified Find Requests: Find Records; Criteria: activitySequence1::_LactivitySequence:
“99999999999999999999” ]
[ Restore ]
Loop
New Record/Request
Set Field [ activitySequence1::kactivity; $workout ]
Set Field [ activitySequence1::time; GetValue ( $sequenceTime ; $valueCount ) ]
Set Field [ activitySequence1::ksegment; GetValue ( $sequenceSegment ; $valueCount ) ]
Set Variable [ $valueCount; Value:$valueCount - 1 ]
Exit Loop If [ $valueCount = 0 ]
End Loop
#
#Insert sequence order and segments performed for
#each sequence.
Set Variable [ $valueCount; Value:ValueCount ( $sequenceTime ) ]
Loop
Set Field [ activitySequence1::sequence; $valueCount ]
Set Field [ activitySequence1::segement; GetValue ( $segmentSequence ; $valueCount ) ]
Set Variable [ $valueCount; Value:$valueCount - 1 ]
Exit Loop If [ $valueCount = 0 ]
Go to Record/Request/Page
[ Previous; Exit after last ]
End Loop
#
Close Window [ Current Window ]
Perform Script [ “CHUNKAddUpPointsAndTime” ]
Exit Script [ ]
End If
#
#
#
#Row C
#
#
#
#First segment
Go to Object [ Object Name: "time" & GetValue ( activity::rowBend; 1 ) ]
Set Variable [ $time; Value:Get ( ActiveFieldContents ) ]
Go to Object [ Object Name: "b" & GetValue ( activity::rowBend ; 1 ) ]
Set Variable [ $time; Value:Get ( ActiveFieldContents ) + $time ]
#
#Add values to the time and segment variables which
#will be used below to create a new set of sequence
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -9-editCreateWorkout: editorButtons: updateTimeSequence
#records. These are used to walk a user through the
#exercise one segment at a time.
Set Variable [ $sequenceTime; Value:$time & ¶ & $sequenceTime ]
Set Field [ activity::m25; GetValue ( activity::rowCbegin ; 1 ) ]
Go to Object [ Object Name: "ksegment" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ & $sequenceSegment ]
#
Go to Object [ Object Name: "c" & GetValue ( activity::rowCbegin ; 1 ) ]
Set Field [ $time ]
Set Variable [ $segment; Value:GetValue ( activity::rowCbegin ; 1 ) + 1 ]
Set Variable [ $segmentSequence; Value:$segmentSequence & GetValue ( activity::rowCbegin ; 1 ) & ¶ ]
#
#All workouts begin at time zero.
Loop
#
#Get the current segments total time or exit loop if
#if there is no time. This can happen if the step below
#the if arguement has already created the final total
#record, which means the user has already run the script
#once and has made a change to one of the segments
#so it is being run again.
Go to Object [ Object Name: "time" & $segment - 1 ]
Go to Object [ Object Name: "time0" & $segment - 1 ]
Set Variable [ $time; Value:Get ( ActiveFieldContents ) + $time ]
Set Variable [ $segmentSequence; Value:$segmentSequence & $segment & ¶ ]
#
#Add values to the time and segment variables which
#will be used below to create a new set of sequence
#records. These are used to walk a user through the
#exercise one segment at a time.
Set Variable [ $sequenceTime; Value:$time & ¶ & $sequenceTime ]
#
Set Field [ activity::m25; $segment ]
Go to Object [ Object Name: "ksegment" ]
If [ Get (ActiveFieldContents) = "" ]
Set Field [ activity::m25; "0" & $segment ]
Go to Object [ Object Name: "ksegment" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ & $sequenceSegment ]
Else If [ Get (ActiveFieldContents) ≠ "" ]
Set Variable [ $sequenceSegment; Value:Get (ActiveFieldContents) & ¶ & $sequenceSegment ]
End If
#
#
#Put in the time and set the segment variable to go
#to the next segment.
Go to Object [ Object Name: "c" & $segment ]
Go to Object [ Object Name: "c0" & $segment ]
Set Field [ $time ]
Set Variable [ $segment; Value:$segment + 1 ]
Go to Object [ Object Name: "time" & $segment ]
Go to Object [ Object Name: "time0" & $segment ]
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -10-editCreateWorkout: editorButtons: updateTimeSequence
Exit Loop If [ Get (ActiveFieldContents) = "" ]
End Loop
Go to Field [ ]
#
#Note total number of segements including repeats
#in workout.
Set Variable [ $valueCount; Value:ValueCount ( $sequenceTime ) ]
Set Field [ activity::countSequenceSegments; $valueCount ]
#
#Create a new sequence for activity.
Go to Layout [ “activitySequence1” (activitySequence1) ]
Perform Find [ Specified Find Requests: Find Records; Criteria: activitySequence1::_LactivitySequence: “99999999999999999999” ]
[ Restore ]
Loop
New Record/Request
Set Field [ activitySequence1::kactivity; $workout ]
Set Field [ activitySequence1::time; GetValue ( $sequenceTime ; $valueCount ) ]
Set Field [ activitySequence1::ksegment; GetValue ( $sequenceSegment ; $valueCount ) ]
Set Variable [ $valueCount; Value:$valueCount - 1 ]
Exit Loop If [ $valueCount = 0 ]
End Loop
#
#Insert sequence order and segments performed for
#each sequence.
Set Variable [ $valueCount; Value:ValueCount ( $sequenceTime ) ]
Loop
Set Field [ activitySequence1::sequence; $valueCount ]
Set Field [ activitySequence1::segement; GetValue ( $segmentSequence ; $valueCount ) ]
Set Variable [ $valueCount; Value:$valueCount - 1 ]
Exit Loop If [ $valueCount = 0 ]
Go to Record/Request/Page
[ Previous; Exit after last ]
End Loop
#
Close Window [ Current Window ]
Perform Script [ “CHUNKAddUpPointsAndTime” ]
Refresh Window
January 8, 平成26 12:40:16 Fat and Muscle Efﬁciency Research.fp7 - updateTimeSequence -11-
