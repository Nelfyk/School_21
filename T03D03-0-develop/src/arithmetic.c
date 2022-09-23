#include <stdio.h>

int main() {
    float a, b;
    scanf("%f %f", &a, &b);
    if ((int)a == a && (int)b == b) {
        if (b != 0)
            printf("%.0f %.0f %.0f %.0f", a + b, a - b, a * b, a / b);
        else
            printf("%.0f %.0f %.0f n/a", a + b, a - b, a * b);
    } else
        printf("n/a");
    return 0;
}