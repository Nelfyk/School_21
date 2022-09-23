#include <stdio.h>

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
    int array[10];
    if (!input(array)) {
        sort(array);
        output(array);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a) {
    int retturn=0;
    for (int i = 0; i < 10 && retturn!=1; i++) {
        if (!scanf("%d", a + i)) {
            retturn++;
        }
    }
    return retturn;
}
void sort(int *a) {
    int temp;
    for (int o = 0; o < 10; o++) {
        for (int i = 0; i < 10; i++) {
            if (*(a + i) > *(a + i + 1)) {
                temp = *(a + i);
                *(a + i) = *(a + i + 1);
                *(a + i + 1) = temp;
            }
        }
    }
}
void output(int *a) {
    for (int i = 0; i < 10; i++) {
        if (i + 1 == 10) {
            printf("%d", *(a + i));
        } else {
            printf("%d ", *(a + i));
        }
    }
}
