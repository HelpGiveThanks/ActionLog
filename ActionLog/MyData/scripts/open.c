open
#PURPOSE determine if ﬁle was opened by admin or by script, and then depending on who opened it: admin = remain open, backup script =
save a copy of itself, or restore script = delete all its ﬁles and import backup ﬁles to replace them
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
#1 backup script = save a copy of itself with the backup ﬂag made blank (this is so that when restore opens this ﬁle it will skip to part 3 just to
ﬁnd the ﬁlepath and copy it, so that it in part 2 the restore script can reference this backup ﬁle and restore all records in it to the primary
data ﬁle.
If [ backup::backup = "backup" ]
Set Field [ backup::backup; "" ]
Set Window Title [ Current Window; New Title: "backup" ]
Save a Copy as [ ]
[ compacted copy (smaller) ]
Close File [ Current File ]
Halt Script
#
#2 restore script = delete all its ﬁles and import backup ﬁles to replace them
#IMPORT MUST BE DONE WITH DIALOGUE BOX SHOWING every time script is updated to teach ﬁlemaker what table to import records
from
Else If [ backup::backup = "restore" ]
Go to Layout [ “backup” (backup) ]
Paste [ backup::ﬁlepath ]
[ Select ]
Set Variable [ $ﬁlepath; Value:Get ( ActiveFieldContents ) ]
Go to Layout [ “user” (user) ]
Show All Records
Delete All Records
[ No dialog ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$ﬁlepath”; Target: “user”; Method: Add; Character Set: “Unicode”; Field Mapping: Source ﬁeld 1 import to user::
FirstName
Source ﬁeld 2 import to user::LastName
Source ﬁeld 3 import to user::FirstPlusLast
Source ﬁeld 4 import to user::Notes
Source ﬁeld 5 import to user::_lockUser
Source ﬁeld 6 import to user::hideStatus
Source ﬁeld 7 import to user::retiredStatus
Source ﬁeld 18 import to user::chartTime1
Source ﬁeld 19 import to user::chartTime2
Source ﬁeld 20 import to user::chartTime3
Source ﬁeld 21 import to user::chartTime4
Source ﬁeld 22 import to user::chartTime5
Source ﬁeld 23 import to user::chartTime6
Source ﬁeld 24 import to user::chartTime7
Source ﬁeld 25 import to user::chartTime8
Source ﬁeld 26 import to user::chartTime9
Source ﬁeld 27 import to user::chartTime10
Source ﬁeld 28 import to user::chosenDay
Source ﬁeld 29 import to user::chosenWeek
Source ﬁeld 30 import to user::chosenMonth
Source ﬁeld 31 import to user::logListFormViewStatus
Source ﬁeld 32 import to user::showStatus
Source ﬁeld 33 import to user::showORhide
Source ﬁeld 34 import to user::chosenSort
Source ﬁeld 35 import to user::chosenLayout
Source ﬁeld 36 import to user::_Number
Source ﬁeld 37 import to user::chosenDayTotal
Source ﬁeld 38 import to user::chosenWeekTotal
Source ﬁeld 39 import to user::chosenMonthTotal
Source ﬁeld 40 import to user::DaysSinceLastUseToggle
Source ﬁeld 41 import to user::chosenSortTotal
Source ﬁeld 42 import to user::iPhoneLayout
Source ﬁeld 43 import to user::windowSizeAndPlace
Source ﬁeld 44 import to user::chosenLayoutMain
Source ﬁeld 45 import to user::windowZoom
Source ﬁeld 46 import to user::chosenTagOrderSort ]
January 6, 平成26 13:14:23 MyData.fp7 - open -1-open
Import Records [ Source: “$ﬁlepath”; Target: “user”; Method: Add; Character Set: “Unicode”; Field Mapping: Source ﬁeld 1 import to user::
FirstName
Source ﬁeld 2 import to user::LastName
Source ﬁeld 3 import to user::FirstPlusLast
Source ﬁeld 4 import to user::Notes
Source ﬁeld 5 import to user::_lockUser
Source ﬁeld 6 import to user::hideStatus
Source ﬁeld 7 import to user::retiredStatus
Source ﬁeld 18 import to user::chartTime1
Source ﬁeld 19 import to user::chartTime2
Source ﬁeld 20 import to user::chartTime3
Source ﬁeld 21 import to user::chartTime4
Source ﬁeld 22 import to user::chartTime5
Source ﬁeld 23 import to user::chartTime6
Source ﬁeld 24 import to user::chartTime7
Source ﬁeld 25 import to user::chartTime8
Source ﬁeld 26 import to user::chartTime9
Source ﬁeld 27 import to user::chartTime10
Source ﬁeld 28 import to user::chosenDay
Source ﬁeld 29 import to user::chosenWeek
Source ﬁeld 30 import to user::chosenMonth
Source ﬁeld 31 import to user::logListFormViewStatus
Source ﬁeld 32 import to user::showStatus
Source ﬁeld 33 import to user::showORhide
Source ﬁeld 34 import to user::chosenSort
Source ﬁeld 35 import to user::chosenLayout
Source ﬁeld 36 import to user::_Number
Source ﬁeld 37 import to user::chosenDayTotal
Source ﬁeld 38 import to user::chosenWeekTotal
Source ﬁeld 39 import to user::chosenMonthTotal
Source ﬁeld 40 import to user::DaysSinceLastUseToggle
Source ﬁeld 41 import to user::chosenSortTotal
Source ﬁeld 42 import to user::iPhoneLayout
Source ﬁeld 43 import to user::windowSizeAndPlace
Source ﬁeld 44 import to user::chosenLayoutMain
Source ﬁeld 45 import to user::windowZoom
Source ﬁeld 46 import to user::chosenTagOrderSort ]
Go to Layout [ “brainstate” (brainstate) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$ﬁlepath”; Target: “brainstate”; Method: Add; Character Set: “Unicode”; Field Mapping: Source ﬁeld 1 import to
brainstate::description
Source ﬁeld 2 import to brainstate::sortNumber
Source ﬁeld 3 import to brainstate::_lockBrainstateID
Source ﬁeld 4 import to brainstate::_keyUser
Source ﬁeld 5 import to brainstate::SortOrder
Source ﬁeld 7 import to brainstate::hide
Source ﬁeld 15 import to brainstate::sortCategory
Source ﬁeld 16 import to brainstate::sortRetired
Source ﬁeld 17 import to brainstate::sortAlpha
Source ﬁeld 18 import to brainstate::alarm
Source ﬁeld 20 import to brainstate::groupAddCheckbox
Source ﬁeld 23 import to brainstate::groupID
Source ﬁeld 24 import to brainstate::kfS
Source ﬁeld 25 import to brainstate::kfO
Source ﬁeld 26 import to brainstate::kfR
Source ﬁeld 27 import to brainstate::kfT
Source ﬁeld 28 import to brainstate::retireDate
Source ﬁeld 29 import to brainstate::separateDate
Source ﬁeld 54 import to brainstate::monthsum
Source ﬁeld 55 import to brainstate::groupUpdate
Source ﬁeld 56 import to brainstate::groupType
Source ﬁeld 57 import to brainstate::Show
Source ﬁeld 81 import to brainstate::sortSubNumber
Source ﬁeld 83 import to brainstate::groupOfGroupAddCheckbox
Source ﬁeld 85 import to brainstate::groupOfGroupID
Source ﬁeld 86 import to brainstate::groupOfGroupUpdate
Source ﬁeld 87 import to brainstate::linkinfo
Source ﬁeld 88 import to brainstate::_Number
Source ﬁeld 89 import to brainstate::groupDisplayID
Source ﬁeld 90 import to brainstate::groupOfGroupDisplayID
Source ﬁeld 92 import to brainstate::schedule
Source ﬁeld 93 import to brainstate::scheduleRepeatEventYear
Source ﬁeld 94 import to brainstate::scheduleStartDate
Source ﬁeld 95 import to brainstate::scheduleRepeatEventMonth
Source ﬁeld 96 import to brainstate::FolderOn
Source ﬁeld 97 import to brainstate::hideCheckBox
Source ﬁeld 99 import to brainstate::tag1
Source ﬁeld 100 import to brainstate::tag2
Source ﬁeld 101 import to brainstate::tag3
Source ﬁeld 103 import to brainstate::DateOfLastUse
Source ﬁeld 104 import to brainstate::DaysSinceLastUseToggle
Source ﬁeld 105 import to brainstate::lockIssue
Source ﬁeld 106 import to brainstate::lockLocation
Source ﬁeld 107 import to brainstate::lockObservation
Source ﬁeld 108 import to brainstate::lockStatus
Source ﬁeld 109 import to brainstate::lockObservationCategory
Source ﬁeld 110 import to brainstate::lockPreﬁx
Source ﬁeld 111 import to brainstate::pulldownBrainstate ]
Go to Layout [ “day” (day) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$ﬁlepath”; Target: “day”; Method: Add; Character Set: “Unicode”; Field Mapping: Source ﬁeld 1 import to day::
_lockDay
Source ﬁeld 2 import to day::timeForcast
Source ﬁeld 3 import to day::swPause
Source ﬁeld 6 import to day::alarm
Source ﬁeld 7 import to day::_keyBrainstate
Source ﬁeld 8 import to day::log
Source ﬁeld 9 import to day::_keyDay
Source ﬁeld 10 import to day::swStart
Source ﬁeld 14 import to day::swTotalSum
Source ﬁeld 16 import to day::swPauseLength
Source ﬁeld 18 import to day::currentTime
Source ﬁeld 19 import to day::updateTime
Source ﬁeld 21 import to day::MergeRecord
Source ﬁeld 25 import to day::_Number
Source ﬁeld 26 import to day::_keyUser
Source ﬁeld 30 import to day::updateTimeSymbol
Source ﬁeld 31 import to day::_keyLogIssues
Source ﬁeld 32 import to day::swLogTimeAccounting ]
January 6, 平成26 13:14:23 MyData.fp7 - open -2-open
Import Records [ Source: “$ﬁlepath”; Target: “day”; Method: Add; Character Set: “Unicode”; Field Mapping: Source ﬁeld 1 import to day::
_lockDay
Source ﬁeld 2 import to day::timeForcast
Source ﬁeld 3 import to day::swPause
Source ﬁeld 6 import to day::alarm
Source ﬁeld 7 import to day::_keyBrainstate
Source ﬁeld 8 import to day::log
Source ﬁeld 9 import to day::_keyDay
Source ﬁeld 10 import to day::swStart
Source ﬁeld 14 import to day::swTotalSum
Source ﬁeld 16 import to day::swPauseLength
Source ﬁeld 18 import to day::currentTime
Source ﬁeld 19 import to day::updateTime
Source ﬁeld 21 import to day::MergeRecord
Source ﬁeld 25 import to day::_Number
Source ﬁeld 26 import to day::_keyUser
Source ﬁeld 30 import to day::updateTimeSymbol
Source ﬁeld 31 import to day::_keyLogIssues
Source ﬁeld 32 import to day::swLogTimeAccounting ]
Go to Layout [ “list” (list) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$ﬁlepath”; Target: “list”; Method: Add; Character Set: “Unicode”; Field Mapping: Source ﬁeld 1 import to list::
_LockList
Source ﬁeld 2 import to list::_Number
Source ﬁeld 3 import to list::text
Source ﬁeld 4 import to list::_keyBrainstate
Source ﬁeld 5 import to list::order
Source ﬁeld 6 import to list::lock
Source ﬁeld 7 import to list::_keyCategory
Source ﬁeld 8 import to list::date
Source ﬁeld 9 import to list::dateDone
Source ﬁeld 10 import to list::status
Source ﬁeld 11 import to list::_keyStatus
Source ﬁeld 12 import to list::_keyDay
Source ﬁeld 13 import to list::_keyLogs
Source ﬁeld 14 import to list::timeSegmentKeyList
Source ﬁeld 15 import to list::issueTotalTime
Source ﬁeld 18 import to list::sortTime
Source ﬁeld 19 import to list::timeTotalSumByCat
Source ﬁeld 20 import to list::oldCategorykey
Source ﬁeld 21 import to list::timeTotalSumByCatSortedByStatus
Source ﬁeld 24 import to list::reviewDate ]
Set Field [ backup::backup; "" ]
Close Window [ Current Window ]
Halt Script
End If
#
#3 open ﬁle and determine its location (path) and then remain open. If it opened by the restore script, then it will be closed by that script after
copying its location to it, and if it is opened by the user it will just remain open.
Set Window Title [ Current Window; New Title: "backup" ]
Go to Layout [ “backup” (backup) ]
Set Field [ backup::ﬁlepath; Get ( FilePath ) ]
Copy [ backup::ﬁlepath ]
[ Select ]
January 6, 平成26 13:14:23 MyData.fp7 - open -3-
