#!/usr/bin/env python3
# -*- coding:utf-8 -*-

list1 = [[76,73,85],[88,84,76],[92,82,92],[82,91,85],[72,74,73]]
total = 0
list2 = []

for i,item in enumerate(list1):
    sum1 = 0
    print("student",i+1)
    for j in range(3):
        print(" ",j+1,": ",item[j],sep="")
        sum1 += item[j]
        total += item[j]
    avg = sum1/3
    list2.append(avg)
    print(" sum:",sum1)
    print(" avg: {0:.2f}".format(avg))
print("total: ",total,", avg: {0:.2f}".format(total/3/len(list1)),sep="")
position = list2.index(max(list2))
print("highest avg: student {0}: {1:.2f}".format(position+1,list2[position]))

