navigation: goPlus1
#PURPOSE go forwards 1 day
#
#
#
#Add 1 to the current date.
Set Field [ reference::day1; reference::day1 + 1 ]
#
#Refresh the layout so that the key fields for each
#record will be recalculated based on the new day
#selected. The date and times shown for each
#record are in a table related to each brainstate
#record by their dates. The key date fields for all
#brainstate records are calculations where the value
# equals the reference field date shown at the top of
#the screen in the green, red, or yellow box. So
#when the user changes the date in the reference
#field (top colored box) and then this script
#refreshes the database, all the brainstate records
#including the ones not shown recalculate their key
# fields, the result being they all take in the new
#date. This means that the related day records now
# change too to show the user the day records that
#match the updated brainstate record keys. (These
# day fields are locked to their related brainstate
#records by the brainstate records ID number.
# Using these two keys, the database is able to return
# the desired day fields for the brainstate record the
#user elects to view at any time.)
Refresh Window
[ Flush cached join results ]
#
#Capture the new day as the user's choosen
#day, and as Timer window's day.
Set Field [ user::chosenDay; reference::day1 ]
#
#Sort the records.
If [ Filter ( Get ( LayoutName ) ; "a" ) = "a"
//Only the "main" layout has an 'a' in it. ]
Sort Records [ Specified Sort Order: timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
Else
Sort Records [ Specified Sort Order: day1::_keyDay; ascending
timer::groupType; ascending
day1::swStart; ascending
timer::sortNumber; based on value list: “__-99”
timer::sortAlpha; based on value list: “sortAlpha”
timer::sortSubNumber; based on value list: “__-99”
timer::sortCategory; based on value list: “sortAlpha”
timer::description; ascending ]
[ Restore; No dialog ]
End If
#
December 10, ଘ౮28 20:00:04 ActionLog.fp7 - goPlus1 -1-
