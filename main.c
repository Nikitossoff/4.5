#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "dynamic_m.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *inA = fopen("t1_A.txt", "r");
    FILE *inB = fopen("t1_B.txt", "r");
    FILE *inC = fopen("t1_C.txt", "r");
    int na, nb, nc;
    do {
        printf("Введите количество строк N массива А: ");
        scanf("%i", &na);
        if (na <= 1 || na > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (na <= 1 || na > 100);
    do {
        printf("Введите количество строк N массива B: ");
        scanf("%i", &nb);
        if (nb <= 1 || nb > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (nb <= 1 || nb > 100);
    do {
        printf("Введите количество строк N массива C: ");
        scanf("%i", &nc);
        if (nc <= 1 || nc > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (nc <= 1 || nc > 100);

    int *A = NULL, *B = NULL, *C = NULL;
    Create(&A, na);
    Create(&B, nb);
    Create(&C, nc);

    Vvod(inA, A, na);
    Vvod(inB, B, nb);
    Vvod(inC, C, nc);

    float sa = sr_arifm(A, na);
    float sb = sr_arifm(B, nb);
    float sc = sr_arifm(C, nc);

    FILE *out = fopen("output.txt", "w");

    if (sa < 0 && sb >= 0 && sc >= 0) {
        fprintf(out, "В A среднее арифметическое отрицательно\n");
        min_chet(out, A, na);
    }
    else if (sb < 0 && sa >= 0 && sc >= 0) {
        fprintf(out, "В B среднее арифметическое отрицательно\n");
        min_chet(out, B, nb);
    }
    else if (sc < 0 && sa >= 0 && sb >= 0) {
        fprintf(out, "В C среднее арифметическое отрицательно\n");
        min_chet(out, C, nc);
    }
    else if (sa < 0 && sb < 0 && sc >= 0) {
        fprintf(out, "В A и B среднее арифметическое отрицательно\n");
        fprintf(out, "Массив A: ");
        min_chet(out, A, na);
        fprintf(out, "Массив B: ");
        min_chet(out, B, nb);
    }
    else if (sa < 0 && sc < 0 && sb >= 0) {
        fprintf(out, "В A и C среднее арифметическое отрицательно\n");
        fprintf(out, "Массив A: ");
        min_chet(out, A, na);
        fprintf(out, "Массив C: ");
        min_chet(out, C, nc);
    }
    else if (sb < 0 && sc < 0 && sa >= 0) {
        fprintf(out, "В B и C среднее арифметическое отрицательно\n");
        fprintf(out, "Массив B: ");
        min_chet(out, B, nb);
        fprintf(out, "Массив C: ");
        min_chet(out, C, nc);
    }
    else if (sa < 0 && sb < 0 && sc < 0) {
        fprintf(out, "Во всех трёх массивах среднее арифметическое отрицательно\n");
        fprintf(out, "Массив A: ");
        min_chet(out, A, na);
        fprintf(out, "Массив B: ");
        min_chet(out, B, nb);
        fprintf(out, "Массив C: ");
        min_chet(out, C, nc);
    }
    else {
        fprintf(out, "Ни в одном из массивов среднее арифметическое не отрицательно\n");
    }

    fclose(inA);
    fclose(inB);
    fclose(inC);
    fclose(out);
    printf("Результат успешно записан в output.txt!");
    Ochistka(&A);
    Ochistka(&B);
    Ochistka(&C);
    return 0;
}
