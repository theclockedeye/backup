# create a square of specific lenght from user input array of integers

import random

# Reading user input
input_array = input("Enter the input array: ")
n = int(input("Enter length of one side of square to be made: "))

# Mapping string values into integer list
array = list(map(int, input_array.split()))
count, j = 0, 0

print("Reference Array:\n",array)

# Creating a resultant matrix with null values
matrix = [[' ' for _ in range(n)] for _ in range(n)]

top = []
count = 0
while count < n:
    val = random.choice(array)
    if val not in top:
        top.append(val)
        count += 1

bottom = []
count = 0
while count < n:
    val = random.choice(array)
    if val not in bottom:
        bottom.append(val)
        count += 1

left = []
count = 0
left.append(top[0])
while count < n-2:
    val = random.choice(array)
    if val not in left:
        left.append(val)
        count += 1
left.append(bottom[0])

right = []
count = 0
right.append(top[n-1])
while count < n-1:
    val = random.choice(array)
    if val not in right:
        right.append(val)
        count += 1
right.append(bottom[n-1])

# Assigning top and bottom rows
matrix[0] = top
matrix[n-1] = bottom

# Assigning left and right columns
for i in range(n):
    matrix[i][0] = left[i]
    matrix[i][n-1] = right[i]

# Printing the resultant matrix, i.e., square with side n
print("Matrix:")
for row in matrix:
    for i in row:
        print(i, end="  ")
    print()

"""
Output:
Enter the input array: 1 2 3 4 5 6 7 8 9 0
Enter length of one side of square to be made: 6
Reference Array:
 [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
Matrix:
6  0  1  3  9  5  
9              4  
0              9  
5              1  
2              6  
4  0  5  2  7  0  

Enter the input array: 1 2 3 4 5 6 7 8 9
Enter length of one side of square to be made: 4
Reference Array:
 [1, 2, 3, 4, 5, 6, 7, 8, 9]
Matrix:
6  7  8  9  
7        6  
2        4  
7  6  3  2  

"""