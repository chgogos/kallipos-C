#include <stdio.h>

int main(void) {
  int a = 5, b = 10;

#if 0
    printf("Swap")
    /*
    a ^= b;
    b ^= a;
    a ^= b;
    */
#endif

  printf("a=%d, b=%d\n", a, b);
}
