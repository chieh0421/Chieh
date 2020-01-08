#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def swap(listx):
    listx = listx[::-1]
    return listx
list1 = []
for i in range(2):
    list1.append(int(input()))
list1 = swap(list1)
for i in list1:
    print(i)