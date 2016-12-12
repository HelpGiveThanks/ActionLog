specific action log: deleteIssue
#
#Color red the specific action to be deleted,
#set variables needed later on this script, and
#importantly exit any fields (failure to exit
#results in a 301 (record is in use another
#window) error and prevents script from
#resetting group total time.
Set Variable [ $name; Value:specificAction::text ]
Set Variable [ $delete; Value:specificAction::_LockSpecificAction ]
Set Variable [ $$stopCategoryRequest; Value:1 ]
Set Variable [ $categoryKey; Value:specificAction::_keyGroup ]
Set Variable [ $issueTotalTime; Value:specificAction::SPATotalTime ]
Go to Field [ ]
Refresh Window
#
#Ask the user if they really want to do this.
If [ specificAction::SPATotalTime = "" ]
Show Custom Dialog [ Message: "Delete, " & Case ( Length ($name) < 26 ; $name ; Left ($name ; 30) ) & " ... ?"; Buttons:
“Cancel”, “Delete” ]
Else
Show Custom Dialog [ Message: "Delete, " & Case ( Length ($name) < 26 ; $name ; Left ($name ; 30) ) &
" and unassign all day time-segments (totaling " & $issueTotalTime & " hours) credited to it?"; Buttons: “Cancel”, “Delete” ]
End If
#
#If they do then continue with the delete.
If [ Get ( LastMessageChoice ) = 2 ]
#
#Check if the specific action has time linked to it.
If [ specificAction::SPATotalTime ≠ "" ]
#
#Prevent windows from flashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
New Window [ Name: "Linked Days" ]
#
#Exit issue field so conditional formatting can be applied.
Go to Field [ ]
#
#Find all day records linked to this issue.
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyLogSPAs; $$issue ]
Perform Find [ ]
#
#Go to layout displaying all time segements
#for the selected day record.
If [ daylog::swActivityLength[11] ≠ "" ]
Go to Layout [ “logs3rows” (logs) ]
Else If [ daylog::swActivityLength[6] ≠ "" ]
Go to Layout [ “logs2rows” (logs) ]
Else If [ daylog::swActivityLength[6] = "" ]
Go to Layout [ “logs1row” (logs) ]
End If
Sort Records [ Specified Sort Order: logs::_keyTimer; descending
logs::_keyDay; descending ]
[ Restore; No dialog ]
#
#Animate Day window to call users attention
#to it.
If [ Get ( SystemPlatform ) ≠ 3 ]
Pause/Resume Script [ Duration (seconds): .01 ]
Move/Resize Window [ Current Window; Left: Get ( WindowWidth ) / 6 ]
Pause/Resume Script [ Duration (seconds): .01 ]
Move/Resize Window [ Current Window; Left: Get ( WindowWidth ) / 4 ]
Pause/Resume Script [ Duration (seconds): .01 ]
Move/Resize Window [ Current Window; Left: Get ( WindowWidth ) / 2 ]
Pause/Resume Script [ Duration (seconds): .01 ]
Move/Resize Window [ Current Window; Left: Get ( WindowWidth ) ]
End If
#
#Inform user of consequences to deleting
#this record.
Set Variable [ $linkedTotal; Value:Get (FoundCount) ]
If [ Get ( SystemPlatform ) ≠ 3 ]
Show Custom Dialog [ Message: $linkedTotal & " days (shown right) are linked to this specific action. Are you sure
you want delete this specific action (highlighted left) and unassign all day time-segments (totaling " &
$issueTotalTime & " hours) credited to it?"; Buttons: “Yes”, “Cancel” ]
Else
Show Custom Dialog [ Message: $linkedTotal & " days are linked to this specific action. Are you sure you want delete
it and unassign all day time-segments (totaling " & $issueTotalTime & " hours) credited to it?"; Buttons: “Yes”,
“Cancel” ]
End If
#
#Stop the delete if the user cancels it.
If [ Get ( LastMessageChoice ) = 2 ]
Set Variable [ $cancel; Value:1 ]
Set Variable [ $$stopRecordLoad ]
Close Window [ Name: "Linked Days"; Current file ]
End If
#
#If the user decides to continue then proceed.
If [ Get ( LastMessageChoice ) = 1 ]
#
#
Go to Layout [ “Issues” (specificAction) ]
Set Field [ specificAction::SPATotalTime; "" ]
#
#Eliminate this issue's time from the all the
#time assigned to its category.
Go to Layout [ “SPATimeTable” (SPATime) ]
Enter Find Mode [ ]
Set Field [ SPATime::_keySPA; $$issue ]
Allow User Abort [ Off ]
Set Error Capture [ On ]
Perform Find [ ]
#
#Delete all group time just in case this was the
#last issue in this group (adding up total time
#remaining in this group requires there be at
#least one specific action record, and if there
#isn't then the system will return 101 (record
#is missing) error because there are no
#records. Without a record to establish a
#relationship to the group table the system
#will not know which group's total needs to be
#deleted, thus, we need to delete it's total
#before deleting these time records.
Set Field [ SPAGroupTag 2::SPATotalTime; "" ]
#
#Imporant to commit the record now as
#otherwise the system will retain the deleted
#value and add it to the group in the rare
#case when there are no more time records in
#this group to force the system to replace the
#old value with a new one. I.E. A retained old
#value will be put back in as the total time
#for this group, UNLESS a commit takes place
#that clears the old time value from the system's
#memory, so no time can be recorded as this
#group's total time if in fact all time is now
#being deleted.
Commit Records/Requests
[ Skip data entry validation; No dialog ]
#
#Delete this issue's time records.
Delete All Records
[ No dialog ]
#
#Add up total time for category it is in.
Enter Find Mode [ ]
Set Field [ specificAction::_keyGroup; $categoryKey ]
Perform Find [ ]
#
#Set new total time for group.
Sort Records [ Specified Sort Order: specificAction::_keyGroup; ascending ]
[ Restore; No dialog ]
Set Field [ SPAGroupTag 2::SPATotalTime; GetSummary ( specificAction::timeSummary ; specificAction::_keyGroup ) ]
#
#Find all day records linked to this issue.
Go to Layout [ “logs2rows” (logs) ]
Enter Find Mode [ ]
Set Field [ logs::_keyLogSPAs; $$issue ]
Perform Find [ ]
Go to Record/Request/Page
[ First ]
Loop
#
#Remove issue key from an activity log (day) records.
Set Variable [ $logIssues; Value:logs::_keyLogSPAs ]
Set Field [ logs::_keyLogSPAs; //last item in list has no paragraph mark, so a valuecount test needs to be done and
if item is not removed, then the removal calc without the paragraph mark is used.
If ( ValueCount ( $logIssues ) ≠ ValueCount ( Substitute ( $logIssues ; $$issue & "¶" ; "" ) ) ;
Substitute ( $logIssues ; $$issue & "¶" ; "" ) ;
Substitute ( $logIssues ; $$issue ; "" )
) ]
#
#Remove issue key from repetitions for each record.
Set Variable [ $repetition; Value:1 ]
Loop
If [ logs::swLogTimeAccounting[$repetition] = $$issue ]
Set Field [ logs::swLogTimeAccounting[$repetition]; "" ]
End If
Set Variable [ $repetition; Value:$repetition + 1 ]
Exit Loop If [ $repetition = 31 ]
End Loop
#
#Go to next day record.
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
Set Variable [ $$stopRecordLoad ]
#
Close Window [ Name: "Linked Days"; Current file ]
End If
End If
#
#If the user canceled the delete, don't delete it.
If [ $cancel ≠ 1 ]
Delete Record/Request
[ No dialog ]
End If
End If
#
#Return window to non-delete colors.
Set Variable [ $delete ]
Set Variable [ $$stopCategoryRequest ]
Select Window [ Name: "Specific Action"; Current file ]
Go to Field [ specificAction::text ]
Go to Field [ ]
Refresh Window
#
December 10, ଘ౮28 21:05:46 ActionLog.fp7 - deleteIssue -1-
