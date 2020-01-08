#!/usr/bin/env python3
# -*- coding:utf-8 -*-

height = int(input(""))
weight = int(input(""))
BMI = weight / (height * height / 10000)
print("{0:.2f}".format(BMI))

if BMI < 18.5:
    print("Underweight")
elif BMI >= 18.5 and BMI < 24:
    print("Normal")
elif BMI >= 24 and BMI < 27:
    print("Overweight")
elif BMI >= 27 and BMI < 30:
    print("Obese Class I")
elif BMI >= 30 and BMI < 35:
    print("Obese Class II")
else:
    print("Obese Class III")