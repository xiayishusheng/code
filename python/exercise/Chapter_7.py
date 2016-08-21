# -*- coding: cp936 -*-
#第七章 更抽象 类 对象

#创建自己的类 下面来看一个简单的类
'''
__metaclass__ = type #确定使用新式类

class Person:
    def setName(self, name):
        self.name = name

    def getName(self):
        return self.name

    def greet(self):
        print "Hello, World! I'm %s." % self.name

foo = Person()
foo.setName('Luke')
print foo.getName()
print foo.name
foo.greet()

foo.name = 'Tom'
foo.greet()

Person.greet(foo)
'''

#自己测试
'''
class Test:
    def test(self):
        print self

bar = Test()
bar.test()
'''

#为了让方法或者特性变为私有(外部无法访问),只要在他的名字前面加上双下划线即可
'''
class Secretive:
    def __inneraccessible(self):
        print "Bet you can't see me..."

    def accessible(self):
        self.__inneraccessible()

s = Secretive()
#s.__inneraccessible()   #错误的访问方法
s.accessible()
'''
