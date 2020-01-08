#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def N_function(n):
    sum1 = 1
    for i in range(n):
        sum1 *= (i+1)
    sum2 = (1+n)*n/2
    print(sum1)
    print(int(sum2))

n = int(input())
N_function(n)