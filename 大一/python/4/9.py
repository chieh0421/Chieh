#!/usr/bin/env python3
# -*- coding:utf-8 -*-

input1 = input()
while input1.isdigit() != 1:
    print("is not a number")
    input1 = input()
print("n=",input1,sep="")