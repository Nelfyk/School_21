#include <math.h>
#include <stdio.h>

int main() {
    const double PI = 3.14159265358979323846;
    double x;
    FILE *pF = fopen("door_data.txt", "w");
    for (int i = 0; i <= 41; i++) {
        x = PI * ((2.0 * (double)i / 41.0) - 1.0);
        printf("%.7f | ", x);
        fprintf(pF, "%.7f | ", x);
        printf("%.7f | ", 1 / (1 + x * x));
        fprintf(pF, "%.7f | ", 1 / (1 + x * x));

        if (!isnan(sqrt(sqrt(1 + 4 * x * x) - x * x - 1))) {
            printf("%.7f | ", sqrt(sqrt(1 + 4 * x * x) - x * x - 1));
            fprintf(pF, "%.7f | ", sqrt(sqrt(1 + 4 * x * x) - x * x - 1));
        } else {
            printf(" - | ");
            fprintf(pF, " - | ");
        }

        printf("%.7f\n", 1 / (x * x));
        fprintf(pF, "%.7f\n", 1 / (x * x));
    }
    fclose(pF);

    return 0;
}
