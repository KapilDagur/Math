#include <stdio.h>

#define MAXSIZE 10

int matrix1[MAXSIZE][MAXSIZE] = {0};
int matrix2[MAXSIZE][MAXSIZE] = {0};
int result_matrix[MAXSIZE][MAXSIZE] = {0};

int row1;
int row2;

int col1;
int col2;

void multiply() {
    if (col1 != row2) {
        printf("MatrixDimensionIncompatibleError: Matrix dimensions are incompatible, Matrix1 Dimension(%dx%d) and Matrix2 Dimension (%dx%d)\n", row1, col1, row2, col2);
        return;
    }

    int row;
    int col;
    int i;

    for (row = 0; row < row1; row++) {
        for (col = 0; col < col2; col++) {
            result_matrix[row][col] = 0;
            for (i = 0; i < col1; i++) {
                result_matrix[row][col] += matrix1[row][i] * matrix2[i][col];
            }
        }
    }
}

void display(int matrix[MAXSIZE][MAXSIZE], int row, int col){
    int row_;
    int col_;
    for(row_ = 0; row_ < row; row_++){
        for(col_ = 0; col_ < col; col_++)
            printf("%d\t", matrix[row_][col_]);
        printf("\n");
    }
}

int main() {
    // Example initialization of the matrices
    row1 = 2, col1 = 3;
    row2 = 3, col2 = 2;

    matrix1[0][0] = 1, matrix1[0][1] = 2, matrix1[0][2] = 3;
    matrix1[1][0] = 4, matrix1[1][1] = 5, matrix1[1][2] = 6;

    matrix2[0][0] = 7, matrix2[0][1] = 8;
    matrix2[1][0] = 9, matrix2[1][1] = 10;
    matrix2[2][0] = 11, matrix2[2][1] = 12;

    printf("Matrix 1:\n");
    display(matrix1, row1, col1);

    printf("\nMatrix 2:\n");
    display(matrix2, row2, col2);

    multiply();

    printf("\nResult Matrix:\n");
    display(result_matrix, row1, col2);

    return 0;
}


