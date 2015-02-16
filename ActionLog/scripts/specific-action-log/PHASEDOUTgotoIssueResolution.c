specific action log: PHASEDOUTgotoIssueResolution
If [ issueStatus::order > 79 and $$stopgotoIssueResolution ≠ 1 ]
Set Variable [ $resolutionDate; Value:GetAsDate ( issue::dateDone ) ]
Set Variable [ $$stoploadrecord; Value:1 ]
Select Window [ Name: "Day"; Current file ]
Go to Record/Request/Page
[ First ]
Go to Field [ ]
Freeze Window
Loop
Exit Loop If [ logs::_keyDay = $resolutionDate ]
Go to Record/Request/Page
[ Next; Exit after last ]
End Loop
If [ logs::_keyDay ≠ $resolutionDate ]
Set Variable [ $$stoploadrecord ]
Go to Record/Request/Page
[ First ]
Scroll Window
[ Home ]
Show Custom Dialog [ Message: "No activity log record matches the date for this issue's resolution. "; Buttons: “OK” ]
Exit Script [ ]
End If
Set Variable [ $$stoploadrecord ]
Perform Script [ “LoadLogrecordID” ]
Go to Field [ logs::log ]
End If
January 6, 平成26 1:15:39 ActionLog.fp7 - PHASEDOUTgotoIssueResolution -1-
