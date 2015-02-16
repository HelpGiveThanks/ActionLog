navigation: goDayLastDayUsed
#PURPOSE go back or forwards the number of days specified in the number field to the right the go button on the 1 day layouts
#
#
If [ brainstate::DaysSinceLastUse = "" or brainstate::DaysSinceLastUse = 0 or brainstate::DaysSinceLastUseToggle ≠ "" ]
Halt Script
End If
#
#1 capture desired number of days and add to the current date. (User picks days from a drop down list that includes negative and positive
numbers.)
Set Field [ reference::day1; reference::day1 - brainstate::DaysSinceLastUse ]
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
#3 capture user's current date perference
Set Field [ steward::chosenDay; reference::day1 ]
#
#4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its
time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is
only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the first record.
Perform Script [ “sortRestoreAfterScript” ]
January 5, 平成26 14:30:12 ActionLog.fp7 - goDayLastDayUsed -1-
