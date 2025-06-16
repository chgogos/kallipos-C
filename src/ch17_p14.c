#include <math.h>
#include <stdio.h>

void fun(double x) {
  double c = ceil(x);
  double f = floor(x);
  double r = round(x);
  double t = trunc(x);
  double integer_part, fractional_part;
  fractional_part = modf(x, &integer_part);
  printf("%5.1f\t%6.1lf\t%7.1lf\t%5.1f\t%5.1f\t%12.1f\t%15.1f\n", x, f, c, r, t,
         integer_part, fractional_part);
}

int main(void) {
  printf(
      "    x\t floor\tceiling\tround\ttrunc\tinteger_part\tfractional_part\n");
  fun(2.3);
  fun(-2.3);
  fun(2.7);
  fun(-2.7);
  return 0;
}
