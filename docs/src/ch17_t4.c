#include <math.h>
#include <stdio.h>

void fun(double x) {
  double c = ceil(x);
  double f = floor(x);
  double r = round(x);
  double t = trunc(x);
  double integer_part, fractional_part;
  fractional_part = modf(x, &integer_part);
  printf("x=%.1f, floor=%.1lf, ceiling=%.1lf, round=%.1f, trunc=%.1f\n", x, f,
         c, r, t);
  printf("Integer part=%.1f, fractional part=%.1f\n", integer_part,
         fractional_part);
}

int main(void) {
  fun(2.3);
  fun(-2.3);
  fun(2.7);
  fun(-2.7);
  return 0;
}