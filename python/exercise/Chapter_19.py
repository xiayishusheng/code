# -*- coding: cp936 -*-
#��ʮ���� ����ı��

#ʹ��ConfigParser�ĳ��� �򵥵������ļ�
'''
from ConfigParser import ConfigParser

CONFIGFILE = "PythonConfig.txt"
config = ConfigParser()
#��ȡ�����ļ�
config.read(CONFIGFILE)
#��ӡ��ʼ�ʺ��Ҫ�鿴�ǡ�message������
print config.get('messages','greeting')
#ʹ�������ļ���һ�������ȡ�뾶
radius = input(config.get('messages','question') + ' ')
#��ӡ�����ļ��еĽ����Ϣ���Զ��Ž�������ͬһ����ʾ
print config.get('messages','result_message')
#getfloat()��configֵת��Ϊfloat����
print config.getfloat('numbers','pi') * radius ** 2
'''

#��־��¼
'''
import logging

logging.basicConfig(level=logging.INFO,filename='PythonLog.log')
logging.info('Starting program...')
logging.info('Trying to divide 1 by 0')
print 1 / 0
logging.info('The division succeeded')
logging.info('Ending program...')
'''
