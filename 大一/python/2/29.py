#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))

for i in range(num-1):
    print(" ",end="")
print("*")

for i in range(num-2):
    for j in range(3):
        for k in range(num-1-i-j):
            print(" ",end="")        
        for k in range(2*i+2*j+1):
            print("^",end="")
        print("")

for i in range(num-2):
    for j in range(num//2+1):
        print(" ",end="")
    for j in range(num-2):
        print("#",end="")
    print("")