#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))
list1 = []
for i in range(num):
    print("data",num-i)
    add = "data " + str(num-i)
    list1.append(add)

print("")

for i in range(num):    
    print(list1.pop())