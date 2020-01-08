#!/usr/bin/env python3
# -*- coding:utf-8 -*-

list1 = []
list1 = input("").split(",")
sum1 = 0
sum2 = 0
sum3 = 0

for i in range(len(list1)):
    if int(list1[i]) % 2 == 1:
        sum1 += int(list1[i])
    if int(list1[i]) % 2 == 0:
        sum2 += int(list1[i])
    sum3 += int(list1[i])

print(sum1)
print(sum2)
print(sum3)