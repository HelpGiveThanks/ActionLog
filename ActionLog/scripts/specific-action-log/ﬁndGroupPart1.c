specific action log: findGroupPart1
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action tag or click the cancel button in the Tag window. After you do this you
can find specific-actions tagged with specific tags."; Buttons: “OK” ]
Exit Script [ ]
End If
#
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#Go to the find layout for category tags.
Go to Layout [ “IssuesAndObservationsFIND” (category) ]
Scroll Window
[ Home ]
Set Variable [ $$found ]
#
#Clear all specific actions records.
Select Window [ Name: "Specific Action"; Current file ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; "nothing" ]
Perform Find [ ]
#
#Return to tag window.
Select Window [ Name: "Tag"; Current file ]
Go to Layout [ “IssuesAndObservationsFIND” (category) ]
// If [ reference::tagCatSort = "abc" ]
// Sort Records [ Specified Sort Order: category::text; ascending
category::sortTime; ascending ]
[ Restore; No dialog ]
// Else
// Sort Records [ Specified Sort Order: group::order; based on value list: “1-99”
group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
// End If
Scroll Window
[ Home ]
#
January 3, ଘ౮28 20:17:29 ActionLog.fp7 - findGroupPart1 -1-
