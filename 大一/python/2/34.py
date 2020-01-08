#!/usr/bin/env python3
# -*- coding:utf-8 -*-

height = int(input(""))
length = int(input(""))

for i in range(1,height+1):
    for j in range(1,length+1):
        print("{0}*{1}={2:2d} ".format(i,j,i*j),end="")
    print("")