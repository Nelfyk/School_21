#include "data_io.h"

#include <stdio.h>

double *input(int *n) {
    scanf("%d", n);

    double *a = (double *)malloc(*n * sizeof(double));
    for (int i = 0; i < *n; i++) {
        scanf("%lf", &a[i]);
    }
    return a;
}
void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i + 1 == n) {
            printf("%.2lf", *(data + i));
        } else {
            printf("%.2lf ", *(data + i));
        }
    }
}
