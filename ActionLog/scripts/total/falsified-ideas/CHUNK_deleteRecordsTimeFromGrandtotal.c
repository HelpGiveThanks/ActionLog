total: falsified ideas: CHUNK_deleteRecordsTimeFromGrandtotal
#DISABLE: I thought this was a good idea to delete total records that nothing to total for the user. But after thinking about it, I now think I should
allow the user to do this. There is no harm in having a non-working total record. It can always be used again by adding records to it to
total, or by turning it into a regular record.
// #PURPOSE set the variables and make a list of the grandtotal records whose time has gone down
// #CHUNK USED BY seperateFromTotal Script
// #
// #
// #
// #basic administration tasks
// Set Error Capture [ On ]
// Allow User Abort [ Off ]
// #
// #
// #
// #1 capture grandtotal record's ID number
// Set Variable [ $brainstateID; Value:brainstate::groupOfGroupID ]
// Set Variable [ $$deleteID; Value:brainstate::_lockBrainstateID ]
// Set Variable [ $totaldisplayID; Value:brainstate::groupDisplayID ]
// Set Variable [ $description; Value:brainstate::description ]
// Set Field [ brainstate::description; " delete interrupted! click here for info: Delete this record and this grandtotal record ID number -- " &
$brainstateID & ". Both can be rebuilt if you still want them. // " & $description ]
// Set Field [ brainstate::groupOfGroupID; "" ]
// Set Field [ brainstate::groupOfGroupDisplayID; "" ]
// #
// #2 make a list of records that are part of the grandtotal -- including the grandtotal in preparation or totaling their time (after separating a record
from one of the totals)
// Enter Find Mode [ ]
// Set Field [ brainstate::groupOfGroupID; $brainstateID ]
// Perform Find [ ]
// Perform Script [ “CHUNK_recalculateGrandTotal” ]
January 5, 平成26 14:16:37 ActionLog.fp7 - CHUNK_deleteRecordsTimeFromGrandtotal -1-
