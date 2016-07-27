specific action log: toggleViewToSeeAllWindows
#
#
If [ Get ( SystemPlatform ) = 3 ]
Exit Script [ ]
End If
#
#Only allow timer to be stopped if it is running today
#or tomorrow (meaning today after midnight).
#
#
If [ Get ( WindowName ) = "Specific Action" ]
#
If [ $$toggleSpecificActionView = "" ]
Set Variable [ $$toggleSpecificActionView; Value:1 ]
Move/Resize Window [ Name: "Tag"; Current file; Height: 266; Width: 344; Top: 0; Left: 688 ]
Move/Resize Window [ Name: "Day"; Current file; Height: 266; Width: 344; Top: 0; Left: 344 ]
Move/Resize Window [ Name: "Timer"; Current file; Height: Get (ScreenHeight) - 276; Width: Get (ScreenWidth) - 344; Top:
251; Left: 344 ]
Move/Resize Window [ Name: "Specific Action"; Current file; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: 0 ]
#
Else
#
Set Variable [ $$toggleSpecificActionView ]
Move/Resize Window [ Name: "Timer"; Current file; Height: Get (ScreenHeight) - 2 * ( Get (ScreenHeight) * .05 ); Width:
Get (ScreenWidth) * .8; Top: Get (ScreenHeight) * .05; Left: Get (ScreenWidth) * .1 ]
Move/Resize Window [ Name: "Tag"; Current file; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
Move/Resize Window [ Name: "Day"; Current file; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: Get (ScreenWidth) -
688 ]
Move/Resize Window [ Name: "Specific Action"; Current file; Height: Get (ScreenHeight); Width: Get (ScreenWidth) - 688;
Top: 0; Left: 0 ]
End If
#
Else
#
If [ $$toggleSpecificActionView = "" ]
Set Variable [ $$toggleSpecificActionView; Value:1 ]
Move/Resize Window [ Name: "Tag"; Current file; Height: 266; Width: 344; Top: 0; Left: 688 ]
Move/Resize Window [ Name: "Day"; Current file; Height: 266; Width: 344; Top: 0; Left: 344 ]
Move/Resize Window [ Name: "Specific Action"; Current file; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: 0 ]
Move/Resize Window [ Name: "Timer"; Current file; Height: Get (ScreenHeight) - 276; Width: Get (ScreenWidth) - 344; Top:
251; Left: 344 ]
#
Else
#
Set Variable [ $$toggleSpecificActionView ]
Move/Resize Window [ Name: "Tag"; Current file; Height: Get (ScreenHeight); Top: 0; Left: Get (ScreenWidth) - 344 ]
Move/Resize Window [ Name: "Day"; Current file; Height: Get (ScreenHeight); Width: 344; Top: 0; Left: Get (ScreenWidth) -
688 ]
Move/Resize Window [ Name: "Specific Action"; Current file; Height: Get (ScreenHeight); Width: Get (ScreenWidth) - 688;
Top: 0; Left: 0 ]
Move/Resize Window [ Name: "Timer"; Current file; Height: Get (ScreenHeight) - 2 * ( Get (ScreenHeight) * .05 ); Width:
Get (ScreenWidth); Top: Get (ScreenHeight) * .05; Left: 0 ]
End If
End If
#
#
July 26, ଘ౮28 15:44:19 ActionLog.fp7 - toggleViewToSeeAllWindows -1-
