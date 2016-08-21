# -*- coding: cp936 -*-
# 测试 和 实验

import os
import sys
'''
basedir = os.path.dirname(sys.argv[0])
print basedir
print os.path.join(basedir, 'zhen')
'''
#模块即程序
sys.path.append('g:/python/module')
'''
import hello    ##  导入模块时，你会看到有新文件出现--本例是c:\python\hello.pyc，
                ##这个以pyc为后缀的文件是(平台无关的)经过编译的文件，已经转换成Python
                ##能够有效处理的文件。如果稍后导入同一个模块，优先导入pyc文件，除非py
                ##文件已经改变--此时会生成新的pyc文件。删除pyc文件没有影响。
'''
'''
import hello2
hello2.hello()
'''
'''
import hello3   #带有测试代码的简单模块
hello3.hello()
'''
'''
import hello4   #条件测试   如果它作为程序运行，hello函数会被执行，而作为模块导入时，它就是普通模块
hello4.hello()
'''

#让你的模块可用
'''
import pprint
pprint.pprint(sys.path)
'''

#包  为了组织好模块，可以将他们分组为包(package) 当模块存储在文件中时包就是模块所在的目录。为了让Python将其作为包对待，它必须包含一个名为__init__.py的文件（模块），如果将它作为普通模块导入芙蓉话，文件的内容就是包的内容。
#探究模块
'''
import copy #假设有一个叫做copy的标准模块，import进来没有异常，所以它存在，但是他能做什么？它有什么？
print [n for n in dir(copy) if not n.startswith('_')]   #列表推导式过滤掉dir(copy)中以下划线开头的列表
print copy.__all__
#print help(copy)
print copy.__doc__
print copy.__file__
'''

#标准库
#print os.environ    #查看系统环境变量
print os.environ['JAVA_HOME']
print os.linesep
#os.system(r'c:\Windows\System32\notepad.exe')
os.startfile(r'c:\Windows\System32\notepad.exe')
