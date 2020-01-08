#!/usr/bin/env python3
# -*- coding:utf-8 -*-

str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dic = {}
for i,item in enumerate(str1):
    dic[item] = i+1
max_num = 0
num = int(input())
for i in range(num):
    sum1 = 0
    str1 = input().upper()
    for i in str1:
        sum1 += dic[i]
    if sum1 > max_num:
        max_num = sum1
        max_str = str1
    print("{0} = {1}".format(str1,sum1))
print("{0} is the key.".format(max_str))