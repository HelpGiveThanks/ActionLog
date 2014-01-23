navigation: goToFarmer
#PURPOSE go the selected farmer's records from the createEditFarmer layout. (This is script is identical to the switchFarmer script except for
step 1, which is required because the reference ﬁeld is not available on this layout, and so the user's ID must be taken from the user table,
not the reference table.)
#
#
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#
#Loop to correct record. Portal shows up in on each
#records layout, so ﬁrst before the script continues
#we need to make sure we are on the record that the user selected.
Set Variable [ $userID; Value:steward 2::_lockUser ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $userID = steward::_lockUser ]
Go to Record/Request/Page
[ Next ]
End Loop
#
#
Freeze Window
If [ Get ( SystemPlatform ) ≠ 3 and steward::iPhoneLayout = "" ]
// Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [1]; Width: steward::windowSizeAndPlace [2]; Top:
steward::windowSizeAndPlace [3]; Left: steward::windowSizeAndPlace [4] ]
Else If [ steward::iPhoneLayout ≠ "" ]
Move/Resize Window [ Current Window; Height: steward::windowSizeAndPlace [5]; Width: steward::windowSizeAndPlace [6]; Top:
steward::windowSizeAndPlace [7]; Left: steward::windowSizeAndPlace [8] ]
End If
#
#1 capture selected userID, insert it into the referenceID ﬁeld, then go to layout showing brainstate records.
Set Variable [ $userID; Value:steward::_lockUser ]
Set Field [ reference::farmerID; $userID ]
#
#2 ﬁnd this user's records
Perform Script [ “CHUNK_createRecordsForNewUsers” ]
#
#4 show the user's name
Set Field [ reference::farmerName; steward::FirstPlusLast ]
#
#5 show/hide all records according the user's last settings
If [ steward::hideStatus = "" and steward::showORhide = "show" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::hide: “=” ]
[ Restore ]
Else If [ steward::showStatus ≠ "" and steward::showORhide = "hide" ]
Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::groupType: “=” ]
[ Restore ]
End If
#8 it the user wants retired records hidden then hide these records if any
Perform Script [ “CHUNK_retire” ]
#
// #6 go to user's chosen day, sort records, and choose last used layout
// If [ Left ( steward::chosenLayout ; 2 ) = "01" ]
// Perform Script [ “to 1” ]
// Else If [ Left ( steward::chosenLayout ; 2 ) = "07" ]
// Perform Script [ “to 7” ]
January 5, 平成26 14:38:23 ActionLog.fp7 - goToFarmer -1-navigation: goToFarmer
// Else If [ Left ( steward::chosenLayout ; 2 ) = "31" ]
// Perform Script [ “to 31” ]
// End If
#
#Set window title.
Set Window Title [ Current Window; New Title: "Timer" ]
#
#Size window to 150.
Set Zoom Level
[ 150% ]
#
#1 go to user's last layout
If [ steward::chosenLayout = "users" ]
Go to Layout [ “01Main” (brainstate) ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
Go to Layout [ “MainiPhone” (brainstate) ]
End If
#END NOT TESTED
Else If [ steward::chosenLayout ≠ "users" ]
Go to Layout [ “01Main” (brainstate) ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
Go to Layout [ “MainiPhone” (brainstate) ]
End If
#END NOT TESTED
End If
#
#2 go to user's chosen day
Set Field [ steward::chosenDay; Get ( CurrentDate ) ]
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
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Field [ steward::chosenLayout; steward::chosenLayoutMain ]
Perform Script [ “sortNumbers” ]
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
January 5, 平成26 14:38:23 ActionLog.fp7 - goToFarmer -2-navigation: goToFarmer
Perform Script [ “openSpeciﬁcAction” ]
Select Window [ Name: "Timer"; Current ﬁle ]
Set Variable [ $$stopRecordLoad ]
Perform Script [ “recordLoad” ]
January 5, 平成26 14:38:23 ActionLog.fp7 - goToFarmer -3-
