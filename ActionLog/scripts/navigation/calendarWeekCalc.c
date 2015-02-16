navigation: CalendarWeekCalc
#PURPOSE calculate the total time for 7 days worth of time
#
#
#
#1 add 7 days to the users selection of the day desired to start the week. (Day 1 is the day the user is currently looking at on the day view
layouts. In order to give the user on the week and month view layouts a calendar going from 1 to 7 or 31 it is neccessary to put the Day 1
field at the far right, or furtherest from the titles of the records. The user expects to to select the day they want to see by clicking on the day
field closest to do the titles, which is day 7 on the week and day 31 on month view. So this script setp captures this left most choice and
adds the 6 or 30 to it and applies it to the day 1 field.)
// Set Field [ reference::day1; reference::day1 + 6 ]
Set Field [ reference::day1; reference::day7Calc + 6 ]
#
#2 capture user's current date perference for starting the week
Set Field [ steward::chosenWeek; reference::day1 ]
#
#3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for
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
day7::swTotalActivity ]
Set Field [ brainstate::monthsumaverage; If (
If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 )
 = 0
 ; "" ; brainstate::monthsum /
(
If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 )
)
 ) ]
Set Field [ brainstate::monthsumdays;
(
If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 )
) ]
January 5, 平成26 14:43:05 ActionLog.fp7 - CalendarWeekCalc -1-navigation: CalendarWeekCalc
Set Field [ brainstate::monthsumdays;
(
If ( day1::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day2::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day3::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day4::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day5::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day6::swTotalActivity ≠ 0 ; 1 ; 0 ) +
If ( day7::swTotalActivity ≠ 0 ; 1 ; 0 )
) ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#7 finish by going back to the orginal layout and first record
Go to Layout [ original layout ]
Go to Record/Request/Page
[ First ]
Set Field [ reference::day7Calc; reference::day7 ]
January 5, 平成26 14:43:05 ActionLog.fp7 - CalendarWeekCalc -2-
