#include <stdio.h>
#define SWAP(a,b)({a ^= b; b ^= a; a ^= b;})

int main(void) {
  int x = 5, y = 10;
  SWAP(x, y);
  printf("x=%d, y=%d\n", x, y);
}