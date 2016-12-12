backup: restoreBackup
#PURPOSE determine if file was opened by
#admin or by script, and then depending on
#who opened it: admin = remain open,
#backup script = save a copy of itself, or
#restore script = delete all its files and import
#backup files to replace them.
#
#Errors will be generated when opening up backup file
#as there is a dependency on the reference file and it
#will probably not be located in the same folder as the
#backup file. This dependency is not needed for backup.
#So we have the system ignore this error message.
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
#Set the backup flag to restore (this is used by
#the open script in the MyData file to
#determine if it should make a copy of itself or
#replace all its current files with a backup.
Set Field [ backup::backup; "restore" ]
#
#Open file and determine its location (path)
#then close it after its location has been
#pasted using that file's open script into the
#main data file.
#Have user point the database to the backup
#copy of their choice.
Open File [ <unknown> ]
Close Window [ Name: "backup" ]
#
#Open MyData file and then using its open
#script restore the backup file just located.
Open File [ “MyData” ]
[ Open hidden ]
#
#Go to user layout and show all records.
Go to Layout [ “users” (user) ]
Show All Records
December 10, ଘ౮28 20:55:12 ActionLog.fp7 - restoreBackup -1-
