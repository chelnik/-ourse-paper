#include "s21_matrix.h"

void testBase();

int main() {
    FILE *file = fopen("text.txt", "r");
    fclose(file);
    printf(" go\n");
    return 0;
}
// функция которая 
//  читает из файла знак
// размер первой матрицы
// первую матрицу
// размер второй матрицы
// вторую матрицу

// функция которая 

void testBase() {
    matrix_t A, result;
    s21_create_matrix(4, 4, &A);

    placeholder_for_inverse_high(&A);
    printer(A);

    printer(result);
}
// rows строка
// columns столбик
-