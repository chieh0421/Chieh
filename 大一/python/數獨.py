#!/usr/bin/env python3
# -*- coding:utf-8 -*-


import os

def square_test(i,j,number):
    if number in square[i][j]:
        return False
    return True

def test(i,j,k,l,number):
    if (square_test(i, j, num)):
        return True
    return False

def print_sudoku():
    print("Solved Successfully!")
    for j in range_3:  
        for l in range_3:
            for i in range_3:
                for k in range_3:
                    print(sudoku[i][j][k][l],end=" ")
                if i!=3:
                    print("|",end=" ")
            print("")
        print("---------------------")

if __name__== "__main__":
    