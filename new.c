#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    FILE *file = fopen("texting.txt", "r");
    if (file == NULL) {
        printf("no such file.");
        return 0;
    }

    // char operations = 0;
    // создание матрицы
    // fscanf(file, "%c\n", &operations);  // взятие знака
    // printf("\n%c", operations);
    char str[30] = "";
    // fputs(str, file);
    int mulNumber;
    char operations;
    fgets(str, 256, file);
    if (str[0] == '*') {
        if (str[2] > 0) {
            // тогда это умножение на число
            mulNumber = str[2];
            sscanf(str, "%c %d", &operations, &mulNumber);
            printf("%c %d\n", operations, mulNumber);
        }
    } else if (str[0] == '+') {
    }
    printf("%s", str);
    fclose(file);
    return 0;
}

// fscanf(file, "%c %d", &operations, &mulNumber);
// printf("%c %d", operations, mulNumber);