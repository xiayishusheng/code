# -*- coding: utf-8 -*-
#!/usr/bin/Python
import math
"""
filter()函数是 Python 内置的另一个有用的高阶函数，filter()函数接收一个函数 f 和一个list，这个函数 f 的作用是对每个元素进行判断，返回 True或 False，filter()根据判断结果自动过滤掉不符合条件的元素，返回由符合条件元素组成的新list。
"""

"""
例如，要从一个list [1, 4, 6, 7, 9, 12, 17]中删除偶数，保留奇数，首先，要编写一个判断奇数的函数
"""
def is_odd(x):
    return x % 2 == 1
print filter(is_odd, [1, 4, 6, 7, 9, 12, 17])

"""
利用filter()，可以完成很多有用的功能，例如，删除 None 或者空字符串
"""
def is_not_empty(s):
    return s and len(s.strip()) > 0
print filter(is_not_empty, ['test', None, '', 'str', '  ', 'END'])

"""
请利用filter()过滤出1~100中平方根是整数的数，即结果应该是
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
"""
def is_sqr(x):
    r = int(math.sqrt(x))
    return r*r == x
print filter(is_sqr, range(1, 101))

