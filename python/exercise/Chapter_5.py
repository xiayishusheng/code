# -*- coding: cp936 -*-
#������ ������ѭ�����������

from math import sqrt

#��ĳ�¼���Ϊ��һ���µ���
"""
import math as foobar
print foobar.sqrt(9)

from math import sqrt as foo
print foo(25)
"""

#���н��
'''
x,y,z = 1,2,3
print x,y,z
x,y = y,x
print x,y,z
'''

#�������������� �����ֵ����Ϊ�������ʽ��ʱ��ᱻ�����������٣�false��False��None��0��""��()��[]��{}
'''
name = raw_input("What's your name?")
if name.endswith('Gumby'):
    print 'Hello, Mr. Gumby!'
else:
    print 'Hello, Stranger!'
'''

#����
'''
age = -1
assert 0 < age < 100, '�������Ϊ����!'
'''

#whileѭ��
'''
x = 1
while x <= 10:
    print x
    x += 1
'''

#forѭ��
'''
words = ['This','is','an','ex','parrot']
for word in words:
    print word

for i in range(0,10,2):
    print i
'''

#��ת���������
'''
print sorted([4,3,6,8,3])
print sorted('Hello,World!')
print list(reversed('Hello,world!'))
print ''.join(reversed('Hello,world!'))
'''

#����ѭ��   ����Ѱ��100���ڵ����ƽ���������ҵ�֮��Ͳ���Ҫִ����
'''
for n in range(99,0,-1):
    root = sqrt(n)
    if root == int(root):
        print n
        break

'''

#ʹ��exec��evalִ�к���ֵ�ַ���
exec "print 'Hello,world!'"
print eval(raw_input("����һ���������ʽ��"))

