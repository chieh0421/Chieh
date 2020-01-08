#!/usr/bin/env python3
# -*- coding:utf-8 -*-

score = int(input(""))
char = "y"

while char == "y":
    if score >= 60:
        print("pass")
    else:
        print("fail")
    char = input("")
    if char == "y":
        score = int(input(""))
        continue