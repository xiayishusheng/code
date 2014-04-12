# -*- coding: cp936 -*-
# 2.3 列表

# 改变列表
x = [1, 1, 1]
x[1] = 2
print x

# 删除元素
names = ['Tom', 'Lily', 'Lucy', 'Earl']
del names[2]
print names

# 分片赋值
name = list('Perl')
print name
name[2:] = list('ar')
print name

numbers = [1, 5]
numbers[1:1] = [2, 3, 4]
print numbers

# 2.3.3 列表方法
#     方法是一个与某些对象有紧密联系的函数，对象也可能是列表、数字，
# 也可能是字符串或其他类型的对象。一般来说，方法可以这样调用：
# 对象.方法(参数)

# 1.append 在列表末尾追加新的对象
lst = [1, 2, 3]
lst.append(4)
print lst

# 2.count 统计某个元素在列表中出现的次数
lst1 = ['to', 'be', 'or', 'not', 'to', 'be']
print lst1.count('to')

# 3.extend 用新的列表扩展原有的列表
lst_a = [1, 2, 3]
lst_b = [4, 5, 6]
lst_a.extend(lst_b)
print lst_a

# 4.index 用于从列表中找出某个值第一个匹配项的索引位置
knights = ["We", "are", "the", "knights", "who", "say", "hello"]
print knights.index("who")

# 5.insert 将对象插入到列表中
numbers = [1, 2, 3, 5, 6, 7]
numbers.insert(3, 'four')
print numbers

# 6.pop 移除列表中的一个元素(默认是最后一个)
x = [1, 2, 3]
x.pop()
print x
x.pop(0)
print x

# 7.remove 移除列表中某个值的第一个匹配项
x = ['to', 'be', 'or', 'not', 'to', 'be']
x.remove('be')
print x

# 8.reverse 将列表中的元素反向存放
x = [1, 2, 3]
x.reverse()
print x

# 9.sort 队列表进行排序
x = [4, 5, 2, 6, 7, 1]
x.sort()
print x