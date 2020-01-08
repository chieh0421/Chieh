#!/usr/bin/env python3
# -*- coding:utf-8 -*-

score = int(input(""))

if score >= 90:
    print("4.3")
    print("A+")
elif score >= 85:
    print("4.0")
    print("A")
elif score >= 80:
    print("3.7")
    print("A-")
elif score >= 77:
    print("3.3")
    print("B+")
elif score >= 73:
    print("3.0")
    print("B")
elif score>= 70:
    print("2.7")
    print("B-")
elif score>= 67:
    print("2.3")
    print("C+")
elif score>= 63:
    print("2.0")
    print("C")
elif score>= 60:
    print("1.7")
    print("C-")
else:
    print("0")
    print("F")