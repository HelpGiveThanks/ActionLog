view
#
#Reveal more or fewer pictures and links for tag.
#
#from 1 to 2
If [ Right ( Get (LayoutName) ; 1) = 1
and
Left ( out::purchaseLayoutView ; 4 ) = "more" ]
Go to Layout [ “PurchaseTotals2” (out) ]
#from 2 to 3
Else If [ Right ( Get (LayoutName) ; 1) = 2
and
Left ( out::purchaseLayoutView ; 4 ) = "more" ]
Go to Layout [ “PurchaseTotals3” (out) ]
#from 3 to 4
Else If [ Right ( Get (LayoutName) ; 1) = 3
and
Left ( out::purchaseLayoutView ; 4 ) = "more" ]
Go to Layout [ “PurchaseTotals4” (out) ]
#from 4 to 3
Else If [ Right ( Get (LayoutName) ; 1) = 4
and
Left ( out::purchaseLayoutView ; 4 ) = "less" ]
Go to Layout [ “PurchaseTotals3” (out) ]
#from 3 to 2
Else If [ Right ( Get (LayoutName) ; 1) = 3
and
Left ( out::purchaseLayoutView ; 4 ) = "less" ]
Go to Layout [ “PurchaseTotals2” (out) ]
#from 2 to 1
Else If [ Right ( Get (LayoutName) ; 1) = 2
and
Left ( out::purchaseLayoutView ; 4 ) = "less" ]
Go to Layout [ “PurchaseTotals1” (out) ]
End If
#
#Remember layout user is on so they can be
#returned to correct view.
#
#from 1 to 2
If [ Right ( Get (LayoutName) ; 1) = 2
and
Left ( out::purchaseLayoutView ; 4 ) = "more" ]
Set Field [ out::purchaseLayoutView; "more" & Get (LayoutName) ]
#from 2 to 3
January 8, 平成26 19:10:01 Budget Research.fp7 - view -1-view
Else If [ Right ( Get (LayoutName) ; 1) = 3
and
Left ( out::purchaseLayoutView ; 4 ) = "more" ]
Set Field [ out::purchaseLayoutView; "more" & Get (LayoutName) ]
#from 3 to 4
Else If [ Right ( Get (LayoutName) ; 1) = 4
and
Left ( out::purchaseLayoutView ; 4 ) = "more" ]
Set Field [ out::purchaseLayoutView; "less" & Get (LayoutName) ]
#from 4 to 3
Else If [ Right ( Get (LayoutName) ; 1) = 3
and
Left ( out::purchaseLayoutView ; 4 ) = "less" ]
Set Field [ out::purchaseLayoutView; "less" & Get (LayoutName) ]
#from 3 to 2
Else If [ Right ( Get (LayoutName) ; 1) = 2
and
Left ( out::purchaseLayoutView ; 4 ) = "less" ]
Set Field [ out::purchaseLayoutView; "less" & Get (LayoutName) ]
#from 2 to 1
Else If [ Right ( Get (LayoutName) ; 1) = 1
and
Left ( out::purchaseLayoutView ; 4 ) = "less"
 or
out::purchaseLayoutView = "" ]
Set Field [ out::purchaseLayoutView; "more" & Get (LayoutName) ]
End If
#
January 8, 平成26 19:10:01 Budget Research.fp7 - view -2-
