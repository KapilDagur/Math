#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate a 2D matrix
int** allocate_matrix(int rows, int cols) {
    // Step 1: Allocate memory for rows (an array of int* pointers)
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Memory allocation failed for rows.\n");
        exit(1); // Exit if memory allocation fails
    }

    // Step 2: Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for row %d.\n", i);
            exit(1); // Exit if memory allocation fails
        }
    }

    return matrix;
}

// Function to free dynamically allocated memory for the matrix
void free_matrix(int** matrix, int rows) {
    // Free each row
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    // Free the array of pointers (rows)
    free(matrix);
}

// Function to display the matrix
void display_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
