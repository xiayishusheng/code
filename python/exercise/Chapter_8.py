# -*- coding: cp936 -*-
#第八章 异常

import exceptions

'''
#raise Exception  抛异常
print dir(exceptions) #内建异常
'''

#捕捉异常
'''
try:
    x = input('Input the first number: ')
    y = input('Input the second number: ')
    print x / y
#except ZeroDivisionError:
except (ZeroDivisionError, TypeError),e:
    print e
'''

#无参raise  如果捕捉到了异常，但是又想重新引发它(也就是传递异常)，那么可以调用不带参数的raise
'''
class MuffledCalculator:
    muffled = False
    def calc(self, expr):
        try:
            return eval(expr)
        except ZeroDivisionError:
            if self.muffled:
                print 'Division by zero is illegal'
            else:
                raise

calculator = MuffledCalculator()
print calculator.calc('10 / 2')
calculator.muffled = True
print calculator.calc('10 / 0')
'''

