#include <stdio.h>
#include <stdlib.h>

#include "matrix_operations.h"
#include "matrix_operations_helper.h"

int main(int argc, char const *argv[])
{
    
    return 0;
}


int add_matrix(const int **A, const int row_A, const int col_A, const int **B, const int row_B, const int col_B, int **C, const int row_C, const int col_C){
    //CHECK FOR MEMORY ALLOCATION...
    if(!A || !A[0] || !B || !B[0] || !C || !C[0]){
        fprintf(stderr, "MemoryAllocationError : Memory not allocated successfully for matrix, either input matrix (A,B) or resultant  matrix (C). \nCan't Perform Matrix Addition");
        return 0;
    }

    //CHECK FOR INPUT MATRIX...
    if(!is_valid_matrix(row_A,col_A,row_B,col_B,"MatrixAdditionError","Matrix Addition failed")){
        fprintf(stderr, "InputMatricesDimensionMismatchError : Matrix A and Matrix B dimension are not same, \nDim(A)=(%dx%d) and Dim(B)=(%dx%d) ",row_A,col_A,row_B,col_B);
        return 0;
    }

    //CHECK FOR OUTPUT MATRIX...
    if(!is_valid_matrix(row_A,col_A,row_C,col_C,"MatrixAdditionError","Matrix Addition failed")){
        fprintf(stderr, "OutputMatrixDimensionMismatchError : Matrix A and Matrix C dimension are not same, \nDim(A)=(%dx%d) and Dim(C)=(%dx%d) ",row_A,col_A,row_C,col_C);
        return 0;
    }

    //Init...
    int row;
    int col;

    //Iteration for Perform Addition Operation on matrix 
    for(row = 0; row < row_A; row++){
        for(col = 0; col < col_A; col++){
            C[row][col] = A[row][col] + B[row][col];
        }
    }
    return 1;
}

int sub_matrix(const int **A, const int row_A, const int col_A, const int **B, const int row_B, const int col_B, int **C, const int row_C, const int col_C){
    //CHECK FOR MEMORY ALLOCATION...
    if(!A || !A[0] || !B || !B[0] || !C || !C[0]){
        fprintf(stderr, "MemoryAllocationError : Memory not allocated successfully for matrix, either input matrix (A,B) or resultant  matrix (C). \nCan't Perform Matrix Substraction");
        return 0;
    }

    //CHECK FOR INPUT MATRIX...
    if(!is_valid_matrix(row_A,col_A,row_B,col_B,"MatrixSubstractionError","Matrix Substraction failed")){
        fprintf(stderr, "InputMatrixesDimensionMismatchError : Matrix A and Matrix B dimension are not same, \nDim(A)=(%dx%d) and Dim(B)=(%dx%d) ",row_A,col_A,row_B,col_B);
        return 0;
    }

    //CHECK FOR OUTPUT MATRIX...
    if(!is_valid_matrix(row_A,col_A,row_C,col_C,"MatrixSubstractionError","Matrix Substraction failed")){
        fprintf(stderr, "OutputMatrixDimensionMismatchError : Matrix A and Matrix C dimension are not same, \nDim(A)=(%dx%d) and Dim(C)=(%dx%d) ",row_A,col_A,row_C,col_C);
        return 0;
    }

    //Init...
    int row;
    int col;

    //Iteration for Perform Substraction Operation on matrix 
    for(row = 0; row < row_A; row++){
        for(col = 0; col < col_A; col++){
            C[row][col] = A[row][col] - B[row][col];
        }
    }
    return 1;
}

int scalar_matrix(int **A, const int row, const int col, const int __scalar){
    //CHECK FOR MEMORY ALLOCATION...
    if(!A || !A[0]){
        fprintf(stderr, "MemoryAllocationError : Memory not allocated successfully for matrix, \nCan't Perform Scalar Multiplication");
        return 0;
    }

    //CHECK ROW...
    if(!is_pos_num(row)){
        fprintf(stderr, "NegativeRowError: Row can't be negative, \nCan't Perform Scalar Multiplication");
        return 0;
    }

    if(!is_pos_num(col)){
        fprintf(stderr, "NegativeColError: Column can't be negative, \nCan't Perform Scalar Multiplication");
        return 0;
    }

    //Init...
    int i;
    int j;

    //Iteration for Perform Substraction Operation on matrix 
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            A[row][col] = __scalar * A[row][col];
        }
    }
    return 1;
}