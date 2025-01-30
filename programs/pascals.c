#include <stdio.h>

void printPascalsTriangle(int numRows) {
    int arr[numRows][numRows];

    // Initialize the Pascal's Triangle
    for (int line = 0; line < numRows; line++) {
        arr[line][0] = 1; // First element of each row is 1

        for (int i = 1; i <= line; i++) {
            arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
        }
    }

    // Print the Pascal's Triangle with proper spacing
    for (int line = 0; line < numRows; line++) {
        // Print leading spaces for alignment
        for (int space = 0; space < numRows - line - 1; space++) {
            printf("   ");
        }

        // Print the numbers in the current row
        for (int i = 0; i <= line; i++) {
            printf("%6d", arr[line][i]);
        }

        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows: ");
    scanf("%d", &numRows);

    printPascalsTriangle(numRows);

    return 0;
}
