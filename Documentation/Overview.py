
Script Name	zzzzzz print log
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Enter Browse Mode
    Go to Layout [ <unknown> ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending ] [ Restore; No dialog ]
    #Go to Preview mode for earlier versions which do not support summary reports in Browse mode.
    If [ GetAsNumber ( Substitute ( Get ( ApplicationVersion ); "."; "x" ) ) < 1000 ]
    Enter Preview Mode [ Pause ]
    Enter Browse Mode
    Go to Layout [ original layout ]
    End If

Fields used in this script	

    brainstate::description

Scripts used in this script	

Layouts used in this script	

    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [zzzzzz print log]		Next Script: [TimerPart2]
Script Name	to 31 Copy
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to time layout 31
    #
    #
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ original layout ]

Fields used in this script	

    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 31 Copy]		Next Script: [TimerRepeatAlarm]
Script Name	TimerPart2
Run script with full access privileges	On
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ reference::repeatAlarm ≠ "" ]
    Perform Script [ “TimerRepeatAlarm” ]
    Halt Script
    End If
    Insert Current Time [ reference::TimerSet ] [ Select ]
    Go to Layout [ “timerAlarm” (steward) ]
    Go to Field [ ]
    Pause/Resume Script [ Duration (seconds): 11 ]
    Go to Layout [ “timerSetAlarm” (steward) ]
    Go to Field [ ]
    Pause/Resume Script [ Duration (seconds): reference::gDuration ]
    Go to Layout [ “timerAlarm” (steward) ]
    Adjust Window [ Hide ]
    Pause/Resume Script [ Duration (seconds): 11 ]
    Go to Layout [ $$alarmLayout ]
    // Close Window [ Name: "Predict Activity Time"; Current file ]

Fields used in this script	

    reference::repeatAlarm
    reference::TimerSet
    reference::gDuration

Scripts used in this script	

    TimerRepeatAlarm

Layouts used in this script	

    timerAlarm
    timerSetAlarm

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [TimerPart2]		Next Script: [TimerPart1]
Script Name	TimerRepeatAlarm
Run script with full access privileges	On
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    TimerPart2

Script Definition
Script Steps	

    Insert Current Time [ reference::TimerSet ] [ Select ]
    Go to Layout [ “timerAlarm” (steward) ]
    Go to Field [ ]
    Pause/Resume Script [ Duration (seconds): 11 ]
    Go to Layout [ “timerSetAlarm” (steward) ]
    Go to Field [ ]
    Loop
    Pause/Resume Script [ Duration (seconds): reference::gDuration ]
    Go to Layout [ “timerAlarm” (steward) ]
    // Adjust Window [ Hide ]
    Pause/Resume Script [ Duration (seconds): 11 ]
    Go to Layout [ “timerSetAlarm” (steward) ]
    End Loop
    // Close Window [ Name: "Predict Activity Time"; Current file ]

Fields used in this script	

    reference::TimerSet
    reference::gDuration

Scripts used in this script	

Layouts used in this script	

    timerAlarm
    timerSetAlarm

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [TimerRepeatAlarm]		Next Script: [MoveToNewDayPart2]
Script Name	TimerPart1
Run script with full access privileges	On
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #basic administration tasks (required to prevent error message: record can't be modfied because it is open in another window)
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $activity; Value:brainstate::description ]
    Set Variable [ $$alarmLayout; Value:Get ( LayoutName ) ]
    // New Window [ Name: "Predict Activity Time"; Height: 420; Width: 630; Top: Get ( WindowHeight ) / 3; Left: Get ( WindowWidth ) / 3 ]
    // Show/Hide Status Area [ Lock; Hide ]
    // Show/Hide Text Ruler [ Hide ]
    Go to Layout [ “timerSetAlarm” (steward) ]
    Set Field [ reference::TimerDescription; $activity ]
    Set Field [ reference::TimerSet; "" ]
    Set Field [ reference::repeatAlarm; "" ]
    // Pause/Resume Script [ Indefinitely ]

Fields used in this script	

    brainstate::description
    reference::TimerDescription
    reference::TimerSet
    reference::repeatAlarm

Scripts used in this script	

Layouts used in this script	

    timerSetAlarm

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [TimerPart1]		Next Script: [zoom150]
Script Name	MoveToNewDayPart2
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $date; Value:reference::gDate ]
    #make sure date selected has no information in it.
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ day1::_keyDay; $date ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 1 day layouts
    #
    #
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; $date ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    Perform Script [ “sortRestoreAfterScript” ]
    Close Window [ Current Window ]

Fields used in this script	

    reference::gDate
    day1::_keyDay
    reference::day1
    steward::chosenDay

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [MoveToNewDayPart2]		Next Script: [CheckRepeatDates]
Script Name	zoom150
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Zoom Level [ 150% ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [zoom150]		Next Script: [CheckRepeatDatesMonth]
Script Name	CheckRepeatDates
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ brainstate::scheduleRepeatEventYear ≠ "" ]
    Show Custom Dialog [ Title: "pick one"; Message: "Choose to repeat item on specific weeks of the month OR every so many weeks, but not both."; Buttons: “OK” ]
    Set Field [ brainstate::scheduleRepeatEventMonth; "" ]
    Go to Field [ ]
    End If

Fields used in this script	

    brainstate::scheduleRepeatEventYear
    brainstate::scheduleRepeatEventMonth

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CheckRepeatDates]		Next Script: [MarkAllDays]
Script Name	CheckRepeatDatesMonth
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ brainstate::scheduleRepeatEventMonth ≠ "" ]
    Show Custom Dialog [ Title: "pick one"; Message: "Choose to repeat item on specific weeks of the month OR every so many weeks, but not both."; Buttons: “OK” ]
    Set Field [ brainstate::scheduleRepeatEventYear; "" ]
    Go to Field [ ]
    End If

Fields used in this script	

    brainstate::scheduleRepeatEventMonth
    brainstate::scheduleRepeatEventYear

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CheckRepeatDatesMonth]		Next Script: [FolderStopwatchCheck]
Script Name	MarkAllDays
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Field [ brainstate::schedule; "" ]
    Set Field [ brainstate::schedule; "Sunday¶Monday¶Tuesday¶Wednesday¶Thursday¶Friday¶Saturday" ]
    Go to Field [ ]

Fields used in this script	

    brainstate::schedule

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [MarkAllDays]		Next Script: [hideCheckbox]
Script Name	FolderStopwatchCheck
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    close
    note veto view
    UpdateTime

Script Definition
Script Steps	

    Go to Record/Request/Page [ First ]
    Loop
    If [ $$folderon = brainstate::_lockBrainstateID ]
    #no other stopwatch is running and one is turned on = 1 one stopwatch running
    If [ brainstate::FolderOn = "" and $$stopwatchON = "t" ]
    Set Field [ brainstate::FolderOn; "1" ]
    Set Variable [ $$stopwatchON; Value:"" ]
    Exit Script [ ]
    End If
    #x number of stopwatchs are already running and another one is turned on = x + 1 more stopwatch running
    If [ brainstate::FolderOn ≠ "" and $$stopwatchON = "t" ]
    Set Field [ brainstate::FolderOn; brainstate::FolderOn + 1 ]
    Set Variable [ $$stopwatchON; Value:"" ]
    Exit Script [ ]
    End If
    #x number of stopwatchs are already running and another one is turned off = x - 1 one less stopwatch running
    If [ brainstate::FolderOn > 1 and $$stopwatchON = "f" ]
    Set Field [ brainstate::FolderOn; brainstate::FolderOn - 1 ]
    Set Variable [ $$stopwatchON; Value:"" ]
    Exit Script [ ]
    End If
    #1 stopwatch is running and one is turned off = 0 stopwatchs running
    If [ brainstate::FolderOn = 1 and $$stopwatchON = "f" ]
    Set Field [ brainstate::FolderOn; "" ]
    Set Variable [ $$stopwatchON; Value:"" ]
    Exit Script [ ]
    End If
    End If
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    Exit Script [ ]

Fields used in this script	

    brainstate::_lockBrainstateID
    brainstate::FolderOn

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [FolderStopwatchCheck]		Next Script: [recordLoad]
Script Name	hideCheckbox
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ brainstate::groupType ≠ "" ]
    Set Field [ brainstate::hide; "t" ]
    Go to Field [ ]
    Halt Script
    End If
    Go to Field [ ]

Fields used in this script	

    brainstate::groupType
    brainstate::hide

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [hideCheckbox]		Next Script: [LoadIssuerecordID]
Script Name	recordLoad
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goToFarmer

Script Definition
Script Steps	

    If [ $$stopRecordLoad = 1 or $$otherApps = 1 ]
    Exit Script [ ]
    End If
    If [ reference::CurrentRecord = Get (RecordID) ]
    Exit Script [ ]
    End If
    Set Field [ reference::CurrentRecord; Get ( RecordID ) ]
    If [ Get ( WindowTop ) < 0 ]
    Move/Resize Window [ Current Window; Top: 0 ]
    End If

Fields used in this script	

    reference::CurrentRecord

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [recordLoad]		Next Script: [LoadLogrecordID]
Script Name	LoadIssuerecordID
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    gotoLogs
    changeLogs Copy
    newActPart2
    newActPart2cancel
    findGroupPart2
    viewLogIssues
    viewAllLogIssues
    addTimeSegmentToIssue

Script Definition
Script Steps	

    If [ $$stopRecordLoad = 1 ]
    Exit Script [ ]
    End If
    Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$group; Value:issue::_keyCategory ]
    Set Variable [ $$status; Value:issue::_keyStatus ]
    Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
    Go to Field [ ]
    #
    #If user clicked on the pulldown when the focus
    #of the system was on another record, this
    #variable prevents the pulldown menu from
    #flashing and going away. It needs to be reset
    #when the user navigates to the record other than
    #by click on the pulldown menus so the user
    #doesn't get bumped out of the menu field
    #if the database is focused on the record whose
    #menus the user is trying to access.
    Set Variable [ $$pulldownCheck; Value:Get (RecordID) ]
    #
    #disabled go to field takes a user view out of a
    #a the text field if they entered it to go to this
    #record, which I don't like as a user, so it is off.
    // Go to Field [ ]
    Set Variable [ $$stopIssuePulldownMenus; Value:1 ]
    Refresh Window
    #
    #For attaching issue record IDs to log records, and
    #for conditionally formatting log records related to an issue,
    #system needs to know what IDs are associated with a log record.
    Set Variable [ $$issue; Value:issue::_LockList ]
    Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
    Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
    Set Variable [ $$stopGroup; Value:1 ]
    Select Window [ Name: "Tag"; Current file ]
    Go to Object [ Object Name: "group" ]
    Scroll Window [ Home ]
    Go to Portal Row [ Last ]
    Loop
    Exit Loop If [ category::_LockList = $$group ]
    Go to Portal Row [ Previous; Exit after last ]
    End Loop
    If [ category::_LockList ≠ $$group ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ First ]
    End If
    Go to Field [ ]
    Set Variable [ $$stopGroup ]
    Refresh Window
    Select Window [ Name: "Day"; Current file ]
    Refresh Window
    Select Window [ Name: "Specific Action"; Current file ]
    Refresh Window

Fields used in this script	

    issue::_keyCategory
    issue::_keyStatus
    issue::_keyBrainstate
    brainstate::pulldownBrainstate
    issue::_LockList
    issue::_keyLogs
    issue::timeSegmentKeyList
    category::_LockList

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [LoadIssuerecordID]		Next Script: [CheckForChanges]
Script Name	LoadLogrecordID
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    changeLogs Copy
    clearPart2
    PHASEDOUTgotoIssueResolution

Script Definition
Script Steps	

    If [ $$stopRecordLoad = 1 ]
    Exit Script [ ]
    Else If [ $$stoprecordload ≠ 1 ]
    Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
    Refresh Window
    End If
    #
    #For attaching issue record IDs to log records, and
    #for conditionally formatting log records related to an issue,
    #system needs to know what IDs are associated with a log record.
    Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
    Set Variable [ $$log; Value:logs::_lockDay ]
    Set Field [ reference::ActivityLogDay; logs::_keyDay ]
    Select Window [ Name: "Specific Action"; Current file ]
    Go to Field [ ]
    Refresh Window
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Select Window [ Name: "Day"; Current file ]
    If [ daylog::swActivityLength[11] ≠ "" ]
    Go to Layout [ “logs3rows” (logs) ]
    Else If [ daylog::swActivityLength[6] ≠ "" ]
    Go to Layout [ “logs2rows” (logs) ]
    Else If [ daylog::swActivityLength[6] = "" ]
    Go to Layout [ “logs1row” (logs) ]
    End If
    Refresh Window
    Set Variable [ $$stopRecordLoad ]
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    // Perform Script [ “viewLogIssues” ]
    #
    #A window showing set of all issues addressed on this
    #needs to be show to the user in a new window.

Fields used in this script	

    logs::_keyLogIssues
    logs::_lockDay
    logs::_keyDay
    reference::ActivityLogDay
    daylog::swActivityLength

Scripts used in this script	

    viewLogIssues

Layouts used in this script	

    logs3rows
    logs2rows
    logs1row

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [LoadLogrecordID]		Next Script: [iphoneFitToScreen]
Script Name	CheckForChanges
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ brainstate::_lockBrainstateID = brainstate::groupID or Filter ( Get ( ApplicationVersion ) ; "go" ) = "go" ]
    Go to Field [ ]
    Halt Script
    End If
    Set Variable [ $$fieldValue; Value:Get ( ActiveFieldContents ) ]

Fields used in this script	

    brainstate::_lockBrainstateID
    brainstate::groupID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CheckForChanges]		Next Script: [updateNumberOfDaysSince]
Script Name	iphoneFitToScreen
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Zoom Level [ 150% ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [iphoneFitToScreen]		Next Script: [DaysSinceLastUseToggle]
Script Name	updateNumberOfDaysSince
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Show All Records
    Go to Record/Request/Page [ First ]
    Loop
    Perform Script [ “CHUNK_lastDayUsed” ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop

Fields used in this script	

Scripts used in this script	

    CHUNK_lastDayUsed

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [updateNumberOfDaysSince]		Next Script: [statusChangeDate]
Script Name	DaysSinceLastUseToggle
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ brainstate::DaysSinceLastUseToggle = "" ]
    Set Field [ brainstate::DaysSinceLastUseToggle; "t" ]
    Else If [ brainstate::DaysSinceLastUseToggle ≠ "" ]
    Set Field [ brainstate::DaysSinceLastUseToggle; "" ]
    End If

Fields used in this script	

    brainstate::DaysSinceLastUseToggle

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [DaysSinceLastUseToggle]		Next Script: [refreshWindow]
Script Name	statusChangeDate
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Go to Field [ issue::dateDone ]
    Set Field [ issue::dateDone; Get ( CurrentTimeStamp ) ]
    Go to Field [ ]

Fields used in this script	

    issue::dateDone

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [statusChangeDate]		Next Script: [newActPart1]
Script Name	refreshWindow
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Go to Field [ ]
    Refresh Window

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [refreshWindow]		Next Script: [newActPart2]
Script Name	newActPart1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    New Record/Request
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
    Set Field [ issue::lock; "issue" ]
    Set Field [ issue::_keyStatus; 7152011154818554 ]
    Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
    Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
    #
    #Set variable to remove background color and allow
    #message explaining assigning group to show.
    Set Variable [ $newAct; Value:issue::_LockList ]
    Refresh Window
    #
    Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Set Variable [ $$stopRecordLoad ]
    Go to Record/Request/Page [ $recordNumber ] [ No dialog ]
    #
    #Set variable to remove background color and allow
    #message explaining assigning group to show.
    Set Variable [ $newAct; Value:issue::_LockList ]
    Refresh Window
    #
    Select Window [ Name: "Tag"; Current file ]
    Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    Set Variable [ $$pick; Value:1 ]
    Refresh Window
    Pause/Resume Script [ Indefinitely ]
    #

Fields used in this script	

    issue::_keyBrainstate
    issue::date
    issue::lock
    issue::_keyStatus
    brainstate::pulldownBrainstate
    issue::_LockList

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservationsTag

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newActPart1]		Next Script: [newActPart2cancel]
Script Name	newActPart2
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    TsubtotalTimeByGroup

Script Definition
Script Steps	

    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    #
    #Make key to fit this group's lock.
    Set Variable [ $$group; Value:category::_LockList ]
    Set Variable [ $$pick ]
    Go to Field [ ]
    // Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
    // Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    Refresh Window
    #
    #Give key to current specific action.
    Select Window [ Name: "Specific Action"; Current file ]
    Set Field [ issue::_keyCategory; $$group ]
    Set Field [ issue::oldCategorykey; $$group ]
    #
    #These two keys are essential for the subtotal to work.
    Set Variable [ $$status; Value:issue::_keyStatus ]
    Set Field [ issue::sortTime; issueCategory::text ]
    #
    // #If user selected the same category that was already
    // #selected then stop this script.
    // If [ issue::_keyCategory = issue::oldCategorykey and $$stopSubtotal = "" ]
    // Go to Field [ ]
    // Exit Script [ ]
    // End If
    #
    Sort Records [ ] [ No dialog ]
    Refresh Window
    Perform Script [ “LoadIssuerecordID” ]
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Go to Record/Request/Page [ Next ]
    Set Variable [ $$stopRecordLoad ]
    Go to Record/Request/Page [ $recordNumber ] [ No dialog ]
    Go to Field [ issue::text ]

Fields used in this script	

    category::_LockList
    issue::_keyCategory
    issue::oldCategorykey
    issue::_keyStatus
    issueCategory::text
    issue::sortTime
    issue::text

Scripts used in this script	

    LoadIssuerecordID

Layouts used in this script	

    IssuesAndObservationsTag

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newActPart2]		Next Script: [newItem]
Script Name	newActPart2cancel
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    #
    #Stop script if user is NOT in the process of picking a specific action group.
    If [ $$pick ≠ 1 ]
    Exit Script [ ]
    End If
    #
    #
    #If user cancels and decides not create a new action...
    Set Variable [ $$pick ]
    Go to Field [ ]
    // Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
    // Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    Refresh Window
    #
    #Give key to current specific action.
    Select Window [ Name: "Specific Action"; Current file ]
    Delete Record/Request [ No dialog ]
    #
    Sort Records [ ] [ No dialog ]
    Refresh Window
    Perform Script [ “LoadIssuerecordID” ]

Fields used in this script	

Scripts used in this script	

    LoadIssuerecordID

Layouts used in this script	

    IssuesAndObservationsTag

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newActPart2cancel]		Next Script: [newPrefix]
Script Name	newItem
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Go to Layout [ “IssuesAndObservations Copy” (issue) ]
    New Record/Request
    Set Field [ issue::lock; "status" ]
    Go to Layout [ original layout ]
    Go to Field [ status::text ]

Fields used in this script	

    issue::lock
    status::text

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservations Copy

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newItem]		Next Script: [newIssueGroup]
Script Name	newPrefix
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Go to Layout [ <unknown> ]
    New Record/Request
    Set Field [ issue::lock; "prefix" ]
    Go to Layout [ original layout ]
    Go to Field [ prefix::text ]

Fields used in this script	

    issue::lock
    prefix::text

Scripts used in this script	

Layouts used in this script	

    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newPrefix]		Next Script: [issueCancelNewIssueScript]
Script Name	newIssueGroup
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    Set Variable [ $brainstate; Value:brainstate::_lockBrainstateID ]
    #
    Go to Layout [ “IssuesAndObservations Copy” (issue) ]
    #
    New Record/Request
    Set Field [ issue::lock; "location" ]
    Set Field [ issue::_keyBrainstate; $brainstate ]
    #
    Set Variable [ $group; Value:issue::_LockList ]
    #
    Go to Layout [ original layout ]
    #
    Go to Object [ Object Name: "group" ]
    #
    Go to Portal Row [ First ]
    Loop
    Exit Loop If [ $group = category::_LockList ]
    Go to Portal Row [ Select; Next ]
    End Loop
    #
    Go to Field [ category::text ]

Fields used in this script	

    brainstate::_lockBrainstateID
    issue::lock
    issue::_keyBrainstate
    issue::_LockList
    category::_LockList
    category::text

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservations Copy

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newIssueGroup]		Next Script: [uniqueCateogryNameRequired]
Script Name	issueCancelNewIssueScript
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    // Halt Script

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [issueCancelNewIssueScript]		Next Script: [uniqueStatusNameRequired]
Script Name	uniqueCateogryNameRequired
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    #Capture text, remove spaces, and then recapture
    #the text to prevent user from creating a group
    #with spaces that would put it above the 10 space
    #group assigned to new issues to keep new issues
    #sorted to the top of the list of issues in the isssues
    #log window.
    Set Variable [ $name; Value:category::text ]
    Set Field [ category::text; Trim ( $name ) ]
    Set Variable [ $name; Value:category::text ]
    Set Variable [ $portalRow; Value:Get ( PortalRowNumber ) ]
    #
    #Make a key to later in script loop
    #to the correct portal row.
    Set Variable [ $key; Value:category::_LockList ]
    #
    #If the user left the field blank...
    If [ category::text = "" ]
    Show Custom Dialog [ Message: "All group names must be unique, and must not be blank."; Buttons: “OK” ]
    #
    #Go to the blank field and fill it in with a unique
    #number.
    Go to Object [ Object Name: "group" ]
    #
    Go to Portal Row [ Select; First ]
    Loop
    Exit Loop If [ $key = category::_LockList ]
    Go to Portal Row [ Select; Next ]
    End Loop
    Set Field [ category::text; $key & Random ]
    Exit Script [ ]
    End If
    #
    #Determine if user used a spelling already in use.
    Go to Portal Row [ Select; First ]
    #
    Loop
    #If the user used a spelling alread in use ...
    If [ $name =category::text and category::_LockList ≠ $key ]
    Show Custom Dialog [ Message: "Each category in this list must have a unique name."; Buttons: “OK” ]
    #
    #Go to the blank field and fill it in with a unique
    #number.
    Go to Object [ Object Name: "group" ]
    #
    Go to Portal Row [ Select; First ]
    Loop
    Exit Loop If [ $key = category::_LockList ]
    Go to Portal Row [ Select; Next ]
    End Loop
    Set Field [ category::text; category::text & " " & $key ]
    Exit Script [ ]
    End If
    Go to Portal Row [ Select; Next; Exit after last ]
    End Loop
    #
    Scroll Window [ Home ]
    #Go to current record.
    Go to Object [ Object Name: "group" ]
    Go to Portal Row [ Select; First ]
    Loop
    #
    Exit Loop If [ $key = category::_LockList ]
    Go to Portal Row [ Select; Next; Exit after last ]
    End Loop

Fields used in this script	

    category::text
    category::_LockList

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [uniqueCateogryNameRequired]		Next Script: [TsubtotalTimeByGroup]
Script Name	uniqueStatusNameRequired
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    #Capture text, remove spaces, and then recapture
    #the text to prevent user from creating a group
    #with spaces that would put it above the 10 space
    #status assigned to new issues to keep new issues
    #sorted to the top of the list of issues in the isssues
    #log window.
    Set Variable [ $name; Value:status::text ]
    Set Field [ status::text; Trim ( $name ) ]
    Set Variable [ $name; Value:status::text ]
    #
    #Make a key to later in script loop
    #to the correct portal row.
    Set Variable [ $key; Value:status::_LockList ]
    #
    #If the user left the field blank...
    If [ status::text = "" ]
    Show Custom Dialog [ Message: "All status names must be unique, and must not be blank."; Buttons: “OK” ]
    #
    #Go to the blank field and fill it in with a unique
    #number.
    Go to Object [ Object Name: "status" ]
    #
    Go to Portal Row [ Select; First ]
    Loop
    Exit Loop If [ $key = status::_LockList ]
    Go to Portal Row [ Select; Next ]
    End Loop
    Set Field [ status::text; $key & Random ]
    Exit Script [ ]
    End If
    #
    #Determine if user used a spelling already in use.
    Go to Portal Row [ Select; First ]
    #
    Loop
    #If the user used a spelling alread in use ...
    If [ $name =status::text and status::_LockList ≠ $key ]
    Show Custom Dialog [ Message: "Each status in this list must have a unique name."; Buttons: “OK” ]
    #
    #Go to the blank field and fill it in with a unique
    #number.
    Go to Object [ Object Name: "status" ]
    #
    Go to Portal Row [ Select; First ]
    Loop
    Exit Loop If [ $key = status::_LockList ]
    Go to Portal Row [ Select; Next ]
    End Loop
    Set Field [ status::text; $key & Random ]
    Exit Script [ ]
    End If
    Go to Portal Row [ Select; Next; Exit after last ]
    End Loop
    #

Fields used in this script	

    status::text
    status::_LockList

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [uniqueStatusNameRequired]		Next Script: [TsubtotalTimeByGroupForStatus]
Script Name	TsubtotalTimeByGroup
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    openSpecificAction
    gotoLogs
    changeLogs Copy
    issueSortStatus
    TsubtotalTimeByGroupForStatus
    viewLogIssues

Script Definition
Script Steps	

    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    #
    #
    If [ $$pick = 1 ]
    Perform Script [ “newActPart2” ]
    Exit Script [ ]
    End If
    #
    If [ Get (WindowName) = "Tag" ]
    #Make key to fit this group's lock.
    Set Variable [ $$group; Value:category::_LockList ]
    Go to Field [ ]
    Refresh Window
    #
    #Give key to current specific action.
    Select Window [ Name: "Specific Action"; Current file ]
    Set Field [ issue::_keyCategory; $$group ]
    #
    #This field is for sorting the records by category
    #to get the subtotal of each categories time.
    # (The subtotal calculation depends on this "break"
    # field to know which set of records should be
    # treated as a subset of the total records shown.)
    #This sort must be done on a field in the table
    #where the time is located: list table.
    #The system is using the text field from the list
    #table for the text of each issue. Another occurance
    #of the list table is used to supply the categories
    #which are located in a different list table record.
    #This allows the system to use the list table for
    #Text and for tags: category and issue tags.
    #However, in order to sort on the text of the
    #category a copy of the text must be made
    #part of each list record shown as an issue
    # (instead of being shown as a category or status)
    #This next field holds the copy of the cateogry
    #tag text for each list record holding issue data.
    Set Field [ issue::sortTime; issueCategory::text ]
    If [ $$stopSort ≠ "" ]
    #
    #Set make the old and current category keys
    #identical, so system will will be able to update
    #the time in this issue records current category
    #if the user decided to reassign it to a different
    #category.
    Set Field [ issue::oldCategorykey; issue::_keyCategory ]
    Exit Script [ ]
    End If
    End If
    #
    #If user selected the same category that was already
    #selected then stop this script.
    If [ issue::_keyCategory = issue::oldCategorykey and $$stopSubtotal = "" ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    Set Variable [ $$stopSubtotal ]
    #
    #Set the old category key variable for use later
    #in this script finding all the issue records that
    #still belong to this record's former category.
    Set Variable [ $OLDcategoryKey; Value:issue::oldCategorykey ]
    #
    #Prevent windows from flashing and script from slowing
    #by stopping strobe effect caused by going back and
    #forth from each window upon loading each records
    #information throughout the script, rather than just
    #at the end.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    Go to Field [ ]
    #
    #This field is for sorting the records by category
    #to get the subtotal of each categories time.
    # (The subtotal calculation depends on this "break"
    # field to know which set of records should be
    # treated as a subset of the total records shown.)
    #This sort must be done on a field in the table
    #where the time is located: list table.
    #The system is using the text field from the list
    #table for the text of each issue. Another occurance
    #of the list table is used to supply the categories
    #which are located in a different list table record.
    #This allows the system to use the list table for
    #Text and for tags: category and issue tags.
    #However, in order to sort on the text of the
    #category a copy of the text must be made
    #part of each list record shown as an issue
    # (instead of being shown as a category or status)
    #This next field holds the copy of the cateogry
    #tag text for each list record holding issue data.
    Set Field [ issue::sortTime; issueCategory::text ]
    #
    #In the focus in the text field, remove it.
    Go to Field [ ]
    #
    #Open a new window so these next steps can
    #be done without disturbing the current view
    #and scroll position of the issue window.
    New Window [ Name: "temp" ]
    #
    #This duplicate layout has no script triggers or conditional
    #formatting and so speeds up the script steps.
    Go to Layout [ “IssuesLayoutForScripts” (issue) ]
    #
    #Add up total time for category the issue is now in.
    #
    #First find all the issues in this category.
    Set Variable [ $categoryKey; Value:issue::_keyCategory ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $categoryKey ]
    Perform Find [ ]
    #
    #Sort them to trigger the calcuation of their
    #total time.
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    #Go to each record including the newly recatorgized
    # and update thier total cateogry time.
    #
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #
    #
    #Add up total time for category it was in.
    #
    #First find all the issues still part of the category
    #it was in, if any.
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $OLDcategoryKey ]
    Perform Find [ ]
    #
    #If records remain in this category then continue
    #reassigning updated total time to member records.
    If [ Get (LastError) ≠ 401 ]
    #
    #Sort them to trigger the calcuation of their
    #total time.
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    #
    #Go to each record including the newly recatorgized
    # and update thier total cateogry time.
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    End If
    #
    #
    #
    #Disabled the next chunk after deciding it was
    #better to use filemaker's subtotal calc rather
    #doing it with this script chunk whose benefit
    #was subtotaling items in a category even when
    #items where divided by status. Filemaker's
    #subtotal calc subtotals at the status and category
    #breaks (essentially all breaks caused by a sort)
    #but I decided to show issue the time by status
    #and category too, so that is why this script chunk
    #is now disabled. The other reason was that it
    #bogged down the system taking a long time to run.
    // #To reset all the category subtotal times, first find
    // #and sort all this issues records.
    // Set Variable [ $brainstateIssues; Value:issue::_keyBrainstate ]
    // Enter Find Mode [ ]
    // Set Field [ issue::_keyBrainstate; $brainstateIssues ]
    // Perform Find [ ]
    // Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issue::timeTotalSummaryByCategory; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    // Go to Record/Request/Page [ First ]
    // #
    // #
    // #AddUp total time showing for this subset of
    // #a cateogory broken up into subsets by different
    // #statuses, like the subset of some category's
    // #record that are pending, or completed, etc.
    // Loop
    // Set Variable [ $category; Value:issue::_keyCategory ]
    // Set Variable [ $status; Value:issue::_keyStatus ]
    // Set Variable [ $recordNumber; Value:Get (RecordNumber) ]
    // Set Variable [ $subsetTotal ]
    // Set Variable [ $oldTotal ]
    // #
    // Loop
    // Set Variable [ $subsetTotal; Value:issue::issueTotalTime + $oldTotal ]
    // Set Variable [ $oldTotal; Value:$subsetTotal ]
    // Go to Record/Request/Page [ Next; Exit after last ]
    // Exit Loop If [ issue::_keyCategory ≠ $category //This next step I thought could happen, but then realized it can nevery happen //or //issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
    // End Loop
    // #
    // #Return the first record in this subset and give it
    // #the subset total, then give the subtotal to all
    // #records in this subset.
    // Go to Record/Request/Page [ $recordNumber ] [ No dialog ]
    // #
    // Loop
    // Set Field [ issue::timeTotalSumByCatSortedByStatus; $subsetTotal ]
    // Go to Record/Request/Page [ Next; Exit after last ]
    // Exit Loop If [ issue::_keyCategory ≠ $category //This next step I thought could happen, but then realized it can nevery happen //or //issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
    // End Loop
    // #
    // Exit Loop If [ Get (LastError) = 101 ]
    // End Loop
    #
    #
    Close Window [ Name: "temp"; Current file ]
    #
    #
    #Set make the old and current category keys
    #identical, so system will will be able to update
    #the time in this issue records current category
    #if the user decided to reassign it to a different
    #category.
    Set Field [ issue::oldCategorykey; issue::_keyCategory ]
    #
    #In order to show the newly updapted time the
    #system must resort the records. This takes
    Set Variable [ $currentRecord; Value:issue::_LockList ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issue::timeTotalSummaryByCategory; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    #
    #In order to show the newly updapted time the
    #The previous script step takes the
    #the focus to the last record. To get the
    #to the current record, and to show it not as
    #as the top record, but if possible show
    #all records above it, requires two sorts, and
    #two scrolls. For some reason Filemaker will not
    #scroll home (the top record) and then scroll
    #down to the current record without a sort being
    #between the sort steps.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ issue::_LockList = $currentRecord ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    Scroll Window [ Home ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::sortTime; ascending issue::order; based on value list: “1-99” issue::text; ascending ] [ Restore; No dialog ]
    #
    Scroll Window [ To Selection ]
    Set Variable [ $$stopRecordLoad ]
    #
    // #The halt script is neccessary in case the user
    // #clicks somewhere other than the in the pulldown
    // #menu. This halt script stops the pause script
    // #that is currently in play.
    // Halt Script

Fields used in this script	

    category::_LockList
    issue::_keyCategory
    issueCategory::text
    issue::sortTime
    issue::oldCategorykey
    issue::timeTotalSummaryByCategory
    issue::timeTotalSumByCat
    issue::_keyBrainstate
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issue::order
    issue::text
    issue::_keyStatus
    issue::issueTotalTime
    issue::timeTotalSumByCatSortedByStatus
    issue::_LockList

Scripts used in this script	

    newActPart2

Layouts used in this script	

    IssuesLayoutForScripts

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [TsubtotalTimeByGroup]		Next Script: [findGroupPart2]
Script Name	TsubtotalTimeByGroupForStatus
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    #
    #Stop script if user is process of picking a specific action group.
    If [ $$pick = 1 ]
    Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can assign other tags. "; Buttons: “OK” ]
    Exit Script [ ]
    End If
    #
    If [ Get (WindowName) = "Tag" ]
    #Make key to fit this group's lock.
    Set Variable [ $$status; Value:status::_LockList ]
    Go to Field [ ]
    Refresh Window
    #
    #Give key to current specific action.
    Select Window [ Name: "Specific Action"; Current file ]
    Set Field [ issue::_keyStatus; $$status ]
    End If
    #
    // Perform Script [ “issueSortStatus” ]
    Perform Script [ “Tstatus” ]
    Perform Script [ “TsubtotalTimeByGroup” ]

Fields used in this script	

    status::_LockList
    issue::_keyStatus

Scripts used in this script	

    issueSortStatus
    Tstatus
    TsubtotalTimeByGroup

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [TsubtotalTimeByGroupForStatus]		Next Script: [findGroupPart1]
Script Name	findGroupPart2
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    #
    #Make key to fit this group's lock.
    Set Variable [ $$group; Value:category::_LockList ]
    Go to Field [ ]
    If [ FilterValues ( $$found ; $$group ) = $$group & ¶ ]
    #
    #Find all specific actions with this key.
    Select Window [ Name: "Specific Action"; Current file ]
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Go to Record/Request/Page [ First ]
    Loop
    If [ issue::_keyCategory = $$group ]
    Omit Record
    Else
    Go to Record/Request/Page [ Next; Exit after last ]
    End If
    End Loop
    Set Variable [ $$found; Value:Substitute ( $$found ; $$group & ¶ ; "" ) ]
    Set Variable [ $$stopRecordLoad ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::order; based on value list: “1-99” issue::text; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Else
    #
    #Find all specific actions with this key.
    Select Window [ Name: "Specific Action"; Current file ]
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $$group ]
    Extend Found Set [ ]
    If [ Get (LastError) ≠ 401 ]
    Set Variable [ $$found; Value:$$group & ¶ & $$found ]
    Else
    Show Custom Dialog [ Message: "There are no specific actions tagged as part of this group."; Buttons: “OK” ]
    End If
    Set Variable [ $$stopRecordLoad ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::order; based on value list: “1-99” issue::text; ascending ] [ Restore; No dialog ]
    End If
    Perform Script [ “LoadIssuerecordID” ]
    #
    #If user selected the same category that was already
    #selected then stop this script.
    Select Window [ Name: "Tag"; Current file ]
    Refresh Window
    #
    // #Find all specific actions with this key.
    // Select Window [ Name: "Specific Action"; Current file ]

Fields used in this script	

    category::_LockList
    issue::_keyCategory
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issue::sortTime
    issue::order
    issue::text

Scripts used in this script	

    LoadIssuerecordID

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [findGroupPart2]		Next Script: [TsubtotalTimeByOrder]
Script Name	findGroupPart1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    #
    #Stop script if user is process of picking a specific action group.
    If [ $$pick = 1 ]
    Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can find specific act records by group."; Buttons: “OK” ]
    Exit Script [ ]
    End If
    #
    #Find all specific actions with this key.
    Go to Layout [ “IssuesAndObservationsFIND” (brainstate) ]
    Scroll Window [ Home ]
    Set Variable [ $$found ]
    #
    #Find all specific actions with this key.
    Select Window [ Name: "Specific Action"; Current file ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; "nothing" ]
    Perform Find [ ]
    #
    #If user selected the same category that was already
    #selected then stop this script.
    Select Window [ Name: "Tag"; Current file ]
    Go to Layout [ “IssuesAndObservationsFIND” (brainstate) ]
    Scroll Window [ Home ]
    #

Fields used in this script	

    issue::_keyCategory

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservationsFIND

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [findGroupPart1]		Next Script: [gotoFieldItemPart3a]
Script Name	TsubtotalTimeByOrder
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    issueSortOrderNumber

Script Definition
Script Steps	

    #
    #If user selected the same category that was already
    #selected then stop this script.
    If [ issue::_keyCategory = issue::oldCategorykey and $$stopSubtotal = "" ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    Set Variable [ $$stopSubtotal ]
    #
    #Set the old category key variable for use later
    #in this script finding all the issue records that
    #still belong to this record's former category.
    Set Variable [ $OLDcategoryKey; Value:issue::oldCategorykey ]
    #
    #Prevent windows from flashing and script from slowing
    #by stopping strobe effect caused by going back and
    #forth from each window upon loading each records
    #information throughout the script, rather than just
    #at the end.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    Go to Field [ ]
    #
    #This field is for sorting the records by category
    #to get the subtotal of each categories time.
    # (The subtotal calculation depends on this "break"
    # field to know which set of records should be
    # treated as a subset of the total records shown.)
    #This sort must be done on a field in the table
    #where the time is located: list table.
    #The system is using the text field from the list
    #table for the text of each issue. Another occurance
    #of the list table is used to supply the categories
    #which are located in a different list table record.
    #This allows the system to use the list table for
    #Text and for tags: category and issue tags.
    #However, in order to sort on the text of the
    #category a copy of the text must be made
    #part of each list record shown as an issue
    # (instead of being shown as a category or status)
    #This next field holds the copy of the cateogry
    #tag text for each list record holding issue data.
    Set Field [ issue::sortTime; issueCategory::text ]
    #
    #In the focus in the text field, remove it.
    Go to Field [ ]
    #
    #Open a new window so these next steps can
    #be done without disturbing the current view
    #and scroll position of the issue window.
    New Window [ Name: "temp" ]
    #
    #This duplicate layout has no script triggers or conditional
    #formatting and so speeds up the script steps.
    Go to Layout [ “IssuesLayoutForScripts” (issue) ]
    #
    #Add up total time for category the issue is now in.
    #
    #First find all the issues in this category.
    Set Variable [ $categoryKey; Value:issue::_keyCategory ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $categoryKey ]
    Perform Find [ ]
    #
    #Sort them to trigger the calcuation of their
    #total time.
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    #Go to each record including the newly recatorgized
    # and update thier total cateogry time.
    #
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #
    #
    #Add up total time for category it was in.
    #
    #First find all the issues still part of the category
    #it was in, if any.
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $OLDcategoryKey ]
    Perform Find [ ]
    #
    #If records remain in this category then continue
    #reassigning updated total time to member records.
    If [ Get (LastError) ≠ 401 ]
    #
    #Sort them to trigger the calcuation of their
    #total time.
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    #
    #Go to each record including the newly recatorgized
    # and update thier total cateogry time.
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    End If
    #
    #
    #
    #Disabled the next chunk after deciding it was
    #better to use filemaker's subtotal calc rather
    #doing it with this script chunk whose benefit
    #was subtotaling items in a category even when
    #items where divided by status. Filemaker's
    #subtotal calc subtotals at the status and category
    #breaks (essentially all breaks caused by a sort)
    #but I decided to show issue the time by status
    #and category too, so that is why this script chunk
    #is now disabled. The other reason was that it
    #bogged down the system taking a long time to run.
    // #To reset all the category subtotal times, first find
    // #and sort all this issues records.
    // Set Variable [ $brainstateIssues; Value:issue::_keyBrainstate ]
    // Enter Find Mode [ ]
    // Set Field [ issue::_keyBrainstate; $brainstateIssues ]
    // Perform Find [ ]
    // Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issue::timeTotalSummaryByCategory; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    // Go to Record/Request/Page [ First ]
    // #
    // #
    // #AddUp total time showing for this subset of
    // #a cateogory broken up into subsets by different
    // #statuses, like the subset of some category's
    // #record that are pending, or completed, etc.
    // Loop
    // Set Variable [ $category; Value:issue::_keyCategory ]
    // Set Variable [ $status; Value:issue::_keyStatus ]
    // Set Variable [ $recordNumber; Value:Get (RecordNumber) ]
    // Set Variable [ $subsetTotal ]
    // Set Variable [ $oldTotal ]
    // #
    // Loop
    // Set Variable [ $subsetTotal; Value:issue::issueTotalTime + $oldTotal ]
    // Set Variable [ $oldTotal; Value:$subsetTotal ]
    // Go to Record/Request/Page [ Next; Exit after last ]
    // Exit Loop If [ issue::_keyCategory ≠ $category //This next step I thought could happen, but then realized it can nevery happen //or //issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
    // End Loop
    // #
    // #Return the first record in this subset and give it
    // #the subset total, then give the subtotal to all
    // #records in this subset.
    // Go to Record/Request/Page [ $recordNumber ] [ No dialog ]
    // #
    // Loop
    // Set Field [ issue::timeTotalSumByCatSortedByStatus; $subsetTotal ]
    // Go to Record/Request/Page [ Next; Exit after last ]
    // Exit Loop If [ issue::_keyCategory ≠ $category //This next step I thought could happen, but then realized it can nevery happen //or //issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
    // End Loop
    // #
    // Exit Loop If [ Get (LastError) = 101 ]
    // End Loop
    #
    #
    Close Window [ Name: "temp"; Current file ]
    #
    #
    #Set make the old and current category keys
    #identical, so system will will be able to update
    #the time in this issue records current category
    #if the user decided to reassign it to a different
    #category.
    Set Field [ issue::oldCategorykey; issue::_keyCategory ]
    #
    #In order to show the newly updapted time the
    #system must resort the records. This takes
    Set Variable [ $currentRecord; Value:issue::_LockList ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issue::order; based on value list: “__-99” issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issue::timeTotalSummaryByCategory; ascending issue::text; ascending ] [ Restore; No dialog ]
    // Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    #
    #In order to show the newly updapted time the
    #The previous script step takes the
    #the focus to the last record. To get the
    #to the current record, and to show it not as
    #as the top record, but if possible show
    #all records above it, requires two sorts, and
    #two scrolls. For some reason Filemaker will not
    #scroll home (the top record) and then scroll
    #down to the current record without a sort being
    #between the sort steps.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ issue::_LockList = $currentRecord ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    Scroll Window [ Home ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issue::order; based on value list: “1-99” issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::text; ascending ] [ Restore; No dialog ]
    // Sort Records [ ] [ No dialog ]
    Scroll Window [ To Selection ]
    // Refresh Window
    Set Variable [ $$stopRecordLoad ]
    #
    // #The halt script is neccessary in case the user
    // #clicks somewhere other than the in the pulldown
    // #menu. This halt script stops the pause script
    // #that is currently in play.
    // Halt Script

Fields used in this script	

    issue::_keyCategory
    issue::oldCategorykey
    issueCategory::text
    issue::sortTime
    issue::timeTotalSummaryByCategory
    issue::timeTotalSumByCat
    issue::_keyBrainstate
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issue::order
    issue::text
    issue::_keyStatus
    issue::issueTotalTime
    issue::timeTotalSumByCatSortedByStatus
    issue::_LockList

Scripts used in this script	

Layouts used in this script	

    IssuesLayoutForScripts

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [TsubtotalTimeByOrder]		Next Script: [Tstatus]
Script Name	gotoFieldItemPart3a
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    #If user clicked on the pulldown when the focus
    #of the system was on another record, stop this
    #script so user wont' get a useless flash of the menu.
    If [ $$pulldownCheck ≠ Get (RecordID) ]
    Set Variable [ $$pulldownCheck; Value:Get (RecordID) ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    Go to Object [ Object Name: 2 ]
    // Go to Field [ issue::_keyCategory ] [ Select/perform ]

Fields used in this script	

    issue::_keyCategory

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoFieldItemPart3a]		Next Script: [gotoIssueOrder]
Script Name	Tstatus
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    TsubtotalTimeByGroupForStatus

Script Definition
Script Steps	

    If [ issueStatus::order > 79 ]
    Set Variable [ $$stopgotoIssueResolution; Value:1 ]
    Set Field [ issue::order; "" ]
    End If
    Go to Field [ ]
    If [ issue::_keyCategory ≠ "" ]
    Go to Field [ issue::dateDone ]
    Set Field [ issue::dateDone; Get ( CurrentTimeStamp ) ]
    Go to Field [ ]
    End If
    Set Variable [ $$stopgotoIssueResolution ]
    #
    #if over 90, do not take user to record when status is changed.
    If [ issueStatus::order > 79 or $$stopSort ≠ "" ]
    Halt Script
    End If
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::order; based on value list: “1-99” issue::text; ascending ] [ Restore; No dialog ]
    Scroll Window [ To Selection ]

Fields used in this script	

    issueStatus::order
    issue::order
    issue::_keyCategory
    issue::dateDone
    brainstate::description
    issueStatus::text
    issueCategory::order
    issue::sortTime
    issue::text

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [Tstatus]		Next Script: [gotoIssues]
Script Name	gotoIssueOrder
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    #If user clicked on the pulldown when the focus
    #of the system was on another record, stop this
    #script so user wont' get a useless flash of the menu.
    If [ $$pulldownCheck ≠ Get (RecordID) ]
    Set Variable [ $$pulldownCheck; Value:Get (RecordID) ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    Go to Object [ Object Name: "order" ]
    // Go to Field [ issue::order ] [ Select/perform ]

Fields used in this script	

    issue::order

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoIssueOrder]		Next Script: [keepblankstatusrecord]
Script Name	gotoIssues
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $brainstate; Value:brainstate::_lockBrainstateID ]
    New Window [ ]
    Go to Layout [ “Issues” (issue) ]
    Sort Records [ Specified Sort Order: issue::_keyBrainstate; ascending issue::_keyStatus; ascending issueCategory::text; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $brainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ issue::_keyBrainstate; $brainstate ]
    Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
    Set Field [ issue::lock; "issue" ]
    Set Field [ issue::text; "issue" ]
    Go to Field [ ]
    Go to Field [ issue::text ]
    End If

Fields used in this script	

    brainstate::_lockBrainstateID
    issue::_keyBrainstate
    issue::_keyStatus
    issueCategory::text
    issue::order
    issue::text
    issue::lock
    issue::date

Scripts used in this script	

Layouts used in this script	

    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoIssues]		Next Script: [keepBlankGroupRecord]
Script Name	keepblankstatusrecord
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ status::_LockList = 6302011014838316 ]
    Go to Field [ ]
    Show Custom Dialog [ Message: "This first record must remain blank, so that new issues are always sorted to the top in the Issues Log window."; Buttons: “OK” ]
    End If

Fields used in this script	

    status::_LockList

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [keepblankstatusrecord]		Next Script: [deleteObservation]
Script Name	keepBlankGroupRecord
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ $$stopGroup ≠ "" ]
    Exit Script [ ]
    End If
    If [ category::text = " " ]
    Go to Field [ ]
    Show Custom Dialog [ Message: "This first record must remain blank, so that new issues are always sorted to the top in the Issues Log window."; Buttons: “OK” ]
    End If

Fields used in this script	

    category::text

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [keepBlankGroupRecord]		Next Script: [deleteIssue]
Script Name	deleteObservation
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $row; Value:Get ( PortalRowNumber ) ]
    Go to Field [ ]
    Go to Portal Row [ $row ] [ Select; No dialog ]
    Set Variable [ $delete; Value:observation::_LockList ]
    Set Variable [ $name; Value:observation::text ]
    Refresh Window
    Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
    If [ Get ( LastMessageChoice ) = 2 ]
    Delete Portal Row [ No dialog ]
    End If
    Set Variable [ $delete ]
    Go to Field [ ]
    Refresh Window

Fields used in this script	

    observation::_LockList
    observation::text

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [deleteObservation]		Next Script: [deletePrefix]
Script Name	deleteIssue
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $delete; Value:issue::_LockList ]
    Set Variable [ $$stopCategoryRequest; Value:1 ]
    Set Variable [ $name; Value:issue::text ]
    Go to Object [ Object Name: 5 ]
    Refresh Window
    Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
    #
    If [ Get ( LastMessageChoice ) = 2 ]
    #
    If [ issue::issueTotalTime ≠ "" ]
    #
    #Prevent windows from flashing and script from slowing
    #by stopping strobe effect caused by going back and
    #forth from each window upon loading each records
    #information throughout the script, rather than just
    #at the end.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    New Window [ Name: "temp" ]
    #
    #Exit issue field so conditional formatting can be applied.
    Go to Field [ ]
    #
    #Prepare to remove issue time for category.
    Set Variable [ $categoryKey; Value:issue::_keyCategory ]
    Set Field [ issue::issueTotalTime; "" ]
    #
    #Eliminate this issue's time from the all the time
    #assigned to its category.
    Go to Layout [ “issueTime” (issueTime) ]
    Enter Find Mode [ ]
    Set Field [ issueTime::_keyIssue; $$issue ]
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    Perform Find [ ]
    Delete All Records [ No dialog ]
    #
    #Add up total time for category it was in.
    Go to Layout [ “Issues” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $categoryKey ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #Find all day records linked to this issue.
    Go to Layout [ “logs2rows” (logs) ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyLogIssues; $$issue ]
    Perform Find [ ]
    Go to Record/Request/Page [ First ]
    Loop
    #
    #Remove issue key from an activity log (day) records.
    Set Variable [ $logIssues; Value:logs::_keyLogIssues ]
    Set Field [ logs::_keyLogIssues; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not removed, then the removal calc without the paragraph mark is used. If ( ValueCount ( $logIssues ) ≠ ValueCount ( Substitute ( $logIssues ; $$issue & "¶" ; "" ) ) ; Substitute ( $logIssues ; $$issue & "¶" ; "" ) ; Substitute ( $logIssues ; $$issue ; "" ) ) ]
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
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    Set Variable [ $$stopRecordLoad ]
    #
    Close Window [ Name: "temp"; Current file ]
    End If
    #
    Delete Record/Request [ No dialog ]
    End If
    #
    Set Variable [ $delete ]
    Set Variable [ $$stopCategoryRequest ]
    Select Window [ Name: "Specific Action"; Current file ]
    Go to Field [ issue::text ]
    Go to Field [ ]
    Refresh Window
    #

Fields used in this script	

    issue::_LockList
    issue::text
    issue::issueTotalTime
    issue::_keyCategory
    issueTime::_keyIssue
    issue::sortTime
    issue::timeTotalSummaryByCategory
    issue::timeTotalSumByCat
    logs::_keyLogIssues
    logs::swLogTimeAccounting

Scripts used in this script	

Layouts used in this script	

    issueTime
    Issues
    logs2rows

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [deleteIssue]		Next Script: [deleteStatus]
Script Name	deletePrefix
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $delete; Value:prefix::_LockList ]
    Set Variable [ $name; Value:prefix::text ]
    Go to Object [ Object Name: 5 ]
    Refresh Window
    Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
    If [ Get ( LastMessageChoice ) = 2 ]
    Delete Record/Request [ No dialog ]
    End If
    Set Variable [ $delete ]
    Go to Field [ ]
    Refresh Window

Fields used in this script	

    prefix::_LockList
    prefix::text

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [deletePrefix]		Next Script: [deleteGroup]
Script Name	deleteStatus
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $row; Value:Get ( PortalRowNumber ) ]
    If [ status::_LockList = "" ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    If [ Get (ActiveFieldContents) = "" ]
    Show Custom Dialog [ Title: "!"; Message: "Select an item to delete."; Buttons: “OK” ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    Set Variable [ $delete; Value:status::_LockList ]
    Set Variable [ $name; Value:status::text ]
    Go to Layout [ “IssuesAndObservations Copy” (issue) ]
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyStatus; $delete ]
    Perform Find [ ]
    Set Variable [ $error; Value:Get (LastError) ]
    Go to Layout [ original layout ]
    If [ $error ≠ 401 ]
    Set Variable [ $delete ]
    Show Custom Dialog [ Message: "'" & $name & "'" & " can be deleted once all issues tagged with it are switched to a different status tag in the issues log window. NOTE: Status tags are global, so this tag may be applied to other action's issues not currently showing."; Buttons: “OK” ]
    Exit Script [ ]
    End If
    Refresh Window
    Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
    If [ Get ( LastMessageChoice ) = 2 ]
    Go to Field [ status::_LockList ]
    Go to Portal Row [ $row ] [ Select; No dialog ]
    Delete Portal Row [ No dialog ]
    End If
    Set Variable [ $delete ]
    Go to Field [ ]
    Refresh Window

Fields used in this script	

    status::_LockList
    status::text
    issue::_keyStatus

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservations Copy

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [deleteStatus]		Next Script: [PHASEDOUTgotoIssueResolution]
Script Name	deleteGroup
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #Stop script if user is process of picking a specific action group.
    If [ $$pick = 1 ]
    Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can delete group tags. "; Buttons: “OK” ]
    Exit Script [ ]
    End If
    #
    If [ Get (ActiveFieldContents) = "" ]
    Show Custom Dialog [ Title: "!"; Message: "Select an item to delete."; Buttons: “OK” ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    #
    If [ category::_LockList = "" ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    #
    Set Variable [ $delete; Value:category::_LockList ]
    Set Variable [ $name; Value:category::text ]
    #
    Go to Layout [ “IssuesAndObservations Copy” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $delete ]
    Perform Find [ ]
    #
    Set Variable [ $error; Value:Get (LastError) ]
    #
    Go to Layout [ original layout ]
    If [ $error ≠ 401 ]
    Set Variable [ $delete ]
    Show Custom Dialog [ Message: "'" & $name & "'" & " can be deleted once all issues tagged with it are switched to a different item tag in the issues log window."; Buttons: “OK” ]
    Exit Script [ ]
    End If
    #
    Refresh Window
    Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
    #
    If [ Get ( LastMessageChoice ) = 2 ]
    Go to Layout [ “menuGroups” (issueCategory) ]
    Enter Find Mode [ ]
    Set Field [ issueCategory::_LockList; $delete ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ original layout ]
    End If
    #
    Set Variable [ $delete ]
    Go to Field [ ]
    Refresh Window

Fields used in this script	

    category::_LockList
    category::text
    issue::_keyCategory
    issueCategory::_LockList

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservations Copy
    menuGroups

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [deleteGroup]		Next Script: [gotoDayOnMainScreen]
Script Name	PHASEDOUTgotoIssueResolution
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ issueStatus::order > 79 and $$stopgotoIssueResolution ≠ 1 ]
    Set Variable [ $resolutionDate; Value:GetAsDate ( issue::dateDone ) ]
    Set Variable [ $$stoploadrecord; Value:1 ]
    Select Window [ Name: "Day"; Current file ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Freeze Window
    Loop
    Exit Loop If [ logs::_keyDay = $resolutionDate ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ logs::_keyDay ≠ $resolutionDate ]
    Set Variable [ $$stoploadrecord ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    Show Custom Dialog [ Message: "No activity log record matches the date for this issue's resolution. "; Buttons: “OK” ]
    Exit Script [ ]
    End If
    Set Variable [ $$stoploadrecord ]
    Perform Script [ “LoadLogrecordID” ]
    Go to Field [ logs::log ]
    End If

Fields used in this script	

    issueStatus::order
    issue::dateDone
    logs::_keyDay
    logs::log

Scripts used in this script	

    LoadLogrecordID

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [PHASEDOUTgotoIssueResolution]		Next Script: [IssueToLog]
Script Name	gotoDayOnMainScreen
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $date; Value:logs::_keyDay ]
    Select Window [ Name: "Timer"; Current file ]
    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 1 day layouts
    #
    #
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; $date ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    #4 sort the records
    Sort Records [ ] [ No dialog ]

Fields used in this script	

    logs::_keyDay
    reference::day1
    steward::chosenDay

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoDayOnMainScreen]		Next Script: [viewLogIssues]
Script Name	IssueToLog
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    addTimeSegmentToIssue

Script Definition
Script Steps	

    #
    #Prevent windows from flashing and script from slowing
    #by stopping strobe effect caused by going back and
    #forth from each window upon loading each records
    #information throughout the script, rather than just
    #at the end.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    #Exit issue field so conditional formatting can be applied.
    Go to Field [ ]
    #
    #If tag has not yet been selected, then add it.
    If [ issue::_LockList & "¶" ≠ FilterValues ( $$logIssues ; issue::_LockList & "¶" ) ]
    #
    Set Variable [ $newIssue; Value:issue::_LockList ]
    Select Window [ Name: "Day"; Current file ]
    If [ Get (LastError) = 112 ]
    Exit Script [ ]
    New Window [ Name: "Day"; Height: Get (ScreenHeight); Width: 608; Top: 0; Left: 441 ]
    End If
    #
    #prepare to add log ID to issueLogs so that the issue
    #will have a record of all days logged to deal with it.
    Set Variable [ $newlog; Value:logs::_lockDay ]
    Set Variable [ $$logIssue; Value:logs::_keyLogIssues ]
    #
    Set Field [ logs::_keyLogIssues; $newIssue & "¶" & $$logIssues ]
    Set Variable [ $$logIssues; Value:logs::_keyLogIssues ]
    Go to Field [ ]
    Refresh Window
    Select Window [ Name: "Specific Action"; Current file ]
    #
    #Add log ID to issueLogs.
    Set Field [ issue::_keyLogs; $newlog & "¶" & $$IssueLogs ]
    Set Variable [ $$IssueLogs; Value:issue::_keyLogs ]
    #
    #For some reason if system does not re-go to this
    #same record, other scripts trying to set fields for this
    #record in a different window (so same layout
    #different window will get an error 301 (record in use
    #by another user). So it is neccessary.
    #addTimeSegmentToIssue is the other scirpt that
    #gets that error message when this step is left out.
    Go to Record/Request/Page [ Get (RecordNumber) ] [ No dialog ]
    Refresh Window
    Set Variable [ $$stopRecordLoad ]
    Exit Script [ ]
    End If
    #
    #
    #
    #
    If [ $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 1 & $$log & "¶" = FilterValues ( $$timeAll ; 1 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 2 & $$log & "¶" = FilterValues ( $$timeAll ; 2 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 3 & $$log & "¶" = FilterValues ( $$timeAll ; 3 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 4 & $$log & "¶" = FilterValues ( $$timeAll ; 4 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 5 & $$log & "¶" = FilterValues ( $$timeAll ; 5 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 6 & $$log & "¶" = FilterValues ( $$timeAll ; 6 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 7 & $$log & "¶" = FilterValues ( $$timeAll ; 7 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 8 & $$log & "¶" = FilterValues ( $$timeAll ; 8 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 9 & $$log & "¶" = FilterValues ( $$timeAll ; 9 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 10 & $$log & "¶" = FilterValues ( $$timeAll ; 10 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 11 & $$log & "¶" = FilterValues ( $$timeAll ; 11 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 12 & $$log & "¶" = FilterValues ( $$timeAll ; 12 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 13 & $$log & "¶" = FilterValues ( $$timeAll ; 13 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 14 & $$log & "¶" = FilterValues ( $$timeAll ; 14 & $$log & "¶" ) or $$log & "¶" = FilterValues ( issue::_keyLogs ; $$log & "¶" ) and $$issueRecordID = Get (RecordID) and 15 & $$log & "¶" = FilterValues ( $$timeAll ; 15 & $$log & "¶" ) ]
    Show Custom Dialog [ Message: "This act has time from the selected day record assigned to it. Do you really want to do unlink it?"; Buttons: “cancel”, “unlink” ]
    If [ Get ( LastMessageChoice ) = 1 ]
    Exit Script [ ]
    End If
    End If
    #
    #
    #If issue is assigned to log, then remove it when user
    #clicks the link button.
    Set Variable [ $removeIssue; Value:issue::_LockList ]
    #
    #See if any time segements belong to this log record.
    If [ issue::timeSegmentKeyList ≠ "" ]
    #
    New Window [ Name: "temp" ]
    #
    Select Window [ Name: "Day"; Current file ]
    Set Variable [ $day; Value:daylog::_lockDay ]
    Select Window [ Name: "temp"; Current file ]
    If [ 1 & $day & "¶" = FilterValues ( $$timeAll ; 1 & $day & "¶" ) or 2 & $day & "¶" = FilterValues ( $$timeAll ; 2 & $day & "¶" ) or 3 & $day & "¶" = FilterValues ( $$timeAll ; 3 & $day & "¶" ) or 4 & $day & "¶" = FilterValues ( $$timeAll ; 4 & $day & "¶" ) or 5 & $day & "¶" = FilterValues ( $$timeAll ; 5 & $day & "¶" ) or 6 & $day & "¶" = FilterValues ( $$timeAll ; 6 & $day & "¶" ) or 7 & $day & "¶" = FilterValues ( $$timeAll ; 7 & $day & "¶" ) or 8 & $day & "¶" = FilterValues ( $$timeAll ; 8 & $day & "¶" ) or 9 & $day & "¶" = FilterValues ( $$timeAll ; 9 & $day & "¶" ) or 10 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or 11 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or 12 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or 13 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or 14 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) or 15 & $day & "¶" = FilterValues ( $$timeAll ; 10 & $day & "¶" ) ]
    Go to Layout [ “issueTime” (issueTime) ]
    Enter Find Mode [ ]
    Set Field [ issueTime::_keyDay; $day ]
    Set Field [ issueTime::_keyIssue; $$issue ]
    Perform Find [ ]
    Delete All Records [ No dialog ]
    #
    #Rebuild issue timeAll list of time segments assigned
    #to this issue.
    Enter Find Mode [ ]
    Set Field [ issueTime::_keyIssue; $$issue ]
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    Perform Find [ ]
    If [ Get (LastError) ≠ 401 ]
    #
    #Get total time for this issue.
    Set Variable [ $totalTime; Value:issueTime::sum ]
    #
    #Make a list of found day and repetition keys.
    Go to Record/Request/Page [ First ]
    Set Variable [ $RepAndDay; Value:issueTime::_keyRepetition & issueTime::_keyDay ]
    Loop
    Set Variable [ $list; Value:issueTime::_keyRepetition & issueTime::_keyDay & "¶" & $RepAndDay ]
    Set Variable [ $RepAndDay; Value:$list ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #Replace timeAll list with updated list.
    Go to Layout [ “Issues” (issue) ]
    Set Field [ issue::issueTotalTime; $TotalTime ]
    Set Field [ issue::timeSegmentKeyList; $list ]
    Set Variable [ $$timeAll; Value:$list ]
    #
    Else If [ Get (LastError) = 401 ]
    #
    #Erase timeAll list.
    Go to Layout [ “Issues” (issue) ]
    Set Field [ issue::issueTotalTime; "" ]
    Set Field [ issue::timeSegmentKeyList; "" ]
    Set Variable [ $$timeAll ]
    End If
    #
    #Add up total time for category it is in.
    Set Variable [ $categoryKey; Value:issue::_keyCategory ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $categoryKey ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    End If
    #
    Close Window [ Name: "temp"; Current file ]
    #
    End If
    #
    #
    #prepare to remove log ID from issueLogs so that the issue
    #will have a record of all days logged to deal with it.
    Select Window [ Name: "Day"; Current file ]
    Set Variable [ $$logIssues; Value:logs::_keyLogIssues ]
    Set Variable [ $removelog; Value:logs::_lockDay ]
    #
    Set Field [ logs::_keyLogIssues; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not removed, then the removal calc without the paragraph mark is used If ( ValueCount ( $$logIssues ) ≠ ValueCount ( Substitute ( $$logIssues ; $removeIssue & "¶" ; "" ) ) ; Substitute ( $$logIssues ; $removeIssue & "¶" ; "" ) ; Substitute ( $$logIssues ; $removeIssue ; "" ) ) ]
    Set Variable [ $$logIssues; Value:logs::_keyLogIssues ]
    Go to Field [ ]
    Refresh Window
    Select Window [ Name: "Specific Action"; Current file ]
    #
    #Remove log ID from issueLogs.
    Set Field [ issue::_keyLogs; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not removed, then the removal calc without the paragraph mark is used If ( ValueCount ( $$IssueLogs ) ≠ ValueCount ( Substitute ( $$IssueLogs ; $removeLog & "¶" ; "" ) ) ; Substitute ( $$IssueLogs ; $removeLog & "¶" ; "" ) ; Substitute ( $$IssueLogs ; $removeLog ; "" ) ) ]
    Set Variable [ $$IssueLogs; Value:issue::_keyLogs ]
    #
    #For some reason if system does not re-go to this
    #same record, other scripts trying to set fields for this
    #record in a different window (so same layout
    #different window will get an error 301 (record in use
    #by another user). So it is neccessary.
    #addTimeSegmentToIssue is the other scirpt that
    #gets that error message when this step is left out.
    Go to Record/Request/Page [ Get (RecordNumber) ] [ No dialog ]
    Set Variable [ $$stopRecordLoad ]

Fields used in this script	

    issue::_LockList
    logs::_lockDay
    logs::_keyLogIssues
    issue::_keyLogs
    issue::timeSegmentKeyList
    daylog::_lockDay
    issueTime::_keyDay
    issueTime::_keyIssue
    issueTime::sum
    issueTime::_keyRepetition
    issue::issueTotalTime
    issue::_keyCategory
    issue::sortTime
    issue::timeTotalSummaryByCategory
    issue::timeTotalSumByCat

Scripts used in this script	

Layouts used in this script	

    issueTime
    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [IssueToLog]		Next Script: [viewAllLogIssues]
Script Name	viewLogIssues
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    LoadLogrecordID

Script Definition
Script Steps	

    #
    #Prevent windows from flashing and script from slowing
    #by stopping strobe effect caused by going back and
    #forth from each window upon loading each records
    #information throughout the script, rather than just
    #at the end.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    #If find mode is active clear it.
    If [ $$found ≠ "" ]
    Select Window [ Name: "Tag"; Current file ]
    Set Variable [ $$found ]
    Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    End If
    #
    #Find all issues linked to this day.
    Select Window [ Name: "Specific Action"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: 0 ]
    If [ Get ( WindowZoomLevel ) > 150 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
    End If
    End If
    Go to Layout [ “Issues” (issue) ]
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyLogs; $$log ]
    Perform Find [ ]
    If [ Get (FoundCount) = 0 ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    End If
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Scroll Window [ Home ]
    Set Variable [ $$issueSort; Value:"status" ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $$stopRecordLoad ]
    Perform Script [ “LoadIssuerecordID” ]
    Set Variable [ $$stopSubtotal; Value:1 ]
    Perform Script [ “TsubtotalTimeByGroup” ]

Fields used in this script	

    issue::_keyLogs
    issue::_keyBrainstate
    issue::lock
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issueCategory::text
    issue::order
    issue::text

Scripts used in this script	

    LoadIssuerecordID
    TsubtotalTimeByGroup

Layouts used in this script	

    IssuesAndObservationsTag
    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [viewLogIssues]		Next Script: [dateStampIssue]
Script Name	viewAllLogIssues
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    ActivityLog!!!!findAllBrainstateLogs

Script Definition
Script Steps	

    #
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    #If find mode is active clear it.
    If [ $$found ≠ "" ]
    Select Window [ Name: "Tag"; Current file ]
    Set Variable [ $$found ]
    Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    End If
    #
    #neccessary step when two monitors are used as this
    #window can be opened in smaller monitor and then
    #move over to larger monitor but not adjust its height
    #unless this step is included.
    Select Window [ Name: "Specific Action"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: 0 ]
    If [ Get ( WindowZoomLevel ) > 150 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
    End If
    End If
    Go to Layout [ “Issues” (issue) ]
    #
    #remember record user was looking at before
    #find all issue records.
    Set Variable [ $issueRecord; Value:issue::_LockList ]
    #
    #Find all issue records.
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    Sort Records [ ] [ No dialog ]
    Set Variable [ $$issueSort; Value:"status" ]
    #
    #Now go the record the user was looking at.
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    Loop
    Exit Loop If [ issue::_LockList = $issueRecord ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #If the user was not looking at any records then
    #go to the first record.
    If [ issue::_LockList ≠ $issueRecord ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    End If
    Set Variable [ $$stopRecordLoad ]
    Perform Script [ “LoadIssuerecordID” ]

Fields used in this script	

    issue::_LockList
    issue::_keyBrainstate
    issue::lock

Scripts used in this script	

    LoadIssuerecordID

Layouts used in this script	

    IssuesAndObservationsTag
    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [viewAllLogIssues]		Next Script: [timeStampIssue]
Script Name	dateStampIssue
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Insert Calculated Result [ "[" & Get ( CurrentDate ) & "] " //TextSize ( "["; 12 ) & TextSize ( Get ( CurrentDate ) ; 12 ) & TextSize ( "] "; 12 ) ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [dateStampIssue]		Next Script: [addTimeSegmentToIssue]
Script Name	timeStampIssue
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $time; Value:daylog::_lockDay ]
    Go to Field [ ]
    Select Window [ Name: "Specific Action"; Current file ]
    Set Variable [ $timeAll; Value:issue::timeSegmentKeyList ]
    If [ $time & "¶" ≠ FilterValues ( $timeAll ; $time & "¶" ) ]
    Set Field [ issue::timeSegmentKeyList; $time & ¶ & $timeAll ]
    Exit Script [ ]
    End If
    Set Field [ issue::timeSegmentKeyList; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not removed, then the removal calc without the paragraph mark is used If ( ValueCount ( $timeAll ) ≠ ValueCount ( Substitute ( $timeAll ; $time & "¶" ; "" ) ) ; Substitute ( $timeAll ; $time & "¶" ; "" ) ; Substitute ( $timeAll ; $time ; "" ) ) ]

Fields used in this script	

    daylog::_lockDay
    issue::timeSegmentKeyList

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [timeStampIssue]		Next Script: [ActivityLog!!!!findAllBrainstateLogs]
Script Name	addTimeSegmentToIssue
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    If [ Get ( ActiveFieldContents ) = "" ]
    Go to Field [ ]
    Exit Script [ ]
    End If
    Set Variable [ $timeSegment; Value:Get ( ActiveRepetitionNumber ) & logs::_lockDay ]
    #
    #Prevent windows from flashing and script from slowing
    #by stopping strobe effect caused by going back and
    #forth from each window upon loading each records
    #information throughout the script, rather than just
    #at the end.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    #Get category key for adding up total category time
    #later in the script.
    Select Window [ Name: "Specific Action"; Current file ]
    Set Variable [ $categoryKey; Value:issue::_keyCategory ]
    Go to Field [ ]
    #
    #For some reason if system does not re-go to same
    #issue record, record in a different window (so same
    #layout different window will get an error 301 (record
    #in use by another user).
    Go to Record/Request/Page [ Get (RecordNumber) ] [ No dialog ]
    Select Window [ Name: "Day"; Current file ]
    #
    #Capture repetition number and _lockDay when
    #segment is clicked in log window.
    Set Variable [ $day; Value:daylog::_lockDay ]
    Set Variable [ $repetition; Value:Get (ActiveRepetitionNumber) ]
    Go to Field [ ]
    #
    #See if time segment is already in use by ANY segment.
    Go to Layout [ “issueTime” (issueTime) ]
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Enter Find Mode [ ]
    Set Field [ issueTime::_keyDay; $day ]
    Set Field [ issueTime::_keyRepetition; $repetition ]
    Perform Find [ ]
    #
    #If it is not in use create a new record in issueTime
    #window and give it issue, day, and repetition keys.
    #to add their time to the total of all time spent on
    #this issue.
    If [ Get (LastError) = 401 ]
    New Record/Request
    Set Field [ issueTime::_keyDay; $day ]
    Set Field [ issueTime::_keyRepetition; $repetition ]
    Set Field [ issueTime::_keyIssue; $$issue ]
    #
    #Add up total time for this issue.
    Enter Find Mode [ ]
    Set Field [ issueTime::_keyIssue; $$issue ]
    Perform Find [ ]
    Set Variable [ $totalTime; Value:issueTime::sum ]
    #
    #Add day and repetition keys to the list of all day
    #and repetition keys for this issue.
    Go to Layout [ “IssuesLayoutForScripts” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_LockList; $$issue ]
    Perform Find [ ]
    Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
    Set Variable [ $time; Value:$repetition & $day ]
    Set Field [ issue::timeSegmentKeyList; $time & ¶ & $$timeAll ]
    Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
    Set Field [ issue::issueTotalTime; $totalTime ]
    #
    #Add up total time for category it is in.
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $categoryKey ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    Go to Layout [ original layout ]
    #
    #Conditionally format segment to show that it is assigned.
    Set Field [ daylog::swLogTimeAccounting[$repetition]; $$issue ]
    #
    #If issue is not linked to day whose time has just
    #been added to it, then link it.
    Select Window [ Name: "Specific Action"; Current file ]
    If [ issue::_LockList & "¶" ≠ FilterValues ( $$logIssues ; issue::_LockList & "¶" ) ]
    Perform Script [ “IssueToLog” ]
    End If
    Select Window [ Name: "Day"; Current file ]
    Go to Field [ ]
    #
    #
    #
    #
    Else If [ Get (LastError) ≠ 401 ]
    Go to Layout [ original layout ]
    Show Custom Dialog [ Message: "Subtract time from act currently credited with it, so that it can be credited to a different act?¶¶Go to act credited with this time?"; Buttons: “GoToAct”, “Subtract” ]
    If [ Get ( LastMessageChoice ) = 1 ]
    Go to Field [ ]
    Select Window [ Name: "Specific Action"; Current file ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") ≠ $timeSegment & "¶" ]
    Enter Find Mode [ ]
    Set Field [ issue::timeSegmentKeyList; $timeSegment & "¶" ]
    Extend Found Set [ ]
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    End If
    Set Variable [ $$stopRecordLoad ]
    Perform Script [ “LoadIssuerecordID” ]
    Exit Script [ ]
    End If
    #
    #Conditionally format segment so it shows as unassigned.
    Set Field [ daylog::swLogTimeAccounting[$repetition]; "" ]
    #
    #If it is in use then subtract its time from the total
    #time of all time segements attributed to this issue.
    #BUT first set a new issue ID variable as the user
    #may be removing the time from an issue not currently
    #selected, meaning the time was part of a different
    #issue and when the user clicked on this time to assign
    #to a new issue, the time first had to be deleted from
    #the issue to which it is currently assigned.
    Go to Layout [ “issueTime” (issueTime) ]
    Set Variable [ $issueTimeDelete; Value:issueTime::_keyIssue ]
    Delete Record/Request [ No dialog ]
    #
    #Add up total time for issue.
    Enter Find Mode [ ]
    Set Field [ issueTime::_keyIssue; $issueTimeDelete ]
    Perform Find [ ]
    Set Variable [ $totalTime; Value:issueTime::sum ]
    #
    #Then subtract day and repetition keys from the list
    #of all day and repetition keys for this issue.
    Go to Layout [ “Issues” (issue) ]
    Set Variable [ $time; Value:$repetition & $day ]
    Enter Find Mode [ ]
    Set Field [ issue::timeSegmentKeyList; $time ]
    Perform Find [ ]
    Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
    Set Field [ issue::timeSegmentKeyList; //last item in list has no paragraph mark, so a valuecount test needs to be done and if item is not removed, then the removal calc without the paragraph mark is used If ( ValueCount ( $$timeAll ) ≠ ValueCount ( Substitute ( $$timeAll ; $time & "¶" ; "" ) ) ; Substitute ( $$timeAll ; $time & "¶" ; "" ) ; Substitute ( $$timeAll ; $time ; "" ) ) ]
    Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
    Set Field [ issue::issueTotalTime; $totalTime ]
    #
    #Add up total time for category it is in.
    Go to Layout [ “Issues” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $categoryKey ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    Go to Layout [ original layout ]
    Go to Layout [ original layout ]
    Go to Field [ ]
    End If
    Set Variable [ $$stopRecordLoad ]
    Select Window [ Name: "Specific Action"; Current file ]
    Perform Script [ “LoadIssuerecordID” ]
    Select Window [ Name: "Day"; Current file ]

Fields used in this script	

    logs::_lockDay
    issue::_keyCategory
    daylog::_lockDay
    issueTime::_keyDay
    issueTime::_keyRepetition
    issueTime::_keyIssue
    issueTime::sum
    issue::_LockList
    issue::timeSegmentKeyList
    issue::issueTotalTime
    issue::sortTime
    issue::timeTotalSummaryByCategory
    issue::timeTotalSumByCat
    daylog::swLogTimeAccounting

Scripts used in this script	

    IssueToLog
    LoadIssuerecordID

Layouts used in this script	

    issueTime
    IssuesLayoutForScripts
    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [addTimeSegmentToIssue]		Next Script: [CHUNK_updateIssueCategoryTime]
Script Name	ActivityLog!!!!findAllBrainstateLogs
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    note veto view

Script Definition
Script Steps	

    Set Variable [ $$stopRecordLoad; Value:1 ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyBrainstate; $$LogBrainstate ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending logs::_keyDay; descending ] [ Restore; No dialog ]
    Set Variable [ $$stopRecordLoad ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
    Set Variable [ $$log; Value:logs::_lockDay ]
    If [ daylog::swActivityLength[11] ≠ "" ]
    Go to Layout [ “logs3rows” (logs) ]
    Else If [ daylog::swActivityLength[6] ≠ "" ]
    Go to Layout [ “logs2rows” (logs) ]
    Else If [ daylog::swActivityLength[6] = "" ]
    Go to Layout [ “logs1row” (logs) ]
    End If
    Refresh Window
    Scroll Window [ Home ]
    // Perform Script [ “viewAllLogIssues” ]

Fields used in this script	

    logs::_keyBrainstate
    logs::_keyDay
    logs::_keyLogIssues
    logs::_lockDay
    daylog::swActivityLength

Scripts used in this script	

    viewAllLogIssues

Layouts used in this script	

    logs3rows
    logs2rows
    logs1row

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [ActivityLog!!!!findAllBrainstateLogs]		Next Script: [gotoIssuesLog]
Script Name	CHUNK_updateIssueCategoryTime
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    UpdateTime
    clearPart2

Script Definition
Script Steps	

    #
    #This script is used by the updateTime script
    #and the clear script.
    #
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    #FIRST capture current window so system can go
    #to it after finished, otherwise
    #UpdateTime script tries to continue in the wrong
    #window, which is showing the wrong layout!
    Set Variable [ $UpdateTimewindowName; Value:Get ( WindowName ) ]
    #
    #Find all issues with this day record's time attributed
    #to them.
    Go to Field [ ]
    #
    New Window [ Name: "temp"; Height: 1; Width: 1; Top: 1; Left: 1 ]
    Go to Layout [ “IssuesLayoutForScripts” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::timeSegmentKeyList; "*" & Replace ( Quote("1") ; 2 ; 1 ; $$updateDay ) ]
    Perform Find [ ]
    If [ Get (LastError) = 401 ]
    Close Window [ Name: "temp"; Current file ]
    Exit Script [ ]
    End If
    #
    #Make sure user is not in any fields before updating
    #as this prevents update of time for the record
    #the user is in (have not test how yet).
    Select Window [ Name: "Specific Action"; Current file ]
    If [ Get (LastError) ≠ 112 ]
    Go to Field [ ]
    End If
    #
    Select Window [ Name: "temp"; Current file ]
    #
    #Make a list of them.
    Go to Record/Request/Page [ First ]
    Loop
    Set Variable [ $AllIssueRecordsNeedingUpdate; Value:issue::_LockList & "¶" & $issueList ]
    Set Variable [ $issueList; Value:$AllIssueRecordsNeedingUpdate ]
    If [ $$clear = 1 ]
    #
    #Remove link to log from issue record.
    Set Field [ issue::_keyLogs; If ( ValueCount ( issue::_keyLogs ) ≠ ValueCount ( Substitute ( issue::_keyLogs ; $$updateDay & "¶" ; "" ) ) ; Substitute ( issue::_keyLogs ; $$updateDay & "¶" ; "" ) ; Substitute ( issue::_keyLogs ; $$updateDay ; "" ) ) ]
    #
    #Remove time segment key from list.
    #(the teen numbers must come first otherwise
    #the singly digits will delete 3 in 13 and leave
    #behind an orphaned 1 for example)
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 11 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 12 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 13 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 14 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 15 & $$updateday & "¶" ; "" ) ]
    #
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 1 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 2 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 3 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 4 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 5 & $$updateday & "¶" ; "" ) ]
    #
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 6 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 7 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 8 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 9 & $$updateday & "¶" ; "" ) ]
    Set Field [ issue::timeSegmentKeyList; Substitute ( issue::timeSegmentKeyList ; 10 & $$updateday & "¶" ; "" ) ]
    End If
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #Update the time for each issue in the list.
    Loop
    Set Variable [ $issue; Value:GetValue ( $AllIssueRecordsNeedingUpdate ; 1 ) ]
    Set Variable [ $AllIssueRecordsNeedingUpdate; Value:If ( ValueCount ( $AllIssueRecordsNeedingUpdate ) ≠ ValueCount ( Substitute ( $AllIssueRecordsNeedingUpdate ; $issue & "¶" ; "" ) ) ; Substitute ( $AllIssueRecordsNeedingUpdate ; $issue & "¶" ; "" ) ; Substitute ( $AllIssueRecordsNeedingUpdate ; $issue ; "" ) ) ]
    #
    #Find all time segments attributed to this issue.
    Go to Layout [ “issueTime” (issueTime) ]
    Enter Find Mode [ ]
    Set Field [ issueTime::_keyIssue; $issue ]
    Perform Find [ ]
    Exit Loop If [ Get (LastError) = 400 ]
    #
    #Get total time for this issue.
    Set Variable [ $totalTime; Value:issueTime::sum ]
    #
    #And update this issue's total time.
    Go to Layout [ “IssuesLayoutForScripts” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_LockList; $issue ]
    Perform Find [ ]
    Set Field [ issue::issueTotalTime; $totalTime ]
    #
    #Add up total time for category it is in.
    Set Variable [ $categoryKey; Value:issue::_keyCategory ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyCategory; $categoryKey ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: issue::sortTime; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #
    #Disabled the next chunk after deciding it was
    #better to use filemaker's subtotal calc rather
    #doing it with this script chunk whose benefit
    #was subtotaling items in a category even when
    #items where divided by status. Filemaker's
    #subtotal calc subtotals at the status and category
    #breaks (essentially all breaks caused by a sort)
    #but I decided to show issue the time by status
    #and category too, so that is why this script chunk
    #is now disabled. The other reason was that it
    #bogged down the system taking a long time to run.
    // #To reset all the category subtotal times, first find
    // #and sort all this issues records.
    // Set Variable [ $brainstateIssues; Value:issue::_keyBrainstate ]
    // Enter Find Mode [ ]
    // Set Field [ issue::_keyBrainstate; $brainstateIssues ]
    // Perform Find [ ]
    // Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issue::timeTotalSummaryByCategory; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    // Go to Record/Request/Page [ First ]
    // #
    // #
    // #AddUp total time showing for this subset of
    // #a cateogory broken up into subsets by different
    // #statuses, like the subset of some category's
    // #record that are pending, or completed, etc.
    // Loop
    // Set Variable [ $category; Value:issue::_keyCategory ]
    // Set Variable [ $status; Value:issue::_keyStatus ]
    // Set Variable [ $recordNumber; Value:Get (RecordNumber) ]
    // Set Variable [ $subsetTotal ]
    // Set Variable [ $oldTotal ]
    // #
    // Loop
    // Set Variable [ $subsetTotal; Value:issue::issueTotalTime + $oldTotal ]
    // Set Variable [ $oldTotal; Value:$subsetTotal ]
    // Go to Record/Request/Page [ Next; Exit after last ]
    // Exit Loop If [ issue::_keyCategory ≠ $category //This next step I thought could happen, but then realized it can nevery happen //or //issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
    // End Loop
    // #
    // #Return the first record in this subset and give it
    // #the subset total, then give the subtotal to all
    // #records in this subset.
    // Go to Record/Request/Page [ $recordNumber ] [ No dialog ]
    // #
    // Loop
    // Set Field [ issue::timeTotalSumByCatSortedByStatus; $subsetTotal ]
    // Go to Record/Request/Page [ Next; Exit after last ]
    // Exit Loop If [ issue::_keyCategory ≠ $category //This next step I thought could happen, but then realized it can nevery happen //or //issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
    // End Loop
    // #
    // Exit Loop If [ Get (LastError) = 101 ]
    End Loop
    #
    #
    #
    Close Window [ Name: "temp"; Current file ]
    #
    // #If user cleared record then need to check if there
    // #are log records to show user, and if not close the
    // #log windows if they are open.
    // #
    // Select Window [ Name: "Day"; Current file ]
    // If [ Get (LastError) = 112 ]
    // Select Window [ Name: $UpdateTimewindowName; Current file ]
    // Exit Script [ ]
    // End If
    // #
    // If [ daylog::swActivityLength[11] ≠ "" ]
    // Go to Layout [ “logs3rows” (logs) ]
    // Else If [ daylog::swActivityLength[6] ≠ "" ]
    // Go to Layout [ “logs2rows” (logs) ]
    // Else If [ daylog::swActivityLength[6] = "" ]
    // Go to Layout [ “logs1row” (logs) ]
    // End If
    // Refresh Window
    Select Window [ Name: $UpdateTimewindowName; Current file ]
    Exit Script [ ]

Fields used in this script	

    issue::timeSegmentKeyList
    issue::_LockList
    issue::_keyLogs
    issueTime::_keyIssue
    issueTime::sum
    issue::issueTotalTime
    issue::_keyCategory
    issue::sortTime
    issue::timeTotalSummaryByCategory
    issue::timeTotalSumByCat
    issue::_keyBrainstate
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issue::order
    issue::text
    issue::_keyStatus
    issue::timeTotalSumByCatSortedByStatus
    daylog::swActivityLength

Scripts used in this script	

Layouts used in this script	

    IssuesLayoutForScripts
    issueTime
    logs3rows
    logs2rows
    logs1row

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CHUNK_updateIssueCategoryTime]		Next Script: [gotoTagMenus]
Script Name	gotoIssuesLog
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Select Window [ Name: "Specific Action"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Specific Action" ]
    If [ Get ( WindowZoomLevel ) > 150 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
    Else If [ Get ( WindowZoomLevel ) = 150 ]
    Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Width: 441; Left: 0 ]
    End If
    Go to Layout [ “Issues” (issue) ]
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logbrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$issue; Value:issue::_LockList ]
    Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
    Refresh Window
    End If

Fields used in this script	

    issue::_keyBrainstate
    issue::lock
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issueCategory::text
    issue::order
    issue::text
    issue::_LockList
    issue::_keyLogs

Scripts used in this script	

Layouts used in this script	

    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoIssuesLog]		Next Script: [zoomLogIN_DELETE!!!!!!]
Script Name	gotoTagMenus
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Select Window [ Name: "Tag"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Tag" ]
    If [ Get ( WindowZoomLevel ) = 200 ]
    Move/Resize Window [ Current Window; Width: 550; Left: If (Get (ScreenWidth) / 2 + 550 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 550 ) ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Move/Resize Window [ Current Window; Width: 830; Left: If (Get (ScreenWidth) / 2 + 830 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 830 ) ]
    Else If [ Get ( WindowZoomLevel ) = 400 ]
    Move/Resize Window [ Current Window; Width: 1100; Left: If (Get (ScreenWidth) / 2 + 1100 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 1100 ) ]
    Else If [ Get ( WindowZoomLevel ) = 150 ]
    Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: If (Get (ScreenWidth) / 2 + 1100 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 1100 ) ]
    End If
    Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
    Perform Find [ ]
    Select Window [ Name: "Tag"; Current file ]
    End If

Fields used in this script	

    brainstate::_lockBrainstateID

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservationsOrder

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoTagMenus]		Next Script: [zoomMainIN]
Script Name	zoomLogIN_DELETE!!!!!!
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Select Window [ Name: "Tag"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Tag"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: Get (ScreenWidth) - 441 ]
    Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
    Perform Find [ ]
    End If
    If [ Get ( WindowZoomLevel ) = 150 ]
    Set Zoom Level [ 200% ]
    Move/Resize Window [ Current Window; Width: 550; Left: If (Get (ScreenWidth) / 2 + 550 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 550 ) ]
    Else If [ Get ( WindowZoomLevel ) = 200 ]
    Move/Resize Window [ Current Window; Width: 830; Left: If (Get (ScreenWidth) / 2 + 830 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 830 ) ]
    Set Zoom Level [ 300% ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Move/Resize Window [ Current Window; Width: 1100; Left: If (Get (ScreenWidth) / 2 + 1100 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 1100 ) ]
    Set Zoom Level [ 400% ]
    End If
    Select Window [ Name: "Specific Action"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: 0 ]
    Go to Layout [ “Issues” (issue) ]
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logbrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$issue; Value:issue::_LockList ]
    Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
    Refresh Window
    End If
    If [ Get ( WindowZoomLevel ) = 150 ]
    Set Zoom Level [ 200% ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
    Else If [ Get ( WindowZoomLevel ) = 200 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
    Set Zoom Level [ 300% ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
    Set Zoom Level [ 400% ]
    End If
    Select Window [ Name: "Day"; Current file ]
    If [ Get ( WindowZoomLevel ) = 150 ]
    Set Zoom Level [ 200% ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
    Else If [ Get ( WindowZoomLevel ) = 200 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
    Set Zoom Level [ 300% ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
    Set Zoom Level [ 400% ]
    End If

Fields used in this script	

    brainstate::_lockBrainstateID
    issue::_keyBrainstate
    issue::lock
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issueCategory::text
    issue::order
    issue::text
    issue::_LockList
    issue::_keyLogs

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservationsOrder
    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [zoomLogIN_DELETE!!!!!!]		Next Script: [zoomLogOUT_DELETE!!!!!!]
Script Name	zoomMainIN
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ Get ( WindowZoomLevel ) ≤ 150 ]
    Set Zoom Level [ 200% ]
    Else If [ Get ( WindowZoomLevel ) = 200 ]
    Set Zoom Level [ 300% ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Set Zoom Level [ 400% ]
    End If

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [zoomMainIN]		Next Script: [zoomMainOUT]
Script Name	zoomLogOUT_DELETE!!!!!!
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Select Window [ Name: "Tag"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Tag"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: Get (ScreenWidth) - 441 ]
    Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
    Perform Find [ ]
    End If
    If [ Get ( WindowZoomLevel ) = 400 ]
    Move/Resize Window [ Current Window; Width: 830; Left: If (Get (ScreenWidth) / 2 + 830 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 830 ) ]
    Set Zoom Level [ 300% ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Set Zoom Level [ 200% ]
    Move/Resize Window [ Current Window; Width: 550; Left: If (Get (ScreenWidth) / 2 + 550 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 550 ) ]
    Else If [ Get ( WindowZoomLevel ) = 200 ]
    Move/Resize Window [ Current Window; Width: 441; Left: If (Get (ScreenWidth) ≥ 441 + 608 + 441; 441 + 608 ; Get (ScreenWidth) - 441 ) ]
    Set Zoom Level [ 150% ]
    End If
    Select Window [ Name: "Specific Action"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: 0 ]
    Go to Layout [ “Issues” (issue) ]
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logbrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$issue; Value:issue::_LockList ]
    Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
    Refresh Window
    End If
    If [ Get ( WindowZoomLevel ) = 400 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
    Set Zoom Level [ 300% ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Set Zoom Level [ 200% ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: 0 ]
    Else If [ Get ( WindowZoomLevel ) = 200 ]
    Move/Resize Window [ Current Window; Width: 441; Left: 0 ]
    Set Zoom Level [ 150% ]
    End If
    Select Window [ Name: "Day"; Current file ]
    If [ Get ( WindowZoomLevel ) = 400 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
    Set Zoom Level [ 300% ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Set Zoom Level [ 200% ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
    Else If [ Get ( WindowZoomLevel ) = 200 ]
    Move/Resize Window [ Current Window; Width: 608; Left: 441 ]
    Set Zoom Level [ 150% ]
    End If

Fields used in this script	

    brainstate::_lockBrainstateID
    issue::_keyBrainstate
    issue::lock
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issueCategory::text
    issue::order
    issue::text
    issue::_LockList
    issue::_keyLogs

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservationsOrder
    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [zoomLogOUT_DELETE!!!!!!]		Next Script: [goToIssueFromAssignedTimeSegment]
Script Name	zoomMainOUT
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ Get ( WindowZoomLevel ) = 400 ]
    Set Zoom Level [ 300% ]
    Else If [ Get ( WindowZoomLevel ) = 300 ]
    Set Zoom Level [ 200% ]
    Else If [ Get ( WindowZoomLevel ) = 200 ]
    Set Zoom Level [ 150% ]
    End If

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [zoomMainOUT]		Next Script: [stopSortWhileReviewChangingStatusAndGroup]
Script Name	goToIssueFromAssignedTimeSegment
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $timeSegment; Value:Get ( ActiveRepetitionNumber ) & logs::_lockDay ]
    Go to Field [ ]
    Select Window [ Name: "Specific Action"; Current file ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ FilterValues (issue::timeSegmentKeyList ; $timeSegment & "¶") = $timeSegment & "¶" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop

Fields used in this script	

    logs::_lockDay
    issue::timeSegmentKeyList

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goToIssueFromAssignedTimeSegment]		Next Script: [orderTagsA]
Script Name	stopSortWhileReviewChangingStatusAndGroup
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ $$stopSort = "" ]
    Set Variable [ $$stopSort; Value:1 ]
    Else
    Set Variable [ $$stopSort ]
    End If
    Refresh Window

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [stopSortWhileReviewChangingStatusAndGroup]		Next Script: [orderTagsB]
Script Name	orderTagsA
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Field [ steward::chosenTagOrderSort; 1 ]
    Go to Object [ Object Name: "A" ]

Fields used in this script	

    steward::chosenTagOrderSort

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [orderTagsA]		Next Script: [orderTagsC]
Script Name	orderTagsB
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Field [ steward::chosenTagOrderSort; 2 ]
    Go to Object [ Object Name: "B" ]

Fields used in this script	

    steward::chosenTagOrderSort

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [orderTagsB]		Next Script: [orderTagsD]
Script Name	orderTagsC
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Field [ steward::chosenTagOrderSort; 3 ]
    Go to Object [ Object Name: "c" ]

Fields used in this script	

    steward::chosenTagOrderSort

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [orderTagsC]		
Script Name	orderTagsD
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Field [ steward::chosenTagOrderSort; 4 ]
    Go to Object [ Object Name: "D" ]

Fields used in this script	

    steward::chosenTagOrderSort

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


start close
	Parent Folder: [start close]	Next Script: [New Script]
Script Name	start
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE save out graphic objects to external folder for reference in graphs and then go to the user layout
    #
    #test
    #
    #1 save out graphic objects to external folder for reference in graphs
    Set Variable [ $path; Value:"file:" & Get(TemporaryPath) & "1.gif" ]
    Export Field Contents [ reference::gResources; “$path” ]
    Set Variable [ $path; Value:"file:" & Get(TemporaryPath) & "2.gif" ]
    Export Field Contents [ reference::gResources[3]; “$path” ]
    #
    #2 go to the user layout
    Go to Layout [ “users” (steward) ]
    Show All Records
    Sort Records [ Specified Sort Order: steward::FirstName; ascending steward::LastName; ascending ] [ Restore; No dialog ]
    If [ steward::windowZoom = 150 ]
    Set Zoom Level [ 100% ]
    Else If [ steward::windowZoom = 200 ]
    Set Zoom Level [ 100% ]
    Else If [ steward::windowZoom = 300 ]
    Set Zoom Level [ 100% ]
    Else If [ steward::windowZoom = 400 ]
    Set Zoom Level [ 100% ]
    End If
    // Adjust Window [ Maximize ]
    Adjust Window [ Resize to Fit ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) * .8; Top: Get (ScreenHeight) * .05; Left: Get (ScreenWidth) * .1 ]
    Set Window Title [ Current Window; New Title: "HelpGiveThanks Solutions" ]
    #
    #Show regular menus if Admin logs in only.
    Show/Hide Text Ruler [ Hide ]
    If [ Get ( AccountName ) = "Admin" ]
    Show/Hide Status Area [ Hide ]
    Install Menu Set [ “[Standard FileMaker Menus]” ]
    Else
    Show/Hide Status Area [ Lock; Hide ]
    End If

Fields used in this script	

    reference::gResources
    steward::FirstName
    steward::LastName
    steward::windowZoom

Scripts used in this script	

Layouts used in this script	

    users

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	

    [Standard FileMaker Menus]


Previous Script: [start]	Parent Folder: [start close]	Next Script: [close]
Script Name	New Script
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [New Script]	Parent Folder: [start close]	
Script Name	close
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE save out graphic objects to external folder for reference in graphs and then go to the user layout
    #
    #
    #
    // #2 flag/unflag active stopwatch field for conditional formatting on main screen if current screen is total layout
    // If [ Left ( Get ( LayoutName ) ; 5 ) = "total" or Left ( Get ( LayoutName ) ; 5 ) = "grand" ]
    // Perform Script [ “FolderStopwatchCheck” ]
    // End If
    #
    #1 set the layout status field
    // If [ Get ( SystemPlatform ) ≠ 3 and steward::iPhoneLayout = "" ]
    // Set Field [ steward::windowSizeAndPlace; Get ( WindowHeight ) ]
    // Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowWidth ) ]
    // Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowTop ) ]
    // Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowLeft ) ]
    // Exit Script [ ]
    // End If
    // Set Field [ steward::windowSizeAndPlace[5]; Get ( WindowHeight ) ]
    // Set Field [ steward::windowSizeAndPlace[6]; Get ( WindowWidth ) ]
    // Set Field [ steward::windowSizeAndPlace[7]; Get ( WindowTop ) ]
    // Set Field [ steward::windowSizeAndPlace[8]; Get ( WindowLeft ) ]

Fields used in this script	

    steward::iPhoneLayout
    steward::windowSizeAndPlace

Scripts used in this script	

    FolderStopwatchCheck

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


total
	Parent Folder: [total]	Next Script: [CHUNK_recalculateTotal]
Script Name	showLinkedRecords
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    note veto view
    note veto view (old: opened things in new windows)

Script Definition
Script Steps	

    #PURPOSE on the normal record view layouts the user is shown a total linkID number underlined to indicated that it is a button and a view button for all total and grand total records. These two buttons -- linkID number and view -- activate this script whose purpose is to 1) navigate from the current layout to the totalview layout, and 2) find and display the linked records. For example, the user may have several leg exercises they do each tracked by separate record and all of them totaled in one leg exercise total record. Clicking on the view button for the total record or the linkID number of this total record displayed next all the leg exercise records will activitate this script with result being the display of just these leg exercise records and the leg exercise total record. The user could take advantage of this feature to hide the leg exercise records displaying only the total record and when they wish to record leg exercise time, the user could click the view button see all the associated records, update them and then return to the main screen in which once again only the total record (now updated with new time) would be shown (along with all the other records the user wants to see.
    #
    #
    #
    #1 check to insure the record is linked and if not stop the script. (This is neccessary because filemaker allows the link button that activitates this script to be hidden but not deactivited, and it should not run if there are no records for it to find and display.)
    If [ brainstate::groupID = "" and brainstate::groupOfGroupID = "" ]
    Halt Script
    #
    #2 if the record is part of total (or is the total record) find and display all linked records and set the users choosen day field.
    Else If [ brainstate::groupID ≠ "" ]
    Set Variable [ $mergeID; Value:brainstate::groupID ]
    Set Field [ steward::chosenDayTotal; brainstate::day1 ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $mergeID ]
    Set Field [ brainstate::sortRetired; "=" ]
    Perform Find [ ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “TotalMainiPhone” (brainstate) ]
    Else If [ Get ( SystemPlatform ) ≠ 3 or steward::iPhoneLayout = "" ]
    Go to Layout [ “TotalMain” (brainstate) ]
    End If
    #END NOT TESTED
    #set the retired status to r (assume the user always only wants to show current set of records minus the ones they have retired)
    Set Field [ steward::retiredStatus; "r" ]
    #future developement: omit retired records if the retired button is on
    // Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    // Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    #save the recordnumber which will now be erased by the next script
    Set Variable [ $$recordnumber2; Value:$$recordnumber ]
    Perform Script [ “DaySelectSortThenSort” ]
    Halt Script
    #
    #3 if the record is part of a grand total (or is the grand total record) find and display all linked records.
    Else If [ brainstate::groupOfGroupID ≠ "" ]
    Set Variable [ $mergeGrandID; Value:brainstate::groupOfGroupID ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $mergeGrandID ]
    Perform Find [ ]
    #future developement: omit retired records if the retired button is on
    // Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    Go to Layout [ “GrandTotal” (brainstate) ]
    // Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Perform Script [ “DaySelectSortThenSort” ]
    Halt Script
    End If

Fields used in this script	

    brainstate::groupID
    brainstate::groupOfGroupID
    brainstate::day1
    steward::chosenDayTotal
    brainstate::sortRetired
    steward::iPhoneLayout
    steward::retiredStatus
    brainstate::groupType
    brainstate::_lockBrainstateID

Scripts used in this script	

    DaySelectSortThenSort

Layouts used in this script	

    TotalMainiPhone
    TotalMain
    GrandTotal

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [showLinkedRecords]	Parent Folder: [total]	Next Script: [CHUNK_recalculateGrandTotal]
Script Name	CHUNK_recalculateTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    seperateFromTotal
    CHUNK_deleteRecordsTimeFromTotal

Script Definition
Script Steps	

    #PURPOSE recalculate the total time for each day for the given set of records
    #CHUNK USED BY DeleteBrainstate Script
    #CHUNK USED BY seperateFromTotal Script
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Set Variable [ $brainstateID; Value:brainstate::groupID ]
    #
    #
    #
    #A) BEGIN delete total's day records
    #
    #1 delete all the total's day records, which will include some of the time from the just separated or soon to be deleted record. (Now we are ready to create new total records for the records that remain.)
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Perform Find [ ]
    #
    #2 double check to insure records to be deleted are the right records. (During testing all 900+ records where deleted from my database. I think what happened is the find came up with zero records and then displayed all the records in the database and the next step deleted them. This If check will prevent that from happening again if that is what happened. I have been unable to duplicate this massive error, so this might not be reason why all the records where deleted, but this is the only time when the database is told to delete all found records, rather than just one record, so I figure it must have been caused here.)
    If [ day2::_keyBrainstate = $brainstateID ]
    Delete All Records [ No dialog ]
    End If
    #
    #A) END delete total's day records
    #
    #
    #
    Loop
    #B) BEGIN check if there are records to be totaled
    #
    #1 make sure there is a record to be totaled (this step will be important when this loop is repeated after the first record to be totaled is omitted).
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Go to Record/Request/Page [ First ]
    #
    #If all records are empty then the total is complete and now the user needs to be shown the new total record and all the records that will feed into it until they are separated.
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    Exit Script [ ]
    End If
    #
    #B) END check if there are records to be totaled
    #
    #
    #
    #C BEGIN find total record's related day records
    #
    #1 make a list of the first brainstate's day records in a new window
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    #
    #C END find total record's related day records
    #
    #
    #
    #D BEGIN no records found loop (this loop will either complete the total process or find a record with related day records to be added to the total record)
    #
    Loop
    #
    #1 if records are found exit loop
    Exit Loop If [ Get ( LastError ) = 0 ]
    #
    #2 clear the merge field (the big X in the box on the ToBeMerged layout) and omit this record
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Set Field [ brainstate::groupAddCheckbox; "" ]
    Omit Record
    #
    #
    #
    #
    #If all records are empty then the total is complete and now the user needs to be shown the new total record and all the records that will feed into it until they are separated.
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    Exit Script [ ]
    End If
    #
    #
    #BEGIN find error 2
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming merge script part D2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 2
    #
    #
    #
    #3 make a list of this record's day records in a new window.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    End Loop
    #
    #D END no records found loop (this loop will either complete the total process or find a record with related day records to be added to the total record)
    #
    #
    #
    #E BEGIN create new related day records and add selected record's time to them
    #
    Loop
    #1 find any day records for the new brainstate that match the kfDay of the first merge record. If this new record already has data in it, then we want to add new data to the old data; not replace the old data with new data.
    Set Variable [ $mergeDay; Value:day1::_keyDay ]
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Perform Find [ ]
    #
    #2 if no matches are found, create a new day record and put in the time of the first the current day record
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & $TotalActivity ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    #
    #
    #
    #BEGIN find error 3
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming merge script part E2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button.
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    #END find error 3
    #
    #
    #
    #3 if a match is found, then add the current day's time to this day's time.
    Else If [ Get ( LastError ) = 0 ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    End If
    #
    #4 repeat loop for found record's next related day record.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #E END create new related day records and add selected record's time to them
    #
    #
    #
    #F BEGIN go to next record with related day records to be added to the new total record.
    #
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #Clear the merge field (the big X in the box on the ToBeMerged layout).
    Set Field [ brainstate::groupAddCheckbox; "" ]
    Omit Record
    #
    #F END go to next record with related day records to be added to the new total record.
    #
    #
    #
    End Loop

Fields used in this script	

    reference::farmerID
    brainstate::groupID
    day2::_keyBrainstate
    brainstate::_lockBrainstateID
    day1::_keyBrainstate
    brainstate::groupAddCheckbox
    steward::retiredStatus
    brainstate::sortRetired
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::Show
    day1::_keyDay
    day2::_keyDay
    day2::swStart
    day1::swTotalActivity
    day2::swPause
    day2::swTotalActivity

Scripts used in this script	

Layouts used in this script	

    calcTotalNewRecord
    calcBrainstateTable
    calcTotalSelectedList

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CHUNK_recalculateTotal]	Parent Folder: [total]	
Script Name	CHUNK_recalculateGrandTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    seperateFromTotal
    seperateFromGrandtotal
    CHUNK_deleteRecordsTimeFromGrandtotal
    DeleteBrainstate
    DeleteBrainstateFromTotal
    CHUNK_deleteTotalOrGrandtotalRecord

Script Definition
Script Steps	

    #PURPOSE add selected record's time data to an existing grand total record
    #CHUNK USED BY DeleteBrainstate Script
    #CHUNK USED BY seperateFromTotal Script
    #CHUNK USED BY CHUNK_deleteRecordsTimeFromGrandtotal Script
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #A) BEGIN prepare records for update
    #
    #1 capture total record's ID number
    Sort Records [ Specified Sort Order: brainstate::groupAddCheckbox; descending brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $brainstateID; Value:brainstate::groupOfGroupID ]
    Set Variable [ $totalbrainstateID; Value:brainstate::groupID ]
    #
    #2 unflag grand total update
    Set Field [ brainstate::groupOfGroupUpdate; "" ]
    #
    #3 delete all its records which will include some of the time from the just separated record. (Now we are ready to create new grandtotal day records.)
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Perform Find [ ]
    #
    #4 double check to insure records to be deleted are the right records. (During testing all 900+ records where deleted from my database. I think what happened is the find came up with zero records and then displayed all the records in the database and the next step deleted them. This If check will prevent that from happening again if that is what happened. I have been unable to duplicate this massive error, so this might not be reason why all the records where deleted, but this is the only time when the database is told to delete all found records, rather than just one record, so I figure it must have been caused here.)
    If [ day2::_keyBrainstate = $brainstateID ]
    Delete All Records [ No dialog ]
    End If
    #
    #5 make a list of only the records to be added and the total record
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Perform Find [ ]
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number.
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CHUNK_recalculateGrandTotal script part A1."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 1
    #
    #
    #
    #6 link all records
    Sort Records [ Specified Sort Order: brainstate::groupType; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ Last ]
    Set Variable [ $brainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Set Field [ brainstate::groupOfGroupDisplayID; $brainstateDisplayID ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #A) END prepare records for update
    #
    #
    #
    #B) BEGIN add a merge record's ID# to the description of the new GRAND total record.
    #
    Loop
    #
    #1 make sure there is a record to be merged (this step will be important when this loop is repeated after the first record to be merged is omitted).
    Go to Record/Request/Page [ First ]
    If [ brainstate::_lockBrainstateID ≠ brainstate::groupOfGroupID ]
    #
    #2 capture merged ID number for GRAND total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    #
    #
    #
    #BEGIN finish
    Else If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new GRAND total record and all the records that will feed into it until they are separated.
    Exit Script [ ]
    #END finish
    #
    #
    #
    End If
    #
    #B) END add a merge record's ID# to the description of the new total record.
    #
    #
    #
    #C) BEGIN find merge record's related day records
    #
    #1 make a list of the first brainstate's day records in a new window
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    #
    #C) END find merge record's related day records
    #
    #
    #
    #D BEGIN no records found loop (this loop will either complete the merge process or find a merge record with related day records)
    #
    Loop
    #
    #1 if records are found exit loop
    Exit Loop If [ Get ( LastError ) = 0 ]
    #
    #2 clear the merge field (the big X in the box on the ToBeMerged layout) and omit this record
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Omit Record
    #
    #
    #
    #BEGIN finish
    If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new GRAND total record and all the records that will feed into it until they are separated.
    Exit Script [ ]
    End If
    #END finish
    #
    #
    #
    #BEGIN find error 2
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CHUNK_recalculateGrandTotal script part D2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 2
    #
    #
    #
    #3 capture next records ID number for total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    #
    #4 make a list of this record's day records in a new window.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    End Loop
    #
    #D END no records found loop
    #
    #
    #
    #E BEGIN create new related day records and add selected record's time to them
    #
    Loop
    #1 find any day records for the new brainstate that match the kfDay of the first merge record. If this new record already has data in it, then we want to add new data to the old data; not replace the old data with new data.
    Set Variable [ $mergeDay; Value:day1::_keyDay ]
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Perform Find [ ]
    #
    #2 if no matches are found, create a new day record and put in the time of the first the current day record
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & $TotalActivity ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    #
    #
    #
    #BEGIN find error 3
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming CHUNK_recalculateGrandTotal script part E2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button.
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    #END find error 3
    #
    #
    #
    #3 if a match is found, then add the current day's time to this day's time.
    Else If [ Get ( LastError ) = 0 ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    End If
    #
    #4 repeat loop for found record's next related day record.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #E END create new related day records and add selected record's time to them
    #
    #
    #
    #F BEGIN go to next record with related day records to be added to the new total record.
    #
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #Clear the merge field (the big X in the box on the ToBeMerged layout).
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Omit Record
    #
    #F END go to next record with related day records to be added to the new total record.
    #
    #
    #
    End Loop

Fields used in this script	

    reference::farmerID
    brainstate::groupAddCheckbox
    brainstate::groupType
    brainstate::groupOfGroupID
    brainstate::groupID
    brainstate::groupOfGroupUpdate
    day2::_keyBrainstate
    steward::retiredStatus
    brainstate::sortRetired
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::Show
    brainstate::_Number
    brainstate::groupOfGroupDisplayID
    brainstate::_lockBrainstateID
    day1::_keyBrainstate
    brainstate::groupOfGroupAddCheckbox
    day1::_keyDay
    day2::_keyDay
    day2::swStart
    day1::swTotalActivity
    day2::swPause
    day2::swTotalActivity

Scripts used in this script	

Layouts used in this script	

    calcTotalNewRecord
    calcBrainstateTable
    calcTotalSelectedList

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


triggered scripts
	Parent Folder: [triggered scripts]	Next Script: [linkGrandDeny]
Script Name	linkDeny
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE on the total up layout there is a box for the user to click into to choose a record to be part of a new total record. This script runs a test to see if the user may include the record chosen. The reason behind this test is to prevent the user from replacing an already linked-to-a-total-record's link information in the form of that total record's ID currently in this linked record's linkID field. While it might be nice to allow the user to count one record as part of several totals, the current design does not allow this.
    #
    #
    #
    #1 check to insure record is not itself a total record. (Replacing the linkID would turn this record into a normal record and stop it from functioning as a total of it's currently linked records time.)
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    Clear [ ] [ Select ]
    Show Custom Dialog [ Title: "!"; Message: "This is a total record. You may create a grand total of two or more totals, or you can click the underlined number to the far right to open the screen that will allow you to make this total record a non-total record."; Buttons: “OK” ]
    Go to Field [ ]
    Halt Script
    End If
    #
    #2 check to insure record is not linked to a total record. (Replacing the linkID would route all future time changes to be summed in the new total record the user is trying to create.)
    If [ brainstate::groupID ≠ "" ]
    Clear [ ] [ Select ]
    Show Custom Dialog [ Title: "!"; Message: "This record is part of another total record and cannot be included in this total unless you click on the underlined button to the far left that opens up a new screen, and then click on the separate button on that new screen."; Buttons: “OK” ]
    Go to Field [ ]
    End If

Fields used in this script	

    brainstate::_lockBrainstateID
    brainstate::groupID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [linkDeny]	Parent Folder: [triggered scripts]	Next Script: [addToLinkDeny]
Script Name	linkGrandDeny
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE on the total up layout there is a box for the user to click into to choose a record to be part of a new grand total record. This script runs a test to see if the user may include the record chosen. The reason behind this test is to prevent the user from replacing an already linked-to-a-grand-total-record's link information in the form of that grand total record's ID currently in this linked record's linkID field. While it might be nice to allow the user to count one record as part of several grand totals, the current design does not allow this. So until it is changed, the user must be prevented from unlinking a record while creating a new total record. The second purpose is to insure that only total records are included in grand totals. This insures that no normal record is part of a total and part of the same grand total that its total record is a part of, which cause double counting the normal record's time in the grand total.
    #
    #
    #
    #1 check to insure that the record is not part of another grand total record.
    If [ brainstate::groupOfGroupID ≠ "" ]
    Clear [ ] [ Select ]
    Show Custom Dialog [ Title: "!"; Message: "This record is part of another grand total record (or is one) and cannot be included in another grand total."; Buttons: “OK” ]
    Go to Field [ ]
    End If
    #
    #2 check to insure that the record is a total record.
    If [ brainstate::_lockBrainstateID ≠ brainstate::groupID ]
    Clear [ ] [ Select ]
    Show Custom Dialog [ Title: "!"; Message: "Only total records may be selected to create a grand total record."; Buttons: “OK” ]
    Go to Field [ ]
    Halt Script
    End If

Fields used in this script	

    brainstate::groupOfGroupID
    brainstate::_lockBrainstateID
    brainstate::groupID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [linkGrandDeny]	Parent Folder: [triggered scripts]	Next Script: [addToGrandtotalDeny]
Script Name	addToLinkDeny
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE on the add2total layout there is a box for the user to click into to choose a record to be part of a total record. This script runs a test to see if the user may include the record chosen. The reason behind this test is to prevent the user from replacing an already linked-to-a-total-record's link information in the form of that total record's ID currently in this linked record's linkID field. While it might be nice to allow the user to count one record as part of several totals, the current design does not allow this.
    #
    #
    #
    #1 check to insure record is not the total record being add to.
    If [ brainstate::groupAddCheckbox = "" and brainstate::groupType ≠ "" ]
    Set Field [ brainstate::groupAddCheckbox; "t" ]
    Go to Field [ ]
    Show Custom Dialog [ Title: "!"; Message: "Select available records to add to this total record or click the cancel button."; Buttons: “OK” ]
    Halt Script
    End If
    #
    #2 check to insure record is not itself a total record. (Replacing the linkID would turn this record into a normal record and stop it from functioning as a total of it's currently linked records time.)
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    Clear [ ] [ Select ]
    Show Custom Dialog [ Title: "!"; Message: "This is a total record. You may not make it part of the currently selected total record."; Buttons: “OK” ]
    Go to Field [ ]
    Halt Script
    End If
    #
    #3 check to insure record is not linked to another total record. (Replacing the linkID would route all future time changes to be summed in the new total record the user is trying to create.)
    If [ brainstate::groupID ≠ "" ]
    Clear [ ] [ Select ]
    Show Custom Dialog [ Title: "!"; Message: "This record is part of another total record and cannot be made part of this total record (unless you separate it from its total record)."; Buttons: “OK” ]
    Go to Field [ ]
    End If

Fields used in this script	

    brainstate::groupAddCheckbox
    brainstate::groupType
    brainstate::_lockBrainstateID
    brainstate::groupID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [addToLinkDeny]	Parent Folder: [triggered scripts]	
Script Name	addToGrandtotalDeny
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE on the add2grandtotal layout there is a box for the user to click into to choose a record to be part of a total record. This script runs a test to see if the user may include the record chosen. The reason behind this test is to prevent the user from replacing an already linked-to-a-total-record's link information in the form of that total record's ID currently in this linked record's linkID field. While it might be nice to allow the user to count one record as part of several totals, the current design does not allow this.
    #
    #
    #
    #1 check to insure record is not the total record being add to.
    If [ brainstate::groupOfGroupAddCheckbox = "" and brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "t" ]
    Go to Field [ ]
    Show Custom Dialog [ Title: "!"; Message: "Select available records to add to this grandtotal record or click the cancel button."; Buttons: “OK” ]
    Halt Script
    End If
    #
    #2 check to insure record is not itself a grandtotal record. (Replacing the linkID would turn this record into a normal record and stop it from functioning as a total of it's currently linked records time.)
    If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    Clear [ ] [ Select ]
    Show Custom Dialog [ Title: "!"; Message: "This is a grandtotal record. You may not make it part of the currently selected grandtotal record."; Buttons: “OK” ]
    Go to Field [ ]
    Halt Script
    End If
    #
    #3 check to insure record is not linked to another total record. (Replacing the linkID would route all future time changes to be summed in the new total record the user is trying to create.)
    If [ brainstate::groupOfGroupID ≠ "" ]
    Clear [ ] [ Select ]
    Show Custom Dialog [ Title: "!"; Message: "This record is part of another grandtotal record and cannot be made part of this grandtotal record (unless you separate it from its current grandtotal record first)."; Buttons: “OK” ]
    Go to Field [ ]
    End If

Fields used in this script	

    brainstate::groupOfGroupAddCheckbox
    brainstate::_lockBrainstateID
    brainstate::groupOfGroupID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


action buttons
	Parent Folder: [action buttons]	Next Script: [newTotal]
Script Name	total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE merge selected record's time data into one total record and then link these records so that time added in the future to any of the merge records will be automatically added to the one total record.
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #A) BEGIN find selected merge records and create new total record and link all records together
    #
    #1 check if there are 1 or more records to merge and if not halt the script. (Can't merge if zero records are selected. 1 record can be merged which is really making a copy of that record for instances where the user has been tracking 2 things with one brainstate but now wants to separate the tracking of these with 2 separate brainstate records.)
    If [ brainstate::groupAddCheckboxCount < 1 ]
    Show Custom Dialog [ Title: "!"; Message: "At least 1 brainstates must be selected for a merge."; Buttons: “OK” ]
    Halt Script
    End If
    #
    #2 make a list of only the records to be merged
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::groupAddCheckbox; "t" ]
    Perform Find [ ]
    #
    #
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number.
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming merge script part A2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 1
    #
    #
    #
    #3 create the new total record
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    New Record/Request
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::linkinfo; "total of: " ]
    Set Field [ brainstate::description; "NEW TOTAL RECORD the ID numbers of the records totaled by this record can be seen by either clicking or hovering over the i at the far right of this description field." ]
    Set Field [ brainstate::groupType; "merge" ]
    #
    #4 link all records
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $brainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupID; $brainstateID ]
    Set Field [ brainstate::groupDisplayID; $brainstateDisplayID ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #A) END find selected merge records and create new total record and link all records together
    #
    #
    #
    Loop
    #B) BEGIN add a merge record's ID# to the description of the new total record.
    #
    #1 make sure there is a record to be merged (this step will be important when this loop is repeated after the first record to be merged is omitted).
    Go to Record/Request/Page [ First ]
    If [ brainstate::_lockBrainstateID ≠ brainstate::groupID ]
    #
    #2 capture merged ID number for total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; If ( WordCount ( brainstate::linkinfo ) = 2 ; brainstate::linkinfo & $CurrentBrainstateDisplayID ; brainstate::linkinfo & ", " & $CurrentBrainstateDisplayID ) ]
    Go to Record/Request/Page [ First ]
    #
    #
    #
    #BEGIN finish
    Else If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new total record and all the records that will feed into it until they are separated.
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “TotalSort” (brainstate) ]
    Go to Field [ ]
    Halt Script
    #END finish
    #
    #
    #
    End If
    #
    #B) END add a merge record's ID# to the description of the new total record.
    #
    #
    #
    #C BEGIN find merge record's related day records
    #
    #1 make a list of the first brainstate's day records in a new window
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    #
    #C END find merge record's related day records
    #
    #
    #
    #D BEGIN no records found loop (this loop will either complete the merge process or find a merge record with related day records)
    #
    Loop
    #
    #1 if records are found exit loop
    Exit Loop If [ Get ( LastError ) = 0 ]
    #
    #2 clear the merge field (the big X in the box on the ToBeMerged layout) and omit this record
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    Set Field [ brainstate::groupAddCheckbox; "" ]
    Omit Record
    #
    #
    #
    #BEGIN finish
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new total record and all the records that will feed into it until they are separated.
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “TotalSort” (brainstate) ]
    Go to Field [ ]
    Halt Script
    End If
    #END finish
    #
    #
    #
    #BEGIN find error 2
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming merge script part D2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 2
    #
    #
    #
    #3 capture next records ID number for total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; If ( WordCount ( brainstate::linkinfo ) = 2 ; brainstate::linkinfo & $CurrentBrainstateDisplayID ; brainstate::linkinfo & ", " & $CurrentBrainstateDisplayID ) ]
    Go to Record/Request/Page [ First ]
    #
    #4 make a list of this record's day records in a new window.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    End Loop
    #
    #D END no records found loop
    #
    #
    #
    #E BEGIN create new related day records and add selected record's time to them
    #
    Loop
    #1 find any day records for the new brainstate that match the kfDay of the first merge record. If this new record already has data in it, then we want to add new data to the old data; not replace the old data with new data.
    Set Variable [ $mergeDay; Value:day1::_keyDay ]
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Perform Find [ ]
    #
    #2 if no matches are found, create a new day record and put in the time of the first the current day record
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & $TotalActivity ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    #
    #
    #
    #BEGIN find error 3
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming merge script part E2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button.
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    #END find error 3
    #
    #
    #
    #3 if a match is found, then add the current day's time to this day's time.
    Else If [ Get ( LastError ) = 0 ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    End If
    #
    #4 repeat loop for found record's next related day record.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #E END create new related day records and add selected record's time to them
    #
    #
    #
    #F BEGIN go to next record with related day records to be added to the new total record.
    #
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    #Clear the merge field (the big X in the box on the ToBeMerged layout).
    Set Field [ brainstate::groupAddCheckbox; "" ]
    Omit Record
    #
    #F END go to next record with related day records to be added to the new total record.
    #
    #
    #
    End Loop

Fields used in this script	

    reference::farmerID
    brainstate::groupAddCheckboxCount
    brainstate::_keyUser
    brainstate::groupAddCheckbox
    steward::retiredStatus
    brainstate::sortRetired
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::Show
    brainstate::linkinfo
    brainstate::description
    brainstate::groupType
    brainstate::_lockBrainstateID
    brainstate::_Number
    brainstate::groupID
    brainstate::groupDisplayID
    day1::_keyBrainstate
    day1::_keyDay
    day2::_keyBrainstate
    day2::_keyDay
    day2::swStart
    day1::swTotalActivity
    day2::swPause
    day2::swTotalActivity

Scripts used in this script	

Layouts used in this script	

    01SortAndSchedule
    TotalSort
    calcTotalSelectedList
    calcTotalNewRecord

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [total]	Parent Folder: [action buttons]	Next Script: [grandTotal]
Script Name	newTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE create a new total record
    #
    #
    #
    #basic administration tasks
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #1 create the new total record
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “TotalSortAndScheduleiPhone” (brainstate) ]
    Else If [ Get ( SystemPlatform ) ≠ 3 or steward::iPhoneLayout = "" ]
    Go to Layout [ “TotalSort” (brainstate) ]
    End If
    #END NOT TESTED
    New Record/Request
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::linkinfo; "total of: " ]
    Set Field [ brainstate::description; "new total record / folder name" ]
    Set Field [ brainstate::groupType; "merge" ]
    Set Field [ brainstate::groupDisplayID; brainstate::_Number ]
    Set Field [ brainstate::Show; "t" ]
    Set Field [ brainstate::hide; "t" ]
    Set Field [ brainstate::groupID; brainstate::_lockBrainstateID ]
    Set Variable [ $mergeID; Value:brainstate::_lockBrainstateID ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $mergeID ]
    Perform Find [ ]
    Go to Field [ brainstate::description ] [ Select/perform ]

Fields used in this script	

    reference::farmerID
    steward::iPhoneLayout
    brainstate::_keyUser
    brainstate::linkinfo
    brainstate::description
    brainstate::groupType
    brainstate::_Number
    brainstate::groupDisplayID
    brainstate::Show
    brainstate::hide
    brainstate::_lockBrainstateID
    brainstate::groupID

Scripts used in this script	

Layouts used in this script	

    TotalSortAndScheduleiPhone
    TotalSort

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newTotal]	Parent Folder: [action buttons]	Next Script: [addToTotalPart1]
Script Name	grandTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE merge selected record's time data into one GRAND total record and then link these records so that time added in the future to any of the merge records will be automatically added to the one total record.
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #A) BEGIN find selected GRAND total records and create new total record and link all records together
    #
    #1 check if there are 2 or more records to merge and if not halt the script. (Can't merge if zero or 1 records are selected.
    If [ brainstate::groupOfGroupAddCheckboxCount < 2 ]
    Show Custom Dialog [ Title: "!"; Message: "At least 2 total records must be selected to create a grand total record."; Buttons: “OK” ]
    Halt Script
    End If
    #
    #2 make a list of only the records to be merged
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "t" ]
    Perform Find [ ]
    #
    #
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number.
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming grand total merge script part A2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 1
    #
    #
    #
    #3 create the new total record
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    New Record/Request
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::description; "NEW GRAND TOTAL RECORD the ID numbers of the records totaled by this record can be seen by either clicking or hovering over the i at the far right of this description field." ]
    Set Field [ brainstate::linkinfo; "grand total of: " ]
    Set Field [ brainstate::groupType; "mergeGrand" ]
    #
    #4 link all records
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $brainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Set Field [ brainstate::groupOfGroupDisplayID; $brainstateDisplayID ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #A) END find selected merge records and create new GRAND total record and link all records together
    #
    #
    #
    Loop
    #B) BEGIN add a merge record's ID# to the description of the new GRAND total record.
    #
    #1 make sure there is a record to be merged (this step will be important when this loop is repeated after the first record to be merged is omitted).
    Go to Record/Request/Page [ First ]
    If [ brainstate::_lockBrainstateID ≠ brainstate::groupOfGroupID ]
    #
    #2 capture merged ID number for GRAND total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; If ( WordCount ( brainstate::linkinfo ) = 3 ; brainstate::linkinfo & $CurrentBrainstateDisplayID ; brainstate::linkinfo & ", " & $CurrentBrainstateDisplayID ) ]
    Go to Record/Request/Page [ First ]
    #
    #
    #
    #BEGIN finish
    Else If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new GRAND total record and all the records that will feed into it until they are separated.
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “GrandTotal” (brainstate) ]
    Go to Field [ ]
    Halt Script
    #END finish
    #
    #
    #
    End If
    #
    #B) END add a merge record's ID# to the description of the new total record.
    #
    #
    #
    #C BEGIN find merge record's related day records
    #
    #1 make a list of the first brainstate's day records in a new window
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    #
    #C END find merge record's related day records
    #
    #
    #
    #D BEGIN no records found loop (this loop will either complete the merge process or find a merge record with related day records)
    #
    Loop
    #
    #1 if records are found exit loop
    Exit Loop If [ Get ( LastError ) = 0 ]
    #
    #2 clear the merge field (the big X in the box on the ToBeMerged layout) and omit this record
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Omit Record
    #
    #
    #
    #BEGIN finish
    If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new GRAND total record and all the records that will feed into it until they are separated.
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “GrandTotal” (brainstate) ]
    Go to Field [ ]
    Halt Script
    End If
    #END finish
    #
    #
    #
    #BEGIN find error 2
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming grand total merge script part D2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 2
    #
    #
    #
    #3 capture next records ID number for total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; If ( WordCount ( brainstate::linkinfo ) = 3 ; brainstate::linkinfo & $CurrentBrainstateDisplayID ; brainstate::linkinfo & ", " & $CurrentBrainstateDisplayID ) ]
    Go to Record/Request/Page [ First ]
    #
    #4 make a list of this record's day records in a new window.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    End Loop
    #
    #D END no records found loop
    #
    #
    #
    #E BEGIN create new related day records and add selected record's time to them
    #
    Loop
    #1 find any day records for the new brainstate that match the kfDay of the first merge record. If this new record already has data in it, then we want to add new data to the old data; not replace the old data with new data.
    Set Variable [ $mergeDay; Value:day1::_keyDay ]
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Perform Find [ ]
    #
    #2 if no matches are found, create a new day record and put in the time of the first the current day record
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & $TotalActivity ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    #
    #
    #
    #BEGIN find error 3
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming grand total merge script part E2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button.
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    #END find error 3
    #
    #
    #
    #3 if a match is found, then add the current day's time to this day's time.
    Else If [ Get ( LastError ) = 0 ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    End If
    #
    #4 repeat loop for found record's next related day record.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #E END create new related day records and add selected record's time to them
    #
    #
    #
    #F BEGIN go to next record with related day records to be added to the new total record.
    #
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    #Clear the merge field (the big X in the box on the ToBeMerged layout).
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Omit Record
    #
    #F END go to next record with related day records to be added to the new total record.
    #
    #
    #
    End Loop

Fields used in this script	

    reference::farmerID
    brainstate::groupOfGroupAddCheckboxCount
    brainstate::_keyUser
    brainstate::groupOfGroupAddCheckbox
    steward::retiredStatus
    brainstate::sortRetired
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::Show
    brainstate::description
    brainstate::linkinfo
    brainstate::groupType
    brainstate::_lockBrainstateID
    brainstate::_Number
    brainstate::groupOfGroupID
    brainstate::groupOfGroupDisplayID
    day1::_keyBrainstate
    day1::_keyDay
    day2::_keyBrainstate
    day2::_keyDay
    day2::swStart
    day1::swTotalActivity
    day2::swPause
    day2::swTotalActivity

Scripts used in this script	

Layouts used in this script	

    01SortAndSchedule
    GrandTotal
    calcTotalSelectedList
    calcTotalNewRecord

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [grandTotal]	Parent Folder: [action buttons]	Next Script: [addToTotalPart2]
Script Name	addToTotalPart1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE create list of records that can be added to the current total record.
    #
    #
    #
    #1 constrain the current records being viewed to just the total record and mark it for adding. (This finding of the record to be marked could also be done with a sort.)
    Constrain Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::groupType: “merge” ] [ Restore ]
    Set Field [ brainstate::groupAddCheckbox; "t" ]
    #
    #2 go to the add2total layout and find all the users records excluding total and grandtotal records. (The list should include only records that could be added to the total.)
    Go to Layout [ “add2total” (brainstate) ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::groupType: “merge” ] [ Restore ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::groupID: “>1” ] [ Restore ]
    Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::groupAddCheckbox: “t” ] [ Restore ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::description: “=” ] [ Restore ]

Fields used in this script	

    brainstate::groupType
    brainstate::groupAddCheckbox
    reference::farmerID
    brainstate::_keyUser
    brainstate::groupID
    brainstate::description

Scripts used in this script	

Layouts used in this script	

    add2total

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [addToTotalPart1]	Parent Folder: [action buttons]	Next Script: [addToGrandtotalPart1]
Script Name	addToTotalPart2
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE add selected records' time data into current total record and then link these records so that time added in the future to any of them will be automatically added to this total record.
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #A) BEGIN find selected records to add and link to total record
    #
    #1 check if there are 1 or more records to merge and if not halt the script. (Can't merge if zero records are selected. 1 record can be merged which is really making a copy of that record for instances where the user has been tracking 2 things with one brainstate but now wants to separate the tracking of these with 2 separate brainstate records.)
    If [ brainstate::groupAddCheckboxCount < 2 ]
    Show Custom Dialog [ Title: "!"; Message: "At least 1 brainstates must be selected to add to the total record (highlighted light blue)."; Buttons: “OK” ]
    Halt Script
    End If
    #
    #2 capture total record's ID number
    Sort Records [ Specified Sort Order: brainstate::groupAddCheckbox; descending brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $mergeto; Value:brainstate::groupID ]
    #
    #3 flag for grand total update
    Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
    #
    #4 make a list of only the records to be added and the total record
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::groupAddCheckbox; "t" ]
    Perform Find [ ]
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number.
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming add to total part 2 script part A2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 1
    #
    #
    #
    #5 link all records and remove t's from merge fields clear the merge field (the big X in the box on the ToBeMerged layout)
    Sort Records [ Specified Sort Order: brainstate::groupType; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ Last ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $brainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupID; $brainstateID ]
    Set Field [ brainstate::groupDisplayID; $brainstateDisplayID ]
    Set Field [ brainstate::groupAddCheckbox; "" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #A) END find selected records to add and link to total record
    #
    #
    #
    Loop
    #B) BEGIN add a merge record's ID# to the description of the new total record.
    #
    #1 make sure there is a record to be merged (this step will be important when this loop is repeated after the first record to be merged is omitted).
    Go to Record/Request/Page [ First ]
    If [ brainstate::_lockBrainstateID ≠ brainstate::groupID ]
    #
    #2 capture merged ID number for total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentDate ) & " added: " & $CurrentBrainstateDisplayID ]
    Go to Record/Request/Page [ First ]
    #
    #
    #
    #BEGIN finish
    Else If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new total record and all the records that will feed into it until they are separated.
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “TotalEditTime” (brainstate) ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 ]
    Go to Layout [ “TotalMainiPhone” (brainstate) ]
    End If
    #END NOT TESTED
    Go to Field [ ]
    If [ brainstate::groupOfGroupUpdate = "u" ]
    Perform Script [ “CHUNK addToTotalPart3” ]
    End If
    Perform Script [ “DaySelectSortThenSort” ]
    Halt Script
    #END finish
    #
    #
    #
    End If
    #
    #B) END add a merge record's ID# to the description of the new total record.
    #
    #
    #
    #C BEGIN find merge record's related day records
    #
    #1 make a list of the first brainstate's day records in a new window
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    #
    #C END find merge record's related day records
    #
    #
    #
    #D BEGIN no records found loop (this loop will either complete the merge process or find a merge record with related day records)
    #
    Loop
    #
    #1 if records are found exit loop
    Exit Loop If [ Get ( LastError ) = 0 ]
    #
    #2 omit this record
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    Omit Record
    #
    #
    #
    #BEGIN finish
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new total record and all the records that will feed into it until they are separated.
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “TotalSort” (brainstate) ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 ]
    Go to Layout [ “TotalMainiPhone” (brainstate) ]
    End If
    #END NOT TESTED
    Go to Field [ ]
    If [ brainstate::groupOfGroupUpdate = "u" ]
    Perform Script [ “CHUNK addToTotalPart3” ]
    End If
    Perform Script [ “DaySelectSortThenSort” ]
    Halt Script
    End If
    #END finish
    #
    #
    #
    #BEGIN find error 2
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming merge script part D2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 2
    #
    #
    #
    #3 capture next records ID number for total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; "¶¶" & Get ( CurrentDate ) & " added: " & $CurrentBrainstateDisplayID ]
    Go to Record/Request/Page [ First ]
    #
    #4 make a list of this record's day records in a new window.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    End Loop
    #
    #D END no records found loop
    #
    #
    #
    #E BEGIN create new related day records and add selected record's time to them
    #
    Loop
    #1 find any day records for the new brainstate that match the kfDay of the first merge record. If this new record already has data in it, then we want to add new data to the old data; not replace the old data with new data.
    Set Variable [ $mergeDay; Value:day1::_keyDay ]
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Perform Find [ ]
    #
    #2 if no matches are found, create a new day record and put in the time of the first the current day record
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & $TotalActivity ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    #
    #
    #
    #BEGIN find error 3
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming merge script part E2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button.
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    #END find error 3
    #
    #
    #
    #3 if a match is found, then add the current day's time to this day's time.
    Else If [ Get ( LastError ) = 0 ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    End If
    #
    #4 repeat loop for found record's next related day record.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #E END create new related day records and add selected record's time to them
    #
    #
    #
    #F BEGIN go to next record with related day records to be added to the new total record.
    #
    Go to Layout [ “TotalSort” (brainstate) ]
    #Clear the merge field (the big X in the box on the ToBeMerged layout).
    Set Field [ brainstate::groupAddCheckbox; "" ]
    Omit Record
    #
    #F END go to next record with related day records to be added to the new total record.
    #
    #
    #
    End Loop

Fields used in this script	

    reference::farmerID
    brainstate::groupAddCheckboxCount
    brainstate::groupAddCheckbox
    brainstate::groupType
    brainstate::groupID
    brainstate::groupOfGroupID
    brainstate::groupOfGroupUpdate
    brainstate::_keyUser
    steward::retiredStatus
    brainstate::sortRetired
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::Show
    brainstate::_lockBrainstateID
    brainstate::_Number
    brainstate::groupDisplayID
    brainstate::linkinfo
    day1::_keyBrainstate
    day1::_keyDay
    day2::_keyBrainstate
    day2::_keyDay
    day2::swStart
    day1::swTotalActivity
    day2::swPause
    day2::swTotalActivity

Scripts used in this script	

    CHUNK addToTotalPart3
    DaySelectSortThenSort

Layouts used in this script	

    TotalEditTime
    TotalMainiPhone
    calcTotalSelectedList
    01SortAndSchedule
    TotalSort
    calcTotalNewRecord

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [addToTotalPart2]	Parent Folder: [action buttons]	Next Script: [addToGrandtotalPart2]
Script Name	addToGrandtotalPart1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE create list of records that can be added to the current grandtotal record.
    #
    #
    #
    #1 constrain the current records being viewed to just the grandtotal record and mark it for adding. (This finding of the record to be marked could also be done with a sort.)
    Constrain Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::groupType: “mergeGrand” ] [ Restore ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "t" ]
    #
    #2 go to the add2total layout and find all the users total records. (The list should inlcude only records that could be added to the grandtotal.)
    Go to Layout [ “add2grandtotal” (brainstate) ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::groupType; "merge" ]
    Perform Find [ ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::groupType: “mergeGrand” ] [ Restore ]
    Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::groupOfGroupAddCheckbox: “t” ] [ Restore ]

Fields used in this script	

    brainstate::groupType
    brainstate::groupOfGroupAddCheckbox
    reference::farmerID
    brainstate::_keyUser

Scripts used in this script	

Layouts used in this script	

    add2grandtotal

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [addToGrandtotalPart1]	Parent Folder: [action buttons]	Next Script: [cancelTotal]
Script Name	addToGrandtotalPart2
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE add selected records' time data into current grandtotal record and then link these records so that time added in the future to any of them will be automatically added to this grandtotal record.
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #A) BEGIN find selected records to add and link to total record
    #
    #1 check if there are 1 or more records to merge and if not halt the script. (Can't merge if zero records are selected. 1 record can be merged which is really making a copy of that record for instances where the user has been tracking 2 things with one brainstate but now wants to separate the tracking of these with 2 separate brainstate records.)
    If [ brainstate::groupOfGroupAddCheckboxCount < 2 ]
    Show Custom Dialog [ Title: "!"; Message: "At least 1 brainstate must be selected to add to the grandtotal record (highlighted light blue)."; Buttons: “OK” ]
    Halt Script
    End If
    #
    #2 capture total record's ID number
    Sort Records [ Specified Sort Order: brainstate::groupAddCheckbox; descending brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $mergeto; Value:brainstate::groupOfGroupID ]
    #
    #4 make a list of only the records to be added and the total record
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "t" ]
    Perform Find [ ]
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number.
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming add to total part 2 script part A2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 1
    #
    #
    #
    #5 link all records and remove t's from merge fields clear the merge field (the big X in the box on the ToBeMerged layout)
    Sort Records [ Specified Sort Order: brainstate::groupType; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ Last ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $brainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Set Field [ brainstate::groupOfGroupDisplayID; $brainstateDisplayID ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #A) END find selected records to add and link to total record
    #
    #
    #
    Loop
    #B) BEGIN add a merge record's ID# to the description of the new GRAND total record.
    #
    #1 make sure there is a record to be merged (this step will be important when this loop is repeated after the first record to be merged is omitted).
    Go to Record/Request/Page [ First ]
    If [ brainstate::_lockBrainstateID ≠ brainstate::groupOfGroupID ]
    #
    #2 capture merged ID number for GRAND total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentTimeStamp ) & " Added: " & $CurrentBrainstateDisplayID ]
    Go to Record/Request/Page [ First ]
    #
    #
    #
    #BEGIN finish
    Else If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new GRAND total record and all the records that will feed into it until they are separated.
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “GrandTotal” (brainstate) ]
    Go to Field [ ]
    Halt Script
    #END finish
    #
    #
    #
    End If
    #
    #B) END add a merge record's ID# to the description of the new total record.
    #
    #
    #
    #C BEGIN find merge record's related day records
    #
    #1 make a list of the first brainstate's day records in a new window
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    #
    #C END find merge record's related day records
    #
    #
    #
    #D BEGIN no records found loop (this loop will either complete the merge process or find a merge record with related day records)
    #
    Loop
    #
    #1 if records are found exit loop
    Exit Loop If [ Get ( LastError ) = 0 ]
    #
    #2 clear the merge field (the big X in the box on the ToBeMerged layout) and omit this record
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Omit Record
    #
    #
    #
    #BEGIN finish
    If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the new GRAND total record and all the records that will feed into it until they are separated.
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “GrandTotal” (brainstate) ]
    Go to Field [ ]
    Halt Script
    End If
    #END finish
    #
    #
    #
    #BEGIN find error 2
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming grand total merge script part D2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 2
    #
    #
    #
    #3 capture next records ID number for total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentTimeStamp ) & " Added: " & $CurrentBrainstateDisplayID ]
    Go to Record/Request/Page [ First ]
    #
    #4 make a list of this record's day records in a new window.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    End Loop
    #
    #D END no records found loop
    #
    #
    #
    #E BEGIN create new related day records and add selected record's time to them
    #
    Loop
    #1 find any day records for the new brainstate that match the kfDay of the first merge record. If this new record already has data in it, then we want to add new data to the old data; not replace the old data with new data.
    Set Variable [ $mergeDay; Value:day1::_keyDay ]
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Perform Find [ ]
    #
    #2 if no matches are found, create a new day record and put in the time of the first the current day record
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & $TotalActivity ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    #
    #
    #
    #BEGIN find error 3
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming grand total merge script part E2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button.
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    #END find error 3
    #
    #
    #
    #3 if a match is found, then add the current day's time to this day's time.
    Else If [ Get ( LastError ) = 0 ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    End If
    #
    #4 repeat loop for found record's next related day record.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #E END create new related day records and add selected record's time to them
    #
    #
    #
    #F BEGIN go to next record with related day records to be added to the new total record.
    #
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    #Clear the merge field (the big X in the box on the ToBeMerged layout).
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Omit Record
    #
    #F END go to next record with related day records to be added to the new total record.
    #
    #
    #
    End Loop

Fields used in this script	

    reference::farmerID
    brainstate::groupOfGroupAddCheckboxCount
    brainstate::groupAddCheckbox
    brainstate::groupType
    brainstate::groupOfGroupID
    brainstate::_keyUser
    brainstate::groupOfGroupAddCheckbox
    steward::retiredStatus
    brainstate::sortRetired
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::Show
    brainstate::_lockBrainstateID
    brainstate::_Number
    brainstate::groupOfGroupDisplayID
    brainstate::linkinfo
    day1::_keyBrainstate
    day1::_keyDay
    day2::_keyBrainstate
    day2::_keyDay
    day2::swStart
    day1::swTotalActivity
    day2::swPause
    day2::swTotalActivity

Scripts used in this script	

Layouts used in this script	

    GrandTotal
    calcTotalSelectedList
    01SortAndSchedule
    calcTotalNewRecord

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [addToGrandtotalPart2]	Parent Folder: [action buttons]	Next Script: [cancelAddToTotal]
Script Name	cancelTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE clear the Xs from the boxes on the add2total layout and then return to the layout they where on
    #
    #
    #
    #1 clear the Xs from the boxes on the add2total layout and then return to the layout they were on
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupAddCheckbox; "" ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    Perform Script [ “goBackButton” ]

Fields used in this script	

    brainstate::groupAddCheckbox
    brainstate::groupOfGroupAddCheckbox

Scripts used in this script	

    goBackButton

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [cancelTotal]	Parent Folder: [action buttons]	Next Script: [cancelAddToGrandtotal]
Script Name	cancelAddToTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE clear the Xs from the boxes on the add2total layout and then return to the totalview layout
    #
    #
    If [ Get ( WindowMode ) = 1 ]
    Exit Script [ ]
    End If
    #
    #1 capture total record's ID
    Sort Records [ Specified Sort Order: brainstate::groupAddCheckbox; descending brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    #
    #2 clear the Xs from the boxes on the add2total layout
    Loop
    Set Field [ brainstate::groupAddCheckbox; "" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #3 return to viewtotal layout
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “TotalSort” (brainstate) ]
    Go to Field [ ]

Fields used in this script	

    brainstate::groupAddCheckbox
    brainstate::groupType
    brainstate::_lockBrainstateID
    brainstate::groupID

Scripts used in this script	

Layouts used in this script	

    TotalSort

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [cancelAddToTotal]	Parent Folder: [action buttons]	Next Script: [seperateFromTotal]
Script Name	cancelAddToGrandtotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE clear the Xs from the boxes on the add2grandtotal layout and then return to the grandtotalview layout
    #
    #
    #
    #
    #1 capture total record's ID
    Sort Records [ Specified Sort Order: brainstate::groupOfGroupAddCheckbox; descending brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    #
    #2 clear the Xs from the boxes on the add2grandtotal layout
    Loop
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #3 return to viewgrandtotal layout
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “GrandTotal” (brainstate) ]
    Go to Field [ ]

Fields used in this script	

    brainstate::groupOfGroupAddCheckbox
    brainstate::groupType
    brainstate::_lockBrainstateID
    brainstate::groupOfGroupID

Scripts used in this script	

Layouts used in this script	

    GrandTotal

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [cancelAddToGrandtotal]	Parent Folder: [action buttons]	Next Script: [seperateFromGrandtotal]
Script Name	seperateFromTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE check to insure the record is linked and then delete this link, thus separating it.
    #
    #
    #
    #1 check to if record is the total record and if so stop the script.
    If [ brainstate::groupID = brainstate::_lockBrainstateID ]
    Halt Script
    End If
    #
    #2 delete the link, capture recordID and description (to update total info) and omit the record from the set of linked records currently being viewed.
    Set Field [ brainstate::groupID; "" ]
    Set Field [ brainstate::groupDisplayID; "" ]
    Set Field [ brainstate::hide; "t" ]
    Set Variable [ $separateID; Value:brainstate::_Number ]
    Set Variable [ $description; Value:brainstate::description ]
    Set Variable [ $layout; Value:Get ( LayoutName ) ]
    Omit Record
    #
    #DISABLE: I thought this was a good idea to delete total records that nothing to total for the user. But after thinking about it, I now think I should allow the user to do this. There is no harm in having a non-working total record. It can always be used again by adding records to it to total, or by turning it into a regular record.
    // #3 determine if user has deleted all records to total
    // If [ Get ( FoundCount ) = 1 and brainstate::_lockBrainstateID = brainstate::groupID ]
    // #
    // #4 capture total record's mergeID
    // Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    // #
    // #5 flag for grand total update
    // Perform Script [ “CHUNK_deleteRecordsTimeFromGrandtotal” ]
    // If [ brainstate::groupOfGroupID ≠ "" ]
    // Set Field [ brainstate::groupOfGroupUpdate; "u" ]
    // End If
    // #
    // #6 tell user this record is being deleted and why.
    // Go to Layout [ <unknown> ]
    // Show Custom Dialog [ Title: "!"; Message: "This total record has no more records to total and so it is being deleted. You can always re-create it by clicking the total button."; Buttons: “OK” ]
    // Delete Record/Request [ No dialog ]
    // Perform Script [ “goBackButton” ]
    // Halt Script
    // End If
    #
    #3 note in the info box which record was separated and when and then capture the ID so the linked records be found at the end of the script
    Sort Records [ Specified Sort Order: brainstate::groupType; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentTimeStamp ) & " Separated: " & $separateID & " " & $description ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    #
    #4 flag for grand total update
    Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
    #
    #5 recalculate total to subtract the separated record's time from it
    Perform Script [ “CHUNK_recalculateTotal” ]
    #
    #6 update grandtotal if this record was also part of a grandtotal
    If [ brainstate::groupOfGroupUpdate = "u" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupUpdate; "u" ]
    Perform Find [ ]
    Perform Script [ “CHUNK_recalculateGrandTotal” ]
    End If
    #
    #7 return user to viewtotal layout and show remaining linked records
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Go to Layout [ $layout ]
    Perform Script [ “DaySelectSortThenSort” ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]

Fields used in this script	

    brainstate::groupID
    brainstate::_lockBrainstateID
    brainstate::groupDisplayID
    brainstate::hide
    brainstate::_Number
    brainstate::description
    brainstate::groupOfGroupID
    brainstate::groupOfGroupUpdate
    brainstate::groupType
    brainstate::linkinfo

Scripts used in this script	

    CHUNK_deleteRecordsTimeFromGrandtotal
    goBackButton
    CHUNK_recalculateTotal
    CHUNK_recalculateGrandTotal
    DaySelectSortThenSort

Layouts used in this script	

    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [seperateFromTotal]	Parent Folder: [action buttons]	Next Script: [newLinkedRecord]
Script Name	seperateFromGrandtotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE check to insure the record is linked and then delete this link. If it is not linked stop the script. This check is neccessary because filemaker allows the link button that activitates this script to be hidden but not deactivited, and it should not run if there are no records for it to find and display.
    #
    #
    #
    #1 check to if record is the grandtotal record and if so stop the script.
    If [ brainstate::groupOfGroupID = brainstate::_lockBrainstateID ]
    Halt Script
    End If
    #
    #2 delete the link and omit the record from the set of linked records currently being viewed.
    Set Variable [ $separateID; Value:brainstate::_Number ]
    Set Variable [ $description; Value:brainstate::description ]
    Set Field [ brainstate::groupOfGroupID; "" ]
    Set Field [ brainstate::groupOfGroupDisplayID; "" ]
    Omit Record
    #
    #3 note in the info box which record was separated and when and then capture the ID so the linked records be found at the end of the script
    Sort Records [ Specified Sort Order: brainstate::groupType; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ Last ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentTimeStamp ) & " Separated: " & $separateID & " " & $description ]
    Set Variable [ $grandID; Value:brainstate::_lockBrainstateID ]
    #
    #5 recalculate grandtotal to subtract the separated record's time from it
    Perform Script [ “CHUNK_recalculateGrandTotal” ]
    #
    #6 return user to viewgrandtotal layout and show remaining linked records
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $grandID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::groupType; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “GrandTotal” (brainstate) ]
    Go to Field [ ]

Fields used in this script	

    brainstate::groupOfGroupID
    brainstate::_lockBrainstateID
    brainstate::_Number
    brainstate::description
    brainstate::groupOfGroupDisplayID
    brainstate::groupType
    brainstate::linkinfo

Scripts used in this script	

    CHUNK_recalculateGrandTotal

Layouts used in this script	

    GrandTotal

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [seperateFromGrandtotal]	Parent Folder: [action buttons]	
Script Name	newLinkedRecord
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE create a new record and link it to an existing total record
    #
    #
    #
    #1 capture the user's and total record's ID numbers
    Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Set Variable [ $MergeID; Value:brainstate::groupID ]
    Set Variable [ $MergeDisplayID; Value:brainstate::groupDisplayID ]
    #
    #2 create new record
    New Record/Request
    #
    #3 assign record to the user
    Set Field [ brainstate::_keyUser; $userID ]
    #
    #4 link record to the total record
    Set Field [ brainstate::groupID; $MergeID ]
    Set Field [ brainstate::groupDisplayID; $MergeDisplayID ]
    Commit Records/Requests [ Skip data entry validation; No dialog ]
    #
    #5 records must be sorted by ID number, otherwise as soon as the brainstate name field is exited the database sorts the brainstate list by whatever current sort is selected, and the user will see their newly created record disappear. Step 1 of sorting by ID number is to clear the reference::sort field which is used to conditionally format the label of the currnt sort. 2 sort the records so the new record is the first record, and 3 make sure the sort layout is showing so user can decide to show or hide the new record on the main screens, and finally 4 go to that first record's description field.
    Sort Records [ Specified Sort Order: day1::swSymbols; based on value list: “MergeSort” brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Clear [ reference::sort ] [ Select ]
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “TotalSortAndScheduleiPhone” (brainstate) ]
    Else If [ ]
    Go to Layout [ “TotalSort” (brainstate) ]
    End If
    Go to Field [ brainstate::description ]

Fields used in this script	

    brainstate::groupType
    reference::farmerID
    brainstate::groupID
    brainstate::groupDisplayID
    brainstate::_keyUser
    day1::swSymbols
    brainstate::_lockBrainstateID
    reference::sort
    steward::iPhoneLayout
    brainstate::description

Scripts used in this script	

Layouts used in this script	

    TotalSortAndScheduleiPhone
    TotalSort

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


addToTotalPart2 CHUNK
	Parent Folder: [addToTotalPart2 CHUNK]	
Script Name	CHUNK addToTotalPart3
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    addToTotalPart2

Script Definition
Script Steps	

    #PURPOSE add selected record's time data to an existing grand total record. (This will essentially involve deleting all the grand total's day records first because we are not adding the brainstate time for a particular day to the grand total for that day; we are instead adding the total of a day to the grand total which may include time from another brainstate day record that is already included in the grand total. For example: if on a particular day the current total is 1 hour and the grand total is 1 hour and we are adding to the total (not the grand total) 1 hour from another brainstate, if we did not delete the current grand total which is already 1, adding the new total of 2 hours (1 hour from each of the days it now accounts for) would make it 3 hours! Thus we first delete the old grand total records so that the updated total records are properly accounted for by it.
    #USED BY addToTotalPart2
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #A) BEGIN find selected records to add and link to total record
    #
    #1 capture total record's ID number
    Sort Records [ Specified Sort Order: brainstate::groupAddCheckbox; descending brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $brainstateID; Value:brainstate::groupOfGroupID ]
    Set Variable [ $totalbrainstateID; Value:brainstate::groupID ]
    #
    #2 unflag grand total update
    Set Field [ brainstate::groupOfGroupUpdate; "" ]
    #
    #3 delete all its records which will include some of the time from the just separated record. (Now we are ready to create new total records for the records that remain.)
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Perform Find [ ]
    #
    #4 double check to insure records to be deleted are the right records. (During testing all 900+ records where deleted from my database. I think what happened is the find came up with zero records and then displayed all the records in the database and the next step deleted them. This If check will prevent that from happening again if that is what happened. I have been unable to duplicate this massive error, so this might not be reason why all the records where deleted, but this is the only time when the database is told to delete all found records, rather than just one record, so I figure it must have been caused here.)
    If [ day2::_keyBrainstate = $brainstateID ]
    Delete All Records [ No dialog ]
    End If
    #5 make a list of only the records to be added and the total record
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Perform Find [ ]
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number.
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming add to total part 2 script part A2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 1
    #
    #
    #
    #6 link all records
    Sort Records [ Specified Sort Order: brainstate::groupType; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ Last ]
    Set Variable [ $brainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Set Field [ brainstate::groupOfGroupDisplayID; $brainstateDisplayID ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #A) END find selected records to add and link to total record
    #
    #
    #
    Loop
    #B) BEGIN add a merge record's ID# to the description of the new GRAND total record.
    #
    #1 make sure there is a record to be merged (this step will be important when this loop is repeated after the first record to be merged is omitted).
    Go to Record/Request/Page [ First ]
    If [ brainstate::_lockBrainstateID ≠ brainstate::groupOfGroupID ]
    #
    #2 capture merged ID number for GRAND total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    #
    #
    #
    #BEGIN finish
    Else If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the updated total and its linked records.
    Go to Layout [ “TotalSort” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $totalbrainstateID ]
    Perform Find [ ]
    Go to Field [ ]
    If [ Get ( SystemPlatform ) = 3 ]
    Go to Layout [ “TotalSortAndScheduleiPhone” (brainstate) ]
    End If
    Halt Script
    #END finish
    #
    #
    #
    End If
    #
    #B) END add a merge record's ID# to the description of the new total record.
    #
    #
    #
    #C BEGIN find merge record's related day records
    #
    #1 make a list of the first brainstate's day records in a new window
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    #
    #C END find merge record's related day records
    #
    #
    #
    #D BEGIN no records found loop (this loop will either complete the merge process or find a merge record with related day records)
    #
    Loop
    #
    #1 if records are found exit loop
    Exit Loop If [ Get ( LastError ) = 0 ]
    #
    #2 clear the merge field (the big X in the box on the ToBeMerged layout) and omit this record
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Omit Record
    #
    #
    #
    #BEGIN finish
    If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #If all records are empty then the merge is complete and now the user needs to be shown the updated total and its linked records.
    Go to Layout [ “TotalEditTime” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $totalbrainstateID ]
    Perform Find [ ]
    Go to Field [ ]
    Halt Script
    End If
    #END finish
    #
    #
    #
    #BEGIN find error 2
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming grand total merge script part D2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    End If
    #END find error 2
    #
    #
    #
    #3 capture next records ID number for total's linkinfo field: total of: ID, ID, ID, etc.
    Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
    Go to Record/Request/Page [ First ]
    #
    #4 make a list of this record's day records in a new window.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
    Perform Find [ ]
    End Loop
    #
    #D END no records found loop
    #
    #
    #
    #E BEGIN create new related day records and add selected record's time to them
    #
    Loop
    #1 find any day records for the new brainstate that match the kfDay of the first merge record. If this new record already has data in it, then we want to add new data to the old data; not replace the old data with new data.
    Set Variable [ $mergeDay; Value:day1::_keyDay ]
    Enter Find Mode [ ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Perform Find [ ]
    #
    #2 if no matches are found, create a new day record and put in the time of the first the current day record
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ day2::_keyBrainstate; $brainstateID ]
    Set Field [ day2::_keyDay; $mergeDay ]
    Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & $TotalActivity ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    #
    #
    #
    #BEGIN find error 3
    Else If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming grand total merge script part E2."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button.
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    Sort Records [ ] [ No dialog ]
    Halt Script
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    Halt Script
    #END find error 3
    #
    #
    #
    #3 if a match is found, then add the current day's time to this day's time.
    Else If [ Get ( LastError ) = 0 ]
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Go to Layout [ “calcTotalNewRecord” (day2) ]
    Set Field [ day2::swPause; Case ( $TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ; $TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ; day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
    End If
    #
    #4 repeat loop for found record's next related day record.
    Go to Layout [ “calcTotalSelectedList” (day1) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #E END create new related day records and add selected record's time to them
    #
    #
    #
    #F BEGIN go to next record with related day records to be added to the new total record.
    #
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    #Clear the merge field (the big X in the box on the ToBeMerged layout).
    Set Field [ brainstate::groupOfGroupAddCheckbox; "" ]
    Omit Record
    #
    #F END go to next record with related day records to be added to the new total record.
    #
    #
    #
    End Loop

Fields used in this script	

    reference::farmerID
    brainstate::groupAddCheckbox
    brainstate::groupType
    brainstate::groupOfGroupID
    brainstate::groupID
    brainstate::groupOfGroupUpdate
    day2::_keyBrainstate
    steward::retiredStatus
    brainstate::sortRetired
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::Show
    brainstate::_Number
    brainstate::groupOfGroupDisplayID
    brainstate::_lockBrainstateID
    day1::_keyBrainstate
    brainstate::groupOfGroupAddCheckbox
    day1::_keyDay
    day2::_keyDay
    day2::swStart
    day1::swTotalActivity
    day2::swPause
    day2::swTotalActivity

Scripts used in this script	

Layouts used in this script	

    calcTotalNewRecord
    calcBrainstateTable
    TotalSort
    TotalSortAndScheduleiPhone
    calcTotalSelectedList
    01SortAndSchedule
    TotalEditTime

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


falsified ideas
	Parent Folder: [falsified ideas]	Next Script: [CHUNK_deleteRecordsTimeFromGrandtotal]
Script Name	UpdateTimeAfterSeperate (OLD)
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE separate a record it total record only deleting only the time on the day separated, but keeping the time previously added. This turned out not to be a good idea. If the user re-adds this record to the total, its time doubled on those days its time was not deleted during the separate.
    // #
    // #
    // #
    // #NOTE: the three # symbols set apart chunks of script.
    // #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    // #
    // #
    // #
    // #basic administration tasks
    // Set Error Capture [ On ]
    // Allow User Abort [ Off ]
    // Set Variable [ $userID; Value:reference::farmerID ]
    // #
    // #
    // #
    // #A) BEGIN go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of the window while performing the script.
    // #
    // #1 open a new window and hide it
    // New Window [ Name: "UpateTime"; Height: 100; Width: 100 ]
    // Adjust Window [ Hide ]
    // Go to Layout [ “calcBrainstateTable” (brainstate) ]
    // #
    // #A) END go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of the window while performing the script.
    // #
    // #
    // #
    // #B) BEGIN mark record for grandtotal update (if it is part of one) and determine if the just separated record was the last record this total record was summing up.
    // #
    // #1 flag for grand total update
    // Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” brainstate::description; ascending ] [ Restore; No dialog ]
    // Go to Record/Request/Page [ First ]
    // Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
    // #
    // #2 determine if user has deleted all records to total and if so give them the option to turn this total record into a normal record or add another record to it to keep it as a total record.
    // If [ Get ( FoundCount ) = 1 and brainstate::_lockBrainstateID = brainstate::groupID ]
    // If [ day1::_keyDay ≠ "" ]
    // Set Variable [ $dayID; Value:day1::_lockDay ]
    // Go to Layout [ “calcDayTable” (day1) ]
    // Enter Find Mode [ ]
    // Set Field [ day1::_lockDay; $dayID ]
    // Perform Find [ ]
    // Delete Record/Request [ No dialog ]
    // End If
    // Close Window [ Name: "UpateTime"; Current file ]
    // Go to Layout [ “totalViewSeparated” (brainstate) ]
    // Show Custom Dialog [ Title: "!"; Message: "Option 1) To make this record a non-total record, change its name (opptional), and click the go back button.¶Option 2) To keep it as a total record, click the add button and select 1 or more records for it to total."; Buttons: “OK” ]
    // Go to Field [ brainstate::description ]
    // Halt Script
    // End If
    // #
    // #B) END mark record for grandtotal update (if it is part of one) and determine if the just separated record was the last record this total record was summing up.
    // #
    // #
    // #
    // #C) BEGIN total record
    // #
    // #1 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially by deleting its current day record and creating a new blank one).
    // If [ day1::_keyDay = "" ]
    // Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
    // Go to Layout [ “calcDayTable” (day1) ]
    // New Record/Request
    // Set Field [ day1::_keyBrainstate; $BrainstateID ]
    // Insert Calculated Result [ day1::_keyDay; reference::day1 ] [ Select ]
    // Go to Layout [ “calcBrainstateTable” (brainstate) ]
    // End If
    // Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
    // Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
    // #
    // Loop
    // #
    // #2 go to the last record
    // Go to Record/Request/Page [ Last ]
    // #
    // #3 if there are no records to add then delete the just created related day record for this total record (this action would be caused by the user deleting all the time in the linked records).
    // If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    // If [ day1::swTotalActivity = "0:00:00" ]
    // Set Variable [ $dayID; Value:day1::_lockDay ]
    // Go to Layout [ “calcDayTable” (day1) ]
    // Enter Find Mode [ ]
    // Set Field [ day1::_lockDay; $dayID ]
    // Perform Find [ ]
    // Delete Record/Request [ No dialog ]
    // Go to Layout [ “calcBrainstateTable” (brainstate) ]
    // End If
    // #
    // #4 go the next part of the script once there are no more records to add
    // Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    // #
    // #5 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
    // Else If [ day1::_keyDay = "" ]
    // Omit Record
    // Else If [ day1::_keyDay ≠ "" ]
    // Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    // Omit Record
    // Go to Record/Request/Page [ First ]
    // Insert Calculated Result [ day1::swPause; Case ( $TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ; $TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ; day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ] [ Select ]
    // End If
    // End Loop
    // #
    // #C) END update found record
    // #
    // #
    // #
    // Loop
    // #
    // #D) BEGIN find all user GRAND total records that need to be udated
    // #
    // #1 find records
    // Enter Find Mode [ ]
    // Set Field [ brainstate::_keyUser; $user ]
    // Set Field [ brainstate::groupOfGroupUpdate; "u" ]
    // Perform Find [ ]
    // #
    // #2 if no records are found go to step
    // Exit Loop If [ Get ( LastError ) = 401 ]
    // #
    // #
    // #
    // #BEGIN error 1
    // If [ Get ( LastError ) ≠ 0 ]
    // #tell user the error number
    // Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime step i1."; Buttons: “OK” ]
    // Close Window [ Name: "UpateTime"; Current file ]
    // Exit Script [ ]
    // End If
    // #END error 1
    // #
    // #
    // #
    // #D) END find all user GRAND total records that need to be udated
    // #
    // #
    // #
    // #E) BEGIN update found record
    // #
    // #1 unflag this total record for grand total update
    // Clear [ brainstate::groupOfGroupUpdate ] [ Select ]
    // #
    // #2 find its linked records
    // Set Variable [ $mergeto; Value:brainstate::groupOfGroupID ]
    // Go to Layout [ “calcBrainstateTable” (brainstate) ]
    // Enter Find Mode [ ]
    // Set Field [ brainstate::groupOfGroupID; $mergeto ]
    // Perform Find [ ]
    // Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    // #
    // #3 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially by deleting its current day record and creating a new blank one).
    // Go to Record/Request/Page [ First ]
    // If [ day1::_keyDay = "" ]
    // Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
    // Go to Layout [ “calcDayTable” (day1) ]
    // New Record/Request
    // Set Field [ day1::_keyBrainstate; $BrainstateID ]
    // Insert Calculated Result [ day1::_keyDay; reference::day1 ] [ Select ]
    // Go to Layout [ “calcBrainstateTable” (brainstate) ]
    // End If
    // Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
    // Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
    // #
    // Loop
    // #
    // #4 go to the last record
    // Go to Record/Request/Page [ Last ]
    // #
    // #5 if there are no records to add then delete the just created related day record for this total record (this action would be caused by the user deleting all the time in the linked records).
    // If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    // If [ day1::swTotalActivity = "0:00:00" ]
    // Set Variable [ $dayID; Value:day1::_lockDay ]
    // Go to Layout [ “calcDayTable” (day1) ]
    // Enter Find Mode [ ]
    // Set Field [ day1::_lockDay; $dayID ]
    // Perform Find [ ]
    // Delete Record/Request [ No dialog ]
    // Go to Layout [ “calcBrainstateTable” (brainstate) ]
    // End If
    // #
    // #6 go the next part of the script once there are no more records to add
    // Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    // #
    // #7 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
    // Else If [ day1::_keyDay = "" ]
    // Omit Record
    // Else If [ day1::_keyDay ≠ "" ]
    // Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    // Omit Record
    // Go to Record/Request/Page [ First ]
    // Insert Calculated Result [ day1::swPause; Case ( $TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ; $TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ; day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ] [ Select ]
    // End If
    // End Loop
    // End Loop
    // #
    // #8) close window and sort records
    // Close Window [ Name: "UpateTime"; Current file ]
    // Perform Script [ “sortRestoreAfterScript” ]
    // #
    // #E) END update found record

Fields used in this script	

    reference::farmerID
    brainstate::groupType
    brainstate::description
    brainstate::groupOfGroupID
    brainstate::groupOfGroupUpdate
    brainstate::_lockBrainstateID
    brainstate::groupID
    day1::_keyDay
    day1::_lockDay
    day1::_keyBrainstate
    reference::day1
    day1::swStart
    day1::swPause
    day1::swTotalActivity
    brainstate::_keyUser

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

    calcBrainstateTable
    calcDayTable
    totalViewSeparated

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [UpdateTimeAfterSeperate (OLD)]	Parent Folder: [falsified ideas]	
Script Name	CHUNK_deleteRecordsTimeFromGrandtotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    seperateFromTotal

Script Definition
Script Steps	

    #DISABLE: I thought this was a good idea to delete total records that nothing to total for the user. But after thinking about it, I now think I should allow the user to do this. There is no harm in having a non-working total record. It can always be used again by adding records to it to total, or by turning it into a regular record.
    // #PURPOSE set the variables and make a list of the grandtotal records whose time has gone down
    // #CHUNK USED BY seperateFromTotal Script
    // #
    // #
    // #
    // #basic administration tasks
    // Set Error Capture [ On ]
    // Allow User Abort [ Off ]
    // #
    // #
    // #
    // #1 capture grandtotal record's ID number
    // Set Variable [ $brainstateID; Value:brainstate::groupOfGroupID ]
    // Set Variable [ $$deleteID; Value:brainstate::_lockBrainstateID ]
    // Set Variable [ $totaldisplayID; Value:brainstate::groupDisplayID ]
    // Set Variable [ $description; Value:brainstate::description ]
    // Set Field [ brainstate::description; " delete interrupted! click here for info: Delete this record and this grandtotal record ID number -- " & $brainstateID & ". Both can be rebuilt if you still want them. // " & $description ]
    // Set Field [ brainstate::groupOfGroupID; "" ]
    // Set Field [ brainstate::groupOfGroupDisplayID; "" ]
    // #
    // #2 make a list of records that are part of the grandtotal -- including the grandtotal in preparation or totaling their time (after separating a record from one of the totals)
    // Enter Find Mode [ ]
    // Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    // Perform Find [ ]
    // Perform Script [ “CHUNK_recalculateGrandTotal” ]

Fields used in this script	

    brainstate::groupOfGroupID
    brainstate::_lockBrainstateID
    brainstate::groupDisplayID
    brainstate::description
    brainstate::groupOfGroupDisplayID

Scripts used in this script	

    CHUNK_recalculateGrandTotal

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


navigation
	Parent Folder: [navigation]	Next Script: [gotoLibraryDatabaseUsingGoButton]
Script Name	gotoLibraryDatabase
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    // Select Window [ Name: "Test" ]
    // Select Window [ Name: "Learn" ]
    // Select Window [ Name: "Setup" ]
    // Select Window [ Name: "Report" ]
    // Select Window [ Name: "References" ]
    Select Window [ Name: MemorySwitch::currentLibraryMainWIndow ]
    If [ Get (LastError) = 112 and MemorySwitch::currentLibraryPath ≠ "" ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute (MemorySwitch::currentLibraryPath ; " " ; "%20" ) ; Substitute ( Substitute ( MemorySwitch::currentLibraryPath ; "file:/" ; "file://" ) ; " " ; "%20" ) ) ] [ No dialog ]
    If [ Get (LastError) = 5 ]
    Set Variable [ $$stopRecordLoad; Value:1 ]
    New Window [ Name: "library" ]
    Go to Layout [ “MemorySwitch” (MemorySwitch) ]
    Set Variable [ $$stopRecordLoad ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ Get (FoundCount) = 0 ]
    #
    #These disabled script steps deleted all invalid paths
    #to libraries and opened the first path that was valid.
    // Open URL [ Substitute ( Substitute ( MemorySwitch::path ; "file:/" ; "file://" ) ; " " ; "%20" ) ] [ No dialog ]
    // Exit Loop If [ Get (LastError) = 0 ]
    // Delete Record/Request [ No dialog ]
    // Exit Loop If [ Get (LastError) = 101 ]
    Exit Loop If [ MemorySwitch::currentLibraryPath = MemorySwitch::path ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ MemorySwitch::currentLibraryPath = MemorySwitch::path ]
    Delete Record/Request [ No dialog ]
    End If
    Set Variable [ $found; Value:Get (FoundCount) ]
    Close Window [ Current Window ]
    If [ $found = 0 ]
    Show Custom Dialog [ Message: "There is no library file in memory. Open one up manually, and it will be added to memory and opened when you next click the library button."; Buttons: “OK” ]
    Else
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "library/library." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "library/library." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ) ] [ No dialog ]
    If [ Get (LastError) = 5 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "library/library.USR" ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "library/library.USR" ; " " ; "%20" ) ) ] [ No dialog ]
    If [ Get (LastError) = 5 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "library/library.USR" ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:///" ) & "library/library.USR" ; " " ; "%20" ) ) ] [ No dialog ]
    End If
    End If
    If [ Get (LastError) = 5 ]
    Show Custom Dialog [ Message: "The library you last looked at cannot be opened because its name was changed, the file was moved, or deleted. Open a library file up manually, and it will be added to memory and opened when you next click the library button."; Buttons: “OK” ]
    End If
    End If
    End If
    Else If [ Get (LastError) = 112 and MemorySwitch::currentLibraryPath = "" ]
    Show Custom Dialog [ Message: "There is no library file in memory. Open one up, and it will be added to memory to be opened in when you next click the library button."; Buttons: “OK” ]
    End If
    Select Window [ Name: "Tag Menus" ]
    Select Window [ Name: "Learn" ]
    Select Window [ Name: "Setup" ]
    Select Window [ Name: "Report" ]
    Select Window [ Name: "References" ]

Fields used in this script	

    MemorySwitch::currentLibraryMainWIndow
    MemorySwitch::currentLibraryPath
    MemorySwitch::path

Scripts used in this script	

Layouts used in this script	

    MemorySwitch

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoLibraryDatabase]	Parent Folder: [navigation]	Next Script: [gotoHelp]
Script Name	gotoLibraryDatabaseUsingGoButton
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    // Set Variable [ $path; Value:Get ( ActiveFieldContents ) ]
    Set Variable [ $path; Value:MemorySwitch::path ]
    #
    Select Window [ Name: "Tag Menus" ]
    #
    #This step is required or else the main library window
    #will remain hidden behind the timer window if open.
    If [ MemorySwitch::currentLibraryPath = $path ]
    Select Window [ Name: MemorySwitch::currentLibraryMainWIndow ]
    End If
    If [ MemorySwitch::currentLibraryPath ≠ $path or Get (LastError) = 112 ]
    Close Window [ Name: "Tag Menus" ]
    Close Window [ Name: "Setup" ]
    Close Window [ Name: "Report" ]
    Close Window [ Name: "Reference" ]
    Close Window [ Name: "Recommendations" ]
    Close Window [ Name: "Numbers" ]
    Close Window [ Name: "Library Update" ]
    Close Window [ Name: "import" ]
    Close Window [ Name: "Test" ]
    Close Window [ Name: "reorder" ]
    Close Window [ Name: "delete tag" ]
    Close Window [ Name: "Citation Note" ]
    Close Window [ Name: "Preview" ]
    Close Window [ Name: "Details" ]
    Close Window [ Name: "" ]
    Close Window [ Name: "Help" ]
    Close Window [ Name: "Print/Copy" ]
    Close Window [ Name: "Cover Page" ]
    Close Window [ Name: "!" ]
    Close Window [ Name: "Copy / Paste Evidence" ]
    Close Window [ Name: "Day" ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute (MemorySwitch::path ; " " ; "%20" ) ; Substitute ( Substitute ( MemorySwitch::path ; "file:/" ; "file://" ) ; " " ; "%20" ) ) ] [ No dialog ]
    End If
    If [ Get (LastError) = 5 ]
    Go to Layout [ “libraryPath” (MemorySwitch) ]
    Enter Find Mode [ ]
    Set Field [ MemorySwitch::path; $path ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ original layout ]
    End If
    #
    #Close other apps window if open after selecting an app.
    If [ $$otherApps = 1 ]
    Close Window [ Name: "Other Apps"; Current file ]
    End If

Fields used in this script	

    MemorySwitch::path
    MemorySwitch::currentLibraryPath
    MemorySwitch::currentLibraryMainWIndow

Scripts used in this script	

Layouts used in this script	

    libraryPath

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoLibraryDatabaseUsingGoButton]	Parent Folder: [navigation]	Next Script: [gotoOtherDatabase]
Script Name	gotoHelp
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    #
    #This step is required or else the main library window
    #will remain hidden behind the timer window if open.
    // Close Window [ Name: "Help" ]
    #
    #Set back path from help to this solution.
    Set Field [ MemorySwitch::backToSolution; "ActionLog" ]
    #
    If [ Get (LayoutName) = "users" ]
    Set Field [ MemorySwitch::helpLayoutName; "dashboard" ]
    Set Field [ MemorySwitch::helpObjectName; "" ]
    #
    Else If [ Get (LayoutName) = "01Main" ]
    Set Field [ MemorySwitch::helpLayoutName; "timer" ]
    Set Field [ MemorySwitch::helpObjectName; "" ]
    #
    Else If [ Get (LayoutName) = "01editTime" ]
    Set Field [ MemorySwitch::helpLayoutName; "timer edit" ]
    Set Field [ MemorySwitch::helpObjectName; "" ]
    #
    Else If [ Get (LayoutName) = "Issues" ]
    Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
    Set Field [ MemorySwitch::helpObjectName; "specific action" ]
    #
    Else If [ Left (Get (LayoutName) ; 3 ) = "log" ]
    Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
    Set Field [ MemorySwitch::helpObjectName; "day" ]
    #
    Else If [ Get (LayoutName) = "IssuesAndObservationsTag" ]
    Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
    Set Field [ MemorySwitch::helpObjectName; "add" ]
    #
    Else If [ Get (LayoutName) = "IssuesAndObservationsOrder" ]
    Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
    Set Field [ MemorySwitch::helpObjectName; "order" ]
    #
    Else If [ Get (LayoutName) = "IssuesAndObservationsFIND" ]
    Set Field [ MemorySwitch::helpLayoutName; "Specific Action" ]
    Set Field [ MemorySwitch::helpObjectName; "find" ]
    End If
    #
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; " " ; "%20" ) ; Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; "file:/" ; "file://" ) ; " " ; "%20" ) ) ] [ No dialog ]
    Open URL [ Substitute ( Substitute ( Substitute ( Substitute ( Get (FilePath) ; Get (FileName) & Right ( Get (FilePath) ; 4 ) ; "help" & Right ( Get (FilePath) ; 4 ) ) ; "file:/" ; "file://" ) ; " " ; "%20" ) ; "file://" ; "file:///Volumes/" ) ] [ No dialog ]
    #
    Select Window [ Name: "Help" ]
    Select Window [ Name: "Tutorial" ]
    #
    #

Fields used in this script	

    MemorySwitch::backToSolution
    MemorySwitch::helpLayoutName
    MemorySwitch::helpObjectName

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoHelp]	Parent Folder: [navigation]	Next Script: [gotoDatabaseFMER]
Script Name	gotoOtherDatabase
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Show Custom Dialog [ Message: "Open the Fat and Muscle Efficiency Research (FMER) application or the Budget Research application?"; Buttons: “cancel”, “Budget”, “FMER” ]
    If [ Get (LastMessageChoice) = 1 ]
    Else If [ Get (LastMessageChoice) = 2 ]
    Select Window [ Name: "Budget Research" ]
    If [ Get (LastError) = 112 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "Budget Research." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "Budget Research." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ) ] [ No dialog ]
    If [ Get (LastError) = 5 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "Budget Research.USR" ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "Budget Research.USR" ; " " ; "%20" ) ) ] [ No dialog ]
    End If
    End If
    Else If [ Get (LastMessageChoice) = 3 ]
    Select Window [ Name: "Icons" ]
    Select Window [ Name: "Workout Editor" ]
    Select Window [ Name: "Plan Week" ]
    Select Window [ Name: "My Workouts" ]
    Select Window [ Name: "Planned Workouts" ]
    If [ MemorySwitch::fatPath = "Workout Editor" ]
    Select Window [ Name: "Icons" ]
    Select Window [ Name: "Workout Editor" ]
    Select Window [ Name: "Plan Week" ]
    Else If [ MemorySwitch::fatPath = "Plan Week" ]
    Select Window [ Name: "Icons" ]
    Select Window [ Name: "Workout Editor" ]
    Select Window [ Name: "Plan Week" ]
    Else If [ MemorySwitch::fatPath = "Icons" ]
    Select Window [ Name: "Icons" ]
    Select Window [ Name: "Workout Editor" ]
    Select Window [ Name: "Plan Week" ]
    Else If [ MemorySwitch::fatPath = "My Workouts" ]
    Select Window [ Name: "My Workouts" ]
    Select Window [ Name: "Planned Workouts" ]
    Else If [ MemorySwitch::fatPath = "Planned Workouts" ]
    Select Window [ Name: "My Workouts" ]
    Select Window [ Name: "Planned Workouts" ]
    End If
    Select Window [ Name: MemorySwitch::fatPath ]
    If [ Get (LastError) = 112 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "Fat and Muscle Efficiency Research." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "Fat and Muscle Efficiency Research." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ) ] [ No dialog ]
    If [ Get (LastError) = 5 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "Fat and Muscle Efficiency Research.USR" ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "Fat and Muscle Efficiency Research.USR" ; " " ; "%20" ) ) ] [ No dialog ]
    End If
    End If
    End If

Fields used in this script	

    MemorySwitch::fatPath

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoOtherDatabase]	Parent Folder: [navigation]	Next Script: [gotoDatabaseBudget]
Script Name	gotoDatabaseFMER
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Select Window [ Name: "Icons" ]
    Select Window [ Name: "Workout Editor" ]
    Select Window [ Name: "Plan Week" ]
    Select Window [ Name: "My Workouts" ]
    Select Window [ Name: "Planned Workouts" ]
    If [ MemorySwitch::fatPath = "Workout Editor" ]
    Select Window [ Name: "Icons" ]
    Select Window [ Name: "Workout Editor" ]
    Select Window [ Name: "Plan Week" ]
    Else If [ MemorySwitch::fatPath = "Plan Week" ]
    Select Window [ Name: "Icons" ]
    Select Window [ Name: "Workout Editor" ]
    Select Window [ Name: "Plan Week" ]
    Else If [ MemorySwitch::fatPath = "Icons" ]
    Select Window [ Name: "Icons" ]
    Select Window [ Name: "Workout Editor" ]
    Select Window [ Name: "Plan Week" ]
    Else If [ MemorySwitch::fatPath = "My Workouts" ]
    Select Window [ Name: "My Workouts" ]
    Select Window [ Name: "Planned Workouts" ]
    Else If [ MemorySwitch::fatPath = "Planned Workouts" ]
    Select Window [ Name: "My Workouts" ]
    Select Window [ Name: "Planned Workouts" ]
    End If
    Select Window [ Name: MemorySwitch::fatPath ]
    If [ Get (LastError) = 112 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "Fat and Muscle Efficiency Research." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "Fat and Muscle Efficiency Research." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ) ] [ No dialog ]
    If [ Get (LastError) = 5 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "Fat and Muscle Efficiency Research.USR" ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "Fat and Muscle Efficiency Research.USR" ; " " ; "%20" ) ) ] [ No dialog ]
    End If
    End If
    #
    #Close other apps window if open after selecting an app.
    If [ $$otherApps = 1 ]
    Close Window [ Name: "Other Apps"; Current file ]
    End If

Fields used in this script	

    MemorySwitch::fatPath

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoDatabaseFMER]	Parent Folder: [navigation]	Next Script: [gotoTimer]
Script Name	gotoDatabaseBudget
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Select Window [ Name: "Budget Research" ]
    If [ Get (LastError) = 112 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "Budget Research." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "Budget Research." & Right ( Get ( FilePath ) ; 3 ) ; " " ; "%20" ) ) ] [ No dialog ]
    If [ Get (LastError) = 5 ]
    Open URL [ Case ( Get ( SystemPlatform ) = - 2 ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file:/" ) & "Budget Research.USR" ; " " ; "%20" ) ; Substitute ( Substitute (Left (Get (FilePath) ; Length ( Get (FilePath) ) - ( Length ( Get (FileName) ) + 4 ) ) ; "file:/" ; "file://" ) & "Budget Research.USR" ; " " ; "%20" ) ) ] [ No dialog ]
    End If
    End If
    #
    #Close other apps window if open after selecting an app.
    If [ $$otherApps = 1 ]
    Close Window [ Name: "Other Apps"; Current file ]
    End If

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoDatabaseBudget]	Parent Folder: [navigation]	Next Script: [gotoSpecificAction]
Script Name	gotoTimer
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    #Stop script if user is process of picking a specific action group.
    If [ $$pick = 1 ]
    Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can select to go to other windows. "; Buttons: “OK” ]
    Exit Script [ ]
    End If
    #
    Select Window [ Name: "Timer" ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoTimer]	Parent Folder: [navigation]	Next Script: [gotoOrder]
Script Name	gotoSpecificAction
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    #Stop script if user is process of picking a specific action group.
    If [ $$pick = 1 ]
    Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can select to go to other windows. "; Buttons: “OK” ]
    Exit Script [ ]
    End If
    #
    Select Window [ Name: "Specific Action" ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoSpecificAction]	Parent Folder: [navigation]	Next Script: [goDay]
Script Name	gotoOrder
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    #Stop script if user is process of picking a specific action group.
    If [ $$pick = 1 ]
    Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can select to go to the order menu. "; Buttons: “OK” ]
    Exit Script [ ]
    End If
    #
    Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

    IssuesAndObservationsOrder

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoOrder]	Parent Folder: [navigation]	Next Script: [goDayLastDayUsed]
Script Name	goDay
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 1 day layouts
    #
    #
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; reference::day1 + reference::go ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    // #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    // Perform Script [ “sortRestoreAfterScript” ]
    #
    #4 sort the records
    Sort Records [ ] [ No dialog ]

Fields used in this script	

    reference::day1
    reference::go
    steward::chosenDay

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goDay]	Parent Folder: [navigation]	Next Script: [goPlus1]
Script Name	goDayLastDayUsed
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 1 day layouts
    #
    #
    If [ brainstate::DaysSinceLastUse = "" or brainstate::DaysSinceLastUse = 0 or brainstate::DaysSinceLastUseToggle ≠ "" ]
    Halt Script
    End If
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; reference::day1 - brainstate::DaysSinceLastUse ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    Perform Script [ “sortRestoreAfterScript” ]

Fields used in this script	

    brainstate::DaysSinceLastUse
    brainstate::DaysSinceLastUseToggle
    reference::day1
    steward::chosenDay

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goDayLastDayUsed]	Parent Folder: [navigation]	Next Script: [goPlus1iphone]
Script Name	goPlus1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go forwards 1 day
    #
    #
    #
    #1 add one the current date.
    Set Field [ reference::day1; reference::day1 + 1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    // #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    // Perform Script [ “sortRestoreAfterScript” ]
    #
    #4 sort the records
    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]

Fields used in this script	

    reference::day1
    steward::chosenDay
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goPlus1]	Parent Folder: [navigation]	Next Script: [goMinus1]
Script Name	goPlus1iphone
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go forwards 1 day
    #
    #
    #
    #1 add one the current date.
    Set Field [ reference::day1; reference::day1 + 1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    #disable step 4 because in view is not a list, so sorting is not helpful.
    // #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    // Perform Script [ “sortRestoreAfterScript” ]

Fields used in this script	

    reference::day1
    steward::chosenDay

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goPlus1iphone]	Parent Folder: [navigation]	Next Script: [goMinus1iphone]
Script Name	goMinus1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go backwards 1 day
    #
    #
    #
    #1 subract one day from the current date.
    Set Field [ reference::day1; reference::day1 - 1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    // #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    // Perform Script [ “sortRestoreAfterScript” ]
    #
    #4 sort the records
    Sort Records [ ] [ No dialog ]

Fields used in this script	

    reference::day1
    steward::chosenDay

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goMinus1]	Parent Folder: [navigation]	Next Script: [goWeekPlus1]
Script Name	goMinus1iphone
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go backwards 1 day
    #
    #
    #
    #1 subract one day from the current date.
    Set Field [ reference::day1; reference::day1 - 1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    #disable step 4 because in view is not a list, so sorting is not helpful.
    // #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    // Perform Script [ “sortRestoreAfterScript” ]

Fields used in this script	

    reference::day1
    steward::chosenDay

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goMinus1iphone]	Parent Folder: [navigation]	Next Script: [goWeekMinus1]
Script Name	goWeekPlus1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 7 day layouts
    #
    #
    #
    #1 add one the current date.
    Set Field [ reference::day1; reference::day1 + 1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference for starting the week
    Set Field [ steward::chosenWeek; reference::day1 ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ original layout ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day1
    steward::chosenWeek
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goWeekPlus1]	Parent Folder: [navigation]	Next Script: [goMonthPlus]
Script Name	goWeekMinus1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 7 day layouts
    #
    #
    #
    #1 add one the current date.
    Set Field [ reference::day1; reference::day1 - 1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference for starting the week
    Set Field [ steward::chosenWeek; reference::day1 ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ original layout ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day1
    steward::chosenWeek
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goWeekMinus1]	Parent Folder: [navigation]	Next Script: [goMonthMinus]
Script Name	goMonthPlus
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 7 day layouts
    #
    #
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; reference::day1 + reference::go ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference for starting the month
    Set Field [ steward::chosenMonth; reference::day1 ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ original layout ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day1
    reference::go
    steward::chosenMonth
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goMonthPlus]	Parent Folder: [navigation]	Next Script: [goToFarmer]
Script Name	goMonthMinus
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 7 day layouts
    #
    #
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; reference::day1 - reference::go ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference for starting the month
    Set Field [ steward::chosenMonth; reference::day1 ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ original layout ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day1
    reference::go
    steward::chosenMonth
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goMonthMinus]	Parent Folder: [navigation]	Next Script: [CalendarDayCalc]
Script Name	goToFarmer
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go the selected farmer's records from the createEditFarmer layout. (This is script is identical to the switchFarmer script except for step 1, which is required because the reference field is not available on this layout, and so the user's ID must be taken from the user table, not the reference table.)
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #
    #Loop to correct record. Portal shows up in on each
    #records layout, so first before the script continues
    #we need to make sure we are on the record that the user selected.
    Set Variable [ $userID; Value:steward 2::_lockUser ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $userID = steward::_lockUser ]
    Go to Record/Request/Page [ Next ]
    End Loop
    #
    #
    Freeze Window
    If [ Get ( SystemPlatform ) ≠ 3 and steward::iPhoneLayout = "" ]
    // Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [1]; Width: steward::windowSizeAndPlace [2]; Top: steward::windowSizeAndPlace [3]; Left: steward::windowSizeAndPlace [4] ]
    Else If [ steward::iPhoneLayout ≠ "" ]
    Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [5]; Width: steward::windowSizeAndPlace [6]; Top: steward::windowSizeAndPlace [7]; Left: steward::windowSizeAndPlace [8] ]
    End If
    #
    #1 capture selected userID, insert it into the referenceID field, then go to layout showing brainstate records.
    Set Variable [ $userID; Value:steward::_lockUser ]
    Set Field [ reference::farmerID; $userID ]
    #
    #2 find this user's records
    Perform Script [ “CHUNK_createRecordsForNewUsers” ]
    #
    #4 show the user's name
    Set Field [ reference::farmerName; steward::FirstPlusLast ]
    #
    #5 show/hide all records according the user's last settings
    If [ steward::hideStatus = "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “=” ] [ Restore ]
    Else If [ steward::showStatus ≠ "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::groupType: “=” ] [ Restore ]
    End If
    #8 it the user wants retired records hidden then hide these records if any
    Perform Script [ “CHUNK_retire” ]
    #
    // #6 go to user's chosen day, sort records, and choose last used layout
    // If [ Left ( steward::chosenLayout ; 2 ) = "01" ]
    // Perform Script [ “to 1” ]
    // Else If [ Left ( steward::chosenLayout ; 2 ) = "07" ]
    // Perform Script [ “to 7” ]
    // Else If [ Left ( steward::chosenLayout ; 2 ) = "31" ]
    // Perform Script [ “to 31” ]
    // End If
    #
    #Set window title.
    Set Window Title [ Current Window; New Title: "Timer" ]
    #
    #Size window to 150.
    Set Zoom Level [ 150% ]
    #
    #1 go to user's last layout
    If [ steward::chosenLayout = "users" ]
    Go to Layout [ “01Main” (brainstate) ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “MainiPhone” (brainstate) ]
    End If
    #END NOT TESTED
    Else If [ steward::chosenLayout ≠ "users" ]
    Go to Layout [ “01Main” (brainstate) ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “MainiPhone” (brainstate) ]
    End If
    #END NOT TESTED
    End If
    #
    #2 go to user's chosen day
    Set Field [ steward::chosenDay; Get ( CurrentDate ) ]
    Set Field [ reference::day1; steward::chosenDay ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be sorted out of top of list), and go to the first record.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Set Field [ steward::chosenLayout; steward::chosenLayoutMain ]
    Perform Script [ “sortNumbers” ]
    #7 go to active brainstate or first brainstate.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ day1::swBugField = "veto" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ day1::swBugField ≠ "veto" ]
    Go to Record/Request/Page [ First ]
    End If
    Perform Script [ “openSpecificAction” ]
    Select Window [ Name: "Timer"; Current file ]
    Set Variable [ $$stopRecordLoad ]
    Perform Script [ “recordLoad” ]

Fields used in this script	

    steward 2::_lockUser
    steward::_lockUser
    steward::iPhoneLayout
    steward::windowSizeAndPlace
    reference::farmerID
    steward::FirstPlusLast
    reference::farmerName
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::groupType
    steward::chosenLayout
    steward::chosenDay
    reference::day1
    steward::chosenLayoutMain
    day1::swBugField

Scripts used in this script	

    CHUNK_createRecordsForNewUsers
    CHUNK_retire
    to 1
    to 7
    to 31
    sortNumbers
    openSpecificAction
    recordLoad

Layouts used in this script	

    01Main
    MainiPhone

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goToFarmer]	Parent Folder: [navigation]	Next Script: [CalendarDayCalciphone]
Script Name	CalendarDayCalc
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE change the day to start the week and recalculate the Day1 key fields to show the user's data for this day.
    #
    #
    #
    #1 capture the new day as the user's choosen day
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    Perform Script [ “sortRestoreAfterScript” ]
    Go to Field [ ]

Fields used in this script	

    reference::day1
    steward::chosenDay

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarDayCalc]	Parent Folder: [navigation]	Next Script: [CalendarWeekCalc]
Script Name	CalendarDayCalciphone
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE change the day to start the week and recalculate the Day1 key fields to show the user's data for this day.
    #
    #
    #
    #1 capture the new day as the user's choosen day
    Set Field [ steward::chosenDay; reference::day1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #disable next step because in view is not a list, so sorting is not helpful.
    // Perform Script [ “sortRestoreAfterScript” ]
    Go to Field [ ]

Fields used in this script	

    reference::day1
    steward::chosenDay

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarDayCalciphone]	Parent Folder: [navigation]	Next Script: [CalendarMonthCalc]
Script Name	CalendarWeekCalc
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE calculate the total time for 7 days worth of time
    #
    #
    #
    #1 add 7 days to the users selection of the day desired to start the week. (Day 1 is the day the user is currently looking at on the day view layouts. In order to give the user on the week and month view layouts a calendar going from 1 to 7 or 31 it is neccessary to put the Day 1 field at the far right, or furtherest from the titles of the records. The user expects to to select the day they want to see by clicking on the day field closest to do the titles, which is day 7 on the week and day 31 on month view. So this script setp captures this left most choice and adds the 6 or 30 to it and applies it to the day 1 field.)
    // Set Field [ reference::day1; reference::day1 + 6 ]
    Set Field [ reference::day1; reference::day7Calc + 6 ]
    #
    #2 capture user's current date perference for starting the week
    Set Field [ steward::chosenWeek; reference::day1 ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ original layout ]
    Go to Record/Request/Page [ First ]
    Set Field [ reference::day7Calc; reference::day7 ]

Fields used in this script	

    reference::day1
    reference::day7Calc
    steward::chosenWeek
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays
    reference::day7

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarWeekCalc]	Parent Folder: [navigation]	Next Script: [CalendarMonthCalcChartSortN]
Script Name	CalendarMonthCalc
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE calculate the total time for 31 days worth of time
    #
    #
    #
    #1 add 30 days to the users selection of the day desired to start the month. (Day 1 is the day the user is currently looking at on the day view layouts. In order to give the user on the week and month view layouts a calendar going from 1 to 7 or 31 it is neccessary to put the Day 1 field at the far right, or furtherest from the titles of the records. The user expects to to select the day they want to see by clicking on the day field closest to do the titles, which is day 7 on the week and day 31 on month view. So this script setp captures this left most choice and adds the 6 or 30 to it and applies it to the day 1 field.)
    Set Field [ reference::day1; reference::day31Calc + 30 ]
    #
    #2 capture user's current date perference for starting the month
    Set Field [ steward::chosenMonth; reference::day1 ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ “31SortN” (brainstate) ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day31Calc
    reference::day1
    steward::chosenMonth
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable
    31SortN

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarMonthCalc]	Parent Folder: [navigation]	Next Script: [to 1]
Script Name	CalendarMonthCalcChartSortN
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE calculate the total time for 31 days worth of time
    #
    #
    #
    #1 add 30 days to the users selection of the day desired to start the month. (Day 1 is the day the user is currently looking at on the day view layouts. In order to give the user on the week and month view layouts a calendar going from 1 to 7 or 31 it is neccessary to put the Day 1 field at the far right, or furtherest from the titles of the records. The user expects to to select the day they want to see by clicking on the day field closest to do the titles, which is day 7 on the week and day 31 on month view. So this script setp captures this left most choice and adds the 6 or 30 to it and applies it to the day 1 field.)
    Set Field [ reference::day1; reference::day31Calc + 30 ]
    #
    #2 capture user's current date perference for starting the month
    Set Field [ steward::chosenMonth; reference::day1 ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ “31chartSortN” (brainstate) ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day31Calc
    reference::day1
    steward::chosenMonth
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable
    31chartSortN

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarMonthCalcChartSortN]	Parent Folder: [navigation]	Next Script: [to 1 chart]
Script Name	to 1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goToFarmer
    switchFarmer

Script Definition
Script Steps	

    #PURPOSE go to time layout 1
    #
    #
    #
    #1 go to time layout 1
    Go to Layout [ “01Main” (brainstate) ]
    #
    #2 go to user's chosen day
    Set Field [ reference::day1; steward::chosenDay ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be sorted out of top of list), and go to the first record.
    Perform Script [ “sortNumbers” ]
    #
    #5 go to active brainstate or first brainstate.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ day1::swBugField = "veto" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ day1::swBugField ≠ "veto" ]
    Go to Record/Request/Page [ First ]
    End If
    #

Fields used in this script	

    steward::chosenLayout
    steward::chosenDay
    reference::day1
    day1::swBugField

Scripts used in this script	

    sortNumbers

Layouts used in this script	

    01Main

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 1]	Parent Folder: [navigation]	Next Script: [to 7]
Script Name	to 1 chart
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to time layout 1
    #
    #
    #
    #1 go to time layout 1
    Go to Layout [ “01chartSortN” (brainstate) ]
    #
    #2 go to user's chosen day
    Set Field [ reference::day1; steward::chosenDay ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be sorted out of top of list), and go to the first record.
    Perform Script [ “DaySelectSortThenSort” ]

Fields used in this script	

    steward::chosenLayout
    steward::chosenDay
    reference::day1

Scripts used in this script	

    DaySelectSortThenSort

Layouts used in this script	

    01chartSortN

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 1 chart]	Parent Folder: [navigation]	Next Script: [to 7 chart]
Script Name	to 7
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goToFarmer
    switchFarmer

Script Definition
Script Steps	

    #PURPOSE go to time layout 7
    #
    #
    #
    #1 go to user's chosen day to start the week view
    // Set Field [ reference::day1; Get ( CurrentDate ) ]
    #
    #2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new layout.)
    Go to Layout [ “07SortN” (brainstate) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go to active brainstate or first brainstate.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ day1::swBugField = "veto" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ day1::swBugField ≠ "veto" ]
    Go to Record/Request/Page [ First ]
    End If
    #
    #8 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ “07SortN” (brainstate) ]
    Set Field [ reference::day7Calc; reference::day7 ]
    Set Field [ steward::chosenSort; "act" ]
    Perform Script [ “sortActivityWeek” ]

Fields used in this script	

    reference::day1
    steward::chosenLayout
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays
    day1::swBugField
    reference::day7
    reference::day7Calc
    steward::chosenSort

Scripts used in this script	

    sortActivityWeek

Layouts used in this script	

    07SortN
    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 7]	Parent Folder: [navigation]	Next Script: [to 31]
Script Name	to 7 chart
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to time layout 7
    #
    #
    #
    #1 go to user's chosen day to start the week view
    If [ steward::chosenWeek = "" ]
    Set Field [ steward::chosenWeek; steward::chosenDay ]
    End If
    Set Field [ reference::day1; steward::chosenWeek ]
    #
    #2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new layout.)
    Go to Layout [ “07chartSortN” (brainstate) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ “07chartSortN” (brainstate) ]
    Perform Script [ “WeekMonthSelectSortThenSort” ]

Fields used in this script	

    steward::chosenWeek
    steward::chosenDay
    reference::day1
    steward::chosenLayout
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

    WeekMonthSelectSortThenSort

Layouts used in this script	

    07chartSortN
    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 7 chart]	Parent Folder: [navigation]	Next Script: [to 31 chart]
Script Name	to 31
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goToFarmer
    switchFarmer

Script Definition
Script Steps	

    #PURPOSE go to time layout 31
    #
    #
    #
    #1 go to user's chosen day to start the month view
    // Set Field [ reference::day1; Get ( CurrentDate ) ]
    #
    #2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new layout.)
    Go to Layout [ “31SortN” (brainstate) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go to active brainstate or first brainstate.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ day1::swBugField = "veto" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ day1::swBugField ≠ "veto" ]
    Go to Record/Request/Page [ First ]
    End If
    #
    #8 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ “31SortN” (brainstate) ]
    Set Field [ steward::chosenSort; "act" ]
    Set Field [ reference::day31Calc; reference::day31 ]
    Perform Script [ “sortActivityWeek” ]
    Perform Script [ “WeekMonthSelectSortThenSort” ]

Fields used in this script	

    reference::day1
    steward::chosenLayout
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays
    day1::swBugField
    steward::chosenSort
    reference::day31
    reference::day31Calc

Scripts used in this script	

    sortActivityWeek
    WeekMonthSelectSortThenSort

Layouts used in this script	

    31SortN
    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 31]	Parent Folder: [navigation]	Next Script: [iphoneModegotoSort]
Script Name	to 31 chart
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to chart layout 31
    #
    #
    #
    #1 go to user's chosen day to start the month view
    If [ steward::chosenMonth = "" ]
    Set Field [ steward::chosenMonth; steward::chosenDay ]
    End If
    Set Field [ reference::day1; steward::chosenMonth ]
    #
    #2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new layout.)
    Go to Layout [ “31chartSortN” (brainstate) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ “31chartSortN” (brainstate) ]
    Perform Script [ “WeekMonthSelectSortThenSort” ]

Fields used in this script	

    steward::chosenMonth
    steward::chosenDay
    reference::day1
    steward::chosenLayout
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

    WeekMonthSelectSortThenSort

Layouts used in this script	

    31chartSortN
    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 31 chart]	Parent Folder: [navigation]	Next Script: [iphoneModegotoSortBack]
Script Name	iphoneModegotoSort
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $$iPhoneLayout; Value:Get ( LayoutName ) ]
    Set Field [ steward::windowSizeAndPlace[5]; Get ( WindowHeight ) ]
    Set Field [ steward::windowSizeAndPlace[6]; Get ( WindowWidth ) ]
    Set Field [ steward::windowSizeAndPlace[7]; Get ( WindowTop ) ]
    Set Field [ steward::windowSizeAndPlace[8]; Get ( WindowLeft ) ]
    Go to Layout [ “01SortAndSchedule” (brainstate) ]
    Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [1]; Width: steward::windowSizeAndPlace [2]; Top: steward::windowSizeAndPlace [3]; Left: steward::windowSizeAndPlace [4] ]
    // Adjust Window [ Maximize ]

Fields used in this script	

    steward::windowSizeAndPlace

Scripts used in this script	

Layouts used in this script	

    01SortAndSchedule

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [iphoneModegotoSort]	Parent Folder: [navigation]	Next Script: [iphoneModegotoSortTotal]
Script Name	iphoneModegotoSortBack
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ steward::iPhoneLayout ≠ "" ]
    Set Field [ steward::windowSizeAndPlace; Get ( WindowHeight ) ]
    Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowWidth ) ]
    Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowTop ) ]
    Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowLeft ) ]
    Go to Layout [ $$iPhoneLayout ]
    Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [5]; Width: steward::windowSizeAndPlace [6]; Top: steward::windowSizeAndPlace [7]; Left: steward::windowSizeAndPlace [8] ]
    Exit Script [ ]
    End If
    Go to Layout [ “01Main” (brainstate) ]

Fields used in this script	

    steward::iPhoneLayout
    steward::windowSizeAndPlace

Scripts used in this script	

Layouts used in this script	

    01Main

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [iphoneModegotoSortBack]	Parent Folder: [navigation]	Next Script: [iphoneModegotoSortBackTotal]
Script Name	iphoneModegotoSortTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $$iPhoneLayout; Value:Get ( LayoutName ) ]
    Set Field [ steward::windowSizeAndPlace[5]; Get ( WindowHeight ) ]
    Set Field [ steward::windowSizeAndPlace[6]; Get ( WindowWidth ) ]
    Set Field [ steward::windowSizeAndPlace[7]; Get ( WindowTop ) ]
    Set Field [ steward::windowSizeAndPlace[8]; Get ( WindowLeft ) ]
    Go to Layout [ “TotalSort” (brainstate) ]
    Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [1]; Width: steward::windowSizeAndPlace [2]; Top: steward::windowSizeAndPlace [3]; Left: steward::windowSizeAndPlace [4] ]
    // Adjust Window [ Maximize ]

Fields used in this script	

    steward::windowSizeAndPlace

Scripts used in this script	

Layouts used in this script	

    TotalSort

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [iphoneModegotoSortTotal]	Parent Folder: [navigation]	Next Script: [EditTimePart1]
Script Name	iphoneModegotoSortBackTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ steward::iPhoneLayout ≠ "" ]
    Set Field [ steward::windowSizeAndPlace; Get ( WindowHeight ) ]
    Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowWidth ) ]
    Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowTop ) ]
    Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowLeft ) ]
    Go to Layout [ $$iPhoneLayout ]
    Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [5]; Width: steward::windowSizeAndPlace [6]; Top: steward::windowSizeAndPlace [7]; Left: steward::windowSizeAndPlace [8] ]
    Exit Script [ ]
    End If
    Go to Layout [ “TotalMain” (brainstate) ]

Fields used in this script	

    steward::iPhoneLayout
    steward::windowSizeAndPlace

Scripts used in this script	

Layouts used in this script	

    TotalMain

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [iphoneModegotoSortBackTotal]	Parent Folder: [navigation]	Next Script: [EditTimePart2]
Script Name	EditTimePart1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Set Field [ steward::chosenLayoutMain; steward::chosenSort ]
    #
    #
    #2 toggle the retired status field
    If [ steward::retiredStatus = "" ]
    Perform Script [ “retireButton” ]
    End If
    #
    #
    Go to Layout [ “01EditTime” (brainstate) ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::groupType; ascending day1::swStart; ascending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    // Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "allow" ]
    #7 go to active brainstate or first brainstate.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ day1::swBugField = "veto" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ day1::swBugField ≠ "veto" ]
    Go to Record/Request/Page [ First ]
    End If
    // Go to Record/Request/Page [ First ]
    // Loop
    // Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    // Go to Record/Request/Page [ Next ]
    // End Loop
    // If [ day1::_keyBrainstate = "" ]
    // Scroll Window [ Home ]
    // End If

Fields used in this script	

    brainstate::_lockBrainstateID
    steward::chosenSort
    steward::chosenLayoutMain
    steward::retiredStatus
    day1::_keyDay
    brainstate::groupType
    day1::swStart
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description
    day1::swBugField
    day1::_keyBrainstate

Scripts used in this script	

    retireButton

Layouts used in this script	

    01EditTime

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [EditTimePart1]	Parent Folder: [navigation]	Next Script: [goAndComeBackPart1]
Script Name	EditTimePart2
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    #
    #this gotoField removes focus from field if user in a
    #field when activates this script. It then causes the script
    #update script to cancel this script, but without changing
    #the users sort. Then when activitated again having now
    #exited all fields, the scirpt preforms fine. The alternative
    #would be to cancel this script if the user was in a field
    #when it was activited. This essentially does that (
    #cancels the script because the focus will trigger a conflicting script).
    Go to Field [ ]
    Set Field [ steward::chosenSort; steward::chosenLayoutMain ]
    Go to Layout [ “01Main” (brainstate) ]
    #1 set the layout status field
    Set Field [ steward::chosenLayout; Get ( LayoutName ) ]
    Set Field [ steward::chosenSort; "rebmun" ]
    Perform Script [ “sortNumbers” ]
    #7 go to active brainstate or first brainstate.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ day1::swBugField = "veto" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    If [ day1::swBugField ≠ "veto" ]
    Go to Record/Request/Page [ First ]
    End If

Fields used in this script	

    brainstate::_lockBrainstateID
    steward::chosenLayoutMain
    steward::chosenSort
    steward::chosenLayout
    day1::swBugField

Scripts used in this script	

    sortNumbers

Layouts used in this script	

    01Main

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [EditTimePart2]	Parent Folder: [navigation]	Next Script: [goAndComeBackPart2]
Script Name	goAndComeBackPart1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE prevent huge time delay. (For some reason, when you select a new value in the go or scale dropdown lists, filemaker goes into a lengthy re-calc of all the barcharts on the layout, even though these drop downs are not connected in anyway with any of the record being calculated. To prevent this form happening, this script makes filemaker freeze the window and go to another layout. This other layout has a script layout trigger that causes the user to be returned to the layout that they just left. This back and forth between layouts seems to stop the recalc process from occuring.)
    #
    #
    #
    #1 freeze window and go to bounce back layout.
    Freeze Window
    Go to Layout [ “bounceBackUtilityLayout” (brainstate) ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

    bounceBackUtilityLayout

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goAndComeBackPart1]	Parent Folder: [navigation]	Next Script: [goBackButton]
Script Name	goAndComeBackPart2
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE bounce back to previous layout via a script trigger on layout load.
    #
    #
    #
    #1 bounce back layout user just left.
    Go to Layout [ steward::chosenLayout ]

Fields used in this script	

    steward::chosenLayout

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goAndComeBackPart2]	Parent Folder: [navigation]	
Script Name	goBackButton
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    cancelTotal
    seperateFromTotal
    DeleteBrainstate
    CHUNK_deleteTotalOrGrandtotalRecord
    CHUNK_deleteRecordsTimeFromTotal

Script Definition
Script Steps	

    #PURPOSE return the user to the layout they where one and find all the records being looked at, and hide the records previously hidden (plus or minus records created and deleted on this layout).
    #
    #
    If [ Get (WindowName) = "Day" or Get (WindowName) = "Tag" or Get (WindowName) = "Specific Action" ]
    Close Window [ Name: "Day"; Current file ]
    Close Window [ Name: "Specific Action"; Current file ]
    Close Window [ Name: "Tag"; Current file ]
    Set Variable [ $$log ]
    Set Variable [ $$issue ]
    Set Variable [ $$group ]
    Set Variable [ $$status ]
    Set Variable [ $$timeAll ]
    Set Variable [ $$issueSort ]
    Set Variable [ $$logissues ]
    Set Variable [ $$issueLogs ]
    Set Variable [ $$logrecordID ]
    Set Variable [ $$logBrainstate ]
    Set Variable [ $$issueRecordID ]
    Exit Script [ ]
    End If
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #reset recordnumber for use in sort on final layout and erase holder variable.
    Set Variable [ $$recordnumber; Value:$$recordnumber2 ]
    Set Variable [ $$recordnumber2 ]
    #
    #
    #
    #A BEGIN go back to log layout
    #
    #1 determine if user is on a log layout
    If [ Left ( Get ( LayoutName ); 3 ) = "log" or Left ( $$iphoneLog; 8 ) = "TotalLog" ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    If [ Left ( $$iphoneLog; 8 ) = "TotalLog" ]
    Go to Layout [ “TotalLogEditTimeiPhone” (brainstate) ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Scroll Window [ Home ]
    Set Variable [ $$iphoneLog; Value:"" ]
    Halt Script
    End If
    Go to Layout [ “LogEditTimeiPhone” (brainstate) ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Scroll Window [ Home ]
    Set Variable [ $$iphoneLog; Value:"" ]
    Halt Script
    End If
    Go to Layout [ $$loglayout ]
    Set Variable [ $$loglayout; Value:"" ]
    // Go to Record/Request/Page [ $$record ] [ No dialog ]
    Halt Script
    End If
    #
    #A END go back to log layout
    #
    #
    #
    #B BEGIN check if user just deleted the total or grandtotal record on a view layout and if so tell them why they are leaving the view that they were on.
    #
    #1 determine if user deleted a total or grandtotal record
    If [ Left ( Get ( LayoutName ); 5 ) = "Total" and $$deleteID = "total" ]
    Show Custom Dialog [ Title: "!"; Message: "You are now being returned to your previous screen as this screen was for showing the total record that you just deleted and all the records that it totaled."; Buttons: “OK” ]
    Else If [ Left ( Get ( LayoutName ); 5 ) = "viewG" and $$deleteID = "grandtotal" ]
    Show Custom Dialog [ Title: "!"; Message: "You are now being returned to your previous screen as this screen was for showing the grandtotal record that you just deleted and all the records that it totaled."; Buttons: “OK” ]
    End If
    #
    #2 clear the $$deleteID variable so that it will not trigger the above dialog boxes without a delete being done.
    Set Variable [ $$deleteID; Value:"" ]
    #
    #B END check if user just deleted the total or grandtotal record on a view layout and if so tell them why they are leaving the view that they were on.
    #
    #
    #
    #C BEGIN show user all records they where looking at previously on the main screen
    #
    #
    #2 show user all records at which they were previously looking
    Perform Script [ “goBackButton_FindRecordsChunk” ]
    #
    #C END shorten list if user has selected to not show some of their records
    #
    #
    #
    #D BEGIN go to layout
    #
    #1 go to user's last layout
    Go to Layout [ steward::chosenLayout ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “MainiPhone” (brainstate) ]
    End If
    Freeze Window
    #
    #2 go to user's chosen day
    Set Field [ reference::day1; steward::chosenDay ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be sorted out of top of list), and go to the first record.
    Perform Script [ “DaySelectSortThenSort” ]
    #
    #D END go to layout

Fields used in this script	

    reference::farmerID
    steward::iPhoneLayout
    steward::chosenLayout
    steward::chosenDay
    reference::day1

Scripts used in this script	

    goBackButton_FindRecordsChunk
    DaySelectSortThenSort

Layouts used in this script	

    TotalLogEditTimeiPhone
    LogEditTimeiPhone
    <Missing Layout>
    MainiPhone

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


help
	Parent Folder: [help]	
Script Name	dashboard
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Close Window [ Name: "help"; Current file ]
    New Window [ Name: "help"; Top: 0; Left: 0 ]
    Go to Layout [ <unknown> ]
    Adjust Window [ Resize to Fit ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


total
	Parent Folder: [total]	Next Script: [goWeekTotal]
Script Name	goDayTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 1 day layouts
    #
    #
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; reference::day1 + reference::go ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference
    Set Field [ steward::chosenDayTotal; reference::day1 ]
    #
    #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    Perform Script [ “sortRestoreAfterScript” ]

Fields used in this script	

    reference::day1
    reference::go
    steward::chosenDayTotal

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goDayTotal]	Parent Folder: [total]	Next Script: [goMonthTotal]
Script Name	goWeekTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 7 day layouts
    #
    #
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; reference::day1 + reference::go ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference for starting the week
    Set Field [ steward::chosenWeekTotal; reference::day1 ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ original layout ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day1
    reference::go
    steward::chosenWeekTotal
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goWeekTotal]	Parent Folder: [total]	Next Script: [CalendarDayCalcTotal]
Script Name	goMonthTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 7 day layouts
    #
    #
    #
    #1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive numbers.)
    Set Field [ reference::day1; reference::day1 + reference::go ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #3 capture user's current date perference for starting the month
    Set Field [ steward::chosenMonthTotal; reference::day1 ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ original layout ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day1
    reference::go
    steward::chosenMonthTotal
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goMonthTotal]	Parent Folder: [total]	Next Script: [CalendarWeekCalcTotal]
Script Name	CalendarDayCalcTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE change the day to start the week and recalculate the Day1 key fields to show the user's data for this day.
    #
    #
    #
    #1 capture the new day as the user's choosen day
    Set Field [ steward::chosenDayTotal; reference::day1 ]
    #
    #2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    Perform Script [ “sortRestoreAfterScript” ]
    Go to Field [ ]

Fields used in this script	

    reference::day1
    steward::chosenDayTotal

Scripts used in this script	

    sortRestoreAfterScript

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarDayCalcTotal]	Parent Folder: [total]	Next Script: [CalendarMonthCalcTotal]
Script Name	CalendarWeekCalcTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE calculate the total time for 7 days worth of time
    #
    #
    #
    #1 add 7 days to the users selection of the day desired to start the week. (Day 1 is the day the user is currently looking at on the day view layouts. In order to give the user on the week and month view layouts a calendar going from 1 to 7 or 31 it is neccessary to put the Day 1 field at the far right, or furtherest from the titles of the records. The user expects to to select the day they want to see by clicking on the day field closest to do the titles, which is day 7 on the week and day 31 on month view. So this script setp captures this left most choice and adds the 6 or 30 to it and applies it to the day 1 field.)
    Set Field [ reference::day1; reference::day7Calc + 6 ]
    #
    #2 capture user's current date perference for starting the week AND capture layout name for bounceback script
    Set Field [ steward::chosenWeekTotal; reference::day1 ]
    Set Variable [ $$layoutTotal; Value:Get ( LayoutName ) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ original layout ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day7Calc
    reference::day1
    steward::chosenWeekTotal
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarWeekCalcTotal]	Parent Folder: [total]	Next Script: [CalendarMonthCalcChartTotal]
Script Name	CalendarMonthCalcTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE calculate the total time for 31 days worth of time
    #
    #
    #
    #1 add 30 days to the users selection of the day desired to start the month. (Day 1 is the day the user is currently looking at on the day view layouts. In order to give the user on the week and month view layouts a calendar going from 1 to 7 or 31 it is neccessary to put the Day 1 field at the far right, or furtherest from the titles of the records. The user expects to to select the day they want to see by clicking on the day field closest to do the titles, which is day 7 on the week and day 31 on month view. So this script setp captures this left most choice and adds the 6 or 30 to it and applies it to the day 1 field.)
    Set Field [ reference::day1; reference::day31Calc + 30 ]
    #
    #2 capture user's current date perference for starting the month AND capture layout name for bounceback script
    Set Field [ steward::chosenMonthTotal; reference::day1 ]
    Set Variable [ $$layoutTotal; Value:Get ( LayoutName ) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ “Total31” (brainstate) ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day31Calc
    reference::day1
    steward::chosenMonthTotal
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable
    Total31

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarMonthCalcTotal]	Parent Folder: [total]	Next Script: [to 1 Total]
Script Name	CalendarMonthCalcChartTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE calculate the total time for 31 days worth of time
    #
    #
    #
    #1 add 30 days to the users selection of the day desired to start the month. (Day 1 is the day the user is currently looking at on the day view layouts. In order to give the user on the week and month view layouts a calendar going from 1 to 7 or 31 it is neccessary to put the Day 1 field at the far right, or furtherest from the titles of the records. The user expects to to select the day they want to see by clicking on the day field closest to do the titles, which is day 7 on the week and day 31 on month view. So this script setp captures this left most choice and adds the 6 or 30 to it and applies it to the day 1 field.)
    Set Field [ reference::day1; reference::day31Calc + 30 ]
    #
    #2 capture user's current date perference for starting the month AND capture layout name for bounceback script
    Set Field [ steward::chosenMonthTotal; reference::day1 ]
    Set Variable [ $$layoutTotal; Value:Get ( LayoutName ) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 finish by going back to the orginal layout and first record
    Go to Layout [ “Total31chart” (brainstate) ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    reference::day31Calc
    reference::day1
    steward::chosenMonthTotal
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable
    Total31chart

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CalendarMonthCalcChartTotal]	Parent Folder: [total]	Next Script: [to 1 chart Total]
Script Name	to 1 Total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to time Total layout 1
    #
    #
    #
    #1 go to time layout 1
    Go to Layout [ “TotalMain” (brainstate) ]
    #
    #2 go to user's chosen day
    Set Field [ reference::day1; steward::chosenDayTotal ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be sorted out of top of list), and go to the first record.
    Perform Script [ “DaySelectSortThenSort” ]

Fields used in this script	

    steward::chosenLayout
    steward::chosenDayTotal
    reference::day1

Scripts used in this script	

    DaySelectSortThenSort

Layouts used in this script	

    TotalMain

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 1 Total]	Parent Folder: [total]	Next Script: [to 7 Total]
Script Name	to 1 chart Total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to time Total layout 1
    #
    #
    #
    #1 go to time layout 1
    Go to Layout [ “Total01chart” (brainstate) ]
    #
    #2 go to user's chosen day
    Set Field [ reference::day1; steward::chosenDayTotal ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be sorted out of top of list), and go to the first record.
    Perform Script [ “DaySelectSortThenSort” ]

Fields used in this script	

    steward::chosenLayout
    steward::chosenDayTotal
    reference::day1

Scripts used in this script	

    DaySelectSortThenSort

Layouts used in this script	

    Total01chart

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 1 chart Total]	Parent Folder: [total]	Next Script: [to 7 chart Total]
Script Name	to 7 Total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to time Total layout 7
    #
    #
    #
    #1 go to user's chosen day to start the week view
    If [ steward::chosenWeekTotal = "" ]
    Set Field [ steward::chosenWeekTotal; steward::chosenDayTotal ]
    End If
    Set Field [ reference::day1; steward::chosenWeekTotal ]
    #
    #2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new layout.)
    Go to Layout [ “Total07” (brainstate) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ “Total07” (brainstate) ]
    Perform Script [ “WeekMonthSelectSortThenSort” ]

Fields used in this script	

    steward::chosenWeekTotal
    steward::chosenDayTotal
    reference::day1
    steward::chosenLayout
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

    WeekMonthSelectSortThenSort

Layouts used in this script	

    Total07
    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 7 Total]	Parent Folder: [total]	Next Script: [to 32 Total]
Script Name	to 7 chart Total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to time Total layout 7
    #
    #
    #
    #1 go to user's chosen day to start the week view
    If [ steward::chosenWeekTotal = "" ]
    Set Field [ steward::chosenWeekTotal; steward::chosenDay ]
    End If
    Set Field [ reference::day1; steward::chosenWeekTotal ]
    #
    #2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new layout.)
    Go to Layout [ “Total07chart” (brainstate) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ “Total07chart” (brainstate) ]
    Perform Script [ “WeekMonthSelectSortThenSort” ]

Fields used in this script	

    steward::chosenWeekTotal
    steward::chosenDay
    reference::day1
    steward::chosenLayout
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

    WeekMonthSelectSortThenSort

Layouts used in this script	

    Total07chart
    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 7 chart Total]	Parent Folder: [total]	Next Script: [to 31 chart Total]
Script Name	to 32 Total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to time Total layout 31
    #
    #
    #
    #1 go to user's chosen day to start the month view
    If [ steward::chosenMonthTotal = "" ]
    Set Field [ steward::chosenMonthTotal; steward::chosenDayTotal ]
    End If
    Set Field [ reference::day1; steward::chosenMonthTotal ]
    #
    #2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new layout.)
    Go to Layout [ “Total31” (brainstate) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ “Total31” (brainstate) ]
    Perform Script [ “WeekMonthSelectSortThenSort” ]

Fields used in this script	

    steward::chosenMonthTotal
    steward::chosenDayTotal
    reference::day1
    steward::chosenLayout
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

    WeekMonthSelectSortThenSort

Layouts used in this script	

    Total31
    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 32 Total]	Parent Folder: [total]	Next Script: [goAndComeBackPart1Total]
Script Name	to 31 chart Total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to chart Total layout 31
    #
    #
    #
    #1 go to user's chosen day to start the month view
    If [ steward::chosenMonthTotal = "" ]
    Set Field [ steward::chosenMonthTotal; steward::chosenDayTotal ]
    End If
    Set Field [ reference::day1; steward::chosenMonthTotal ]
    #
    #2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new layout.)
    Go to Layout [ “Total31chart” (brainstate) ]
    #
    #3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
    Refresh Window [ Flush cached join results ]
    #
    #4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is calcuated. (This must be done after flushing the cache (step 2) otherwise the flush unfreezes the window.)
    Freeze Window
    #
    #5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::monthsum; day1::swTotalActivity + day2::swTotalActivity + day3::swTotalActivity + day4::swTotalActivity + day5::swTotalActivity + day6::swTotalActivity + day7::swTotalActivity + day8::swTotalActivity + day9::swTotalActivity + day10::swTotalActivity + day11::swTotalActivity + day12::swTotalActivity + day13::swTotalActivity + day14::swTotalActivity + day15::swTotalActivity + day16::swTotalActivity + day17::swTotalActivity + day18::swTotalActivity + day19::swTotalActivity + day20::swTotalActivity + day21::swTotalActivity + day22::swTotalActivity + day23::swTotalActivity + day24::swTotalActivity + day25::swTotalActivity + day26::swTotalActivity + day27::swTotalActivity + day28::swTotalActivity + day29::swTotalActivity + day30::swTotalActivity + day31::swTotalActivity ]
    Set Field [ brainstate::monthsumaverage; If ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) = 0 ; "" ; brainstate::monthsum / ( If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ) ) ]
    Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) + If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #7 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be sorted to the top of list), and go to the first record.
    Go to Layout [ “Total31chart” (brainstate) ]
    Perform Script [ “WeekMonthSelectSortThenSort” ]

Fields used in this script	

    steward::chosenMonthTotal
    steward::chosenDayTotal
    reference::day1
    steward::chosenLayout
    day1::swTotalActivity
    day2::swTotalActivity
    day3::swTotalActivity
    day4::swTotalActivity
    day5::swTotalActivity
    day6::swTotalActivity
    day7::swTotalActivity
    day8::swTotalActivity
    day9::swTotalActivity
    day10::swTotalActivity
    day11::swTotalActivity
    day12::swTotalActivity
    day13::swTotalActivity
    day14::swTotalActivity
    day15::swTotalActivity
    day16::swTotalActivity
    day17::swTotalActivity
    day18::swTotalActivity
    day19::swTotalActivity
    day20::swTotalActivity
    day21::swTotalActivity
    day22::swTotalActivity
    day23::swTotalActivity
    day24::swTotalActivity
    day25::swTotalActivity
    day26::swTotalActivity
    day27::swTotalActivity
    day28::swTotalActivity
    day29::swTotalActivity
    day30::swTotalActivity
    day31::swTotalActivity
    brainstate::monthsum
    brainstate::monthsumaverage
    brainstate::monthsumdays

Scripts used in this script	

    WeekMonthSelectSortThenSort

Layouts used in this script	

    Total31chart
    calcBrainstateTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [to 31 chart Total]	Parent Folder: [total]	Next Script: [goAndComeBackPart2Total]
Script Name	goAndComeBackPart1Total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE prevent huge time delay. (For some reason, when you select a new value in the go or scale dropdown lists, filemaker goes into a lengthy re-calc of all the barcharts on the layout, even though these drop downs are not connected in anyway with any of the record being calculated. To prevent this form happening, this script makes filemaker freeze the window and go to another layout. This other layout has a script layout trigger that causes the user to be returned to the layout that they just left. This back and forth between layouts seems to stop the recalc process from occuring.)
    #
    #
    #
    #1 capture layout name for bounceback part 2 and then freeze window and go to bounce back layout.
    Set Variable [ $$layoutTotal; Value:Get ( LayoutName ) ]
    Freeze Window
    Go to Layout [ “bounceBackUtilityLayoutTotal” (brainstate) ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

    bounceBackUtilityLayoutTotal

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goAndComeBackPart1Total]	Parent Folder: [total]	
Script Name	goAndComeBackPart2Total
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE bounce back to previous layout via a script trigger on layout load.
    #
    #
    #
    #1 bounce back layout user just left.
    // Go to Layout [ steward::chosenLayout ]
    Go to Layout [ $$layoutTotal ]

Fields used in this script	

    steward::chosenLayout

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


goBackButton & goToFarmer CHUNK
	Parent Folder: [goBackButton & goToFarmer CHUNK]	
Script Name	CHUNK_createRecordsForNewUsers
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goToFarmer

Script Definition
Script Steps	

    #PURPOSE check to make sure that the user has records and if not create a record for the user
    #CHUNK USED BY goBackButton script
    #CHUNK USED BY goToFarmer script
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #1 find this user's brainstate records
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    #
    #2 if the user has no records, create a new one and assign it to the user so that there name will show up. (All the layouts are tied to the brainstate table not the user table. So the only way to show a user name and all the correct formating attributes is to have one user record.)
    If [ Get ( FoundCount ) = 0 ]
    Set Variable [ $actionNames; Value:"sleep" & ¶ & "exercise brain" & ¶ & "exercise body" & ¶ & "decrease confusion" & ¶ & "note learning" & ¶ & "break" & ¶ & "prepare" & ¶ & //"travel" & ¶ & "send and receive" & ¶ & "study others" & ¶ & "new day" & ¶ ]
    Set Variable [ $actionOrderNumber; Value:1 & ¶ & 2 & ¶ & 4 & ¶ & 5 & ¶ & 7 & ¶ & 8 & ¶ & 10 & ¶ & //12 & ¶ & 13 & ¶ & 15 & ¶ & 16 & ¶ ]
    Set Variable [ $number; Value:1 ]
    Loop
    New Record/Request
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::hide; "t" & ¶ ]
    Set Field [ brainstate::description; GetValue ( $actionNames ; $number ) ]
    Set Field [ brainstate::sortNumber; GetValue ( $actionOrderNumber ; $number ) ]
    Set Variable [ $number; Value:$number + 1 ]
    Exit Loop If [ $number = 11 ]
    End Loop
    #
    Set Variable [ $kpnBrainstateID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “calcDayTable” (day1) ]
    New Record/Request
    Set Field [ day1::_keyBrainstate; $kpnBrainstateID ]
    Set Field [ day1::_keyUser; $userID ]
    // Set Field [ day1::_keyDay; reference::day1 ]
    Set Field [ day1::swStart; Get ( CurrentTimeStamp ) ]
    Set Field [ day1::swPause; Get ( CurrentTimeStamp ) ]
    Show Custom Dialog [ Message: "Enter your date of birth so that this program can calculate your new day number, every day."; Buttons: “OK”; Input #1: day1::_keyDay, "use date format: 01/01/1900" ]
    Commit Records/Requests
    If [ IsValid ( day1::_keyDay ) ≠ 1 ]
    Show Custom Dialog [ Message: "Enter your date of birth so that this program can calculate your new day number, every day. Use must enter a valid date using this format: 00/00/0000."; Buttons: “OK”; Input #1: day1::_keyDay, "use date format: 01/01/1900" ]
    Commit Records/Requests
    End If
    Set Variable [ $dateOfLastUse; Value:day1::_keyDay ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Set Field [ brainstate::DateOfLastUse; $dateOfLastUse ]
    End If
    #

Fields used in this script	

    reference::farmerID
    brainstate::_keyUser
    brainstate::hide
    brainstate::description
    brainstate::sortNumber
    brainstate::_lockBrainstateID
    day1::_keyBrainstate
    day1::_keyUser
    reference::day1
    day1::_keyDay
    day1::swStart
    day1::swPause
    <Missing Field>
    brainstate::DateOfLastUse

Scripts used in this script	

Layouts used in this script	

    calcBrainstateTable
    calcDayTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


log
	Parent Folder: [log]	Next Script: [gotoSpecificIssuesLog]
Script Name	logShowAll
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE show only all records being browsed (list view)
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    // If [ Left ( $$loglayout ; 5 ) ≠ "total" ]
    // Halt Script
    // End If
    #1 capture record number and object number user is currently on
    #
    #2 go to selected object
    Go to Layout [ “LogHome” (brainstate) ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $itemID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “logs2rows” (logs) ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyBrainstate; $itemID ]
    Perform Find [ ]
    Loop
    Go to Layout [ “LogHome” (brainstate) ]
    Go to Record/Request/Page [ Next; Exit after last ]
    Set Variable [ $itemID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “logs2rows” (logs) ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyBrainstate; $itemID ]
    Extend Found Set [ ]
    End Loop
    Go to Layout [ “logs2rows” (logs) ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “logByActioniPhone” (logs) ]
    End If
    Sort Records [ Specified Sort Order: brainstate::description; ascending logs::_keyBrainstate; ascending logs::logDay; descending ] [ Restore; No dialog ]

Fields used in this script	

    brainstate::_lockBrainstateID
    logs::_keyBrainstate
    steward::iPhoneLayout
    brainstate::description
    logs::logDay

Scripts used in this script	

Layouts used in this script	

    LogHome
    logs2rows
    logByActioniPhone

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [logShowAll]	Parent Folder: [log]	Next Script: [openSpecificAction]
Script Name	gotoSpecificIssuesLog
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE open log windows
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    Select Window [ Name: "Tag"; Current file ]
    Select Window [ Name: "Day"; Current file ]
    Select Window [ Name: "Specific Action"; Current file ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoSpecificIssuesLog]	Parent Folder: [log]	Next Script: [gotoLogs]
Script Name	openSpecificAction
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goToFarmer
    gotoIssueLog

Script Definition
Script Steps	

    #PURPOSE open log window and select log entry for
    #current record.
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #Stop the load record scripts. They slow things down.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Set Variable [ $$stopSubtotal; Value:1 ]
    #
    #I really need to decide on ONE means to store the
    #current brainstate key, isntead of making up a new
    #one for each module because I'm not sure how the
    #others are being used. A definition of each variable
    #and how it is used would be great!
    Set Variable [ $$logBrainstate; Value:brainstate::_lockBrainstateID ]
    #
    Set Window Title [ Current Window; New Title: "Timer" ]
    #
    #Open a new window to test if any log records exist
    #for this brainstate record. A log record will not exist
    #if the user has never logged anytime for this brainstate.
    New Window [ Name: "Day"; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: Get (ScreenWidth) - 688 ]
    Set Zoom Level [ 100% ]
    #
    #Find first issue record if there is one and set variable
    #to conditionally format times for the first day record.
    Go to Layout [ “Issues” (issue) ]
    #
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    #
    If [ Get ( LastError ) = 401 ]
    // New Record/Request
    // Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    // Set Field [ issue::_keyCategory; $groupID ]
    // Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
    // Set Field [ issue::lock; "issue" ]
    // Set Field [ issue::text; "specific action" ]
    // #
    // #makes all new issues stay at the top of the window
    // #until a non-blank status is assigned to them.
    // Set Field [ issue::_keyStatus; 6302011014838316 ]
    // Go to Field [ ]
    // Go to Field [ issue::text ]
    Else
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    #
    Set Variable [ $$stopSubtotal ]
    Perform Script [ “TsubtotalTimeByGroup” ]
    End If
    #
    Set Variable [ $$issue; Value:issue::_LockList ]
    Set Variable [ $$status; Value:issue::_keyStatus ]
    Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
    Set Variable [ $$group; Value:issue::_keyCategory ]
    Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
    #
    #Now find log records for this timer.
    Go to Layout [ “logs2rows” (logs) ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyBrainstate; $$logBrainstate ]
    Perform Find [ ]
    #
    #Display all rows of time for this timer.
    If [ daylog::swActivityLength[11] ≠ "" ]
    Go to Layout [ “logs3rows” (logs) ]
    Else If [ daylog::swActivityLength[6] ≠ "" ]
    Go to Layout [ “logs2rows” (logs) ]
    Else If [ daylog::swActivityLength[6] = "" ]
    Go to Layout [ “logs1row” (logs) ]
    End If
    #
    #Sort and go to first record.
    Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending logs::_keyDay; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    #
    #For attaching issue record IDs to log records, and
    #for conditionally formatting log records related to an issue,
    #system needs to know what IDs are associated with a log record.
    Set Variable [ $$log; Value:logs::_lockDay ]
    Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
    #
    Refresh Window
    #
    #Show all status and category menu items for brainstate's log.
    New Window [ Name: "Tag" ]
    Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
    Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
    Perform Find [ ]
    #
    #Update review dates.
    Go to Object [ Object Name: "status" ]
    Go to Portal Row [ Select; First ]
    Set Variable [ $reviewNames; Value:"daily" & ¶ & "weekly" & ¶ & "monthly" & ¶ & "1/2 yearly" & ¶ & "yearly" & ¶ & "complete" & ¶ & "discard" ]
    Set Variable [ $reviewDates; Value://daily review "" & ¶ & //weekly review Case ( Day ( Get ( CurrentDate ) ) < 8 ; Month ( Get ( CurrentDate ) ) - 1 & "/" ; Month ( Get ( CurrentDate ) ) & "/" ) & Case ( DayOfWeek ( Get ( CurrentDate ) ) = 1 ; Day ( Get ( CurrentDate ) ) ; DayOfWeek ( Get ( CurrentDate ) - 1 ) = 1 ; Day ( Get ( CurrentDate ) - 1 ) ; DayOfWeek ( Get ( CurrentDate ) - 2 ) = 1 ; Day ( Get ( CurrentDate ) - 2 ) ; DayOfWeek ( Get ( CurrentDate ) - 3 ) = 1 ; Day ( Get ( CurrentDate ) - 3 ) ; DayOfWeek ( Get ( CurrentDate ) - 4 ) = 1 ; Day ( Get ( CurrentDate ) - 4 ) ; DayOfWeek ( Get ( CurrentDate ) - 5 ) = 1 ; Day ( Get ( CurrentDate ) - 5 ) ; DayOfWeek ( Get ( CurrentDate ) - 6 ) = 1 ; Day ( Get ( CurrentDate ) - 6 ) ) //& " - " & //Month ( Get ( CurrentDate ) ) & "/" & //Case ( //DayOfWeek ( Get ( CurrentDate ) ) = 7 ; Day ( Get ( CurrentDate ) ) ; //DayOfWeek ( Get ( CurrentDate ) + 1 ) = 7 ; Day ( Get ( CurrentDate ) + 1 ) ; //DayOfWeek ( Get ( CurrentDate ) + 2 ) = 7 ; Day ( Get ( CurrentDate ) + 2 ) ; //DayOfWeek ( Get ( CurrentDate ) + 3 ) = 7 ; Day ( Get ( CurrentDate ) + 3 ) ; //DayOfWeek ( Get ( CurrentDate ) + 4 ) = 7 ; Day ( Get ( CurrentDate ) + 4 ) ; //DayOfWeek ( Get ( CurrentDate ) + 5 ) = 7 ; Day ( Get ( CurrentDate ) + 5 ) ; //DayOfWeek ( Get ( CurrentDate ) + 6 ) = 7 ; Day ( Get ( CurrentDate ) + 6 ) ) ¶ & //monthly review " " & Case ( Day ( Get ( CurrentDate ) ) > 7 ; //MonthName ( Month ( Get ( CurrentDate ) ) + 1 & "/" & 1 & "/" & 2012) ; //MonthName ( Month ( Get ( CurrentDate ) ) & "/" & 1 & "/" & 2012) ) //& ")" Month ( Get ( CurrentDate ) ) + 1 & "/" & "1" ; Month ( Get ( CurrentDate ) ) & "/" & "1" ) ]
    Set Variable [ $number; Value:1 ]
    If [ status::text = "" ]
    Set Field [ status::status; "Remember existence" & ¶ & "of a specific action..." ]
    Loop
    Set Field [ status::text; GetValue ( $reviewNames ; $number ) ]
    Set Field [ status::reviewDate; GetValue ( $reviewDates ; $number ) ]
    Set Variable [ $number; Value:$number + 1 ]
    Go to Portal Row [ Select; Next; Exit after last ]
    End Loop
    End If
    #
    #Find all groups for this action.
    Go to Layout [ “menuGroups” (issueCategory) ]
    Enter Find Mode [ ]
    Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
    Set Field [ issueCategory::lock; "location" ]
    Perform Find [ ]
    #
    #If none are found then create one.
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ issueCategory::lock; "location" ]
    Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
    Set Field [ issueCategory::text; "administration" ]
    Set Variable [ $groupKey; Value:issueCategory::_LockList ]
    End If
    #
    Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    #
    #
    #Show all issues for this brainstate's log.
    New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: Get (ScreenWidth) - 688; Top: 0; Left: 0 ]
    Go to Layout [ “IssuesLayoutForScripts” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    #
    #If none are found then create one.
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
    Set Field [ issue::lock; "issue" ]
    Set Field [ issue::text; "review these specific action items and update their status, priority, and grouping as necessary." ]
    Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
    Set Field [ issue::_keyStatus; 7152011154818554 ]
    Set Field [ issue::_keyCategory; $groupKey ]
    End If
    #
    Go to Layout [ “Issues” (issue) ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Set Variable [ $$issueSort; Value:"status" ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    #
    #Start load record scripts as needed for normal function.
    Set Variable [ $$stopRecordLoad ]

Fields used in this script	

    brainstate::_lockBrainstateID
    issue::_keyBrainstate
    issue::lock
    issue::_keyCategory
    issue::date
    issue::text
    issue::_keyStatus
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issue::sortTime
    issue::order
    issue::_LockList
    issue::_keyLogs
    issue::timeSegmentKeyList
    logs::_keyBrainstate
    daylog::swActivityLength
    logs::_keyDay
    logs::_lockDay
    logs::_keyLogIssues
    status::text
    status::status
    status::reviewDate
    issueCategory::_keyBrainstate
    issueCategory::lock
    issueCategory::text
    issueCategory::_LockList
    brainstate::pulldownBrainstate

Scripts used in this script	

    TsubtotalTimeByGroup

Layouts used in this script	

    Issues
    logs2rows
    logs3rows
    logs1row
    IssuesAndObservationsTag
    menuGroups
    IssuesLayoutForScripts

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [openSpecificAction]	Parent Folder: [log]	Next Script: [changeLogs Copy]
Script Name	gotoLogs
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE open log window and select log entry for
    #current record.
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #If user remains in time edit field, conditional formatting
    #fails to work in day window when time is assigned.
    Go to Field [ ]
    #
    #Stop the load record scripts. They slow things down.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Set Variable [ $$stopSubtotal; Value:1 ]
    #
    #I really need to decide on ONE means to store the
    #current brainstate key, isntead of making up a new
    #one for each module because I'm not sure how the
    #others are being used. A definition of each variable
    #and how it is used would be great!
    Set Variable [ $$logBrainstate; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $day1; Value:reference::day1 ]
    Select Window [ Name: "Day"; Current file ]
    If [ logs::_keyBrainstate = $$logBrainstate and logs::_keyDay = $day1 ]
    #
    #Display all rows of time for this timer.
    If [ daylog::swActivityLength[11] ≠ "" ]
    Go to Layout [ “logs3rows” (logs) ]
    Else If [ daylog::swActivityLength[6] ≠ "" ]
    Go to Layout [ “logs2rows” (logs) ]
    Else If [ daylog::swActivityLength[6] = "" ]
    Go to Layout [ “logs1row” (logs) ]
    End If
    #
    Select Window [ Name: "Tag"; Current file ]
    Select Window [ Name: "Specific Action"; Current file ]
    #
    #Start load record scripts as needed for normal function.
    Set Variable [ $$stopRecordLoad ]
    Set Variable [ $$stopSubtotal ]
    Exit Script [ ]
    End If
    #
    #Find first issue record if there is one and set variable
    #to conditionally format times for the first day record.
    Go to Layout [ “Issues” (issue) ]
    #
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    #
    If [ Get ( LastError ) = 401 ]
    // New Record/Request
    // Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    // Set Field [ issue::_keyCategory; $groupID ]
    // Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
    // Set Field [ issue::lock; "issue" ]
    // Set Field [ issue::text; "specific action" ]
    // #
    // #makes all new issues stay at the top of the window
    // #until a non-blank status is assigned to them.
    // Set Field [ issue::_keyStatus; 7152011154818554 ]
    // Go to Field [ ]
    // Go to Field [ issue::text ]
    Else
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    #
    Set Variable [ $$stopSubtotal ]
    Perform Script [ “TsubtotalTimeByGroup” ]
    End If
    #
    Set Variable [ $$issue; Value:issue::_LockList ]
    Set Variable [ $$status; Value:issue::_keyStatus ]
    Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
    Set Variable [ $$group; Value:issue::_keyCategory ]
    Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$timeAll; Value:issue::timeSegmentKeyList ]
    #
    #Now find log records for this timer.
    Go to Layout [ “logs2rows” (logs) ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyBrainstate; $$logBrainstate ]
    Perform Find [ ]
    #
    #Sort and go to first record.
    Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending logs::_keyDay; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    #
    #Display all rows of time for this timer.
    If [ daylog::swActivityLength[11] ≠ "" ]
    Go to Layout [ “logs3rows” (logs) ]
    Else If [ daylog::swActivityLength[6] ≠ "" ]
    Go to Layout [ “logs2rows” (logs) ]
    Else If [ daylog::swActivityLength[6] = "" ]
    Go to Layout [ “logs1row” (logs) ]
    End If
    #
    #For attaching issue record IDs to log records, and
    #for conditionally formatting log records related to an issue,
    #system needs to know what IDs are associated with a log record.
    Set Variable [ $$log; Value:logs::_lockDay ]
    Set Variable [ $$logrecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$logissues; Value:logs::_keyLogIssues ]
    #
    Refresh Window
    #
    #
    #
    #Show all status and category menu items for brainstate's log.
    Select Window [ Name: "Tag"; Current file ]
    Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
    Perform Find [ ]
    #
    #Update review dates.
    Go to Object [ Object Name: "status" ]
    Go to Portal Row [ Select; First ]
    Set Variable [ $reviewNames; Value:"daily" & ¶ & "weekly" & ¶ & "monthly" & ¶ & "1/2 yearly" & ¶ & "yearly" & ¶ & "complete" & ¶ & "discard" ]
    Set Variable [ $reviewDates; Value://daily review "" & ¶ & //weekly review Case ( Day ( Get ( CurrentDate ) ) < 8 ; Month ( Get ( CurrentDate ) ) - 1 & "/" ; Month ( Get ( CurrentDate ) ) & "/" ) & Case ( DayOfWeek ( Get ( CurrentDate ) ) = 1 ; Day ( Get ( CurrentDate ) ) ; DayOfWeek ( Get ( CurrentDate ) - 1 ) = 1 ; Day ( Get ( CurrentDate ) - 1 ) ; DayOfWeek ( Get ( CurrentDate ) - 2 ) = 1 ; Day ( Get ( CurrentDate ) - 2 ) ; DayOfWeek ( Get ( CurrentDate ) - 3 ) = 1 ; Day ( Get ( CurrentDate ) - 3 ) ; DayOfWeek ( Get ( CurrentDate ) - 4 ) = 1 ; Day ( Get ( CurrentDate ) - 4 ) ; DayOfWeek ( Get ( CurrentDate ) - 5 ) = 1 ; Day ( Get ( CurrentDate ) - 5 ) ; DayOfWeek ( Get ( CurrentDate ) - 6 ) = 1 ; Day ( Get ( CurrentDate ) - 6 ) ) //& " - " & //Month ( Get ( CurrentDate ) ) & "/" & //Case ( //DayOfWeek ( Get ( CurrentDate ) ) = 7 ; Day ( Get ( CurrentDate ) ) ; //DayOfWeek ( Get ( CurrentDate ) + 1 ) = 7 ; Day ( Get ( CurrentDate ) + 1 ) ; //DayOfWeek ( Get ( CurrentDate ) + 2 ) = 7 ; Day ( Get ( CurrentDate ) + 2 ) ; //DayOfWeek ( Get ( CurrentDate ) + 3 ) = 7 ; Day ( Get ( CurrentDate ) + 3 ) ; //DayOfWeek ( Get ( CurrentDate ) + 4 ) = 7 ; Day ( Get ( CurrentDate ) + 4 ) ; //DayOfWeek ( Get ( CurrentDate ) + 5 ) = 7 ; Day ( Get ( CurrentDate ) + 5 ) ; //DayOfWeek ( Get ( CurrentDate ) + 6 ) = 7 ; Day ( Get ( CurrentDate ) + 6 ) ) ¶ & //monthly review " " & Case ( Day ( Get ( CurrentDate ) ) > 7 ; //MonthName ( Month ( Get ( CurrentDate ) ) + 1 & "/" & 1 & "/" & 2012) ; //MonthName ( Month ( Get ( CurrentDate ) ) & "/" & 1 & "/" & 2012) ) //& ")" Month ( Get ( CurrentDate ) ) + 1 & "/" & "1" ; Month ( Get ( CurrentDate ) ) & "/" & "1" ) ]
    Set Variable [ $number; Value:1 ]
    If [ status::text = "" ]
    Set Field [ status::status; "Remember existence" & ¶ & "of a specific action..." ]
    Loop
    Set Field [ status::text; GetValue ( $reviewNames ; $number ) ]
    Set Field [ status::reviewDate; GetValue ( $reviewDates ; $number ) ]
    Set Variable [ $number; Value:$number + 1 ]
    Go to Portal Row [ Select; Next; Exit after last ]
    End Loop
    End If
    #
    #Find all groups for this action.
    Go to Layout [ “menuGroups” (issueCategory) ]
    Enter Find Mode [ ]
    Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
    Set Field [ issueCategory::lock; "location" ]
    Perform Find [ ]
    #
    #If none are found then create one.
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ issueCategory::lock; "location" ]
    Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
    Set Field [ issueCategory::text; "administration" ]
    Set Variable [ $groupKey; Value:issueCategory::_LockList ]
    End If
    #
    Go to Layout [ “IssuesAndObservationsTag” (brainstate) ]
    #
    #
    #
    #Show all issues for this brainstate's log.
    Select Window [ Name: "Specific Action"; Current file ]
    Go to Layout [ “IssuesLayoutForScripts” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    #
    #If none are found then create one.
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
    Set Field [ issue::lock; "issue" ]
    Set Field [ issue::text; "review these specific action items and update their status, priority, and grouping as necessary." ]
    Set Field [ brainstate::pulldownBrainstate; issue::_keyBrainstate ]
    Set Field [ issue::_keyStatus; 7152011154818554 ]
    Set Field [ issue::_keyCategory; $groupKey ]
    End If
    #
    Go to Layout [ “Issues” (issue) ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Set Variable [ $$issueSort; Value:"status" ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    #
    #Start load record scripts as needed for normal function.
    Set Variable [ $$stopRecordLoad ]
    Perform Script [ “LoadIssuerecordID” ]

Fields used in this script	

    brainstate::_lockBrainstateID
    reference::day1
    logs::_keyBrainstate
    logs::_keyDay
    daylog::swActivityLength
    issue::_keyBrainstate
    issue::lock
    issue::_keyCategory
    issue::date
    issue::text
    issue::_keyStatus
    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issue::sortTime
    issue::order
    issue::_LockList
    issue::_keyLogs
    issue::timeSegmentKeyList
    logs::_lockDay
    logs::_keyLogIssues
    status::text
    status::status
    status::reviewDate
    issueCategory::_keyBrainstate
    issueCategory::lock
    issueCategory::text
    issueCategory::_LockList
    brainstate::pulldownBrainstate

Scripts used in this script	

    TsubtotalTimeByGroup
    LoadIssuerecordID

Layouts used in this script	

    logs3rows
    logs2rows
    logs1row
    Issues
    IssuesAndObservationsTag
    menuGroups
    IssuesLayoutForScripts

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoLogs]	Parent Folder: [log]	Next Script: [gotoIssueLog]
Script Name	changeLogs Copy
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE open log window and select log entry for
    #current record, but if that record has no time entry
    #the show the calendar log view for that record
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $$stopSubtotal; Value:1 ]
    #
    #I really need to decide on ONE means to store the
    #current brainstate key, isntead of making up a new
    #one for each module because I'm not sure how the
    #others are being used. A definition of each variable
    #and how it is used would be great!
    Set Variable [ $$logBrainstate; Value:brainstate::_lockBrainstateID ]
    #
    #Stop the load record scripts. They slow things down.
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Set Window Title [ Current Window; New Title: "Timer" ]
    #
    Select Window [ Name: "Tag"; Current file ]
    Select Window [ Name: "Day"; Current file ]
    Select Window [ Name: "Specific Action"; Current file ]
    // End If
    Go to Layout [ “Issues” (issue) ]
    Set Variable [ $$issueRecordID; Value:Get ( RecordID ) ]
    Set Variable [ $$issue; Value:issue::_LockList ]
    Set Variable [ $$issueLogs; Value:issue::_keyLogs ]
    Refresh Window
    #neccessary step when two monitors are used as this
    #window can be opened in smaller monitor and then
    #move over to larger monitor but not adjust its height
    #unless this step is included.
    Move/Resize Window [ Name: "Day"; Current file; Height: Get (ScreenHeight) ]
    Select Window [ Name: "Day"; Current file ]
    Set Variable [ $$stopRecordLoad ]
    Exit Script [ ]
    #
    #
    #
    #Open a new window to test if any log records exist
    #for this brainstate record. A log record will not exist
    #if the user has never logged anytime for this brainstate.
    New Window [ Name: "Day"; Height: Get (ScreenHeight); Width: 608; Top: 0; Left: 441 ]
    Move/Resize Window [ Current Window; Width: Get (ScreenWidth) / 2; Left: Get (ScreenWidth) / 2 ]
    Set Zoom Level [ 100% ]
    Go to Layout [ “logs2rows” (logs) ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyBrainstate; $$logBrainstate ]
    Perform Find [ ]
    #
    #Decided to show log windows even if there are
    #no log records as user may want to create some
    #issues.
    If [ Get ( LastError ) = 401 ]
    Show Custom Dialog [ Title: "!"; Message: "You can create issues for this brainstate, but until you click the stopwatch for this brainstate there will be no log records to show in the Activity Log window. "; Buttons: “OK” ]
    End If
    #
    #
    #If there are records for this brainstate then show them.
    Sort Records [ Specified Sort Order: logs::_keyBrainstate; descending logs::_keyDay; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    #
    #Show all status and category menu items for brainstate's log.
    Select Window [ Name: "Tag"; Current file ]
    If [ Get (LastError) = 112 ]
    New Window [ Name: "Tag" ]
    Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: //If (Get (ScreenWidth) / 2 + 1100 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 1100 ) Get (ScreenWidth)/2 ]
    Set Zoom Level [ 100% ]
    End If
    Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
    Allow User Abort [ Off ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
    Perform Find [ ]
    Go to Layout [ “menuGroups” (issueCategory) ]
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #Find the blank (10 space) record for this brainstate's
    #set of group tags for grouping issues by group.
    Enter Find Mode [ ]
    Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
    Set Field [ issueCategory::lock; "location" ]
    Set Field [ issueCategory::text; "==" & " " ]
    Set Field [ issueCategory::order; "" ]
    Perform Find [ ]
    #
    #If the blank (10 space) record is not found then
    #create a new one.
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ issueCategory::lock; "location" ]
    Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
    Set Field [ issueCategory::text; " " ]
    Set Variable [ $groupID; Value:issueCategory::_LockList ]
    End If
    #
    #Set the key for the first blank record (actually
    #the record with 10 spaces in it, which looks
    #blank to the user and will scroll to the top, which
    #is what is essential.
    Set Variable [ $$blankGroupKey; Value:issueCategory::_LockList ]
    Enter Find Mode [ ]
    Set Field [ issueCategory::_keyBrainstate; $$logBrainstate ]
    Set Field [ issueCategory::lock; "location" ]
    Perform Find [ ]
    Go to Layout [ “IssuesAndObservationsOrder” (brainstate) ]
    #
    #
    #Show all issues for this brainstate's log.
    New Window [ Name: "Specific Action"; Height: Get (ScreenHeight); Width: Get (ScreenWidth) / 2; Top: 0; Left: 0 ]
    Set Zoom Level [ 100% ]
    Go to Layout [ “IssuesLayoutForScripts” (issue) ]
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::lock; "issue" ]
    Perform Find [ ]
    If [ Get ( LastError ) = 401 ]
    New Record/Request
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::_keyCategory; $groupID ]
    Set Field [ issue::date; Get ( CurrentTimeStamp ) ]
    Set Field [ issue::lock; "issue" ]
    Set Field [ issue::text; "issue" ]
    #
    #makes all new issues stay at the top of the window
    #until a non-blank status is assigned to them.
    Set Field [ issue::_keyStatus; 6302011014838316 ]
    Go to Field [ ]
    Go to Field [ issue::text ]
    End If
    Go to Layout [ “Issues” (issue) ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issue::sortTime; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    Perform Script [ “TsubtotalTimeByGroup” ]
    Set Variable [ $$issueSort; Value:"status" ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]
    #
    #neccessary step when two monitors are used as this
    #window can be opened in smaller monitor and then
    #move over to larger monitor but not adjust its height
    #unless this step is included.
    // Move/Resize Window [ Name: "Activity Log"; Current file; Height: Get (ScreenHeight) ]
    #
    #Start load record scripts as needed for normal function.
    Set Variable [ $$stopRecordLoad ]
    Perform Script [ “LoadIssuerecordID” ]
    Select Window [ Name: "Day"; Current file ]
    Perform Script [ “LoadLogrecordID” ]

Fields used in this script	

    brainstate::_lockBrainstateID
    issue::_LockList
    issue::_keyLogs
    logs::_keyBrainstate
    logs::_keyDay
    issueCategory::_keyBrainstate
    issueCategory::lock
    issueCategory::text
    issueCategory::order
    issueCategory::_LockList
    issue::_keyBrainstate
    issue::lock
    issue::_keyCategory
    issue::date
    issue::text
    issue::_keyStatus
    brainstate::description
    issueStatus::order
    issueStatus::text
    issue::sortTime
    issue::order

Scripts used in this script	

    TsubtotalTimeByGroup
    LoadIssuerecordID
    LoadLogrecordID

Layouts used in this script	

    Issues
    logs2rows
    IssuesAndObservationsOrder
    menuGroups
    IssuesLayoutForScripts

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [changeLogs Copy]	Parent Folder: [log]	Next Script: [logOpen]
Script Name	gotoIssueLog
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #
    Perform Script [ “openSpecificAction” ]

Fields used in this script	

Scripts used in this script	

    openSpecificAction

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [gotoIssueLog]	Parent Folder: [log]	Next Script: [logClose]
Script Name	logOpen
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $$loglayout; Value:Get ( LayoutName ) ]
    Go to Layout [ “LogHome” (brainstate) ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 ]
    Go to Layout [ “logHomeiPhone” (brainstate) ]
    End If

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

    LogHome
    logHomeiPhone

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [logOpen]	Parent Folder: [log]	Next Script: [logViewByDate]
Script Name	logClose
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Go to Layout [ $$loglayout ]
    Set Variable [ $$loglayout ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [logClose]	Parent Folder: [log]	Next Script: [logViewByAction]
Script Name	logViewByDate
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Go to Layout [ “logByDate” (logs) ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “logByDateiPhone” (logs) ]
    End If
    Sort Records [ Specified Sort Order: logs::_keyDay; descending logs::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]

Fields used in this script	

    steward::iPhoneLayout
    logs::_keyDay
    logs::swStart
    brainstate::description

Scripts used in this script	

Layouts used in this script	

    logByDate
    logByDateiPhone

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [logViewByDate]	Parent Folder: [log]	Next Script: [logHideBlanks]
Script Name	logViewByAction
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Go to Layout [ “logs2rows” (logs) ]
    #NOT TESTED
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    Go to Layout [ “logByActioniPhone” (logs) ]
    End If
    Sort Records [ Specified Sort Order: brainstate::description; ascending logs::_keyBrainstate; descending logs::swStart; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Scroll Window [ Home ]

Fields used in this script	

    steward::iPhoneLayout
    brainstate::description
    logs::_keyBrainstate
    logs::swStart

Scripts used in this script	

Layouts used in this script	

    logs2rows
    logByActioniPhone

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [logViewByAction]	Parent Folder: [log]	Next Script: [RemoveTextFormatting]
Script Name	logHideBlanks
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE open log window and select log entry for current record, but if that record has no time entry the show the calendar log view for that record
    #
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: logs::log: “=” ] [ Restore ]
    #1 capture layout name for the return trip
    If [ Get ( LastError ) = 401 ]
    If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
    If [ Left ( $$iphoneLog; 8 ) = "TotalLog" ]
    Go to Layout [ “TotalLogEditTimeiPhone” (brainstate) ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Scroll Window [ Home ]
    Set Variable [ $$iphoneLog; Value:"" ]
    Show Custom Dialog [ Title: "!"; Message: "All log entries are blank."; Buttons: “OK” ]
    Halt Script
    End If
    Go to Layout [ “LogEditTimeiPhone” (brainstate) ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Scroll Window [ Home ]
    Show Custom Dialog [ Title: "!"; Message: "All log entries are blank."; Buttons: “OK” ]
    Halt Script
    End If
    Go to Layout [ $$loglayout ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Scroll Window [ Home ]
    Show Custom Dialog [ Title: "!"; Message: "All log entries are blank."; Buttons: “OK” ]
    Halt Script
    End If

Fields used in this script	

    logs::log
    steward::iPhoneLayout

Scripts used in this script	

Layouts used in this script	

    TotalLogEditTimeiPhone
    LogEditTimeiPhone

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [logHideBlanks]	Parent Folder: [log]	Next Script: [resetRememberTags]
Script Name	RemoveTextFormatting
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Field [ TextFontRemove ( (Get ( ActiveFieldContents )) ) ]
    Set Field [ TextFormatRemove ( (Get ( ActiveFieldContents )) ) ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [RemoveTextFormatting]	Parent Folder: [log]	
Script Name	resetRememberTags
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE resets remember tags.
    #
    #
    #Stop script if user is process of picking a specific action group.
    If [ $$pick = 1 ]
    Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can reset these tags to the default setting. "; Buttons: “OK” ]
    Exit Script [ ]
    End If
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Go to Field [ ]
    #
    #Make sure user wants to reset dates to default.
    Show Custom Dialog [ Message: "Are you sure you want to reset the remember tags names to daily, weekly, monthly, 1/2 yearly, yearly, complete, discard?"; Buttons: “cancel”, “OK” ]
    If [ Get ( LastMessageChoice ) = 1 ]
    Exit Script [ ]
    End If
    #
    #Update remember names and review dates.
    Set Field [ status::status; "Remember existence" & ¶ & "of a specific action..." ]
    Go to Object [ Object Name: "status" ]
    Go to Portal Row [ Select; First ]
    Set Variable [ $reviewNames; Value:"daily" & ¶ & "weekly" & ¶ & "monthly" & ¶ & "1/2 yearly" & ¶ & "yearly" & ¶ & "complete" & ¶ & "discard" ]
    // Set Variable [ $reviewDates; Value://daily review "" & ¶ & //weekly review Case ( Day ( Get ( CurrentDate ) ) < 8 ; Month ( Get ( CurrentDate ) ) - 1 & "/" ; Month ( Get ( CurrentDate ) ) & "/" ) & Case ( DayOfWeek ( Get ( CurrentDate ) ) = 1 ; Day ( Get ( CurrentDate ) ) ; DayOfWeek ( Get ( CurrentDate ) - 1 ) = 1 ; Day ( Get ( CurrentDate ) - 1 ) ; DayOfWeek ( Get ( CurrentDate ) - 2 ) = 1 ; Day ( Get ( CurrentDate ) - 2 ) ; DayOfWeek ( Get ( CurrentDate ) - 3 ) = 1 ; Day ( Get ( CurrentDate ) - 3 ) ; DayOfWeek ( Get ( CurrentDate ) - 4 ) = 1 ; Day ( Get ( CurrentDate ) - 4 ) ; DayOfWeek ( Get ( CurrentDate ) - 5 ) = 1 ; Day ( Get ( CurrentDate ) - 5 ) ; DayOfWeek ( Get ( CurrentDate ) - 6 ) = 1 ; Day ( Get ( CurrentDate ) - 6 ) ) & " - " & //Month ( Get ( CurrentDate ) ) & "/" & Case ( DayOfWeek ( Get ( CurrentDate ) ) = 7 ; Day ( Get ( CurrentDate ) ) ; DayOfWeek ( Get ( CurrentDate ) + 1 ) = 7 ; Day ( Get ( CurrentDate ) + 1 ) ; DayOfWeek ( Get ( CurrentDate ) + 2 ) = 7 ; Day ( Get ( CurrentDate ) + 2 ) ; DayOfWeek ( Get ( CurrentDate ) + 3 ) = 7 ; Day ( Get ( CurrentDate ) + 3 ) ; DayOfWeek ( Get ( CurrentDate ) + 4 ) = 7 ; Day ( Get ( CurrentDate ) + 4 ) ; DayOfWeek ( Get ( CurrentDate ) + 5 ) = 7 ; Day ( Get ( CurrentDate ) + 5 ) ; DayOfWeek ( Get ( CurrentDate ) + 6 ) = 7 ; Day ( Get ( CurrentDate ) + 6 ) ) & ¶ & //monthly review " " & Case ( Day ( Get ( CurrentDate ) ) > 7 ; //MonthName ( Month ( Get ( CurrentDate ) ) + 1 & "/" & 1 & "/" & 2012) ; //MonthName ( Month ( Get ( CurrentDate ) ) & "/" & 1 & "/" & 2012) ) //& ")" Month ( Get ( CurrentDate ) ) + 1 & "/" & "1" ; Month ( Get ( CurrentDate ) ) & "/" & "1" ) ]
    Set Variable [ $reviewDates; Value://daily review "" & ¶ & //weekly review Case ( Day ( Get ( CurrentDate ) ) < 8 ; Month ( Get ( CurrentDate ) ) - 1 & "/" ; Month ( Get ( CurrentDate ) ) & "/" ) & Case ( DayOfWeek ( Get ( CurrentDate ) ) = 1 ; Day ( Get ( CurrentDate ) ) ; DayOfWeek ( Get ( CurrentDate ) - 1 ) = 1 ; Day ( Get ( CurrentDate ) - 1 ) ; DayOfWeek ( Get ( CurrentDate ) - 2 ) = 1 ; Day ( Get ( CurrentDate ) - 2 ) ; DayOfWeek ( Get ( CurrentDate ) - 3 ) = 1 ; Day ( Get ( CurrentDate ) - 3 ) ; DayOfWeek ( Get ( CurrentDate ) - 4 ) = 1 ; Day ( Get ( CurrentDate ) - 4 ) ; DayOfWeek ( Get ( CurrentDate ) - 5 ) = 1 ; Day ( Get ( CurrentDate ) - 5 ) ; DayOfWeek ( Get ( CurrentDate ) - 6 ) = 1 ; Day ( Get ( CurrentDate ) - 6 ) ) //& " - " & //Month ( Get ( CurrentDate ) ) & "/" & //Case ( //DayOfWeek ( Get ( CurrentDate ) ) = 7 ; Day ( Get ( CurrentDate ) ) ; //DayOfWeek ( Get ( CurrentDate ) + 1 ) = 7 ; Day ( Get ( CurrentDate ) + 1 ) ; //DayOfWeek ( Get ( CurrentDate ) + 2 ) = 7 ; Day ( Get ( CurrentDate ) + 2 ) ; //DayOfWeek ( Get ( CurrentDate ) + 3 ) = 7 ; Day ( Get ( CurrentDate ) + 3 ) ; //DayOfWeek ( Get ( CurrentDate ) + 4 ) = 7 ; Day ( Get ( CurrentDate ) + 4 ) ; //DayOfWeek ( Get ( CurrentDate ) + 5 ) = 7 ; Day ( Get ( CurrentDate ) + 5 ) ; //DayOfWeek ( Get ( CurrentDate ) + 6 ) = 7 ; Day ( Get ( CurrentDate ) + 6 ) ) ¶ & //monthly review " " & Case ( Day ( Get ( CurrentDate ) ) > 7 ; //MonthName ( Month ( Get ( CurrentDate ) ) + 1 & "/" & 1 & "/" & 2012) ; //MonthName ( Month ( Get ( CurrentDate ) ) & "/" & 1 & "/" & 2012) ) //& ")" Month ( Get ( CurrentDate ) ) + 1 & "/" & "1" ; Month ( Get ( CurrentDate ) ) & "/" & "1" ) ]
    Set Variable [ $number; Value:1 ]
    Loop
    Set Field [ status::text; GetValue ( $reviewNames ; $number ) ]
    Set Field [ status::reviewDate; GetValue ( $reviewDates ; $number ) ]
    Set Variable [ $number; Value:$number + 1 ]
    Go to Portal Row [ Select; Next; Exit after last ]
    End Loop
    #
    Go to Field [ ]
    #

Fields used in this script	

    status::status
    status::text
    status::reviewDate

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


action buttons
	Parent Folder: [action buttons]	Next Script: [note veto view (old: opened things in new windows)]
Script Name	note veto view
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    DeleteBrainstate

Script Definition
Script Steps	

    #total: action buttons: total
#PURPOSE merge selected record's time data into one total record and then link these records so that time added in the future to any of the
merge records will be automatically added to the one total record.
#
#
#
#NOTE: the three # symbols set apart chunks of script.
#NOTE: the ﬁnish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason,
they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $userID; Value:reference::farmerID ]
#
#
#
#A) BEGIN ﬁnd selected merge records and create new total record and link all records together
#
#1 check if there are 1 or more records to merge and if not halt the script. (Can't merge if zero records are selected. 1 record can be merged
which is really making a copy of that record for instances where the user has been tracking 2 things with one brainstate but now wants to
separate the tracking of these with 2 separate brainstate records.)
If [ brainstate::groupAddCheckboxCount < 1 ]
Show Custom Dialog [ Title: "!"; Message: "At least 1 brainstates must be selected for a merge."; Buttons: “OK” ]
Halt Script
End If
#
#2 make a list of only the records to be merged
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::groupAddCheckbox; "t" ]
Perform Find [ ]
#
#
#
#BEGIN ﬁnd error 1
If [ Get ( LastError ) ≠ 0 ]
#tell user the error number.
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming merge script part A2."; Buttons: “OK” ]
#Find all records user had showing when they clicked the merge button
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
If [ steward::retiredStatus = "r" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::hide: “t” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
Halt Script
End If
If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::Show: “=” ]
[ Restore ]
December 1, 2013 17:28:54 ActionLog.fp7 - total -1-total: action buttons: total
Sort Records [ ]
[ No dialog ]
Halt Script
End If
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Halt Script
End If
#END ﬁnd error 1
#
#
#
#3 create the new total record
Go to Layout [ “01SortAndSchedule” (brainstate) ]
New Record/Request
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::linkinfo; "total of: " ]
Set Field [ brainstate::description; "NEW TOTAL RECORD the ID numbers of the records totaled by this record can be seen by either clicking or
hovering over the i at the far right of this description ﬁeld." ]
Set Field [ brainstate::groupType; "merge" ]
#
#4 link all records
Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $brainstateDisplayID; Value:brainstate::_Number ]
Go to Record/Request/Page
[ First ]
Loop
Set Field [ brainstate::groupID; $brainstateID ]
Set Field [ brainstate::groupDisplayID; $brainstateDisplayID ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#A) END ﬁnd selected merge records and create new total record and link all records together
#
#
#
Loop
#B) BEGIN add a merge record's ID# to the description of the new total record.
#
#1 make sure there is a record to be merged (this step will be important when this loop is repeated after the ﬁrst record to be merged is
omitted).
Go to Record/Request/Page
[ First ]
If [ brainstate::_lockBrainstateID ≠ brainstate::groupID ]
#
#2 capture merged ID number for total's linkinfo ﬁeld: total of: ID, ID, ID, etc.
Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
Go to Record/Request/Page
[ Last ]
Set Field [ brainstate::linkinfo; If ( WordCount ( brainstate::linkinfo ) = 2 ;
brainstate::linkinfo & $CurrentBrainstateDisplayID ;
brainstate::linkinfo & ", " & $CurrentBrainstateDisplayID ) ]
Go to Record/Request/Page
[ First ]
December 1, 2013 17:28:54 ActionLog.fp7 - total -2-total: action buttons: total Go to Record/Request/Page
[ First ]
#
#
#
#BEGIN ﬁnish
Else If [ brainstate::_lockBrainstateID = brainstate::groupID ]
#If all records are empty then the merge is complete and now the user needs to be shown the new total record and all the records that
will feed into it until they are separated.
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $brainstateID ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Layout [ “TotalSort” (brainstate) ]
Go to Field [ ]
Halt Script
#END ﬁnish
#
#
#
End If
#
#B) END add a merge record's ID# to the description of the new total record.
#
#
#
#C BEGIN ﬁnd merge record's related day records
#
#1 make a list of the ﬁrst brainstate's day records in a new window
Go to Layout [ “calcTotalSelectedList” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
Perform Find [ ]
#
#C END ﬁnd merge record's related day records
#
#
#
#D BEGIN no records found loop (this loop will either complete the merge process or ﬁnd a merge record with related day records)
#
Loop
#
#1 if records are found exit loop
Exit Loop If [ Get ( LastError ) = 0 ]
#
#2 clear the merge ﬁeld (the big X in the box on the ToBeMerged layout) and omit this record
If [ Get ( LastError ) = 401 ]
Go to Layout [ “01SortAndSchedule” (brainstate) ]
Set Field [ brainstate::groupAddCheckbox; "" ]
Omit Record
#
#
#
#BEGIN ﬁnish
If [ brainstate::_lockBrainstateID = brainstate::groupID ]
December 1, 2013 17:28:54 ActionLog.fp7 - total -3-total: action buttons: total
#If all records are empty then the merge is complete and now the user needs to be shown the new total record and all the
records that will feed into it until they are separated.
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $brainstateID ]
Perform Find [ ]
Sort Records [ Speciﬁed Sort Order: brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Go to Layout [ “TotalSort” (brainstate) ]
Go to Field [ ]
Halt Script
End If
#END ﬁnish
#
#
#
#BEGIN ﬁnd error 2
Else If [ Get ( LastError ) ≠ 0 ]
#tell user the error number
Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming merge script part D2.";
Buttons: “OK” ]
#Find all records user had showing when they clicked the merge button
Enter Find Mode [ ]
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
If [ steward::retiredStatus = "r" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::hide: “t” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
Halt Script
End If
If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::Show: “=” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
Halt Script
End If
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Halt Script
End If
#END ﬁnd error 2
#
#
#
#3 capture next records ID number for total's linkinfo ﬁeld: total of: ID, ID, ID, etc.
Set Variable [ $CurrentBrainstateID; Value:brainstate::_lockBrainstateID ]
Set Variable [ $CurrentBrainstateDisplayID; Value:brainstate::_Number ]
Go to Record/Request/Page
[ Last ]
December 1, 2013 17:28:54 ActionLog.fp7 - total -4-total: action buttons: total Go to Record/Request/Page
[ Last ]
Set Field [ brainstate::linkinfo; If ( WordCount ( brainstate::linkinfo ) = 2 ;
brainstate::linkinfo & $CurrentBrainstateDisplayID ;
brainstate::linkinfo & ", " & $CurrentBrainstateDisplayID ) ]
Go to Record/Request/Page
[ First ]
#
#4 make a list of this record's day records in a new window.
Go to Layout [ “calcTotalSelectedList” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_keyBrainstate; $CurrentBrainstateID ]
Perform Find [ ]
End Loop
#
#D END no records found loop
#
#
#
#E BEGIN create new related day records and add selected record's time to them
#
Loop
#1 ﬁnd any day records for the new brainstate that match the kfDay of the ﬁrst merge record. If this new record already has data in it,
then we want to add new data to the old data; not replace the old data with new data.
Set Variable [ $mergeDay; Value:day1::_keyDay ]
Enter Find Mode [ ]
Go to Layout [ “calcTotalNewRecord” (day2) ]
Set Field [ day2::_keyBrainstate; $brainstateID ]
Set Field [ day2::_keyDay; $mergeDay ]
Perform Find [ ]
#
#2 if no matches are found, create a new day record and put in the time of the ﬁrst the current day record
If [ Get ( LastError ) = 401 ]
New Record/Request
Set Field [ day2::_keyBrainstate; $brainstateID ]
Set Field [ day2::_keyDay; $mergeDay ]
Set Field [ day2::swStart; day2::_keyDay & " 0:00:00" ]
Go to Layout [ “calcTotalSelectedList” (day1) ]
Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
Go to Layout [ “calcTotalNewRecord” (day2) ]
Set Field [ day2::swPause; Case (
$TotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ;
$TotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ;
day2::_keyDay & " " & $TotalActivity )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
#
#
#
#BEGIN ﬁnd error 3
Else If [ Get ( LastError ) ≠ 0 ]
#tell user the error number
Show Custom Dialog [ Title: "!"; Message: "Unexpected error" & Get ( LastError ) & "peforming merge script part E2."; Buttons:
“OK” ]
#Find all records user had showing when they clicked the merge button.
Enter Find Mode [ ]
December 1, 2013 17:28:54 ActionLog.fp7 - total -5-total: action buttons: total
Set Field [ brainstate::_keyUser; $userID ]
Perform Find [ ]
If [ steward::retiredStatus = "r" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
End If
If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::hide: “t” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
Halt Script
End If
If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::Show: “=” ]
[ Restore ]
Sort Records [ ]
[ No dialog ]
Halt Script
End If
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Halt Script
#END ﬁnd error 3
#
#
#
#3 if a match is found, then add the current day's time to this day's time.
Else If [ Get ( LastError ) = 0 ]
Go to Layout [ “calcTotalSelectedList” (day1) ]
Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
Go to Layout [ “calcTotalNewRecord” (day2) ]
Set Field [ day2::swPause; Case (
$TotalActivity + day2::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day2::_keyDay & " 24:00:00" ;
$TotalActivity + day2::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day2::_keyDay & " 00:00:00" ;
day2::_keyDay & " " & ($TotalActivity + day2::swTotalActivity) )
//insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ]
End If
#
#4 repeat loop for found record's next related day record.
Go to Layout [ “calcTotalSelectedList” (day1) ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#E END create new related day records and add selected record's time to them
#
#
#
#F BEGIN go to next record with related day records to be added to the new total record.
#
Go to Layout [ “01SortAndSchedule” (brainstate) ]
#Clear the merge ﬁeld (the big X in the box on the ToBeMerged layout).
Set Field [ brainstate::groupAddCheckbox; "" ]
December 1, 2013 17:28:54 ActionLog.fp7 - total -6-total: action buttons: total
Omit Record
#
#F END go to next record with related day records to be added to the new total record.
#
#
#
End Loop
December 1, 2013 17:28:54 ActionLog.fp7 - total -7-

Fields used in this script	

    brainstate::_lockBrainstateID
    brainstate::groupID
    brainstate::sortRetired
    brainstate::description
    brainstate::groupOfGroupID
    day1::swSymbols
    reference::farmerID
    day1::_keyBrainstate
    day1::_keyUser
    reference::day1
    day1::_keyDay
    day1::swStart
    day1::updateTimeSymbol
    day1::updateTimeCurrentTimeCalc
    day1::updateTime
    day1::swPause
    day1::swOccurances
    daylog::swActivityLength

Scripts used in this script	

    showLinkedRecords
    CHUNK_lastDayUsed
    ActivityLog!!!!findAllBrainstateLogs
    FolderStopwatchCheck
    DaySelectSortThenSort
    UpdateTime
    UpdatePauseTotals

Layouts used in this script	

    calcDayTable
    logs3rows
    logs2rows
    logs1row

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [note veto view]	Parent Folder: [action buttons]	Next Script: [timerCloseWindow]
Script Name	note veto view (old: opened things in new windows)
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE merge selected record's time data into one total record and then link these records so that time added in the future to any of the merge records will be automatically added to the one total record.
    #
    #
    #BUG remove focus from any fields. This step seems to be neccessary as I periodically have been getting a -- this record is being modified in a separate window -- message. I'm leaving this step in to see if I stop getting this message.
    Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
    Go to Field [ ]
    Go to Record/Request/Page [ $recordNumber ] [ No dialog ]
    #
    #
    #
    If [ brainstate::sortRetired ≠ "" ]
    Show Custom Dialog [ Title: "!"; Message: "This record is currently retired. To make it active again, click on the r to the immediate left of the record title (if the edit controls are hidden, then first click the edit button (top left corner of this window)."; Buttons: “OK” ]
    Halt Script
    End If
    #
    #1 if the view button is showing: determine if the record is total record, and it is show the these linked records, unless the user is on the total record layout in which case halt the script. (From the user's point of view the stopwatch button will say 'view' instead of 'note' if it is a total record, and this part of the script will be activitated.)
    If [ brainstate::_lockBrainstateID = brainstate::groupID or brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    If [ Left ( Get ( LayoutName ) ; 5 ) = "total" or Left ( Get ( LayoutName ) ; 5 ) = "grand" ]
    Halt Script
    End If
    Perform Script [ “showLinkedRecords” ]
    Halt Script
    End If
    #
    #1 if the note button is showing first determine if there is a day record to update
    If [ day1::swSymbols = "" ]
    #
    #2 if not create a new one for this brainstate record and do it a new window so the user's focus is maintained (just going to the day layout and back resest the scroll bar unfortunately and I can't find away around this, but I want too!)
    Set Variable [ $kpnBrainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $userID; Value:reference::farmerID ]
    New Window [ Name: "!"; Height: 100; Width: 100 ]
    Adjust Window [ Hide ]
    Go to Layout [ “calcDayTable” (day1) ]
    New Record/Request
    Set Field [ day1::_keyBrainstate; $kpnBrainstateID ]
    Set Field [ day1::_keyUser; $userID ]
    Set Field [ day1::_keyDay; reference::day1 ]
    #
    #3 start the timer by inserting the current time in the start field
    Set Field [ day1::swStart; Get ( CurrentTimeStamp ) ]
    Close Window [ Name: "!"; Current file ]
    Go to Layout [ original layout ]
    #
    #4 sort the records if the current sort is based on time which will make this record with zero current time shoot the top or bottom of the list depending on how the user is currently shorting time. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
    Perform Script [ “DaySelectSortThenSort” ]
    Halt Script
    End If
    #
    #5 if the veto button is showing stop the stopwatch and put in the in the time stopped
    If [ day1::swSymbols = "veto" ]
    Set Field [ day1::swPause[day1::swOccurances]; Get ( CurrentTimeStamp ) ]
    #
    #5 recalculate the time for this record and check and see if is linked to any total records and if so update their time too
    Perform Script [ “UpdateTime” ]
    Perform Script [ “DaySelectSortThenSort” ]
    Halt Script
    End If
    #
    #6 if the note button is showing restart the timer by putting a new start time in next available start field for this day record
    Set Field [ day1::swStart[day1::swOccurances + 1]; Get ( CurrentTimeStamp ) ]
    If [ day1::swOccurances = 29 ]
    Set Field [ day1::swStart[29]; Get ( CurrentTimeStamp ) ]
    End If
    #
    #7 recalculate the pause between stop and start times to show user the amount of time that has passed since the last time this brainstate was active
    Perform Script [ “UpdatePauseTotals” ]
    Perform Script [ “DaySelectSortThenSort” ]

Fields used in this script	

    brainstate::sortRetired
    brainstate::_lockBrainstateID
    brainstate::groupID
    brainstate::groupOfGroupID
    day1::swSymbols
    reference::farmerID
    day1::_keyBrainstate
    day1::_keyUser
    reference::day1
    day1::_keyDay
    day1::swStart
    day1::swPause
    day1::swOccurances

Scripts used in this script	

    showLinkedRecords
    DaySelectSortThenSort
    UpdateTime
    UpdatePauseTotals

Layouts used in this script	

    calcDayTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [note veto view (old: opened things in new windows)]	Parent Folder: [action buttons]	Next Script: [UpdateTime]
Script Name	timerCloseWindow
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE return user to previous layout and end the script which is done in the button setup by selecting the 'halt script' option.
    #
    #
    #
    Go to Layout [ $$alarmLayout ]
    Set Variable [ $$alarmLayout ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [timerCloseWindow]	Parent Folder: [action buttons]	Next Script: [CHUNK_lastDayUsed]
Script Name	UpdateTime
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    note veto view
    note veto view (old: opened things in new windows)
    clearPart2
    Clear (old: opens windows to perform)

Script Definition
Script Steps	

    #PURPOSE update the time paused fields and the total and grand total fields after a user leaves a time field or clicks the veto button. They may or may not have done anything, but in case they did this update is performed.
    #
    #If user just clicked into the time field and the clicked
    #out without doing anything then stop this script as
    #there is not time change to update.
    #NEED TO STOP $$FIELDVALUE GETTING CREATED WHEN STOPWATCH BUTTON IS CLICKED, THEN THIS SCRIPT STEP SHOULD WORK.
    #SAME TIME INCLUDE VARIABLE TO STOP UPDATE OF ISSUE TIME!
    // If [ $$fieldValue = Get (ActiveFieldContents) ]
    // Exit Script [ ]
    // End If
    #
    If [ $$iphoneStop ≠ "" ]
    Set Variable [ $$iphoneStop ]
    Exit Script [ ]
    End If
    #
    Set Variable [ $$stopRecordLoad; Value:1 ]
    #
    #
    #when the user is in the time edit window we want to
    #use the recordnumber variable to focus on record in
    #in use on this window. But when user goes from this
    #edit window to the main window we want the sort script
    #to find the record to focus by looping through each record's
    #ID number until the correct record is found.
    If [ $$sortstatus ≠ "" ]
    Set Variable [ $$recordnumber; Value:Get (RecordNumber) ]
    End If
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    Freeze Window
    #If the user enters a time field but makes no changes prevent the script from continuing if on the iphone. Do not do this for the PC as the user could have dragged the time into another stopwatch, thus requring the script to udate this stopwatch's values.
    If [ Get ( SystemPlatform ) = 3 and Get ( ActiveFieldContents ) = $$fieldValue and $$fieldValue ≠ "" ]
    Go to Field [ ]
    Set Variable [ $$fieldValue ]
    Set Variable [ $$recordnumber ]
    Set Variable [ $$stopRecordLoad ]
    Halt Script
    End If
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Set Variable [ $mergeID; Value:brainstate::groupID ]
    Set Variable [ $mergeGrandID; Value:brainstate::groupOfGroupID ]
    Set Variable [ $layout; Value:Get ( LayoutName ) ]
    Set Variable [ $record; Value:Get (RecordNumber) ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $$recordFIXTOMANYVARIABLES; Value:brainstate::_lockBrainstateID ]
    // #needed by folderstopwatchcheck script in case the stopwatch being started or stopped belongs to a total record
    // Set Variable [ $$folderon; Value:brainstate::groupID ]
    // If [ day1::swSymbols = "veto" ]
    // Set Variable [ $$stopwatchON; Value:"t" ]
    // Set Variable [ $$onoff; Value:"" ]
    // Else If [ day1::swSymbols = "note" or $$onoff = "note" ]
    // Set Variable [ $$stopwatchON; Value:"f" ]
    // Set Variable [ $$onoff; Value:"" ]
    // End If
    #
    #
    #
    #A) BEGIN go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of the window while performing the script.
    #
    #1 exit field the user is in so that they are returned to a clean layout when done
    Go to Field [ ]
    #
    // #2 open a new window and hide it
    // New Window [ Name: "UpateTime"; Height: 100; Width: 100 ]
    // Adjust Window [ Hide ]
    #
    #3 go to the first record
    Go to Record/Request/Page [ First ]
    Loop
    If [ day1::_lockDay = "" and brainstate::_lockBrainstateID ≠ brainstate::groupID ]
    Omit Record
    Else If [ day1::_lockDay ≠ "" or brainstate::_lockBrainstateID = brainstate::groupID ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End If
    End Loop
    Go to Record/Request/Page [ First ]
    #
    #A) END go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of the window while performing the script.
    #
    #
    #
    Loop
    #
    #B) BEGIN if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer again, but if they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
    #
    #1 get the day records ID number
    If [ day1::_lockDay ≠ "" and day1::swTotalActivity = "" ]
    Set Variable [ $DayID; Value:day1::_lockDay ]
    #needed by folderstopwatchcheck script
    Set Variable [ $$stopwatchON; Value:"f" ]
    #
    #2 tag the main record as updated so any total and grand totals it is a part of get updated too
    Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
    Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
    #
    #3 find the day record ad delete it
    Go to Layout [ “calcDayTable” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_lockDay; $DayID ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    #
    #B) END if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer again, but if they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
    #
    #
    #
    #C) START skip the records that have not been changed.
    #
    #1 compare the record's total time against the last
    #update time recorded, and if they are the same go
    #to the next record.
    #
    #The updatetime field is populated by this script as a
    #way of flagging when a record has been updated by
    #this script.
    #
    #User may have used the drag feature to change
    #multiple records and the only way to know what has
    #been changed is to compare these time fields.
    // If [ day1::updateTime ≠ day1::updateTimeCurrentTimeCalc and day1::swBugField = "note" ]
    If [ day1::swSymbols ≠ day1::updateTimeSymbol or day1::updateTime ≠ day1::updateTimeCurrentTimeCalc ]
    #
    #2 if the record is a total or grand total record, go to the next record (these will be updated later in the script).
    If [ brainstate::groupID ≠ brainstate::_lockBrainstateID ]
    #
    #C) END skip the records that have not been changed.
    #
    #
    #
    #D) BEGIN update changed record's flags
    #
    #1 equalize these two times, thus unflagging this record as needing updating.
    Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
    #
    #2 flag this record as changed if it belongs to a total record, so later in this script that record's time can be updated
    Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
    #
    #D) END update changed record's flags
    #
    #
    #
    #E) BEGIN update the pause time fields
    #
    #This script step has been removed. Initially, I thought since most records only have one time event to skip the update pause step for these records. However, in testing I found that when a timer is started for a second time event a pause time is calculated resulting in a gray bar in the bar chart. If the user then deletes this second start time, this now disabled script stops that bar from being removed because when this script gets to this step the field is blank and so no calculation is done. I decided to leave this failure in just in case I forgot why this doesn't work, try it again, and fail to not perform the correct test, which I did until by accident noticed something wrong!
    // #1 if there is only one time, skip the following steps to recalculate the time paused between more than one time.
    // If [ day1::swActivityLength[2] ≠ "" ]
    #
    #1 clear all PauseTotal fields, which is necessary because a user may have reduced the number of activity times, thus reducing the number of pauses. NOTE: pause field repetition 1 is never used as their is no pause between time zero and the first time.
    Set Variable [ $repetition; Value:2 ]
    Loop
    Set Field [ day1::swPauseLength[$repetition]; Get ( CurrentTime ) ]
    Clear [ day1::swPauseLength[$repetition] ] [ Select ]
    Set Variable [ $repetition; Value:$repetition+1 ]
    Exit Loop If [ $repetition = 31 ]
    End Loop
    #
    #2 calculate all pause times between activity times. This step is stopped when the next time to calculate a pause between is blank or when this loop has reached the last repitition (this test is neccessary because there are only 30 repetitions, so there will not be a blank 31 to detect, thus reaching 31 has to trigger a stop).
    Set Variable [ $repetition; Value:2 ]
    Loop
    Set Field [ day1::swPauseLength[$repetition]; day1::swStart[$repetition] - day1::swPause[$repetition-1] ]
    Set Variable [ $repetition; Value:$repetition+1 ]
    Exit Loop If [ day1::swStart[$repetition] = "" ]
    Exit Loop If [ $repetition = 31 ]
    End Loop
    #
    #E) END update the pause time fields
    #
    #
    #E2) UPDATE the time in any dependent issues.
    If [ $$stopCHUNK_updateIssueCategoryTime ≠ 1 ]
    Set Variable [ $$updateDay; Value:day1::_lockDay ]
    Perform Script [ “CHUNK_updateIssueCategoryTime” ]
    Set Variable [ $$updateDay ]
    End If
    #
    #
    End If
    End If
    #
    Set Variable [ $$stopCHUNK_updateIssueCategoryTime ]
    #
    #
    #F) BEGIN go to next record
    #
    #
    #
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #F) END go to next record
    #
    #
    #
    Loop
    #
    #G) BEGIN find all user total records that need to be udated
    #
    #1 find records
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $user ]
    Set Field [ brainstate::groupUpdate; "u" ]
    Perform Find [ ]
    #
    #2 if no records are found go to step
    Exit Loop If [ Get ( LastError ) = 401 ]
    #
    #
    #
    #BEGIN error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime step G1."; Buttons: “OK” ]
    Go to Record/Request/Page [ $record ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    Set Variable [ $$stopRecordLoad ]
    Exit Script [ ]
    End If
    #END error 1
    #
    #
    #
    #G) END find all user total records that need to be udated
    #
    #
    #
    #H) BEGIN update found record
    #
    #1 unflag this total record for total update
    Clear [ brainstate::groupUpdate ] [ Select ]
    #
    #1b set variables so total record's conditional formatting will match that of the stopwatch being updated.
    If [ day1::swSymbols ≠ day1::updateTimeSymbol or $$onoff = "note" ]
    Set Variable [ $$folderon; Value:brainstate::groupID ]
    If [ day1::swSymbols = "veto" ]
    Set Variable [ $$stopwatchON; Value:"t" ]
    Set Variable [ $$onoff; Value:"" ]
    Else If [ day1::swSymbols = "note" or $$onoff = "note" ]
    Set Variable [ $$stopwatchON; Value:"f" ]
    Set Variable [ $$onoff; Value:"" ]
    End If
    End If
    Set Field [ day1::updateTimeSymbol; day1::swSymbols ]
    #
    #2 find its linked records
    Set Variable [ $mergeto; Value:brainstate::groupID ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $mergeto ]
    // Set Field [ brainstate::sortRetired; "=" ]
    Perform Find [ ]
    Perform Script [ “FolderStopwatchCheck” ]
    #3 go to the first record
    Loop
    If [ day1::swStart = "" and brainstate::_lockBrainstateID ≠ brainstate::groupID ]
    Omit Record
    Else If [ day1::swStart ≠ "" or brainstate::_lockBrainstateID = brainstate::groupID ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End If
    End Loop
    #
    Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” brainstate::description; ascending ] [ Restore; No dialog ]
    #
    #3 flag for grand total update
    Go to Record/Request/Page [ First ]
    Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
    #
    #4 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially by deleting its current day record and creating a new blank one).
    If [ day1::_keyDay = "" ]
    Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “calcDayTable” (day1) ]
    New Record/Request
    Set Field [ day1::_keyBrainstate; $BrainstateID ]
    Insert Calculated Result [ day1::_keyDay; reference::day1 ] [ Select ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
    Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
    #
    Loop
    #
    #5 go to the last record
    Go to Record/Request/Page [ Last ]
    #
    #6 if there are no records to add then delete the just created related day record for this total record (this action would be caused by the user deleting all the time in the linked records).
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    If [ day1::swTotalActivity = "0:00:00" ]
    Set Variable [ $dayID; Value:day1::_lockDay ]
    Go to Layout [ “calcDayTable” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_lockDay; $dayID ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    #
    #7 go the next part of the script once there are no more records to add
    Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    #
    #8 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
    Else If [ day1::_keyDay = "" ]
    Omit Record
    Else If [ day1::_keyDay ≠ "" ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Omit Record
    Go to Record/Request/Page [ First ]
    Insert Calculated Result [ day1::swPause; Case ( $TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ; $TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ; day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ] [ Select ]
    End If
    End Loop
    #
    #H) END update found record
    #
    #
    #
    Loop
    #
    #I) BEGIN find all user GRAND total records that need to be udated
    #
    #1 find records
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $user ]
    Set Field [ brainstate::groupOfGroupUpdate; "u" ]
    Perform Find [ ]
    #
    #2 if no records are found go to step
    Exit Loop If [ Get ( LastError ) = 401 ]
    #
    #
    #
    #BEGIN error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime step i1."; Buttons: “OK” ]
    // Close Window [ Name: "UpateTime"; Current file ]
    Go to Record/Request/Page [ $record ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    Set Variable [ $$stopRecordLoad ]
    Exit Script [ ]
    End If
    #END error 1
    #
    #
    #
    #I) END find all user total records that need to be udated
    #
    #
    #
    #J) BEGIN update found record
    #
    #1 unflag this total record for grand total update
    Clear [ brainstate::groupOfGroupUpdate ] [ Select ]
    #
    #2 find its linked records
    Set Variable [ $mergeto; Value:brainstate::groupOfGroupID ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $mergeto ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    #
    #3 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially by deleting its current day record and creating a new blank one).
    Go to Record/Request/Page [ First ]
    If [ day1::_keyDay = "" ]
    Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “calcDayTable” (day1) ]
    New Record/Request
    Set Field [ day1::_keyBrainstate; $BrainstateID ]
    Insert Calculated Result [ day1::_keyDay; reference::day1 ] [ Select ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
    Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
    #
    Loop
    #
    #4 go to the last record
    Go to Record/Request/Page [ Last ]
    #
    #5 if there are no records to add then delete the just created related day record for this total record (this action would be caused by the user deleting all the time in the linked records).
    If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    If [ day1::swTotalActivity = "0:00:00" ]
    Set Variable [ $dayID; Value:day1::_lockDay ]
    Go to Layout [ “calcDayTable” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_lockDay; $dayID ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    #
    #6 go the next part of the script once there are no more records to add
    Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #
    #7 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
    Else If [ day1::_keyDay = "" ]
    Omit Record
    Else If [ day1::_keyDay ≠ "" ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Omit Record
    Go to Record/Request/Page [ First ]
    Insert Calculated Result [ day1::swPause; Case ( $TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ; $TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ; day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ] [ Select ]
    End If
    End Loop
    End Loop
    #
    #J) END update found record
    #
    #
    #
    End Loop
    #
    #Have to go back to orginal layout, otherwise Hide Window step causes the data to be delayed showing up after the next interation of the stopwatch script runs thru.
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$record ]
    Perform Find [ ]
    Go to Layout [ $layout ]
    Set Variable [ $$stopRecordLoad ]
    If [ $mergeID ≠ "" and Left ( $layout ; 5 ) = "Total" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $mergeID ]
    Perform Find [ ]
    Else If [ $mergeGrandID ≠ "" and Left ( $layout ; 5 ) = "Grand" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $mergeGrandID ]
    Perform Find [ ]
    Else If [ Left ( $layout ; 5 ) ≠ "Total" ]
    Perform Script [ “goBackButton_FindRecordsChunk” ]
    Perform Script [ “CHUNK_lastDayUsed” ]
    // Perform Script [ “FolderStopwatchCheck” ]
    Perform Script [ “DaySelectSortThenSort” ]
    Halt Script
    End If
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    Perform Script [ “CHUNK_lastDayUsed” ]
    // Perform Script [ “FolderStopwatchCheck” ]
    Perform Script [ “DaySelectSortThenSort” ]

Fields used in this script	

    reference::farmerID
    brainstate::groupID
    brainstate::groupOfGroupID
    brainstate::_lockBrainstateID
    day1::swSymbols
    day1::_lockDay
    day1::swTotalActivity
    brainstate::groupUpdate
    brainstate::groupOfGroupUpdate
    day1::updateTime
    day1::updateTimeCurrentTimeCalc
    day1::swBugField
    day1::updateTimeSymbol
    day1::swActivityLength
    day1::swPauseLength
    day1::swStart
    day1::swPause
    brainstate::_keyUser
    brainstate::sortRetired
    brainstate::groupType
    brainstate::description
    day1::_keyDay
    day1::_keyBrainstate
    reference::day1
    steward::retiredStatus

Scripts used in this script	

    CHUNK_updateIssueCategoryTime
    FolderStopwatchCheck
    goBackButton_FindRecordsChunk
    CHUNK_lastDayUsed
    DaySelectSortThenSort

Layouts used in this script	

    calcBrainstateTable
    calcDayTable
    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [UpdateTime]	Parent Folder: [action buttons]	Next Script: [UpdateTime (old: opened things in new windows)]
Script Name	CHUNK_lastDayUsed
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    note veto view
    UpdateTime
    clearPart2
    updateNumberOfDaysSince

Script Definition
Script Steps	

    #PURPOSE go the selected farmer's records from the createEditFarmer layout. (This is script is identical to the switchFarmer script except for step 1, which is required because the reference field is not available on this layout, and so the user's ID must be taken from the user table, not the reference table.)
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #
    #
    #
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “logByDate” (logs) ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyBrainstate; $brainstateID ]
    Perform Find [ ]
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ original layout ]
    Exit Script [ ]
    End If
    Sort Records [ Specified Sort Order: logs::_keyDay; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Field [ brainstate::DateOfLastUse; logs::_keyDay ]
    Set Variable [ $date; Value:logs::_keyDay ]
    If [ brainstate::groupID ≠ "" ]
    Set Variable [ $brainstateID; Value:brainstate::groupID ]
    Enter Find Mode [ ]
    Set Field [ logs::_keyBrainstate; $brainstateID ]
    Perform Find [ ]
    If [ Get ( LastError ) = 401 ]
    Go to Layout [ original layout ]
    Exit Script [ ]
    End If
    Sort Records [ Specified Sort Order: logs::_keyDay; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    If [ reference::day1 ≠ $date ]
    Set Field [ brainstate::DateOfLastUse; logs::_keyDay ]
    Else If [ reference::day1 = $date ]
    Set Field [ brainstate::DateOfLastUse; $date ]
    End If
    End If
    Go to Layout [ original layout ]

Fields used in this script	

    brainstate::_lockBrainstateID
    logs::_keyBrainstate
    logs::_keyDay
    brainstate::DateOfLastUse
    brainstate::groupID
    reference::day1

Scripts used in this script	

Layouts used in this script	

    logByDate

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CHUNK_lastDayUsed]	Parent Folder: [action buttons]	Next Script: [UpdatePauseTotals]
Script Name	UpdateTime (old: opened things in new windows)
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE update the time paused fields and the total and grand total fields after a user leaves a time field or clicks the veto button. They may or may not have done anything, but in case they did this update is performed.
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    #A) BEGIN go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of the window while performing the script.
    #
    #1 exit field the user is in so that they are returned to a clean layout when done
    Go to Field [ ]
    #
    #2 open a new window and hide it
    New Window [ Name: "UpateTime"; Height: 100; Width: 100 ]
    Adjust Window [ Hide ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    #
    #3 go to the first record
    Go to Record/Request/Page [ First ]
    #
    #A) END go to a new window and hide it to preserve focus in user's current window while peforming this script, and to hide the strobe effect of the window while performing the script.
    #
    #
    #
    Loop
    #
    #B) BEGIN if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer again, but if they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
    #
    #1 get the day records ID number
    If [ day1::_lockDay ≠ "" and day1::swTotalActivity = "" ]
    Set Variable [ $DayID; Value:day1::_lockDay ]
    #
    #2 tag the main record as updated so any total and grand totals it is a part of get updated too
    Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
    Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
    #
    #3 find the day record ad delete it
    Go to Layout [ “calcDayTable” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_lockDay; $DayID ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    #
    #B) END if the user deleted all time, then delete the related day record. (The user may decide they want to begin this timer again, but if they don't a blank day record will exist which causes conditional formatting issues on the layouts.)
    #
    #
    #
    #C) START skip the records that have not been changed.
    #
    #1 compare the record's total time against the last update time recorded, and if they are the same go to the next record. The updatetime field is populated by this script as a way of flagging when a record has been updated by this script. User may have used the drag feature to change multiple records and the only way to know what has been changed is to compare these time fields.
    If [ day1::updateTime ≠ day1::updateTimeCurrentTimeCalc ]
    #
    #2 if the record is a total or grand total record, go to the next record (these will be updated later in the script).
    If [ brainstate::groupID ≠ brainstate::_lockBrainstateID ]
    #
    #C) END skip the records that have not been changed.
    #
    #
    #
    #D) BEGIN update changed record's flags
    #
    #1 equalize these two times, thus unflagging this record as needing updating.
    Set Field [ day1::updateTime; day1::updateTimeCurrentTimeCalc ]
    #
    #2 flag this record as changed if it belongs to a total record, so later in this script that record's time can be updated
    Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
    #
    #D) END update changed record's flags
    #
    #
    #
    #E) BEGIN update the pause time fields
    #
    #This script step has been removed. Initially, I thought since most records only have one time event to skip the update pause step for these records. However, in testing I found that when a timer is started for a second time event a pause time is calculated resulting in a gray bar in the bar chart. If the user then deletes this second start time, this now disabled script stops that bar from being removed because when this script gets to this step the field is blank and so no calculation is done. I decided to leave this failure in just in case I forgot why this doesn't work, try it again, and fail to not perform the correct test, which I did until by accident noticed something wrong!
    // #1 if there is only one time, skip the following steps to recalculate the time paused between more than one time.
    // If [ day1::swActivityLength[2] ≠ "" ]
    #
    #1 clear all PauseTotal fields, which is necessary because a user may have reduced the number of activity times, thus reducing the number of pauses. NOTE: pause field repetition 1 is never used as their is no pause between time zero and the first time.
    Set Variable [ $repetition; Value:2 ]
    Loop
    Set Field [ day1::swPauseLength[$repetition]; Get ( CurrentTime ) ]
    Clear [ day1::swPauseLength[$repetition] ] [ Select ]
    Set Variable [ $repetition; Value:$repetition+1 ]
    Exit Loop If [ $repetition = 31 ]
    End Loop
    #
    #2 calculate all pause times between activity times. This step is stopped when the next time to calculate a pause between is blank or when this loop has reached the last repitition (this test is neccessary because there are only 30 repetitions, so there will not be a blank 31 to detect, thus reaching 31 has to trigger a stop).
    Set Variable [ $repetition; Value:2 ]
    Loop
    Set Field [ day1::swPauseLength[$repetition]; day1::swStart[$repetition] - day1::swPause[$repetition-1] ]
    Set Variable [ $repetition; Value:$repetition+1 ]
    Exit Loop If [ day1::swStart[$repetition] = "" ]
    Exit Loop If [ $repetition = 31 ]
    End Loop
    #
    #E) END update the pause time fields
    #
    #
    #
    End If
    End If
    #
    #
    #
    #F) BEGIN go to next record
    #
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #F) END go to next record
    #
    #
    #
    Loop
    #
    #G) BEGIN find all user total records that need to be udated
    #
    #1 find records
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $user ]
    Set Field [ brainstate::groupUpdate; "u" ]
    Perform Find [ ]
    #
    #2 if no records are found go to step
    Exit Loop If [ Get ( LastError ) = 401 ]
    #
    #
    #
    #BEGIN error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime step G1."; Buttons: “OK” ]
    Close Window [ Name: "UpateTime"; Current file ]
    Exit Script [ ]
    End If
    #END error 1
    #
    #
    #
    #G) END find all user total records that need to be udated
    #
    #
    #
    #H) BEGIN update found record
    #
    #1 unflag this total record for total update
    Clear [ brainstate::groupUpdate ] [ Select ]
    #
    #2 find its linked records
    Set Variable [ $mergeto; Value:brainstate::groupID ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $mergeto ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” brainstate::description; ascending ] [ Restore; No dialog ]
    #
    #3 flag for grand total update
    Go to Record/Request/Page [ First ]
    Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
    #
    #4 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially by deleting its current day record and creating a new blank one).
    If [ day1::_keyDay = "" ]
    Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “calcDayTable” (day1) ]
    New Record/Request
    Set Field [ day1::_keyBrainstate; $BrainstateID ]
    Insert Calculated Result [ day1::_keyDay; reference::day1 ] [ Select ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
    Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
    #
    Loop
    #
    #5 go to the last record
    Go to Record/Request/Page [ Last ]
    #
    #6 if there are no records to add then delete the just created related day record for this total record (this action would be caused by the user deleting all the time in the linked records).
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    If [ day1::swTotalActivity = "0:00:00" ]
    Set Variable [ $dayID; Value:day1::_lockDay ]
    Go to Layout [ “calcDayTable” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_lockDay; $dayID ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    #
    #7 go the next part of the script once there are no more records to add
    Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    #
    #8 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
    Else If [ day1::_keyDay = "" ]
    Omit Record
    Else If [ day1::_keyDay ≠ "" ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Omit Record
    Go to Record/Request/Page [ First ]
    Insert Calculated Result [ day1::swPause; Case ( $TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ; $TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ; day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ] [ Select ]
    End If
    End Loop
    #
    #H) END update found record
    #
    #
    #
    Loop
    #
    #I) BEGIN find all user GRAND total records that need to be udated
    #
    #1 find records
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $user ]
    Set Field [ brainstate::groupOfGroupUpdate; "u" ]
    Perform Find [ ]
    #
    #2 if no records are found go to step
    Exit Loop If [ Get ( LastError ) = 401 ]
    #
    #
    #
    #BEGIN error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CheckUpdateTime step i1."; Buttons: “OK” ]
    Close Window [ Name: "UpateTime"; Current file ]
    Exit Script [ ]
    End If
    #END error 1
    #
    #
    #
    #I) END find all user total records that need to be udated
    #
    #
    #
    #J) BEGIN update found record
    #
    #1 unflag this total record for grand total update
    Clear [ brainstate::groupOfGroupUpdate ] [ Select ]
    #
    #2 find its linked records
    Set Variable [ $mergeto; Value:brainstate::groupOfGroupID ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $mergeto ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    #
    #3 if linked records are found, first reset the total record's time to zero in case the amount of time has decreased (essentially by deleting its current day record and creating a new blank one).
    Go to Record/Request/Page [ First ]
    If [ day1::_keyDay = "" ]
    Set Variable [ $BrainstateID; Value:brainstate::_lockBrainstateID ]
    Go to Layout [ “calcDayTable” (day1) ]
    New Record/Request
    Set Field [ day1::_keyBrainstate; $BrainstateID ]
    Insert Calculated Result [ day1::_keyDay; reference::day1 ] [ Select ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    Set Field [ day1::swStart; day1::_keyDay & " 0:00:00" ]
    Set Field [ day1::swPause; day1::_keyDay & " 0:00:00" ]
    #
    Loop
    #
    #4 go to the last record
    Go to Record/Request/Page [ Last ]
    #
    #5 if there are no records to add then delete the just created related day record for this total record (this action would be caused by the user deleting all the time in the linked records).
    If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    If [ day1::swTotalActivity = "0:00:00" ]
    Set Variable [ $dayID; Value:day1::_lockDay ]
    Go to Layout [ “calcDayTable” (day1) ]
    Enter Find Mode [ ]
    Set Field [ day1::_lockDay; $dayID ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    End If
    #
    #6 go the next part of the script once there are no more records to add
    Exit Loop If [ brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    #
    #7 if there is a record to add capture its total time, omit it, go the first record and add this time to current total time.
    Else If [ day1::_keyDay = "" ]
    Omit Record
    Else If [ day1::_keyDay ≠ "" ]
    Set Variable [ $TotalActivity; Value:day1::swTotalActivity ]
    Omit Record
    Go to Record/Request/Page [ First ]
    Insert Calculated Result [ day1::swPause; Case ( $TotalActivity + day1::swTotalActivity > Time ( 23 ; 59 ; 59 ) ; day1::_keyDay & " 24:00:00" ; $TotalActivity + day1::swTotalActivity < Time ( 0 ; 0 ; 0 ) ; day1::_keyDay & " 00:00:00" ; day1::_keyDay & " " & ($TotalActivity + day1::swTotalActivity) ) //insures that no more than 24 hours will be put into a day and that a day with negative time does not cause an error. ] [ Select ]
    End If
    End Loop
    End Loop
    #
    #J) END update found record
    #
    #
    #
    End Loop
    #
    #Have to go back to orginal layout, otherwise Hide Window step causes the data to be delayed showing up after the next interation of the stopwatch script runs thru.
    Close Window [ Name: "UpateTime"; Current file ]
    Perform Script [ “DaySelectSortThenSort” ]

Fields used in this script	

    reference::farmerID
    day1::_lockDay
    day1::swTotalActivity
    brainstate::groupID
    brainstate::groupUpdate
    brainstate::groupOfGroupID
    brainstate::groupOfGroupUpdate
    day1::updateTime
    day1::updateTimeCurrentTimeCalc
    brainstate::_lockBrainstateID
    day1::swActivityLength
    day1::swPauseLength
    day1::swStart
    day1::swPause
    brainstate::_keyUser
    brainstate::groupType
    brainstate::description
    day1::_keyDay
    day1::_keyBrainstate
    reference::day1

Scripts used in this script	

    DaySelectSortThenSort

Layouts used in this script	

    calcBrainstateTable
    calcDayTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [UpdateTime (old: opened things in new windows)]	Parent Folder: [action buttons]	Next Script: [clearPart1]
Script Name	UpdatePauseTotals
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    note veto view
    note veto view (old: opened things in new windows)

Script Definition
Script Steps	

    #PURPOSE update the time paused fields and the total and grand total fields after a user leaves a time field or clicks the veto button. They may or may not have done anything, but in case they did this update is performed.
    #
    #
    #1 if there is only one time, skip the following steps to recalculate the time paused between more than one time.
    If [ day1::swActivityLength[2] ≠ "" ]
    #
    #2 calculate all pause times between activity times. This step is stopped when the next time to calculate a pause between is blank or when this loop has reached the last repitition (this test is neccessary because there are only 30 repetitions, so there will not be a blank 31 to detect, thus reaching 31 has to trigger a stop).
    Set Variable [ $repetition; Value:2 ]
    Loop
    Set Field [ day1::swPauseLength[$repetition]; day1::swStart[$repetition] - day1::swPause[$repetition-1] ]
    Set Variable [ $repetition; Value:$repetition+1 ]
    Exit Loop If [ day1::swStart[$repetition] = "" ]
    Exit Loop If [ $repetition = 31 ]
    End Loop
    End If

Fields used in this script	

    day1::swActivityLength
    day1::swStart
    day1::swPause
    day1::swPauseLength

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [UpdatePauseTotals]	Parent Folder: [action buttons]	Next Script: [clearPart2]
Script Name	clearPart1
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ day1::swActivityLength = "" ]
    Exit Script [ ]
    End If
    Set Variable [ $$warning; Value:brainstate::_lockBrainstateID ]
    Refresh Window
    Show Custom Dialog [ Title: "?"; Message: "Clear all today's times for" & ¶ & ¶ & brainstate::description & "?"; Buttons: “Cancel”, “OK” ]
    If [ Get ( LastMessageChoice ) = 1 ]
    Set Variable [ $$warning ]
    Refresh Window
    Halt Script
    End If
    Set Variable [ $$warning ]
    Refresh Window
    Set Variable [ $$recordFIXTOMANYVARIABLES; Value:brainstate::_lockBrainstateID ]
    Perform Script [ “clearPart2” ]

Fields used in this script	

    day1::swActivityLength
    brainstate::_lockBrainstateID
    brainstate::description

Scripts used in this script	

    clearPart2

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [clearPart1]	Parent Folder: [action buttons]	Next Script: [Clear (old: opens windows to perform)]
Script Name	clearPart2
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    clearPart1

Script Definition
Script Steps	

    #PURPOSE just like on a stopwatch, this script activated by the clear button deletes the time recorded for a brainstate record's related day record. Rather than just return the time to zero, this scripts deletes the record in case the user made a mistake in starting a timer for a particular brainstate record and will not be using it at all, in which case if it is not deleted, this unused record will fill up the database wasting space.
    #
    #1 check to insure that there is a record to clear and if not hast the script, then check to insure if there is a record that it is not a total or grand total record. These total records are sums of other records and so their times are not created by the stopwatch script and should not be cleared by this script. They will be cleared if there linked records' times are cleared by the UpdateTime script.
    If [ day1::_keyDay = "" or brainstate::_lockBrainstateID = brainstate::groupID or brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    Set Variable [ $$recordFIXTOMANYVARIABLES ]
    Halt Script
    End If
    #
    #preserve stopwatch symbol for use in updatetime script as it will be deleted by this script
    Set Variable [ $$onoff; Value:"note" ]
    #BUG remove focus from any fields. This step seems to be neccessary as I periodically have been getting a -- this record is being modified in a separate window -- message. I'm leaving this step in to see if I stop getting this message.
    Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
    Go to Field [ ]
    Go to Record/Request/Page [ $recordNumber ] [ No dialog ]
    #
    #
    #
    #2 capture the day record's ID number
    Set Variable [ $dayID; Value:day1::_lockDay ]
    #
    // #3 open a new window to perform the delete. This is neccessary because just going to the day layout and then back to the brainstate layout will reset the scroll and confuse the user. When a new window is used the scroll and focus on the orignal layout is not changed.
    // New Window [ Name: "Clear"; Height: 2; Width: 2 ]
    // Adjust Window [ Hide ]
    #
    #3 find and delete the day record
    Go to Layout [ “calcDayTable” (day1) ]
    Enter Find Mode [ ]
    Insert Calculated Result [ day1::_lockDay; $dayID ] [ Select ]
    Perform Find [ ]
    #
    #Capture day key to remove time from an issues records
    #that currently have time from this day attributed to them.
    Set Variable [ $$updateDay; Value:day1::_lockDay ]
    Set Variable [ $$clear; Value:1 ]
    Set Variable [ $$stopRecordLoad; Value:1 ]
    Delete Record/Request [ No dialog ]
    Set Variable [ $$stopRecordLoad ]
    Go to Layout [ original layout ]
    Perform Script [ “CHUNK_lastDayUsed” ]
    #
    #4 determine if the record whose time was just cleared is linked to a total and if so flag it as changed and run the UpdateTime script to update its total record's time.
    Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
    If [ brainstate::groupID ≠ "" ]
    #
    #Update time in issue records if neccessary.
    Perform Script [ “CHUNK_updateIssueCategoryTime” ]
    Set Variable [ $$clear ]
    #
    // #Reload log record in case current variables are
    // #set for log record that was just deleted/cleared.
    // Select Window [ Name: "Activity Log"; Current file ]
    // If [ Get (LastError) ≠ 112 //window missing ]
    // Perform Script [ “LoadLogrecordID” ]
    // End If
    Select Window [ Name: "Timer"; Current file ]
    Set Variable [ $$stopCHUNK_updateIssueCategoryTime; Value:1 ]
    #
    #Update time for affected total record if any and for
    #other brainstate records as user may have dragged
    #time to other records before clearing this one, and
    #so system needs to update the time in those records.
    Perform Script [ “UpdateTime” ]
    End If
    #
    #5 determine if the user is currently sorting by time and if so sort re-sort the records to remove this record from its current position in the time sort. (It should be listed in alphabetical order under the list of records sorted by their times as this record no longer has any time associated with it.)
    Go to Field [ ]

Fields used in this script	

    day1::_keyDay
    brainstate::_lockBrainstateID
    brainstate::groupID
    brainstate::groupOfGroupID
    day1::_lockDay
    brainstate::groupUpdate

Scripts used in this script	

    CHUNK_lastDayUsed
    CHUNK_updateIssueCategoryTime
    LoadLogrecordID
    UpdateTime

Layouts used in this script	

    calcDayTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [clearPart2]	Parent Folder: [action buttons]	Next Script: [newBrainstateOnTotalLayouts]
Script Name	Clear (old: opens windows to perform)
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE just like on a stopwatch, this script activated by the clear button deletes the time recorded for a brainstate record's related day record. Rather than just return the time to zero, this scripts deletes the record in case the user made a mistake in starting a timer for a particular brainstate record and will not be using it at all, in which case if it is not deleted, this unused record will fill up the database wasting space.
    #
    #
    #BUG remove focus from any fields. This step seems to be neccessary as I periodically have been getting a -- this record is being modified in a separate window -- message. I'm leaving this step in to see if I stop getting this message.
    Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
    Go to Field [ ]
    Go to Record/Request/Page [ $recordNumber ] [ No dialog ]
    #
    #
    #1 check to insure that there is a record to clear and if not hast the script, then check to insure if there is a record that it is not a total or grand total record. These total records are sums of other records and so their times are not created by the stopwatch script and should not be cleared by this script. They will be cleared if there linked records' times are cleared by the UpdateTime script.
    If [ day1::_keyDay = "" or brainstate::_lockBrainstateID = brainstate::groupID or brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    Halt Script
    End If
    #
    #2 capture the day record's ID number
    Set Variable [ $dayID; Value:day1::_lockDay ]
    #
    #3 open a new window to perform the delete. This is neccessary because just going to the day layout and then back to the brainstate layout will reset the scroll and confuse the user. When a new window is used the scroll and focus on the orignal layout is not changed.
    New Window [ Name: "Clear"; Height: 2; Width: 2 ]
    Adjust Window [ Hide ]
    #
    #3 find and delete the day record then close the window
    Go to Layout [ “calcDayTable” (day1) ]
    Enter Find Mode [ ]
    Insert Calculated Result [ day1::_lockDay; $dayID ] [ Select ]
    Perform Find [ ]
    Delete Record/Request [ No dialog ]
    Go to Layout [ original layout ]
    Close Window [ Name: "Clear"; Current file ]
    #
    #4 determine if the record whose time was just cleared is linked to a total and if so flag it as changed and run the UpdateTime script to update its total record's time.
    Set Field [ brainstate::groupUpdate; If ( brainstate::groupID ≠ "" ; "u" ; "" ) ]
    If [ brainstate::groupID ≠ "" ]
    Perform Script [ “UpdateTime” ]
    End If
    #
    #5 determine if the user is currently sorting by time and if so sort re-sort the records to remove this record from its current position in the time sort. (It should be listed in alphabetical order under the list of records sorted by their times as this record no longer has any time associated with it.)
    Perform Script [ “sortRestoreAfterScript” ]
    Go to Field [ ]

Fields used in this script	

    day1::_keyDay
    brainstate::_lockBrainstateID
    brainstate::groupID
    brainstate::groupOfGroupID
    day1::_lockDay
    brainstate::groupUpdate

Scripts used in this script	

    UpdateTime
    sortRestoreAfterScript

Layouts used in this script	

    calcDayTable

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [Clear (old: opens windows to perform)]	Parent Folder: [action buttons]	Next Script: [newBrainstateOnMainLayouts]
Script Name	newBrainstateOnTotalLayouts
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE create a new record for the user (but do not check hide automatically)
    #
    #
    #
    #1 capture the user's ID number
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #2 create a new record
    New Record/Request
    #
    #3 assign is to the user
    Set Field [ brainstate::_keyUser; $userID ]
    Commit Records/Requests [ Skip data entry validation; No dialog ]
    #
    #4 records must be sorted by ID number, otherwise as soon as the brainstate name field is exited the database sorts the brainstate list by whatever current sort is selected, and the user will see their newly created record disappear. Step 1 of sorting by ID is to clear the reference::sort field which is used to conditionally formate the label of the currnt sort. 2 sort the records so the new record is the first record, then 3 go to that first records brainstate name field.
    Clear [ reference::sort ] [ Select ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    #
    #5 put cursor in title text box for the user to enter a title
    Go to Field [ brainstate::description ]

Fields used in this script	

    reference::farmerID
    brainstate::_keyUser
    reference::sort
    brainstate::_lockBrainstateID
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newBrainstateOnTotalLayouts]	Parent Folder: [action buttons]	Next Script: [newFarmer]
Script Name	newBrainstateOnMainLayouts
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE create a new record for the user and check hide automatically so record will show up on main page if requested by user (I know, the field name should be changed)
    #
    #
    #
    #1 capture the user's ID number
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #2 create a new record
    New Record/Request
    #
    #3 assign is to the user and check hide field
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::hide; "t" ]
    Commit Records/Requests [ Skip data entry validation; No dialog ]
    #
    #4 records must be sorted by ID number, otherwise as soon as the brainstate name field is exited the database sorts the brainstate list by whatever current sort is selected, and the user will see their newly created record disappear. Step 1 of sorting by ID is to clear the reference::sort field which is used to conditionally formate the label of the currnt sort. 2 sort the records so the new record is the first record, then 3 go to that first records brainstate name field.
    Clear [ reference::sort ] [ Select ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    #
    #5 put cursor in title text box for the user to enter a title
    Go to Field [ brainstate::description ]

Fields used in this script	

    reference::farmerID
    brainstate::_keyUser
    brainstate::hide
    reference::sort
    brainstate::_lockBrainstateID
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newBrainstateOnMainLayouts]	Parent Folder: [action buttons]	Next Script: [info]
Script Name	newFarmer
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE create a new record for the user
    #
    #
    #
    #1 create a new record
    New Record/Request
    #
    #2 put cursor in title text box for the user to enter first name
    Go to Field [ steward::FirstName ]

Fields used in this script	

    steward::FirstName

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [newFarmer]	Parent Folder: [action buttons]	Next Script: [iphoneCut]
Script Name	info
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE open a window to display record info if there is any to display.
    #
    #
    #
    #1 check to see if there is info
    If [ brainstate::linkinfo ≠ "" ]
    #
    #2 open window and display info
    New Window [ Name: "info"; Height: 500; Width: 400 ]
    Show/Hide Status Area [ Lock; Hide ]
    Show/Hide Text Ruler [ Hide ]
    Go to Layout [ “info” (brainstate) ]
    End If

Fields used in this script	

    brainstate::linkinfo

Scripts used in this script	

Layouts used in this script	

    info

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [info]	Parent Folder: [action buttons]	Next Script: [FindSpecificAction]
Script Name	iphoneCut
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    // Cut [ ] [ Select ]
    Set Variable [ $$cut; Value:Get (ActiveFieldContents) ]
    Set Variable [ $$iphoneStop; Value:1 ]
    Set Field [ "" ]
    Go to Field [ ]
    Refresh Window

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [iphoneCut]	Parent Folder: [action buttons]	Next Script: [FindSpecificActionCancel]
Script Name	FindSpecificAction
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #Capture errors and tell user about them in custom
    #dialogue box.
    Allow User Abort [ Off ]
    Set Error Capture [ On ]
    #
    #If the user clicks the find button and the system is already
    #in find mode, capture the user's current find request
    #and then perform the requested find.
    #This capture is done in case nothing is found and the
    #user is asked if they want to modify their request.
    #The system puts in the captured request so that the
    #user can see the failed request.
    If [ Get (WindowMode) = 1 ]
    Set Variable [ $issueText; Value:issue::text ]
    Perform Find [ ]
    #
    #If the system is not in find mode and the find button
    #is clicked then enter find mode and await the user's
    #find request.
    Else
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Show/Hide Status Area [ Hide ]
    Show/Hide Text Ruler [ Hide ]
    Go to Layout [ “IssuesFIND” (issue) ]
    Go to Field [ issue::text ]
    Pause/Resume Script [ Indefinitely ]
    Set Variable [ $issueText; Value:issue::text ]
    Perform Find [ ]
    End If
    #
    #If the find fails tell the user it failed and give them
    #option to modify their request or cancel the find.
    Loop
    If [ Get (LastError) = 401 ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::text; $issueText ]
    Go to Field [ issue::text ]
    Show Custom Dialog [ Message: "No records match this request."; Buttons: “cancel”, “modify find” ]
    #
    #If the user decides to modify their request then re-enter
    #find mode and await the users new request.
    If [ Get ( LastMessageChoice ) = 2 ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Variable [ $issueText; Value:issue::text ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Set Field [ issue::text; $issueText ]
    Go to Field [ issue::text ]
    Pause/Resume Script [ Indefinitely ]
    Set Variable [ $issueText; Value:issue::text ]
    #
    #If the user decides to cancel their the find, then return
    #to the main record window and show all records.
    Else If [ Get ( LastMessageChoice ) = 1 ]
    Go to Layout [ “Issues” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Perform Find [ ]
    Show/Hide Status Area [ Hide ]
    Show/Hide Text Ruler [ Hide ]
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Exit Script [ ]
    End If
    Perform Find [ ]
    End If
    #
    #If the find is successful then show the user the found
    #records on the main records layout.
    Exit Loop If [ Get (LastError) = 0 ]
    End Loop
    Go to Layout [ “Issues” (issue) ]
    Show/Hide Status Area [ Hide ]
    Show/Hide Text Ruler [ Hide ]
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    issue::text
    issue::_keyBrainstate

Scripts used in this script	

Layouts used in this script	

    IssuesFIND
    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [FindSpecificAction]	Parent Folder: [action buttons]	Next Script: [iphoneCopy]
Script Name	FindSpecificActionCancel
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #If the user decides to cancel their the find, then return
    #to the main record window and show all records.
    Go to Layout [ “Issues” (issue) ]
    Enter Find Mode [ ]
    Set Field [ issue::_keyBrainstate; $$logBrainstate ]
    Perform Find [ ]
    Show/Hide Status Area [ Hide ]
    Show/Hide Text Ruler [ Hide ]
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script

Fields used in this script	

    issue::_keyBrainstate

Scripts used in this script	

Layouts used in this script	

    Issues

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [FindSpecificActionCancel]	Parent Folder: [action buttons]	Next Script: [iphonePaste]
Script Name	iphoneCopy
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Variable [ $$cut; Value:Get (ActiveFieldContents) ]
    Set Variable [ $$iphoneStop; Value:1 ]
    Go to Field [ ]
    Refresh Window

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [iphoneCopy]	Parent Folder: [action buttons]	Next Script: [DeleteBrainstate]
Script Name	iphonePaste
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Set Field [ $$cut ]
    Set Variable [ $$cut ]
    Go to Field [ ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [iphonePaste]	Parent Folder: [action buttons]	Next Script: [DeleteBrainstateFromTotal]
Script Name	DeleteBrainstate
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE determine if user really wants to delete the selected record, delete that record if true, and if it is a total or grand total record also clear its linked records of their link.
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    If [ brainstate::_lockBrainstateID = brainstate::groupID and brainstate::groupType ≠ "" ]
    Show Custom Dialog [ Title: "!"; Message: "Action groups must be deleted from the group display screen. You will taken there now."; Buttons: “OK”, “Cancel” ]
    If [ Get ( LastMessageChoice ) = 2 ]
    Halt Script
    End If
    Perform Script [ “note veto view” ]
    Go to Layout [ “TotalSort” (brainstate) ]
    Exit Script [ ]
    End If
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $deleteID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $deletelayout; Value:Get ( LayoutName ) ]
    Set Variable [ $$deletelayout; Value:Get ( LayoutName ) ]
    Set Variable [ $$hide; Value:brainstate::hide ]
    #
    #
    #
    #A) BEGIN check if user is in any fields (neccessary because if user is in a field another script could be triggered causing this script to be terminated).
    #
    #1 check if user is in any fields and if so halt the script
    If [ Get ( ActiveFieldName ) ≠ "" ]
    Show Custom Dialog [ Title: "!"; Message: "As long as record is in use it cannot be deleted. Please exit all fields and try again. "; Buttons: “OK” ]
    Halt Script
    End If
    #
    #A) END check if user is in any fields (neccessary because if user is in a field another script could be triggered causing this script to be terminated).
    #
    #
    #
    #B) BEGIN ask for delete confirmation
    #
    #1) clear the reference. This field is the lock the user must insert the first letter of the record's title to open and then delete the record. This step insures it is locked! (If there is a value in the field, the field is unlocked and the user could accidently delete a record they really decide that they want to keep.)
    Set Field [ reference::YorN; "" ]
    #
    #2) open a text box and ask the user to type in the first letter of the records title
    Set Variable [ $$warning; Value:brainstate::_lockBrainstateID ]
    Refresh Window
    Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or 1 space if blank) and click OK to delete ¶¶" & brainstate::description; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
    #
    #B) END ask for delete confirmation
    #
    Set Variable [ $$warning ]
    Refresh Window
    #
    #
    #C) BEGIN confirm user wants to delete record or cancel delete
    #
    #1) halt delete if the user typed nothing and clicked OK or hit the cancel button
    If [ reference::YorN = "" ]
    Set Variable [ $$warning ]
    Refresh Window
    Halt Script
    End If
    #
    #2) confirm user typed correct letter OR if record was blank and user typed in a blank (this test covers the possibility that first letter of title may be a blank, and insures the user's desire to delete the record is taken care of in the case of blank or blank looking record).
    If [ reference::YorN = Left ( brainstate::description ; 1 ) or reference::YorN = " " and brainstate::description = "" ]
    #
    #3) if the user failed to follow directions give them all the chances they need to follow them correctly
    Else If [ reference::YorN ≠ Left ( brainstate::description ; 1 ) or reference::YorN ≠ " " and brainstate::description = "" ]
    Loop
    Set Field [ reference::YorN; "" ]
    Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or click the space bar once to type a space in the field below if title appears to be blank) and click OK to delete ¶" & brainstate::description; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
    Exit Loop If [ reference::YorN = Left ( brainstate::description ; 1 ) or brainstate::description = "" and reference::YorN = " " or reference::YorN = "" ]
    End Loop
    End If
    #
    #4) recheck if the user typed nothing and clicked OK or hit the cancel button
    If [ reference::YorN = "" ]
    Set Variable [ $$warning ]
    Refresh Window
    Halt Script
    End If
    #
    #C) END confirm user wants to delete record or cancel delete
    #
    #
    #
    #D) BEGIN delete total or grandtotal record
    #
    #1) check if total or grandtotal record and if so perform the CHUNK_deleteTotalOrGrandtotalRecord script
    If [ brainstate::groupType ≠ "" and brainstate::_lockBrainstateID = brainstate::groupID or brainstate::groupType ≠ "" and brainstate::_lockBrainstateID = brainstate::groupOfGroupID ]
    Perform Script [ “CHUNK_deleteTotalOrGrandtotalRecord” ]
    Set Variable [ $$warning ]
    Refresh Window
    Halt Script
    End If
    #
    #D) END delete total or grandtotal record
    #
    #
    #
    #E) BEGIN determine if record is linked to a total record and subtract it
    #
    #1) subtract record's time from total if it was part of a total.
    If [ brainstate::groupID ≠ "" ]
    Perform Script [ “CHUNK_deleteRecordsTimeFromTotal” ]
    #
    #2) capture mergeID (necessary if user was on the totalview layout for returning the user to that layout and showing only the records with the same mergeID)
    Set Variable [ $brainstateID; Value:brainstate::groupID ]
    #
    #E) END determine if record is linked to a total record and subtract it
    #
    #
    #
    #F) BEGIN delete record linked to a total record and a grandtotal record
    #
    #1) subtract record's time from a grandtotal if this record was part of a grandtotal
    If [ brainstate::groupOfGroupUpdate = "u" ]
    Perform Script [ “CHUNK_recalculateGrandTotal” ]
    #
    #2) delete the record chosen to be deleted aftering updating total and grandtotal
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$deleteID ]
    Perform Find [ ]
    If [ brainstate::_lockBrainstateID = $deleteID ]
    Delete Record/Request [ No dialog ]
    Else If [ brainstate::_lockBrainstateID ≠ $deleteID ]
    Show Custom Dialog [ Title: "!"; Message: "Error peforming F2 of the DeleteBrainstate script."; Buttons: “OK” ]
    End If
    #
    #3) if user was on the viewTotal screen find only those records that are part of the total being viewed prior to deleting and show the user those records on that layout.
    If [ Left ( $deletelayout ; 5 ) = "Total" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ $$deletelayout ]
    // #NOT TESTED
    // If [ Get ( SystemPlatform ) = 3 ]
    // Go to Layout [ “TotalMainiPhone” (brainstate) ]
    // End If
    // #END NOT TESTED
    Go to Field [ ]
    Set Variable [ $$warning ]
    Refresh Window
    Halt Script
    End If
    #
    #4) if user was not on the viewTotal screen go back to the layout user was on and show records that users was looking at
    Perform Script [ “goBackButton” ]
    End If
    End If
    #
    #F) END delete record linked to a total record and a grandtotal record
    #
    #
    #
    #G) BEGIN delete record
    #
    #1) delete the record chosen to be deleted
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $deleteID ]
    Perform Find [ ]
    If [ brainstate::_lockBrainstateID = $deleteID ]
    Delete Record/Request [ No dialog ]
    Else If [ brainstate::_lockBrainstateID ≠ $deleteID ]
    Show Custom Dialog [ Title: "!"; Message: "Error peforming G1 of the DeleteBrainstate script."; Buttons: “OK” ]
    End If
    #
    #2) if user was on the viewTotal screen find only those records that are part of the total being viewed prior to deleting and show the user those records on that layout.
    If [ Left ( $deletelayout ; 4 ) = "Tota" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ $$deletelayout ]
    // #NOT TESTED
    // If [ Get ( SystemPlatform ) = 3 ]
    // Go to Layout [ “TotalMainiPhone” (brainstate) ]
    // End If
    // #END NOT TESTED
    Go to Field [ ]
    Halt Script
    End If
    #
    #3) if user was not on the view Total screen, go back to the layout user was on and show records that users was looking at
    Perform Script [ “goBackButton” ]
    Halt Script
    #
    #G) END delete record

Fields used in this script	

    brainstate::_lockBrainstateID
    brainstate::groupID
    brainstate::groupType
    reference::farmerID
    brainstate::hide
    reference::YorN
    brainstate::description
    <Missing Field>
    brainstate::groupOfGroupID
    brainstate::groupOfGroupUpdate

Scripts used in this script	

    note veto view
    CHUNK_deleteTotalOrGrandtotalRecord
    CHUNK_deleteRecordsTimeFromTotal
    CHUNK_recalculateGrandTotal
    goBackButton

Layouts used in this script	

    TotalSort
    TotalMainiPhone

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [DeleteBrainstate]	Parent Folder: [action buttons]	Next Script: [DeleteFarmer]
Script Name	DeleteBrainstateFromTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE determine if user really wants to delete the selected record, delete that record if true, and if it is a total or grand total record also clear its linked records of their link.
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $mergeID; Value:brainstate::groupID ]
    Set Variable [ $deleteID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $deletelayout; Value:Get ( LayoutName ) ]
    Set Variable [ $$deletelayout; Value:Get ( LayoutName ) ]
    Set Variable [ $$record; Value:Get ( RecordNumber ) ]
    #
    #
    #
    #A) BEGIN check if user is in any fields (neccessary because if user is in a field another script could be triggered causing this script to be terminated).
    #
    #1 check if user is in any fields and if so halt the script
    If [ Get ( ActiveFieldName ) ≠ "" ]
    Show Custom Dialog [ Title: "!"; Message: "As long as record is in use it cannot be deleted. Please exit all fields and try again. "; Buttons: “OK” ]
    Halt Script
    End If
    #
    #A) END check if user is in any fields (neccessary because if user is in a field another script could be triggered causing this script to be terminated).
    #
    #
    #
    #B) BEGIN ask for delete confirmation
    #
    #1) clear the reference. This field is the lock the user must insert the first letter of the record's title to open and then delete the record. This step insures it is locked! (If there is a value in the field, the field is unlocked and the user could accidently delete a record they really decide that they want to keep.)
    Set Field [ reference::YorN; "" ]
    #
    #2) open a text box and ask the user to type in the first letter of the records title
    Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or 1 space if blank) and click OK to delete ¶¶" & brainstate::description; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
    #
    #B) END ask for delete confirmation
    #
    #
    #
    #C) BEGIN confirm user wants to delete record or cancel delete
    #
    #1) halt delete if the user typed nothing and clicked OK or hit the cancel button
    If [ reference::YorN = "" ]
    Halt Script
    End If
    #
    #2) confirm user typed correct letter OR if record was blank and user typed in a blank (this test covers the possibility that first letter of title may be a blank, and insures the user's desire to delete the record is taken care of in the case of blank or blank looking record).
    If [ reference::YorN = Left ( brainstate::description ; 1 ) or reference::YorN = " " and brainstate::description = "" ]
    #
    #3) if the user failed to follow directions give them all the chances they need to follow them correctly
    Else If [ reference::YorN ≠ Left ( brainstate::description ; 1 ) or reference::YorN ≠ " " and brainstate::description = "" ]
    Loop
    Set Field [ reference::YorN; "" ]
    Show Custom Dialog [ Title: brainstate::description; Message: "Type the 1st character of the title below (or click the space bar once to type a space in the field below if title appears to be blank) and click OK to delete ¶" & brainstate::description; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
    Exit Loop If [ reference::YorN = Left ( brainstate::description ; 1 ) or brainstate::description = "" and reference::YorN = " " or reference::YorN = "" ]
    End Loop
    End If
    #
    #4) recheck if the user typed nothing and clicked OK or hit the cancel button
    If [ reference::YorN = "" ]
    Halt Script
    End If
    #
    #C) END confirm user wants to delete record or cancel delete
    #
    #
    #
    #D) BEGIN delete total or grandtotal record
    #
    #1) check if total or grandtotal record and if so perform the CHUNK_deleteTotalOrGrandtotalRecord script
    If [ brainstate::groupType ≠ "" ]
    Perform Script [ “CHUNK_deleteTotalOrGrandtotalRecord” ]
    Halt Script
    End If
    #
    #D) END delete total or grandtotal record
    #
    #
    #
    #E) BEGIN determine if record is linked to a total record and subtract it
    #
    #1) subtract record's time from total if it was part of a total.
    If [ brainstate::groupID ≠ "" ]
    Perform Script [ “CHUNK_deleteRecordsTimeFromTotal” ]
    #
    #2) capture mergeID (necessary if user was on the totalview layout for returning the user to that layout and showing only the records with the same mergeID)
    Set Variable [ $brainstateID; Value:brainstate::groupID ]
    #
    #E) END determine if record is linked to a total record and subtract it
    #
    #
    #
    #F) BEGIN delete record linked to a total record and a grandtotal record
    #
    #1) subtract record's time from a grandtotal if this record was part of a grandtotal
    If [ brainstate::groupOfGroupUpdate = "u" ]
    Perform Script [ “CHUNK_recalculateGrandTotal” ]
    #
    #2) delete the record chosen to be deleted aftering updating total and grandtotal
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$deleteID ]
    Perform Find [ ]
    If [ brainstate::_lockBrainstateID = $deleteID ]
    Delete Record/Request [ No dialog ]
    Else If [ brainstate::_lockBrainstateID ≠ $deleteID ]
    Show Custom Dialog [ Title: "!"; Message: "Error peforming F2 of the DeleteBrainstate script."; Buttons: “OK” ]
    End If
    #
    #3) if user was on the viewTotal screen find only those records that are part of the total being viewed prior to deleting and show the user those records on that layout.
    If [ Left ( $deletelayout ; 5 ) = "total" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $mergeID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ $$deletelayout ]
    // #NOT TESTED
    // If [ Get ( SystemPlatform ) = 3 ]
    // Go to Layout [ “TotalMainiPhone” (brainstate) ]
    // End If
    // #END NOT TESTED
    Go to Field [ ]
    Halt Script
    End If
    #
    #4) if user was not on the viewTotal screen go back to the layout user was on and show records that users was looking at
    End If
    End If
    #
    #F) END delete record linked to a total record and a grandtotal record
    #
    #
    #
    #G) BEGIN delete record
    #
    #1) delete the record chosen to be deleted
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $deleteID ]
    Perform Find [ ]
    If [ brainstate::_lockBrainstateID = $deleteID ]
    Delete Record/Request [ No dialog ]
    Else If [ brainstate::_lockBrainstateID ≠ $deleteID ]
    Show Custom Dialog [ Title: "!"; Message: "Error peforming G1 of the DeleteBrainstate script."; Buttons: “OK” ]
    End If
    #
    #2) if user was on the viewTotal screen find only those records that are part of the total being viewed prior to deleting and show the user those records on that layout.
    If [ Left ( $deletelayout ; 4 ) = "Tota" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    #
    #4 it the user wants retired records hidden then hide these records if any
    // If [ steward::retiredStatus ≠ "" ]
    // Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    // End If
    Perform Script [ “CHUNK_retire” ]
    #
    Perform Script [ “CHUNK_DaySelectSortThenSort” ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ $$deletelayout ]
    // #NOT TESTED
    // If [ Get ( SystemPlatform ) = 3 ]
    // Go to Layout [ “TotalMainiPhone” (brainstate) ]
    // End If
    // #END NOT TESTED
    Go to Field [ ]
    Halt Script
    End If
    #
    #3) if user was not on the view Total screen, go back to the layout user was on and show records that users was looking at
    Halt Script
    #
    #G) END delete record

Fields used in this script	

    reference::farmerID
    brainstate::_lockBrainstateID
    brainstate::groupID
    reference::YorN
    brainstate::description
    <Missing Field>
    brainstate::groupType
    brainstate::groupOfGroupUpdate
    steward::retiredStatus
    brainstate::sortRetired

Scripts used in this script	

    CHUNK_deleteTotalOrGrandtotalRecord
    CHUNK_deleteRecordsTimeFromTotal
    CHUNK_recalculateGrandTotal
    CHUNK_retire
    CHUNK_DaySelectSortThenSort

Layouts used in this script	

    TotalMainiPhone
    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [DeleteBrainstateFromTotal]	Parent Folder: [action buttons]	Next Script: [editFarmer]
Script Name	DeleteFarmer
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE determine if user really wants to delete the selected record and delete that record if true.
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    #
    #
    #
    #A) BEGIN check if user is in any fields (neccessary because if user is in a field another script could be triggered causing this script to be terminated).
    #
    #1 check if there are 2 or more records to merge and if not halt the script. (Can't merge if zero or 1 records are selected.
    If [ Get ( ActiveFieldName ) ≠ "" ]
    Show Custom Dialog [ Title: "!"; Message: "As long as record is in use it cannot be deleted. Please exit all fields and try again. "; Buttons: “OK” ]
    Halt Script
    End If
    #
    #A) END check if user is in any fields (neccessary because if user is in a field another script could be triggered causing this script to be terminated).
    #
    #
    #
    #B) BEGIN check to insure user has something they can use a password to delete this record and all records associated with it
    #
    #1 password check
    If [ WordCount ( steward::FirstName ) + WordCount ( steward::LastName ) = 0 ]
    Show Custom Dialog [ Title: "!"; Message: "You must have something (other than spaces) typed in at least the first or last name text boxes to use as a password to delete this record."; Buttons: “OK” ]
    Halt Script
    End If
    #
    #B) END check to insure user has something they can use a password to delete this record and all records associated with it
    #
    #
    #
    #C) BEGIN ask for delete confirmation
    #
    #1) clear the reference. This field is the lock the user must insert the first letter of the record's title to open and then delete the record. This step insures it is locked!
    Set Field [ reference::YorN; "" ]
    #
    #2) open a text box and ask the user to type in the full name of the user to be deleted
    Show Custom Dialog [ Title: "DELETE steward::FirstPlusLast"; Message: "Type the full name as shown below and click OK to delete all records for this person. ¶¶" & steward::FirstPlusLast; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
    #
    #C) END ask for delete confirmation
    #
    #
    #
    #D) BEGIN delete
    #
    #1) halt delete if the user typed nothing or hit the cancel button
    If [ reference::YorN = "" ]
    Halt Script
    #
    #2) confirm user typed correct name
    Else If [ reference::YorN = steward::FirstPlusLast or reference::YorN = steward::FirstName and steward::LastName = "" ]
    #
    #3) delete
    Delete Record/Request [ No dialog ]
    Halt Script
    #
    End If
    #
    #4) if the user failed to follow directions give them another chance
    Loop
    Set Field [ reference::YorN; "" ]
    Show Custom Dialog [ Title: "DELETE steward::FirstPlusLast"; Message: "Type the full name as shown below and click OK to delete all records for this person. ¶¶" & steward::FirstPlusLast; Buttons: “OK”, “Cancel”; Input #1: reference::YorN ]
    Exit Loop If [ reference::YorN = steward::FirstPlusLast or reference::YorN = steward::FirstName and steward::LastName = "" or reference::YorN = "" ]
    End Loop
    #
    #5) halt delete if the user typed nothing or hit the cancel button
    If [ reference::YorN = "" ]
    Halt Script
    End If
    #
    #6) delete
    Delete Record/Request [ No dialog ]
    Halt Script
    #
    #D) END delete

Fields used in this script	

    reference::farmerID
    brainstate::_lockBrainstateID
    steward::FirstName
    steward::LastName
    reference::YorN
    steward::FirstPlusLast
    <Missing Field>

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [DeleteFarmer]	Parent Folder: [action buttons]	Next Script: [otherSolutionsMenu]
Script Name	editFarmer
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to createEdit farmer layout and show all users.
    #
    #
    #
    #1 go to the edit/create layout and show all users.
    Go to Layout [ “users” (steward) ]
    Show All Records
    Close Window [ Name: "Day"; Current file ]
    Close Window [ Name: "Specific Action"; Current file ]
    Close Window [ Name: "Tag"; Current file ]
    #
    #Set window title.
    Set Window Title [ Current Window; New Title: "HelpGiveThanks Solutions" ]
    #
    #Size window to 100%
    Set Zoom Level [ 100% ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

    users

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [editFarmer]	Parent Folder: [action buttons]	Next Script: [switchFarmer]
Script Name	otherSolutionsMenu
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE go to other apps menu.
    #
    #
    #
    #1 go to the edit/create layout and show all users.
    Close Window [ Name: "Other Solutions"; Current file ]
    New Window [ Name: "Other Solutions" ]
    Go to Layout [ “users Copy3” (steward) ]
    Show All Records
    #
    #Size window to 100%
    Set Zoom Level [ 100% ]
    Adjust Window [ Resize to Fit ]
    #
    #
    #Set variable that will close this other apps menu
    #when the user selectes a new database.
    Set Variable [ $$otherApps; Value:1 ]
    Pause/Resume Script [ Indefinitely ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

    users Copy3

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [otherSolutionsMenu]	Parent Folder: [action buttons]	Next Script: [time]
Script Name	switchFarmer
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE switch from one user's records to anothers via the reference field farmer which is a global field holding the current ID number of the current user.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #
    #
    #1 capture selected userID chosen
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #2 find this user's records
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    #
    #3 if the user has no records, create a new one and assign it to the user so that there name will show up. (All the layouts are tied to the brainstate table not the user table. So the only way to show a user name and all the correct formating attributes is to have one user record.)
    If [ Get ( LastError ) = 401 ]
    Set Field [ reference::farmerID; "" ]
    Go to Field [ reference::farmerID ]
    Halt Script
    Else If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error performing switchFarmer script"; Buttons: “OK” ]
    Go to Layout [ “users” (steward) ]
    Show All Records
    Halt Script
    End If
    #
    #4 show the user's name
    Set Field [ reference::farmerName; steward::FirstPlusLast ]
    #
    #5 show/hide all records according the user's last settings
    If [ steward::retiredStatus = "r" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    If [ steward::hideStatus = "" and steward::showORhide = "hide" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    Else If [ steward::showStatus ≠ "" and steward::showORhide = "show" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::Show: “=” ] [ Restore ]
    End If
    #
    #6 go to user's chosen day, sort records, and choose last used layout
    If [ Left ( steward::chosenLayout ; 2 ) = "01" ]
    Perform Script [ “to 1” ]
    Else If [ Left ( steward::chosenLayout ; 2 ) = "07" ]
    Perform Script [ “to 7” ]
    Else If [ Left ( steward::chosenLayout ; 2 ) = "31" ]
    Perform Script [ “to 31” ]
    End If

Fields used in this script	

    reference::farmerID
    brainstate::_keyUser
    steward::FirstPlusLast
    reference::farmerName
    steward::retiredStatus
    brainstate::sortRetired
    steward::hideStatus
    steward::showORhide
    brainstate::hide
    steward::showStatus
    brainstate::Show
    steward::chosenLayout

Scripts used in this script	

    to 1
    to 7
    to 31

Layouts used in this script	

    users

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [switchFarmer]	Parent Folder: [action buttons]	
Script Name	time
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE script attached to the time button on the edit time layouts. It checks if user is in a time field, and if they are inserts the current time into it, and if they are not tells them how to use the time button.
    #
    #
    If [ brainstate::_lockBrainstateID = brainstate::groupID ]
    Go to Field [ ]
    Halt Script
    End If
    #
    #1 determine if the user is in a time field
    If [ Get ( ActiveFieldName ) = "swPause" or Get ( ActiveFieldName ) = "swStart" ]
    #
    #2 if they are then insert the current time into it
    Insert Current Time [ ] [ Select ]
    Go to Field [ ]
    Halt Script
    End If
    #
    #2 if they are not tell them how to use this button
    Show Custom Dialog [ Title: "!"; Message: "This button is for inserting the current time into a stop or start time field."; Buttons: “OK” ]

Fields used in this script	

    brainstate::_lockBrainstateID
    brainstate::groupID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


DeleteBrainstate CHUNKS
	Parent Folder: [DeleteBrainstate CHUNKS]	Next Script: [CHUNK_deleteRecordsTimeFromTotal]
Script Name	CHUNK_deleteTotalOrGrandtotalRecord
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    DeleteBrainstate
    DeleteBrainstateFromTotal

Script Definition
Script Steps	

    #PURPOSE delete a total or grand total record and also clear the linked records of their link to it (the records that add up to the total/grandtotal being deleted).
    #CHUNK USED BY DeleteBrainstate Script
    #
    #
    #
    #NOTE: the three # symbols set apart chunks of script.
    #NOTE: the finish and error script chunks are almost identical (the error message differ in telling where in the script they occur). For this reason, they are not numbered as part of a particular chuck of the script, and are separated by three # symbols to set them apart.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #
    #A BEGIN delete total record
    #
    #1 if total record find all linked records so that they can be cleared of their link
    If [ brainstate::groupType = "merge" ]
    Set Variable [ $mergeID; Value:brainstate::groupID ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $mergeID ]
    Perform Find [ ]
    #
    #
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number.
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming CHUNK_deleteTotalOrGrandtotalRecord script part A1."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Perform Script [ “goBackButton” ]
    End If
    #END find error 1
    #
    #
    #
    #2 clear all the linked record's linked to the old total record
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupID; "" ]
    Set Field [ brainstate::groupDisplayID; "" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #3 sort the total record to the top and mark it for deletion. (Delete is the last step in the process so if the computer crashes or loses power the user can still complete the delete process. If the record was deleted before the links the where deleted and the computer crashed, those linked records would forever be linked to the now deleted total record unless the user could directly access the data table.)
    Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $$deleteID; Value:brainstate::_lockBrainstateID ]
    If [ brainstate::groupOfGroupID ≠ "" ]
    #
    #4 capture total record's ID number from the record to be deleted and then omit this soon to be deleted record
    Set Variable [ $brainstateID; Value:brainstate::groupOfGroupID ]
    Set Variable [ $displayID; Value:brainstate::_Number ]
    Set Variable [ $description; Value:brainstate::description ]
    Set Field [ brainstate::description; " delete interrupted! click here for info: This record should be deleted, along with this total record ID number -- " & $brainstateID & ". You can then rebuild it using the total process. // " & $description ]
    Set Field [ brainstate::groupOfGroupID; "" ]
    Omit Record
    #
    #5 make a list of the grandtotal records it is being removed from so that they can be used to re-total the grandtotal
    Go to Layout [ “calcBrainstateTable” (brainstate) ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::groupAddCheckbox; descending brainstate::groupType; based on value list: “MergeSort” ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentTimeStamp ) & " Deleted: " & $displayID & " " & $description ]
    #
    #6 subtract record's time from grandtotal
    Perform Script [ “CHUNK_recalculateGrandTotal” ]
    #
    #7 delete the record chosen to be deleted
    Enter Find Mode [ ]
    Set Field [ brainstate::_lockBrainstateID; $$deleteID ]
    Perform Find [ ]
    If [ brainstate::_lockBrainstateID = $$deleteID ]
    Delete Record/Request [ No dialog ]
    Else If [ brainstate::_lockBrainstateID ≠ $$deleteID ]
    Show Custom Dialog [ Title: "!"; Message: "Error peforming A7 of the CHUNK_deleteTotalOrGrandtotalRecord script."; Buttons: “OK” ]
    End If
    #
    #8 if user was on the viewGrandtotal layout find only those records that are part of the grandtotal being viewed prior to deleting and show the user those records on that layout.
    If [ Left ( $$deletelayout ; 5 ) = "viewG" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $brainstateID ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Layout [ “GrandTotal” (brainstate) ]
    Go to Field [ ]
    Halt Script
    End If
    #
    #9 if user was not on the viewgrandotal layout go back to the layout user was on and show records that users was looking at
    Perform Script [ “goBackButton” ]
    Halt Script
    End If
    #
    #9 delete total record
    Delete Record/Request [ No dialog ]
    Set Variable [ $$deleteID; Value:"total" ]
    Perform Script [ “goBackButton” ]
    Halt Script
    #
    #A END delete total record
    #
    #
    #
    #B BEGIN delete grandtotal record
    #
    #1 if grand total record find all linked records so that they can be cleared of their link
    Else If [ brainstate::groupType = "mergeGrand" ]
    Set Variable [ $mergeID; Value:brainstate::groupOfGroupID ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupOfGroupID; $mergeID ]
    Perform Find [ ]
    #
    #
    #
    #BEGIN find error 2
    If [ Get ( LastError ) ≠ 0 ]
    #tell user the error number.
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming delete script part C8."; Buttons: “OK” ]
    #Find all records user had showing when they clicked the merge button
    Perform Script [ “goBackButton” ]
    End If
    #END find error 2
    #
    #
    #
    #2 clear all the linked record's linked to the old grand total record
    Go to Record/Request/Page [ First ]
    Loop
    Set Field [ brainstate::groupOfGroupID; "" ]
    Set Field [ brainstate::groupOfGroupDisplayID; "" ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    #
    #3 sort the grandtotal record to the top and delete it
    Sort Records [ Specified Sort Order: brainstate::groupType; based on value list: “MergeSort” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Set Variable [ $$deleteID; Value:brainstate::_lockBrainstateID ]
    If [ brainstate::_lockBrainstateID = $$deleteID ]
    Delete Record/Request [ No dialog ]
    Else If [ brainstate::_lockBrainstateID ≠ $$deleteID ]
    Show Custom Dialog [ Title: "!"; Message: "Error peforming B2 of the CHUNK_deleteTotalOrGrandtotalRecord script."; Buttons: “OK” ]
    End If
    #
    #4 return user to previous layout and halt the script
    Set Variable [ $$deleteID; Value:"grandtotal" ]
    Perform Script [ “goBackButton” ]
    Halt Script
    #
    End If
    #
    #B END delete grandtotal record

Fields used in this script	

    brainstate::groupType
    brainstate::groupID
    brainstate::groupDisplayID
    brainstate::description
    brainstate::_lockBrainstateID
    brainstate::groupOfGroupID
    brainstate::_Number
    brainstate::groupAddCheckbox
    brainstate::linkinfo
    brainstate::groupOfGroupDisplayID

Scripts used in this script	

    goBackButton
    CHUNK_recalculateGrandTotal

Layouts used in this script	

    calcBrainstateTable
    GrandTotal

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CHUNK_deleteTotalOrGrandtotalRecord]	Parent Folder: [DeleteBrainstate CHUNKS]	
Script Name	CHUNK_deleteRecordsTimeFromTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    DeleteBrainstate
    DeleteBrainstateFromTotal

Script Definition
Script Steps	

    #PURPOSE find the to-be-deleted record's total record, omit the to-be-deleted record and then start the process of updating the total records day records (subtracting the to-be-deleted record's time from these records). By omitting the to-be-deleted at this stage if the computer crashes or loses power and is then re-booted the program will show that the to-be-deleted still in need of deleting and the process can be done again becuase the delete takes place as the final part of the script.
    #CHUNK USED BY DeleteBrainstate Script
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #
    #
    #1 capture total record's ID number from the record to be deleted and then omit this soon to be deleted record
    Set Variable [ $brainstateID; Value:brainstate::groupID ]
    Set Variable [ $$deleteID; Value:brainstate::_lockBrainstateID ]
    Set Variable [ $displayID; Value:brainstate::_Number ]
    Set Variable [ $totaldisplayID; Value:brainstate::groupDisplayID ]
    Set Variable [ $description; Value:brainstate::description ]
    Set Field [ brainstate::description; " delete interrupted! click here for info: This record is fine, the bad news is the record that totaled its time may have been corrupted. So this total record ID number -- " & $totaldisplayID & " -- should be deleted and rebuilt if you still want it. // " & $description ]
    Set Field [ brainstate::groupID; "" ]
    Set Field [ brainstate::groupDisplayID; "" ]
    #
    #2 find all records linked to this total record
    Enter Find Mode [ ]
    Set Field [ brainstate::groupID; $brainstateID ]
    Perform Find [ ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::description: “" delete inter"” ] [ Restore ]
    #
    #DISABLED: I thought these next steps where a good idea: to delete total records with nothing to total. But after thinking about it, I now think I should allow the user to do this. There is no harm in having a non-working total record. It can always be used again by adding records to it to total, or by turning it into a regular record.)
    // #3 determine if user has deleted all records to total
    // If [ Get ( FoundCount ) = 1 and brainstate::_lockBrainstateID = brainstate::groupID ]
    // #
    // #4 capture total record's mergeID
    // Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    // #
    // #5 flag for grand total update
    // If [ brainstate::groupOfGroupID ≠ "" ]
    // Set Field [ brainstate::groupOfGroupUpdate; "u" ]
    // End If
    // #
    // #6 tell user this record is being deleted and why.
    // Go to Layout [ <unknown> ]
    // Show Custom Dialog [ Title: "!"; Message: "This total record has no more records to total and so it is being deleted. You can always re-create it by clicking the total button."; Buttons: “OK” ]
    // Delete Record/Request [ No dialog ]
    // Enter Find Mode [ ]
    // Set Field [ brainstate::_lockBrainstateID; $$deleteID ]
    // Perform Find [ ]
    // Delete Record/Request [ No dialog ]
    // Perform Script [ “goBackButton” ]
    // Halt Script
    // End If
    #
    #4 capture total record's mergeID and remove the t from its merge field
    Sort Records [ Specified Sort Order: brainstate::groupType; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ Last ]
    Set Variable [ $brainstateID; Value:brainstate::_lockBrainstateID ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶" & Get ( CurrentTimeStamp ) & " Deleted: " & $displayID & " " & $description ]
    #
    #5 flag for grand total update
    Set Field [ brainstate::groupOfGroupUpdate; If ( brainstate::groupOfGroupID ≠ "" ; "u" ; "" ) ]
    #
    Perform Script [ “CHUNK_recalculateTotal” ]

Fields used in this script	

    brainstate::groupID
    brainstate::_lockBrainstateID
    brainstate::_Number
    brainstate::groupDisplayID
    brainstate::description
    brainstate::groupOfGroupID
    brainstate::groupOfGroupUpdate
    brainstate::groupType
    brainstate::linkinfo

Scripts used in this script	

    goBackButton
    CHUNK_recalculateTotal

Layouts used in this script	

    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


falsified idea
	Parent Folder: [falsified idea]	
Script Name	edit
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE open a new window to edit time on the day layout windows where the editable start/stop time fields are hidden.
    #
    #DEVELOPMENT STOPPED: This script is seemed like a good idea, but now given windows issue of minimizing windows I am putting it on hold.
    // #
    // If [ day1::_keyDay ≠ "" ]
    // Set Variable [ $rownumber; Value:Get ( RecordNumber ) ]
    // Set Error Capture [ On ]
    // Allow User Abort [ Off ]
    // Select Window [ Name: "edit"; Current file ]
    // #If the window is open then just bring it to the front, otherwise make a new window.
    // If [ Get ( LastError ) = 112 ]
    // New Window [ Name: "edit"; Height: 310; Top: 300 ]
    // Go to Layout [ <unknown> ]
    // Show/Hide Status Area [ Hide ]
    // Show/Hide Text Ruler [ Hide ]
    // Go to Record/Request/Page [ Next ]
    // Go to Record/Request/Page [ Next ]
    // Go to Record/Request/Page [ Previous ]
    // Go to Record/Request/Page [ Previous ]
    // Halt Script
    // End If
    // Go to Record/Request/Page [ $rownumber ] [ No dialog ]
    // Adjust Window [ Restore ]
    // End If

Fields used in this script	

    day1::_keyDay

Scripts used in this script	

Layouts used in this script	

    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


show/hide buttons and checkboxes
	Parent Folder: [show/hide buttons and checkboxes]	Next Script: [CHUNK_retire]
Script Name	retireButton
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    EditTimePart1
    HideButton

Script Definition
Script Steps	

    #PURPOSE set the status for whether or not to show retired records and then show or hide them.
    #
    #
    #
    #2 set the retired status to blank
    #
    // If [ Left ( $$loglayout ; 5 ) = "total" ]
    // Perform Script [ “retireButtonOnViewLayout” ]
    // End If
    #
    #4 set the retired status to r (not blank because it now has an r in it)
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Set Variable [ $mergeID; Value:brainstate::groupID ]
    #
    #2 toggle the retired status field
    If [ steward::retiredStatus = "" ]
    Set Field [ steward::retiredStatus; "r" ]
    Else If [ steward::retiredStatus ≠ "" ]
    Set Field [ steward::retiredStatus; "" ]
    End If
    #
    #
    #1 set the current find status to hide. The show and hide scripts use the showORhide field to determine if the user wants to hide or show marked records. This field also is used to format the hide and show buttons to visually tell the user which of the two is currently selected, or if neither of the two is selected (this field is blank).
    #
    #2 if the hide status is blank and the user clicks the hide button then they want to hide records records marked hide (hide=t), so find only blank records, will have the effect of omitting all non-blank records.
    If [ steward::hideStatus ≠ "" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupType; "merge" ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming HideButton script part 1."; Buttons: “OK” ]
    Go to Layout [ original layout ]
    Halt Script
    End If
    #END find error 1
    #
    #4 it the user wants retired records hidden then hide these records if any
    // If [ steward::retiredStatus ≠ "" ]
    // Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::sortRetired: “=” AND brainstate::groupDisplayID: “=” ] [ Restore ]
    // Else If [ steward::retiredStatus = "" ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::groupDisplayID: “=” ] [ Restore ]
    // End If
    Perform Script [ “CHUNK_retire” ]
    #
    #3 set the hide status to blank, remove the focus from any field, and resort the records according the user's current sort status
    Perform Script [ “DaySelectSortThenSort” ]
    #
    End If
    #
    #6 if the hide status is not blank and the user clicks the hide button then they want to show all records, so find all records
    If [ steward::hideStatus = "" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::hide; "t" ]
    Perform Find [ ]
    #
    #BEGIN find error 2
    If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming HideButton script part 6."; Buttons: “OK” ]
    Go to Layout [ original layout ]
    Halt Script
    End If
    #END find error 2
    #
    #8 it the user wants retired records hidden then hide these records if any
    // If [ steward::retiredStatus ≠ "" ]
    // Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::sortRetired: “=” AND brainstate::groupDisplayID: “=” ] [ Restore ]
    // Else If [ steward::retiredStatus = "" ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::groupDisplayID: “=” ] [ Restore ]
    // End If
    Perform Script [ “CHUNK_retire” ]
    #
    #7 set the hide status to t (not blank), remove the focus from any field, and resort the records according the user's current sort status
    // Perform Script [ “DaySelectSortThenSort” ]
    #
    End If
    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]

Fields used in this script	

    reference::farmerID
    brainstate::groupID
    steward::retiredStatus
    steward::hideStatus
    brainstate::groupType
    brainstate::_keyUser
    brainstate::sortRetired
    brainstate::hide
    brainstate::groupDisplayID
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

    retireButtonOnViewLayout
    CHUNK_retire
    DaySelectSortThenSort

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [retireButton]	Parent Folder: [show/hide buttons and checkboxes]	Next Script: [retireButtonOnViewLayout]
Script Name	CHUNK_retire
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goToFarmer
    DeleteBrainstateFromTotal
    retireButton
    goBackButton_FindRecordsChunk

Script Definition
Script Steps	

    #PURPOSE set the status for whether or not to show retired records and then show or hide them.
    #
    #
    #
    #2 set the retired status to blank
    #8 it the user wants retired records hidden then hide these records if any
    If [ steward::retiredStatus ≠ "" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    Enter Find Mode [ ]
    Set Field [ brainstate::hide; "t" ]
    Set Field [ brainstate::sortRetired; "=" ]
    Set Field [ brainstate::groupDisplayID; "=" ]
    Set Field [ brainstate::_keyUser; reference::farmerID ]
    Extend Found Set [ ]
    Else If [ steward::retiredStatus = "" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::hide; "t" ]
    Set Field [ brainstate::groupDisplayID; "=" ]
    Set Field [ brainstate::_keyUser; reference::farmerID ]
    Extend Found Set [ ]
    End If

Fields used in this script	

    steward::retiredStatus
    brainstate::sortRetired
    brainstate::hide
    brainstate::groupDisplayID
    reference::farmerID
    brainstate::_keyUser

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CHUNK_retire]	Parent Folder: [show/hide buttons and checkboxes]	Next Script: [retireCheckbox]
Script Name	retireButtonOnViewLayout
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    retireButton

Script Definition
Script Steps	

    #PURPOSE set the status for whether or not to show retired records and then show or hide them.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    Set Variable [ $layoutname; Value:Get ( LayoutName ) ]
    Set Variable [ $totalRecord; Value:brainstate::groupID ]
    #
    #
    #
    #1 if the retired status is not blank and the user clicks the retired button then they want to show all retired records, so find all records
    If [ steward::retiredStatus ≠ "" ]
    #future developement: omit retired records if the retired button is on
    // If [ Get ( LayoutName ) = "viewTotal" or Get ( LayoutName ) = "viewGrandtotal" ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” ] [ Restore ]
    // Halt Script
    // End If
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::groupID; $totalRecord ]
    Perform Find [ ]
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming RetireButton script part 1."; Buttons: “OK” ]
    Go to Layout [ $layoutname ]
    Halt Script
    End If
    #END find error 1
    #
    #2 set the retired status to blank
    Set Field [ steward::retiredStatus; "" ]
    #
    #3 if the retired status is blank and the user clicks the retired button then they want to hide all retired records, so omit retired records from the users set of records
    Else If [ steward::retiredStatus = "" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::sortRetired; "=" ]
    Set Field [ brainstate::groupID; $totalRecord ]
    Perform Find [ ]
    #
    #BEGIN find error 2
    If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming RetireButton script part 3."; Buttons: “OK” ]
    Go to Layout [ $layoutname ]
    Halt Script
    End If
    #END find error 2
    #
    #4 set the retired status to r (not blank because it now has an r in it)
    Set Field [ steward::retiredStatus; "r" ]
    End If
    Perform Script [ “DaySelectSortThenSort” ]

Fields used in this script	

    reference::farmerID
    brainstate::groupID
    steward::retiredStatus
    brainstate::hide
    brainstate::_keyUser
    brainstate::sortRetired

Scripts used in this script	

    DaySelectSortThenSort

Layouts used in this script	

    <Missing Layout>

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [retireButtonOnViewLayout]	Parent Folder: [show/hide buttons and checkboxes]	Next Script: [HideButton]
Script Name	retireCheckbox
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE change the user's retired status and note this change in the records info box
    #
    #
    #
    #1 retire the record and note this change in status. (The if test says to look for a non-blank record and this is because the checkbox has inserted the letter r before this script is activated. So the record will not be blank when the user wants it retired.)
    If [ brainstate::sortRetired ≠ "" ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶retired: " & Get ( CurrentTimeStamp ) ]
    End If
    #neccessary step to remove focus from checkbox
    Go to Field [ ]
    #
    #2 if the user current has elected to hide all retired records hide this newly retired record and also tell user why it is being hidden/omitted.
    If [ brainstate::sortRetired ≠ "" and steward::retiredStatus ≠ "" ]
    Show Custom Dialog [ Title: "retired"; Message: "You currently have the hide retired or r button on. So this record will now be hidden. ¶¶To see this record again, click the r button."; Buttons: “OK” ]
    Omit Record
    End If
    #
    #3 un- retire the record and note this change in status. (The if test says to look for a record and this is because the checkbox has deleted the letter r before this script is activated. So the record will be blank when the user wants the record un-retired.)
    If [ brainstate::sortRetired = "" ]
    Set Field [ brainstate::sortRetired; "" ]
    Set Field [ brainstate::linkinfo; brainstate::linkinfo & "¶¶un-retired: " & Get ( CurrentTimeStamp ) ]
    End If
    #neccessary step to remove focus from checkbox
    Go to Field [ ]

Fields used in this script	

    brainstate::sortRetired
    brainstate::linkinfo
    steward::retiredStatus

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [retireCheckbox]	Parent Folder: [show/hide buttons and checkboxes]	Next Script: [goBackButton_FindRecordsChunk]
Script Name	HideButton
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE set the status for whether or not to show or hide records marked hide and then show or hide them.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    // #1 set the current find status to hide. The show and hide scripts use the showORhide field to determine if the user wants to hide or show marked records. This field also is used to format the hide and show buttons to visually tell the user which of the two is currently selected, or if neither of the two is selected (this field is blank).
    // Set Field [ steward::showORhide; "hide" ]
    // If [ Left ( $$loglayout ; 5 ) = "total" ]
    // Perform Script [ “retireButton” ]
    // End If
    #
    #2 if the hide status is blank and the user clicks the hide button then they want to hide records records marked hide (hide=t), so find only blank records, will have the effect of omitting all non-blank records.
    If [ steward::hideStatus = "" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupType; "merge" ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    #FIX COMMENT
    Enter Find Mode [ ]
    Set Field [ brainstate::hide; "t" ]
    Set Field [ brainstate::groupID; "=" ]
    Set Field [ brainstate::_keyUser; $userID ]
    Extend Found Set [ ]
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming HideButton script part 1."; Buttons: “OK” ]
    Go to Layout [ original layout ]
    Halt Script
    End If
    #END find error 1
    #
    #3 set the hide status to blank, remove the focus from any field, and resort the records according the user's current sort status
    Set Field [ steward::showORhide; "hide" ]
    Set Field [ steward::hideStatus; "t" ]
    Go to Field [ ]
    #
    #4 it the user wants retired records hidden then hide these records if any
    If [ steward::retiredStatus ≠ "" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    #
    #5 go to the first record and halt the script
    Perform Script [ “DaySelectSortThenSort” ]
    End If
    #
    #6 if the hide status is not blank and the user clicks the hide button then they want to show all records, so find all records
    If [ steward::hideStatus ≠ "" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::hide; "t" ]
    Perform Find [ ]
    #
    #BEGIN find error 2
    If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming HideButton script part 6."; Buttons: “OK” ]
    Go to Layout [ original layout ]
    Halt Script
    End If
    #END find error 2
    #
    #7 set the hide status to t (not blank), remove the focus from any field, and resort the records according the user's current sort status
    Set Field [ steward::showORhide; "show" ]
    Set Field [ steward::hideStatus; "" ]
    Go to Field [ ]
    #
    #8 it the user wants retired records hidden then hide these records if any
    If [ steward::retiredStatus ≠ "" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    #
    #9 go to the first record and halt the script
    Perform Script [ “DaySelectSortThenSort” ]
    End If

Fields used in this script	

    reference::farmerID
    steward::showORhide
    steward::hideStatus
    brainstate::groupType
    brainstate::_keyUser
    brainstate::hide
    brainstate::groupID
    steward::retiredStatus
    brainstate::sortRetired

Scripts used in this script	

    retireButton
    DaySelectSortThenSort

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [HideButton]	Parent Folder: [show/hide buttons and checkboxes]	Next Script: [ShowButton]
Script Name	goBackButton_FindRecordsChunk
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goBackButton
    UpdateTime

Script Definition
Script Steps	

    #PURPOSE set the status for whether or not to show or hide records marked hide and then show or hide them.
    #
    #
    #
    #basic administration tasks
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    Set Variable [ $userID; Value:reference::farmerID ]
    #
    #
    #
    // #1 set the current find status to hide. The show and hide scripts use the showORhide field to determine if the user wants to hide or show marked records. This field also is used to format the hide and show buttons to visually tell the user which of the two is currently selected, or if neither of the two is selected (this field is blank).
    // Set Field [ steward::showORhide; "hide" ]
    #
    #2 if the hide status is blank and the user clicks the hide button then they want to hide records records marked hide (hide=t), so find only blank records, will have the effect of omitting all non-blank records.
    If [ steward::hideStatus ≠ "" or $$hide ≠ "" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::groupType; "merge" ]
    Set Field [ brainstate::_keyUser; $userID ]
    Perform Find [ ]
    #FIX COMMENT
    Enter Find Mode [ ]
    Set Field [ brainstate::hide; "t" ]
    Set Field [ brainstate::groupID; "=" ]
    Extend Found Set [ ]
    #
    #BEGIN find error 1
    If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming HideButton script part 1."; Buttons: “OK” ]
    Go to Layout [ original layout ]
    Halt Script
    End If
    #END find error 1
    #
    #3 set the hide status to blank, remove the focus from any field, and resort the records according the user's current sort status
    // Perform Script [ “sortRestoreAfterScript” ]
    #
    #4 it the user wants retired records hidden then hide these records if any
    // If [ steward::retiredStatus ≠ "" ]
    // Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::sortRetired: “=” AND brainstate::groupDisplayID: “=” ] [ Restore ]
    // Else If [ steward::retiredStatus = "" ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::groupDisplayID: “=” ] [ Restore ]
    // End If
    Perform Script [ “CHUNK_retire” ]
    #
    #5 go to the first record and halt the script
    Go to Record/Request/Page [ First ]
    End If
    #
    #6 if the hide status is not blank and the user clicks the hide button then they want to show all records, so find all records
    If [ steward::hideStatus = "" ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $userID ]
    Set Field [ brainstate::hide; "t" ]
    Perform Find [ ]
    #
    #BEGIN find error 2
    If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error " & Get ( LastError ) & " peforming HideButton script part 6."; Buttons: “OK” ]
    Go to Layout [ original layout ]
    Halt Script
    End If
    #END find error 2
    #
    #7 set the hide status to t (not blank), remove the focus from any field, and resort the records according the user's current sort status
    // Perform Script [ “sortRestoreAfterScript” ]
    #
    #8 it the user wants retired records hidden then hide these records if any
    // If [ steward::retiredStatus ≠ "" ]
    // Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::sortRetired: “=” AND brainstate::groupDisplayID: “=” ] [ Restore ]
    // Else If [ steward::retiredStatus = "" ]
    // Extend Found Set [ Specified Find Requests: Find Records; Criteria: brainstate::hide: “t” AND brainstate::groupDisplayID: “=” ] [ Restore ]
    // End If
    Perform Script [ “CHUNK_retire” ]
    #
    #9 go to original record.
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ brainstate::_lockBrainstateID = $$record ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    End If

Fields used in this script	

    reference::farmerID
    steward::showORhide
    steward::hideStatus
    brainstate::groupType
    brainstate::_keyUser
    brainstate::hide
    brainstate::groupID
    steward::retiredStatus
    brainstate::sortRetired
    brainstate::groupDisplayID
    brainstate::_lockBrainstateID

Scripts used in this script	

    sortRestoreAfterScript
    CHUNK_retire

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [goBackButton_FindRecordsChunk]	Parent Folder: [show/hide buttons and checkboxes]	
Script Name	ShowButton
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Freeze Window
    Set Field [ steward::showORhide; "show" ]
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    If [ steward::showStatus = "" ]
    #This script is activited by the hide button. When clicked the script performs a find of all the user records where the user has not clicked the view checkbox putting a 't' into the view field. Thus it finds the users brainstate records with blank view fields.
    Set Variable [ $user; Value:reference::farmerID ]
    Enter Find Mode [ ]
    Set Field [ brainstate::Show; "t" ]
    Set Field [ brainstate::_keyUser; $user ]
    #If the user wants to hide brainstate records than they want find only brainstate records where show = t; and if they want to show all brainstate records then they just perform a find for all their records regardless of show status.
    Perform Find [ ]
    #why?
    If [ Get ( LastError ) = 401 ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $user ]
    Perform Find [ ]
    Else If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error performing hide script"; Buttons: “OK” ]
    Halt Script
    End If
    Set Field [ steward::showStatus; "t" ]
    Go to Field [ ]
    If [ steward::retiredStatus ≠ "" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    End If
    If [ steward::showStatus ≠ "" ]
    #This script is activited by the hide button. When clicked the script performs a find of all the user records where the user has not clicked the view checkbox putting a 't' into the view field. Thus it finds the users brainstate records with blank view fields.
    Set Variable [ $user; Value:reference::farmerID ]
    Enter Find Mode [ ]
    Set Field [ brainstate::_keyUser; $user ]
    #If the user wants to hide brainstate records than they want find only brainstate records where show = t; and if they want to show all brainstate records then they just perform a find for all their records regardless of show status.
    Perform Find [ ]
    If [ Get ( LastError ) = 401 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error performing view script"; Buttons: “OK” ]
    Else If [ Get ( LastError ) ≠ 0 ]
    Show Custom Dialog [ Title: "!"; Message: "Unexpected error performing view script"; Buttons: “OK” ]
    Halt Script
    End If
    Set Field [ steward::showStatus; "" ]
    Go to Record/Request/Page [ First ]
    Go to Field [ ]
    If [ steward::retiredStatus ≠ "" ]
    Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ] [ Restore ]
    End If
    Sort Records [ ] [ No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    End If

Fields used in this script	

    steward::showORhide
    steward::showStatus
    reference::farmerID
    brainstate::Show
    brainstate::_keyUser
    steward::retiredStatus
    brainstate::sortRetired

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Sorts
	Parent Folder: [Sorts]	Next Script: [DaySelectSortThenSort]
Script Name	sortRestoreAfterScript
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    UpdateTimeAfterSeperate (OLD)
    goDay
    goDayLastDayUsed
    goPlus1
    goPlus1iphone
    goMinus1
    goMinus1iphone
    CalendarDayCalc
    CalendarDayCalciphone
    goDayTotal
    CalendarDayCalcTotal
    Clear (old: opens windows to perform)
    goBackButton_FindRecordsChunk
    MoveToNewDayPart2

Script Definition
Script Steps	

    #PURPOSE after another script is run that may change time values this script is run to re-sort the records according time unless the user has them sorted another way, in which case this script is halted and no sort is performed.
    #
    #
    #
    #1 check if the sort status field to see if the user is currently sorting by time and if so sort the records
    If [ steward::chosenSort = "wact" or steward::chosenSort = "wtca" or steward::chosenSort = "act" or steward::chosenSort = "tca" or steward::chosenSort = "veto" or steward::chosenSort = "etov" or steward::chosenSort = "allow" or steward::chosenSort = "wolla" or steward::chosenSort = "Brainstates A-Z" or steward::chosenSort = "Brainstates Z-A" ]
    Sort Records [ Specified Sort Order: day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    #
    #not sure why I put this in here. So I'm leaving it for now until its use become apparent or I'm satisified it is not needed.
    // If [ day1::_keyDay = "" ]
    // Go to Record/Request/Page [ First ]
    // End If
    End If
    // If [ steward::chosenSort = "act" or steward::chosenSort = "tca" or steward::chosenSort = "veto" or steward::chosenSort = "etov" or steward::chosenSort = "allow" or steward::chosenSort = "wolla" ]
    // Show Custom Dialog [ Title: "!"; Message: "Your list of records has been resorted based on time: total time, start time, or f-stop time."; Buttons: “OK” ]
    // End If

Fields used in this script	

    steward::chosenSort
    day1::swStart
    brainstate::description
    day1::_keyDay

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortRestoreAfterScript]	Parent Folder: [Sorts]	Next Script: [CHUNK_DaySelectSortThenSort]
Script Name	DaySelectSortThenSort
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    showLinkedRecords
    addToTotalPart2
    seperateFromTotal
    to 1 chart
    to 1 Total
    to 1 chart Total
    goBackButton
    note veto view
    note veto view (old: opened things in new windows)
    UpdateTime
    UpdateTime (old: opened things in new windows)
    retireButton
    retireButtonOnViewLayout
    HideButton

Script Definition
Script Steps	

    #PURPOSE sort the user's records according to the sort specified in the sort status field
    #
    #
    #
    #1 find the sort the user wants and sort the user's records with it
    If [ Left ( Get ( LayoutName ) ; 5 ) ≠ "total" ]
    If [ steward::chosenSort = "Brainstates A-Z" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "number" ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "number" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$recordFIXTOMANYVARIABLES = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    Go to Field [ ]
    Set Variable [ $$record ]
    Set Variable [ $$recordnumber ]
    Set Variable [ $$recordFIXTOMANYVARIABLES ]
    Set Variable [ $$record ]
    Halt Script
    #
    Else If [ steward::chosenSort = "ms" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortMergeToBlanksToBottom; descending brainstate::groupID; ascending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "abc" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "sub" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "cat" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "allow" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    // Sort Records [ Specified Sort Order: day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    // Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::groupType; ascending day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::groupType; ascending day1::swStart; ascending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$recordFIXTOMANYVARIABLES = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next; Exit after last ]
    End Loop
    Set Variable [ $$recordFIXTOMANYVARIABLES ]
    // If [ $$recordnumber ≠ "" ]
    // Go to Record/Request/Page [ First ]
    // Scroll Window [ Home ]
    // Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    // Set Variable [ $$recordnumber ]
    // End If
    Halt Script
    #
    Else If [ steward::chosenSort = "veto" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::swStop; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "act" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "id" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "Brainstates Z-A" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "rebmun" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "sm" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::groupID; descending brainstate::groupOfGroupID; descending brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::description; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "cba" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "bus" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "tac" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "wolla" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStart; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "etov" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStop; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSort = "tca" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    End If
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    End If
    If [ steward::chosenSortTotal = "Brainstates A-Z" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "number" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "ms" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortMergeToBlanksToBottom; descending brainstate::groupID; ascending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "abc" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "sub" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "cat" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "allow" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "veto" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::swStop; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "act" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "id" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "Brainstates Z-A" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "rebmun" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "sm" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::groupID; descending brainstate::groupOfGroupID; descending brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::description; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "cba" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "bus" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "tac" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "wolla" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStart; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "etov" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStop; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    Else If [ steward::chosenSortTotal = "tca" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If
    Halt Script
    #
    End If
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    If [ $$recordnumber ≠ "" ]
    Scroll Window [ Home ]
    Go to Record/Request/Page [ $$recordnumber ] [ No dialog ]
    Set Variable [ $$recordnumber ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    day1::_keyDay
    brainstate::description
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::sortMergeToBlanksToBottom
    brainstate::groupID
    day1::swStart
    brainstate::groupType
    day1::swStop
    day1::swTotalActivity
    brainstate::groupOfGroupID
    steward::chosenSortTotal

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [DaySelectSortThenSort]	Parent Folder: [Sorts]	Next Script: [WeekMonthSelectSortThenSort]
Script Name	CHUNK_DaySelectSortThenSort
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    DeleteBrainstateFromTotal

Script Definition
Script Steps	

    #PURPOSE sort the user's records according to the sort specified in the sort status field (had to create this script for scripts that need this sort but should not halt after doing the sort but go on to other sorts)
    #
    #
    #
    #1 find the sort the user wants and sort the user's records with it
    If [ steward::chosenSort = "Brainstates A-Z" ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "number" ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "ms" ]
    Sort Records [ Specified Sort Order: brainstate::sortMergeToBlanksToBottom; descending brainstate::groupID; ascending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "abc" ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "sub" ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "cat" ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "allow" ]
    Sort Records [ Specified Sort Order: day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "veto" ]
    Sort Records [ Specified Sort Order: day1::swStop; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "act" ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "id" ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "Brainstates Z-A" ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "rebnum" ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "sm" ]
    Sort Records [ Specified Sort Order: brainstate::groupID; descending brainstate::groupOfGroupID; descending brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::description; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "cba" ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "bus" ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "tac" ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "wolla" ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStart; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "etov" ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStop; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    Else If [ steward::chosenSort = "tca" ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]
    Exit Script [ ]
    #
    End If
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ $$record ] [ No dialog ]
    Set Variable [ $$record ]

Fields used in this script	

    steward::chosenSort
    day1::_keyDay
    brainstate::description
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::sortMergeToBlanksToBottom
    brainstate::groupID
    day1::swStart
    day1::swStop
    day1::swTotalActivity
    brainstate::_lockBrainstateID
    brainstate::groupOfGroupID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CHUNK_DaySelectSortThenSort]	Parent Folder: [Sorts]	Next Script: [sortBrainstate]
Script Name	WeekMonthSelectSortThenSort
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    to 7 chart
    to 31
    to 31 chart
    to 7 Total
    to 7 chart Total
    to 32 Total
    to 31 chart Total

Script Definition
Script Steps	

    #PURPOSE sort the user's records according to the sort specified in the sort status field
    #
    #
    #
    #1 find the sort the user wants and sort the user's records with it
    If [ steward::chosenSort = "Brainstates A-Z" ]
    Sort Records [ Specified Sort Order: brainstate::sortBlanksToBottom; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "number" ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "ms" ]
    Sort Records [ Specified Sort Order: brainstate::sortMergeToBlanksToBottom; descending brainstate::groupID; ascending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "abc" ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "sub" ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "cat" ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "allow" ]
    Sort Records [ Specified Sort Order: day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "veto" ]
    Sort Records [ Specified Sort Order: day1::swStop; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "act" ]
    Sort Records [ Specified Sort Order: brainstate::sortBlanksToBottom; descending brainstate::monthsum; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "id" ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "Brainstates Z-A" ]
    Sort Records [ Specified Sort Order: brainstate::sortBlanksToBottom; descending brainstate::description; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "rebmun" ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "sm" ]
    Sort Records [ Specified Sort Order: brainstate::groupID; descending brainstate::groupOfGroupID; descending brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::description; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "cba" ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "bus" ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "tac" ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "wolla" ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStart; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "etov" ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStop; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    Else If [ steward::chosenSort = "tca" ]
    Sort Records [ Specified Sort Order: brainstate::monthsum; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Halt Script
    #
    End If
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]

Fields used in this script	

    steward::chosenSort
    brainstate::sortBlanksToBottom
    brainstate::description
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::sortMergeToBlanksToBottom
    brainstate::groupID
    day1::swStart
    day1::swStop
    brainstate::monthsum
    brainstate::_lockBrainstateID
    brainstate::groupOfGroupID
    day1::_keyDay

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [WeekMonthSelectSortThenSort]	Parent Folder: [Sorts]	Next Script: [sortBrainstateWeekMonth]
Script Name	sortBrainstate
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by record title
    #
    #
    #
    If [ steward::chosenSort = "Brainstates A-Z" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; descending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "Brainstates Z-A" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "Brainstates A-Z" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "Brainstates A-Z" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Halt Script
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    day1::_keyDay
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortBrainstate]	Parent Folder: [Sorts]	Next Script: [sortNumbers]
Script Name	sortBrainstateWeekMonth
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE by record title on week or month layouts
    #
    #
    #
    If [ steward::chosenSort = "Brainstates A-Z" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortBlanksToBottom; descending brainstate::description; descending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "Brainstates Z-A" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "Brainstates A-Z" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortBlanksToBottom; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "Brainstates A-Z" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    brainstate::sortBlanksToBottom
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortBrainstateWeekMonth]	Parent Folder: [Sorts]	Next Script: [sortMergeTo]
Script Name	sortNumbers
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    goToFarmer
    to 1
    EditTimePart2

Script Definition
Script Steps	

    #PURPOSE of the 4 number and alpha fields, sort by the first one
    #
    #
    #
    // If [ steward::chosenSort = "number" ]
    // Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    // Sort Records [ Specified Sort Order: brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    // Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    // Set Field [ steward::chosenSort; "rebmun" ]
    // Go to Record/Request/Page [ First ]
    // Loop
    // Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    // Go to Record/Request/Page [ Next ]
    // End Loop
    // Set Variable [ $$record ]
    // Go to Field [ ]
    // Halt Script
    // End If
    // If [ steward::chosenSort ≠ "number" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "number" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    // End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortNumbers]	Parent Folder: [Sorts]	Next Script: [sortAlpha]
Script Name	sortMergeTo
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by link ID number (records part of a total or grand total record)
    #
    #
    #
    If [ steward::chosenSort = "ms" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::groupDisplayID; descending brainstate::groupOfGroupDisplayID; descending brainstate::groupType; descending brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::description; descending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "sm" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "ms" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortMergeToBlanksToBottom; descending brainstate::groupDisplayID; ascending brainstate::groupOfGroupDisplayID; ascending brainstate::groupType; descending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "ms" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    brainstate::groupDisplayID
    brainstate::groupOfGroupDisplayID
    brainstate::groupType
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::description
    brainstate::sortMergeToBlanksToBottom
    brainstate::sortCategory

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortMergeTo]	Parent Folder: [Sorts]	Next Script: [sortSubNumbers]
Script Name	sortAlpha
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE of the 4 number and alpha fields, sort by the second one
    #
    #
    #
    If [ steward::chosenSort = "abc" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "cba" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "abc" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "abc" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortAlpha]	Parent Folder: [Sorts]	Next Script: [sortSubAlpha]
Script Name	sortSubNumbers
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE of the 4 number and alpha fields, sort by the second to last one
    #
    #
    #
    If [ steward::chosenSort = "sub" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "bus" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "sub" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "sub" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortSubNumbers]	Parent Folder: [Sorts]	Next Script: [sortStart]
Script Name	sortSubAlpha
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE of the 4 number and alpha fields, sort by the last one
    #
    #
    #
    If [ steward::chosenSort = "cat" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "tac" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "cat" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "cat" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortSubAlpha]	Parent Folder: [Sorts]	Next Script: [sortStop]
Script Name	sortStart
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by start time
    #
    #
    #
    If [ steward::chosenSort = "allow" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    // Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStart; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::groupType; ascending day1::swStart; ascending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "wolla" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "allow" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    // Sort Records [ Specified Sort Order: day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    // Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::groupType; ascending day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::groupType; ascending day1::swStart; descending brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "allow" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    day1::_keyDay
    day1::swStart
    brainstate::description
    brainstate::groupType
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortStart]	Parent Folder: [Sorts]	Next Script: [sortActivity]
Script Name	sortStop
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by stop time
    #
    #
    #
    If [ steward::chosenSort = "veto" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStop; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "etov" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "veto" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::swStop; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "veto" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    day1::_keyDay
    day1::swStop
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortStop]	Parent Folder: [Sorts]	Next Script: [sortActivityWeek]
Script Name	sortActivity
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by total time on the day layouts
    #
    #
    #
    If [ steward::chosenSort = "act" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "tca" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "act" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "act" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    day1::_keyDay
    day1::swTotalActivity
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortActivity]	Parent Folder: [Sorts]	Next Script: [sortID]
Script Name	sortActivityWeek
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    to 7
    to 31

Script Definition
Script Steps	

    #PURPOSE sort by total time on week or month layouts
    #
    #
    #
    If [ steward::chosenSort = "act" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::monthsum; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "tca" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "atc" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortBlanksToBottom; descending brainstate::monthsum; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "act" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID
    brainstate::monthsum
    brainstate::description
    brainstate::sortBlanksToBottom

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortActivityWeek]	Parent Folder: [Sorts]	Next Script: [sortBrainstateTotal]
Script Name	sortID
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by ID
    #
    #
    #
    If [ steward::chosenSort = "id" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "di" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSort ≠ "id" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSort; "id" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSort
    brainstate::_lockBrainstateID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortID]	Parent Folder: [Sorts]	Next Script: [sortNumbersTotal]
Script Name	sortBrainstateTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by record title
    #
    #
    #
    If [ steward::chosenSortTotal = "Brainstates A-Z" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; descending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "Brainstates Z-A" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "Brainstates A-Z" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "Brainstates A-Z" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    day1::_keyDay
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortBrainstateTotal]	Parent Folder: [Sorts]	Next Script: [sortAlphaTotal]
Script Name	sortNumbersTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE of the 4 number and alpha fields, sort by the first one
    #
    #
    #
    If [ steward::chosenSortTotal = "number" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; descending brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "rebmun" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "number" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "number" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortNumbersTotal]	Parent Folder: [Sorts]	Next Script: [sortSubNumbersTotal]
Script Name	sortAlphaTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE of the 4 number and alpha fields, sort by the second one
    #
    #
    #
    If [ steward::chosenSortTotal = "abc" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; descending brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "cba" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "abc" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "abc" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortAlphaTotal]	Parent Folder: [Sorts]	Next Script: [sortSubAlphaTotal]
Script Name	sortSubNumbersTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE of the 4 number and alpha fields, sort by the second to last one
    #
    #
    #
    If [ steward::chosenSortTotal = "sub" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; descending brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "bus" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "sub" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "sub" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortSubNumbersTotal]	Parent Folder: [Sorts]	Next Script: [sortStartTotal]
Script Name	sortSubAlphaTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE of the 4 number and alpha fields, sort by the last one
    #
    #
    #
    If [ steward::chosenSortTotal = "cat" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "tac" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "cat" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "cat" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortSubAlphaTotal]	Parent Folder: [Sorts]	Next Script: [sortStopTotal]
Script Name	sortStartTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by start time
    #
    #
    #
    If [ steward::chosenSortTotal = "allow" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStart; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "wolla" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "allow" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::swStart; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "allow" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    day1::_keyDay
    day1::swStart
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortStartTotal]	Parent Folder: [Sorts]	Next Script: [sortActivityTotal]
Script Name	sortStopTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by stop time
    #
    #
    #
    If [ steward::chosenSortTotal = "veto" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swStop; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "etov" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "veto" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::swStop; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "veto" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    day1::_keyDay
    day1::swStop
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortStopTotal]	Parent Folder: [Sorts]	Next Script: [sortActivityWeekTotal]
Script Name	sortActivityTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by total time on the day layouts
    #
    #
    #
    If [ steward::chosenSortTotal = "act" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "tca" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "act" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: day1::_keyDay; ascending day1::swTotalActivity; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "act" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    day1::_keyDay
    day1::swTotalActivity
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortActivityTotal]	Parent Folder: [Sorts]	Next Script: [sortIDTotal]
Script Name	sortActivityWeekTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by total time on week or month layouts
    #
    #
    #
    If [ steward::chosenSortTotal = "act" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::monthsum; descending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "tca" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "atc" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::sortBlanksToBottom; descending brainstate::monthsum; ascending brainstate::description; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "act" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID
    brainstate::monthsum
    brainstate::description
    brainstate::sortBlanksToBottom

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortActivityWeekTotal]	Parent Folder: [Sorts]	Next Script: [issueSortCategory]
Script Name	sortIDTotal
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE sort by ID
    #
    #
    #
    If [ steward::chosenSortTotal = "id" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; descending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "di" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    Halt Script
    End If
    If [ steward::chosenSortTotal ≠ "id" ]
    Set Variable [ $$record; Value:brainstate::_lockBrainstateID ]
    Sort Records [ Specified Sort Order: brainstate::_lockBrainstateID; ascending ] [ Restore; No dialog ]
    Set Field [ steward::chosenSortTotal; "id" ]
    Go to Record/Request/Page [ First ]
    Loop
    Exit Loop If [ $$record = brainstate::_lockBrainstateID ]
    Go to Record/Request/Page [ Next ]
    End Loop
    Set Variable [ $$record ]
    Go to Field [ ]
    End If

Fields used in this script	

    steward::chosenSortTotal
    brainstate::_lockBrainstateID

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortIDTotal]	Parent Folder: [Sorts]	Next Script: [issueSortStatus]
Script Name	issueSortCategory
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Sort Records [ Specified Sort Order: brainstate::description; ascending issueCategory::order; ascending issueCategory::text; ascending issueStatus::order; ascending issueStatus::text; ascending issue::order; based on value list: “1-99” issue::text; ascending ] [ Restore; No dialog ]
    Set Variable [ $$issueSort; Value:"category" ]

Fields used in this script	

    brainstate::description
    issueCategory::order
    issueCategory::text
    issueStatus::order
    issueStatus::text
    issue::order
    issue::text

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [issueSortCategory]	Parent Folder: [Sorts]	Next Script: [issueSortOrderNumber]
Script Name	issueSortStatus
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

    TsubtotalTimeByGroupForStatus

Script Definition
Script Steps	

    // If [ $$issueSort = "status" ]
    // Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; descending issueStatus::text; descending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    // Set Variable [ $$issueSort; Value:"sutats" ]
    // Exit Script [ ]
    // End If
    Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “1-99” issue::text; ascending ] [ Restore; No dialog ]
    Set Variable [ $$issueSort; Value:"status" ]
    Set Variable [ $$stopSubtotal; Value:1 ]
    Perform Script [ “TsubtotalTimeByGroup” ]

Fields used in this script	

    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issueCategory::text
    issue::order
    issue::text

Scripts used in this script	

    TsubtotalTimeByGroup

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [issueSortStatus]	Parent Folder: [Sorts]	Next Script: [issueSortDate]
Script Name	issueSortOrderNumber
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    // If [ $$issueSort = "status" ]
    // Sort Records [ Specified Sort Order: brainstate::description; ascending issueStatus::order; descending issueStatus::text; descending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “__-99” issue::text; ascending ] [ Restore; No dialog ]
    // Set Variable [ $$issueSort; Value:"sutats" ]
    // Exit Script [ ]
    // End If
    If [ Get ( FoundCount ) = 0 ]
    Set Variable [ $$issueSort; Value:"order" ]
    Refresh Window
    Exit Script [ ]
    End If
    Sort Records [ Specified Sort Order: brainstate::description; ascending issue::order; based on value list: “1-99” issueStatus::order; based on value list: “__-99” issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::text; ascending ] [ Restore; No dialog ]
    Set Variable [ $$issueSort; Value:"order" ]
    Set Variable [ $$stopSubtotal; Value:1 ]
    Perform Script [ “TsubtotalTimeByOrder” ]

Fields used in this script	

    brainstate::description
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issueCategory::text
    issue::order
    issue::text

Scripts used in this script	

    TsubtotalTimeByOrder

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [issueSortOrderNumber]	Parent Folder: [Sorts]	
Script Name	issueSortDate
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    If [ $$issueSort = "date" ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending issue::date; ascending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “1-99” issue::text; ascending ] [ Restore; No dialog ]
    Set Variable [ $$issueSort; Value:"date" ]
    Exit Script [ ]
    End If
    Sort Records [ Specified Sort Order: brainstate::description; ascending issue::date; descending issueStatus::order; ascending issueStatus::text; ascending issueCategory::order; ascending issueCategory::text; ascending issue::order; based on value list: “1-99” issue::text; ascending ] [ Restore; No dialog ]
    Set Variable [ $$issueSort; Value:"etad" ]

Fields used in this script	

    brainstate::description
    issue::date
    issueStatus::order
    issueStatus::text
    issueCategory::order
    issueCategory::text
    issue::order
    issue::text

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


backup
	Parent Folder: [backup]	Next Script: [restoreBackup]
Script Name	backup
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE remove focus from field (activited by a layout trigger)
    #
    #
    #
    #1 set the flag for backups to "backup" then open the BFData file
    Set Field [ backup::backup; "backup" ]
    Open File [ “MyData” ] [ Open hidden ]

Fields used in this script	

    backup::backup

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [backup]	Parent Folder: [backup]	
Script Name	restoreBackup
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE determine if file was opened by admin or by script, and then depending on who opened it: admin = remain open, backup script = save a copy of itself, or restore script = delete all its files and import backup files to replace them
    #
    #Errors will be generated when opening up backup file
    #as there is a dependency on the reference file and it
    #will probably not be located in the same folder as the
    #backup file. This dependency is not needed for backup.
    #So we have the system ignore this error message.
    Set Error Capture [ On ]
    Allow User Abort [ Off ]
    #
    #1 set the backup flag to restore (this is used by the open script in the main file to determine if it should make a copy of itself or replace all its current files with a backup
    Set Field [ backup::backup; "restore" ]
    #
    #2 open file and determine its location (path) then close it after its location has been pasted using that file's open script into the main data file
    #file is unknown so user is given the opportunity to point the database to the backup copy of their choice
    Open File [ <unknown> ]
    Close Window [ Name: "backup" ]
    #
    #3 open main data file and then using its open script restore the backup file just located in step 2
    Open File [ “MyData” ] [ Open hidden ]
    #
    #4 go to user layout and show all records
    Go to Layout [ “users” (steward) ]
    Show All Records

Fields used in this script	

    backup::backup

Scripts used in this script	

Layouts used in this script	

    users

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


triggered scripts
	Parent Folder: [triggered scripts]	Next Script: [layoutStatus]
Script Name	clear
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE clear field (activated by a layout trigger)
    #
    #
    #
    #1 clear field
    Clear [ ] [ Select ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [clear]	Parent Folder: [triggered scripts]	Next Script: [sortByNumber]
Script Name	layoutStatus
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE set the layout status field with the layout that triggers this script when it loads
    #
    #
    If [ Get (LayoutName) = $$loglayout or $$otherApps = 1 ]
    Exit Script [ ]
    End If
    #
    #1 set the layout status field
    Set Field [ steward::chosenLayout; Get ( LayoutName ) ]
    #
    #2 set the layout variable (I think I created this and then didn't end up using it, I think. I can't find it being used in any scripts, but due to paranoia I'm leaving it here. I'm just to tired at this point to look for it.)
    Set Variable [ $$layout; Value:Get ( LayoutName ) ]
    #
    Set Field [ steward::windowSizeAndPlace; Get ( WindowHeight ) ]
    Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowWidth ) ]
    Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowTop ) ]
    Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowLeft ) ]
    Set Field [ steward::windowZoom; Get ( WindowZoomLevel ) ]

Fields used in this script	

    steward::chosenLayout
    steward::windowSizeAndPlace
    steward::windowZoom

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [layoutStatus]	Parent Folder: [triggered scripts]	Next Script: [layoutExit]
Script Name	sortByNumber
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    Sort Records [ Specified Sort Order: brainstate::sortNumber; based on value list: “__-99” brainstate::sortAlpha; based on value list: “sortAlpha” brainstate::sortSubNumber; based on value list: “__-99” brainstate::sortCategory; based on value list: “sortAlpha” brainstate::description; ascending ] [ Restore; No dialog ]

Fields used in this script	

    brainstate::sortNumber
    brainstate::sortAlpha
    brainstate::sortSubNumber
    brainstate::sortCategory
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [sortByNumber]	Parent Folder: [triggered scripts]	Next Script: [xpLayout]
Script Name	layoutExit
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE set the layout status field with the layout that triggers this script when it loads
    #
    #
    #
    #1 set the layout status field
    Set Field [ steward::windowSizeAndPlace; Get ( WindowWidth ) ]
    Set Field [ steward::windowSizeAndPlace[2]; Get ( WindowHeight ) ]
    Set Field [ steward::windowSizeAndPlace[3]; Get ( WindowLeft ) ]
    Set Field [ steward::windowSizeAndPlace[4]; Get ( WindowTop ) ]
    #
    #2 set the layout variable (I think I created this and then didn't end up using it, I think. I can't find it being used in any scripts, but due to paranoia I'm leaving it here. I'm just to tired at this point to look for it.)

Fields used in this script	

    steward::windowSizeAndPlace

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [layoutExit]	Parent Folder: [triggered scripts]	Next Script: [exitField]
Script Name	xpLayout
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE set the layout status field with the layout that triggers this script when it loads
    #
    #
    If [ Get ( SystemPlatform ) = -2 ]
    Go to Layout [ “01SortAndScheduleXP” (brainstate) ]
    Exit Script [ ]
    End If
    #
    Go to Layout [ “01SortAndSchedule” (brainstate) ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

    01SortAndScheduleXP
    01SortAndSchedule

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [xpLayout]	Parent Folder: [triggered scripts]	Next Script: [goToField]
Script Name	exitField
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE remove focus from field (activited by a layout trigger)
    #
    #
    #
    #1 remove focus from a field
    Go to Field [ ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [exitField]	Parent Folder: [triggered scripts]	
Script Name	goToField
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #PURPOSE remove focus from field (activited by a layout trigger)
    #
    #
    #
    #1 remove focus from a field
    Go to Field [ ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


not sure if these are being used
	Parent Folder: [not sure if these are being used]	Next Script: [ShowInactiveToo????]
Script Name	clearAndExit
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #not sure if this is being used somewhere as layout trigger
    Set Field [ "" ]
    Go to Field [ ]

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [clearAndExit]	Parent Folder: [not sure if these are being used]	Next Script: [CloseWindow???]
Script Name	ShowInactiveToo????
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #not sure if this is being used somewhere
    Copy [ brainstate::_keyUser ] [ Select ]
    Enter Find Mode [ ]
    Paste [ brainstate::_keyUser ] [ Select ]
    Perform Find [ ]
    Sort Records [ Specified Sort Order: brainstate::description; ascending ] [ Restore; No dialog ]
    Go to Record/Request/Page [ First ]
    Go to Field [ brainstate::description ]

Fields used in this script	

    brainstate::_keyUser
    brainstate::description

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [ShowInactiveToo????]	Parent Folder: [not sure if these are being used]	Next Script: [chartTime???]
Script Name	CloseWindow???
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #not sure if this is being used somewhere as a button
    Close Window [ Current Window ]
    Halt Script

Fields used in this script	

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


Previous Script: [CloseWindow???]	Parent Folder: [not sure if these are being used]	
Script Name	chartTime???
Run script with full access privileges	Off
Include In Menu	Yes
Layouts that use this script	

Scripts that use this script	

Script Definition
Script Steps	

    #not sure if this is being used somewhere
    Set Field [ steward::chartTime1; reference::chartTime ]
    Go to Field [ ]

Fields used in this script	

    reference::chartTime
    steward::chartTime1

Scripts used in this script	

Layouts used in this script	

Tables used in this script	

Table occurrences used by this script	

Custom Functions used by this script	

Custom menu set used by this script	


