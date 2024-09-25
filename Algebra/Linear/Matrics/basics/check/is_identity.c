#include <stdio.h>
#include <stdlib.h>

#include "../utils/metrix_alloc.c"

#define MAXSIZE 10

int is_identity_matrix(int **matrix, int row, int col){
    //BASE CONDITION
    if(row != col){
        printf("DimensionError : Row and Column Are not same");
        return 0;
    }
    int i;
    int j;

    //Iter each element of matrix and validate it's value with identity matrix condition
    //CASE 1: row == col and matrix[row][col] != 1 than it's not identity matrix
    //CASE 2: matrix[row][col] != 0 than it's not identity matrix
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(i == j && matrix[i][j] != 1){
                return 0;
            }
            else if(matrix[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}


void test_identity_matrix(){

    int **matrix;
    int row;
    int col;

    row = 3;
    col = 3;

    //Test 1
    matrix = allocate_matrix(row,col);
    
    matrix[0][0] = 1, matrix[0][1] = 0, matrix[0][2] = 0;
    matrix[1][0] = 0, matrix[1][1] = 1, matrix[1][2] = 0;
    matrix[2][0] = 0, matrix[2][1] = 0, matrix[2][2] = 1;

    display_matrix(matrix, row, col);
    if(is_identity_matrix(matrix, row, col))
        printf("Identity Matrix \nTest 1 Passed!\n");

    free_matrix(matrix, row);

    //Test 2
    row = 2;
    col = 3;
    matrix = allocate_matrix(row,col);
    
    matrix[0][0] = 1, matrix[0][1] = 0, matrix[0][2] = 0;
    matrix[1][0] = 0, matrix[1][1] = 1, matrix[1][2] = 0;
    
    display_matrix(matrix, row, col);
    if(!is_identity_matrix(matrix, row, col))
        printf("Not Identity Matrix \nTest 2 Passed!\n");

    free_matrix(matrix, row);

    //Test 3
    row = 3;
    col = 2;
    matrix = allocate_matrix(row,col);
    
    matrix[0][0] = 1, matrix[0][1] = 0;
    matrix[1][0] = 0, matrix[1][1] = 1;
    matrix[2][0] = 0, matrix[2][1] = 0;
    
    display_matrix(matrix, row, col);
    if(!is_identity_matrix(matrix, row, col))
        printf("Not Identity Matrix \nTest 3 Passed!\n");

    free_matrix(matrix, row);

    //Test 4
    matrix = allocate_matrix(row,col);
    row = 3;
    col = 3;
    
    matrix[0][0] = 1, matrix[0][1] = 0, matrix[0][2] = 0;
    matrix[1][0] = 0, matrix[1][1] = 1, matrix[1][2] = 0;
    matrix[2][0] = 1, matrix[2][1] = 0, matrix[2][2] = 1;

    display_matrix(matrix, row, col);
    if(!is_identity_matrix(matrix, row, col))
        printf("Not Identity Matrix \nTest 4 Passed!\n");

    free_matrix(matrix, row);


}

int main(int argc, char const *argv[])
{
    test_identity_matrix();

    
    return 0;
}
