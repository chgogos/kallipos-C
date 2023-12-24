#include <stdio.h>

void swap(int a, int b) {
  int t = a;
  a = b;
  b = t;
}

int main(void) {
  int x = 100, y = 200;
  printf("Before swap: x=%d y=%d\n", x, y);
  swap(x, y);
  printf("After swap:  x=%d y=%d\n", x, y);
  return 0;
}
