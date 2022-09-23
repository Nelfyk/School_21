#include <math.h>
#include <stdio.h>

int main() {
  double delta_y = 1.0 / 12.0;
  double arr_y[80];
  for (int i = 0; i < 80; i += 1) {
    arr_y[i] = sin(cos(2 * ((double)i * 4. * M_PI / 79.)));
    // sin((double)i * 4. * M_PI / 79.);
    // printf("%lf\n", arr_y[i]);
  }

  for (double y = -1; y <= 1.000000000000001; y += delta_y) {
    for (int x = 0; x < 80; x++) {
      double y_min = y - delta_y / 2.0;
      double y_max = y + delta_y / 2.0;
      if (y_min < arr_y[x] && arr_y[x] <= y_max) {
        printf("*");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }

  return 0;
}