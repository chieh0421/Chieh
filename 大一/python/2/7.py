#!/usr/bin/env python3
# -*- coding:utf-8 -*-

sum1 = float(input(""))
sum2 = float(input(""))
input1 = input("")

if input1 == "+":
    print("{0:.2f} + {1:.2f} = {2:.2f}".format(sum1,sum2,sum1+sum2))
elif input1 == "-":
    print("{0:.2f} - {1:.2f} = {2:.2f}".format(sum1,sum2,sum1-sum2))
elif input1 == "*":
    print("{0:.2f} * {1:.2f} = {2:.2f}".format(sum1,sum2,sum1*sum2))
elif input1 == "/":
    print("{0:.2f} / {1:.2f} = {2:.2f}".format(sum1,sum2,sum1/sum2))