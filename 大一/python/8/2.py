#!/usr/bin/env python3
# -*- coding:utf-8 -*-

while 1:
    try:
        a = eval(input())
        b = int(input())
        c = a/b
    except NameError:
        print("NameError")
    except ValueError:
        print("ValueError")
    except ZeroDivisionError:
        print("ZeroDivisionError")
    else:
        print("{0}/{1} = {2:.2f}".format(a,b,c))
        break