#include <iostream>
using namespace std;

int calculateMatrixSum(int rows, int columns, int **matrix) {
    int i, j, sum = 0;
    if ((rows > 0) && (columns > 0)) {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                if (i == j) { // Check only diagonal elements
                    if (matrix[i][j] % 2 != 0) { // Check if the element is odd
                        sum += matrix[i][j];
                    }
                }
            }
        }
        return sum; // Return the computed sum
    } else {
        return sum; // Return 0 if dimensions are invalid
    }
}
