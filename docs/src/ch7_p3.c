#include <stdio.h>

int main(void) {
  int x = 100;
  double y = 200;
  int *px = &x;
  double *py = &y;
  printf("x=%d y=%lf\n", x, y);
  printf("&px=%p &py=%p\n", (void *)px, (void *)py);
  return 0;
}
