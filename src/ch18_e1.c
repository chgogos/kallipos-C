#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double pick(double a, double b) {
  int r = rand();
  printf("%d %d\n", r, RAND_MAX);
  return a + (double)r / (double)RAND_MAX * (b - a);
}

int main(void) {
  srand(time(NULL));
  printf("%.2f\n", pick(10, 20));
  return 0;
}
