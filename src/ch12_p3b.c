#include <stdio.h>

#define SQUARE(x)                                                              \
  ({                                                                           \
    typeof(x) _x = (x);                                                        \
    _x *_x;                                                                    \
  })

int main(void) {
  int a = 7;
  printf("%d\n", SQUARE(a));
  printf("%d\n", SQUARE(a + 1));
  printf("%d\n", SQUARE(a++));
  printf("%d\n", a);
}
