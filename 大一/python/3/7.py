#!/usr/bin/env python3
# -*- coding:utf-8 -*-

dic = {"P":"Pikachu","M":"Mickey Mouse","H":"Hello kitty"}
input1 = input("")

while input1 != "-1":
    if input1 in dic:
        print(dic[input1])
        input1 = input("")
    else:
        print(input1,"does not exist. Enter a new one:")
        intput_name = input("")
        dic[input1] = intput_name
        input1 = input("")