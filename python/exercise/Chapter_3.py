# -*- coding: cp936 -*-

#第三章 字符串

from string import  Template

#格式化字符串
"""
format_string = "Hello %s! %s is hot!"
values = ('World','ShangHai')
print format_string % values

s = Template('$x,glorious $x!')
print s.substitute(x='slurm')

s = Template("It's ${x}tastic!!")
print s.substitute(x='slurm')
"""

#find方法 字符串.find('要查找的字符串',起始位置,结束位置)   返回字符串所在位置的最左端索引 找不到返回-1
"""
title = "Monty Python's Flying Circus"
print title.find('Monty')
print title.find('Python')
print title.find('zhen')
"""

#join方法 它是split方法的逆方法，用来在队列中添加元素
"""
sequence = ['1','2','3','4','5']
separator = '+'
print separator.join(sequence)

dirs = '/'+'usr','bin','env'
separator2 = '/'
print separator2.join(dirs)
"""

#split 将字符串分割为序列
"""
oringin_string = '1+2+3+4+5'
print oringin_string.split('+')
"""

#lower方法    返回字符串的小写字母
"""
hello = 'Hello World!!'
print hello.lower()
"""

#replace方法
"""
Name = 'My name is Tom'
print Name.replace('Tom','Lily')
"""

# strip方法返回去除两侧（不包括内部）空格的字符串 strip('字符') 去除指定的字符
"""
print '       nihao  !!! shi de  ???   '.strip()
"""


