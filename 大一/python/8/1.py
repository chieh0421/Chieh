#!/usr/bin/env python3
# -*- coding:utf-8 -*-

class student:
    def __init__(self,name,gender):
        self.name = name
        self.gender = gender
        self.grades = []
        
    def add(self,grade):
        self.grades.append(grade)
    
    def avg(self):
        sum1 = 0
        for i in self.grades:
            sum1 += i
        average = sum1 / len(self.grades)
        return "{0:.2f}".format(average)
    
    def fcount(self):
        fail_count = 0
        for i in self.grades:
            if i < 60:
                fail_count += 1
        return fail_count

name = input()
gender = input()
s1 = student(name, gender)
for i in range(3):
    s1.add(int(input()))
print(s1.name)
print(s1.avg())
print(s1.fcount())