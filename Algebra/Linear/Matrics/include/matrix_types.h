#ifndef MATRIX_TYPES_H
#define MATRIX_TYPES_H 1

/**
 * @brief Check if the matrix is a row matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a row matrix, otherwise returns 0.
 * 
 * @note A row matrix has exactly one row.
 */
int is_row_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a column matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a column matrix, otherwise returns 0.
 * 
 * @note A column matrix has exactly one column.
 */
int is_column_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a square matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a square matrix, otherwise returns 0.
 * 
 * @note A square matrix has an equal number of rows and columns.
 */
int is_square_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a diagonal matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a diagonal matrix, otherwise returns 0.
 * 
 * @note A diagonal matrix is a square matrix where all elements outside the main diagonal are zero.
 */
int is_diagonal_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a scalar matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a scalar matrix, otherwise returns 0.
 * 
 * @note A scalar matrix is a diagonal matrix where all diagonal elements are the same.
 */
int is_scalar_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is an identity matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is an identity matrix, otherwise returns 0.
 * 
 * @note An identity matrix is a square matrix where all diagonal elements are 1 and all off-diagonal elements are 0.
 */
int is_identity_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a unit matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a unit matrix, otherwise returns 0.
 * 
 * @note A unit matrix has all diagonal elements equal to 1, similar to an identity matrix.
 */
int is_unit_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a zero matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a zero matrix, otherwise returns 0.
 * 
 * @note A zero matrix has all its elements equal to zero.
 */
int is_zero_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a null matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a null matrix, otherwise returns 0.
 * 
 * @note A null matrix is synonymous with a zero matrix, where all elements are zero.
 */
int is_null_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is an upper triangular matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is an upper triangular matrix, otherwise returns 0.
 * 
 * @note An upper triangular matrix is a square matrix where all elements below the main diagonal are zero.
 */
int is_upper_triangular_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a lower triangular matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is a lower triangular matrix, otherwise returns 0.
 * 
 * @note A lower triangular matrix is a square matrix where all elements above the main diagonal are zero.
 */
int is_lower_triangular_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a symmetric matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is symmetric, otherwise returns 0.
 * 
 * @note A symmetric matrix is a square matrix that is equal to its transpose.
 */
int is_symmetric_matrix(const int **matrix, const int row, const int col);

/**
 * @brief Check if the matrix is a skew-symmetric matrix.
 * 
 * @param matrix The matrix to check.
 * @param row Number of rows in the matrix.
 * @param col Number of columns in the matrix.
 * @return int Returns 1 if the matrix is skew-symmetric, otherwise returns 0.
 * 
 * @note A skew-symmetric matrix is a square matrix that is equal to the negative of its transpose.
 */
int is_skew_symmetric_matrix(const int **matrix, const int row, const int col);

#endif