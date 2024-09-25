#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

// Function to display matrix
void display(float matrix[MAXSIZE][MAXSIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%0.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix inversion using Gauss-Jordan elimination
int inverse(float matrix[MAXSIZE][MAXSIZE], float inverse[MAXSIZE][MAXSIZE], int size) {
    // Augmenting the matrix with the identity matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                inverse[i][j] = 1;
            else
                inverse[i][j] = 0;
        }
    }

    // Applying Gauss-Jordan elimination
    for (int i = 0; i < size; i++) {
        float diagElement = matrix[i][i];
        if (diagElement == 0) {
            printf("Matrix is singular and cannot be inverted.\n");
            return 0;
        }

        // Divide the row by the diagonal element to make it 1
        for (int j = 0; j < size; j++) {
            matrix[i][j] /= diagElement;
            inverse[i][j] /= diagElement;
        }

        // Make all other elements in the column 0
        for (int row = 0; row < size; row++) {
            if (row != i) {
                float factor = matrix[row][i];
                for (int col = 0; col < size; col++) {
                    matrix[row][col] -= factor * matrix[i][col];
                    inverse[row][col] -= factor * inverse[i][col];
                }
            }
        }
    }

    return 1;
}

int main() {
    int size = 3;
    float matrix[MAXSIZE][MAXSIZE] = {
        {2, -4, 0},
        {1, 2, 3},
        {0, 1, 2}
    };

    float inverse_matrix[MAXSIZE][MAXSIZE] = {0};

    printf("Original Matrix:\n");
    display(matrix, size);

    if (inverse(matrix, inverse_matrix, size)) {
        printf("\nInverse Matrix:\n");
        display(inverse_matrix, size);
    } else {
        printf("\nMatrix cannot be inverted.\n");
    }

    return 0;
}
