#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))
sum1 = 1

for i in range(num):
    for j in range (i+1):
        print(sum1,end='')
        sum1 += 1
        if j != i:
            print(" ",end='')
        else:
            print(" ")
