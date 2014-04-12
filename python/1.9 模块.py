# -*- coding: cp936 -*-
# 1.9 模块

import math
# math.floor() 将给定的值向下取整
print "math.floor(32.9) = %f" % math.floor(32.9)

from math import sqrt
print "sqrt(9) = %f" % sqrt(9)

# 使用变量引用函数
foo = math.sqrt
print foo(9)

# 负数的平方根
import cmath
print "cmath.sqrt(-1) = %s" % cmath.sqrt(-1)

print "(1 + 3j) * (9 + 4j) = %s" % ( (1 + 3j) * (9 + 4j) )
