#include <stdio.h>

#include "matrix_operations_helper.h"

int cmp_input(const int __num1, const int __num2){
    return __num1 == __num2 ? 1 : 0;
}

int is_pos_num(const int __num){
    return __num > 0 ? 1: 0;
}

int is_valid_rows(const int row1, const int row2){
    if(!cmp_input(row1,row2)){
        fprintf(stderr, "RowsMismatchError: Entered Rows are not same. \n\tEntered Rows are as follow- #Row1 %d* #Row2 %d*", row1,row2);
        return 0;
    }
    return 1;
}

int is_valid_cols(const int col1, const int col2){
    if(!cmp_input(col1,col2)){
        fprintf(stderr, "ColsMismatchError: Entered Cols are not same. \n\tEntered Cols are as follow- #Col1 %d* #Col2 %d*", col1,col2);
        return 0;
    }
    return 1;
}

int is_valid_matrix(const int row1, const int col1, const int row2, const int col2, const char* __error_type, const char* __error_message){
    //ROW CHECK...
    if(!is_pos_num(row1) || !is_pos_num(row2)){
        fprintf(stderr, "NonPositiveRowError: Row can't be negative");
        fprintf(stdout, "%s is non positive %d", row1 > 0 ? "#Row2" : "#Row1", row1 > 0 ? row2 : row1);
        return 0;
    }

    //COL CHECK...
    if(!is_pos_num(col1) || !is_pos_num(col2)){
        fprintf(stderr, "NonPositiveColError: Column can't be negative");
        fprintf(stdout, "%s is non positive %d", col1 > 0 ? "#Col2" : "#Col1", col1 > 0 ? col2 : col1);
        return 0;
    }

    //ROWs COMPARE...
    if(!is_valid_rows(row1, row2)){
        fprintf(stderr, "%s : %s, Rows are not same.", __error_type, __error_message);
        fprintf(stdout, "Invalid Rows : #Row1 %d, #Row2 %d",row1, row2);
        return 0;
    }

    //Cols COMPARE...
    if(!is_valid_cols(col1, col2)){
        fprintf(stderr, "%s : %s, Cols are not same.", __error_type, __error_message);
        fprintf(stdout, "Invalid Cols : #Col1 %d, #Col2 %d",col1, col2);
        return 0;
    }
    return 1;
}