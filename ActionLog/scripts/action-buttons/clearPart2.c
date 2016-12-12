action buttons: clearPart2
#PURPOSE script activated by the clearPart1 script,
#which is activated by the 'cleartime' button.
#It clears all time for a give day for the
#selected timer.
#
Allow User Abort [ Off ]
#
#Check to insure that there is a record to clear
#and if not halt the script.
If [ day1::_keyDay = "" or
timer::_lockTimer = timer::groupID or
timer::_lockTimer = timer::groupOfGroupID ]
Set Variable [ $$recordFIXTOMANYVARIABLES ]
Set Variable [ $$clear ]
Halt Script
End If
#
#????? Why ??????
#Preserve current stopwatch state before this
#info is deleted for use in updatetime script
#used later on in this script.
Set Variable [ $$onoff; Value:"note" ]
#
#BUG remove focus from any fields. This step
#seems to be neccessary as I periodically have
#been getting a -- this record is being
#modified in a separate window -- message.
Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
Go to Field [ ]
Go to Record/Request/Page [ $recordNumber ]
[ No dialog ]
#
#Find the day record.
Set Variable [ $dayID; Value:day1::_lockDay ]
Go to Layout [ “DayTable” (day1) ]
Enter Find Mode [ ]
Insert Calculated Result [ day1::_lockDay; $dayID ]
[ Select ]
Perform Find [ ]
#
#Capture day key to remove time from any
#issues records that currently have time from
#this day attributed to them.
Set Variable [ $$updateDay; Value:day1::_lockDay ]
#
#Turn on clear variable, which allows
#CHUNK_updateIssueCategoryTime to remove
#the deleted day's key from any SPA (issue)
#records.
Set Variable [ $$clear; Value:1 ]
#
#Delete the day record.
Set Variable [ $$stopRecordLoad; Value:1 ]
Delete Record/Request
[ No dialog ]
Set Variable [ $$stopRecordLoad ]
#
#Re-calculate last day this timer was used
#number to show user.
Perform Script [ “CHUNK_lastDayUsed” ]
#
#Update time in any linked SPA/issue records.
Go to Layout [ original layout ]
Perform Script [ “CHUNK_updateIssueCategoryTime (update)” ]
#
#Delete any SPA time records belonging
#to this day.
Go to Layout [ “SPATimeTable” (SPATime) ]
Enter Find Mode [ ]
Insert Calculated Result [ SPATime::_keyDay; $dayID ]
[ Select ]
Perform Find [ ]
If [ SPATime::_keyDay = $dayID ]
Delete All Records
[ No dialog ]
End If
Go to Layout [ original layout ]
#
#Script will halt after performing sort step below
#so clear the $$clear variable.
Set Variable [ $$clear ]
#
#Update time for other Timers as user may
#have dragged time to other records before
#clicking the 'clear' button.
Select Window [ Name: "Timer"; Current file ]
Set Variable [ $$stopCHUNK_updateIssueCategoryTime; Value:1 ]
Perform Script [ “updateTime” ]
Go to Field [ ]
#
December 10, ଘ౮28 20:51:10 ActionLog.fp7 - clearPart2 -1-
