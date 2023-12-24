#include <stdio.h>

int main(void) {
  int x[5];
  int *px = &x[0];
  x[0] = 1;
  *(px + 1) = 10;
  *(px + 2) = 100;
  x[3] = 1000;
  x[4] = 10000;
  for (int i = 0; i < 5; i++) {
    printf("x[%d]=%d ", i, x[i]);
  }
  printf("\n");
  for (int i = 0; i < 5; i++) {
    printf("*(%p)=%d ", (void*)&x[i], x[i]);
  }
  printf("\n");
  return 0;
}
