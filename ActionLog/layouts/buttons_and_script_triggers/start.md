TagMenu layouts below *(layout numbers for Library v3.2c beta)* all have a 'move' button with the following properties:

* dropdown menus
 * on copyright, publication, and publisher layouts =
 tagGroupNoSectionTagsLikePath
 * on keyword, and node layouts =
 tagGroupNoSectionTagsLikePath
* conditional formatting =


    //Hide the 'move' button if ...

      //there is only one group,
        ValueCount ( ValueListItems ( Get ( FileName ) ; "tagGroup" ) ) = 1
        and ( $$citationMatch  =  "key" or $$citationMatch  =  "node" )  = 1
        or
        ValueCount ( ValueListItems ( Get ( FileName ) ; "tagGroupNoSectionTagsLikePath" ) ) = 1

      //record is locked by the node that created it,
        or nodeLockTagMenus::orderOrLock ≠ ""

      //record is locked by system admin.
        or tagMenus::orderOrLock = "lock"

 * field = tagMenus::kGroupOrTest
 * layout script trigger = OnRecordLoad perform script loadTagRecord
 * script trigger = OnObjectModify perform script moveTagToNewGroup


1.  22 defaultHealth
1.  23 defaultNode1
1.  24 defaultNode2
1.  25 defaultNode3
1.  36 ReferenceMenuHealth
6.	43 ReferenceMenu2keywordOrNode3
7.	44 ReferenceMenu2SkeywordOrNode3
6.	45 ReferenceMenu2keywordOrNode4
7.	46 ReferenceMenu2SkeywordOrNode4
6.	47 ReferenceMenu2keywordOrNode5
7.	48 ReferenceMenu2SkeywordOrNode5
8.	67 addMenu1
9.	68 addMenuNodeKeyword
10.	69 addMenu1
11.	70 addMenuTestItem
11.	94 ltagNK3
11.	95 ltagNKs3
11.	96 ltagNK4
11.	97 ltagNKs4
11.	98 ltagNK2
11.	99 ltagNKs2
11.	101 learnMenu1
11.	102 learnMenuHealth
11.	103 learnMenuSHealth
11.	156 testMenuTestItemMORE
