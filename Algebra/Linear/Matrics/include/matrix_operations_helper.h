#ifndef MATRIX_OPERATIONS_HELPER_H
#define MATRIX_OPERATIONS_HELPER_H 1

int cmp_input(const int __num1, const int __num2);

int is_pos_num(const int num);

int is_valid_rows(const int row1, const int row2);

int is_valid_cols(const int col1, const int col2);

int is_valid_matrix(const int row1, const int col1, const int row2, const int col2, const char* __error_type, const char* __error_message);

#endif