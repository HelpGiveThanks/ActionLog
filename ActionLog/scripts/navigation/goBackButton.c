navigation: goBackButton
#PURPOSE return the user to the layout they where one and find all the records being looked at, and hide the records previously hidden (plus or
minus records created and deleted on this layout).
#
#
If [ Get (WindowName) = "Day" or
Get (WindowName) = "Tag" or
Get (WindowName) = "Specific Action" ]
Close Window [ Name: "Day"; Current file ]
Close Window [ Name: "Specific Action"; Current file ]
Close Window [ Name: "Tag"; Current file ]
Set Variable [ $$log ]
Set Variable [ $$issue ]
Set Variable [ $$group ]
Set Variable [ $$status ]
Set Variable [ $$timeAll ]
Set Variable [ $$issueSort ]
Set Variable [ $$logissues ]
Set Variable [ $$issueLogs ]
Set Variable [ $$logrecordID ]
Set Variable [ $$logBrainstate ]
Set Variable [ $$issueRecordID ]
Exit Script [ ]
End If
#
#basic administration tasks
Set Error Capture [ On ]
Allow User Abort [ Off ]
Set Variable [ $userID; Value:reference::farmerID ]
#reset recordnumber for use in sort on final layout and erase holder variable.
Set Variable [ $$recordnumber; Value:$$recordnumber2 ]
Set Variable [ $$recordnumber2 ]
#
#
#
#A BEGIN go back to log layout
#
#1 determine if user is on a log layout
If [ Left ( Get ( LayoutName ); 3 ) = "log" or Left ( $$iphoneLog; 8 ) = "TotalLog" ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
If [ Left ( $$iphoneLog; 8 ) = "TotalLog" ]
Go to Layout [ “TotalLogEditTimeiPhone” (brainstate) ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Scroll Window
[ Home ]
Set Variable [ $$iphoneLog; Value:"" ]
Halt Script
End If
Go to Layout [ “LogEditTimeiPhone” (brainstate) ]
Go to Record/Request/Page [ $$record ]
[ No dialog ]
Scroll Window
[ Home ]
Set Variable [ $$iphoneLog; Value:"" ]
Halt Script
End If
Go to Layout [ $$loglayout ]
January 5, 平成26 19:14:00 ActionLog.fp7 - goBackButton -1-navigation: goBackButton
Set Variable [ $$loglayout; Value:"" ]
// Go to Record/Request/Page [ $$record ]
[ No dialog ]
Halt Script
End If
#
#A END go back to log layout
#
#
#
#B BEGIN check if user just deleted the total or grandtotal record on a view layout and if so tell them why they are leaving the view that they
were on.
#
#1 determine if user deleted a total or grandtotal record
If [ Left ( Get ( LayoutName ); 5 ) = "Total" and $$deleteID = "total" ]
Show Custom Dialog [ Title: "!"; Message: "You are now being returned to your previous screen as this screen was for showing the total
record that you just deleted and all the records that it totaled."; Buttons: “OK” ]
Else If [ Left ( Get ( LayoutName ); 5 ) = "viewG" and $$deleteID = "grandtotal" ]
Show Custom Dialog [ Title: "!"; Message: "You are now being returned to your previous screen as this screen was for showing the
grandtotal record that you just deleted and all the records that it totaled."; Buttons: “OK” ]
End If
#
#2 clear the $$deleteID variable so that it will not trigger the above dialog boxes without a delete being done.
Set Variable [ $$deleteID; Value:"" ]
#
#B END check if user just deleted the total or grandtotal record on a view layout and if so tell them why they are leaving the view that they were
on.
#
#
#
#C BEGIN show user all records they where looking at previously on the main screen
#
#
#2 show user all records at which they were previously looking
Perform Script [ “goBackButton_FindRecordsChunk” ]
#
#C END shorten list if user has selected to not show some of their records
#
#
#
#D BEGIN go to layout
#
#1 go to user's last layout
Go to Layout [ steward::chosenLayout ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
Go to Layout [ “MainiPhone” (brainstate) ]
End If
Freeze Window
#
#2 go to user's chosen day
Set Field [ reference::day1; steward::chosenDay ]
#
#3 refresh the layout so that the key fields for each record will be recalculated based on the new day selected. The date and times shown for
each record are in a table related to each brainstate record by their dates. The key date fields for all brainstate records are calculations
where the value equals the reference field date shown at the top of the screen in the green, red, or yellow box. So when the user changes
the date in the reference field (top colored box) and then this script refreshes the database, all the brainstate records including the ones not
shown recalculate their key fields, the result being they all take in the new date. This means that the related day records now change too to
show the user the day records that match the updated brainstate record keys. (These day fields are locked to their related brainstate
records by the brainstate records ID number. Using these to keys, the database is able to return the desired day fields for brainstate record
the user elects to view at any one time.)
January 5, 平成26 19:14:00 ActionLog.fp7 - goBackButton -2-navigation: goBackButton
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
#
#D END go to layout
January 5, 平成26 19:14:00 ActionLog.fp7 - goBackButton -3-
