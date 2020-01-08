#!/usr/bin/env python3
# -*- coding:utf-8 -*-


f = open("./stores_old.csv","r",encoding='big5')
output = f.readlines()
f.close()
output = [x.split(",") for x in output]
index_sid = output[0].index("sid")
index_name= output[0].index("name")
index_tel=output[0].index("tel")
index_wifi=output[0].index("wifi")
fo = open("./stores_new.csv","w",encoding="utf-8")
for i in output:
    i = "{},{},{},{},\n".format(i[index_sid],i[index_name],i[index_tel],i[index_wifi]) 
    fo.write(i)
fo.close()
fo = open("./stores_new.csv","r",encoding="utf-8")
for i in fo.readlines():
    i = i.strip()
    print(i)
fo.close()