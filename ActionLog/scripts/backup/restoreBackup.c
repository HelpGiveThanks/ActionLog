backup: restoreBackup
#PURPOSE determine if file was opened by admin or by script, and then depending on who opened it: admin = remain open, backup script =
save a copy of itself, or restore script = delete all its files and import backup files to replace them
#
#Errors will be generated when opening up backup file
#as there is a dependency on the reference file and it
#will probably not be located in the same folder as the
#backup file. This dependency is not needed for backup.
#So we have the system ignore this error message.
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#1 set the backup ﬂag to restore (this is used by the open script in the main file to determine if it should make a copy of itself or replace all its
current files with a backup
Set Field [ backup::backup; "restore" ]
#
#2 open file and determine its location (path) then close it after its location has been pasted using that file's open script into the main data file
#file is unknown so user is given the opportunity to point the database to the backup copy of their choice
Open File [ <unknown> ]
Close Window [ Name: "backup" ]
#
#3 open main data file and then using its open script restore the backup file just located in step 2
Open File [ “MyData” ]
[ Open hidden ]
#
#4 go to user layout and show all records
Go to Layout [ “users” (steward) ]
Show All Records
January 6, 平成26 1:00:54 ActionLog.fp7 - restoreBackup -1-
