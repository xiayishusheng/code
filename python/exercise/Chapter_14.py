# -*- coding: cp936 -*-
#第十四章 网络编程

import socket
'''
#一个小型服务器
s = socket.socket()

host = socket.gethostname()
print host
port = 1235
s.bind((host, port))

s.listen(5)
while True:
    c, addr = s.accept()
    print 'Got connect from', addr
    c.send('Thank you for connecting!')
    c.close()
'''
'''
#小型客户机
s = socket.socket()
host = socket.gethostname()
port = 1235

s.connect((host, port))
print s.recv(1024)
'''

#urllib和urllib2模块
'''##打开远程文件
from urllib import urlopen,urlretrieve
webpage = urlopen('http://www.python.org')
##获取远程文件
urlretrieve('http://www.python.org','python.html')'''

#Twisted模块
from twisted.internet import reactor

