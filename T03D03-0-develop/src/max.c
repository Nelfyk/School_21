#include <stdio.h>

float max(float a, float b);

int main() {
    float a, b;
    scanf("%f %f", &a, &b);
    if ((int)a == a && (int)b == b) {
        printf("%.0f", max(a, b));
    } else
        printf("n/a");
    return 0;
}

float max(float a, float b) {
    if (a > b)
        return a;
    else
        return b;
}