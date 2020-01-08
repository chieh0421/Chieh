#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))

for i in range(num):
    for j in range(num-i-1):
        print(" ",end="")
    for j in range(i+1):
        print("*",end="")
        if j != i :
            print(" ",end="")
    print("")