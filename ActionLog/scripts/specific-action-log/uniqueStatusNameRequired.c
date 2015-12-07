specific action log: uniqueStatusNameRequired
#
#Capture text, remove spaces, and then recapture
#the text to prevent user from creating a group
#with spaces that would put it above the 10 space
#status assigned to new issues to keep new issues
#sorted to the top of the list of issues in the isssues
#log window.
Set Variable [ $name; Value:status::text ]
Set Field [ status::text; Trim ( $name ) ]
Set Variable [ $name; Value:status::text ]
#
#Make a key to later in script loop
#to the correct portal row.
Set Variable [ $key; Value:status::_LockList ]
#
#If the user left the field blank...
If [ status::text = "" ]
Show Custom Dialog [ Message: "All status names must be unique. Blanks are not allowed."; Buttons: “OK” ]
#
#Go to the blank field and fill it in with a unique
#name.
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $key = status::_LockList ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Set Field [ status::text; "status" & status::_LockList ]
Exit Script [ ]
End If
#
#Determine if user used a spelling already in use.
Go to Record/Request/Page
[ First ]
#
Loop
#If the user used a spelling alread in use ...
If [ $name =status::text and status::_LockList ≠ $key ]
Show Custom Dialog [ Message: "Each status in this list must have a unique name."; Buttons: “OK” ]
#
#Make name unique.
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $key = status::_LockList ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Set Field [ status::text; $name & status::_LockList ]
Exit Script [ ]
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
#
#
Scroll Window
[ Home ]
#Go to current record.
Go to Record/Request/Page
[ First ]
Loop
#
Exit Loop If [ $key = category::_LockList ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
December 6, ଘ౮27 21:29:33 ActionLog.fp7 - uniqueStatusNameRequired -1-
