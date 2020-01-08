#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = input("")
list1 = []

while num != "q":
    if num.isalpha() == True:
        print("Please Enter Numbers Only")
        num = input("")
        continue
    list1.append(eval(num))
    num = input("")
list2 = list1[:]
print(list1)
list1.sort()
print(list1)
list1.sort(reverse= True)
print(list1)
print(list2)
    