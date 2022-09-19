#include "matrix.h"

/**
 * @brief Сложение матриц
 * @return
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 *     нельзя провести вычисления и т.д.)
 */
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    if (A && B && result && A->rows >= 1 && A->columns >= 1) {
        if (A->rows == B->rows && A->columns == B->columns) {
            create_matrix(A->rows, A->columns, result);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                }
            }
        } else {
            flag = CALCULATION_ERROR;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}

/**
 * @brief Умножение матрицы на число
 */
int mult_number(matrix_t *A, double number, matrix_t *result) {
    int flag = OK;
    if (A && result) {
        if (A->rows >= 1 && A->columns >= 1) {
            create_matrix(A->rows, A->columns, result);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = A->matrix[i][j] * number;
                }
            }
        } else {
            // flag = CALCULATION_ERROR;
            flag = INCORRECT_MATRIX;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}

/**
 * @brief Умножение двух матриц
 */
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    double sum = 0;
    if (A && B && result && B->rows >= 1 && B->columns >= 1 && A->rows >= 1 &&
        A->columns >= 1) {
        if (A->rows == B->columns && A->columns == B->rows) {
            create_matrix(A->rows, B->columns, result);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    for (int k = 0; k < A->columns; k++) {
                        sum += A->matrix[i][k] * B->matrix[k][j];
                    }
                    result->matrix[i][j] = sum;
                    sum = 0;
                }
            }
        } else {
            flag = CALCULATION_ERROR;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}
