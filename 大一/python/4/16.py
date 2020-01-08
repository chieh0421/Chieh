#!/usr/bin/env python3
# -*- coding:utf-8 -*-

list_str = []
list_len = []

input_str = input()

while input_str != "-1":
    list_str.append(input_str)
    list_len.append(len(input_str))
    input_str = input()
    
circle = input()
max_len = max(list_len)

for i in range(len(list_str)):
    if list_len[i] < max_len:
        for j in range(max_len-list_len[i]):
            list_str[i] += " "

for i in range(len(list_str)+2):
    if i == 0 or i == len(list_str)+1:
        for j in range(max_len+2):
            print(circle,end="")
        print("")
    else:
        print("{0}{1}{0}".format(circle,list_str[i-1]))