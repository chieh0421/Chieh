#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))

for i in range(num):
    for j in range(num-i-1):
        print(" ",end="")
    for k in range(2*i+1):
        print("*",end="")
    print("")