#!/usr/bin/env python3
# -*- coding:utf-8 -*-

intab = "123456789"
outtab = "壹貳參肆伍陸柒捌玖"
transtab = str.maketrans(intab,outtab)

num = str(input(""))
num = num.translate(transtab)

if len(num) == 5:
    print(num[0],"萬",num[1],"仟",num[2],"佰",num[3],"拾",num[4],"元整",sep="")
elif len(num) == 4:
    print(num[0],"仟",num[1],"佰",num[2],"拾",num[3],"元整",sep="")
elif len(num) == 3:
    print(num[0],"佰",num[1],"拾",num[2],"元整",sep="")
elif len(num) ==2:
    print(num[0],"拾",num[1],"元整",sep="")
else:
    print(num[0],"元整",sep="")