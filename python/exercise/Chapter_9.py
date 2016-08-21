# -*- coding: cp936 -*-
#�ھ��� ħ�����������Ժ͵�����

#   ��Python�У��е����ƻ���ǰ��ͺ��涼���������»��ߣ�����д��������ĺ��壬���Բ�Ҫ��
#������ʹ�����������֡���Python�У�����Щ������ɵļ����������ķ�����Ϊħ�����������ⷽ����

#���췽��   __init__ ��Ϊ���캯��
'''
class FooBar:
    def __init__(self, value):
        self.somevar = value

f = FooBar('Hello World!!')
print f.somevar
'''

#��дһ�㷽��������Ĺ��췽��
'''
##�����ʵ���е��÷��������ڸ�����û���ҵ��˷�������ô�ͻ�ȥ�����ĳ�������
class A:
    def hello(self):
        print "Hello, I'm A."
class B(A): #B�̳���A
    pass
a = A()
b = B()
a.hello()
b.hello() #bʵ����û��hello()��������ȥA��������
##������дA���hello()����
class C(A):
    def hello(self):
        print "Hello, I'm C."
c = C()
c.hello()
'''

#��д���췽��������  ���һ����Ĺ��췽������д����ô����Ҫ���ó���Ĺ��췽������������ܱ���ȷ�ĳ�ʼ��
"""
'''
class Bird: #����ඨ�����е��񶼾���һЩ��������������
    def __init__(self):
        self.hungry = True
    def eat(self):
        if self.hungry:
            print '�Һܶ�,Ҫ�Է�!'
            self.hungry = False
        else:
            print "������,�ҳԱ���!"
            self.hungry = True
b = Bird()
b.eat()
b.eat()
b.eat()
b.eat()
## ����SongBird��Ϊ����ӳ������Ϊ
class SongBird(Bird):
    def __init__(self):
        self.sound = "ͬһ�׸�!"
    def sing(self):
        print self.sound
sb = SongBird()
sb.sing()
##��ΪSongBird��Bird�����࣬���̳���eat()�����������������eat()�������ͻ����
#sb.eat()
##  �׳����쳣�����˵������������ڣ�SongBirdû��hungry���ԡ�
##ԭ�����������ģ���SongBird�У����췽������д�������µĹ��췽��û���κι��ڳ�ʼ��hungry
##�����ԵĴ��롣Ϊ�˴ﵽԤ�ڵ�Ч����SongBird�Ĺ��췽����������䳬��Bird�Ĺ��췽����ȷ��
##���л����ĳ�ʼ����
##�����ַ����ܴﵽ���Ŀ�ģ�1�����ó��๹�췽����δ�󶨰汾
##                       2��ʹ��super����

#1�����ó��๹�췽����δ�󶨰汾
class SongBird(Bird):               ##  Ϊʲô���������Ľ�����ڵ���һ��ʵ���ķ���ʱ��
    def __init__(self):             ##�÷�����self�����ᱻ�Զ��󶨵�ʵ���ϡ����ǣ����
        Bird.__init__(self)         ##ֱ�ӵ�����ķ�������ô��û��ʵ�����󶨡������Ϳ���
        self.sound = "����������"    ##���ɵ��ṩ��Ҫ��self�����������ķ�����Ϊδ��(unbound)
    def sing(self):                 ##������
        print self.sound            ##
sb = SongBird()                     ##
sb.sing()                           ##
sb.eat()                            ##
sb.eat()                            ##
'''

#2��ʹ��super����
'''
##����������Ƕ�Bird���ӵĸ���
__metaclass__ = type #super����ֻ����ģʽ������Ч
class Bird:
    def __init__(self):
        self.hungry = True
    def eat(self):
        if self.hungry:
            print "�Ҷ��ˣ�Ҫ�Է���"
            self.hungry = False
        else:
            print "�����ˣ��ҳԱ��ˣ�"
            self.hungry = True
class SongBird(Bird):
    def __init__(self):
        super(SongBird, self).__init__()
        self.sound = "ī������"
    def sing(self):
        print self.sound
sb = SongBird()
sb.sing()
sb.eat()
'''
"""

#��̬���������Ա����
"""
##  ��̬���������Ա�����ڴ���ʱ�ֱ�װ��Sraticmethod���ͺ�Classmethod���͵Ķ�����
##��̬����û��self���������ܱ��౾��ֱ�ӵ��á��෽���ڶ����ʱ��Ҫ��Ϊcls��������self�Ĳ�����
##���Ա��������ֱ������ľ��������ã���cls�������Զ����󶨵���ġ�
'''__metaclass__ = type
class MyClass:
    def smeth():
        print 'This is a static method'
    smeth = staticmethod(smeth)
    def cmeth(cls):
        print 'This is a class method of',cls
    cmeth = classmethod(cmeth)'''
##  2.4�汾�����롮װ�����������﷨(���ܶ��κοɵ��õĶ�����а�װ���������ڷ���Ҳ�����ں���)
##ʹ��@���������ڷ���������Ϸ���װ�����г����Ӷ�ָ��һ�����߸����װ���������װ������Ӧ��ʱ��˳���ָ��˳���෴����
__metaclass__ = type
class MyClass:
    @staticmethod
    def smeth():
        print 'This is a static method'
    @classmethod
    def cmeth(cls):
        print 'This is a class method of',cls
MyClass.smeth()     #��������Щ�����󣬾Ϳ���ֱ��ʹ���ˣ�����ʵ�����ࣩ
MyClass.cmeth()
"""

#������    __iter__�ǵ���������(iertator protocol)�Ļ���
##���ӣ�쳲���������
'''
class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1
    def next(self):
        self.a, self.b = self.b, self.a + self.b
        return self.a
    def __iter__(self):
        return self
##һ��ʵ����__iter__�����Ķ����ǿɵ����ģ�һ��ʵ����next�����Ķ������ǵ�����
fibs = Fibs()
for f in fibs:
    if f > 1000:    #������쳲����������б�1000������е���С��
        print f
        break
'''

#�ӵ������õ�����
'''
class TestIterator:
    value = 0
    def next(self):
        self.value += 1
        if self.value > 10 : raise StopIteration
        return self.value
    def __iter__(self):
        return self
ti = TestIterator()
print list(ti)
'''

#������
'''
def flatten(nested):
    for sublist in nested:
        for element in sublist:
            yield element   ##  ����yield���ĺ�����Ϊ������
nested = [[1,2],[3,4],[5]]  ##����������ʱ���������еĴ��벻��ִ�У�
for num in flatten(nested): ##���Ƿ���һ����������
    print num
'''
#�˻ʺ�����
"""
def conflict(state, nextX):
    nextY = len(state)
    for i in range(nextY):
        if abs(state[i] - nextX) in (0, nextY - i):
            return True
        return False
'''def queens(num, state):
    if len(state) == num-1:
        for pos in range(num):
            if not conflict(state, pos):
                yield pos
    else:
        for pos in range(num):
            if not conflict(state, pos):
                for result in queens(num, state + (pos,)):
                    yield (pos,) + result
print list(queens(4, (1,3,0)))'''
def queens(num = 8, state = ()):
    for pos in range(num):
         if not conflict(state, pos):
             if len(state) == num - 1:
                 yield (pos,)
    else:
        for result in queens(num,state+(pos,)):
            yield (pos,) + result
"""

