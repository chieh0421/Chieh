#!/usr/bin/env python3
# -*- coding:utf-8 -*-

shelf = ["Book1", "Book2", "Book6", "Book4", "Book5"]
shelf.append(shelf[2])
shelf[2] = "Book3"
print(shelf)