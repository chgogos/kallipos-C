#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("int (%zu bytes)\t\t%d to %d\n", sizeof(int), INT_MIN, INT_MAX);
  printf("double (%zu bytes)\t%e to %e\n", sizeof(double), DBL_MIN, DBL_MAX);
  return 0;
}
