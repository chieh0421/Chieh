#!/usr/bin/env python3
# -*- coding:utf-8 -*-

initial = int(input())
d = int(input())
num = int(input())
total = 0

for i in range(num):
    now_num = initial+i*d
    if now_num >= 0:
        print(now_num,end="")
    else:
        print("({0})".format(now_num),end="")
    total += now_num
    if i != num-1:
        print(" + ",end="")
    else:
        print(" =",total)