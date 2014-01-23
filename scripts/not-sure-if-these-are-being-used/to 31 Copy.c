not sure if these are being used: to 31 Copy
#PURPOSE go to time layout 31
#
#
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
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#7 go back to layout time 7, sort records (neccessary because the week and month view usually show more active records that need to be
sorted to the top of list), and go to the ﬁrst record.
Go to Layout [ original layout ]
January 6, 平成26 12:57:25 ActionLog.fp7 - to 31 Copy -1-
