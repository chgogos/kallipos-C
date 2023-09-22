#include <math.h>
#include <stdio.h>

int main(void) {
  double x = 2.0;
  double irrational = sqrt(x);
  printf("The square root of %.2f is %.8f\n", x, irrational);
  return 0;
}
