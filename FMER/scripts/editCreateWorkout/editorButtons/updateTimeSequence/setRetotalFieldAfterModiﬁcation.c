editCreateWorkout: editorButtons: updateTimeSequence: setRetotalFieldAfterModiﬁcation
#
#This script insures that a workouts time or zone
#cannot be modified and then used without re-totaling
#the workout first to take account of the modification.
Set Field [ activity::go; "" ]
#
#The other purpose of the script is to exit a
#modified field.
Go to Field [ ]
January 8, 平成26 12:41:02 Fat and Muscle Efﬁciency Research.fp7 - setRetotalFieldAfterModiﬁcation -1-
