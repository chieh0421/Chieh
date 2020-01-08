#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))

for i in range(num):
    for j in range(i+1):
        print("*",end='')
    print("")