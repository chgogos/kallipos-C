#include <math.h>
#include <stdio.h>

int main(void) {
  double x = 10.0, y = 4.4;
  int d = floor(x / y);
  double r = fmod(x, y);
  printf("The value %.1f fits %d times in %.1f and the remainder is %.1f\n", y,
         d, x, r);
  return 0;
}
