#include <fcntl.h>

#include "matrix.h"
void testBase();
int scanner();
int matrixScanner(FILE *file, int numOfMatrix);
void scanMatrix(FILE *file, matrix_t *result);
int main() {
    scanner();
    return 0;
}

int scanner() {
    FILE *file = fopen("text.txt", "r");

    if (file == NULL) {
        printf("no such file.");
        return 0;
    }
    int numOfMatrix = 0;
    fscanf(file, "%d\n", &numOfMatrix);

    matrixScanner(file, numOfMatrix);
    fclose(file);
    return 0;
}
int matrixScanner(FILE *file, int numOfMatrix) {
    for (int i = 0; i < numOfMatrix; i++) {
        int rows = 0, cols = 0;
        char operations = 0;
        // создание матрицы
        matrix_t A, B;
        fscanf(file, "%c\n", &operations);      // взятие знака
        fscanf(file, "%d %d\n", &rows, &cols);  // взятие rows cols

        create_matrix(rows, cols, &A);
        scanMatrix(file, &A);

        fscanf(file, "%c\n", &operations);      // взятие знака
        fscanf(file, "%d %d\n", &rows, &cols);  // взятие rows cols
        create_matrix(rows, cols, &B);
        scanMatrix(file, &B);

        printer(A);
        printer(B);

        switch (operations) {
            case '+':
                // sum_matrix()
                break;
            case '*':

                break;
            default:
                break;
        }
    }

    return 0;
}

void scanMatrix(FILE *file, matrix_t *result) {
    // сканирование матрицы
    for (int j = 0; j < result->rows; j++) {
        for (int k = 0; k < result->columns; k++) {
            int number;
            if (k == 0) {
                fscanf(file, "%d", &number);
            } else {
                fscanf(file, " %d", &number);
            }
            result->matrix[j][k] = number;
        }
    }
}
// пока не конец файла или не ошибка
// функция которая
//  читает из файла знак
// размер первой матрицы
// первую матрицу
// размер второй матрицы
// вторую матрицу
// вызывается функция
//
// выход из файла и закрытие

void testBase() {
    matrix_t A, result;
    create_matrix(4, 4, &A);

    placeholder_for_inverse_high(&A);
    printer(A);

    printer(result);
}
// rows строка
// columns столбик

// if (k == cols - 1) {
//     fscanf(file, "%d\n", &number);
// } else {
//     fscanf(file, "%d ", &number);
// }