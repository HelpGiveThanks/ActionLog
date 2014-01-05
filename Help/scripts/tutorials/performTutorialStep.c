tutorial: performTutorialStep
#
#
#
If [ $$stopScript = 1 ]
Exit Script [ ]
End If
#
If [ tutorial::layoutName = "" ]
Show Custom Dialog [ Message: "Select a tutorial to do."; Buttons: “OK” ]
Go to Field [ tutorial::layoutName ]
[ Select/perform ]
Exit Script [ ]
End If
#
#
Set Variable [ $$number; Value:Get (RecordNumber) ]
#
Set Variable [ $column; Value:tutorial::changeHelpObjectName ]
#
Set Variable [ $$layout; Value:tutorial::klayout ]
If [ tutorial::anchor ≠ "" ]
Set Variable [ $$anchor; Value:tutorial::anchor ]
Else
Set Variable [ $$anchor; Value:tutorial::helpNumber ]
End If
Set Variable [ $$helpNumber; Value:tutorial::helpNumber ]
Refresh Window
#
Select Window [ Name: "Help"; Current ﬁle ]
#
If [ Get (LayoutName) ≠ $$layout ]
Go to Layout [ $$layout ]
Refresh Window
End If
#
If [ $column ≠ "" ]
Set Field [ MemorySwitch::helpObjectName; $column ]
End If
#
// View As
[ View as Form ]
Go to Object [ Object Name: $$anchor ]
Go to Field [ ]
Refresh Window
// View As
[ View as List ]
// Go to Object [ Object Name: $$anchor ]
// Go to Field [ ]
#
#
Select Window [ Name: "Tutorial"; Current ﬁle ]
Go to Field [ ]
Scroll Window
[ To Selection ]
// Go to Field [ tutorial::InstructionView ]
#
#
