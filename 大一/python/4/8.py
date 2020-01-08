#!/usr/bin/env python3
# -*- coding:utf-8 -*-

line1 = "Welcome to Python World Game."
line2 = "Can you can a can as a canner can can a can?"
line3 = "Few free fruit flies fly from flames."
line4 = "Czngrxtulxtizns, yzu hxve pxssed the czmpetitizn."

list1 = line1.split(" ")
num2 = line2.count("a")
position3 = line3.find("fly")
line4_new = line4.replace("z","o")
line4_new = line4_new.replace("x","a")

print(line1,list1,line2,num2,line3,position3,line4,line4_new,sep="\n")