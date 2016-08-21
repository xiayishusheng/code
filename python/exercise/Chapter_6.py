# -*- coding: cp936 -*-
#第6章 抽象
#懒惰即美德 (^_^)

import math

#函数 内建的callable函数可以用来判断函数是否可调用,如下例：x不可调用 y可以被调用。Python 3.0 中callable不能用，要使用hasattr(func,__call__)代替
'''
x = 1
y = math.sqrt
print callable(x),callable(y)
'''

#创建函数和调用函数   使用def 函数名(参数)来创建函数
'''
def hello(name):
    return 'Hello,' + name + '!'
print hello('Jim')
'''

#例子:计算斐波那契数列
"""
def fibs(num):
    #在函数的开头写下说明文字，他就会作为函数的一部分存储，这称为‘文档字符串’
    '''
    功能：计算斐波那契数列
    参数：num 要得到的数列长度
    '''
    result = [0,1]
    for i in range(num - 2):
        result.append(result[-2] + result[-1])
    return result
print fibs.__doc__  #打印‘文档字符串’
print help(fibs)    #内建函数help,可以得到关于函数，包括文档字符串的信息
print fibs(12)
"""

#收集参数
'''
def print_params(title,*params):
    print title , params
print_params('参数:', 1, 2, 3, 4, 5)
'''

#经典例子：阶乘
def factorial(n):   #使用循环实现
    result = n
    for i in range(1,n):
        result *= i
    return result

def factorial2(n):  #使用递归实现
    if n == 1:
        return 1
    else:
        return n * factorial2(n-1)

