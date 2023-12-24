#include <stdio.h>

void f(int x) {
  printf("F(x)=%d\n", x);
  x = x + 1;
  printf("F(x)=%d\n", x);
}

int main(void) {
  int mainX = 100;
  printf("MAIN(x)=%d\n", mainX);
  f(mainX);
  printf("MAIN(x)=%d\n", mainX);
  return 0;
}
