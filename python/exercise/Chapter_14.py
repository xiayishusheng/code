# -*- coding: cp936 -*-
#��ʮ���� ������

import socket
'''
#һ��С�ͷ�����
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
#С�Ϳͻ���
s = socket.socket()
host = socket.gethostname()
port = 1235

s.connect((host, port))
print s.recv(1024)
'''

#urllib��urllib2ģ��
'''##��Զ���ļ�
from urllib import urlopen,urlretrieve
webpage = urlopen('http://www.python.org')
##��ȡԶ���ļ�
urlretrieve('http://www.python.org','python.html')'''

#Twistedģ��
from twisted.internet import reactor

