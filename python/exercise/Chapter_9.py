# -*- coding: cp936 -*-
#第九章 魔法方法、属性和迭代器

#   在Python中，有的名称会在前面和后面都加上两个下划线，这种写法有特殊的含义，所以不要在
#程序中使用这样的名字。在Python中，由这些名字组成的集合所包含的方法称为魔法方法或特殊方法。

#构造方法   __init__ 即为构造函数
'''
class FooBar:
    def __init__(self, value):
        self.somevar = value

f = FooBar('Hello World!!')
print f.somevar
'''

#重写一般方法和特殊的构造方法
'''
##如果在实例中调用方法，但在该类中没有找到此方法，那么就会去的他的超类中找
class A:
    def hello(self):
        print "Hello, I'm A."
class B(A): #B继承了A
    pass
a = A()
b = B()
a.hello()
b.hello() #b实例中没有hello()方法，就去A类里面找
##可以重写A类的hello()方法
class C(A):
    def hello(self):
        print "Hello, I'm C."
c = C()
c.hello()
'''

#重写构造方法的例子  如果一个类的构造方法被重写，那么就需要调用超类的构造方法，否则对象不能被正确的初始化
"""
'''
class Bird: #这个类定义所有的鸟都具有一些基本的能力：吃
    def __init__(self):
        self.hungry = True
    def eat(self):
        if self.hungry:
            print '我很饿,要吃饭!'
            self.hungry = False
        else:
            print "不用了,我吃饱了!"
            self.hungry = True
b = Bird()
b.eat()
b.eat()
b.eat()
b.eat()
## 子类SongBird，为他添加唱歌的行为
class SongBird(Bird):
    def __init__(self):
        self.sound = "同一首歌!"
    def sing(self):
        print self.sound
sb = SongBird()
sb.sing()
##因为SongBird是Bird的子类，他继承了eat()方法，但是如果调用eat()方法，就会出错
#sb.eat()
##  抛出的异常清楚的说明了问题的所在：SongBird没有hungry属性。
##原因是是这样的：在SongBird中，构造方法被重写，但是新的构造方法没有任何关于初始化hungry
##的属性的代码。为了达到预期的效果，SongBird的构造方法必须调用其超类Bird的构造方法来确保
##进行基本的初始化。
##有两种方法能达到这个目的：1、调用超类构造方法的未绑定版本
##                       2、使用super函数

#1、调用超类构造方法的未绑定版本
class SongBird(Bird):               ##  为什么会有这样的结果？在调用一个实例的方法时，
    def __init__(self):             ##该方法的self参数会被自动绑定到实例上。但是，如果
        Bird.__init__(self)         ##直接调用类的方法，那么就没有实例被绑定。这样就可以
        self.sound = "海上生明月"    ##自由的提供需要的self参数。这样的方法称为未绑定(unbound)
    def sing(self):                 ##方法。
        print self.sound            ##
sb = SongBird()                     ##
sb.sing()                           ##
sb.eat()                            ##
sb.eat()                            ##
'''

#2、使用super函数
'''
##下面的例子是对Bird例子的更新
__metaclass__ = type #super函数只在新模式类中起效
class Bird:
    def __init__(self):
        self.hungry = True
    def eat(self):
        if self.hungry:
            print "我饿了，要吃饭！"
            self.hungry = False
        else:
            print "不用了，我吃饱了！"
            self.hungry = True
class SongBird(Bird):
    def __init__(self):
        super(SongBird, self).__init__()
        self.sound = "墨明棋妙"
    def sing(self):
        print self.sound
sb = SongBird()
sb.sing()
sb.eat()
'''
"""

#静态方法和类成员方法
"""
##  静态方法和类成员方法在创建时分别被装入Sraticmethod类型和Classmethod类型的对象中
##静态方法没有self参数，且能被类本身直接调用。类方法在定义的时需要名为cls的类似于self的参数，
##类成员方法可以直接用类的具体对象调用，但cls参数是自动被绑定到类的。
'''__metaclass__ = type
class MyClass:
    def smeth():
        print 'This is a static method'
    smeth = staticmethod(smeth)
    def cmeth(cls):
        print 'This is a class method of',cls
    cmeth = classmethod(cmeth)'''
##  2.4版本后引入‘装饰器’的新语法(他能对任何可调用的对象进行包装，既能用于方法也能用于函数)
##使用@操作符，在方法活函数的上方将装饰器列出，从而指定一个或者更多的装饰器（多个装饰器在应用时的顺序和指定顺序相反）。
__metaclass__ = type
class MyClass:
    @staticmethod
    def smeth():
        print 'This is a static method'
    @classmethod
    def cmeth(cls):
        print 'This is a class method of',cls
MyClass.smeth()     #定义了这些方法后，就可以直接使用了（不用实例化类）
MyClass.cmeth()
"""

#迭代器    __iter__是迭代器规则(iertator protocol)的基础
##例子：斐波那契数列
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
##一个实现了__iter__方法的对象是可迭代的，一个实现了next方法的对象则是迭代器
fibs = Fibs()
for f in fibs:
    if f > 1000:    #查找在斐波那契数列中比1000打的数中的最小数
        print f
        break
'''

#从迭代器得到序列
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

#生成器
'''
def flatten(nested):
    for sublist in nested:
        for element in sublist:
            yield element   ##  包含yield语句的函数称为生成器
nested = [[1,2],[3,4],[5]]  ##当他被调用时，函数体中的代码不会执行，
for num in flatten(nested): ##而是返回一个迭代器。
    print num
'''
#八皇后问题
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

