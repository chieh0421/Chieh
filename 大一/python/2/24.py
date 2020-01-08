#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))

for i in range(num):
    for k in range(i):
        print(" ",end = '')
    for j in range(num-i):
        print("*",end='')
    print("")