#small server

import socket

s = socket.socket()

host = socket.gethostname()
print host
port = 1236
s.bind((host, port))

s.listen(5)
while True:
    c, addr = s.accept()
    print 'Got connect from', addr
    c.send('Thank you for connecting!')
    c.close()