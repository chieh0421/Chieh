#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))

if num%12 != 0:
    print("{0} dozen and {1}".format(num//12,num%12))
else:
    print("{0} dozen".format(num//12))