#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# 繳交日期：2016.10.17

# 作業內容：
# 1. 請閱讀 Wikipedia 維基百科 IEEE754 條目 (https://zh.wikipedia.org/wiki/IEEE_754)

# 2. 請試玩 http://armorgames.com/play/17826/logical-element

# 3. 請利用以下空白範本設計一支程式。程式可輸入一段字串，並自動計算出字串中包括空白字元出現的機率。
#    並由高排到低。
def charFreqLister(inputSTR):
    resultLIST = []
    freq = {}
    
    for x in inputSTR:
        freq[x] = inputSTR.count(x) 
        freq[x] = freq[x]/len(inputSTR)   
    
    for y in freq:
        resultLIST.append((freq[y], y))
    
    resultLIST.sort(key=lambda input:input[0], reverse=False)
    return(resultLIST)

# 3.1 加分題 (有做有加分，沒做不扣分)：請用課堂中提到的「霍夫曼編碼]
#     (https://zh.wikipedia.org/wiki/霍夫曼編碼) 為你之前設計的
#     程式加上轉碼壓縮的功能。
# e.g.,
def huffmanTranslater(inputSTR):
    
    resultLIST = charFreqLister(inputSTR)
    while len(resultLIST) != 1:
        
    
    
    
    
    
    return resultLIST




#    resultLIST = [(freq, char, code), (freq, char, code), (freq, char, code),...]



if __name__ == "__main__":
    inputSTR = input("輸入字串：")
    print(huffmanTranslater(inputSTR))
