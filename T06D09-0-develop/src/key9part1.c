/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

int input(int *a, int *n);
void output(int *a2, int s, int sumEven);
int even(int *a, int n);
int size(int *a, int n, int sumEven);
void newArray(int *a, int n, int *a2, int sumEven);

int main() {
    int n, array[10];
    if (!input(array, &n)) {
        int sumEven = even(array, n);
        int s = size(array, n, sumEven);
        int array2[10];
        newArray(array, n, array2, sumEven);
        output(array2, s, sumEven);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    int retturn=0;
    char c;
    if (scanf("%d", n) && *n < 11 && *n > 0) {
        for (int i = 0; i < *n && retturn==0; i++) {
            if (!(scanf("%d%c", a + i,&c) && (c==' '||c=='\n'))) {
                retturn++;
            }
        }
    } else {
        retturn++;
    }
    return retturn;
}
void output(int *a2, int s, int sumEven) {  // OUT
    printf("%d\n", sumEven);
    for (int i = 0; i < s; i++) {
        if (i + 1 == s) {
            printf("%d", *(a2 + i));
        } else {
            printf("%d ", *(a2 + i));
        }
    }
}

int even(int *a, int n) {
    int sumEven = 0;
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0) {
            sumEven += *(a + i);
        }
    }
    return sumEven;
}
int size(int *a, int n, int sumEven) {
    int size = 0;
    for (int i = 0; i < n; i++) {
        if (*(a + i) != 0 && sumEven % *(a + i) == 0) {
            size++;
        }
    }
    return size;
}

void newArray(int *a, int n, int *a2, int sumEven) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(a + i) != 0 && sumEven % *(a + i) == 0) {
            *(a2 + count) = *(a + i);
            count++;
        }
    }
}
