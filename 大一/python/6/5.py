#!/usr/bin/env python3
# -*- coding:utf-8 -*-

import time

time_1 = float(input(""))
print (time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime(time_1)))
print (time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(time_1)))