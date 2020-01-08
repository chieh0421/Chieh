#!/usr/bin/env python3
# -*- coding:utf-8 -*-

month = int(input(""))

if month >= 1 and month <= 12:
    if month >= 3 and month <= 5:
        print("Spring")
    elif month >= 6 and month <= 8:
        print("Summer")
    elif month >= 9 and month <= 11:
        print("Autumn")
    else:
        print("Winter")
else:
    print("Month doesn't exist!")