#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H 1

/**
 * @brief Adds two matrices of the same dimension.
 *
 * This function adds corresponding elements of matrix A and matrix B and stores the result in matrix C. All matrices should be allocated before calling this function.
 * 
 * Preconditions:
 * - Matrices A, B, and C must be allocated and their dimensions validated.
 * - Matrices A and B must have the same dimensions.
 * - Matrix C must have the same dimensions as matrix A (and B).
 *
 * @param A Pointer to matrix A.
 * @param row_A Number of rows in matrix A.
 * @param col_A Number of columns in matrix A.
 * @param B Pointer to matrix B.
 * @param row_B Number of rows in matrix B.
 * @param col_B Number of columns in matrix B.
 * @param C Pointer to the result matrix C.
 * @param row_C Number of rows in matrix C.
 * @param col_C Number of columns in matrix C.
 * @return int Returns 1 if the addition was successful, otherwise 0. Prints error messages in case of failure.
 */
int add_matrix(const int **A, const int row_A, const int col_A, const int **B, const int row_B, const int col_B, int **C, const int row_C, const int col_C);

/**
 * @brief Subtracts matrix B from matrix A.
 *
 * This function subtracts corresponding elements of matrix B from matrix A and stores the result in matrix C. All matrices should be allocated before calling this function.
 * 
 * Preconditions:
 * - Matrices A, B, and C must be allocated and their dimensions validated.
 * - Matrices A and B must have the same dimensions.
 * - Matrix C must have the same dimensions as matrix A (and B).
 *
 * @param A Pointer to matrix A.
 * @param row_A Number of rows in matrix A.
 * @param col_A Number of columns in matrix A.
 * @param B Pointer to matrix B.
 * @param row_B Number of rows in matrix B.
 * @param col_B Number of columns in matrix B.
 * @param C Pointer to the result matrix C.
 * @param row_C Number of rows in matrix C.
 * @param col_C Number of columns in matrix C.
 * @return int Returns 1 if the subtraction was successful, otherwise 0. Prints error messages in case of failure.
 */
int sub_matrix(const int **A, const int row_A, const int col_A, const int **B, const int row_B, const int col_B, int **C, const int row_C, const int col_C);

int scalar_matrix(int **A, const int row, const int col, const int __scalar);

#endif
