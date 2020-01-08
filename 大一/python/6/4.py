#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def crossXY(listx,listy):
    for i,item in enumerate(listx):
        list_result = []
        for k in range(3):
            sum1 = 0
            for j in range(3):
                sum1 += item[j]*(listy[j])[k]
            list_result.append(sum1)
        for j in list_result:
            print("{0:<5d}".format(j),end="")
        print("")

list1 = []
list2 = []
for i in range(3):
    list1.append(input().split())
    list1[i] = [int(x) for x in list1[i]]

for i in range(3):
    list2.append(input().split())
    list2[i] = [int(x) for x in list2[i]]

crossXY(list1,list2)