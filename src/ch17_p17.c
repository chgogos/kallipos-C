#include <math.h>
#include <stdio.h>

int main(void) {
  double pi = acos(-1);
  double a[] = {-0.1,    -0.01,  -0.001, -0.0001, -0.00001,
                0.00001, 0.0001, 0.001,  0.01,    0.1};
  for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    printf("%lf(rad)=%lf(deg): tan=%+.5lf\n", pi / 2 + a[i],
           (pi / 2 + a[i]) * 57.2957795, tan(pi / 2 + a[i]));
  }
  return 0;
}
