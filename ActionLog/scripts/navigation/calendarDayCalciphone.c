navigation: CalendarDayCalciphone
#PURPOSE change the day to start the week and recalculate the Day1 key fields to show the user's data for this day.
#
#
#
#1 capture the new day as the user's choosen day
Set Field [ steward::chosenDay; reference::day1 ]
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
#disable next step because in view is not a list, so sorting is not helpful.
// Perform Script [ “sortRestoreAfterScript” ]
Go to Field [ ]
January 5, 平成26 14:42:16 ActionLog.fp7 - CalendarDayCalciphone -1-
