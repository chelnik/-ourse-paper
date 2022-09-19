#include "s21_matrix.h"

/**
 * @brief Обнуляет матрицу
 */
void set_zero(matrix_t *A) {
    if (A) {
        A->matrix = NULL;
        A->rows = 0;
        A->rows = 0;
    }
}

/**
 * @brief Сравнение матриц
 * @return 1 - Совпадают, 0 - Не совпадают
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int flag = SUCCESS;
    if (A && B) {
        if (A->rows == B->rows && A->columns == B->columns) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS)
                        flag = FAILURE;
                }
            }
        } else {
            flag = FAILURE;
        }
    } else {
        flag = FAILURE;
    }
    return flag;
}

/**
 * @brief Создание матриц
 * @return 0 - OK, 1 - Ошибка, некорректная матрица
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int flag = OK;
    if (rows >= 1 && columns >= 1 && result != NULL) {
        result->rows = rows;
        result->columns = columns;
        result->matrix = calloc(rows, sizeof(double *));
        for (int i = 0; i < rows; i++) {
            result->matrix[i] = calloc(columns, sizeof(double));
        }
        // printf("\n%p", result->matrix);
        // printer(*result);
    } else {
        flag = INCORRECT_MATRIX;
        set_zero(result);
    }

    return flag;
}

/**
 * @brief Очистка матриц
 */
void s21_remove_matrix(matrix_t *A) {
    if (A) {
        if (A->matrix) {
            for (int i = 0; i < A->rows; i++) {
                free(A->matrix[i]);
            }
            free(A->matrix);
        }
    }
}

/**
 * @brief Вычитание матриц
 * @return
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 *     нельзя провести вычисления и т.д.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    if (A && B && result && A->rows >= 1 && A->columns >= 1) {
        if (A->rows == B->rows && A->columns == B->columns) {
            s21_create_matrix(A->rows, A->columns, result);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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
