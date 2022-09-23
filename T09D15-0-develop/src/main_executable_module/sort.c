#include "sort.h"

void sort(double *data, int n) {
    double temp;
    for (int o = 0; o < n; o++) {
        for (int i = 0; i < n - 1; i++) {
            if (*(data + i) > *(data + i + 1)) {
                temp = *(data + i);
                *(data + i) = *(data + i + 1);
                *(data + i + 1) = temp;
            }
        }
    }
}
