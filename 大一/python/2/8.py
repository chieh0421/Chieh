#!/usr/bin/env python3
# -*- coding:utf-8 -*-

sum1 = 0

maxnum = int(input(""))

for i in range(maxnum):
    print(i+1,sep='',end='')
    if i+1 != maxnum:
        print("+",sep='',end='')
    else:
        print(" = ",sep='',end='')
    sum1 += i + 1

print(sum1)