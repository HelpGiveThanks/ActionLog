navigation: openActionLogs
#
#
#Create a new user record if there are none.
If [ Get ( FoundCount ) = 0 ]
Perform Script [ “newUser (update Name change from newFarmer)” ]
Exit Script [ ]
End If
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#
#Loop to correct record. Portal shows up in on each
#records layout, so first before the script continues
#we need to make sure we are on the record that the user selected.
Set Variable [ $userID; Value:user 2::_lockUser ]
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $userID = user::_lockUser ]
Go to Record/Request/Page
[ Next ]
End Loop
#
#
Freeze Window
If [ Get ( SystemPlatform ) ≠ 3 and user::iPhoneLayout = "" ]
// Move/Resize Window [ Current Window; Height: user::windowSizeAndPlace [1]; Width: user::windowSizeAndPlace [2]; Top:
user::windowSizeAndPlace [3]; Left: user::windowSizeAndPlace [4] ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight) - 2 * ( Get (ScreenHeight) * .05 ); Width: Get
(ScreenWidth) * .8; Top: Get (ScreenHeight) * .05; Left: Get (ScreenWidth) * .1 ]
Else If [ user::iPhoneLayout ≠ "" ]
Move/Resize Window [ Current Window; Height: user::windowSizeAndPlace [5]; Width: user::windowSizeAndPlace [6]; Top:
user::windowSizeAndPlace [7]; Left: user::windowSizeAndPlace [8] ]
End If
#
#1 capture selected userID, insert it into the referenceID field, then go to layout showing brainstate records.
Set Variable [ $userID; Value:user::_lockUser ]
Set Field [ reference::userID; $userID ]
#
#2 find this user's records
Perform Script [ “loadORcreateTimersForUser (update name changed from CHUNK_createRecordsForNewUsers )” ]
#
#4 show the user's name
Set Field [ reference::userName; user::FirstPlusLast ]
#
#5 show/hide all records according the user's last settings
If [ user::hideStatus = "" and user::showORhide = "show" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: timer::hide: “=” ]
[ Restore ]
Else If [ user::showStatus ≠ "" and user::showORhide = "hide" ]
Constrain Found Set [ Specified Find Requests: Omit Records; Criteria: timer::groupType: “=” ]
[ Restore ]
End If
#8 it the user wants retired records hidden then hide these records if any
Perform Script [ “CHUNK_retire” ]
#
// #6 go to user's chosen day, sort records, and choose last used layout
// If [ Left ( user::chosenLayout ; 2 ) = "01" ]
// Perform Script [ “to 1” ]
// Else If [ Left ( user::chosenLayout ; 2 ) = "07" ]
// Perform Script [ “to 7” ]
// Else If [ Left ( user::chosenLayout ; 2 ) = "31" ]
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
If [ user::chosenLayout = "users" ]
Go to Layout [ “01Main” (timer) ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or user::iPhoneLayout ≠ "" ]
Go to Layout [ “MainiPhone” (timer) ]
End If
#END NOT TESTED
Else If [ user::chosenLayout ≠ "users" ]
Go to Layout [ “01Main” (timer) ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or user::iPhoneLayout ≠ "" ]
Go to Layout [ “MainiPhone” (timer) ]
End If
#END NOT TESTED
End If
#
#2 go to user's chosen day
Set Field [ user::chosenDay; Get ( CurrentDate ) ]
Set Field [ reference::day1; user::chosenDay ]
#
#3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times
shown for each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records
are calculations where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box.
So when the user changes the date in the reference field (top colored box) and then this script refreshes the database, all the
brainstate records including the ones not shown recalculate their key fields, the result being they all take in the new date. This
means that the related day records now change too to show the user the day records that match the updated brainstate record
keys. (These day fields are locked to their related brainstate records by the brainstate records ID number. Using these to keys,
the database is able to return the desired day fields for brainstate record the user elects to view at any one time.)
Refresh Window
[ Flush cached join results ]
#
#4 sort records (neccessary because the week and month view usually show more active records than the day view that need to be
sorted out of top of list), and go to the first record.
Set Variable [ $$stopRecordLoad; Value:1 ]
Set Field [ user::chosenLayout; user::chosenLayoutMain ]
Perform Script [ “sortNumbers” ]
// #
// #7 go to active brainstate.
// Go to Record/Request/Page
[ First ]
// Loop
// Exit Loop If [ day1::swBugField = "veto" ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
#
#8 Select the default Specific Action timer.
If [ timer::_lockTimer ≠ user::DefaultSpecificAction ]
#
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ timer::_lockTimer = user::DefaultSpecificAction ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#If no default, go to the first timer.
If [ timer::_lockTimer ≠ user::DefaultSpecificAction ]
Go to Record/Request/Page
[ First ]
End If
End If
#
#9 Open Specific Action windows for the
#selected timer.
Perform Script [ “openSpecificAction (update)” ]
#
#10 View all windows.
If [ Get ( SystemPlatform ) ≠ 3 ]
Set Variable [ $$toggleSpecificActionView; Value:1 ]
#
#For some reason in FM13 the Timer window is
#flashing black when scripts run a find. After
#testing, the bug appears to shift to the Day
#window. If I repeat steps for it the problem is
#transfered to the Tag window, where it seems
#to be the least noticable. The exact file in
#FM10 does not have this problem.
Select Window [ Name: "Timer"; Current file ]
New Window [ Name: "TimerNew" ]
Close Window [ Name: "Timer"; Current file ]
Set Window Title [ Of Window: "TimerNew"; Current file; New Title: "Timer" ]
Move/Resize Window [ Name: "Timer"; Current file; Height: Get (ScreenHeight) - 276; Width: Get (ScreenWidth) - 344; Top: 251;
Left: 344 ]
#
Select Window [ Name: "Day"; Current file ]
New Window [ Name: "DayNew" ]
Close Window [ Name: "Day"; Current file ]
Set Window Title [ Of Window: "DayNew"; Current file; New Title: "Day" ]
Move/Resize Window [ Name: "Day"; Current file; Height: 266; Width: 344; Top: 0; Left: 344 ]
#
Move/Resize Window [ Name: "Tag"; Current file; Height: 266; Width: 344; Top: 0; Left: 688 ]
#
Move/Resize Window [ Name: "Specific Action"; Current file; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: 0 ]
End If
Select Window [ Name: "Timer"; Current file ]
#
#10 If the timer is not active go to the first timer.
If [ day1::swBugField ≠ "veto" ]
Go to Record/Request/Page
[ First ]
End If
#
#7 go to first active timer.
Loop
Exit Loop If [ day1::swBugField = "veto" ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#10 If the timer is not active go to the first timer.
If [ day1::swBugField ≠ "veto" ]
Go to Record/Request/Page
[ First ]
End If
#
If [ day1::swBugField ≠ "veto" ]
Go to Record/Request/Page
[ First ]
End If
Set Variable [ $$stopRecordLoad ]
Perform Script [ “recordLoad (update)” ]
#
December 10, ଘ౮28 20:17:26 ActionLog.fp7 - openActionLogs -1-
