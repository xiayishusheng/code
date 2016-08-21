# -*- coding: cp936 -*-
#序列
"""
edward = ['Edward Gumby',42]
john = ['Jone Smith',50]
database = [edward,john]
print database
"""

#索引
"""
greeting = 'Hello'
print greeting[0]
print greeting[1]
print greeting[2]
print greeting[3]
print greeting[4]
print greeting[-1]
print greeting[-2]
print greeting[-3]
print greeting[-4]
print greeting[-5]
fourth = raw_input('Year: ')[3]
print fourth
"""

#分片 冒号分隔的索引
"""
tag = '<a herf="http://www.python.org">Python Web Site</a>'
print tag[9:30]
print tag[32:-4]
"""

#乘法
"""
print 'python '*5
print [3]*10
"""

#序列（字符串）乘法示例
"""
sentence = raw_input("Sentence: ")
screen_width = 80
text_width = len(sentence)
box_width = text_width + 10
left_margin = (screen_width -box_width) // 2
print
print ' '*left_margin + '+' + '-'*box_width + '+'
print ' '*left_margin + '|' + ' '*box_width + '|'
print ' '*left_margin + '|' + ' '*5 + sentence + ' '*5 + '|'
print ' '*left_margin + '|' + ' '*box_width + '|'
print ' '*left_margin + '+' + '-'*box_width + '+'
print
"""

#成员资格   使用“in”运算符
"""
permissions = 'rw'
print 'w' in permissions

users = ['mlh','foo','bar']
print 'foo' in users

database = [
    ['Tom','1234'],
    ['Jim','5678'],
    ['Lucy','2345']

]
username = raw_input('User name: ')
pin = raw_input('PIN code: ')
if [username,pin] in database :
    print 'Access granted!'
else :
    print 'No Permission!'
"""

#长度、最小值和最大值 内建函数len、min和max
"""
numbers = [100,34,678]
print len(numbers)
print min(numbers)
print max(numbers)
print min(9,5,6,7,2)
"""

#列表
"""
print list('Hello')

x = [1,1,1]
x[1] = 2
print x
del x[2]
print x
"""
#列表方法
"""
lst = ['hello','world','ni']
lst.append('hao')
print lst

x = [[1,2],1,1,[2,1,[1,2]]]
print x.count(1)
print x.count([1,2])

a = [1,2,3]
b = [4,5,6]
a.extend(b)
print a

colors = ['Purple','Black','Yellow','Green','Blue','Red','White']
print colors.index('Red')

x = [1,2,3]
x.reverse()
print x

x = [4,6,8,9,3,2]
x.sort()
print x
"""

#
