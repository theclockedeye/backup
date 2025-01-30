import numpy as np
import re
import random

def getIndex(a, b):
    if a in range(3):
        if b in range(3): return 0
        if b in range(3, 6): return 1
        if b in range(6, 9): return 2
    if a in range(3, 6):
        if b in range(3): return 3
        if b in range(3, 6): return 4
        if b in range(6, 9): return 5
    if a in range(6, 9):
        if b in range(3): return 6
        if b in range(3, 6): return 7
        if b in range(6, 9): return 8

def is_valid(matrix, row, col, num):
    # Check if num is not in the current row
    if num in matrix[row]:
        return False
    # Check if num is not in the current column
    if num in matrix[:, col]:
        return False
    # Check if num is not in the current 3x3 square
    square_index = getIndex(row, col)
    start_row, start_col = (square_index // 3) * 3, (square_index % 3) * 3
    if num in matrix[start_row:start_row+3, start_col:start_col+3]:
        return False
    return True

def solve_sudoku(matrix):
    # Find the next empty cell
    for row in range(9):
        for col in range(9):
            if matrix[row, col] == 0:
                for num in range(1, 10):
                    if is_valid(matrix, row, col, num):
                        matrix[row, col] = num
                        if solve_sudoku(matrix):
                            return True
                        matrix[row, col] = 0
                return False
    return True

matrix = np.zeros((9, 9), dtype=int)
flag = True
i = 0

# Reading input matrix from user
print("Enter the elements available in the order \"Row, Column, Value\"\nThe matrix is zero-indexed!!")
while flag:
    i += 1
    print(f"Element: {i}")
    ref = [int(x) for x in re.split(r'[ ,]', input("Enter r, c, value: ")) if x]
    if matrix[ref[0], ref[1]] != 0:
        print("Occupied!! Try another")
    else:
        matrix[ref[0], ref[1]] = ref[2]
    done = input(">>>done? (Y/N): ").strip().lower()
    if done == 'y':
        break

# Solve the Sudoku puzzle
if solve_sudoku(matrix):
    print("Resultant Matrix....")
    for i in range(9):
        for j in range(9):
            print(matrix[i,j],end="  ")
        print("\n")
else:
    print("No solution exists")
