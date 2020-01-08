#!/usr/bin/env python3
# -*- coding:utf-8 -*-

file_name = input()
f= open(file_name,"r",encoding="big5")
for i in f.readlines():
    i = i.strip()
    print(i)
f.close()