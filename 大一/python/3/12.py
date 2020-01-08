#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input())
list1 =[]
total = 0

while num != -1:
    list1.append(num)
    if num > 30:
        total += num
    num = int(input())
print(list1)
list1.sort()
print(list1)
print(total)