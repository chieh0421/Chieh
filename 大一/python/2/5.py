#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num1 = int(input(""))
cal = num1 // 4 + num1 % 4
result = num1 + num1 // 4

while cal>= 4 :
    result += cal//4
    cal = cal // 4 + cal % 4
    
else:
    if cal == 3:
        result += 1
    else:
        pass
    print(result)
