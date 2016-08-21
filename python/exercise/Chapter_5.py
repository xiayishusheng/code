# -*- coding: cp936 -*-
#第五章 条件、循环和其他语句

from math import sqrt

#把某事件作为另一件事导入
"""
import math as foobar
print foobar.sqrt(9)

from math import sqrt as foo
print foo(25)
"""

#序列解包
'''
x,y,z = 1,2,3
print x,y,z
x,y = y,x
print x,y,z
'''

#布尔变量的作用 下面的值在作为布尔表达式的时候会被解释器看做假（false）False、None、0、""、()、[]、{}
'''
name = raw_input("What's your name?")
if name.endswith('Gumby'):
    print 'Hello, Mr. Gumby!'
else:
    print 'Hello, Stranger!'
'''

#断言
'''
age = -1
assert 0 < age < 100, '年龄必须为正数!'
'''

#while循环
'''
x = 1
while x <= 10:
    print x
    x += 1
'''

#for循环
'''
words = ['This','is','an','ex','parrot']
for word in words:
    print word

for i in range(0,10,2):
    print i
'''

#翻转和排序迭代
'''
print sorted([4,3,6,8,3])
print sorted('Hello,World!')
print list(reversed('Hello,world!'))
print ''.join(reversed('Hello,world!'))
'''

#跳出循环   例：寻找100以内的最大平方数，当找到之后就不需要执行了
'''
for n in range(99,0,-1):
    root = sqrt(n)
    if root == int(root):
        print n
        break

'''

#使用exec和eval执行和求值字符串
exec "print 'Hello,world!'"
print eval(raw_input("输入一个算数表达式："))

