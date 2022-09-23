#include "data_stat.h"

double max(double *data, int n) {
    double max = *data;
    for (int i = 1; i < n; i++) {
        if (max < *(data + i)) {
            max = *(data + i);
        }
    }
    return max;
}

double min(double *data, int n) {
    double min = *data;
    for (int i = 1; i < n; i++) {
        if (min > *(data + i)) {
            min = *(data + i);
        }
    }
    return min;
}
double mean(double *data, int n) {  // ожидание (first+last)/2
    return (*data + *(data + n)) / 2.0;
}
double variance(int n) {  // дисперсия (n*n-1)/12
    return ((double)n * (double)n - 1.0) / 12.0;
}
