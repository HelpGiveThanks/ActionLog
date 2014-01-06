speciﬁc action log: uniqueCateogryNameRequired
#
#Capture text, remove spaces, and then recapture
#the text to prevent user from creating a group
#with spaces that would put it above the 10 space
#group assigned to new issues to keep new issues
#sorted to the top of the list of issues in the isssues
#log window.
Set Variable [ $name; Value:category::text ]
Set Field [ category::text; Trim ( $name ) ]
Set Variable [ $name; Value:category::text ]
Set Variable [ $portalRow; Value:Get ( PortalRowNumber ) ]
#
#Make a key to later in script loop
#to the correct portal row.
Set Variable [ $key; Value:category::_LockList ]
#
#If the user left the ﬁeld blank...
If [ category::text = "" ]
Show Custom Dialog [ Message: "All group names must be unique, and must not be blank."; Buttons: “OK” ]
#
#Go to the blank ﬁeld and ﬁll it in with a unique
#number.
Go to Object [ Object Name: "group" ]
#
Go to Portal Row
[ Select; First ]
Loop
Exit Loop If [ $key = category::_LockList ]
Go to Portal Row
[ Select; Next ]
End Loop
Set Field [ category::text; $key & Random ]
Exit Script [ ]
End If
#
#Determine if user used a spelling already in use.
Go to Portal Row
[ Select; First ]
#
Loop
#If the user used a spelling alread in use ...
If [ $name =category::text and category::_LockList ≠ $key ]
Show Custom Dialog [ Message: "Each category in this list must have a unique name."; Buttons: “OK” ]
#
#Go to the blank ﬁeld and ﬁll it in with a unique
#number.
Go to Object [ Object Name: "group" ]
#
Go to Portal Row
[ Select; First ]
Loop
Exit Loop If [ $key = category::_LockList ]
Go to Portal Row
[ Select; Next ]
End Loop
Set Field [ category::text; category::text & " " & $key ]
Exit Script [ ]
End If
January 6, 平成26 11:17:01 ActionLog.fp7 - uniqueCateogryNameRequired -1-speciﬁc action log: uniqueCateogryNameRequired
Go to Portal Row
[ Select; Next; Exit after last ]
End Loop
#
Scroll Window
[ Home ]
#Go to current record.
Go to Object [ Object Name: "group" ]
Go to Portal Row
[ Select; First ]
Loop
#
Exit Loop If [ $key = category::_LockList ]
Go to Portal Row
[ Select; Next; Exit after last ]
End Loop
January 6, 平成26 11:17:01 ActionLog.fp7 - uniqueCateogryNameRequired -2-
