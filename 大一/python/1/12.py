#!/usr/bin/env python3
# -*- coding:utf-8 -*-

head,foot = (input("").split(' '))
head = int(head)
foot = int(foot)
determine = (4*head-foot)%2
chicken_num = (4*head-foot)//2
rabbit_num = head - chicken_num

if determine == 0 and chicken_num >= 0 and rabbit_num >= 0:
    print("YES")
    print(chicken_num,rabbit_num)
else:
    print("NO")