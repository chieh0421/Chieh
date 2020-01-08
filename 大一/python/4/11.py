#!/usr/bin/env python3
# -*- coding:utf-8 -*-

sum1 = 0
sum2 = 0
sum3 = 0
num = int(input())
for i in range(num):
    str1 = input()
    if str1.islower() == 1:
        sum1 += 1
    elif str1.isupper() == 1:
        sum2 += 1
    else:
        sum3 += 1
print(sum1,sum2,sum3)