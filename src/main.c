#include "s21_matrix.h"
//  Готовься к Тупым ошибкам
//  Мир не такой уж и солнечный. Это очень опасное жесткое место
void high_test_for_determinant() {
    matrix_t A, result;
    double resulter;
    s21_create_matrix(4, 4, &A);
    placeholder(&A);
    A.matrix[1][1] = 66;
    A.matrix[2][2] = 119;
    s21_determinant(&A, &resulter);
    printf("\n%lf", resulter);
    printer(result);
}
void high_test_for_calcomplements() {
    matrix_t A, result;
    s21_create_matrix(4, 4, &A);
    placeholder(&A);
    A.matrix[1][1] = 66;
    A.matrix[2][2] = 119;
    s21_calc_complements(&A, &result);
    printer(result);
}
void test_minor() {
    matrix_t a, result;
    int rows = 3, columns = 3;
    s21_create_matrix(rows, columns, &a);
    // printf("\n%d", s21_eq_matrix(&a, &b));
    placeholder(&a);
    printf("\n матрица которая была:");
    printer(a);
    minor_matrix(&a, &result, 2, 2);
    printf("\n результат: ");
    printer(result);
}
//  ----------------------------------------------------------------
int main() {
    matrix_t A, result;
    s21_create_matrix(4, 4, &A);

    placeholder_for_inverse_high(&A);
    printer(A);

    printf("\n%d", s21_inverse_matrix(&A, &result));

    printer(result);
    // high_test_for_determinant();
    // high_test_for_calcomplements();
    return 0;
}

// rows строка
// columns столбик
