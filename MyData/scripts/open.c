open
#PURPOSE determine if file was opened by admin or by script, and then depending on who opened it: admin = remain open, backup script =
save a copy of itself, or restore script = delete all its files and import backup files to replace them
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Show/Hide Status Area
[ Lock; Hide ]
Show/Hide Text Ruler
[ Hide ]
#
#
#
#1 backup script = save a copy of itself with the backup ﬂag made blank (this is so that when restore opens this file it will skip to part 3 just to
find the filepath and copy it, so that it in part 2 the restore script can reference this backup file and restore all records in it to the primary
data file.
If [ backup::backup = "backup" ]
Set Field [ backup::backup; "" ]
Set Window Title [ Current Window; New Title: "backup" ]
Save a Copy as [ ]
[ compacted copy (smaller) ]
Close File [ Current File ]
Halt Script
#
#2 restore script = delete all its files and import backup files to replace them
#IMPORT MUST BE DONE WITH DIALOGUE BOX SHOWING every time script is updated to teach filemaker what table to import records
from
Else If [ backup::backup = "restore" ]
Go to Layout [ “backup” (backup) ]
Paste [ backup::filepath ]
[ Select ]
Set Variable [ $filepath; Value:Get ( ActiveFieldContents ) ]
Go to Layout [ “user” (user) ]
Show All Records
Delete All Records
[ No dialog ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “user”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import to user::
FirstName
Source field 2 import to user::LastName
Source field 3 import to user::FirstPlusLast
Source field 4 import to user::Notes
Source field 5 import to user::_lockUser
Source field 6 import to user::hideStatus
Source field 7 import to user::retiredStatus
Source field 18 import to user::chartTime1
Source field 19 import to user::chartTime2
Source field 20 import to user::chartTime3
Source field 21 import to user::chartTime4
Source field 22 import to user::chartTime5
Source field 23 import to user::chartTime6
Source field 24 import to user::chartTime7
Source field 25 import to user::chartTime8
Source field 26 import to user::chartTime9
Source field 27 import to user::chartTime10
Source field 28 import to user::chosenDay
Source field 29 import to user::chosenWeek
Source field 30 import to user::chosenMonth
Source field 31 import to user::logListFormViewStatus
Source field 32 import to user::showStatus
Source field 33 import to user::showORhide
Source field 34 import to user::chosenSort
Source field 35 import to user::chosenLayout
Source field 36 import to user::_Number
Source field 37 import to user::chosenDayTotal
Source field 38 import to user::chosenWeekTotal
Source field 39 import to user::chosenMonthTotal
Source field 40 import to user::DaysSinceLastUseToggle
Source field 41 import to user::chosenSortTotal
Source field 42 import to user::iPhoneLayout
Source field 43 import to user::windowSizeAndPlace
Source field 44 import to user::chosenLayoutMain
Source field 45 import to user::windowZoom
Source field 46 import to user::chosenTagOrderSort ]
January 6, 平成26 13:14:23 MyData.fp7 - open -1-open
Import Records [ Source: “$filepath”; Target: “user”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import to user::
FirstName
Source field 2 import to user::LastName
Source field 3 import to user::FirstPlusLast
Source field 4 import to user::Notes
Source field 5 import to user::_lockUser
Source field 6 import to user::hideStatus
Source field 7 import to user::retiredStatus
Source field 18 import to user::chartTime1
Source field 19 import to user::chartTime2
Source field 20 import to user::chartTime3
Source field 21 import to user::chartTime4
Source field 22 import to user::chartTime5
Source field 23 import to user::chartTime6
Source field 24 import to user::chartTime7
Source field 25 import to user::chartTime8
Source field 26 import to user::chartTime9
Source field 27 import to user::chartTime10
Source field 28 import to user::chosenDay
Source field 29 import to user::chosenWeek
Source field 30 import to user::chosenMonth
Source field 31 import to user::logListFormViewStatus
Source field 32 import to user::showStatus
Source field 33 import to user::showORhide
Source field 34 import to user::chosenSort
Source field 35 import to user::chosenLayout
Source field 36 import to user::_Number
Source field 37 import to user::chosenDayTotal
Source field 38 import to user::chosenWeekTotal
Source field 39 import to user::chosenMonthTotal
Source field 40 import to user::DaysSinceLastUseToggle
Source field 41 import to user::chosenSortTotal
Source field 42 import to user::iPhoneLayout
Source field 43 import to user::windowSizeAndPlace
Source field 44 import to user::chosenLayoutMain
Source field 45 import to user::windowZoom
Source field 46 import to user::chosenTagOrderSort ]
Go to Layout [ “brainstate” (brainstate) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “brainstate”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import to
brainstate::description
Source field 2 import to brainstate::sortNumber
Source field 3 import to brainstate::_lockBrainstateID
Source field 4 import to brainstate::_keyUser
Source field 5 import to brainstate::SortOrder
Source field 7 import to brainstate::hide
Source field 15 import to brainstate::sortCategory
Source field 16 import to brainstate::sortRetired
Source field 17 import to brainstate::sortAlpha
Source field 18 import to brainstate::alarm
Source field 20 import to brainstate::groupAddCheckbox
Source field 23 import to brainstate::groupID
Source field 24 import to brainstate::kfS
Source field 25 import to brainstate::kfO
Source field 26 import to brainstate::kfR
Source field 27 import to brainstate::kfT
Source field 28 import to brainstate::retireDate
Source field 29 import to brainstate::separateDate
Source field 54 import to brainstate::monthsum
Source field 55 import to brainstate::groupUpdate
Source field 56 import to brainstate::groupType
Source field 57 import to brainstate::Show
Source field 81 import to brainstate::sortSubNumber
Source field 83 import to brainstate::groupOfGroupAddCheckbox
Source field 85 import to brainstate::groupOfGroupID
Source field 86 import to brainstate::groupOfGroupUpdate
Source field 87 import to brainstate::linkinfo
Source field 88 import to brainstate::_Number
Source field 89 import to brainstate::groupDisplayID
Source field 90 import to brainstate::groupOfGroupDisplayID
Source field 92 import to brainstate::schedule
Source field 93 import to brainstate::scheduleRepeatEventYear
Source field 94 import to brainstate::scheduleStartDate
Source field 95 import to brainstate::scheduleRepeatEventMonth
Source field 96 import to brainstate::FolderOn
Source field 97 import to brainstate::hideCheckBox
Source field 99 import to brainstate::tag1
Source field 100 import to brainstate::tag2
Source field 101 import to brainstate::tag3
Source field 103 import to brainstate::DateOfLastUse
Source field 104 import to brainstate::DaysSinceLastUseToggle
Source field 105 import to brainstate::lockIssue
Source field 106 import to brainstate::lockLocation
Source field 107 import to brainstate::lockObservation
Source field 108 import to brainstate::lockStatus
Source field 109 import to brainstate::lockObservationCategory
Source field 110 import to brainstate::lockPrefix
Source field 111 import to brainstate::pulldownBrainstate ]
Go to Layout [ “day” (day) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “day”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import to day::
_lockDay
Source field 2 import to day::timeForcast
Source field 3 import to day::swPause
Source field 6 import to day::alarm
Source field 7 import to day::_keyBrainstate
Source field 8 import to day::log
Source field 9 import to day::_keyDay
Source field 10 import to day::swStart
Source field 14 import to day::swTotalSum
Source field 16 import to day::swPauseLength
Source field 18 import to day::currentTime
Source field 19 import to day::updateTime
Source field 21 import to day::MergeRecord
Source field 25 import to day::_Number
Source field 26 import to day::_keyUser
Source field 30 import to day::updateTimeSymbol
Source field 31 import to day::_keyLogIssues
Source field 32 import to day::swLogTimeAccounting ]
January 6, 平成26 13:14:23 MyData.fp7 - open -2-open
Import Records [ Source: “$filepath”; Target: “day”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import to day::
_lockDay
Source field 2 import to day::timeForcast
Source field 3 import to day::swPause
Source field 6 import to day::alarm
Source field 7 import to day::_keyBrainstate
Source field 8 import to day::log
Source field 9 import to day::_keyDay
Source field 10 import to day::swStart
Source field 14 import to day::swTotalSum
Source field 16 import to day::swPauseLength
Source field 18 import to day::currentTime
Source field 19 import to day::updateTime
Source field 21 import to day::MergeRecord
Source field 25 import to day::_Number
Source field 26 import to day::_keyUser
Source field 30 import to day::updateTimeSymbol
Source field 31 import to day::_keyLogIssues
Source field 32 import to day::swLogTimeAccounting ]
Go to Layout [ “list” (list) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “list”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import to list::
_LockList
Source field 2 import to list::_Number
Source field 3 import to list::text
Source field 4 import to list::_keyBrainstate
Source field 5 import to list::order
Source field 6 import to list::lock
Source field 7 import to list::_keyCategory
Source field 8 import to list::date
Source field 9 import to list::dateDone
Source field 10 import to list::status
Source field 11 import to list::_keyStatus
Source field 12 import to list::_keyDay
Source field 13 import to list::_keyLogs
Source field 14 import to list::timeSegmentKeyList
Source field 15 import to list::issueTotalTime
Source field 18 import to list::sortTime
Source field 19 import to list::timeTotalSumByCat
Source field 20 import to list::oldCategorykey
Source field 21 import to list::timeTotalSumByCatSortedByStatus
Source field 24 import to list::reviewDate ]
Set Field [ backup::backup; "" ]
Close Window [ Current Window ]
Halt Script
End If
#
#3 open file and determine its location (path) and then remain open. If it opened by the restore script, then it will be closed by that script after
copying its location to it, and if it is opened by the user it will just remain open.
Set Window Title [ Current Window; New Title: "backup" ]
Go to Layout [ “backup” (backup) ]
Set Field [ backup::filepath; Get ( FilePath ) ]
Copy [ backup::filepath ]
[ Select ]
January 6, 平成26 13:14:23 MyData.fp7 - open -3-
