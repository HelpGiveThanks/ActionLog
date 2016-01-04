specific action log: updateTimerTotalTimeInTagWindow
#
#Stop script if user is NOT in the process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action tag or click the cancel button in the Tag window. After you do this you
can re-calculate total time logged under each tag."; Buttons: “OK” ]
Exit Script [ ]
End If
#
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Prevent windows from flashing and script from slowing
Set Variable [ $$stopRecordLoad; Value:1 ]
#
New Window [ Height: 1; Width: 1; Top: -1000; Left: -1000 ]
#
#This duplicate layout has no script triggers or conditional
#formatting and so speeds up the script steps.
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
#
Set Variable [ $$stopRecordLoad ]
#
#First find all the issues in this category.
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
#
#
#Sort them to trigger the calcuation of their
#total time.
Sort Records [ Specified Sort Order: issue::_keyCategory; ascending ]
[ Restore; No dialog ]
#
Go to Record/Request/Page
[ First ]
Set Variable [ $category; Value:issue::_keyCategory ]
Set Field [ issueCategory::issueTotalTime; GetSummary ( issue::timeSummary ; issue::_keyCategory ) ]
Loop
If [ $category ≠ issue::_keyCategory ]
Set Field [ issueCategory::issueTotalTime; GetSummary ( issue::timeSummary ; issue::_keyCategory ) ]
Set Variable [ $category; Value:issue::_keyCategory ]
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#
#
#
#Add up total time for all actions with this category tag.
Go to Layout [ “calcDayTable” (day1) ]
Enter Find Mode [ ]
Set Field [ day1::_keyBrainstate; $$logbrainstate ]
Perform Find [ ]
Go to Record/Request/Page
[ First ]
Loop
Set Variable [ $totalTime; Value:$time + day1::swTotalActivity ]
Set Variable [ $time; Value:$totalTime ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
Close Window [ Current Window ]
Set Field [ brainstate::totalTimeLogged; $totalTime ]
Sort Records [ Specified Sort Order: issue::order; based on value list: “1-99”
group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
Set Field [ reference::tagCatSort; "group" ]
#
#
January 3, ଘ౮28 20:25:38 ActionLog.fp7 - updateTimerTotalTimeInTagWindow -1-
