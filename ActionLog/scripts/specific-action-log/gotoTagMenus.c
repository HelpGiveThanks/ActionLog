specific action log: gotoTagMenus
Select Window [ Name: "Tag"; Current file ]
If [ Get (LastError) = 112 ]
New Window [ Name: "Tag" ]
If [ Get ( WindowZoomLevel ) = 200 ]
Move/Resize Window [ Current Window; Width: 550; Left: If (Get (ScreenWidth) / 2 + 550 ≤ Get (ScreenWidth) ; Get
(ScreenWidth)/2 ; Get (ScreenWidth) - 550 ) ]
Else If [ Get ( WindowZoomLevel ) = 300 ]
Move/Resize Window [ Current Window; Width: 830; Left: If (Get (ScreenWidth) / 2 + 830 ≤ Get (ScreenWidth) ; Get
(ScreenWidth)/2 ; Get (ScreenWidth) - 830 ) ]
Else If [ Get ( WindowZoomLevel ) = 400 ]
Move/Resize Window [ Current Window; Width: 1100; Left: If (Get (ScreenWidth) / 2 + 1100 ≤ Get (ScreenWidth) ; Get
(ScreenWidth)/2 ; Get (ScreenWidth) - 1100 ) ]
Else If [ Get ( WindowZoomLevel ) = 150 ]
Move/Resize Window [ Current Window; Height: Get (ScreenHeight); Width: 441; Top: 0; Left: If (Get (ScreenWidth) / 2 +
1100 ≤ Get (ScreenWidth) ; Get (ScreenWidth)/2 ; Get (ScreenWidth) - 1100 ) ]
End If
Go to Layout [ <unknown> ]
Enter Find Mode [ ]
Set Field [ brainstate::_lockBrainstateID; $$logBrainstate ]
Perform Find [ ]
Select Window [ Name: "Tag"; Current file ]
End If
December 7, ଘ౮27 18:52:36 ActionLog.fp7 - gotoTagMenus -1-
