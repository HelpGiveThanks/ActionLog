specific action log: newTagGroup
#
#When a new record is created the text field is blank.
#If the user clicks the new button before giving
#their current new record a name these steps will
#name it for them.
If [ category::text = "" ]
Set Field [ category::text; "tag" & category::_LockList ]
End If
Set Variable [ $$TagNameRequired; Value:1 ]
#
#Create new group record.
New Record/Request
Set Field [ category::lock; "group" ]
Set Field [ category::_keyBrainstate; $$logBrainstate ]
Set Field [ category::text; "group" & category::_LockList ]
Set Variable [ $group; Value:category::_LockList ]
#
#Remove it so it only shows up as a header and
#and not as both a header and a tag.
Omit Record
#
#Create a new tag record and assign it to this new
#group so the group will show up as its header.
New Record/Request
Set Field [ category::lock; "location" ]
Set Field [ category::_keyBrainstate; $$logBrainstate ]
Set Field [ category::_keyCategory; $group ]
#
#Sort records so new group header will show up.
Sort Records [ Specified Sort Order: group::text; ascending
category::text; ascending ]
[ Restore; No dialog ]
Go to Field [ category::text ]
#
#Turn off variable set at start of script.
Set Variable [ $$TagNameRequired ]
#
December 6, ଘ౮27 22:03:39 ActionLog.fp7 - newTagGroup -1-
