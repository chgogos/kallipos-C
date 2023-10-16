#include <stdio.h>

int main(void) {
  int x = 100;
  double y = 200.0;
  printf("x=%d y=%lf\n", x, y);
  printf("&x=%p, &y=%p \n", &x, &y);
  return 0;
}
