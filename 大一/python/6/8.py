#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def func(a,b):
    sum1 = 1
    for i in range(a-b,a):
        sum1 *= i+1
    return sum1

num1 = int(input())
num2 = int(input())
result = func(num1,num2)
print(result)