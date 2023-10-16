#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  unsigned int x = 0;
  x = ~x;
  printf("x=%u UINT_MAX=%u\n", x, UINT_MAX);
  return 0;
}
