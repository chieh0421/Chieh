#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def guessnum(minnum,maxnum):
    return int(input("%d < ? < %d\n"%(minnum,maxnum)))
    
if __name__ == "__main__":
    maxnum = 100
    minnum = 1
    answer = int(input(""))
    guess = guessnum(minnum,maxnum)
    while guess != answer:
        if guess <= maxnum and guess >= minnum:
            if guess > answer:
                maxnum = guess
                print("wrong answer, guess smaller")
            else:
                minnum = guess
                print("wrong answer, guess larger")
            guess = guessnum(minnum,maxnum)
            continue            
        else:
            print("超出範圍")
            guess = guessnum(minnum,maxnum)
            continue
    else:
        print("bingo answer is %d"%answer)