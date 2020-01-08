#!/usr/bin/env python3
# -*- coding:utf-8 -*-

f= open("sheet.txt","r",encoding="big5")
for i in f.readlines():
    i = i.strip()
    print(i)
f.close()