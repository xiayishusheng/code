# -*- coding: cp936 -*-
#第四章 字典：当索引不好用时

#字典由多个键及与其对应的值构成的键值对组成，键和值用冒号(:)分开，项之间用逗号(,)分开，整个字典用一个打括号括起来
"""
phonebook = {'Alice':'2341','Beth':'9102','Cecil':'3258'}
print phonebook['Alice']
"""

#字典示例
#使用人名作为键的字典，每个人用另外一个字典表示，其键'phone'和'addr'分别表示他们的电话和地址
"""
people = {
    'Cholland':{
        'phone':'13524289827',
        'addr':'上海'
    },

    'Dpaul':{
        'phone':'15138006048',
        'addr':'北京'
    },

    'Mary':{
        'phone':'13836873457',
        'addr':'广东'
    }
}
#针对电话号码和地址使用的描述标签，在打印输出的时候用到
labels = {
    'phone':'电话号码',
    'addr':'家庭住址'
}
#要查找人名
name = raw_input('Name:')
#查找电话号码还是地址？
request = raw_input('Phone number (p) or address (a)?')
#使用正确的键
if request == 'p' : key = 'phone'
if request == 'a' : key = 'addr'
#如果名字是字典中的有效键才打印信息
if name in people :
    print "%s的%s是:%s." % (name,labels[key],people[name][key])
else :
    print '没有此人!!'
"""

#模板系统中使用字典  如处理HTML
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
