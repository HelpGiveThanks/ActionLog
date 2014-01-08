editCreateWorkout: editorButtons: updateTimeSequence: setRetotalFieldAfterZoneChange
#
#This script insures that a workouts time or zone
#cannot be modified and then used without re-totaling
#the workout first to take account of the modification.
Set Field [ activity::go; "" ]
#
#The other purpose of the script is to refresh
#the window to account for changes zone change can make.
Go to Field [ ]
Refresh Window
January 8, 平成26 12:41:48 Fat and Muscle Efﬁciency Research.fp7 - setRetotalFieldAfterZoneChange -1-
