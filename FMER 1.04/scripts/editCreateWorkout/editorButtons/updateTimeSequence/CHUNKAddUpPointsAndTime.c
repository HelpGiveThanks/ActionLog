editCreateWorkout: editorButtons: updateTimeSequence: CHUNKAddUpPointsAndTime
Set Variable [ $workout; Value:activity::_Lactivity ]
Go to Field [ ]
Go to Layout [ “WorkoutSegment” (segment01) ]
Enter Find Mode [ ]
Set Field [ segment01::kworkout; $workout ]
Perform Find [ ]
Go to Record/Request/Page
[ First ]
#
#Clear all points.
Go to Object [ Object Name: 1 ]
Set Field [ "" ]
Go to Object [ Object Name: 2 ]
Set Field [ "" ]
Go to Object [ Object Name: 3 ]
Set Field [ "" ]
Go to Object [ Object Name: 4 ]
Set Field [ "" ]
Go to Object [ Object Name: 5 ]
Set Field [ "" ]
#
#Loop thru each segemet and capture points for one
#zone at a time.
Set Variable [ $zone; Value:1 ]
Loop
Loop
#
#Add full or half points to zone total depending on
#icon segement point spread over 1 or 2 zones.
If [ segment01::ZoneMultiplier = $zone ]
#
If [ Length (segment01::ZoneMultiplier) = 1 ]
Go to Object [ Object Name: $zone ]
Set Variable [ $add; Value:Get (ActiveFieldContents) ]
Set Field [ segment01::ZonePoints + $add ]
#
Else If [ Length (segment01::ZoneMultiplier) ≠ 1 ]
#
If [ segment01::ZoneMultiplier = 2.5 ]
Go to Object [ Object Name: 2 ]
Set Variable [ $add; Value:Get (ActiveFieldContents) ]
Set Field [ ( ( ( ( (
segment01::ZonePoints
* 60 )
/ segment01::ZoneMultiplier )
/ 2 )
* 2 )
/ 60 )
+ $add ]
January 8, 平成26 12:42:28 Fat and Muscle Efﬁciency Research.fp7 - CHUNKAddUpPointsAndTime -1-editCreateWorkout: editorButtons: updateTimeSequence: CHUNKAddUpPointsAndTime
Go to Object [ Object Name: 3 ]
Set Variable [ $add; Value:Get (ActiveFieldContents) ]
Set Field [ ( ( ( ( (
segment01::ZonePoints
* 60 )
/ segment01::ZoneMultiplier )
/ 2 )
* 3 )
/ 60 )
+ $add ]
#
Else If [ segment01::ZoneMultiplier = 3.5 ]
Go to Object [ Object Name: 3 ]
Set Variable [ $add; Value:Get (ActiveFieldContents) ]
Set Field [ ( ( ( ( (
segment01::ZonePoints
* 60 )
/ segment01::ZoneMultiplier )
/ 2 )
* 3 )
/ 60 )
+ $add ]
Go to Object [ Object Name: 4 ]
Set Variable [ $add; Value:Get (ActiveFieldContents) ]
Set Field [ ( ( ( ( (
segment01::ZonePoints
* 60 )
/ segment01::ZoneMultiplier )
/ 2 )
* 4 )
/ 60 )
+ $add ]
#
Else If [ segment01::ZoneMultiplier = 4.5 ]
Go to Object [ Object Name: 4 ]
Set Variable [ $add; Value:Get (ActiveFieldContents) ]
Set Field [ ( ( ( ( (
segment01::ZonePoints
* 60 )
/ segment01::ZoneMultiplier )
/ 2 )
* 4 )
/ 60 )
+ $add ]
Go to Object [ Object Name: 5 ]
January 8, 平成26 12:42:28 Fat and Muscle Efﬁciency Research.fp7 - CHUNKAddUpPointsAndTime -2-editCreateWorkout: editorButtons: updateTimeSequence: CHUNKAddUpPointsAndTime
Set Variable [ $add; Value:Get (ActiveFieldContents) ]
Set Field [ ( ( ( ( (
segment01::ZonePoints
* 60 )
/ segment01::ZoneMultiplier )
/ 2 )
* 5 )
/ 60 )
+ $add ]
End If
#
End If
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Set Variable [ $zone; Value:Case (
$zone = 1 ; 2 ;
$zone = 2 ; 2.5 ;
$zone = 2.5 ; 3 ;
$zone = 3 ; 3.5 ;
$zone = 3.5 ; 4 ;
$zone = 4 ; 4.5 ;
$zone = 4.5 ; 5 ;
$zone = 5 ; 6 ) ]
Exit Loop If [ $zone = 6 ]
Go to Record/Request/Page
[ First ]
End Loop
#
#Insert zone total time.
Go to Object [ Object Name: 1 ]
Set Variable [ $points; Value:Get (ActiveFieldContents) ]
Go to Object [ Object Name: "1t" ]
Set Field [ Round ( Case (
$points * 60 = 0 ;
"" ;
$points * 60 ) ; "" ) ]
#
Go to Object [ Object Name: 2 ]
Set Variable [ $points; Value:Get (ActiveFieldContents) /2 ]
Go to Object [ Object Name: "2t" ]
Set Field [ Round ( Case (
$points * 60 = 0 ;
"" ;
$points * 60 ) ; "" ) ]
#
Go to Object [ Object Name: 3 ]
Set Variable [ $points; Value:Get (ActiveFieldContents) /3 ]
Go to Object [ Object Name: "3t" ]
Set Field [ Round ( Case (
$points * 60 = 0 ;
"" ;
$points * 60 ) ; "" ) ]
#
January 8, 平成26 12:42:28 Fat and Muscle Efﬁciency Research.fp7 - CHUNKAddUpPointsAndTime -3-editCreateWorkout: editorButtons: updateTimeSequence: CHUNKAddUpPointsAndTime
Go to Object [ Object Name: 4 ]
Set Variable [ $points; Value:Get (ActiveFieldContents) /4 ]
Go to Object [ Object Name: "4t" ]
Set Field [ Round ( Case (
$points * 60 = 0 ;
"" ;
$points * 60 ) ; "" ) ]
#
Go to Object [ Object Name: 5 ]
Set Variable [ $points; Value:Get (ActiveFieldContents) / 5 ]
Go to Object [ Object Name: "5t" ]
Set Field [ Round ( Case (
$points * 60 = 0 ;
"" ;
$points * 60 ) ; "" ) ]
#
Go to Layout [ original layout ]
Set Field [ activity::go; 1 ]
Set Field [ activity::reTotal; "" ]
January 8, 平成26 12:42:28 Fat and Muscle Efﬁciency Research.fp7 - CHUNKAddUpPointsAndTime -4-
