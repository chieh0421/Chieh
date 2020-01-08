#!/usr/bin/env python3
# -*- coding:utf-8 -*-

main = 10
grade = int(input(""))


if grade >= 95:
    money = 2000
elif grade >= 90 and grade <= 94:
    money = 1000
elif grade >= 80 and grade <= 89:
    money = 500
else:
    money = 0
    
print("獎金 {0} 元".format(money))