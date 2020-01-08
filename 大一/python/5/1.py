#!/usr/bin/env python3
# -*- coding:utf-8 -*-

total = 0

num_class = int(input())
num_people = int(input())

for i in range(num_class):
    sum1 = 0
    print("class",i+1)
    list1 = [int(x) for x in input().split()]
    for j,item in enumerate(list1):
        print(" {0}: {1}".format(j+1,item))
        sum1 += item
        total += item
    print(" sum: {0}\n avg: {1:.2f}".format(sum1,sum1/num_people))
print("total: {0}, avg: {1:.2f}".format(total,total/num_class/num_people))
    