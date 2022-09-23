#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        output(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(n));
    } else {
        printf("n/a");
    }

    return 0;
}
int input(int *a, int *n) {
    if (scanf("%d", n) && *n > 0 && *n < 11) {
        for (int p = 0; p < *n; p++) {
            if (!scanf("%d", a + p)) {
                return 1;
            }
        }
        return 0;
    } else {
        return 1;
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++)
        if (i + 1 == n) {
            printf("%d", *(a + i));
        } else {
            printf("%d ", *(a + i));
        }
}

int max(int *a, int n) {  // экстремум max
    int max = *(a);
    for (int i = 1; i < n; i++) {
        if (*(a + i) > max)
            max = *(a + i);
    }
    return max;
}
int min(int *a, int n) {  // экстремум min
    int min = *(a);
    for (int i = 1; i < n; i++) {
        if (*(a + i) < min)
            min = *(a + i);
    }
    return min;
}
double mean(int *a, int n) {  // ожидание (first+last)/2
    double temp1 = *a;
    double temp2 = *(a + n - 1);
    return (temp1 + temp2) / 2;
}
double variance(int n) {  // дисперсия (n*n-1)/12
    double temp = n;
    return (temp * temp - 1) / 12;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
