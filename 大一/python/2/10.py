#!/usr/bin/env python3
# -*- coding:utf-8 -*-

len1 = int(input(""))
len2 = int(input(""))
len3 = int(input(""))
list1 = [len1,len2,len3]
list1.sort()
a,b,c = list1

if a + b > c:
    print("True")
    if a*a + b*b == c*c :
        print("Right Triangle")
    else:
        print("Non-Right Triangle")
else:
    print("False")