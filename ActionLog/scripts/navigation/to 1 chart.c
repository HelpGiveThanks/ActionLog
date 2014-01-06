navigation: to 1 chart
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
#4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be sorted out of
top of list), and go to the ﬁrst record.
Perform Script [ “DaySelectSortThenSort” ]
January 5, 平成26 19:02:48 ActionLog.fp7 - to 1 chart -1-
