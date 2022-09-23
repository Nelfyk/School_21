#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    int n;
    double *data = input(&n);

    // Don`t forget to allocate memory !

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");
    free(data);
    return 0;
}
