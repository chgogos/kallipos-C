#include <stdio.h>

int main(void) {
  int x = 10, y = ++x + 5;
  printf("Prefix increment example: x=%d, y=%d\n", x, y);
  x = 10;
  y = x++ + 5;
  printf("Postfix increment example: x=%d, y=%d\n", x, y);
  return 0;
}
