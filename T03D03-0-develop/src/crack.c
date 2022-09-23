#include <stdio.h>

int main() {
    float x, y;
    if (scanf("%f %f", &x, &y)) {
        if (x * x + y * y < 25)
            printf("GOTCHA");
        else
            printf("MISS");
    } else
        printf("n/a");
    return 0;
}