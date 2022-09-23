#include <stdio.h>
/*

Создать программу src/cycle_shift.c, ожидающую на вход число n, массив
A из n целых чисел и число c, на которое все элементы массива должны сдвинутся влево циклично.
При этом, при отрицательном значении c сдвиг должен произойти вправо по массиву.
В качестве вывода ожидается измененный массив. Необходимо придерживаться предлагаемой декомпозиции, как и в прошлых квестах.
Использовать stdlib.h нельзя. Передача массива в функцию только по указателю. Максимальный размер входного массива - 10.
В случае ошибки выводить "n/a". ==

Входные данные: {
10
4 3 9 0 1 2 0 2 7 -1
2
}
Выходные данные: 9 0 1 2 0 2 7 -1 4 3

*/
int input(int *a, int *n, int *c);
void output(int *a, int n);
void loop(int *a, int n, int c);

int main() {
    int n, c;
    int array[10];

    if (!input(array, &n, &c)) {
        loop(array, n, c);
        output(array, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n, int *c) {
    int retturn=0;
    if (scanf("%d", n) && *n < 11 && *n > 0) {
        for (int i = 0; i < *n && retturn==0; i++) {
            if (!scanf("%d", a + i)) {
                retturn++;
            }
        }
        char ch;
        if (!(scanf("%d%c", c, &ch) && (ch==' ' || ch == '\n'))) {
            retturn++;
        }
    } else {
        retturn++;
    }
    return retturn;
}
void loop(int *a, int n, int c) {
    int temp;
    if (c > 0) {
        while (c > 0) {
            c--;
            temp = *a;
            for (int i = 1; i < n; i++) {
                *(a + i - 1) = *(a + i);
            }
            *(a + n - 1) = temp;
        }
    } else {
        while (c < 0) {
            c++;
            temp = *(a + n - 1);
            for (int i = n - 1; i > 0; i--) {
                *(a + i) = *(a + i - 1);
            }
            *a = temp;
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
