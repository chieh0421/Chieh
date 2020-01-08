#!/usr/bin/env python3
# -*- coding:utf-8 -*-

ans = input()
guess = input()
len1 = len(ans)

while guess != ans:
    num_A = 0
    num_B = 0
    for i in range(len1):
        for j in range(len1):
            if guess[i] == ans[j]:
                if i == j:
                    num_A += 1
                else:
                    num_B += 1
        guess = guess.replace(guess[i]," ")
    print("{0}A{1}B".format(num_A,num_B))
    guess = input()
else:
    print("4A0B")
    print("You Win!")