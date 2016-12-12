triggered scripts: moveTagStep2
#PURPOSE completes tag move to a new group.
#
#If user selected the tag's current group, exit.
If [ SPAGroupTag::_keyGroup = $$groupKey ]
Go to Field [ ]
Exit Script [ ]
End If
#
#If there is only one group, exit script.
If [ ValueCount ( ValueListItems ( Get ( FileName ) ; "tagGroup" ) ) = 1 ]
Go to Field [ ]
Exit Script [ ]
End If
#
#Check if this tag is the last tag in its group.
Set Variable [ $$stopMoveStep1; Value:1 ]
New Window [ ]
Go to Layout [ “category data” (SPAGroupTag) ]
Enter Find Mode [ ]
Set Field [ SPAGroupTag::_keyGroup; $$groupKey ]
Perform Find [ ]
Set Variable [ $tagsingroup; Value:Get (FoundCount) ]
Close Window [ Current Window ]
Set Variable [ $$stopMoveStep1 ]
#
#If it is the last tag in the group inform the user
#and make sure they still want to delete tag and group.
If [ $tagsingroup = 1 ]
#
#Set variables for conditional formatting and
#message to users.
Set Variable [ $groupKey; Value:$$groupKey ]
Set Variable [ $groupName; Value:$$groupName ]
Set Variable [ $newlySelectedGroup; Value:SPAGroupTag::_keyGroup ]
Set Variable [ $tagBeingMoved; Value:SPAGroupTag::_LockSpecificAction ]
Set Field [ SPAGroupTag::_keyGroup; $$groupKey ]
Refresh Window
#
#Make sure user wants to continue moving
#after learning its group will be deleted.
Show Custom Dialog [ Message: "The tag group — " & $$groupName & " — will be deleted because tag " & SPAGroupTag::text
& " is the last tag in it. If you want to keep this group then cancel, and create a new tag before moving the selected tag.";
Buttons: “continue”, “cancel” ]
#
#If they decide to cancel the move,
#then cancel it.
If [ Get ( LastMessageChoice ) = 2 ]
Set Variable [ $groupName ]
Set Variable [ $tagBeingMoved ]
Go to Field [ ]
Refresh Window
Exit Script [ ]
End If
#
#If they decide to continue the move,
#then delete its old and now ophaned
#group.
New Window [ ]
Go to Layout [ “category data” (SPAGroupTag) ]
Enter Find Mode [ ]
Set Field [ SPAGroupTag::_LockSpecificAction; $$groupKey ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Close Window [ Current Window ]
Set Field [ SPAGroupTag::_keyGroup; $newlySelectedGroup ]
End If
#
#Remove focus from move field in menu area.
Go to Field [ ]
Sort Records [ Specified Sort Order: TagGroup::order; based on value list: “1-99”
TagGroup::text; ascending
SPAGroupTag::sortTime; ascending
SPAGroupTag::text; ascending ]
[ Restore; No dialog ]
#
#Load tag's new group variables.
Set Variable [ $$groupKey; Value:SPAGroupTag::_keyGroup ]
Set Variable [ $$groupName; Value:TagGroup::text ]
Go to Field [ ]
#
December 10, ଘ౮28 20:58:18 ActionLog.fp7 - moveTagStep2 -1-
