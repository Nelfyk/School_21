#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    int n;
    double *data = input(&n);

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
    free(data);
    return 0;
}
