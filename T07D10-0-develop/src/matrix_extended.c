#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int choiceF(int *choice);
int input(int *n, int *m);
int inputArray(int *a, int n, int m);
int **oneBuffer(int n, int m, int *error);
int **segments(int n, int m, int *error);
int **arrayPointers(int n, int m, int *error);

void outputStatic(int *a, int n, int m);
void outputDinamic(int **a, int n, int m);

void OutMinMaxStatic(int *a, int n, int m);
void outMinMaxDinamic(int **a, int n, int m);

int main() {
    int n, m, choice, error = 0;
    if (!choiceF(&choice) && choice >= 1 && choice <= 4 && !input(&n, &m) && n > 0 && m > 0) {
        switch (choice) {
            case 1: {
                if (n <= 100 && m <= 100) {
                    int array2[MAX][MAX];
                    inputArray((int *)array2, n, m);
                    outputStatic((int *)array2, n, m);
                    OutMinMaxStatic((int *)array2, n, m);
                } else {
                    error++;
                }
                break;
            }
            case 2: {
                int **array = oneBuffer(n, m, &error);  //  oneBuffer
                if (!error) {
                    outputDinamic(array, n, m);
                    outMinMaxDinamic(array, n, m);
                }
                free(array);
                break;
            }
            case 3: {
                int **array = segments(n, m, &error);  // segments
                if (!error) {
                    outputDinamic(array, n, m);
                    outMinMaxDinamic(array, n, m);
                }
                free(array);
                break;
            }
            case 4: {
                int **array = arrayPointers(n, m, &error);  // arrayPointers
                if (!error) {
                    outputDinamic(array, n, m);
                    outMinMaxDinamic(array, n, m);
                }
                // ------- clear -------
                for (int i = 0; i < n; i++) {
                    free(array[i]);
                }
                // ------- clear -------
                free(array);
                break;
            }
        }
    } else {
        error++;
    }
    if (error) {
        printf("n/a");
    }
    return 0;
}
int choiceF(int *choice) {
    char c;
    int flag = 0;
    if (!(scanf("%d%c", choice, &c) && (c == ' ' || c == '\n'))) {
        flag++;
    } else {
    }
    return flag;
}
int input(int *n, int *m) {
    char c;
    int flag = 0;
    if (!(scanf("%d%c", n, &c) && (c == ' ' || c == '\n'))) {
        flag++;
    }
    if (!(scanf("%d%c", m, &c) && (c == ' ' || c == '\n'))) {
        flag++;
    }
    return flag;
}
int inputArray(int *a, int n, int m) {
    int flag = 0;
    char c;
    for (int i = 0; i < n && flag != 1; i++) {
        for (int j = 0; j < m && flag != 1; j++) {
            if (!(scanf("%d%c", a + i * m + j, &c) && (c == ' ' || c == '\n'))) {
                flag++;
            }
        }
    }
    return flag;
}

int **oneBuffer(int n, int m, int *error) {  // -= 2 =-
    char c;
    int **a = malloc(n * m * sizeof(int) + n * sizeof(int *));
    int *ptr = (int *)(a + n);
    for (int i = 0; i < m; i++) {
        a[i] = ptr + n * i;
    }
    for (int i = 0; i < n && *error == 0; i++) {
        for (int j = 0; j < m && *error == 0; j++) {
            if (!(scanf("%d%c", &a[i][j], &c) && (c == ' ' || c == '\n'))) {
                *error += 1;
            }
        }
    }
    return a;
}
int **segments(int n, int m, int *error) {  // -= 3 =-
    char c;
    int **a = malloc(n * sizeof(int *));   // pointer_array
    int *b = malloc(n * m * sizeof(int));  // value_array
    for (int i = 0; i < n; i++) {
        a[i] = b + m * i;
    }
    for (int i = 0; i < n && *error == 0; i++) {
        for (int j = 0; j < m && *error == 0; j++) {
            if (!(scanf("%d%c", &a[i][j], &c) && (c == ' ' || c == '\n'))) {
                *error += 1;
            }
        }
    }
    free(b);
    return a;
}

int **arrayPointers(int n, int m, int *error) {  // -= 4 =-
    char c;
    int **a = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = malloc(m * sizeof(int));
    }
    for (int i = 0; i < n && *error == 0; i++) {
        for (int j = 0; j < m && *error == 0; j++) {
            if (!(scanf("%d%c", &a[i][j], &c) && (c == ' ' || c == '\n'))) {
                *error += 1;
            }
        }
    }
    return a;
}

void outputStatic(int *a, int n, int m) {  // =OUT=STATIC
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 == n) {
                printf("%d", *(a + i * m + j));
            } else {
                printf("%d ", *(a + i * m + j));
            }
        }
        if (i + 1 != n) {
            printf("\n");
        }
    }
}

void outputDinamic(int **a, int n, int m) {  // =OUT=DINAMIC
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 == n) {
                printf("%d", a[i][j]);
            } else {
                printf("%d ", a[i][j]);
            }
        }
        if (i + 1 != n) {
            printf("\n");
        }
    }
}

void OutMinMaxStatic(int *a, int n, int m) {
    printf("\n");
    // =========/ MAX
    for (int i = 0; i < n; i++) {
        int max = *(a + i * m + 0);
        for (int j = 1; j < m; j++) {
            if (max < *(a + i * m + j)) {
                max = *(a + i * m + j);
            }
        }

        if (i + 1 == n) {
            printf("%d", max);
            printf("\n");
        } else {
            printf("%d ", max);
        }
    }
    // =========/ MIN
    for (int i = 0; i < n; i++) {
        int min = *(a + 0 * m + i);
        for (int j = 0; j < m; j++) {
            if (min > *(a + j * m + i)) {
                min = *(a + j * m + i);
            }
        }

        if (i + 1 == n) {
            printf("%d", min);
        } else {
            printf("%d ", min);
        }
    }
}
void outMinMaxDinamic(int **a, int n, int m) {
    printf("\n");
    // =========/ MAX
    for (int i = 0; i < n; i++) {
        int max = a[i][0];
        for (int j = 1; j < m; j++) {
            if (max < a[i][j]) {
                max = a[i][j];
            }
        }
        if (i + 1 == n) {
            printf("%d", max);
            printf("\n");
        } else {
            printf("%d ", max);
        }
    }
    // =========/ MIN
    for (int i = 0; i < n; i++) {
        int min = a[0][i];
        for (int j = 0; j < m; j++) {
            if (min > a[j][i]) {
                min = a[j][i];
            }
        }
        if (i + 1 == n) {
            printf("%d", min);
        } else {
            printf("%d ", min);
        }
    }
}
