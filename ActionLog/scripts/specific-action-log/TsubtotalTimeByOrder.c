specific action log: TsubtotalTimeByOrder
#
#If user selected the same category that was already
#selected then stop this script.
If [ issue::_keyCategory = issue::oldCategorykey and $$stopSubtotal = "" ]
Go to Field [ ]
Exit Script [ ]
End If
Set Variable [ $$stopSubtotal ]
#
#Set the old category key variable for use later
#in this script finding all the issue records that
#still belong to this record's former category.
Set Variable [ $OLDcategoryKey; Value:issue::oldCategorykey ]
#
#Prevent windows from ﬂashing and script from slowing
#by stopping strobe effect caused by going back and
#forth from each window upon loading each records
#information throughout the script, rather than just
#at the end.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
Go to Field [ ]
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
#In the focus in the text field, remove it.
Go to Field [ ]
#
#Open a new window so these next steps can
#be done without disturbing the current view
#and scroll position of the issue window.
New Window [ Name: "temp" ]
#
#This duplicate layout has no script triggers or conditional
#formatting and so speeds up the script steps.
Go to Layout [ “IssuesLayoutForScripts” (issue) ]
#
January 6, 平成26 11:20:54 ActionLog.fp7 - TsubtotalTimeByOrder -1-specific action log: TsubtotalTimeByOrder
#Add up total time for category the issue is now in.
#
#First find all the issues in this category.
Set Variable [ $categoryKey; Value:issue::_keyCategory ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $categoryKey ]
Perform Find [ ]
#
#Sort them to trigger the calcuation of their
#total time.
Sort Records [ Specified Sort Order: issue::sortTime; ascending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
#Go to each record including the newly recatorgized
# and update thier total cateogry time.
#
Loop
Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#
#
#Add up total time for category it was in.
#
#First find all the issues still part of the category
#it was in, if any.
Allow User Abort [ Off ]
Set Error Capture [ On ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $OLDcategoryKey ]
Perform Find [ ]
#
#If records remain in this category then continue
#reassigning updated total time to member records.
If [ Get (LastError) ≠ 401 ]
#
#Sort them to trigger the calcuation of their
#total time.
Sort Records [ Specified Sort Order: issue::sortTime; ascending ]
[ Restore; No dialog ]
#
#Go to each record including the newly recatorgized
# and update thier total cateogry time.
Go to Record/Request/Page
[ First ]
Loop
Set Field [ issue::timeTotalSumByCat; issue::timeTotalSummaryByCategory ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
End If
#
#
#
#Disabled the next chunk after deciding it was
January 6, 平成26 11:20:54 ActionLog.fp7 - TsubtotalTimeByOrder -2-specific action log: TsubtotalTimeByOrder
#better to use filemaker's subtotal calc rather
#doing it with this script chunk whose benefit
#was subtotaling items in a category even when
#items where divided by status. Filemaker's
#subtotal calc subtotals at the status and category
#breaks (essentially all breaks caused by a sort)
#but I decided to show issue the time by status
#and category too, so that is why this script chunk
#is now disabled. The other reason was that it
#bogged down the system taking a long time to run.
// #To reset all the category subtotal times, first find
// #and sort all this issues records.
// Set Variable [ $brainstateIssues; Value:issue::_keyBrainstate ]
// Enter Find Mode [ ]
// Set Field [ issue::_keyBrainstate; $brainstateIssues ]
// Perform Find [ ]
// Sort Records [ Specified Sort Order: brainstate::description; ascending
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issue::timeTotalSummaryByCategory; ascending
issue::order; based on value list: “__-99”
issue::text; ascending ]
[ Restore; No dialog ]
// Go to Record/Request/Page
[ First ]
// #
// #
// #AddUp total time showing for this subset of
// #a cateogory broken up into subsets by different
// #statuses, like the subset of some category's
// #record that are pending, or completed, etc.
// Loop
// Set Variable [ $category; Value:issue::_keyCategory ]
// Set Variable [ $status; Value:issue::_keyStatus ]
// Set Variable [ $recordNumber; Value:Get (RecordNumber) ]
// Set Variable [ $subsetTotal ]
// Set Variable [ $oldTotal ]
// #
// Loop
// Set Variable [ $subsetTotal; Value:issue::issueTotalTime + $oldTotal ]
// Set Variable [ $oldTotal; Value:$subsetTotal ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// Exit Loop If [ issue::_keyCategory ≠ $category
//This next step I thought could happen, but then realized it can nevery happen
//or
//issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
// End Loop
// #
// #Return the first record in this subset and give it
// #the subset total, then give the subtotal to all
// #records in this subset.
// Go to Record/Request/Page [ $recordNumber ]
[ No dialog ]
// #
// Loop
// Set Field [ issue::timeTotalSumByCatSortedByStatus; $subsetTotal ]
// Go to Record/Request/Page
[ Next; Exit after last ]
January 6, 平成26 11:20:54 ActionLog.fp7 - TsubtotalTimeByOrder -3-specific action log: TsubtotalTimeByOrder
// Exit Loop If [ issue::_keyCategory ≠ $category
//This next step I thought could happen, but then realized it can nevery happen
//or
//issue::_keyCategory = $category and issue::_keyStatus ≠ $status ]
// End Loop
// #
// Exit Loop If [ Get (LastError) = 101 ]
// End Loop
#
#
Close Window [ Name: "temp"; Current file ]
#
#
#Set make the old and current category keys
#identical, so system will will be able to update
#the time in this issue records current category
#if the user decided to reassign it to a different
#category.
Set Field [ issue::oldCategorykey; issue::_keyCategory ]
#
#In order to show the newly updapted time the
#system must resort the records. This takes
Set Variable [ $currentRecord; Value:issue::_LockList ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issue::order; based on value list: “__-99”
issueStatus::order; ascending
issueStatus::text; ascending
issueCategory::order; ascending
issue::timeTotalSummaryByCategory; ascending
issue::text; ascending ]
[ Restore; No dialog ]
// Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
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
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ issue::_LockList = $currentRecord ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Scroll Window
[ Home ]
Sort Records [ Specified Sort Order: brainstate::description; ascending
issue::order; based on value list: “1-99”
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::text; ascending ]
[ Restore; No dialog ]
January 6, 平成26 11:20:54 ActionLog.fp7 - TsubtotalTimeByOrder -4-specific action log: TsubtotalTimeByOrder
Sort Records [ Specified Sort Order: brainstate::description; ascending
issue::order; based on value list: “1-99”
issueStatus::order; based on value list: “__-99”
issueStatus::text; ascending
issueCategory::order; ascending
issue::sortTime; ascending
issue::text; ascending ]
[ Restore; No dialog ]
// Sort Records [ ]
[ No dialog ]
Scroll Window
[ To Selection ]
// Refresh Window
Set Variable [ $$stopRecordLoad ]
#
// #The halt script is neccessary in case the user
// #clicks somewhere other than the in the pulldown
// #menu. This halt script stops the pause script
// #that is currently in play.
// Halt Script
January 6, 平成26 11:20:54 ActionLog.fp7 - TsubtotalTimeByOrder -5-
