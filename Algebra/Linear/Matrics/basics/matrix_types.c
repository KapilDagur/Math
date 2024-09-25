#include <stdio.h>
#include <complex.h>

#include "matrix_types.h"
#include "determinant_operation.h"

//Helper

int is_valid_matrix(const int **matrix, const int row, const int col){
    return matrix != NULL && matrix[0] != NULL && row > 0 && col > 0 ? 1 : 0; 
}

int is_scalar_matrix_number(const int **matrix, const int row, const int col, const int number){
    //Init...
    int i;
    int j;
    
    //ITERATE MATRIX AND CHECK
    //CASE 1: left diagonal always contains non zero elements and should contain a element inside diagonal it
    //CASE 2: else all element are zero
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(i == j && matrix[i][j] != number){
                return 0;
            }
            else if(matrix[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int **arr;
    int a;
    int b;
    
    return 0;
}


int is_row_matrix(const int **matrix, const int row, const int col){
    return is_valid_matrix(matrix,row,col) && row == 1 ? 1 : 0;
}

int is_column_matrix(const int **matrix, const int row, const int col){
    return is_valid_matrix(matrix,row,col) && col == 1 ? 1 : 0;
}

int is_square_matrix(const int **matrix, const int row, const int col){
    return is_valid_matrix(matrix,row,col) && row == col ? 1 : 0;
}

int is_diagonal_matrix(const int **matrix, const int row, const int col){
    
    //BASE CONDITION (SQUARE MATRIX REQUIRED)
    if(!is_square_matrix(matrix,row,col))
        return 0;
    
    //Init...
    int i;
    int j;
    
    //ITERATE MATRIX AND CHECK
    //CASE 1: left diagonal always contains non zero elements
    //CASE 2: else all element are zero
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(i == j && matrix[i][j] == 0){
                return 0;
            }
            else if(i != j && matrix[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int is_scalar_matrix(const int **matrix, const int row, const int col){
    //BASE CONDITION (SQUARE MATRIX REQUIRED)
    if(!is_square_matrix(matrix,row,col))
        return 0;
    
    return is_scalar_matrix_number(matrix,row,col,matrix[0][0]);
}

int is_identity_matrix(const int **matrix, const int row, const int col){
    return is_unit_matrix(matrix,row,col);
}

int is_unit_matrix(const int **matrix, const int row, const int col){
    //BASE CASE (SQUARE MATRIX REQUIRED)
    if(!is_square_matrix(matrix,row,col))
        return 0;
    
    return is_scalar_matrix_number(matrix,row,col,1);
}

int is_zero_matrix(const int **matrix, const int row, const int col){
    //BASE CASE (VALID MATRIX)
    if(!is_valid_matrix(matrix,row,col))
        return 0;

    //Init...
    int i;
    int j;
    
    //ITERATE EACH ELEMENT END CHECH IS ZERO
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(matrix[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int is_null_matrix(const int **matrix, const int row, const int col){
    return is_zero_matrix(matrix,row,col);
}

int is_upper_triangular_matrix(const int **matrix, const int row, const int col){
    //BASE CASE (SQUARE MATRIX REQUIRED)
    if(!is_square_matrix(matrix,row,col))
        return 0;
    
    //Init...
    int i;
    int j;
    
    //ITERATE EACH ELEMENT AND CHECK
    //CASE 1: EACH ELEMENT OF UPPER TRIANGLE INCLUDING DIAGONAL IS NON ZERO ELEMENT
    //CASE 2: EACH ELEMENT OF LOWER TRIANGLE EXCLUDING DIAGONAL SHOULD BE ZERO
    for(i = 0; i < row; i++){
        for( j = 0; j < col; j++){
            if(i > j && matrix[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int is_lower_triangular_matrix(const int **matrix, const int row, const int col){
    //BASE CASE (SQUARE MATRIX REQUIRED)
    if(!is_square_matrix(matrix,row,col))
        return 0;
    
    //Init...
    int i;
    int j;
    
    //ITERATE EACH ELEMENT AND CHECK
    //CASE 1: EACH ELEMENT OF UPPER TRIANGLE EXCLUDING DIAGONAL SHOULD BE ZERO
    //CASE 2: EACH ELEMENT OF LOWER TRIANGLE INCLUDING DIAGONAL SHOULD BE NON ZERO
    for(i = 0; i < row; i++){
        for( j = 0; j < col; j++){
            if(i < j && matrix[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int is_symmetric_matrix(const int **matrix, const int row, const int col){
    //BASE CASE (SQUARE MATRIX REQUIRED)
    if(!is_square_matrix(matrix,row,col))
        return 0;
    
    //Init...
    int i;
    int j;
    
    //ITERATION EACH ELEMENT AND CHECK
    //CASE 1: EACH ELEMENT OF ROW ELEMENT SHOULD BE SAME AS COLUMN ELEMENT
    for(i = 0; i < row; i++)
        for(j = col; j > i-1; j--)
            if(matrix[i][j] != matrix[j][i])
                return 0;

    return 1;
}

int is_skew_symmetric_matrix(const int **matrix, const int row, const int col){
    //BASE CASE (SQUARE MATRIX REQUIRED)
    if(!is_square_matrix(matrix,row,col))
        return 0;
    
    //Init...
    int i;
    int j;
    
    //ITERATION EACH ELEMENT AND CHECK
    //CASE 1: EACH ELEMENT OF ROW ELEMENT SHOULD BE SAME AS NEGATIVE OF COLUMN ELEMENT
    for(i = 0; i < row; i++)
        for(j = col; j > i-1; j--)
            if(matrix[i][j] != -matrix[j][i])
                return 0;

    return 1;
}