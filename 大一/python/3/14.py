#!/usr/bin/env python3
# -*- coding:utf-8 -*-

sum1 = 0
num1 = int(input())
list1 = input().split()
list1 = [int(x) for x in list1]
num2 = int(input())
list2 = input().split()
list2 = [int(x) for x in list2]
for i in list2:
    if i == 0:
        list1[i] = 0
        continue
    list1[i-1] = 0
for i in list1:
    sum1 += i
max_num = max(list1)
position = list1.index(max_num)
print(sum1)
print(position+1,max_num)