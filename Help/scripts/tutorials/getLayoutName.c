tutorial: getLayoutName
Select Window [ Name: "Help"; Current ﬁle ]
Set Variable [ $$layout; Value:Get(LayoutName) ]
Select Window [ Name: "Tutorial"; Current ﬁle ]
Set Field [ tutorial::klayout; $$layout ]
