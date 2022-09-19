#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

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
    double** matrix;
    int rows;
    int columns;
} matrix_t;


int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
void minor_matrix(matrix_t *A, matrix_t *result, int row, int column);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

double second_minor(matrix_t *A);
void set_zero(matrix_t *A);
void printer(matrix_t A);
void placeholder(matrix_t *A);
void placeholder_new(matrix_t *A);
void placeholder_for_inverse(matrix_t *A);
void placeholder_for_inverse_high(matrix_t *A);
void copy_matrix(matrix_t *A, matrix_t *result);

#endif  // SRC_S21_MATRIX_H_
