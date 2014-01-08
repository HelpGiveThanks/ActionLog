planned workouts: main: useWeek
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#If there are no records, then exit script.
If [ Get (FoundCount) = 0 ]
Exit Script [ ]
End If
#
#Stop record load scripts to prevent variables from
#being changed and to speed up script.
Set Variable [ $$stopLoadUserWeek; Value:1 ]
#
#Check to make sure all records are assigned to a
#workout (there are no green rows of planned time).
Go to Record/Request/Page
[ First ]
Loop
If [ planlog::kworkout = "" ]
Go to Record/Request/Page
[ First ]
Show Custom Dialog [ Message: "There are still green planned rows in this week. These must be replaced by actual
workouts or deleted before this week of workouts can be created."; Buttons: “OK” ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadPlanWeek” ]
#
Exit Script [ ]
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Check to make sure all records are totaled.
Go to Record/Request/Page
[ First ]
Loop
If [ activity::go = "" ]
Go to Record/Request/Page
[ First ]
Show Custom Dialog [ Message: "Total all workouts."; Buttons: “OK” ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadPlanWeek” ]
#
Exit Script [ ]
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
January 8, 平成26 12:31:37 Fat and Muscle Efﬁciency Research.fp7 - useWeek -1-planned workouts: main: useWeek
#
#Next insure that this plan has an intensity level on which
#the plan is based.
If [ week::kintensity = "" ]
Go to Record/Request/Page
[ First ]
Show Custom Dialog [ Message: "Select a level for this week of workouts."; Buttons: “OK” ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadPlanWeek” ]
#
Exit Script [ ]
End If
#
#Next insure that this plan meets the percentage
#requirements for the intesity level selected.
If [ //zone 1
Case ( Middle ( intensityWeek::timeInZone ; 1 ; 3 ) = "100" ;
planlog::z1percentage_plan = 1 ;
Middle ( intensityWeek::timeInZone ; 1 ; 2 ) = 30 ;
.25 ≤ Left ( planlog::z1percentage_plan ; 3 ) and Left ( planlog::z1percentage_plan ; 3 ) ≤ .35 ;
Middle ( intensityWeek::timeInZone ; 1 ; 2 ) = 10 ;
.05 ≤ Left ( planlog::z1percentage_plan ; 3 ) and Left ( planlog::z1percentage_plan ; 3 ) ≤ .15 ;
Middle ( intensityWeek::timeInZone ; 1 ; 2 ) = "05" ;
.01 ≤ Left ( planlog::z1percentage_plan ; 3 ) and Left ( planlog::z1percentage_plan ; 3 ) ≤ .07 )
 or
//zone 2
Case (
Middle ( intensityWeek::timeInZone ; 3 ; 2 ) = 40 ;
.35 ≤ Left ( planlog::z2percentage_plan ; 3 ) and Left ( planlog::z2percentage_plan ; 3 ) ≤ .45 ;
Middle ( intensityWeek::timeInZone ; 3 ; 2 ) = 70 ;
.65 ≤ Left ( planlog::z2percentage_plan ; 3 ) and Left ( planlog::z2percentage_plan ; 3 ) ≤ .75 ;
Middle ( intensityWeek::timeInZone ; 3 ; 2 ) = 10 ;
.05 ≤ Left ( planlog::z2percentage_plan ; 3 ) and Left ( planlog::z2percentage_plan ; 3 ) ≤ .15 ;
Middle ( intensityWeek::timeInZone ; 3 ; 2 ) = 15 ;
.1 ≤ Left ( planlog::z2percentage_plan ; 3 ) and Left ( planlog::z2percentage_plan ; 3 ) ≤ .2 )
 or
//zone 3
Case (
Middle ( intensityWeek::timeInZone ; 5 ; 2 ) = 60 ;
.55 ≤ Left ( planlog::z3percentage_plan ; 3 ) and Left ( planlog::z3percentage_plan ; 3 ) ≤ .65 ;
Middle ( intensityWeek::timeInZone ; 5 ; 2 ) = 70 ;
.65 ≤ Left ( planlog::z3percentage_plan ; 3 ) and Left ( planlog::z3percentage_plan ; 3 ) ≤ .75 ;
Middle ( intensityWeek::timeInZone ; 5 ; 2 ) = 50 ;
.45 ≤ Left ( planlog::z3percentage_plan ; 3 ) and Left ( planlog::z3percentage_plan ; 3 ) ≤ .55 )
 or
//zone 4
Case (
Middle ( intensityWeek::timeInZone ; 7 ; 2 ) = 10 ;
.05 ≤ Left ( planlog::z4percentage_plan ; 3 ) and Left ( planlog::z4percentage_plan ; 3 ) ≤ .15 ;
Middle ( intensityWeek::timeInZone ; 7 ; 2 ) = 20 ;
.15 ≤ Left ( planlog::z4percentage_plan ; 3 ) and Left ( planlog::z4percentage_plan ; 3 ) ≤ .25 )
 or
//zone 5
Case (
Middle ( intensityWeek::timeInZone ; 9 ; 2 ) = 10 ;
.05 ≤ Left ( planlog::z5percentage_plan ; 3 ) and Left ( planlog::z5percentage_plan ; 3 ) ≤ .15 ; ) ]
January 8, 平成26 12:31:37 Fat and Muscle Efﬁciency Research.fp7 - useWeek -2-planned workouts: main: useWeek
If [ //zone 1
Case ( Middle ( intensityWeek::timeInZone ; 1 ; 3 ) = "100" ;
planlog::z1percentage_plan = 1 ;
Middle ( intensityWeek::timeInZone ; 1 ; 2 ) = 30 ;
.25 ≤ Left ( planlog::z1percentage_plan ; 3 ) and Left ( planlog::z1percentage_plan ; 3 ) ≤ .35 ;
Middle ( intensityWeek::timeInZone ; 1 ; 2 ) = 10 ;
.05 ≤ Left ( planlog::z1percentage_plan ; 3 ) and Left ( planlog::z1percentage_plan ; 3 ) ≤ .15 ;
Middle ( intensityWeek::timeInZone ; 1 ; 2 ) = "05" ;
.01 ≤ Left ( planlog::z1percentage_plan ; 3 ) and Left ( planlog::z1percentage_plan ; 3 ) ≤ .07 )
 or
//zone 2
Case (
Middle ( intensityWeek::timeInZone ; 3 ; 2 ) = 40 ;
.35 ≤ Left ( planlog::z2percentage_plan ; 3 ) and Left ( planlog::z2percentage_plan ; 3 ) ≤ .45 ;
Middle ( intensityWeek::timeInZone ; 3 ; 2 ) = 70 ;
.65 ≤ Left ( planlog::z2percentage_plan ; 3 ) and Left ( planlog::z2percentage_plan ; 3 ) ≤ .75 ;
Middle ( intensityWeek::timeInZone ; 3 ; 2 ) = 10 ;
.05 ≤ Left ( planlog::z2percentage_plan ; 3 ) and Left ( planlog::z2percentage_plan ; 3 ) ≤ .15 ;
Middle ( intensityWeek::timeInZone ; 3 ; 2 ) = 15 ;
.1 ≤ Left ( planlog::z2percentage_plan ; 3 ) and Left ( planlog::z2percentage_plan ; 3 ) ≤ .2 )
 or
//zone 3
Case (
Middle ( intensityWeek::timeInZone ; 5 ; 2 ) = 60 ;
.55 ≤ Left ( planlog::z3percentage_plan ; 3 ) and Left ( planlog::z3percentage_plan ; 3 ) ≤ .65 ;
Middle ( intensityWeek::timeInZone ; 5 ; 2 ) = 70 ;
.65 ≤ Left ( planlog::z3percentage_plan ; 3 ) and Left ( planlog::z3percentage_plan ; 3 ) ≤ .75 ;
Middle ( intensityWeek::timeInZone ; 5 ; 2 ) = 50 ;
.45 ≤ Left ( planlog::z3percentage_plan ; 3 ) and Left ( planlog::z3percentage_plan ; 3 ) ≤ .55 )
 or
//zone 4
Case (
Middle ( intensityWeek::timeInZone ; 7 ; 2 ) = 10 ;
.05 ≤ Left ( planlog::z4percentage_plan ; 3 ) and Left ( planlog::z4percentage_plan ; 3 ) ≤ .15 ;
Middle ( intensityWeek::timeInZone ; 7 ; 2 ) = 20 ;
.15 ≤ Left ( planlog::z4percentage_plan ; 3 ) and Left ( planlog::z4percentage_plan ; 3 ) ≤ .25 )
 or
//zone 5
Case (
Middle ( intensityWeek::timeInZone ; 9 ; 2 ) = 10 ;
.05 ≤ Left ( planlog::z5percentage_plan ; 3 ) and Left ( planlog::z5percentage_plan ; 3 ) ≤ .15 ; ) ]
#Continue script if it meets the requirements.
Else
Go to Record/Request/Page
[ First ]
Show Custom Dialog [ Message: "This is plan does not meet the intestity-level percentage requirements selected. All
percentages need to be green (within 5%) of the requirement before you can use this plan."; Buttons: “OK” ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadPlanWeek” ]
#
Exit Script [ ]
End If
#
#Make sure plan is assigned to a prediction.
If [ week::kprediction = "" ]
Go to Record/Request/Page
[ First ]
Show Custom Dialog [ Message: "These workouts need to part of a series of workouts that you predict will cause your body to be
able to do X comfortably: walk 5 miles, ﬁnish a half-marthon in 3 hours, hike up and down steep hills for 1 hour, etc."; Buttons:
“OK” ]
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadPlanWeek” ]
#
Exit Script [ ]
End If
#
#Clear order field as it will be assigned 1 when a
#prediction is selected is for it because there is only
#one week showing. The system will not know the
#real order number until it finds all the weeks that
#are part of this prediction in the next step.
#Clearning this field will insure this week becomes the
#last record in that set.
Set Field [ week::Order; "" ]
#
#Get the last order number for the set of weeks with
#no prediction assigned to them.
Set Variable [ $prediction; Value:week::kprediction ]
Go to Layout [ “weekTag” (week) ]
Enter Find Mode [ ]
Set Field [ week::kprediction; $prediction ]
Perform Find [ ]
If [ Get (FoundCount) = 1 ]
January 8, 平成26 12:31:37 Fat and Muscle Efﬁciency Research.fp7 - useWeek -3-planned workouts: main: useWeek
Set Field [ week::Order; 1 ]
Else
Sort Records [ Specified Sort Order: week::Order; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ Last ]
Set Variable [ $order; Value:week::Order ]
#
#Give it the last order number for this set of weeks.
Go to Record/Request/Page
[ First ]
Set Field [ week::Order; $order + 1 ]
End If
#
#Clear editor window so locked workout cannot be edited.
#If it was left in the window it could be edited.
Select Window [ Name: "Workout Editor"; Current file ]
Enter Find Mode [ ]
Set Field [ activity::_Lactivity; "nothing" ]
Perform Find [ ]
#
#Change status to planned and lock all workouts.
#Workouts are locked so that they cannot be changed
#which would mess up the precentages of weeks using
#these workouts.
#But first make a key for first record's lock for final stage.
Select Window [ Name: "Plan Week"; Current file ]
Go to Layout [ “userWeek” (planlog) ]
Go to Record/Request/Page
[ First ]
Set Variable [ $key; Value:planlog::_Lplanlog ]
#
Loop
Set Field [ planlog::plannedOrPerformed; "planned" ]
Set Field [ activity::planningOrPlanned; "locked" ]
Omit Record
Exit Loop If [ Get (FoundCount) = 0 ]
End Loop
Go to Layout [ “weekPlan” (planlog) ]
#
#Go the Predictions window and show this new planned
#week along with all the other planned weeks.
Select Window [ Name: "Planned Workouts"; Current file ]
Enter Find Mode [ ]
Set Field [ planlog::kuser; planlog::kuserGlobal ]
Set Field [ planlog::plannedOrPerformed; "planned" ]
Perform Find [ ]
Sort Records [ Specified Sort Order: prediction 3::name; ascending
week::Order; ascending ]
[ Restore; No dialog ]
#
#Take user to the newly planned week.
January 8, 平成26 12:31:37 Fat and Muscle Efﬁciency Research.fp7 - useWeek -4-planned workouts: main: useWeek
Loop
Exit Loop If [ planlog::_Lplanlog = $key ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Restart load record script and perform it to highlight
#current record, if any.
Set Variable [ $$stopLoadUserWeek ]
Perform Script [ “loadUserPlannedWeek” ]
#
January 8, 平成26 12:31:37 Fat and Muscle Efﬁciency Research.fp7 - useWeek -5-
