#!/usr/bin/env python3
# -*- coding:utf-8 -*-

str1 = str(input())
if str1.isdigit() == 1:
    print(str1,"is a number.")
elif str1.isupper() == 1:
    print(str1,"is a capital letter.")
elif str1.islower() == 1:
    print(str1,"is a lowercase letter.\nswap to capital letter {0}.".format(str1.upper()))
else:
    print(str1,"is a punctuation.")