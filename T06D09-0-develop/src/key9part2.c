#include <stdio.h>

#define LEN 101

void sum(int *a1, int n1, int *a2, int n2, int *res, int n3, int *count);
void sub(int *a1, int n1, int *a2, int n2, int *res, int n3, int *count);
int sizeMax(int n1, int n2);
int input(int *a, int *n);
void output(int *a, int n, int count);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int arr1[LEN], n1;
    int arr2[LEN], n2;
    int count = 0;
    
    if (input(arr1, &n1) && input(arr2, &n2)) {
        int n3 = sizeMax(n1, n2);
        int result[LEN];
        sum(arr1, n1, arr2, n2, result, n3, &count);
        output(result, n3, count);
        int result2[LEN];
        sub(arr1, n1, arr2, n2, result2, n3, &count);
        printf("\n");
        output(result2, n3, count);
    } else {
        printf("n/a");
    }
}
int input(int *a, int *n) {
    int leave = 0;
    int retturn = 1;  // наоборот
    char c;
    for (int i = 0; i < LEN && retturn != 0 && leave == 0; i++) {
        if (scanf("%d%c", a + i, &c) && *(a + i) >= 0 && *(a + i) <= 9
        && (c == ' ' || c == '\n')) {
            if (c == '\n') {
                *n = i + 1;
                if (*n > 100) {
                    retturn = 0;
                }
                leave++;
            }
        } else {
            retturn = 0;
        }
    }
    return retturn;
}

void sum(int *a1, int n1, int *a2, int n2, int *res, int n3, int *count) {
    int temp = 0;
    if (n1 >= n2) {
        for (int i = n3 - 1, len = n2 - 1; i > 0 || len >= 0; i--, len--) {
            while (temp > 0 && (*(res + i) + 1 < 9)) {
                res[i]++;
                temp--;
            }
            if (len >= 0) {
                if ((*(a1 + i - 1) + *(a2 + len) + *(res + i)) > 9) {
                    *(res + i) = *(a1 + i - 1) + *(a2 + len) + *(res + i) - 10;
                    temp++;
                } else {
                    *(res + i) = *(a1 + i - 1) + *(a2 + len) + *(res + i);
                }
            } else {
                *(res + i) += *(a1 + i - 1);
            }
            if (*(res + i) == 10) {
                temp++;
                *(res + i) = 0;
            }
        }
        if (temp > 0) {  // если есть temp
            res[0]++;
            temp--;
        }

        while (res[0] == 0 && n3 > 0) {  // убираем нули
            for (int i = 0; i < n3; i++) {
                res[i] = res[i + 1];
            }
            *count += 1;  // кол-во сдвигов
        }
    } else {
        for (int i = n3 - 1, len = n1 - 1; i > 0 || len >= 0; i--, len--) {
            while (temp > 0 && (*(res + i) + 1 < 9)) {
                res[i]++;
                temp--;
            }
            if (len >= 0) {
                if ((*(a2 + i - 1) + *(a1 + len) + *(res + i)) > 9) {
                    *(res + i) = *(a2 + i - 1) + *(a1 + len) + *(res + i) - 10;
                    temp++;
                } else {
                    *(res + i) = *(a2 + i - 1) + *(a1 + len) + *(res + i);
                }
            } else {
                *(res + i) += *(a2 + i - 1);
            }
            if (*(res + i) == 10) {
                temp++;
                *(res + i) = 0;
            }
        }
        if (temp > 0) {  // если есть temp
            res[0]++;
            temp--;
        }

        while (res[0] == 0 && n3 > 0) {  // убираем нули
            for (int i = 0; i < n3; i++) {
                res[i] = res[i + 1];
            }
            *count += 1;  // кол-во сдвигов
        }
    }
}
void sub(int *a1, int n1, int *a2, int n2, int *res, int n3, int *count) {
    *count = 0;
    if (n1 >= n2) {
        int temp = 0;
        int quit = 0;
        for (int i = n3 - 1, len = n2 - 1; i > 0 || len >= 0; i--, len--) {
            // printf("OUT: %d temp: %d\n",*(a1 + i - 1) -*(a2 + len)-1,temp);
            while (temp > 0 && ((*(a1 + i - 1) - *(a2 + len)) - 1 >= 0)) {
                // printf("while loop \n");
                res[i]--;
                temp--;
            }
            if (len >= 0) {
                if ((*(a1 + i - 1) + *(res + i)) - *(a2 + len) < 0) {
                    *(res + i) = *(a1 + i - 1) + *(res + i) - *(a2 + len) + 10;
                    temp++;
                } else {
                    *(res + i) = *(a1 + i - 1) + *(res + i) - *(a2 + len);
                }
            } else {
                *(res + i) += *(a1 + i - 1);
            }
        }
        if (temp > 0) {  // если есть temp
            if (res[1] - 1 > 0) {
                res[1]--;
                temp--;
                // printf("temp true: %d\n",temp);
            } else {
                // printf("temp false: %d\n",temp);
                quit++;
            }
        }

        while (res[0] == 0 && n3 > 0) {  // убираем нули
            for (int i = 0; i < n3; i++) {
                res[i] = res[i + 1];
            }
            *count += 1;  // кол-во сдвигов
        }

        if (quit) {
            res[0] = -40;
        }
    } else {
        res[0] = -40;
    }
}

void output(int *a, int n, int count) {
    if (*a != -40) {
        for (int i = 0; i < n - count; i++) {
            if (i + 1 == n - count) {
                printf("%d", *(a + i));
            } else {
                printf("%d ", *(a + i));
            }
        }
    } else {
        printf("n/a");
    }
}
int sizeMax(int n1, int n2) {  // нахождение длины для третьего массива
    if (n1 > n2) {
        return n1 + 1;
    } else {
        return n2 + 1;
    }
}
