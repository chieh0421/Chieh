#!/usr/bin/env python3
# -*- coding:utf-8 -*-


f = open("../app/stores_old.csv","r",encoding='big5')
output = f.readlines()
f.close()
output = [x.split(",") for x in output]
index_sid = output[0].index("sid")
index_name= output[0].index("name")
index_tel=output[0].index("tel")
index_wifi=output[0].index("wifi")
for i in output:
    print(i[index_sid],i[index_name],i[index_tel],i[index_wifi],sep=",",end=",\n")
