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
        return average
    
    def fcount(self):
        fail_count = 0
        for i in self.grades:
            if i < 60:
                fail_count += 1
        return fail_count
    
    def list_one(self):
        print("Name:",self.name)
        print("Gender:",self.gender)
        print("Grades:",self.grades)
        print("Avg: {0:.1f}".format(self.avg()))
        print("Fail Number:",self.fcount())
        print("")
        
def TOP(turple):
    max1 = 0
    who = ""
    for i in turple:
        if i.avg() > max1:
            max1 = i.avg()
            who = i
    print("Top Student:")
    who.list_one()

s1 = student("Tom","M")
s2 = student("Jane","F")
s3 = student("John","M")
s4 = student("Ann","F")
s5 = student("Peter","M")
s1.add(80)
s1.add(90)
s1.add(55)
s1.add(77)
s1.add(40)
s2.add(58)
s2.add(87)
s3.add(100)
s3.add(80)
s4.add(40)
s4.add(55)
s5.add(60)
s5.add(60)
s1.list_one()
s2.list_one()
s3.list_one()
s4.list_one()
s5.list_one()
t1 = {s1,s2,s3,s4,s5}
TOP(t1)


