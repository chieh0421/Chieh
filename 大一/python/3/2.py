#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))
list1_num = input("")
list1_num = list1_num.strip()
list1 = list1_num.split(" ",num-1)
list1.reverse()

for i in list1:
    print(i,end=" ")
print("")