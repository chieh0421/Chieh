#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))
list1 = []

while num != -1:
    list1.append(num)
    num = int(input(""))

list1.sort()
print(list1)
list1.insert(3,10)
print(list1)
print(list1.count(10))
list1.sort(reverse=True)
print(list1)