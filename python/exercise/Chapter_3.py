# -*- coding: cp936 -*-

#������ �ַ���

from string import  Template

#��ʽ���ַ���
"""
format_string = "Hello %s! %s is hot!"
values = ('World','ShangHai')
print format_string % values

s = Template('$x,glorious $x!')
print s.substitute(x='slurm')

s = Template("It's ${x}tastic!!")
print s.substitute(x='slurm')
"""

#find���� �ַ���.find('Ҫ���ҵ��ַ���',��ʼλ��,����λ��)   �����ַ�������λ�õ���������� �Ҳ�������-1
"""
title = "Monty Python's Flying Circus"
print title.find('Monty')
print title.find('Python')
print title.find('zhen')
"""

#join���� ����split�������淽���������ڶ��������Ԫ��
"""
sequence = ['1','2','3','4','5']
separator = '+'
print separator.join(sequence)

dirs = '/'+'usr','bin','env'
separator2 = '/'
print separator2.join(dirs)
"""

#split ���ַ����ָ�Ϊ����
"""
oringin_string = '1+2+3+4+5'
print oringin_string.split('+')
"""

#lower����    �����ַ�����Сд��ĸ
"""
hello = 'Hello World!!'
print hello.lower()
"""

#replace����
"""
Name = 'My name is Tom'
print Name.replace('Tom','Lily')
"""

# strip��������ȥ�����ࣨ�������ڲ����ո���ַ��� strip('�ַ�') ȥ��ָ�����ַ�
"""
print '       nihao  !!! shi de  ???   '.strip()
"""


