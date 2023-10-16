//  ΠΡΟΣΟΧΗ ΜΕ ΤΗ rand() ΣΤΟ MINGW

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double pick(double a, double b) {
  int z = rand();
  double r = a + (double)z / (double)RAND_MAX * (b - a);
  printf("rand()=%d RAND_MAX=%d, %.2f\n", z, RAND_MAX,
         (double)z / (double)RAND_MAX);
  printf("a=%f b=%f r=%f\n", a, b, r);
  return r;
}

int main() {
  srand(time(NULL));
  printf("%.2f\n", pick(10, 20));
}