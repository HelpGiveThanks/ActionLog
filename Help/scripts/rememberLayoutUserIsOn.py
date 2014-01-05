rememberLayoutUserIsOn
Set Variable [ $$layout; Value:Get (LayoutName) ]
If [ LeftValues ( tutorial::layoutName ; 1 ) ? Get (LayoutName) & ? ]
Set Variable [ $name; Value:tutorial::layoutName ]
Set Field [ tutorial::layoutName; Get (LayoutName) & ? & $name ]
End If
January 4, ??26 19:14:45 help.fp7 - rememberLayoutUserIsOn -1-