#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))
list1 = [int(x) for x in input().split()]
max_num = max(list1)
max_position = list1.index(max_num) + 1
min_num = min(list1)
min_position = list1.index(min_num) + 1
print(max_position,max_num)
print(min_position,min_num)