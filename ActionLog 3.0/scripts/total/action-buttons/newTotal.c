total: action buttons: newTotal
#PURPOSE create a new total record
#
#
#
#basic administration tasks
Set Variable [ $userID; Value:reference::farmerID ]
#
#
#
#1 create the new total record
#NOT TESTED
If [ Get ( SystemPlatform ) = 3 or steward::iPhoneLayout ≠ "" ]
Go to Layout [ “TotalSortAndScheduleiPhone” (brainstate) ]
Else If [ Get ( SystemPlatform ) ≠ 3 or steward::iPhoneLayout = "" ]
Go to Layout [ “TotalSort” (brainstate) ]
End If
#END NOT TESTED
New Record/Request
Set Field [ brainstate::_keyUser; $userID ]
Set Field [ brainstate::linkinfo; "total of: " ]
Set Field [ brainstate::description; "new total record / folder name" ]
Set Field [ brainstate::groupType; "merge" ]
Set Field [ brainstate::groupDisplayID; brainstate::_Number ]
Set Field [ brainstate::Show; "t" ]
Set Field [ brainstate::hide; "t" ]
Set Field [ brainstate::groupID; brainstate::_lockBrainstateID ]
Set Variable [ $mergeID; Value:brainstate::_lockBrainstateID ]
Enter Find Mode [ ]
Set Field [ brainstate::groupID; $mergeID ]
Perform Find [ ]
Go to Field [ brainstate::description ]
[ Select/perform ]
January 5, 平成26 14:09:51 ActionLog.fp7 - newTotal -1-
