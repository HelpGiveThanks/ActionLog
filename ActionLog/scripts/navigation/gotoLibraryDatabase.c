navigation: gotoLibraryDatabase
#
#
#Stop script if user is process of picking a specific action group.
If [ $$pick = 1 ]
Show Custom Dialog [ Message: "Pick a specific-action tag or click the cancel button in the Tag window. After you do this you can go to
the library. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Select the current library windows if open and selected.
Select Window [ Name: "Tag Menus" ]
Select Window [ Name: "Learn" ]
Select Window [ Name: "Setup" ]
Select Window [ Name: "Report" ]
Select Window [ Name: "References" ]
Select Window [ Name: MemorySwitch::currentLibraryMainWIndow ]
#
#If no library is open, then open the last library used.
If [ Get (LastError) = 112 and MemorySwitch::currentLibraryPath ≠ "" ]
Open URL [ Case ( Get ( SystemPlatform ) = - 2 ;
Substitute (MemorySwitch::currentLibraryPath ; " " ; "%20" ) ;
Substitute ( Substitute ( MemorySwitch::currentLibraryPath ; "file:/" ; "file://" ) ; " " ; "%20" ) ) ]
[ No dialog ]
#
#If the path stored for the selected library failed to open
#the library, then that library is no longer there or its
#name has been changed, so inform the user of their
#options.
If [ Get (LastError) = 5 ]
Show Custom Dialog [ Message: "Last library used cannot be found as it must have been renamed, moved, or deleted. Find and
open it manually or click the allsolutions button to select another library."; Buttons: “OK” ]
End If
#
#If their are no libraries in the system let the user
#know how to add new ones.
Else If [ Get (LastError) = 112 and MemorySwitch::currentLibraryPath = "" ]
Show Custom Dialog [ Message: "There is no library file in memory. Click on a library file manually and it will be added to memory and
opened the next time you click the library button."; Buttons: “OK” ]
End If
#
December 6, ଘ౮27 20:21:53 ActionLog.fp7 - gotoLibraryDatabase -1-
