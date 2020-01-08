#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def charFreqLister(inputSTR):
    resultLIST = []
    freq = {}
    
    for x in inputSTR:
        freq[x] = inputSTR.count(x) 
        freq[x] = freq[x]/len(inputSTR)   
    for y in freq:
        resultLIST.append((freq[y], y))
    
    resultLIST.sort(key=lambda input:input[0], reverse=True)
    return resultLIST

if __name__== "__main__":
    inputSTR = input("輸入字串：")
    print(charFreqLister(inputSTR))
