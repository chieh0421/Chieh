#!/usr/bin/env python3
# -*- coding:utf-8 -*-

money = int(input(""))


if money <= 540000:
    print("5% {0:.0f} 0 {1:.0f} ".format(money*0.05,money*0.05))
elif money <= 1210000:
    print("12% {0:.0f} 37800 {1:.0f} ".format(money*0.12,money*0.12-37800))
elif money <= 2420000:
    print("20% {0:.0f} 134600 {1:.0f} ".format(money*0.2,money*0.2-134600))
elif money <= 4530000:
    print("30% {0:.0f} 376600 {1:.0f} ".format(money*0.3,money*0.3-376600))
elif money <= 10310000:
    print("40% {0:.0f} 829600 {1:.0f} ".format(money*0.4,money*0.4-829600))
else:
    print("45% {0:.0f} 1345100 {1:.0f} ".format(money*0.45,money*0.45-1345100))