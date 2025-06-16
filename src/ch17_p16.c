#include <math.h>
#include <stdio.h>

int main(void) {
  double pi = acos(-1);
  double a[] = {pi, pi / 2, pi / 3, pi / 4, pi / 6};
  for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    printf("%lf(rad)=%3.0lf(deg): sin=%+lf, cos=%+lf, tan=%+lf\n", a[i],
           a[i] * 57.2957795, sin(a[i]), cos(a[i]), tan(a[i]));
  }
  return 0;
}
