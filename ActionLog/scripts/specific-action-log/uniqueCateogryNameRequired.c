specific action log: uniqueTagNameRequired (NAME CHANGE)
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
Set Variable [ $recordNumber; Value:Get ( RecordNumber ) ]
#
#Make a key to later in script loop
#to the correct portal row.
Set Variable [ $key; Value:category::_LockList ]
#
#If the user left the field blank...
If [ category::text = "" ]
Show Custom Dialog [ Message: "All tag names must be unique, and must not be blank."; Buttons: “OK” ]
#
#Go to the blank field and fill it in with a unique
#name.
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $key = category::_LockList ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Set Field [ category::text; $key & category::_LockList ]
Exit Script [ ]
End If
#
#Determine if user used a spelling already in use.
Go to Record/Request/Page
[ First ]
#
Loop
#If the user used a spelling alread in use ...
If [ $name =category::text and category::_LockList ≠ $key ]
Show Custom Dialog [ Message: "Each category in this list must have a unique name."; Buttons: “OK” ]
#
#Make name unique.
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $key = category::_LockList ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
Set Field [ category::text; category::text & " " & $key ]
Exit Script [ ]
End If
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
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
December 6, ଘ౮27 21:27:32 ActionLog.fp7 - uniqueTagNameRequired (NAME CHANGE) -1-
