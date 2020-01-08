#!/usr/bin/env python3
# -*- coding:utf-8 -*-

f = open("../app/sim.txt","r",encoding="gb2312")
for i in f.readlines():
    i= i.strip()
    print(i)
f.close()