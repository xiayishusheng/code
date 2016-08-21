# -*- coding: utf-8 -*-
#!/usr/bin/python
"""
Python的函数不但可以返回int、str、list、dict等数据类型，还可以返回函数！
"""
def f():
    print 'call f()...'
    def g():
        print 'call g()...'
        return g
