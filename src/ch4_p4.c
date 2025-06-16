#include <stdio.h>

extern int a;

int main(void) {
  printf("a=%d\n", a);
  return 0;
}

int a = 1;
