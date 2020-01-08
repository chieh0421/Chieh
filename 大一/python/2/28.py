#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))

for i in range(num):
    if i <= num//2:
        for k in range(num//2-i):
            print(" ",end="")
        for j in range(2*i+1):
            print("*",end="")
        print("")
    else:
        for k in range(i-num//2):
            print(" ",end="")
        for j in range(num-2*(i-num//2)):
            print("*",end="")
        print("")