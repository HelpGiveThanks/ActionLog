total: showLinkedRecords
#PURPOSE on the normal record view layouts the user is shown a total linkID number underlined to indicated that it is a button and a view
button for all total and grand total records. These two buttons -- linkID number and view -- activate this script whose purpose is to 1)
navigate from the current layout to the totalview layout, and 2) ﬁnd and display the linked records. For example, the user may have several
leg exercises they do each tracked by separate record and all of them totaled in one leg exercise total record. Clicking on the view button
for the total record or the linkID number of this total record displayed next all the leg exercise records will activitate this script with result
being the display of just these leg exercise records and the leg exercise total record. The user could take advantage of this feature to hide
the leg exercise records displaying only the total record and when they wish to record leg exercise time, the user could click the view button
see all the associated records, update them and then return to the main screen in which once again only the total record (now updated with
new time) would be shown (along with all the other records the user wants to see.
#
#
#
#1 check to insure the record is linked and if not stop the script. (This is neccessary because ﬁlemaker allows the link button that activitates this
script to be hidden but not deactivited, and it should not run if there are no records for it to ﬁnd and display.)
If [ brainstate::groupID = "" and brainstate::groupOfGroupID = "" ]
Halt Script
#
#2 if the record is part of total (or is the total record) ﬁnd and display all linked records and set the users choosen day ﬁeld.
Else If [ brainstate::groupID ≠ "" ]
Set Variable [ $mergeID; Value:brainstate::groupID ]
Set Field [ steward::chosenDayTotal; brainstate::day1 ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $mergeID ]
Set Field [ brainstate::sortRetired; "=" ]
Perform Find [ ]
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
Go to Layout [ “TotalMainiPhone” (brainstate) ]
Else If [ Get ( SystemPlatform ) ≠ 3 or steward::iPhoneLayout = "" ]
Go to Layout [ “TotalMain” (brainstate) ]
End If
#END NOT TESTED
#set the retired status to r (assume the user always only wants to show current set of records minus the ones they have retired)
Set Field [ steward::retiredStatus; "r" ]
#future developement: omit retired records if the retired button is on
// Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
// Sort Records [ Speciﬁed Sort Order: brainstate::groupType; based on value list: “MergeSort”
brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
#save the recordnumber which will now be erased by the next script
Set Variable [ $$recordnumber2; Value:$$recordnumber ]
Perform Script [ “DaySelectSortThenSort” ]
Halt Script
#
#3 if the record is part of a grand total (or is the grand total record) ﬁnd and display all linked records.
Else If [ brainstate::groupOfGroupID ≠ "" ]
Set Variable [ $mergeGrandID; Value:brainstate::groupOfGroupID ]
Enter Find Mode [ ]
Set Field [ brainstate::groupOfGroupID; $mergeGrandID ]
Perform Find [ ]
#future developement: omit retired records if the retired button is on
// Constrain Found Set [ Speciﬁed Find Requests: Omit Records; Criteria: brainstate::sortRetired: “r” ]
[ Restore ]
Go to Layout [ “GrandTotal” (brainstate) ]
// Sort Records [ Speciﬁed Sort Order: brainstate::groupType; based on value list: “MergeSort”
brainstate::_lockBrainstateID; descending ]
[ Restore; No dialog ]
Perform Script [ “DaySelectSortThenSort” ]
Halt Script
End If
January 5, 平成26 13:22:05 ActionLog.fp7 - showLinkedRecords -1-
