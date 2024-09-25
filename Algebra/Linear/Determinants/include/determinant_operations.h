#ifndef DETERMINANT_OPERATIONS_H
#define DETERMINANT_OPERATIONS_H 1

/**
 * @brief Computes the cofactor of a given element in a square matrix.
 *
 * This function creates a temporary submatrix `temp` by excluding the specified
 * row `p` and column `q` from the original matrix `matrix`. The submatrix can then
 * be used for further calculations, such as determinant computation via Laplace expansion.
 *
 * @param matrix The original square matrix (size n x n) from which the cofactor is computed.
 * @param temp   The temporary matrix where the cofactor submatrix will be stored.
 *               It should have space for a (n-1) x (n-1) matrix.
 * @param p      The row index of the element to be excluded from the cofactor.
 * @param q      The column index of the element to be excluded from the cofactor.
 * @param n      The size (dimension) of the original square matrix.
 *
 * @note This function does not allocate memory for the `temp` matrix, so it must
 * be pre-allocated by the caller. It modifies `temp` to store the cofactor matrix
 * based on the exclusion of row `p` and column `q` from the original `matrix`.
 */
void get_cofactor(const int **matrix, int **temp, int p, int q, int n);


/**
 * @brief Recursively computes the determinant of a square matrix.
 *
 * This function calculates the determinant of an n x n square matrix using
 * recursive Laplace expansion. It works by breaking down the matrix into smaller
 * submatrices and calculating the determinant of each until it reaches the base case.
 *
 * @param matrix The square matrix for which the determinant is to be calculated.
 *               The matrix should be of size n x n.
 * @param n      The size (dimension) of the square matrix.
 *               When n is 1, the base case is reached, and the function returns
 *               the single element as the determinant.
 *
 * @return The determinant of the square matrix as an integer value.
 *
 * @note This function allocates memory for temporary submatrices internally
 * and frees it before returning. If the matrix contains non-integer elements or
 * large values, the result might overflow due to integer arithmetic.
 */
int determinant(const int **matrix, int n);


#endif