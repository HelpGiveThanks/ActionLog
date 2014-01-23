tutorial: OpenTutorialMenuWindow
If [ Get ( WindowName ) = "Tutorial" ]
Go to Layout [ “tutorialGroup” (tutorialGroup) ]
Show All Records
Sort Records [ Speciﬁed Sort Order: tutorialGroup::ModuleName; ascending
tutorialGroup::Name; ascending ]
[ Restore; No dialog ]
Exit Script [ ]
End If
Set Variable [ $tutorial; Value:Get (ActiveFieldContents) ]
Go to Field [ ]
Select Window [ Name: "Tutorial"; Current ﬁle ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Tutorial"; Height: Get ( ScreenHeight ); Top: 0; Left: 0 ]
Go to Layout [ “tutorialGroup” (tutorialGroup) ]
Show All Records
Sort Records [ Speciﬁed Sort Order: tutorialGroup::ModuleName; ascending
tutorialGroup::Name; ascending ]
[ Restore; No dialog ]
End If
Adjust Window
[ Resize to Fit ]
Set Variable [ $width; Value:Get (WindowWidth) ]
Select Window [ Name: "Help"; Current ﬁle ]
Move/Resize Window [ Current Window; Height: Get ( ScreenHeight ); Width: Get (ScreenWidth) - $width; Top: 0; Left: $width ]
Select Window [ Name: "Tutorial"; Current ﬁle ]
