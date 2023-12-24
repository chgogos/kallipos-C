#include <limits.h>
#include <stdio.h>

int main(void) {
  int a = INT_MAX;
  unsigned int b = UINT_MAX;
  printf("a=%d, b=%u\n", a, b);
  a++;
  b++;
  printf("a=%d, b=%u\n", a, b);
  return 0;
}