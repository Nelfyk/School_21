#include <math.h>
#include <stdio.h>

int mod(int a, int b);
int simple(int a);

int main() {
    float a;
    char c;
    if (scanf("%f%c", &a, &c) && c == '\n') {
        a = fabs(a);
        printf("%d", simple((int)a));
    } else {
        printf("n/a");
    }
    return 0;
}

int mod(int a, int b) {
    while (a >= b) {
        a -= b;
    }
    return a;
}

int simple(int a) {
    int max = 0, s = 0;
    for (int i = 1; i <= a; i++) {
        if (mod(a, i) == 0) {
            s = 1;
            for (int j = 2; j < i; j++)
                if (mod(i, j) == 0)
                    s = 0;
            if (s)
                max = i;
        }
    }
    return max;
}
