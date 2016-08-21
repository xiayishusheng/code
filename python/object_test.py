# -*- coding: utf-8 -*-
#!/usr/bin/python

class Person():
    def __init__(self, name, gender, birth):
        self.name = name
        self.gender = gender
        self.birth = birth

xiaoming = Person('Xiao Ming', 'Male', '1989-11-03')
xiaohong = Person('Xiao Hong', 'Female', '1990-2-2')

print xiaoming.name
print xiaohong.birth
