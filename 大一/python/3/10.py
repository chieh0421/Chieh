#!/usr/bin/env python3
# -*- coding:utf-8 -*-

itemsA = {"蘋果", "香蕉", "鳳梨", "芭樂"}
itemsB = {"鳳梨", "蘋果", "水梨", "蓮霧"}
list1 = []

set1 = (itemsA.difference(itemsB)).union(itemsB.difference(itemsA))
list1 = list(set1)
list1.sort()    

print(list1)