#!/usr/bin/env python3
# -*- coding:utf-8 -*-

import math

original = int(input(""))
adjusted = math.sqrt(original)*10

print("Original: {0:.2f}".format(float(original)))
print("Adjusted: {0:.2f}(+{1:.0f})".format(adjusted,adjusted-original))