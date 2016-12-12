specific action log: CHUNK_seeIfSPAisActiveOnOtherDays
#
#SPA = Specific Action (issue)
#
#This script is used by the updateTime,
#CHUNK_updateIssueCategoryTime, and
#addORsubtractTimeSegmentFromSPA scripts.
#
#Prevent loading record variables during loops
#thru them to speed things up.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#See if any of these Specific Action (issue)
#records are active on multiple days.
Loop
Set Variable [ $issue; Value:specificAction::_LockSpecificAction ]
Set Variable [ $logSegments; Value:specificAction::timeSegmentKeyList ]
Go to Layout [ “logs1row” (logs) ]
#
#Find all days on which this timer (brainstate)
#is active.
Enter Find Mode [ ]
Set Field [ logs::swBugField; "veto" ]
Set Field [ logs::_keyLogSPAs; $issue & ¶ ]
Set Field [ logs::_keyTimer; $$logBrainstate ]
Perform Find [ ]
#
#Check to see if this specific action (issue)
#record has any time segments that are active.
Loop
If [ FilterValues ($logSegments ; logs::swOccurances & daylog::_lockDay & "¶" ) = logs::swOccurances & logs::_lockDay &
"¶" ]
Set Variable [ $itsActive; Value:1 ]
End If
Set Variable [ $itsActiveTotal; Value:$itsActiveTotal + $itsActive ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Go to Layout [ “SpecificActionTable” (specificAction) ]
#
#Make this specific action active if there is one
#or more days on which this SPA is active.
If [ $itsActiveTotal > 0 ]
Set Field [ specificAction::timer; "active" ]
Else
Set Field [ specificAction::timer; "" ]
End If
#
#Repeat this loop for all remaining specific
#action (issue) timers if any.
Set Variable [ $itsActive ]
Set Variable [ $itsActiveTotal ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#Turn back on the ability to record variables.
Set Variable [ $$stopRecordLoad ]
#
December 10, ଘ౮28 23:45:47 ActionLog.fp7 - CHUNK_seeIfSPAisActiveOnOtherDays -1-
