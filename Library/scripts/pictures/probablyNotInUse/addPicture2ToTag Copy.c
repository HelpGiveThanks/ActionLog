pictures: probablyNotInUse: addPicture2ToTag Copy
#
#Do not allow learn records to be added to tags as
#that would require insuring all that Learn record's
#reference records tagged onto it were also
#brought into the new section along with all
#their tags, and their tags' tags. THUS only allow
#Learn records to be added to tags that have a picture
#or link (thus provide value) and have none of the
#above mentioned tags: reference, cite.
#AND once such a tag is added no reference,
#or cite tags can be added to it.
If [ testlearn::kcitation ≠ "" or testlearn::kcreference ≠ "" ]
Show Custom Dialog [ Message: "Learn records with references or a citation cannot be added to tags. Doing so would require adding all these reference and cite records' references and cite records, and then all of theirs, and so on. "; Buttons: “OK” ]
Exit Script [ ]
End If
#
#Note which button has been clicked ( 1, 2 or 3)
#and if there is a picture to show then link it
#to tag user is currently wanting to link it to.
If [ reference::kﬁleLocation ≠ "" and reference::ﬁleName ≠ "" and ruleCitationCategoryMedium::name = "picture"
 or
ruleCitationCategoryMedium::name = "picture" and reference::URL ≠ ""
 or
testlearn::kﬁleLocation ≠ "" and testlearn::ﬁlename ≠ "" and ruleTLCategoryMedium::name = "picture"
 or
ruleTLCategoryMedium::name = "picture" and testlearn::URL ≠ "" ]
Set Variable [ $$name; Value:"picture" ]
Set Variable [ $$number; Value:2 ]
#
#If the ﬁlterFind checkbox is not checked for the
#the current $$CitationMatch variable, then
#these next scripts will identify that problem,
#ﬁx it, and inform the user of what it did.
If [ Get ( LayoutTableName ) = "testlearn" ]
If [ $$citationMatch = "key" and "keyword" & ¶ ≠ FilterValues ( testlearn::ﬁlterFind ; "keyword" ) ]
Set Variable [ $ﬁlterFind; Value:testlearn::ﬁlterFind ]
Set Field [ testlearn::ﬁlterFind; "keyword" & ¶ & $ﬁlterFind ]
Show Custom Dialog [ Message: "The system has added this learn record to the " &
If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) &
 " citation record set. You will not have to click the 'all' button anymore to ﬁnd it for " & If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."
//Next time you click on the add button, this record will be found as part of the records supplying pictures, ﬁle and web links to " &
//If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."; Buttons: “OK” ]
Else If [ $$citationMatch & ¶ ≠ FilterValues ( testlearn::ﬁlterFind ; $$citationMatch ) ]
Set Variable [ $ﬁlterFind; Value:testlearn::ﬁlterFind ]
Set Field [ testlearn::ﬁlterFind; $$citationMatch & ¶ & $ﬁlterFind ]
Show Custom Dialog [ Message: "The system has added this learn record to the " &
If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) &
 " citation record set. You will not have to click the 'all' button anymore to ﬁnd it for " & If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."
//Next time you click on the add button, this record will be found as part of the records supplying pictures, ﬁle and web links to " &
//If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."; Buttons: “OK” ]
End If
#
Else If [ Get ( LayoutTableName ) = "reference" ]
If [ $$citationMatch = "key" and "keyword" & ¶ ≠ FilterValues ( reference::ﬁlterFind ; "keyword" ) ]
Set Variable [ $ﬁlterFind; Value:reference::ﬁlterFind ]
Set Field [ reference::ﬁlterFind; "keyword" & ¶ & $ﬁlterFind ]
Show Custom Dialog [ Message: "The system has added this reference record to the " &
If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) &
 " citation record set. You will not have to click the 'all' button anymore to ﬁnd it for " & If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."
//Next time you click on the add button, this record will be found as part of the records supplying pictures, ﬁle and web links to " &
//If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."; Buttons: “OK” ]
Else If [ $$citationMatch & ¶ ≠ FilterValues ( reference::ﬁlterFind ; $$citationMatch ) ]
Set Variable [ $ﬁlterFind; Value:reference::ﬁlterFind ]
Set Field [ reference::ﬁlterFind; $$citationMatch & ¶ & $ﬁlterFind ]
Show Custom Dialog [ Message: "The system has added this reference record to the " &
If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) &
 " citation record set. You will not have to click the 'all' button anymore to ﬁnd it for " & If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."
//Next time you click on the add button, this record will be found as part of the records supplying pictures, ﬁle and web links to " &
//If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."; Buttons: “OK” ]
End If
End If
#
#Now perform the script that adds the tag.
Perform Script [ “CHUNKaddPictureToTag” ]
End If
January 7, 平成26 17:21:35 Imagination Quality Management.fp7 - addPicture2ToTag Copy -1-
