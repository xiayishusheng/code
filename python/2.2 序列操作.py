# -*- coding: cp936 -*-
## 2.2 序列操作

# 索引
greeting = 'Hello'
print "greeting = %s" % greeting
print "greeting[0] = %s" % greeting[0]
print "greeting[-1] = %s" % greeting[-1]

# 分片 分片操作需要提供两个索引作为边界，
# 第一个索引的元素是包含在分片内的，而第二个则不包含在分片内
numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
print numbers[3 : 6]

# 序列相加 两种相同类型的序列才能相加
print [1, 2, 3] + [4, 5 ,6]
print 'Hello, ' + 'World!'

# 序列乘法
print 'Python, ' * 5
