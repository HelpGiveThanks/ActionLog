specific action log: newTag
#
#When a new record is created the text field is blank.
#If the user clicks the new button before giving
#their current new record a name these steps will
#name it for them.
If [ SPAGroupTag::text = "" and Get ( LayoutTableName ) ≠ "Status" ]
Set Field [ SPAGroupTag::text; "tag" & SPAGroupTag::_LockSpecificAction ]
Else If [ status::text = "" and Get ( LayoutTableName ) = "Status" ]
Set Field [ status::text; "status" & status::_LockSpecificAction ]
End If
#
#Create a new tag record and assign it the group
#the user is in right now.
If [ Get ( FoundCount ) = 0 ]
Perform Script [ “newTagGroup” ]
Exit Script [ ]
Else
Set Variable [ $group; Value:SPAGroupTag::_keyGroup ]
End If
#
Set Variable [ $$TagNameRequired; Value:1 ]
#
New Record/Request
If [ Get ( LayoutTableName ) ≠ "Status" ]
Set Field [ SPAGroupTag::lock; "location" ]
Set Field [ SPAGroupTag::_keyTimer; $$logBrainstate ]
Set Field [ SPAGroupTag::_keyGroup; $group ]
Else If [ Get ( LayoutTableName ) = "Status" ]
Set Field [ status::lock; "status" ]
End If
#
#Sort only if you want to bring new tag to the top
#of the group list of tags. I found it to be less
#disruptive if the tags don't sort.
// Sort Records [ Specified Sort Order: TagGroup::text; ascending
SPAGroupTag::text; ascending ]
[ Restore; No dialog ]
#
#Make it easy for user to type new name for tag.
If [ SPAGroupTag::text = "" and Get ( LayoutTableName ) ≠ "Status" ]
Go to Field [ SPAGroupTag::text ]
Else
Go to Field [ status::text ]
End If
#
#Turn off variable set at start of script.
Set Variable [ $$TagNameRequired ]
#
December 10, ଘ౮28 23:14:32 ActionLog.fp7 - newTag -1-
