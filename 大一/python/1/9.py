#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num1 = int(input(""))
num2 = int(input(""))
num3 = int(input(""))

print("sum is",num1+num2+num3)
print("average is {0:.2f}".format((num1+num2+num3)/3))
print("product is",num1*num2*num3)
print("smallest is",min(num1,num2,num3))
print("largest is",max(num1,num2,num3))