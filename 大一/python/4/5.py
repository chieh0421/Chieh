#!/usr/bin/env python3
# -*- coding:utf-8 -*-

str1 = str(input())
if str1.isdigit() == 1:
    print(str1,"is a number.")
elif str1.isupper() == 1:
    print(str1,"is a capital letter.")
elif str1.islower() == 1:
    print(str1,"is a lowercase letter.")
else:
    print(str1,"is a punctuation.")