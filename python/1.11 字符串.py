# -*- coding: cp936 -*-
# 1.11

## �ַ�����ʾ,str��repr
# �������۵�ʵ������ֵ��ת��Ϊ�ַ��������ֻ��ƣ�����ͨ����������������ʵ�������ֻ��ƣ�
# һ��str���������ַ����������Ķ�
# ����repr��ѽ���ַ���ת��Ϊ�Ϸ���Python���ʽ

print repr("Hello, World!")
print repr(100000L)

print str("Hello, World!")
print str(100000L)

# ���ϣ����ӡһ���������ֵľ��ӣ���ôrepr()�ͺ�������
temp = 42
print "the temperature is " + repr(temp)


## input �� raw_input �ıȽ�
"""
name = input("What is your name?")
print "Hello, " + name + "!"
"""
# �������һ���Ϸ��ĳ���input ������û�������ǺϷ���Python���ʽ��������ַ���(�磺"Tom")��Ϊ�����������û�����
# Ȼ����Ҫ���û������������������ƺ��е���֣������Ҫʹ��raw_input()��������������뵱��ԭʼ���ݷ����ַ����С�
# ���Ƕ�input���ر����Ҫ������Ӧ�þ����ܵ�ʹ��raw_input()����


## ���ַ�����ԭʼ�ַ��� �� Unicode
# ���ַ���
print '''This is a very long string.
It continues here.
And it's not over yet.
"Hello, World!"
Still here.'''

# ԭʼ�ַ���
path = 'c:\nowhere'
print path
print 'c:\\nowhere'
print r'c:\nowhere' # ԭʼ�ַ�����r��ͷ

## Unicode�ַ���
# Python����ͨ�ַ������ڲ�����8λASCII����ʽ�洢����Unicode��洢Ϊ16λ��Unicode�ַ�
print u'Hello, World!'
