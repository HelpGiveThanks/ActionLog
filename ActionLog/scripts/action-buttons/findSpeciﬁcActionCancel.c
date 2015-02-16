action buttons: FindSpecificActionCancel
#If the user decides to cancel their the find, then return
#to the main record window and show all records.
Go to Layout [ “Issues” (issue) ]
Enter Find Mode [ ]
Set Field [ issue::_keyBrainstate; $$logBrainstate ]
Perform Find [ ]
Show/Hide Status Area
[ Hide ]
Show/Hide Text Ruler
[ Hide ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Halt Script
January 5, 平成26 19:50:04 ActionLog.fp7 - FindSpecificActionCancel -1-
