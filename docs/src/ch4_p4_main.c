#include <stdio.h>

extern int a;
extern void foo(void);

int main(void) {
  for (int i = 0; i < 3; i++) {
    foo();
    printf("a=%d\n", a);
  }
}
