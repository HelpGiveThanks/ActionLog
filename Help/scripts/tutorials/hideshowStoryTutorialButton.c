tutorial: hideshowStoryTutorialButton
If [ $$story = "" ]
Set Variable [ $$story; Value:Case ($$anchor ≠ "" ; "" ; 1) ]
Refresh Window
Else
Set Variable [ $$story; Value:"" ]
Refresh Window
End If
