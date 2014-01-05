navigation: gotoLibraryDatabaseUsingGoButton
#
// Set Variable [ $path; Value:Get ( ActiveFieldContents ) ]
Set Variable [ $path; Value:MemorySwitch::path ]
#
Select Window [ Name: "Tag Menus" ]
#
#This step is required or else the main library window
#will remain hidden behind the timer window if open.
If [ MemorySwitch::currentLibraryPath = $path ]
Select Window [ Name: MemorySwitch::currentLibraryMainWIndow ]
End If
If [ MemorySwitch::currentLibraryPath ≠ $path or Get (LastError) = 112 ]
Close Window [ Name: "Tag Menus" ]
Close Window [ Name: "Setup" ]
Close Window [ Name: "Report" ]
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
If [ Get (LastError) = 5 ]
Go to Layout [ “libraryPath” (MemorySwitch) ]
Enter Find Mode [ ]
Set Field [ MemorySwitch::path; $path ]
Perform Find [ ]
Delete Record/Request
[ No dialog ]
Go to Layout [ original layout ]
End If
#
#Close other apps window if open after selecting an app.
If [ $$otherApps = 1 ]
Close Window [ Name: "Other Apps"; Current ﬁle ]
End If
January 5, 平成26 14:21:08 ActionLog.fp7 - gotoLibraryDatabaseUsingGoButton -1-
