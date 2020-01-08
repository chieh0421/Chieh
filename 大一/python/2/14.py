#!/usr/bin/env python3
# -*- coding:utf-8 -*-

count = -1
score = total =0
maxnum = score

while score != -1:
    count += 1
    total += score
    if score > maxnum:
        position = count
        maxnum = score
    score = int(input(""))

print(total)
print("{0:.1f}".format(total/count))
print(maxnum)
print(position)