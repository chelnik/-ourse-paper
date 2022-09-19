#include "s21_matrix.h"
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
/**
 * @brief Заполняет по возрастанию
 */
void placeholder(matrix_t *A) {
    int count = 0;
    if (A->matrix) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                A->matrix[i][j] = ++count;
            }
        }
    }
}
void placeholder_new(matrix_t *A) {
    int array[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
    if (A->matrix) {
        for (int i = 0, count = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++, count++) {
                A->matrix[i][j] = array[count];
            }
        }
    }
}
void placeholder_for_inverse(matrix_t *A) {
    int array[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    if (A->matrix) {
        for (int i = 0, count = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++, count++) {
                A->matrix[i][j] = array[count];
            }
        }
    }
}
void placeholder_for_inverse_high(matrix_t *A) {
    int array[16] = {2, 5, 7, 1, 6, 3, 4, 1, 5, -2, -3, 1, 11, 1, 1, 1};
    if (A->matrix) {
        for (int i = 0, count = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++, count++) {
                A->matrix[i][j] = array[count];
            }
        }
    }
}

void copy_matrix(matrix_t *A, matrix_t *result) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j];
        }
    }
}
