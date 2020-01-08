#!/usr/bin/env python3
# -*- coding:utf-8 -*-

import os

def print_(list1):
    list1.sort(key = lambda x :x[1])
    print(list1)

num = int(input())

os.mkdir("files")
os.chdir("files")

for i in range(num):
    os.mkdir("f{0}".format(i+1))  

print_(os.listdir("./"))

os.rename("f1","folder1")
print_(os.listdir("./"))

os.rmdir("folder1")
print_(os.listdir("./"))

for i in os.listdir("./"):
    os.rmdir(i)
os.chdir("../")
os.rmdir("files")