#include <math.h>
#include <stdio.h>
#define MAX 30

int input(int *a, int *n);
void output(int *a, int n);
int even(int a);
double mean(int *a, int n);
double variance(int n);
int mustBe(int *a, int n);

int main() {
    int n, array[MAX];
    if (!input(array, &n)) {
        printf("%d", mustBe(array, n));
    } else {
        printf("n/a");
    }

    return 0;
}
int input(int *a, int *n) {
    if (scanf("%d", n) && *n > 0 && *n < 31) {
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
int even(int a) {
    if (!(a % 2)) {
        return 1;
    } else {
        return 0;
    }
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
int mustBe(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (even(*(a + i))) {                                          // "even"
            if (*(a + i) >= mean(a, n)) {                              // ">= mean"
                if (*(a + i) <= mean(a, n) + 3 * sqrt(variance(n))) {  // "<= mean + 3 * sqrt(variance)"
                    if (*(a + i) != 0) {                               // "!= 0"
                        return *(a + i);
                    }
                }
            }
        }
    }
    return 0;
}

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
