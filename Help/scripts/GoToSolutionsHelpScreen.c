GoToSolutionsHelpScreen
Set Variable [ $layout; Value:module::name ]
Close Window [ Name: "Help Screens"; Current ?le ]
Go to Layout [ $layout ]
Omit Multiple Records [ Get (FoundCount) - 1 ]
[ No dialog ]
