# -*- coding: cp936 -*-
# ���� �� ʵ��

import os
import sys
'''
basedir = os.path.dirname(sys.argv[0])
print basedir
print os.path.join(basedir, 'zhen')
'''
#ģ�鼴����
sys.path.append('g:/python/module')
'''
import hello    ##  ����ģ��ʱ����ῴ�������ļ�����--������c:\python\hello.pyc��
                ##�����pycΪ��׺���ļ���(ƽ̨�޹ص�)����������ļ����Ѿ�ת����Python
                ##�ܹ���Ч������ļ�������Ժ���ͬһ��ģ�飬���ȵ���pyc�ļ�������py
                ##�ļ��Ѿ��ı�--��ʱ�������µ�pyc�ļ���ɾ��pyc�ļ�û��Ӱ�졣
'''
'''
import hello2
hello2.hello()
'''
'''
import hello3   #���в��Դ���ļ�ģ��
hello3.hello()
'''
'''
import hello4   #��������   �������Ϊ�������У�hello�����ᱻִ�У�����Ϊģ�鵼��ʱ����������ͨģ��
hello4.hello()
'''

#�����ģ�����
'''
import pprint
pprint.pprint(sys.path)
'''

#��  Ϊ����֯��ģ�飬���Խ����Ƿ���Ϊ��(package) ��ģ��洢���ļ���ʱ������ģ�����ڵ�Ŀ¼��Ϊ����Python������Ϊ���Դ������������һ����Ϊ__init__.py���ļ���ģ�飩�����������Ϊ��ͨģ�鵼��ܽ�ػ����ļ������ݾ��ǰ������ݡ�
#̽��ģ��
'''
import copy #������һ������copy�ı�׼ģ�飬import����û���쳣�����������ڣ�����������ʲô������ʲô��
print [n for n in dir(copy) if not n.startswith('_')]   #�б��Ƶ�ʽ���˵�dir(copy)�����»��߿�ͷ���б�
print copy.__all__
#print help(copy)
print copy.__doc__
print copy.__file__
'''

#��׼��
#print os.environ    #�鿴ϵͳ��������
print os.environ['JAVA_HOME']
print os.linesep
#os.system(r'c:\Windows\System32\notepad.exe')
os.startfile(r'c:\Windows\System32\notepad.exe')
