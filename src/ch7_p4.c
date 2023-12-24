#include <stdio.h>

int main(void) {
  int x = 100;
  double y = 200;
  int *px = &x;
  double *py = &y;
  printf("x=%d y=%lf\n", x, y);
  *px = 5;
  *py = 20;
  printf("x=%d y=%lf\n", x, y);
  return 0;
}
