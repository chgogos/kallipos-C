#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main(void) {
  int a = 7;
  printf("%d\n", SQUARE(a));
  printf("%d\n", SQUARE(a + 1));
}
