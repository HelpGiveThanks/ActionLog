navigation: goPlus1
#PURPOSE go forwards 1 day
#
#
#
#1 add one the current date.
Set Field [ reference::day1; reference::day1 + 1 ]
#
#2 refresh the layout so that the key ﬁelds for each
#record will be recalculated based on the new day
#selected. The date and times shown for each
#record are in a table related to each brainstate
#record by their dates. The key date ﬁelds for all
#brainstate records are calculations where the value
# equals the reference ﬁeld date shown at the top of
#the screen in the green, red, or yellow box. So
#when the user changes the date in the reference
#ﬁeld (top colored box) and then this script
#refreshes the database, all the brainstate records
#including the ones not shown recalculate their key
# ﬁelds, the result being they all take in the new
#date. This means that the related day records now
# change too to show the user the day records that
#match the updated brainstate record keys. (These
# day ﬁelds are locked to their related brainstate
#records by the brainstate records ID number.
# Using these two keys, the database is able to return
# the desired day ﬁelds for the brainstate record the
#user elects to view at any time.)
Refresh Window
[ Flush cached join results ]
#
#3 capture user's current date perference
Set Field [ steward::chosenDay; reference::day1 ]
#
// #4 sort the records if the current sort is based on time so if any time is changed it goes up or down the current set of records according to its
time value. The point is to keep the focus where the user expects it to be so the sort, which removes the focus from the current record is
only done if the user wants the records sorted by time, in which case after the sort the focus is returned to the ﬁrst record.
// Perform Script [ “sortRestoreAfterScript” ]
#
#4 sort the records
If [ Get ( LayoutName ) = "01EditTime" ]
Sort Records [ Speciﬁed Sort Order: day1::_keyDay; ascending
brainstate::groupType; ascending
day1::swStart; ascending
brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
Else
Sort Records [ Speciﬁed Sort Order: brainstate::sortNumber; based on value list: “__-99”
brainstate::sortAlpha; based on value list: “sortAlpha”
brainstate::sortSubNumber; based on value list: “__-99”
brainstate::sortCategory; based on value list: “sortAlpha”
brainstate::description; ascending ]
[ Restore; No dialog ]
End If
February 6, 平成26 12:33:09 ActionLog.fp7 - goPlus1 -1-