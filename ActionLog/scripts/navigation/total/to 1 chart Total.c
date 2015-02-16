navigation: total: to 1 chart Total
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
#4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be sorted out of
top of list), and go to the first record.
Perform Script [ “DaySelectSortThenSort” ]
January 5, 平成26 19:21:45 ActionLog.fp7 - to 1 chart Total -1-
