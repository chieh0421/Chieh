#!/usr/bin/env python3
# -*- coding:utf-8 -*-

determine = int(input(""))

if determine == 1 or determine ==2:
    score = int(input(""))
    if score <= 100 and score >= 0:
        if determine == 1:
            if score >= 60:
                print("pass")
            else:
                print("fail")
        else:
            if score >= 70:
                print("pass")
            else:
                print("fail")
    else:
        print("score error")
else:
    print("roll error")
