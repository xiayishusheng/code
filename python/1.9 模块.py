# -*- coding: cp936 -*-
# 1.9 ģ��

import math
# math.floor() ��������ֵ����ȡ��
print "math.floor(32.9) = %f" % math.floor(32.9)

from math import sqrt
print "sqrt(9) = %f" % sqrt(9)

# ʹ�ñ������ú���
foo = math.sqrt
print foo(9)

# ������ƽ����
import cmath
print "cmath.sqrt(-1) = %s" % cmath.sqrt(-1)

print "(1 + 3j) * (9 + 4j) = %s" % ( (1 + 3j) * (9 + 4j) )
