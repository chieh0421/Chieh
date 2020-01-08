#!/usr/bin/env python3
# -*- coding:utf-8 -*-

class pokemon:
    
    def __init__(self,string_name,Lv,HpMax):
        self.__name = string_name
        self.__Lv = int(Lv)
        self.__HpMax = int(HpMax)
        self.__HPCurrent = int(HpMax)
        
    def show_info(self):
        print("Name:",self.__name)
        print("Lv:",self.__Lv)
        print("HP: {0}/{1}".format(self.__HPCurrent,self.__HpMax))
        
    def attack(self,other):
        print("{} Attack {} {} Points.".format(self.__name,other.__name,self.__Lv))
        if other.__HPCurrent <= self.__Lv:
            other.__HPCurrent = 0
            break
        else:
            other.__HPCurrent -= self.__Lv


num = int(input())
for i in range(num):
    enemy = pokemon(Mewtwo,30,300)
    string_name = input()
    Lv = input()
    HpMax = input()
    ally = pokemon(string_name, Lv, HpMax)
    print("#{}".format(i+1))
    while 1:
        ally.attack(enemy)
        enemy.attack(ally)
    if ally._pokemon__HPCurrent ==0:
        print("{} Seriously Injured.".format(ally._pokemon__name))
        print("{} Win, {} Lose.".format(enemy._pokemon__name,ally._pokemon__name))
        print("{} is unable to attack.".format(ally._pokemon__name))
    else:
        print("{} Seriously Injured.".format(enemy._pokemon__name))
        print("{} Win, {} Lose.".format(ally._pokemon__name,enemy._pokemon__name))
        print("{} is unable to attack.".format(enemy._pokemon__name))
    enemy.show_info()
    ally.show_info()
    print("")
    