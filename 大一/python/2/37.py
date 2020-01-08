#!/usr/bin/env python3
# -*- coding:utf-8 -*-

money_103 = ['million','thousand','dollar']
money_num = ['zero','one','two','three','four','five','six','seven','eight','nine']
money_10n = ['zero','ten','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
money_11to19 = ['ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
money =input("")

while len(money) % 3 != 0:
    money = "0" + money

for i in range(len(money) //3):
    for j in range(3):
        if money[3*i+j] == "0":
            continue
        if j == 0:
            print(money_num[int(money[3*i+j])],"hundred",end=" ")
        if j == 1:
            if money[3*i+j] == "1":
                print(money_11to19[int(money[3*i+j+1])],end=" ")
                break
            else:
                print(money_10n[int(money[3*i+j])],end=" ")
        if j == 2:
            print(money_num[int(money[3*i+j])],end=" ")
    print(money_103[i-len(money)//3],end="")
    if i != len(money)//3 - 1:
        print(" ",end="")
        
if int(money) > 1:
    print("s")
else:
    print("")