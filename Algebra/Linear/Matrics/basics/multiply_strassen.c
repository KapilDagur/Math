#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

// Function to add two matrices
void add_matrix(int A[MAXSIZE][MAXSIZE], int B[MAXSIZE][MAXSIZE], int C[MAXSIZE][MAXSIZE], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtract_matrix(int A[MAXSIZE][MAXSIZE], int B[MAXSIZE][MAXSIZE], int C[MAXSIZE][MAXSIZE], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen's algorithm for matrix multiplication
void strassen(int A[MAXSIZE][MAXSIZE], int B[MAXSIZE][MAXSIZE], int C[MAXSIZE][MAXSIZE], int size) {
    if (size == 1) {
        // Base case for 1x1 matrix
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int a11[MAXSIZE][MAXSIZE], a12[MAXSIZE][MAXSIZE], a21[MAXSIZE][MAXSIZE], a22[MAXSIZE][MAXSIZE];
    int b11[MAXSIZE][MAXSIZE], b12[MAXSIZE][MAXSIZE], b21[MAXSIZE][MAXSIZE], b22[MAXSIZE][MAXSIZE];
    int c11[MAXSIZE][MAXSIZE], c12[MAXSIZE][MAXSIZE], c21[MAXSIZE][MAXSIZE], c22[MAXSIZE][MAXSIZE];
    int m1[MAXSIZE][MAXSIZE], m2[MAXSIZE][MAXSIZE], m3[MAXSIZE][MAXSIZE], m4[MAXSIZE][MAXSIZE], m5[MAXSIZE][MAXSIZE], m6[MAXSIZE][MAXSIZE], m7[MAXSIZE][MAXSIZE];
    int temp1[MAXSIZE][MAXSIZE], temp2[MAXSIZE][MAXSIZE];

    // Divide matrices A and B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate the 7 products using Strassen's formulas
    add_matrix(a11, a22, temp1, newSize);       // temp1 = a11 + a22
    add_matrix(b11, b22, temp2, newSize);       // temp2 = b11 + b22
    strassen(temp1, temp2, m1, newSize);        // m1 = (a11 + a22) * (b11 + b22)

    add_matrix(a21, a22, temp1, newSize);       // temp1 = a21 + a22
    strassen(temp1, b11, m2, newSize);          // m2 = (a21 + a22) * b11

    subtract_matrix(b12, b22, temp2, newSize);  // temp2 = b12 - b22
    strassen(a11, temp2, m3, newSize);          // m3 = a11 * (b12 - b22)

    subtract_matrix(b21, b11, temp2, newSize);  // temp2 = b21 - b11
    strassen(a22, temp2, m4, newSize);          // m4 = a22 * (b21 - b11)

    add_matrix(a11, a12, temp1, newSize);       // temp1 = a11 + a12
    strassen(temp1, b22, m5, newSize);          // m5 = (a11 + a12) * b22

    subtract_matrix(a21, a11, temp1, newSize);  // temp1 = a21 - a11
    add_matrix(b11, b12, temp2, newSize);       // temp2 = b11 + b12
    strassen(temp1, temp2, m6, newSize);        // m6 = (a21 - a11) * (b11 + b12)

    subtract_matrix(a12, a22, temp1, newSize);  // temp1 = a12 - a22
    add_matrix(b21, b22, temp2, newSize);       // temp2 = b21 + b22
    strassen(temp1, temp2, m7, newSize);        // m7 = (a12 - a22) * (b21 + b22)

    // Compute the result submatrices
    add_matrix(m1, m4, temp1, newSize);         // temp1 = m1 + m4
    subtract_matrix(temp1, m5, temp2, newSize); // temp2 = (m1 + m4) - m5
    add_matrix(temp2, m7, c11, newSize);        // c11 = (m1 + m4 - m5 + m7)

    add_matrix(m3, m5, c12, newSize);           // c12 = m3 + m5
    add_matrix(m2, m4, c21, newSize);           // c21 = m2 + m4

    add_matrix(m1, m3, temp1, newSize);         // temp1 = m1 + m3
    subtract_matrix(temp1, m2, temp2, newSize); // temp2 = (m1 + m3) - m2
    add_matrix(temp2, m6, c22, newSize);        // c22 = (m1 + m3 - m2 + m6)

    // Combine submatrices into the result matrix
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }
}

// Function to display matrix
void display(int matrix[MAXSIZE][MAXSIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 4;  // We use a 2x2 matrix for simplicity in this example

    // Initialize Matrix 1
    int matrix1[MAXSIZE][MAXSIZE] = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7}
    };

    // Initialize Matrix 2
    int matrix2[MAXSIZE][MAXSIZE] = {
        {7, 6, 5, 4},
        {6, 5, 4, 3},
        {5, 4, 3, 2},
        {4, 3, 2, 1}
    };

    // Result matrix
    int result_matrix[MAXSIZE][MAXSIZE] = {0};

    // Perform Strassen's matrix multiplication
    strassen(matrix1, matrix2, result_matrix, size);

    // Display result
    printf("Result Matrix:\n");
    display(result_matrix, size, size);

    return 0;
}
