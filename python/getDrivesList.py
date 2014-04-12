import win32api
import win32con
import win32file

class Drives():
	@staticmethod
	def getDrivesList():
		l = []
		drives = win32api.GetLogicalDriveStrings()
		drives = drives.split('\000')[:-1]
		for drive in drives:
			t = win32file.GetDriveType(drive)
			if t == win32con.DRIVE_REMOTE:
				continue
			
			l.append(drive)
		
		return l

drives = Drives()
print drives.getDrivesList()

drives = win32api.GetLogicalDriveStrings()
print drives
drives = drives.split('\000')[:-1]
print drives
