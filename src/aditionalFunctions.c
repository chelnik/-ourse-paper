#include "matrix.h"
/**
 * @brief Выводит матрицу
 */
void printer(matrix_t A) {
    printf("\n");
    if (A.matrix) {
        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < A.columns; j++) {
                printf("%lf ", A.matrix[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

void copy_matrix(matrix_t *A, matrix_t *result) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j];
        }
    }
}
