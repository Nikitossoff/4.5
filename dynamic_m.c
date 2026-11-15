#include "dynamic_m.h"
#include <malloc.h>

void Create(int **x, int n) {
    *x = (int *)malloc(n * sizeof(int));
    return;
}

void Vvod(FILE *in, int *x, int n) {
    for (int i = 0; i < n; i++) {
        fscanf(in, "%i", &x[i]);
    }
    return;
}

void Vivod(FILE *out, int *x, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(out, "%4i ", x[i]);
    }
    fprintf(out, "\n");
    return;
}

float sr_arifm(int *x, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += x[i];
    }
    float sr = (float)s / n;
    return sr;
}

int first_chet(int *x, int n) {
    int i = 0;
    int fl = 1;

    while (i < n && fl) {
        if (x[i] % 2 == 0) {
            fl = 0;
        } else {
            i += 1;
        }
    }
    return i;
}

void min_chet(FILE *out, int *x, int n, int i) {
    int Min = x[i];
    int index = i;
    for (int j = i + 1; j < n; j++) {
        if (x[j] % 2 == 0 && x[j] < Min) {
            Min = x[j];
            index = j;
        }
    }
    fprintf(out, "Минимальный четный элемент: %i (индекс %i)\n", Min, index);
    return;
}

void Ochistka(int **x) {
    free((*x));
    return;
}
