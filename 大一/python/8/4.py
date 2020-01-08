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
        else:
            other.__HPCurrent -= self.__Lv
        
    def Battle(self,other):
        while 1:
            self.attack(other)
            if other.__HPCurrent == 0:
                break
            other.attack(self)
            if self.__HPCurrent == 0:
                break
        if ally._pokemon__HPCurrent == 0:
            print("{} Seriously Injured.".format(ally.__name))
            print("{} Win, {} Lose.".format(enemy.__name,ally.__name))
            print("{} is unable to attack.".format(ally.__name))
        else:
            print("{} Seriously Injured.".format(enemy.__name))
            print("{} Win, {} Lose.".format(ally.__name,enemy.__name))
            print("{} is unable to attack.".format(enemy.__name))

num = int(input())
for i in range(num):
    enemy = pokemon("Mewtwo",30,300)
    string_name = input()
    Lv = input()
    HpMax = input()
    ally = pokemon(string_name, Lv, HpMax)
    print("#{}".format(i+1))
    ally.Battle(enemy)
    enemy.show_info()
    ally.show_info()
    print("")
    