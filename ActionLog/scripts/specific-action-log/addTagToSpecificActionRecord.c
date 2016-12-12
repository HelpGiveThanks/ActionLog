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
Set Variable [ $$group; Value:SPAGroupTag::_LockSpecificAction ]
Go to Field [ ]
Refresh Window
#
#Give key to current specific action.
Select Window [ Name: "Specific Action"; Current file ]
#
#If there are no SPAs then exit this script.
If [ Get (FoundCount) = 0 ]
Select Window [ Name: "Tag"; Current file ]
Set Variable [ $$group ]
Refresh Window
Exit Script [ ]
End If
#
#Set variables for next part of script.
Set Variable [ $categoryOLD; Value:specificAction::oldGroupkey ]
Set Field [ specificAction::_keyGroup; $$group ]
Set Field [ specificAction::dateModified; Get ( CurrentTimeStamp ) ]
Commit Records/Requests
[ Skip data entry validation; No dialog ]
#
#If user selected the same category that was already
#selected then stop this script.
If [ specificAction::_keyGroup = specificAction::oldGroupkey and $$stopSubtotal = "" ]
Go to Field [ ]
Exit Script [ ]
End If
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
Set Field [ specificAction::sortTime; SPAGroupTag 2::text ]
#
#Prevent loading of record when new window
#is opened.
Set Variable [ $$stopRecordLoad; Value:1 ]
#
#Open a new window so these next steps can
#be done without disturbing the current view
#and scroll position of the issue window.
New Window [ Name: "temp"; Height: 1; Width: 1; Top: -10000; Left: -10000 ]
// New Window [ Name: "temp" ]
#
#This duplicate layout has no script triggers or
#conditional formatting and so speeds up the
#script steps.
Go to Layout [ “SpecificActionTable” (specificAction) ]
#
#Turn back on record loading script.
Set Variable [ $$stopRecordLoad ]
#
#Add up total time for group user just put the
#specific action record into.
#
#First find all the SPAs in its new group.
Enter Find Mode [ ]
Set Field [ specificAction::_keyTimer; $$logBrainstate ]
Set Field [ specificAction::_keyGroup; $$group ]
Set Field [ specificAction::lock; "issue" ]
Perform Find [ ]
#
#Sort them to trigger the calcuation of their
#total time.
Sort Records [ Specified Sort Order: specificAction::_keyGroup; ascending ]
[ Restore; No dialog ]
#
#Input new group's new total.
Set Field [ SPAGroupTag 2::SPATotalTime; GetSummary ( specificAction::timeSummary ; specificAction::_keyGroup ) ]
#
#Add up total time for group this SPA record
#was in before being moved to its new group.
#
#First find all the SPAs in its old group.
Enter Find Mode [ ]
Set Field [ specificAction::_keyTimer; $$logBrainstate ]
Set Field [ specificAction::_keyGroup; $categoryOLD ]
Set Field [ specificAction::lock; "issue" ]
Perform Find [ ]
#
#Sort them to trigger the calcuation of their
#total time.
Sort Records [ Specified Sort Order: specificAction::_keyGroup; ascending ]
[ Restore; No dialog ]
#
#Input old group's new total.
Set Field [ SPAGroupTag 2::SPATotalTime; GetSummary ( specificAction::timeSummary ; specificAction::_keyGroup ) ]
#
#
Close Window [ Name: "temp"; Current file ]
#
Sort Records [ Specified Sort Order: timer::description; ascending
SPAStatus::order; ascending
SPAStatus::text; ascending
SPAGroupTag 2::order; ascending
specificAction::timeTotalSummaryByGroup; ascending
specificAction::order; based on value list: “__-99”
specificAction::text; ascending ]
[ Restore; No dialog ]
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
// Exit Loop If [ specificAction::_LockSpecificAction = $currentRecord ]
// Go to Record/Request/Page
[ Next; Exit after last ]
// End Loop
Scroll Window
[ Home ]
Sort Records [ Specified Sort Order: timer::description; ascending
SPAStatus::order; based on value list: “__-99”
SPAStatus::text; ascending
SPAGroupTag 2::order; ascending
SPAGroupTag 2::text; ascending
specificAction::sortTime; ascending
specificAction::order; based on value list: “1-99”
specificAction::text; ascending ]
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
Set Field [ specificAction::oldGroupkey; $$group ]
#
Select Window [ Name: "Tag"; Current file ]
December 10, ଘ౮28 23:19:55 ActionLog.fp7 - addTagToSpecificActionRecord -1-
