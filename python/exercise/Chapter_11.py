# -*- coding: cp936 -*-
#��ʮһ�� �ļ�

f = open('python_file_test.txt','a')
f.write('\n')
f.write('Hello, ')
f.write('World!')
f.close()

f = open('python_file_test.txt','r')
print f.read(4)
