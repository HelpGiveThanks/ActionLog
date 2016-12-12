open 
#PURPOSE determine if file was opened by admin or by script, and then depending on who opened it: admin = remain open, backup
script = save a copy of itself, or restore script = delete all its files and import backup files to replace them
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
#1 backup script = save a copy of itself with the backup flag made blank (this is so that when restore opens this file it will skip to part 3
just to find the filepath and copy it, so that it in part 2 the restore script can reference this backup file and restore all records in it to
the primary data file.
If [ backup::backup = "backup" ]
Set Field [ backup::backup; "" ]
Set Window Title [ Current Window; New Title: "backup" ]
Save a Copy as [ ]
[ compacted copy (smaller) ]
Close File [ Current File ]
Halt Script
#
#2 restore script = delete all its files and import backup files to replace them
#IMPORT MUST BE DONE WITH DIALOGUE BOX SHOWING every time script is updated to teach filemaker what table to
import records from
Else If [ backup::backup = "restore" ]
Go to Layout [ “backup” (backup) ]
Paste [ backup::filepath ]
[ Select ]
Set Variable [ $filepath; Value:Get ( ActiveFieldContents ) ]
#
Go to Layout [ “user” (user) ]
Show All Records
Delete All Records
[ No dialog ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “user”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import
to user::FirstName
Source field 2 import to user::LastName
Source field 3 import to user::FirstPlusLast
Source field 4 import to user::Notes
Source field 5 import to user::_lockUser
Source field 6 import to user::hideStatus
Source field 7 import to user::retiredStatus
Source field 8 import to user::chartTime1
Source field 9 import to user::chartTime2
Source field 10 import to user::chartTime3
Source field 11 import to user::chartTime4
Source field 12 import to user::chartTime5
Source field 13 import to user::chartTime6
Source field 14 import to user::chartTime7
Source field 15 import to user::chartTime8
Source field 16 import to user::chartTime9
Source field 17 import to user::chartTime10
Source field 18 import to user::chosenDay
Source field 19 import to user::chosenWeek
Source field 20 import to user::chosenMonth
Source field 21 import to user::logListFormViewStatus
Source field 22 import to user::showStatus
Source field 23 import to user::showORhide
Source field 24 import to user::chosenSort
Source field 25 import to user::chosenLayout
Source field 26 import to user::_Number
Source field 27 import to user::chosenDayTotal
Source field 28 import to user::chosenWeekTotal
Source field 29 import to user::chosenMonthTotal
Source field 30 import to user::DaysSinceLastUseToggle
Source field 31 import to user::chosenSortTotal
Source field 32 import to user::iPhoneLayout
Source field 33 import to user::windowSizeAndPlace
Source field 34 import to user::chosenLayoutMain
Source field 35 import to user::windowZoom
Source field 36 import to user::chosenTagOrderSort
Source field 37 import to user::DefaultSpecificAction
Source field 38 import to user::birthday ]
#
Go to Layout [ “timer” (timer) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “timer”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import
to timer::description
Source field 2 import to timer::sortNumber
Source field 3 import to timer::_lockTimer
Source field 4 import to timer::_keyUser
Source field 5 import to timer::SortOrder
Source field 7 import to timer::hide
Source field 15 import to timer::sortCategory
Source field 16 import to timer::sortRetired
Source field 17 import to timer::sortAlpha
Source field 18 import to timer::newDayTimer
Source field 19 import to timer::groupAddCheckbox
Source field 22 import to timer::groupID
Source field 23 import to timer::kfS
Source field 24 import to timer::kfO
Source field 25 import to timer::kfR
Source field 26 import to timer::kfT
Source field 27 import to timer::retireDate
Source field 28 import to timer::separateDate
Source field 53 import to timer::monthsum
Source field 54 import to timer::groupUpdate
Source field 55 import to timer::groupType
Source field 56 import to timer::Show
Source field 59 import to timer::monthsumaverage
Source field 60 import to timer::monthsumdays
Source field 62 import to timer::sortSubNumber
Source field 64 import to timer::groupOfGroupAddCheckbox
Source field 66 import to timer::groupOfGroupID
Source field 67 import to timer::groupOfGroupUpdate
Source field 68 import to timer::linkinfo
Source field 69 import to timer::_Number
Source field 70 import to timer::groupDisplayID
Source field 71 import to timer::groupOfGroupDisplayID
Source field 73 import to timer::schedule
Source field 74 import to timer::scheduleRepeatEventYear
Source field 75 import to timer::scheduleStartDate
Source field 76 import to timer::scheduleRepeatEventMonth
Source field 77 import to timer::FolderOn
Source field 78 import to timer::hideCheckBox
Source field 80 import to timer::tag1
Source field 81 import to timer::tag2
Source field 82 import to timer::tag3
Source field 84 import to timer::DateOfLastUse
Source field 85 import to timer::DaysSinceLastUseToggle
Source field 86 import to timer::lockIssue
Source field 87 import to timer::lockLocation
Source field 88 import to timer::lockObservation
Source field 89 import to timer::lockStatus
Source field 90 import to timer::lockObservationCategory
Source field 91 import to timer::lockPrefix
Source field 92 import to timer::pulldownTimer
Source field 93 import to timer::totalTimeLogged
Source field 94 import to timer::HighlightLibraryButton
Source field 95 import to timer::HighlightSpecificActionButton
Source field 96 import to timer::HighlightNoteButton ]
#
Go to Layout [ “day” (day) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “day”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field 1 import
to day::_lockDay
Source field 2 import to day::timeForcast
Source field 3 import to day::swPause
Source field 6 import to day::alarm
Source field 7 import to day::_keyTimer
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
Source field 31 import to day::_keyLogSPAs
Source field 32 import to day::swLogTimeAccounting ]
#
Go to Layout [ “specificAction” (specificAction) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “specificAction”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field
1 import to specificAction::_LockSpecificAction
Source field 2 import to specificAction::_Number
Source field 3 import to specificAction::text
Source field 4 import to specificAction::_keyTimer
Source field 5 import to specificAction::order
Source field 6 import to specificAction::lock
Source field 7 import to specificAction::_keyGroup
Source field 8 import to specificAction::date
Source field 9 import to specificAction::dateModified
Source field 10 import to specificAction::status
Source field 11 import to specificAction::_keyStatus
Source field 12 import to specificAction::_keyDay
Source field 13 import to specificAction::_keyLogs
Source field 14 import to specificAction::timeSegmentKeyList
Source field 15 import to specificAction::SPATotalTime
Source field 18 import to specificAction::sortTime
Source field 19 import to specificAction::timeTotalSumByGroup
Source field 20 import to specificAction::oldGroupkey
Source field 21 import to specificAction::timeTotalSumByGroupSortedByStatus
Source field 24 import to specificAction::reviewDate
Source field 25 import to specificAction::weblink
Source field 27 import to specificAction::timer ]
#
Go to Layout [ “SPATime” (SPATime) ]
Show All Records
Delete All Records
[ No dialog ]
Import Records [ Source: “$filepath”; Target: “specificAction”; Method: Add; Character Set: “Unicode”; Field Mapping: Source field
1 import to specificAction::_LockSpecificAction
Source field 2 import to specificAction::_Number
Source field 3 import to specificAction::text
Source field 4 import to specificAction::_keyTimer
Source field 5 import to specificAction::order
Source field 6 import to specificAction::lock
Source field 7 import to specificAction::_keyGroup
Source field 8 import to specificAction::date
Source field 9 import to specificAction::dateModified
Source field 10 import to specificAction::status
Source field 11 import to specificAction::_keyStatus
Source field 12 import to specificAction::_keyDay
Source field 13 import to specificAction::_keyLogs
Source field 14 import to specificAction::timeSegmentKeyList
Source field 15 import to specificAction::SPATotalTime
Source field 18 import to specificAction::sortTime
Source field 19 import to specificAction::timeTotalSumByGroup
Source field 20 import to specificAction::oldGroupkey
Source field 21 import to specificAction::timeTotalSumByGroupSortedByStatus
Source field 24 import to specificAction::reviewDate
Source field 25 import to specificAction::weblink
Source field 27 import to specificAction::timer ]
#
Set Field [ backup::backup; "" ]
Close Window [ Current Window ]
Halt Script
End If
#
#3 open file and determine its location (path) and then remain open. If it opened by the restore script, then it will be closed by that
script after copying its location to it, and if it is opened by the user it will just remain open.
Set Window Title [ Current Window; New Title: "backup" ]
Go to Layout [ “backup” (backup) ]
Set Field [ backup::filepath; Get ( FilePath ) ]
Copy [ backup::filepath ]
[ Select ]
December 11, ଘ౮28 20:49:40 MyData.fp7 - open -1-
