specific action log: addTagToSpecificActionRecord
#
#
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#
If [ $$pick = 1 ]
Perform Script [ “newActPart2” ]
Exit Script [ ]
End If
#
#Make key to fit this group's lock.
Set Variable [ $$group; Value:category::_LockList ]
Go to Field [ ]
Refresh Window
#
#Give key to current specific action.
Select Window [ Name: "Specific Action"; Current file ]
#
#
If [ Get (FoundCount) = 0 ]
Select Window [ Name: "Tag"; Current file ]
Set Variable [ $$group ]
Refresh Window
Exit Script [ ]
End If
#
#
Set Variable [ $categoryOLD; Value:issue::oldCategorykey ]
Set Field [ issue::_keyCategory; $$group ]
Commit Records/Requests
[ Skip data entry validation; No dialog ]
#
#
#If user selected the same category that was already
#selected then stop this script.
If [ issue::_keyCategory = issue::oldCategorykey and $$stopSubtotal = "" ]
Go to Field [ ]
Exit Script [ ]
End If
#
#
#
#
#This field is for sorting the records by category
#to get the subtotal of each categories time.
# (The subtotal calculation depends on this "break"
# field to know which set of records should be
# treated as a subset of the total records shown.)
#This sort must be done on a field in the table
#where the time is located: list table.
#The system is using the text field from the list
#table for the text of each issue. Another occurance
#of the list table is used to supply the categories
#which are located in a different list table record.
#This allows the system to use the list table for
#Text and for tags: category and issue tags.
#However, in order to sort on the text of the
#category a copy of the text must be made
#part of each list record shown as an issue
# (instead of being shown as a category or status)
#This next field holds the copy of the cateogry
#tag text for each list record holding issue data.
Set Field [ issue::sortTime; issueCategory::text ]
#
#
#
#
#Prevent windows from flashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Open a new window so these next steps can
#be done without disturbing the current view
#and scroll position of the issue window.
// New Window [ Name: "temp"; Height: 1; Width: 1; Top: -10000; Left: -10000 ]
New Window [ Name: "temp" ]
#
#This duplicate layout has no script triggers or conditional
#formatting and so speeds up the script steps.
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
#
Set Variable [ $$stopRecordLoad ]
#
#Add up total time for category the issue is now in.
#
// #First find all the issues in this category.
// Enter Find Mode [ ]
// Set Field [ issue::_keyBrainstate; $$logBrainstate ]
// Set Field [ issue::lock; "issue" ]
// Perform Find [ ]
#
#First find all the issues in this category.
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::_keyCategory; $$group ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
#
#Sort them to trigger the calcuation of their
#total time.
Sort Records [ Specified Sort Order: issue::_keyCategory; ascending ]
[ Restore; No dialog ]
#
#
Set Field [ issueCategory::issueTotalTime; GetSummary ( issue::timeSummary ; issue::_keyCategory ) ]
#
#
#First find all the issues in this category.
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Set Field [ issue::_keyCategory; $categoryOLD ]
Set Field [ issue::lock; "issue" ]
Perform Find [ ]
#
#
#Sort them to trigger the calcuation of their
#total time.
Sort Records [ Specified Sort Order: issue::_keyCategory; ascending ]
[ Restore; No dialog ]
#
Set Field [ issueCategory::issueTotalTime; GetSummary ( issue::timeSummary ; issue::_keyCategory ) ]
#
#
// Go to Record/Request/Page
[ First ]
// Set Variable [ $category; Value:issue::_keyCategory ]
// Set Field [ issueCategory::issueTotalTime; GetSummary ( issue::timeSummary ; issue::_keyCategory ) ]
// Loop
// If [ $category ≠ issue::_keyCategory ]
// Set Field [ issueCategory::issueTotalTime; GetSummary ( issue::timeSummary ; issue::_keyCategory ) ]
// Set Variable [ $category; Value:issue::_keyCategory ]
// End If
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
#
#
Close Window [ Name: "temp"; Current file ]
#
// Set Variable [ $currentRecord; Value:issue::_LockList ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issue::timeTotalSummaryByCategory; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
// Go to Record/Request/Page
[ First ]
#
#In order to show the newly updapted time the
#The previous script step takes the
#the focus to the last record. To get the
#to the current record, and to show it not as
#as the top record, but if possible show
#all records above it, requires two sorts, and
#two scrolls. For some reason Filemaker will not
#scroll home (the top record) and then scroll
#down to the current record without a sort being
#between the sort steps.
// Go to Record/Request/Page
[ First ]
// Loop
// Exit Loop If [ issue::_LockList = $currentRecord ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
Scroll Window
[ Home ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issueCategory::text; ascending
issue::sortTime; ascending
issue::order; based on value list: “1-99”
issue::text; ascending ]
[ Restore; No dialog ]
#
Scroll Window
[ To Selection ]
#
#Set make the old and current category keys
#identical, so system will will be able to update
#the time in this issue records current category
#if the user decided to reassign it to a different
#category.
Set Field [ issue::oldCategorykey; $$group ]
#
Select Window [ Name: "Tag"; Current file ]
December 6, ଘ౮27 21:50:55 ActionLog.fp7 - addTagToSpecificActionRecord -1-
