#include <stdio.h>

#define MAXSIZE 10

int matrix1[MAXSIZE][MAXSIZE] = {0};
int matrix2[MAXSIZE][MAXSIZE] = {0};
int result_matrix[MAXSIZE][MAXSIZE] = {0};

int row1;
int row2;

int col1;
int col2;

int check_dim(){
    if (row1 != row2 || col1 != col2) {
        printf("MatrixDimensionIncompatibleError: Matrix dimensions are incompatible, Matrix1 Dimension(%dx%d) and Matrix2 Dimension (%dx%d)\n", row1, col1, row2, col2);
        return 0;
    }
    return 1;
}

void add(){
    if(!check_dim())
        return;
    //Init...
    int row;
    int col;


    //Addition Operation...
    for(row = 0; row < row1; row++){
        for(col = 0; col < col1; col++){
            result_matrix[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
}

void sub(){
    if(!check_dim())
        return;
    //Init...
    int row;
    int col;


    //Addition Operation...
    for(row = 0; row < row1; row++){
        for(col = 0; col < col1; col++){
            result_matrix[row][col] = matrix1[row][col] - matrix2[row][col];
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


int main(int argc, char const *argv[])
{
    row1 = 3;
    row2 = 3;

    col1 = 4;
    col2 = 4;

    matrix1[0][0] = 1, matrix1[0][1] = 2, matrix1[0][2] = 3, matrix1[0][3] = 4;
    matrix1[1][0] = 2, matrix1[1][1] = 3, matrix1[1][2] = 4, matrix1[1][3] = 5;
    matrix1[2][0] = 3, matrix1[2][1] = 4, matrix1[2][2] = 5, matrix1[2][3] = 6;

    matrix2[0][0] = 5, matrix2[0][1] = 4, matrix2[0][2] = 3, matrix2[0][3] = 2;
    matrix2[1][0] = 4, matrix2[1][1] = 3, matrix2[1][2] = 2, matrix2[1][3] = 1;
    matrix2[2][0] = 3, matrix2[2][1] = 2, matrix2[2][2] = 1, matrix2[2][3] = 0;

    printf("Matrix 1 : \n");
    display(matrix1, row1, col1);

    printf("Matrix 2 : \n");
    display(matrix2, row2, col2);

    add();
    printf("Result Matrix after add : \n");
    display(result_matrix, row1, col1);

    sub();
    printf("Result Matrix after sub : \n");
    display(result_matrix, row1, col1);
    return 0;
}
