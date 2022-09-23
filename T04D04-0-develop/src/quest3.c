#include <stdio.h>
int fib(int n, int a, int b, int c);
int main() {
    float in;
    char c;
    if (scanf("%f%c", &in, &c) && c == '\n') {
        printf("%d", fib(in, 0, 1, 0));
    } else {
        printf("n/a");
    }
    return 0;
}

int fib(int n, int a, int b, int c) {
    if (n == 0)
        return c;
    a = b;
    b = c;
    c = a + b;
    n--;
    return fib(n, a, b, c);
}
