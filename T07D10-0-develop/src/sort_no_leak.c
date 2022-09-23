#include <stdio.h>
#include <stdlib.h>

int input(int *n);
int inputArray(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int n;
    if (!input(&n)) {
        int *array;
        array = malloc(n * sizeof(int));
        if (!inputArray(array, n)) {
            sort(array, n);
            output(array, n);
            free(array);
        } else {
            free(array);
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}
int input(int *n) {
    char c;
    int flag = 0;
    if (!(scanf("%d%c", n, &c) && (c == ' ' || c == '\n'))) {
        flag++;
    }
    return flag;
}
int inputArray(int *a, int n) {
    int flag = 0;
    char c;
    for (int i = 0; i < n && flag != 1; i++) {
        if (!(scanf("%d%c", a + i, &c) && (c == ' ' || c == '\n'))) {
            flag++;
        }
    }
    return flag;
}
void sort(int *a, int n) {
    int temp;
    for (int o = 0; o < n - 1; o++) {
        for (int i = 0; i < n - 1; i++) {
            if (*(a + i) > *(a + i + 1)) {
                temp = *(a + i);
                *(a + i) = *(a + i + 1);
                *(a + i + 1) = temp;
            }
        }
    }
}
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i + 1 == n) {
            printf("%d", *(a + i));
        } else {
            printf("%d ", *(a + i));
        }
    }
}
