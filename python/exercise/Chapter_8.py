# -*- coding: cp936 -*-
#�ڰ��� �쳣

import exceptions

'''
#raise Exception  ���쳣
print dir(exceptions) #�ڽ��쳣
'''

#��׽�쳣
'''
try:
    x = input('Input the first number: ')
    y = input('Input the second number: ')
    print x / y
#except ZeroDivisionError:
except (ZeroDivisionError, TypeError),e:
    print e
'''

#�޲�raise  �����׽�����쳣��������������������(Ҳ���Ǵ����쳣)����ô���Ե��ò���������raise
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

