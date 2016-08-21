# -*- coding: cp936 -*-                            #  1
#为Python脚本添加行号                              #  2
                                                   #  3
import fileinput                                   #  4
                                                   #  5
for line in fileinput.input(inplace=True):         #  6
    line = line.rstrip()                           #  7
    num = fileinput.lineno()                       #  8
    print '%-50s # %2i' % (line,num)               #  9
