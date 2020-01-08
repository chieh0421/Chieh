#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def key1(x):
    return x[1]
def key0(x):
    return x[0]

math_pass = {"柯南","灰原","步美","美環","光彦"}
english_pass = {"柯南","灰原","丸尾","野口","步美"}

only_math = math_pass.difference(english_pass)
only_eng = english_pass.difference(math_pass)
all_pass = math_pass.intersection(english_pass)

only_math = list(only_math)
only_eng = list(only_eng)
all_pass = list(all_pass)
only_math.sort(key = key1)
only_eng.sort(key = key1,reverse=True)
all_pass.sort(key = key0,reverse=False)

print(only_math)
print(only_eng)
print(all_pass)