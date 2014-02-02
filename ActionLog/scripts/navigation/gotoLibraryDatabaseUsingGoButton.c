navigation: gotoLibraryDatabaseUsingGoButton
#
#Because this portal is to external database it is
#essential to get this record's path info for use in
#other script steps.
Set Variable [ $path; Value:MemorySwitch::path ]
#
#If library path is blank (which should only happen if
#admin adds library manually with path), then delete
#this library name from the list.
If [ MemorySwitch::path = "" ]
Show Custom Dialog [ Message: "This library ﬁle cannot be found under the name " & MemorySwitch::name & ". It will be removed from
this list. You can add it back by double clicking on it in its current location."; Buttons: “OK” ]
#
#ISSUE: If you have a portal into a table that is more
#than one relationship away, and if that related table
#exists in an external ﬁle, then you cannot delete
#the portal row.
// Go to Portal Row [ $row ]
[ No dialog ]
// Delete Record/Request
[ No dialog ]
// Delete Portal Row
[ No dialog ]
#
Go to Layout [ “MemorySwitch” (MemorySwitch) ]
Show All Records
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $path = MemorySwitch::path ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ $path = MemorySwitch::path ]
Delete Record/Request
[ No dialog ]
End If
Go to Layout [ “users” (steward) ]
Exit Script [ ]
End If
#
#Select the current library windows if open and selected.
If [ MemorySwitch::currentLibraryPath = $path ]
Select Window [ Name: "Tag Menus" ]
Select Window [ Name: "Learn" ]
Select Window [ Name: "Setup" ]
Select Window [ Name: "Report" ]
Select Window [ Name: "References" ]
Select Window [ Name: MemorySwitch::currentLibraryMainWIndow ]
End If
#
#If the library selected is not open, then close the current
#library, which means closing all of its windows, and
#then open the selected library.
If [ MemorySwitch::currentLibraryPath ≠ $path or Get (LastError) = 112 ]
Close Window [ Name: "Tag Menus" ]
Close Window [ Name: "Setup" ]
Close Window [ Name: "Report" ]
February 1, 平成26 18:22:18 ActionLog.fp7 - gotoLibraryDatabaseUsingGoButton -1-navigation: gotoLibraryDatabaseUsingGoButton
Close Window [ Name: "Reference" ]
Close Window [ Name: "Recommendations" ]
Close Window [ Name: "Numbers" ]
Close Window [ Name: "Library Update" ]
Close Window [ Name: "import" ]
Close Window [ Name: "Test" ]
Close Window [ Name: "reorder" ]
Close Window [ Name: "delete tag" ]
Close Window [ Name: "Citation Note" ]
Close Window [ Name: "Preview" ]
Close Window [ Name: "Details" ]
Close Window [ Name: "" ]
Close Window [ Name: "Help" ]
Close Window [ Name: "Print/Copy" ]
Close Window [ Name: "Cover Page" ]
Close Window [ Name: "!" ]
Close Window [ Name: "Copy / Paste Evidence" ]
Close Window [ Name: "Day" ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (MemorySwitch::path ; " " ; "%20" ) ;
Substitute ( Substitute ( MemorySwitch::path ; "ﬁle:/" ; "ﬁle://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
End If
#
#If the path stored for the selected library failed to open
#the library, then that library is no longer there or its
#name has been changed, so delete it from the
#library list.
If [ Get (LastError) = 5 ]
Show Custom Dialog [ Message: "Selected library ﬁle cannot be found under the name " & MemorySwitch::name & ". It will be removed
from the library list. You can add it back by double clicking on it in its current location."; Buttons: “OK” ]
#
#ISSUE: If you have a portal into a table that is more
#than one relationship away, and if that related table
#exists in an external ﬁle, then you cannot delete
#the portal row.
// Go to Portal Row [ $row ]
[ No dialog ]
// Delete Record/Request
[ No dialog ]
// Delete Portal Row
[ No dialog ]
#
Go to Layout [ “MemorySwitch” (MemorySwitch) ]
Show All Records
Go to Record/Request/Page
[ First ]
Loop
Exit Loop If [ $path = MemorySwitch::path ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ $path = MemorySwitch::path ]
Delete Record/Request
[ No dialog ]
End If
Go to Layout [ “users” (steward) ]
Exit Script [ ]
February 1, 平成26 18:22:18 ActionLog.fp7 - gotoLibraryDatabaseUsingGoButton -2-navigation: gotoLibraryDatabaseUsingGoButton
End If
#
#Close other solutions window if open after selecting a library.
If [ $$otherApps = 1 ]
Close Window [ Name: "Other Solutions"; Current ﬁle ]
Set Variable [ $$otherApps ]
End If
#
February 1, 平成26 18:22:18 ActionLog.fp7 - gotoLibraryDatabaseUsingGoButton -3-