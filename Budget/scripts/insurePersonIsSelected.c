insurePersonIsSelected
If [ out::kperson = "" ]
Go to Field [ ]
If [ $$stopMessage = "" ]
Show Custom Dialog [ Message: "Select a person or group of people doing the spending."; Buttons: “OK” ]
End If
Go to Field [ out::kperson ]
[ Select/perform ]
// Go to Object [ Object Name: "person" ]
End If
January 8, 平成26 19:08:27 Budget Research.fp7 - insurePersonIsSelected -1-
