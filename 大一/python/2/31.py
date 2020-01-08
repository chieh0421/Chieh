#!/usr/bin/env python3
# -*- coding:utf-8 -*-

num = int(input(""))


for k in range(2,num+1):
        if k == 2:
                print(k,"is prime")        
        else:
                for i in range(2,k):
                        if k % i == 0:
                                break
                else:
                        print(k,"is prime")

        
        