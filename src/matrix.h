#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_
// выше защита  от повторного включения заголовочных файлов
// https://ru.stackoverflow.com/questions/483235/%D0%97%D0%B0%D1%87%D0%B5%D0%BC-%D0%BF%D0%B8%D1%88%D1%83%D1%82-ifndef-file-h-%D0%B2-%D0%BD%D0%B0%D1%87%D0%B0%D0%BB%D0%B5-%D1%84%D0%B0%D0%B9%D0%BB%D0%B0
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// для арифметики
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2
// для сравнения
#define SUCCESS 1
#define FAILURE 0

#define EPS 1e-7

typedef struct matrix_struct {
    double **matrix;
    int rows;
    int columns;
} matrix_t;

int create_matrix(int rows, int columns, matrix_t *result);
void remove_matrix(matrix_t *A);
int eq_matrix(matrix_t *A, matrix_t *B);
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

void set_zero(matrix_t *A);
void printer(matrix_t A);
// void placeholder(matrix_t *A);
// void placeholder_new(matrix_t *A);
// void placeholder_for_inverse(matrix_t *A);
// void placeholder_for_inverse_high(matrix_t *A);
void copy_matrix(matrix_t *A, matrix_t *result);

#endif  // SRC_MATRIX_H_
