#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))

if num == 2:
    print(num,"is prime")
else:
    for i in range(2,num):
        if num % i == 0:
            print(num,"is not prime")
            break
        
    else:
        print(num,"is prime")
        
        