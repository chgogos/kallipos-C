#include <stdio.h>
#include <stdlib.h>

int fun1(int a) {
  int x = 0;
  x += a;
  return x;
}

int fun2(int b) {
  int y;
  y += b;
  return y;
}

int main(void) {
  int z1, z2;
  z1 = fun1(5);
  z2 = fun2(5);
  printf("%d\n", z1);
  printf("%d\n", z2);
  return 0;
}
