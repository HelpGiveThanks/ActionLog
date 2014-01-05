rememberLayoutUserIsOn
Set Variable [ $$layout; Value:Get (LayoutName) ]
If [ LeftValues ( tutorial::layoutName ; 1 ) ≠ Get (LayoutName) & ¶ ]
Set Variable [ $name; Value:tutorial::layoutName ]
Set Field [ tutorial::layoutName; Get (LayoutName) & ¶ & $name ]
End If
