# -*- coding: cp936 -*-
#��6�� ����
#���輴���� (^_^)

import math

#���� �ڽ���callable�������������жϺ����Ƿ�ɵ���,��������x���ɵ��� y���Ա����á�Python 3.0 ��callable�����ã�Ҫʹ��hasattr(func,__call__)����
'''
x = 1
y = math.sqrt
print callable(x),callable(y)
'''

#���������͵��ú���   ʹ��def ������(����)����������
'''
def hello(name):
    return 'Hello,' + name + '!'
print hello('Jim')
'''

#����:����쳲���������
"""
def fibs(num):
    #�ں����Ŀ�ͷд��˵�����֣����ͻ���Ϊ������һ���ִ洢�����Ϊ���ĵ��ַ�����
    '''
    ���ܣ�����쳲���������
    ������num Ҫ�õ������г���
    '''
    result = [0,1]
    for i in range(num - 2):
        result.append(result[-2] + result[-1])
    return result
print fibs.__doc__  #��ӡ���ĵ��ַ�����
print help(fibs)    #�ڽ�����help,���Եõ����ں����������ĵ��ַ�������Ϣ
print fibs(12)
"""

#�ռ�����
'''
def print_params(title,*params):
    print title , params
print_params('����:', 1, 2, 3, 4, 5)
'''

#�������ӣ��׳�
def factorial(n):   #ʹ��ѭ��ʵ��
    result = n
    for i in range(1,n):
        result *= i
    return result

def factorial2(n):  #ʹ�õݹ�ʵ��
    if n == 1:
        return 1
    else:
        return n * factorial2(n-1)

