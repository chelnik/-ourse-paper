#include <fcntl.h>

#include "matrix.h"

#define ISNUM 1

void testBase();

void scanner();

int matrixScanner(FILE *file, int numOfMatrix);

void scanMatrix(FILE *file, matrix_t *result);

void remover(matrix_t *A, matrix_t *B, matrix_t *result);

void workWithTwoMatrix(FILE *file, int rows, int cols, char operations);

void workWithNumber(FILE *file, int rows, int cols, int mulNumber);

int main() {
    scanner();
    return 0;
}

void scanner() {
    FILE *file = fopen("text.txt", "r");

    if (file == NULL) {
        printf("no such file.");
    } else {
        int numOfMatrix = 0;
        fscanf(file, "%d\n", &numOfMatrix);

        matrixScanner(file, numOfMatrix);
        fclose(file);
    }
}

int getSign(FILE *file, char *operations, int *mulNumber) {
    char str[30] = "";
    fgets(str, 256, file);
    if (str[0] == '*') {
        if (str[2] > 0) {
            // тогда это умножение на число
            sscanf(str, "%c %d", operations, mulNumber);
            // printf("%c %d\n", operations, mulNumber);
            return ISNUM;
        } else {
            sscanf(str, "%c", operations);
        }
    } else if (str[0] == '+') {
        sscanf(str, "%c", operations);
    }
    return 0;
    //    printf("%s", str);
}

int matrixScanner(FILE *file, int numOfMatrix) {
    for (int i = 0; i < numOfMatrix; i++) {
        int rows = 0, cols = 0;
        char operations = 0;
        int mulNumber = 0;
        // fscanf(file, "%c\n", &operations);  // взятие знака
        if (getSign(file, &operations, &mulNumber)) {
            // тогда это умножение на число
            workWithNumber(file, rows, cols, mulNumber);
        } else {
            workWithTwoMatrix(file, rows, cols, operations);
        }
    }
    return 0;
}

void workWithNumber(FILE *file, int rows, int cols, int mulNumber) {
    matrix_t A, result;
    fscanf(file, "%d %d\n", &rows, &cols);
    create_matrix(rows, cols, &A);
    scanMatrix(file, &A);
    mult_number(&A, mulNumber, &result);
    printer(A);
    printf("\nУмножение на %d :", mulNumber);
    printer(result);
    remove_matrix(&A);
    remove_matrix(&result);
}

void workWithTwoMatrix(FILE *file, int rows, int cols, char operations) {
    // создание матрицы
    matrix_t A, B, result;
    fscanf(file, "%d %d\n", &rows, &cols);  // взятие rows cols

    printf("\n%d", create_matrix(rows, cols, &A));

    scanMatrix(file, &A);

    fscanf(file, "%d %d\n", &rows, &cols);  // взятие rows cols
    create_matrix(rows, cols, &B);
    scanMatrix(file, &B);

    printer(A);
    printer(B);

    switch (operations) {
        case '+':
            printf("\n%s", "Cложение:");
            sum_matrix(&A, &B, &result);
            printer(result);
            break;
        case '*':
            printf("\n%s", "Умножение:");
            mult_matrix(&A, &B, &result);
            printer(result);
            break;
        default:
            break;
    }
    remover(&A, &B, &result);
}

// очищает память
void remover(matrix_t *A, matrix_t *B, matrix_t *result) {
    remove_matrix(A);
    remove_matrix(B);
    remove_matrix(result);
}

void scanMatrix(FILE *file, matrix_t *result) {
    // сканирование матрицы
    for (int j = 0; j < result->rows; j++) {
        for (int k = 0; k < result->columns; k++) {
            int number;
            if (k == result->columns - 1) {
                fscanf(file, "%d\n", &number);
            } else {
                fscanf(file, "%d ", &number);
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
    matrix_t A;
    create_matrix(4, 4, &A);

    placeholder_for_inverse_high(&A);
    printer(A);

    //    printer(result);
}
// rows строка
// columns столбик
