#!/usr/bin/env python3
# -*- coding:utf-8 -*-

str1 = input()
str2 = input()

position = str1.find(str2)

while position != -1:
    print(position)
    position = str1.find(str2,position+1)

