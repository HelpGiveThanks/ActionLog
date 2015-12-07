specific action log: newTag (NAME CHANGE)
#
#When a new record is created the text field is blank.
#If the user clicks the new button before giving
#their current new record a name these steps will
#name it for them.
If [ category::text = "" and Get ( LayoutTableName ) ≠ "Status" ]
Set Field [ category::text; "tag" & category::_LockList ]
Else If [ status::text = "" and Get ( LayoutTableName ) = "Status" ]
Set Field [ status::text; "status" & status::_LockList ]
End If
#
#Create a new tag record and assign it the group
#the user is in right now.
Set Variable [ $group; Value:category::_keyCategory ]
#
Set Variable [ $$TagNameRequired; Value:1 ]
#
New Record/Request
If [ Get ( LayoutTableName ) ≠ "Status" ]
Set Field [ category::lock; "location" ]
Set Field [ category::_keyBrainstate; $$logBrainstate ]
Set Field [ category::_keyCategory; $group ]
Else If [ Get ( LayoutTableName ) = "Status" ]
Set Field [ status::lock; "status" ]
End If
#
#Sort only if you want to bring new tag to the top
#of the group list of tags. I found it to be less
#disruptive if the tags don't sort.
// Sort Records [ Specified Sort Order: group::text; ascending
category::text; ascending ]
[ Restore; No dialog ]
#
#Make it easy for user to type new name for tag.
If [ category::text = "" and Get ( LayoutTableName ) ≠ "Status" ]
Go to Field [ category::text ]
Else
Go to Field [ status::text ]
End If
#
#Turn off variable set at start of script.
Set Variable [ $$TagNameRequired ]
#
December 6, ଘ౮27 21:39:36 ActionLog.fp7 - newTag (NAME CHANGE) -1-
