# -*- coding: cp936 -*-
#������ �ֵ䣺������������ʱ

#�ֵ��ɶ�����������Ӧ��ֵ���ɵļ�ֵ����ɣ�����ֵ��ð��(:)�ֿ�����֮���ö���(,)�ֿ��������ֵ���һ��������������
"""
phonebook = {'Alice':'2341','Beth':'9102','Cecil':'3258'}
print phonebook['Alice']
"""

#�ֵ�ʾ��
#ʹ��������Ϊ�����ֵ䣬ÿ����������һ���ֵ��ʾ�����'phone'��'addr'�ֱ��ʾ���ǵĵ绰�͵�ַ
"""
people = {
    'Cholland':{
        'phone':'13524289827',
        'addr':'�Ϻ�'
    },

    'Dpaul':{
        'phone':'15138006048',
        'addr':'����'
    },

    'Mary':{
        'phone':'13836873457',
        'addr':'�㶫'
    }
}
#��Ե绰����͵�ַʹ�õ�������ǩ���ڴ�ӡ�����ʱ���õ�
labels = {
    'phone':'�绰����',
    'addr':'��ͥסַ'
}
#Ҫ��������
name = raw_input('Name:')
#���ҵ绰���뻹�ǵ�ַ��
request = raw_input('Phone number (p) or address (a)?')
#ʹ����ȷ�ļ�
if request == 'p' : key = 'phone'
if request == 'a' : key = 'addr'
#����������ֵ��е���Ч���Ŵ�ӡ��Ϣ
if name in people :
    print "%s��%s��:%s." % (name,labels[key],people[name][key])
else :
    print 'û�д���!!'
"""

#ģ��ϵͳ��ʹ���ֵ�  �紦��HTML
"""
template = '''<html>
<head><title>%(title)s</title></head>
<body>
<h1>%(title)s</h1>
<p>%(text)s</p>
</body>'''
data = {'title':'My Home Page','text':'Welcome to my home page!'}
print template % data
"""
