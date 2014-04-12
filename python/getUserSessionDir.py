import locale
import os
import time
import glob
import sys

import pythoncom
import win32api
import win32com.client
from   win32com.shell import shell, shellcon
import win32con
import win32event
import win32file
import win32process

def getUserSessionDir():
	try:
		encoding = locale.getpreferredencoding()
	except locale.Error:
		encoding = "UTF-8"
	
	d = shell.SHGetSpecialFolderPath(None, shellcon.CSIDL_APPDATA)
	d = d.encode(encoding)
	
	return os.path.join(d, "chrust", "svd")

print getUserSessionDir()

appdata = os.getenv("APPDATA")
print appdata

t0 = time.time()
print t0

print os.environ["windir"]

buf = file("dump.txt", "a", 0)
sys.stderr = buf
sys.stdout = buf
print "#################################################"
print getUserSessionDir()