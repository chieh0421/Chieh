#!/usr/bin/env python3
# -*- coding:utf-8 -*-

str1 = input()
str2 = input()
if str1 > str2:
    print("1>2")
elif str1 == str2:
    print("1==2")
else:
    print("1<2")

print(str1,str2,sep="")
print(len(str1)+len(str2))