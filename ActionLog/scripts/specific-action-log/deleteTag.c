specific action log: deleteTag
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action group. After you do this you can delete tags. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Not sure about this step, but would guess
#that if the record is not a tag then don't delete it.
If [ category::_LockList = "" ]
Go to Field [ ]
Exit Script [ ]
End If
#
#Capture essential information.
Go to Field [ ]
Set Variable [ $group; Value:category::_keyCategory ]
Set Variable [ $delete; Value:category::_LockList ]
Set Variable [ $name; Value:category::text ]
#
#See if any specific actions are tagged with this tag.
New Window [ ]
Go to Layout [ “IssuesAndObservations Copy” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_keyCategory; $delete ]
Perform Find [ ]
Set Variable [ $error; Value:Get (LastError) ]
Set Variable [ $foundcount; Value:Get ( FoundCount ) ]
#
#If it tags nothing, then check if it is the last tag
#in its group.
If [ $foundcount = 0 ]
Go to Layout [ “category data” (category) ]
Enter Find Mode [ ]
Set Field [ category::_keyCategory; $group ]
Perform Find [ ]
Set Variable [ $tagsingroup; Value:Get (FoundCount) ]
End If
#
#Close the find window.
Close Window [ Current Window ]
#
#If specific items are found tagged with tag
#inform user of how many there are and exit script.
If [ $error ≠ 401 ]
Set Variable [ $delete ]
Show Custom Dialog [ Message: Case ( $foundcount ≠ 1 ;
"'" & $name & "'" & " can be deleted once the " & $foundcount & " specific issues tagged with it are tagged with a different tag. To find
these " & $foundcount & ", click the 'find' button (above) and then this tag's button." ;
"'" & $name & "'" & " can be deleted once the 1 specific issue tagged with it is tagged with a different tag. To find it, click the 'find'
button above and then this tag's button." ); Buttons: “OK” ]
Exit Script [ ]
End If
#
December 6, ଘ౮27 21:17:11 ActionLog.fp7 - deleteTag -1-
specific action log: deleteTag
#If none are found then ask user if they really want
#to delete this tag.
Refresh Window
Show Custom Dialog [ Title: "!"; Message: "Delete " & $name & "?"; Buttons: “Cancel”, “Delete” ]
#
#If the user says yes, first make sure the record
#is not the last record in a group. If it is and
#the system deleted the record without deleting
#the group too, this group would become
#an orphan as only categories that have records
#attached to them show up for the user to add
#more records uner them. So the group
#record must also be deleted if this is the last
#record under it.
If [ Get ( LastMessageChoice ) = 2 ]
#
#If it is the last tag in the group inform the user
#and make sure they still want to delete tag and group.
If [ $tagsingroup = 1 ]
Set Variable [ $groupName; Value:group::text ]
Refresh Window
Show Custom Dialog [ Message: "The tag group — " & $groupName & " — will also be deleted because tag " & $name & " is the last
tag in it."; Buttons: “OK”, “cancel” ]
#
#If they don't, then stop the script.
If [ Get ( LastMessageChoice ) = 2 ]
Set Variable [ $groupName ]
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
Exit Script [ ]
End If
#
#If they do the first find and delete the group.
New Window [ ]
Go to Layout [ “category data” (category) ]
Enter Find Mode [ ]
Set Field [ category::_LockList; $group ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Close Window [ Current Window ]
End If
#
#Delete the tag.
Delete Record/Request
[ No dialog ]
End If
#
#If the user clicks 'cancel' then clear the conditional
#formatting and exit.
Set Variable [ $delete ]
Go to Field [ ]
Refresh Window
December 6, ଘ౮27 21:17:11 ActionLog.fp7 - deleteTag -2-
