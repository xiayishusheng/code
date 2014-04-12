# -*- coding: cp936 -*-
# 1.11

## 字符串表示,str和repr
# 这里讨论的实际上是值被转换为字符串的两种机制，可以通过以下两个函数来实现这两种机制：
# 一：str函数，让字符串更容易阅读
# 二：repr会把结果字符串转换为合法的Python表达式

print repr("Hello, World!")
print repr(100000L)

print str("Hello, World!")
print str(100000L)

# 如果希望打印一个包含数字的句子，那么repr()就很有用了
temp = 42
print "the temperature is " + repr(temp)


## input 和 raw_input 的比较
"""
name = input("What is your name?")
print "Hello, " + name + "!"
"""
# 上面的是一个合法的程序。input 会假设用户输入的是合法的Python表达式，如果以字符串(如："Tom")作为输入的名字是没问题的
# 然而，要求用户带着引号输入名字似乎有点过分，因此需要使用raw_input()函数，他会把输入当做原始数据放入字符串中。
# 除非对input有特别的需要，否则应该尽可能的使用raw_input()函数


## 长字符串、原始字符串 和 Unicode
# 长字符串
print '''This is a very long string.
It continues here.
And it's not over yet.
"Hello, World!"
Still here.'''

# 原始字符串
path = 'c:\nowhere'
print path
print 'c:\\nowhere'
print r'c:\nowhere' # 原始字符串以r开头

## Unicode字符串
# Python中普通字符串在内部是以8位ASCII码形式存储，而Unicode则存储为16位的Unicode字符
print u'Hello, World!'
