navigation: to 31
#PURPOSE go to time layout 31
#
#
#
#1 go to user's chosen day to start the month view
// Set Field [ reference::day1; Get ( CurrentDate ) ]
#
#2 go to requested layout. (This step prevents the user from seeing the current screen change with the a new date before going to the new
layout.)
Go to Layout [ “31SortN” (brainstate) ]
#
#3 refresh the layout so that the key ﬁelds for each record will be recalculated based on the new day selected. The date and times shown for
each record are in a table related to each brainstate record by their dates. The key date ﬁelds for all brainstate records are calculations
where the value equals the reference ﬁeld date shown at the top of the screen in the green, red, or yellow box. So when the user changes
the date in the reference ﬁeld (top colored box) and then this script refreshes the database, all the brainstate records including the ones not
shown recalculate their key ﬁelds, the result being they all take in the new date. This means that the related day records now change too to
show the user the day records that match the updated brainstate record keys. (These day ﬁelds are locked to their related brainstate
records by the brainstate records ID number. Using these to keys, the database is able to return the desired day ﬁelds for brainstate record
the user elects to view at any one time.)
Refresh Window
[ Flush cached join results ]
#
#4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is
calcuated. (This must be done after ﬂushing the cache (step 2) otherwise the ﬂush unfreezes the window.)
Freeze Window
#
#5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
Go to Layout [ “calcBrainstateTable” (brainstate) ]
#
#6 total 7 days of time for each record displayed, along with the average time, and number of days contributing time the this average
Go to Record/Request/Page
[ First ]
Loop
Set Field [ brainstate::monthsum; day1::swTotalActivity +
day2::swTotalActivity +
day3::swTotalActivity +
day4::swTotalActivity +
day5::swTotalActivity +
day6::swTotalActivity +
day7::swTotalActivity +
day8::swTotalActivity +
day9::swTotalActivity +
day10::swTotalActivity +
day11::swTotalActivity +
day12::swTotalActivity +
day13::swTotalActivity +
day14::swTotalActivity +
day15::swTotalActivity +
day16::swTotalActivity +
day17::swTotalActivity +
day18::swTotalActivity +
day19::swTotalActivity +
day20::swTotalActivity +
day21::swTotalActivity +
day22::swTotalActivity +
day23::swTotalActivity +
day24::swTotalActivity +
day25::swTotalActivity +
day26::swTotalActivity +
day27::swTotalActivity +
day28::swTotalActivity +
day29::swTotalActivity +
day30::swTotalActivity +
day31::swTotalActivity ]
Set Field [ brainstate::monthsumaverage; If (
If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 )
 = 0
 ; "" ; brainstate::monthsum /
(
If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 )
)
 ) ]
January 5, 平成26 19:05:37 ActionLog.fp7 - to 31 -1-navigation: to 31
Set Field [ brainstate::monthsumaverage; If (
If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 )
 = 0
 ; "" ; brainstate::monthsum /
(
If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 )
)
 ) ]
Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
January 5, 平成26 19:05:37 ActionLog.fp7 - to 31 -2-navigation: to 31
Set Field [ brainstate::monthsumdays; If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day8::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day9::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day10::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day11::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day12::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day13::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day14::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day15::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day16::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day17::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day18::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day19::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day20::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day21::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day22::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day23::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day24::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day25::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day26::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day27::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day28::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day29::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day30::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day31::swTotalActivity ≠ 0 ; 1 ; 0 ) ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#7 go to active brainstate or ﬁrst brainstate.
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ day1::swBugField = "veto" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ day1::swBugField ≠ "veto" ]
Go to Record/Request/Page
[ First ]
End If
#
#8 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be
sorted to the top of list), and go to the ﬁrst record.
Go to Layout [ “31SortN” (brainstate) ]
Set Field [ steward::chosenSort; "act" ]
Set Field [ reference::day31Calc; reference::day31 ]
Perform Script [ “sortActivityWeek” ]
Perform Script [ “WeekMonthSelectSortThenSort” ]
January 5, 平成26 19:05:37 ActionLog.fp7 - to 31 -3-
