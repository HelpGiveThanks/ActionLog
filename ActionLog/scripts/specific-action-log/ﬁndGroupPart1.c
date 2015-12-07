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
Set Field [ reference::tagCatSort; "group" ]
Sort Records [ Specified Sort Order: group::text; ascending
category::sortTime; ascending
category::text; ascending ]
[ Restore; No dialog ]
Scroll Window
[ Home ]
#
December 6, ଘ౮27 21:34:47 ActionLog.fp7 - findGroupPart1 -1-
