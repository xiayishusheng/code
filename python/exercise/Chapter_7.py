# -*- coding: cp936 -*-
#������ ������ �� ����

#�����Լ����� ��������һ���򵥵���
'''
__metaclass__ = type #ȷ��ʹ����ʽ��

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

#�Լ�����
'''
class Test:
    def test(self):
        print self

bar = Test()
bar.test()
'''

#Ϊ���÷����������Ա�Ϊ˽��(�ⲿ�޷�����),ֻҪ����������ǰ�����˫�»��߼���
'''
class Secretive:
    def __inneraccessible(self):
        print "Bet you can't see me..."

    def accessible(self):
        self.__inneraccessible()

s = Secretive()
#s.__inneraccessible()   #����ķ��ʷ���
s.accessible()
'''
