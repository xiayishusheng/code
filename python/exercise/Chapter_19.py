# -*- coding: cp936 -*-
#第十九章 好玩的编程

#使用ConfigParser的程序 简单的配置文件
'''
from ConfigParser import ConfigParser

CONFIGFILE = "PythonConfig.txt"
config = ConfigParser()
#读取配置文件
config.read(CONFIGFILE)
#打印初始问候语，要查看是‘message’区段
print config.get('messages','greeting')
#使用配置文件的一个问题读取半径
radius = input(config.get('messages','question') + ' ')
#打印配置文件中的结果信息，以逗号结束，在同一行显示
print config.get('messages','result_message')
#getfloat()将config值转换为float类型
print config.getfloat('numbers','pi') * radius ** 2
'''

#日志记录
'''
import logging

logging.basicConfig(level=logging.INFO,filename='PythonLog.log')
logging.info('Starting program...')
logging.info('Trying to divide 1 by 0')
print 1 / 0
logging.info('The division succeeded')
logging.info('Ending program...')
'''
