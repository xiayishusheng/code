# -*- coding: cp936 -*-
# 2.3 �б�

# �ı��б�
x = [1, 1, 1]
x[1] = 2
print x

# ɾ��Ԫ��
names = ['Tom', 'Lily', 'Lucy', 'Earl']
del names[2]
print names

# ��Ƭ��ֵ
name = list('Perl')
print name
name[2:] = list('ar')
print name

numbers = [1, 5]
numbers[1:1] = [2, 3, 4]
print numbers

# 2.3.3 �б���
#     ������һ����ĳЩ�����н�����ϵ�ĺ���������Ҳ�������б����֣�
# Ҳ�������ַ������������͵Ķ���һ����˵�����������������ã�
# ����.����(����)

# 1.append ���б�ĩβ׷���µĶ���
lst = [1, 2, 3]
lst.append(4)
print lst

# 2.count ͳ��ĳ��Ԫ�����б��г��ֵĴ���
lst1 = ['to', 'be', 'or', 'not', 'to', 'be']
print lst1.count('to')

# 3.extend ���µ��б���չԭ�е��б�
lst_a = [1, 2, 3]
lst_b = [4, 5, 6]
lst_a.extend(lst_b)
print lst_a

# 4.index ���ڴ��б����ҳ�ĳ��ֵ��һ��ƥ���������λ��
knights = ["We", "are", "the", "knights", "who", "say", "hello"]
print knights.index("who")

# 5.insert ��������뵽�б���
numbers = [1, 2, 3, 5, 6, 7]
numbers.insert(3, 'four')
print numbers

# 6.pop �Ƴ��б��е�һ��Ԫ��(Ĭ�������һ��)
x = [1, 2, 3]
x.pop()
print x
x.pop(0)
print x

# 7.remove �Ƴ��б���ĳ��ֵ�ĵ�һ��ƥ����
x = ['to', 'be', 'or', 'not', 'to', 'be']
x.remove('be')
print x

# 8.reverse ���б��е�Ԫ�ط�����
x = [1, 2, 3]
x.reverse()
print x

# 9.sort ���б��������
x = [4, 5, 2, 6, 7, 1]
x.sort()
print x