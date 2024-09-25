#include <stdio.h>
#include <stdlib.h>

#include "determinant_operations.h"

void get_cofactor(const int **matrix, int **temp, int p, int q, int n) {
    int i = 0, j = 0;

    // Looping through rows and columns to get the cofactor.
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copying only those elements that are not in row p and column q.
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];

                // Row is filled, so increase row index and reset column index.
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(const int **matrix, int n) {
    int D = 0;  // Initialize result.

    // Base case: if matrix contains single element.
    if (n == 1)
        return matrix[0][0];

    // Temporary matrix to store cofactors.
    int **temp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        temp[i] = (int *)malloc(n * sizeof(int));

    int sign = 1;  // To store sign multiplier.

    // Iterate for each element of the first row.
    for (int f = 0; f < n; f++) {
        // Getting Cofactor of matrix[0][f].
        getCofactor(matrix, temp, 0, f, n);
        D += sign * matrix[0][f] * determinant((const int **)temp, n - 1);

        // Alternating sign.
        sign = -sign;
    }

    // Freeing allocated memory.
    for (int i = 0; i < n; i++)
        free(temp[i]);
    free(temp);

    return D;
}
