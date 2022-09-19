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
 * @brief Сложение матриц
 * @return
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 *     нельзя провести вычисления и т.д.)
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    if (A && B && result && A->rows >= 1 && A->columns >= 1) {
        if (A->rows == B->rows && A->columns == B->columns) {
            s21_create_matrix(A->rows, A->columns, result);
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

/**
 * @brief Умножение матрицы на число
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int flag = OK;
    if (A && result) {
        if (A->rows >= 1 && A->columns >= 1) {
            s21_create_matrix(A->rows, A->columns, result);
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
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    double sum = 0;
    if (A && B && result && B->rows >= 1 && B->columns >= 1 && A->rows >= 1 &&
        A->columns >= 1) {
        if (A->rows == B->columns && A->columns == B->rows) {
            s21_create_matrix(A->rows, B->columns, result);
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

/**
 * @brief Транспонирование матриц (Замена строк этой матрицы ее столбцами с
 * сохранением их номеров)
 *  создает матрицу result
 * @return
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 *     нельзя провести вычисления и т.д.)
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
    int flag = OK;
    if (A && result) {
        if (A->rows >= 1 && A->columns >= 1) {
            s21_create_matrix(A->columns, A->rows, result);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[j][i] = A->matrix[i][j];
                }
            }
        } else {
            // flag = CALCULATION_ERROR;
            flag = INCORRECT_MATRIX;
            // set_zero(result);
        }
    } else {
        // set_zero(result);
        flag = INCORRECT_MATRIX;
    }
    return flag;
}
/**
 * @brief Находит 2*2 определитель матрицы (determinant)
 */
double second_minor(matrix_t *A) {
    return A->matrix[0][0] * A->matrix[1][1] -
           A->matrix[0][1] * A->matrix[1][0];
}

/**
 * @brief Находит определитель матрицы (determinant)
 */
int s21_determinant(matrix_t *A, double *result) {
    // ДОБАВИТЬ ПРОВЕРКИ КАК ВО ВСЕХ ФУНКЦИЯХ И ОБРАБОТКУ ОШИБОК!!!
    int flag = OK;
    // *result = 0;

    if (A && result && A->rows >= 1 && A->columns >= 1) {
        if (A->rows == A->columns) {
            if (A->rows == 1) {
                *result = A->matrix[0][0];
            } else if (A->rows == 2) {
                *result = second_minor(A);
            } else {
                double determinant = 0;
                for (int j = 0; j < A->columns; j++) {
                    matrix_t matrix_minor;
                    s21_create_matrix(A->rows - 1, A->columns - 1,
                                      &matrix_minor);
                    minor_matrix(A, &matrix_minor, 0, j);
                    s21_determinant(&matrix_minor, result);
                    determinant += A->matrix[0][j] * pow(-1, j) * (*result);
                    s21_remove_matrix(&matrix_minor);
                }
                *result = determinant;
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
 * @brief Находит минор матрицы
 */
void minor_matrix(matrix_t *A, matrix_t *result, int row, int column) {
    for (int i = 0, new_i = 0; i < A->rows; i++) {
        if (i == row) continue;
        for (int j = 0, new_j = 0; j < A->columns; j++) {
            if (j == column) continue;
            result->matrix[new_i][new_j] = A->matrix[i][j];
            new_j++;
        }
        new_i++;
    }
}

/**
 * @brief матрица алгебраических дополнений
 * создает матрицу result
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int flag = OK;
    if (A && result && A->rows >= 1 && A->columns >= 1) {
        if (A->rows == A->columns) {
            matrix_t m_for_determinant;
            s21_create_matrix(A->columns, A->rows, result);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    s21_create_matrix(A->columns - 1, A->rows - 1,
                                      &m_for_determinant);
                    double determinant = 0;
                    minor_matrix(A, &m_for_determinant, i, j);
                    s21_determinant(&m_for_determinant, &determinant);
                    s21_remove_matrix(&m_for_determinant);
                    result->matrix[i][j] = determinant * pow(-1, i + j);
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
 * @brief Находит обратную матрицу
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int flag = OK;
    if (A && result && A->rows >= 1 && A->columns >= 1) {
        if (A->rows == A->columns) {
            double determinant = 0;
            s21_determinant(A, &determinant);
            if (fabs(determinant) <= EPS) {
                flag = CALCULATION_ERROR;
            } else {
                matrix_t tmp;
                matrix_t tmp1;
// Когда-то тут была огромная ошибка с потерей памяти в куче
                s21_calc_complements(A, &tmp);
                s21_transpose(&tmp, &tmp1);
                s21_mult_number(&tmp1, 1. / determinant, result);

                s21_remove_matrix(&tmp);
                s21_remove_matrix(&tmp1);
            }

        } else {
            flag = CALCULATION_ERROR;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}
