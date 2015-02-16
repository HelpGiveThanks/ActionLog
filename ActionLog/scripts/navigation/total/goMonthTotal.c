navigation: total: goMonthTotal
#PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 7 day layouts
#
#
#
#1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive
numbers.)
Set Field [ reference::day1; reference::day1 + reference::go ]
#
#2 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for
each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations
where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes
the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not
shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to
show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate
records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record
the user elects to view at any one time.)
Refresh Window
[ Flush cached join results ]
#
#3 capture user's current date perference for starting the month
Set Field [ steward::chosenMonthTotal; reference::day1 ]
#
#4 freeze window to speed up the calculation by refreshing the window after all records have been calcuated rather than after each record is
calcuated. (This must be done after ﬂushing the cache (step 2) otherwise the ﬂush unfreezes the window.)
Freeze Window
#
#5 go to a different layout to perform this script, which prevents user from seeing the current window refresh.
Go to Layout [ “calcBrainstateTable” (brainstate) ]
#
#6 total 31 days of time for each record displayed, along with the average time, and number of days contributing time the this average
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
January 5, 平成26 19:16:54 ActionLog.fp7 - goMonthTotal -1-navigation: total: goMonthTotal
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
January 5, 平成26 19:16:54 ActionLog.fp7 - goMonthTotal -2-navigation: total: goMonthTotal
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
#7 finish by going back to the orginal layout and first record
Go to Layout [ original layout ]
Go to Record/Request/Page
[ First ]
January 5, 平成26 19:16:54 ActionLog.fp7 - goMonthTotal -3-
