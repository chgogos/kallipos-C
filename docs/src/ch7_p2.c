#include <stdio.h>

int main(void) {
  int a = 100;
  double b = 200;
  int *x;
  double *z;
  printf("Sizes of variables %lu and %lu \n", sizeof(a), sizeof(b));
  printf("Sizes of pointers %lu and %lu \n", sizeof(x), sizeof(z));
  return 0;
}
